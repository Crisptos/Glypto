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

    inline void OrthoCamera::RecalcViewProjMat()
    {
        glm::mat4 camera_transform = glm::translate(glm::mat4(1.0f), m_Pos) * glm::rotate(glm::mat4(1.0f), glm::radians(m_Rotation), glm::vec3(0.0f, 0.0f, 1.0f));
        m_ViewMat = glm::inverse(camera_transform);
        m_ViewProjMat = m_ProjectionMat * m_ViewMat;
    }
}