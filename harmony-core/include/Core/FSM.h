#pragma once

#include "STL/Functional.h"
#include "STL/Vector.h"
namespace harmony {
    class FSM {
    public:
        const unsigned char MAX_TRANSITIONS_PER_PROCESS = 8;

        class State {
        public:
            State(int state, Lambda<int()> action, Lambda<void()> entry = NULL,
                  Lambda<void()> exit = NULL);

            bool HasEntry;
            bool HasExit;
        protected:
            Lambda<void()> m_EntryProcedure;
            Lambda<void()> m_ExitProcedure;
            Lambda<int()> m_Action;
            const int m_State;

            friend class FSM;
        };

        struct StateTransition {
            int Trigger;
            int SrcState;
            int DstState;
        };

    public:
        FSM();

        void SetStartingState(int state);

        void Process();

        void AddState(int state, Lambda<int()> action);

        void AddStateEntry(int state, Lambda<void()> entry);

        void AddStateExit(int state, Lambda<void()> exit);

        void AddTrigger(int trigger, int srcState, int dstState);

        void Trigger(int trigger);

        // arbitrary, can probably be done in a better way but we are in trouble if we have an FSM with more than 65000 states.
        inline static const int NO_TRIGGER = 65536;
    protected:
        int p_PreviousState;
        int p_CurrentState;
        bool p_RunEntry;

        void TransitionState(int newState);

        Vector<State> p_States;
        Vector<StateTransition> p_Transitions;
    };
}