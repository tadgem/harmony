using HarmonyMono;
using System;

namespace GameTest
{
    public class TestClass : ProgramComponent.IOnInit, ProgramComponent.IOnUpdate, ProgramComponent.IOnCleanup
    {
        public void Cleanup()
        {
            Console.WriteLine("Cleanup");
        }

        public void Update()
        {
            Console.WriteLine("This is an updated message");
        }

        public void Init()
        {
            Console.WriteLine("Init");
        }
    }
}
