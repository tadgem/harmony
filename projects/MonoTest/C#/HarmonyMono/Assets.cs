using System;
using System.Runtime.CompilerServices;

namespace Harmony
{
    public struct AssetHandle
    {
        string  Path;
        uint    Index;
        ulong   TypeHash; 
    }

    public static class AssetMethods
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static AssetHandle[] GetAssetsAtPath(string path);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static TextureAsset GetTextureAsset(AssetHandle handle);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static Mesh GetMeshAsset(AssetHandle handle);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static ShaderStage GetShaderStageAsset(AssetHandle handle);
    }
}
