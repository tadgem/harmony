using Harmony;
using System;
using System.Numerics;

namespace GameTest
{
    public class TestBehaviour : Behaviour
    {
        public float Speed = 3.0f;
        private Scene _scene;
        private NativeTransformComponent _transform;
        private float _boxMove = 0.0f;
        VectorGraphics.NVGcolor _circleColor = new VectorGraphics.NVGcolor();

        public override void Init()
        {
            _scene = SceneMethods.GetActiveScene();
            _transform = _scene.GetEntityTransform(Self);
            Vector3 v = _transform.GetTransformPosition();
            Log.Info($"I am entity : {Self} : Pos : {v}");
            _circleColor.r = 192.0f / 255.0f;
            _circleColor.g = 128.0f / 255.0f;
            _circleColor.b = 192.0f / 255.0f;
            _circleColor.a = 255.0f / 255.0f;
        }
        public override void Update()
        {
            float delta = (float) Time.GetFrameTime();
            _boxMove += delta * Speed * Speed ;
            Vector3 euler = _transform.GetTransformEuler();
            Vector3 position = _transform.GetTransformPosition();
            Vector3 forward = _transform.GetTransformForward();

            euler.X += delta * Speed * Speed;
            position += forward * delta * (Speed / Speed);
            _transform.SetTransformEuler(euler);
            _transform.SetTransformPosition(position);

            if (Input.GetKeyButton(Input.Key.Space))
            {
                Log.Info("Space pressed");
            }

            var mouse = Input.GetMousePosition();

            VectorGraphics.FontFace(VectorGraphics.Layer.One, "carbontype");
            VectorGraphics.FontSize(VectorGraphics.Layer.One, 60.0f);
            VectorGraphics.FillColor(VectorGraphics.Layer.One, _circleColor);
            VectorGraphics.Text(VectorGraphics.Layer.One, 15.0f, 60.0f, $"Delta Time : {delta}");

            VectorGraphics.BeginPath(VectorGraphics.Layer.One);
            VectorGraphics.Rect(VectorGraphics.Layer.One, Math.Abs(mouse.X), Math.Abs(mouse.Y), 300.0f, 400.0f);
            //VectorGraphics.Translate(VectorGraphics.Layer.One, _boxMove, 0.0f);
            VectorGraphics.FillColor(VectorGraphics.Layer.One, _circleColor);
            VectorGraphics.Fill(VectorGraphics.Layer.One);

            VectorGraphics.BeginPath(VectorGraphics.Layer.One);
            VectorGraphics.Rect(VectorGraphics.Layer.One, Math.Abs(mouse.X), Math.Abs(mouse.Y), 200.0f + position.Y, 200.0f);
            //VectorGraphics.Translate(VectorGraphics.Layer.One, _boxMove, 0.0f);
            VectorGraphics.FillColor(VectorGraphics.Layer.One, new VectorGraphics.NVGcolor(1.0f, 1.0f, 1.0f, 1.0f));
            VectorGraphics.Fill(VectorGraphics.Layer.One);


        }

    }
}
