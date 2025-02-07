#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace Glypto
{

    class OrthoCamera
    {
    public:
        OrthoCamera(float left, float right, float bottom, float top, float near, float far);
        ~OrthoCamera();

        glm::vec3 &GetPosition() { return m_Pos; }
        void SetPosition(const glm::vec3 &pos)
        {
            m_Pos = pos;
            RecalculateViewProjectionMatrix();
        }

        float &GetRotation() { return m_Rotation; }
        void SetRotation(const float &rotation)
        {
            m_Rotation = rotation;
            RecalculateViewProjectionMatrix();
        }

        const glm::mat4 GetViewProjectionMatrix() const { return m_ViewProjMat; }

    private:
        void RecalculateViewProjectionMatrix();

        float m_Rotation;
        glm::vec3 m_Pos;
        glm::mat4 m_ProjectionMat;
        glm::mat4 m_ViewMat;
        glm::mat4 m_ViewProjMat;
    };
}