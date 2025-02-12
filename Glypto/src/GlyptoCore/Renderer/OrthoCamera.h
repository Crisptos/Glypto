#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace Glypto
{
    class OrthoCamera
    {
    public:
        OrthoCamera(float left, float right, float bottom, float top, glm::vec3 pos, float rot);
        ~OrthoCamera();

        inline glm::mat4 &GetViewProjMat() { return m_ViewProjMat; };
        inline void SetPosition(glm::vec3 &pos)
        {
            m_Pos = pos;
            m_ViewMat = glm::translate(m_ViewMat, -m_Pos);
            RecalcViewProjMat();
        }
        glm::vec3 &GetPosition() { return m_Pos; }
        inline void SetRotation(float &rot)
        {
            m_Rotation = rot;
            RecalcViewProjMat();
        }
        float &GetRotation() { return m_Rotation; }
        inline void RecalcViewProjMat() { m_ViewProjMat = m_ProjectionMat * m_ViewMat; }

    private:
        glm::vec3 m_Pos;
        float m_Rotation;
        glm::mat4 m_ProjectionMat;
        glm::mat4 m_ViewMat;
        glm::mat4 m_ViewProjMat;
    };
}