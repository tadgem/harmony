using System;
using System.Runtime.CompilerServices;

namespace Harmony
{
#pragma warning disable CS0169
    public class AssetHandle
    {
        public string Path;
        public uint Index;
        public ulong TypeHash; 
    }
#pragma warning restore CS0169

    public static class AssetMethods
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static AssetHandle[] GetAssetsAtPath(string path);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static TextureAsset GetTextureAsset(AssetHandle handle);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static Mesh GetMeshAsset(AssetHandle handle);
    }
}
