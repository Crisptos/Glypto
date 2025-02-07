#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace Glypto
{
    class PerspectiveCamera
    {
    public:
        PerspectiveCamera(float fov, float aspect_ration, glm::vec3 pos);
        ~PerspectiveCamera();

        glm::mat4 GetViewProjectionMatrix() const;

    private:
        glm::vec3 m_Pos;
        glm::vec3 m_Front;
        glm::vec3 m_Up;
        glm::mat4 m_ProjectionMat;
        glm::mat4 m_ViewMat;
    };
}