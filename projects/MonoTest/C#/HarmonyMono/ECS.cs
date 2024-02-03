using System;
using System.Numerics;
using System.Runtime.CompilerServices;
namespace Harmony
{
    /// <summary>
    /// ID must match entt entity index.
    /// </summary>
    public readonly struct Entity
    {
        public Entity(uint id)
        {
            ID = id;
        }

        public readonly uint ID;
        public static implicit operator uint (Entity entity) { return entity.ID; }

        public override string ToString()
        {
            return $"{ID}";
        }
    }

    public class MeshComponent : INativeComponent
    {
        public AssetHandle Asset
        {
            get => _native.GetMeshAsset();
            set => _native.SetMeshAsset(value);
        }

        private NativeMeshComponent _native;

        IntPtr INativeComponent.Handle { get => _native.Handle; set => _native.Handle = value; }

        public IntPtr GetNativeHandle(Scene scene, Entity entity)
        {
            return scene.GetEntityMesh(entity).Handle;
        }


    }

    public class CameraComponent : INativeComponent
    {
        private NativeCameraComponent _native;

        IntPtr INativeComponent.Handle { get => _native.Handle; set => _native.Handle = value; }

        public IntPtr GetNativeHandle(Scene scene, Entity entity)
        {
            return scene.GetEntityCamera(entity).Handle;
        }
    }

    public class MaterialComponent : INativeComponent
    {
        private NativeMaterialComponent _native;

        IntPtr INativeComponent.Handle { get => _native.Handle; set => _native.Handle = value; }

        public IntPtr GetNativeHandle(Scene scene, Entity entity)
        {
            return scene.GetEntityMaterial(entity).Handle;
        }
    }

    public class DirectionalLightComponent : INativeComponent
    {
        public Vector4 Diffuse
        {
            get => _native.GetDirectionalLightDiffuse();
            set => _native.SetDirectionalLightDiffuse(value);
        }

        public Vector4 Ambient
        {
            get => _native.GetDirectionalLightAmbient();
            set => _native.SetDirectionalLightAmbient(value);
        }

        private NativeDirectionalLightComponent _native;

        IntPtr INativeComponent.Handle { get => _native.Handle; set => _native.Handle = value; }

        public IntPtr GetNativeHandle(Scene scene, Entity entity)
        {
            return scene.GetEntityDirectionalLight(entity).Handle;
        }
    }

    public class PointLightComponent : INativeComponent
    {
        public Vector4 Diffuse
        {
            get => _native.GetPointLightDiffuse();
            set => _native.SetPointLightDiffuse(value);
        }

        public Vector4 Ambient
        {
            get => _native.GetPointLightAmbient();
            set => _native.SetPointLightAmbient(value);
        }

        public float Radius
        {
            get => _native.GetPointLightRadius();
            set => _native.SetPointLightRadius(value);
        }

        public float Intensity
        {
            get => _native.GetPointLightIntensity();
            set => _native.SetPointLightIntensity(value);
        }

        private NativePointLightComponent _native;

        IntPtr INativeComponent.Handle { get => _native.Handle; set => _native.Handle = value; }

        public IntPtr GetNativeHandle(Scene scene, Entity entity)
        {
            return scene.GetEntityPointLight(entity).Handle;
        }
    }

    public class SpotLightComponent : INativeComponent
    {
        public Vector4 Diffuse
        {
            get => _native.GetSpotLightDiffuse();
            set => _native.SetSpotLightDiffuse(value);
        }

        public Vector4 Ambient
        {
            get => _native.GetSpotLightAmbient();
            set => _native.SetSpotLightAmbient(value);
        }

        public float Radius
        {
            get => _native.GetSpotLightRadius();
            set => _native.SetSpotLightRadius(value);
        }

        public float Intensity
        {
            get => _native.GetSpotLightIntensity();
            set => _native.SetSpotLightIntensity(value);
        }

