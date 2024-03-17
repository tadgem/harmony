using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace Harmony
{
    public enum DebugDrawChannel : byte
    {
        Editor,
        Game
    };

    public static class DebugDraw
    {
        [MethodImpl(MethodImplOptions.InternalCall)] 
        public extern static void SetColour(DebugDrawChannel channel, uint rgba);
        
        [MethodImpl(MethodImplOptions.InternalCall)] 
        public extern static void SetStipple(DebugDrawChannel channel, bool stipple, float scale, float offset);
        
        [MethodImpl(MethodImplOptions.InternalCall)] 
        public extern static void SetWireframe(DebugDrawChannel channel, bool wireframe);
        
        [MethodImpl(MethodImplOptions.InternalCall)] 
        public extern static void SetTranslate(DebugDrawChannel channel, Vector3 translate);
        
        [MethodImpl(MethodImplOptions.InternalCall)] 
        public extern static void MoveTo(DebugDrawChannel channel, Vector3 translate);
        
        [MethodImpl(MethodImplOptions.InternalCall)] 
        public extern static void LineTo(DebugDrawChannel channel, Vector3 translate);
        
        [MethodImpl(MethodImplOptions.InternalCall)] 
        public extern static void Circle(DebugDrawChannel channel, Vector3 normal, Vector3 center, float radius, float weight);
        
        [MethodImpl(MethodImplOptions.InternalCall)] 
        public extern static void Quad(DebugDrawChannel channel, Vector3 normal, Vector3 center, float size);
        
        [MethodImpl(MethodImplOptions.InternalCall)] 
        public extern static void Sphere(DebugDrawChannel channel, Vector3 center, float radius);
        
        [MethodImpl(MethodImplOptions.InternalCall)] 
        public extern static void Cylinder(DebugDrawChannel channel, Vector3 from, Vector3 to, float radius);
        
        [MethodImpl(MethodImplOptions.InternalCall)] 
        public extern static void Capsule(DebugDrawChannel channel, Vector3 from, Vector3 to, float radius);
        
        [MethodImpl(MethodImplOptions.InternalCall)] 
        public extern static void Cone(DebugDrawChannel channel, Vector3 from, Vector3 to, float radius);
        
        [MethodImpl(MethodImplOptions.InternalCall)] 
        public extern static void Grid(DebugDrawChannel channel, Vector3 normal, Vector3 center, uint size, float step);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void Orb(DebugDrawChannel channel, Vector3 center, float radius);
    }

}
