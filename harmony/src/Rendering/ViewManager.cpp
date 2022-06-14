#include "Core/Log.hpp"
#include "Rendering/ViewManager.h"

harmony::ViewManager::ViewManager() : p_HandleCounter(0)
{
}

harmony::WeakRef<harmony::View> harmony::ViewManager::AddView()
{
    Ref<View> view = CreateRef<View>();

    p_Views.emplace_back(view);

    return GetWeakRef<View>(view);
}

void harmony::ViewManager::RemoveView(WeakRef<View> view)
{
    int indexToRemove = -1;
    for (int i = 0; i < p_Views.size(); i++)
    {
        if (p_Views[i] == view.lock())
        {
            indexToRemove = i;
        }
    }

    if (indexToRemove >= 0)
    {
        p_Views[indexToRemove].reset();
        p_Views.erase(p_Views.begin() + indexToRemove);
    }
}

void harmony::ViewManager::SetViewActive(WeakRef<View> viewWeakRef, bool active)
{
    if (viewWeakRef.expired())
    {
        harmony::log::warn("Passed Weak Ref to view which is not managed by view manager! : ", viewWeakRef);
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
                harmony::log::info("View with handle : {} is already active!", view);
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