#include "GlyptoCore/Renderer/OrthoCamera.h"

namespace Glypto
{
    OrthoCamera::OrthoCamera(float left, float right, float bottom, float top, glm::vec3 pos, float rot)
        : m_Pos(pos), m_Rotation(rot), m_ViewProjMat(glm::mat4(1.0f)), m_ProjectionMat(glm::ortho(left, right, bottom, top, -1.0f, 1.0f)), m_ViewMat(glm::translate(glm::mat4(1.0f), -pos))
    {
        RecalcViewProjMat();
    }

    OrthoCamera::~OrthoCamera()
    {
    }
}