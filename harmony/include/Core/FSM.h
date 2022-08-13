#pragma once
#include <functional>

namespace harmony
{
    class FSM
    {
    protected:
        const uint8_t MAX_TRANSITIONS_PER_PROCESS = 8;
        class State
        {
        public:
            State(int state, int(*action)(), void(*entry)() = nullptr, void(*exit)() = nullptr);

            bool HasEntry;
            bool HasExit;
        protected:
            void(*m_EntryProcedure)();
            void(*m_ExitProcedure)();
            int(*m_Action)();
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

        void AddState(int state, int(*action)());
        void AddStateEntry(int state, void(*entry)());
        void AddStateExit(int state, void(*exit)());

        void AddTrigger(int trigger, int srcState, int dstState);

        // arbitrary, can probably be done in a better way but we are in trouble if we have an FSM with more than 65000 states.
        inline static const int NO_TRIGGER = 65536; 
    protected:
        int p_PreviousState;
        int p_CurrentState;
        bool p_RunEntry;

        void TransitionState(int newState);

        std::vector<State> p_States;
        std::vector<StateTransition> p_Transitions;
    };
}