        public float Angle
        {
            get => _native.GetSpotLightAngle();
            set => _native.SetSpotLightAngle(value);
        }

        private NativeSpotLightComponent _native;

        IntPtr INativeComponent.Handle { get => _native.Handle; set => _native.Handle = value; }

        public IntPtr GetNativeHandle(Scene scene, Entity entity)
        {
            return scene.GetEntitySpotLight(entity).Handle;
        }
    }

    public class SkyComponent : INativeComponent
    {
        private NativeSkyComponent _native;

        public float SunSize
        {
            get => _native.GetSkySunSize();
            set => _native.SetSkySunSize(value);
        }

        public float SunBloom
        {
            get => _native.GetSkySunBloom();
            set => _native.SetSkySunBloom(value);
        }

        public float Exposition
        {
            get => _native.GetSkyExposition();
            set => _native.SetSkyExposition(value);
        }

        public float Turbidity
        {
            get => _native.GetSkyTurbidity();
            set => _native.SetSkyTurbidity(value);
        }

        public Vector3 Luminance
        {
            get => _native.GetSkyLuminance();
            set => _native.SetSkyLuminance(value);
        }

        IntPtr INativeComponent.Handle { get => _native.Handle; set => _native.Handle = value; }

        public IntPtr GetNativeHandle(Scene scene, Entity entity)
        {
            return scene.GetEntitySky(entity).Handle;
        }
    }

    public class TransformComponent : INativeComponent
    {
        private NativeTransformComponent _native;
        
        IntPtr INativeComponent.Handle { get => _native.Handle; set => _native.Handle = value; }

        public Vector3 Position
        {
            get => ECSMethods.GetTransformPosition(_native);
            set => ECSMethods.SetTransformPosition(_native, value);
        }

        public Vector3 Euler
        {
            get => ECSMethods.GetTransformEuler(_native);
            set => ECSMethods.SetTransformEuler(_native, value);
        }

        public Vector3 Scale
        {
            get => ECSMethods.GetTransformScale(_native);
            set => ECSMethods.SetTransformScale(_native, value);
        }

        public Vector3 Up
        {
            get => ECSMethods.GetTransformUp(_native);
        }

        public Vector3 Forward
        {
            get => ECSMethods.GetTransformForward(_native);
        }

        public Vector3 Right
        {
            get => ECSMethods.GetTransformRight(_native);
        }
        
        public IntPtr GetNativeHandle(Scene scene, Entity entity)
        {
            return scene.GetEntityTransform(entity).Handle;

        }
    }

    internal struct NativeTransformComponent
    {
        public IntPtr Handle;
    }

    internal struct NativeMeshComponent
    {
        public IntPtr Handle;
    }

    internal struct NativeMaterialComponent
    {
        public IntPtr Handle;
    }

    internal struct NativeDirectionalLightComponent
    {
        public IntPtr Handle;
    }

    internal struct NativePointLightComponent
    {
        public IntPtr Handle;
    }

    internal struct NativeSpotLightComponent
    {
        public IntPtr Handle;
    }

    internal struct NativeSkyComponent
    {
        public IntPtr Handle;
    }

    internal struct NativeCameraComponent
    {
        public IntPtr Handle;
    }


    internal static class ECSMethods
    {
        #region Transform
        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static NativeTransformComponent GetEntityTransform(this Scene scene, Entity entity);

        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static Vector3 GetTransformPosition(this NativeTransformComponent t);

        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static Vector3 GetTransformEuler(this NativeTransformComponent t);

        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static Vector3 GetTransformScale(this NativeTransformComponent t);

        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static Vector3 GetTransformForward(this NativeTransformComponent t);

        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static Vector3 GetTransformRight(this NativeTransformComponent t);

        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static Vector3 GetTransformUp(this NativeTransformComponent t);

        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static void SetTransformPosition(this NativeTransformComponent t, Vector3 pos);

        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static void SetTransformEuler(this NativeTransformComponent t, Vector3 euler);

        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static void SetTransformScale(this NativeTransformComponent t, Vector3 scale);
        #endregion

