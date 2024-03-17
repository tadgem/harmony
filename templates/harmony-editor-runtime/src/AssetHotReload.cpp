#include "AssetHotReload.h"
#include "Core/Log.hpp"
#include "Core/Program.h"

harmony::AssetHotReloadProvider::AssetHotReloadProvider(const std::string &name) : m_Name(name) {
}

harmony::String harmony::AssetHotReloadProvider::GetActionName(efsw::Action action) {
    switch (action) {
        case efsw::Action::Add:
            return "Add";
        case efsw::Action::Delete:
            return "Delete";
        case efsw::Action::Modified:
            return "Modified";
        case efsw::Action::Moved:
            return "Moved";
        default:
            return "?";
    }
}

harmony::AssetHotReload::AssetHotReload(Program &prog) : ProgramComponent(GetTypeHash<AssetHotReload>()),
                                                         p_Program(prog) {
    p_FileWatcher = new efsw::FileWatcher();
}

harmony::AssetHotReload::~AssetHotReload() {
}

void harmony::AssetHotReload::Init() {
    if (p_Program.m_Project) {
        std::string projDirectory = p_Program.m_Project->m_ProjectDirectory;
        std::string shadersDirectory = projDirectory + "\\assets";

        efsw::FileWatchListener *listener = this;

        p_DirectoryWatchID = p_FileWatcher->addWatch(shadersDirectory, listener, true);
        p_FileWatcher->watch();

        for (int i = 0; i < p_HotReloadProviders.size(); i++) {
            p_HotReloadProviders[i]->Init();
        }
    }

}

void harmony::AssetHotReload::Update() {
}

void harmony::AssetHotReload::Render() {
}

void harmony::AssetHotReload::Cleanup() {
}

nlohmann::json harmony::AssetHotReload::ToJson() {
    return nlohmann::json();
}

void harmony::AssetHotReload::FromJson(const nlohmann::json &json) {
}

void harmony::AssetHotReload::AddHotReloadProvider(RefCntPtr<AssetHotReloadProvider> provider) {
    for (auto p: p_HotReloadProviders) {
        if (provider->m_Name == p->m_Name) {
            harmony::log::warn("AssetHotReload : Provider with name : {} : already in provider collection, skipping.",
                               provider->m_Name);
            return;
        }
    }

    p_HotReloadProviders.emplace_back(provider);
}

void
harmony::AssetHotReload::handleFileAction(efsw::WatchID watchid, const std::string &dir, const std::string &filename,
                                          efsw::Action action, std::string oldFilename) {
    for (int i = 0; i < p_HotReloadProviders.size(); i++) {
        p_HotReloadProviders[i]->OnChange(filename, dir, action);
    }
}

