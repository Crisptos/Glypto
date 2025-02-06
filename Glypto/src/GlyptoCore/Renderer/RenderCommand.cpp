#include "GlyptoCore/Renderer/RenderCommand.h"
#include "GlyptoCore/Renderer/OpenGL/OpenGLRendererAPI.h"

namespace Glypto
{
    RendererAPI *RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}