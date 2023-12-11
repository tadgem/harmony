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
            Vector3 start = _transform.GetTransformPosition() + _transform.GetTransformForward();

            RaycastResult[] results = Physics.RaycastMulti(start, _transform.GetTransformForward() * 20);
            if (results.Length > 0)
            {
                foreach (RaycastResult r2 in results)
                {
                    if (r2.Body.GetEntity() != _body.GetEntity())
                    {
                        DebugDraw.Cylinder(DebugDrawChannel.Editor, start, r2.HitPoint, 0.1f);
                        DebugDraw.Orb(DebugDrawChannel.Editor, r2.HitPoint, 0.3f);
                    }
                }
            }

            //ShapecastResultSimple[] sphereResults = Physics.CollideSphere(_transform.GetTransformPosition(), 30.0f);

            //if (sphereResults.Length > 0)
            //{
            //    foreach (ShapecastResultSimple r in sphereResults)
            //    {
            //        Log.Info($"SphereCast : Found entity {r.Body.GetEntity()}");
            //    }
            //}

            ShapecastResultSimple[] sphereCastResults = Physics.Spherecast(_transform.GetTransformPosition() + _transform.GetTransformForward(), _transform.GetTransformForward(), 2.0f);
            if (sphereCastResults.Length > 0)
            {
                foreach (ShapecastResultSimple r in sphereCastResults)
                {
                    Log.Info($"SphereCast : Found entity {r.Body.GetEntity()}");
                }
            }
        }

    }
}
