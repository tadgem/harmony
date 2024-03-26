#pragma once

#include "Core/Alias.h"
#include "Core/Memory.h"
#include "Core/ProgramComponent.h"
#include "efsw/efsw.hpp"
#include "STL/Vector.h"

namespace harmony {

    class AssetHotReloadProvider {
    public:
        AssetHotReloadProvider(const String &name);

        virtual void Init() = 0;

        virtual void OnChange(const String &filename, const String &directory, efsw::Action action) = 0;

        const String &m_Name;

        String GetActionName(efsw::Action action);
    };

    class Program;

    class AssetHotReload : public ProgramComponent, public efsw::FileWatchListener {
    public:
        AssetHotReload(Program &prog);

        ~AssetHotReload();

        virtual void Init() override;

        virtual void Update() override;

        virtual void Render() override;

        virtual void Cleanup() override;

        virtual Json ToJson() override;

        virtual void FromJson(const Json &json) override;

        void AddHotReloadProvider(RefCntPtr<AssetHotReloadProvider> provider);

    protected:
        Vector<RefCntPtr<AssetHotReloadProvider>> p_HotReloadProviders;

        Program &p_Program;

        efsw::FileWatcher *p_FileWatcher;
        efsw::WatchID p_DirectoryWatchID;

        // Inherited via FileWatchListener
        virtual void handleFileAction(efsw::WatchID watchid, const String &dir, const String &filename,
                                      efsw::Action action, String oldFilename) override;
    };
}