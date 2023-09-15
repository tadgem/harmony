using HarmonyMono;
using System;

namespace GameTest
{
    public class TestClass : IOnInit, IOnUpdate, IOnCleanup
    {
        public void Cleanup()
        {
            Console.WriteLine("Cleanup");
        }

        public void Update()
        {
            Console.WriteLine("Update");
        }

        public void Init()
        {
            Console.WriteLine("Init");
        }
    }
}
