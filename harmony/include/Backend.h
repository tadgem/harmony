#pragma once

namespace harmony
{
  class Backend
  {
  public:
    virtual void init() = 0;
    virtual void pre_frame() = 0;
    virtual void end_frame() = 0;
    virtual void cleanup() = 0;
    virtual bool should_run() = 0;

  };
}