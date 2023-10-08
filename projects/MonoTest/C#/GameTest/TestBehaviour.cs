using Harmony;
using Harmony.Math;

namespace GameTest
{
    public class TestBehaviour : Behaviour
    {
        private Scene _scene;
        private NativeTransformComponent _transform;
        public float Speed = 3.0f;
        public override void Init()
        {
            _scene = SceneMethods.GetActiveScene();
            _transform = ECSMethods.GetEntityTransform(_scene, Self);
            Vector3 v = ECSMethods.GetTransformPosition(_transform);
            Log.Info($"I am entity : {Self} : Pos : {v}");
        }
        public override void Update()
        {
            float delta = (float) Time.GetFrameTime();
            Vector3 v = ECSMethods.GetTransformEuler(_transform);
            v.x = v.x + delta * 3.0f;
            ECSMethods.SetTransformEuler(_transform, v);
        }

    }
}
