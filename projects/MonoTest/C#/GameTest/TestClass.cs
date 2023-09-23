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
            Console.WriteLine($"I am type {typeof(T).Name}");
        }

        public void Cleanup()
        {
            Console.WriteLine("Cleanup");
        }

        public void Update()
        {
            AddThing<TestProgramComponent>();
        }

        public void Init()
        {
            Console.WriteLine($"Init : {1}");
        }

    }
}
