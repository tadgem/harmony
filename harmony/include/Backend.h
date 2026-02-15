#pragma once

namespace harmony
{
  class Backend
  {
  public:
    virtual void Init() = 0;
    virtual void PreFrame() = 0;
    virtual void EndFrame() = 0;
    virtual void Cleanup() = 0;
    virtual bool ShouldRun() = 0;

  };
}