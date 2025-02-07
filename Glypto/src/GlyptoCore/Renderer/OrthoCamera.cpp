#include "GlyptoCore/Renderer/OrthoCamera.h"

namespace Glypto
{
    OrthoCamera::OrthoCamera(float left, float right, float bottom, float top, float near, float far)
        : m_ProjectionMat(glm::ortho(left, right, bottom, top, near, far)), m_ViewMat(1.0f)
    {
        m_ViewProjMat = m_ProjectionMat * m_ViewMat;
    }

    OrthoCamera::~OrthoCamera()
    {

    }

    void OrthoCamera::RecalculateViewProjectionMatrix()
    {
        glm::mat4 transform = glm::translate(glm::mat4(1.0f), m_Pos);
        m_ViewMat = glm::inverse(transform);
        m_ViewProjMat = m_ProjectionMat * m_ViewMat;
    }
}