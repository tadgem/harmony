using Harmony;
using System;
using System.Numerics;

namespace GameTest
{
    public class TestBehaviour : Behaviour
    {
        private Scene _scene;
        private NativeTransformComponent _transform;
        public float Speed = 3.0f;
        VectorGraphics.NVGcolor _circleColor = new VectorGraphics.NVGcolor();
        Vector2 _circlePos = new Vector2();

        public override void Init()
        {
            _scene = SceneMethods.GetActiveScene();
            _transform = _scene.GetEntityTransform(Self);
            Vector3 v = _transform.GetTransformPosition();
            Log.Info($"I am entity : {Self} : Pos : {v}");
            _circleColor.r = 255.0f;
            _circleColor.a = 255.0f;
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
            _circlePos.X += delta * Speed;
            _circlePos.Y += delta * Speed;
            

            if (Input.GetKeyButton(Input.Key.Space))
            {
                Log.Info("Space pressed");
            }

            VectorGraphics.BeginPath(VectorGraphics.Layer.One);
            VectorGraphics.Circle(VectorGraphics.Layer.One, _circlePos.X, 30.0f, 20.0f);
            VectorGraphics.FillColor(VectorGraphics.Layer.One, _circleColor);
            VectorGraphics.Fill(VectorGraphics.Layer.One);
        }

    }
}
