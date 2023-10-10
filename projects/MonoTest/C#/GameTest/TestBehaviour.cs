using Harmony;
using System.Numerics;

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
            _transform = _scene.GetEntityTransform(Self);
            Vector3 v = _transform.GetTransformPosition();
            Log.Info($"I am entity : {Self} : Pos : {v}");
        }
        public override void Update()
        {
            float delta = (float) Time.GetFrameTime();
            Vector3 euler = _transform.GetTransformEuler();
            Vector3 position = _transform.GetTransformPosition();
            Vector3 forward = _transform.GetTransformForward();

            euler.X += delta * Speed * Speed;
            position += forward * delta * (Speed / Speed);
            _transform.SetTransformEuler(euler);
            _transform.SetTransformPosition(position);
        }

    }
}
