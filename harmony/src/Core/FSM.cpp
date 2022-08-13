#include "Core/FSM.h"
#include "Core/Log.hpp"

harmony::FSM::State::State(int state, std::function<int()> action, std::function<void()> entry, std::function<void()> exit) : m_State(state), m_Action(action)
{
	HasEntry = false;
	HasExit = false;

	if (entry != NULL)
	{
		m_EntryProcedure = entry;
		HasEntry = true;
	}

	if (exit != NULL)
	{
		m_ExitProcedure = exit;
		HasExit = true;
	}
}

harmony::FSM::FSM() : p_CurrentState(UINT16_MAX), p_RunEntry(false)
{
}

void harmony::FSM::SetStartingState(int state)
{
	p_CurrentState = state;
}

void harmony::FSM::Process()
{
	int index = -1;
	for (int i = 0; i < p_States.size(); i++)
	{
		if (p_States[i].m_State == p_CurrentState)
		{
			index = i;
			break;
		}
	}

	if (index <= 0)
	{
		harmony::log::info("No State to process");
		p_PreviousState = p_CurrentState;
		return;
	}

	if (!p_RunEntry)
	{
		if (p_States[index].HasEntry)
		{
			p_States[index].m_EntryProcedure();
			p_RunEntry = true;
		}
	}

	int trigger = p_States[index].m_Action();
	uint8_t numTransitions = 0;
	while (trigger != NO_TRANSITION)
	{
		p_PreviousState = p_CurrentState;

		if (!p_RunEntry)
		{
			if (p_States[index].HasEntry)
			{
				p_States[index].m_EntryProcedure();
				p_RunEntry = true;
			}
		}

		for (int i = 0; i < p_Transitions.size(); i++)
		{
			if (p_Transitions[i].Trigger == trigger)
			{
				if (p_Transitions[i].SrcState == p_CurrentState)
				{
					TransitionState(p_Transitions[i].DstState);
					numTransitions++;
					break;
				}
			}
		}

		if (p_CurrentState != p_PreviousState)
		{
			trigger = p_States[index].m_Action();
		}

	}

	p_PreviousState = p_CurrentState;

}

void harmony::FSM::AddState(int state, std::function<int()> action)
{
	for (int i = 0; i < p_States.size(); i++)
	{
		if (p_States[i].m_State == state)
		{
			harmony::log::error("Already have a state in machine for : {}", state);
			return;
		}
	}

	State stateObj = State(state, action);
	p_States.emplace_back(stateObj);

}

void harmony::FSM::AddStateEntry(int state, std::function<int()> entry)
{
	for (int i = 0; i < p_States.size(); i++)
	{
		if (p_States[i].m_State == state)
		{
			p_States[i].m_EntryProcedure = entry;
			p_States[i].HasEntry = true;
		}
	}
}

void harmony::FSM::AddStateExit(int state, std::function<int()> exit)
{
	for (int i = 0; i < p_States.size(); i++)
	{
		if (p_States[i].m_State == state)
		{
			p_States[i].m_ExitProcedure = exit;
			p_States[i].HasExit = true;
		}
	}
}

void harmony::FSM::AddTrigger(int trigger, int srcState, int dstState)
{
	StateTransition transition{ trigger, srcState, dstState };

	p_Transitions.emplace_back(transition);

}

void harmony::FSM::TransitionState(int newState)
{
	if (p_States[p_CurrentState].HasExit)
	{
		p_States[p_CurrentState].m_ExitProcedure();
	}

	p_CurrentState = newState;
	p_RunEntry = false;
}
