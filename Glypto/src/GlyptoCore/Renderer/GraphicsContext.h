#pragma once

namespace Glypto
{
    class GraphicsContext
    {
    public:
        virtual void InitializeContext() = 0;
        virtual void SwapWindowBuffers() = 0;

    private:
    };
}