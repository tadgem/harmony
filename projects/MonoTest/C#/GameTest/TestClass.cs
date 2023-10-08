using Harmony;
using System;

namespace GameTest
{    
    public class TestClass : ProgramComponent.IOnInit, ProgramComponent.IOnUpdate, ProgramComponent.IOnCleanup
    {
        private class TestProgramComponent : ProgramComponent
        {

        }
        public void AddThing<T>() where T : ProgramComponent
        {
            Log.Warn($"I am the number {2}");
        }

        public void Cleanup()
        {
            Log.Info("Cleanup");
        }

        public void Update()
        {
        }

        public void Init()
        {
            Log.Info($"Init : {1}");

            AddThing<TestProgramComponent>();
        }

    }
}
