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
        public float Force = 5000.0f;

        public override void Init()
        {
            _scene = SceneMethods.GetActiveScene();
            _transform = _scene.GetEntityTransform(Self);

            NativeJoltBodyComponent joltBody = _scene.GetEntityJoltBodyComponent(Self);
            IntPtr bodyPtr = joltBody.GetJoltBodyFromComponent();
            _body = new HarmonyJoltSharp.Body(bodyPtr);

            Vector3 v = _transform.GetTransformPosition();
            Log.Info($"I am entity : {Self} : Pos : {v}");
        }
        public override void Update()
        {
            NativeJoltBodyComponent joltBody = _scene.GetEntityJoltBodyComponent(Self);
            IntPtr bodyPtr = joltBody.GetJoltBodyFromComponent();
            _body = new HarmonyJoltSharp.Body(bodyPtr);
            _body.AddForce(Vector3.UnitY * Force);
        }

    }
}
