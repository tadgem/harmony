using System;

namespace GameTest
{
    public interface IOnInit
    {
        void Init();
    }
    public interface IOnUpdate
    {
        void Update();
    }
    public interface IOnCleanup
    {
        void Cleanup();
    }

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
