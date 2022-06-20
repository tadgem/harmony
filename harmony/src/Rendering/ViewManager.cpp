#include "Core/Log.hpp"
#include "Rendering/ViewManager.h"
#include "Rendering/Renderer.h"
#if HARMONY_DEBUG
#include "ImGui/imgui.h"
#endif

uint32_t harmony::ViewManager::p_HandleCounter = 0;

harmony::ViewManager::ViewManager(Renderer& renderer) : p_Renderer(renderer)
{
}

harmony::WeakRef<harmony::View> harmony::ViewManager::AddView(const std::string& name)
{
    Ref<View> view = CreateRef<View>(name);

    p_Views.emplace(view, std::vector<WeakRef<Pipeline>>());

    return GetWeakRef<View>(view);
}

void harmony::ViewManager::RemoveView(WeakRef<View> view)
{
    if (view.expired())
    {
        harmony::log::error("Removing expired view weak ref!");
        return;
    }
    {
        Ref<View> _view = view.lock();
        if (p_Views.find(_view) != p_Views.end())
        {
            p_Views.erase(_view);
        }
    }
}

void harmony::ViewManager::SetViewActive(WeakRef<View> viewWeakRef, bool active)
{
    if (viewWeakRef.expired())
    {
        harmony::log::warn("Passed Weak Ref to view which is not managed by view manager!");
        return;
    }

    auto view = viewWeakRef.lock();

    int indexToRemove = -1;

    for (int i = 0; i < m_ActiveViews.size(); i++)
    {
        if (m_ActiveViews[i].lock() == view)
        {
            if (active)
            {
                harmony::log::info("View already active!");
                return;
            }
            else
            {
                indexToRemove = i;
            }
        }
    }

    if (indexToRemove >= 0)
    {
        m_ActiveViews.erase(m_ActiveViews.begin() + indexToRemove);
    }
    else
    {
        m_ActiveViews.emplace_back(viewWeakRef);
    }

}

void harmony::ViewManager::AddViewPipelineAssociation(WeakRef<View> viewWeakRef, WeakRef<Pipeline> pipelineHandle)
{
    if (viewWeakRef.expired())
    {
        harmony::log::error("Trying to add pipeline association to a view which is expired.");
        return;
    }

    Ref<View> view = viewWeakRef.lock();

    if (p_Views.find(view) == p_Views.end())
    {
        harmony::log::error("Trying to add pipeline association to a view not managed by this View Manager.");
        return;
    }

    p_Views[view].emplace_back(pipelineHandle);
}

#if HARMONY_DEBUG
void harmony::ViewManager::OnImGui()
{
    if (ImGui::Begin("View Manager"))
    {
        ImGui::Text("Views");
        ImGui::Separator();

        for (auto& [view, pipelines] : p_Views)
        {
            ImGui::Text(view->m_Name.c_str());
        }
    }
    ImGui::End();
}
#endif

bgfx::ViewId harmony::ViewManager::GetViewID()
{
    bgfx::ViewId v = p_HandleCounter;
    p_HandleCounter++;
    return v;
}
