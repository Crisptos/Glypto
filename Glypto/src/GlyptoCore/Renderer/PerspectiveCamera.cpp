#include "GlyptoCore/Renderer/PerspectiveCamera.h"

namespace Glypto
{
    PerspectiveCamera::PerspectiveCamera(float fov, float aspect_ration, glm::vec3 pos)
        : m_Pos(pos), m_Front({0.0f, 0.0f, -1.0f}), m_Up({0.0f, 1.0f, 0.0f})
    {
        m_ProjectionMat = glm::perspective(fov, aspect_ration, 0.1f, 100.0f);
        m_ViewMat = glm::lookAt(m_Pos, m_Pos + m_Front, m_Up);
    }

    PerspectiveCamera::~PerspectiveCamera()
    {

    }

    glm::mat4 PerspectiveCamera::GetViewProjectionMatrix() const
    {
        return m_ProjectionMat * m_ViewMat;
    }
}