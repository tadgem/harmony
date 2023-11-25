using Harmony;
using HarmonyJoltSharp;
using System;
using System.Numerics;

namespace GameTest
{
    public class JoltTestBehaviour : Behaviour
    {
        private Scene _scene;
        private NativeTransformComponent _transform;
        private HarmonyJoltSharp.Body _body;
        public float Force = 10000.0f;
        private ContactCallback _callback;
        private Action _action;
        public override void Init()
        {
            _scene = SceneMethods.GetActiveScene();
            _transform = _scene.GetEntityTransform(Self);

            NativeJoltBodyComponent joltBody = _scene.GetEntityJoltBodyComponent(Self);
            IntPtr bodyPtr = joltBody.GetJoltBodyFromComponent();
            _body = new HarmonyJoltSharp.Body(bodyPtr);

            _action = OnCollisionEnter2;
            _body.AddContactAddedCallback(_action);

            Vector3 v = _transform.GetTransformPosition();
            Log.Info($"I am entity : {Self} : Pos : {v}");
        }

        //public void OnCollisionEnter(IntPtr a, IntPtr b, IntPtr manifold, IntPtr settings)
        //{
        //    Log.Info($"JoltTestBehaviour : I am being called from a collision callback a : {a}, b : {b}, manifold : {manifold}, settings : {settings}");
        //}

        public void OnCollisionEnter2()
        {
            Log.Info($"JoltTestBehaviour : Entity {Self} : I am being called from a collision callback");
        }

        public override void Update()
        {
            IntPtr bodyPtr = _scene.GetJoltBodyFromEntity(Self);
            _body = new HarmonyJoltSharp.Body(bodyPtr);
            _body.AddForce(Vector3.UnitY * Force);
        }

    }
}
