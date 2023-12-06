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
        
        public override void Init()
        {
            _scene = SceneMethods.GetActiveScene();
            _transform = _scene.GetEntityTransform(Self);

            NativeJoltBodyComponent joltBody = _scene.GetEntityJoltBodyComponent(Self);
            IntPtr bodyPtr = joltBody.GetJoltBodyFromComponent();
            _body = new Body(bodyPtr);

            _body.AddContactAddedCallback(OnContactEnter);
            // _body.AddContactPersistedCallback(OnContactPersisted);
            _body.AddContactRemovedCallback(OnContactRemoved);
        }

        public void OnContactEnter(Body a, Body b, ContactManifoldData manifold, ContactSettings settings)
        {
            Entity e1 = a.GetEntity();
            Entity e2 = b.GetEntity();
            Log.Info($"Entity : {e1} entered collision with {e2}");
        }

        public void OnContactPersisted(Body a, Body b, ContactManifoldData manifold, ContactSettings settings)
        {
            Entity e1 = a.GetEntity();
            Entity e2 = b.GetEntity();
            // Log.Info($"Entity : {e1} persisted collision with {e2}");
        }

        public void OnContactRemoved(Body a, Body b)
        {
            Entity e1 = a.GetEntity();
            Entity e2 = b.GetEntity();
            Log.Info($"Entity : {e1} removed collision with {e2}");
        }

        public override void Update()
        {
            IntPtr bodyPtr = _scene.GetJoltBodyFromEntity(Self);
            _body = new HarmonyJoltSharp.Body(bodyPtr);
            _body.AddForce(Vector3.UnitY * Force);
            //RaycastResult result = Physics.Raycast(_transform.GetTransformPosition(), _transform.GetTransformForward());
            //if(result.DidHit)
            //{
            //    Log.Info($"Raycast hit entity : {result.Body.GetEntity()}");
            //}
        }

    }
}
