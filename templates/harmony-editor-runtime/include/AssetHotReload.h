#pragma once
#include "Core/Alias.h"
#include "Core/Memory.h"
#include "Core/ProgramComponent.h"
#include "efsw/efsw.hpp"

namespace harmony {

    class AssetHotReloadProvider {
    public:
        AssetHotReloadProvider(const std::string &name);

        virtual void Init() = 0;

        virtual void OnChange(const std::string &filename, const std::string &directory, efsw::Action action) = 0;

        const std::string &m_Name;

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

        virtual nlohmann::json ToJson() override;

        virtual void FromJson(const nlohmann::json &json) override;

        void AddHotReloadProvider(Ref<AssetHotReloadProvider> provider);

    protected:
        std::vector<Ref<AssetHotReloadProvider>> p_HotReloadProviders;

        Program &p_Program;

        efsw::FileWatcher *p_FileWatcher;
        efsw::WatchID p_DirectoryWatchID;

        // Inherited via FileWatchListener
        virtual void handleFileAction(efsw::WatchID watchid, const std::string &dir, const std::string &filename,
                                      efsw::Action action, std::string oldFilename) override;
    };
}