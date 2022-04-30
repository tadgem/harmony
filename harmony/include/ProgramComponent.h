#pragma once
namespace harmony
{
    class ProgramComponent
    {
    public:

        virtual ~ProgramComponent() {};

        virtual void Init() = 0;
        virtual void Update() = 0;
        virtual void Render() = 0;
        virtual void Cleanup() = 0;
    };
};