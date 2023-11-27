using Harmony;
using HarmonyJoltSharp;
using System;
using System.Numerics;

namespace GameTest
{
    public class JoltTestBehaviour : Behaviour
    {
        public float Force = 10000.0f;
        
        private Scene _scene;
        private NativeTransformComponent _transform;
        private Body _body;
        private ContactCallback _callback;
        public override void Init()
        {
            _scene = SceneMethods.GetActiveScene();
            _transform = _scene.GetEntityTransform(Self);

            NativeJoltBodyComponent joltBody = _scene.GetEntityJoltBodyComponent(Self);
            IntPtr bodyPtr = joltBody.GetJoltBodyFromComponent();
            _body = new Body(bodyPtr);

            _callback = OnContactEnter;
            _body.AddContactAddedCallback(_callback);
        }

        public void OnContactEnter(Body a, Body b, ContactManifoldData manifold, ContactSettings settings)
        {
            Entity e1 = a.GetEntity();
            Entity e2 = b.GetEntity();
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
