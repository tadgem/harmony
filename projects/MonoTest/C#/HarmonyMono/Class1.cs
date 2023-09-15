using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HarmonyMono
{
    public interface IOnInit
    {
        void Init();
    }
    public interface IOnUpdate
    {
        void Update();
    }
    public interface IOnCleanup
    {
        void Cleanup();
    }
}
