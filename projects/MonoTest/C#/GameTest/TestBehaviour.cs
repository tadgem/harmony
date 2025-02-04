﻿using Harmony;
using System;
using System.Numerics;

namespace GameTest
{
    public class TestBehaviour : Behaviour
    {
        public float Speed = 3.0f;
        private Scene _scene;
        private TransformComponent _transform;
        private float _boxMove = 0.0f;
        VectorGraphics.NVGcolor _circleColor = new VectorGraphics.NVGcolor();

        public override void Init()
        {
            _scene = SceneMethods.GetActiveScene();
            _transform = _scene.GetComponent<TransformComponent>(Self);
            Vector3 v = _transform.Position;
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
            Vector3 euler = _transform.Euler;
            Vector3 position = _transform.Position;
            Vector3 forward = _transform.Forward;

            euler.X += delta * Speed * Speed;
            position += forward * delta * (Speed / Speed);
            _transform.Euler = euler;
            _transform.Position = position;

            if (Input.GetKeyButton(Input.Key.Space))
            {
                Log.Info("Space pressed");
                // SceneMethods.LoadScene("TestDupe.harmonyscene");
            }

            var mouse = Input.GetMousePosition();

            VectorGraphics.FontFace(VectorGraphics.Layer.One, "carbontype");
            VectorGraphics.FontSize(VectorGraphics.Layer.One, 60.0f);
            VectorGraphics.FillColor(VectorGraphics.Layer.One, _circleColor);
            VectorGraphics.Text(VectorGraphics.Layer.One, 15.0f, 60.0f, $"Delta Time : {delta}");

            VectorGraphics.BeginPath(VectorGraphics.Layer.One);
            VectorGraphics.Rect(VectorGraphics.Layer.One, Math.Abs(mouse.X), Math.Abs(mouse.Y), 300.0f, 400.0f);
            VectorGraphics.FillColor(VectorGraphics.Layer.One, _circleColor);
            VectorGraphics.Fill(VectorGraphics.Layer.One);

            VectorGraphics.BeginPath(VectorGraphics.Layer.One);
            VectorGraphics.Rect(VectorGraphics.Layer.One, Math.Abs(mouse.X), Math.Abs(mouse.Y), 200.0f + position.Y, 200.0f);
            VectorGraphics.FillColor(VectorGraphics.Layer.One, new VectorGraphics.NVGcolor(1.0f, 1.0f, 1.0f, 1.0f));
            VectorGraphics.Fill(VectorGraphics.Layer.One);


        }

    }
}
