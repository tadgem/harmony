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
        public override void Init()
        {
            _scene = SceneMethods.GetActiveScene();
            _transform = _scene.GetEntityTransform(Self);

            NativeJoltBodyComponent joltBody = _scene.GetEntityJoltBodyComponent(Self);
            IntPtr bodyPtr = joltBody.GetJoltBodyFromComponent();
            _body = new HarmonyJoltSharp.Body(bodyPtr);

            _callback = OnContactEnter;
            _body.AddContactAddedCallback(_callback);

            Vector3 v = _transform.GetTransformPosition();
            Log.Info($"I am entity : {Self} : Pos : {v}");
        }

        public void OnContactEnter(IntPtr a, IntPtr b, ContactManifoldData manifold, ContactSettings settings)
        {
            Body b1 = new Body(a);
            Body b2 = new Body(b);

            Entity e1 = b1.GetEntity();
            Entity e2 = b2.GetEntity();
            Log.Info($"Entity : {e1} collided with {e2}");
        }

        public override void Update()
        {
            IntPtr bodyPtr = _scene.GetJoltBodyFromEntity(Self);
            _body = new HarmonyJoltSharp.Body(bodyPtr);
            _body.AddForce(Vector3.UnitY * Force);
        }

    }
}
