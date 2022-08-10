#pragma once
#include <functional>

namespace harmony
{
    class FSM
    {
    protected:
        class State
        {
        public:
            State(int state, std::function<int()> action, std::function<void()> entry = NULL, std::function<void()> exit = NULL);

            bool HasEntry;
            bool HasExit;
        protected:
            std::function<void()> m_EntryProcedure;
            std::function<void()> m_ExitProcedure;
            std::function<int()> m_Action;
            const int m_State;
            friend class FSM;
        };

        struct StateTransition
        {
            int Trigger;
            int SrcState;
            int DstState;
        };

    public:
        FSM();

        void SetStartingState(int state);
        void Process();

        void AddState(int state, std::function<int()> action);
        void AddStateEntry(int state, std::function<int()> entry);
        void AddStateExit(int state, std::function<int()> exit);

        void AddTrigger(int trigger, int srcState, int dstState);

    protected:
        int p_PreviousState;
        int p_CurrentState;
        bool p_RunEntry;

        void TransitionState(int newState);

        std::vector<State> p_States;
        std::vector<StateTransition> p_Transitions;
    };
}