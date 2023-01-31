#pragma once

#include <string>
#include <iostream>
#include "core/gpu/mesh.h"
#include "utils/glm_utils.h"


namespace object3D
{
    float getZ(float x, float R, float cx, float cz);
    Mesh* DrawTrack(const std::string &name, glm::vec3 color, std::vector<VertexFormat> *vc1, \
        std::vector<VertexFormat>* vc2, std::vector<VertexFormat>* vcTree);
    Mesh* DrawCar(const std::string& name, glm::vec3 color1, glm::vec3 color2);
    Mesh* DrawTree(const std::string& name, glm::vec3 color1, glm::vec3 color2);
    Mesh* DrawGround(const std::string& name, glm::vec3 color);
}
