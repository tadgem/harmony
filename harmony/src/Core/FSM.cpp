#include "Core/FSM.h"

harmony::FSM::State::State(uint16_t state, std::function<int()> action, std::function<void()> entry, std::function<void()> exit) : m_State(state), m_Action(action)
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

harmony::FSM::FSM() : p_CurrentState(UINT16_MAX), p_RunEntry(false), p_RunExit(false)
{
}

void harmony::FSM::Process()
{
}

void harmony::FSM::AddState(uint16_t state, std::function<int()> action)
{
}

void harmony::FSM::AddStateEntry(uint16_t state, std::function<int()> entry)
{
}

void harmony::FSM::AddStateExit(uint16_t state, std::function<int()> exit)
{
}

void harmony::FSM::AddTrigger(uint16_t trigger, uint16_t srcState, uint16_t dstState)
{
}
