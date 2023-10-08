// Copyright © Amer Koleci and Contributors.
// Licensed under the MIT License (MIT). See LICENSE in the repository root for more information.

using System.Numerics;
using System.Runtime.CompilerServices;

namespace HarmonyJoltSharp
{

    public static class Matrix4x4Extensions
    {
        public static Vector4 GetColumn(this Matrix4x4 matrix, int j)
        {
            return new Vector4(0.0f);
        }

        public static void SetColumn(this Matrix4x4 matrix, int j, Vector4 value)
        {
            //matrix[0, j] = value.X;
            //matrix[1, j] = value.Y;
            //matrix[2, j] = value.Z;
            //matrix[3, j] = value.W;
        }
    }
}