        #region Mesh
        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static NativeMeshComponent GetEntityMesh(this Scene scene, Entity entity);

        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static AssetHandle GetMeshAsset(this NativeMeshComponent mesh);

        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static void SetMeshAsset(this NativeMeshComponent mesh, AssetHandle handle);
        #endregion

        #region Material

        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static NativeMaterialComponent GetEntityMaterial(this Scene scene, Entity entity);
        #endregion

        #region Directional Light
        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static NativeDirectionalLightComponent GetEntityDirectionalLight(this Scene scene, Entity entity);

        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static Vector4 GetDirectionalLightDiffuse(this NativeDirectionalLightComponent light);
        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static Vector4 GetDirectionalLightAmbient(this NativeDirectionalLightComponent light);

        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static void SetDirectionalLightDiffuse(this NativeDirectionalLightComponent light, Vector4 v);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static void SetDirectionalLightAmbient(this NativeDirectionalLightComponent light, Vector4 v);

        #endregion

        #region Point Light
        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static NativePointLightComponent GetEntityPointLight(this Scene scene, Entity entity);

        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static Vector4 GetPointLightDiffuse(this NativePointLightComponent light);
        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static Vector4 GetPointLightAmbient(this NativePointLightComponent light);
        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static float GetPointLightIntensity(this NativePointLightComponent light);
        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static float GetPointLightRadius(this NativePointLightComponent light);

        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static void SetPointLightDiffuse(this NativePointLightComponent light, Vector4 v);

        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static void SetPointLightAmbient(this NativePointLightComponent light, Vector4 v);
        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static void SetPointLightIntensity(this NativePointLightComponent light, float v);

        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static void SetPointLightRadius(this NativePointLightComponent light, float v);

        #endregion

        #region Spot Lights
        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static NativeSpotLightComponent GetEntitySpotLight(this Scene scene, Entity entity);

        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static Vector4 GetSpotLightDiffuse(this NativeSpotLightComponent light);
        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static Vector4 GetSpotLightAmbient(this NativeSpotLightComponent light);
        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static float GetSpotLightIntensity(this NativeSpotLightComponent light);
        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static float GetSpotLightRadius(this NativeSpotLightComponent light);
        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static float GetSpotLightAngle(this NativeSpotLightComponent light);

        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static void SetSpotLightDiffuse(this NativeSpotLightComponent light, Vector4 v);

        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static void SetSpotLightAmbient(this NativeSpotLightComponent light, Vector4 v);
        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static void SetSpotLightIntensity(this NativeSpotLightComponent light, float v);

        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static void SetSpotLightRadius(this NativeSpotLightComponent light, float v);

        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static void SetSpotLightAngle(this NativeSpotLightComponent light, float v);
        #endregion

        #region Sky
        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static NativeSkyComponent GetEntitySky(this Scene scene, Entity entity);

        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static float GetSkySunSize(this NativeSkyComponent sky);
        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static float GetSkySunBloom(this NativeSkyComponent sky);
        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static float GetSkyExposition(this NativeSkyComponent sky);
        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static float GetSkyTurbidity(this NativeSkyComponent sky);
        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static Vector3 GetSkyLuminance(this NativeSkyComponent sky);

        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static float SetSkySunSize(this NativeSkyComponent sky, float v);
        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static float SetSkySunBloom(this NativeSkyComponent sky, float v);
        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static float SetSkyExposition(this NativeSkyComponent sky, float v);
        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static float SetSkyTurbidity(this NativeSkyComponent sky, float v);
        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static Vector3 SetSkyLuminance(this NativeSkyComponent sky, Vector3 v);

        #endregion

        #region Camera
        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static NativeCameraComponent GetEntityCamera(this Scene scene, Entity entity);
        #endregion
    }
}
