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
            State(uint16_t state, std::function<int()> action, std::function<void()> entry = NULL, std::function<void()> exit = NULL);

            bool HasEntry;
            bool HasExit;
        protected:
            std::function<void()> m_EntryProcedure;
            std::function<void()> m_ExitProcedure;
            std::function<int()> m_Action;
            const uint16_t m_State;
            friend class FSM;
        };

        struct StateTransition
        {
            uint16_t Trigger;
            uint16_t SrcState;
            uint16_t DstState;
        };

    public:
        FSM();

        void Process();

        void AddState(uint16_t state, std::function<int()> action);
        void AddStateEntry(uint16_t state, std::function<int()> entry);
        void AddStateExit(uint16_t state, std::function<int()> exit);

        void AddTrigger(uint16_t trigger, uint16_t srcState, uint16_t dstState);

    protected:
        uint16_t p_CurrentState;
        bool p_RunEntry;
        bool p_RunExit;

        std::vector<State> p_States;
        std::vector<StateTransition> p_Transitions;
    };
}