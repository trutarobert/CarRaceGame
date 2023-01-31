#include "object3D.h"

#include <vector>
#include "core/engine.h"
#include "utils/gl_utils.h"
#include <iostream>

Mesh* object3D::DrawCar(const std::string& name, glm::vec3 color1, glm::vec3 color2)
{
    std::vector<VertexFormat> vertices = {
        //fereastra 1
        VertexFormat(glm::vec3(2, 2, 0), color1),
        VertexFormat(glm::vec3(6, 2, 0), color1),
        VertexFormat(glm::vec3(3, 3, 1), color1),
        VertexFormat(glm::vec3(5, 3, 1), color1),
        //2
        VertexFormat(glm::vec3(2, 2, 4), color1),
        VertexFormat(glm::vec3(6, 2, 4), color1),
        VertexFormat(glm::vec3(3, 3, 3), color1),
        VertexFormat(glm::vec3(5, 3, 3), color1),
        //3
        VertexFormat(glm::vec3(6, 2, 4), color1),
        VertexFormat(glm::vec3(6, 2, 0), color1),
        VertexFormat(glm::vec3(5, 3, 3), color1),
        VertexFormat(glm::vec3(5, 3, 1), color1),
        //4
        VertexFormat(glm::vec3(2, 2, 4), color1),
        VertexFormat(glm::vec3(2, 2, 0), color1),
        VertexFormat(glm::vec3(3, 3, 3), color1),
        VertexFormat(glm::vec3(3, 3, 1), color1),
        //capota
        VertexFormat(glm::vec3(6, 2, 4), color2),
        VertexFormat(glm::vec3(6, 2, 0), color2),
        VertexFormat(glm::vec3(7, 2, 4), color2),
        VertexFormat(glm::vec3(7, 2, 0), color2),
        //portbagaj
        VertexFormat(glm::vec3(2, 2, 4), color2),
        VertexFormat(glm::vec3(2, 2, 0), color2),
        VertexFormat(glm::vec3(1, 2, 4), color2),
        VertexFormat(glm::vec3(1, 2, 0), color2),
        //bara fata
        VertexFormat(glm::vec3(7, 2, 4), color2),
        VertexFormat(glm::vec3(7, 2, 0), color2),
        VertexFormat(glm::vec3(7, 1, 4), color2),
        VertexFormat(glm::vec3(7, 1, 0), color2),
        //bara spate
        VertexFormat(glm::vec3(1, 2, 4), color2),
        VertexFormat(glm::vec3(1, 2, 0), color2),
        VertexFormat(glm::vec3(0, 1, 4), color2),
        VertexFormat(glm::vec3(0, 1, 0), color2),
        //aripa dreapta
        VertexFormat(glm::vec3(1, 2, 0), color2),
        VertexFormat(glm::vec3(7, 2, 0), color2),
        VertexFormat(glm::vec3(0, 1, 0), color2),
        VertexFormat(glm::vec3(7, 1, 0), color2),
        //aripa stanga
        VertexFormat(glm::vec3(1, 2, 4), color2),
        VertexFormat(glm::vec3(7, 2, 4), color2),
        VertexFormat(glm::vec3(0, 1, 4), color2),
        VertexFormat(glm::vec3(7, 1, 4), color2),
        //acoperisi
        VertexFormat(glm::vec3(3, 3, 3), color2),
        VertexFormat(glm::vec3(3, 3, 1), color2),
        VertexFormat(glm::vec3(5, 3, 3), color2),
        VertexFormat(glm::vec3(5, 3, 1), color2),
        //podea
        VertexFormat(glm::vec3(0, 1, 4), color2),
        VertexFormat(glm::vec3(0, 1, 0), color2),
        VertexFormat(glm::vec3(7, 1, 4), color2),
        VertexFormat(glm::vec3(7, 1, 0), color2),
        //cauciuc 1
        VertexFormat(glm::vec3(2, 0, 4), glm::vec3(0.25, 0.25, 0.25)),
        VertexFormat(glm::vec3(3, 0, 4), glm::vec3(0.25, 0.25, 0.25)),
        VertexFormat(glm::vec3(2, 1, 4), glm::vec3(0.25, 0.25, 0.25)),
        VertexFormat(glm::vec3(3, 1, 4), glm::vec3(0.25, 0.25, 0.25)),
        VertexFormat(glm::vec3(2, 0, 3), glm::vec3(0.25, 0.25, 0.25)),
        VertexFormat(glm::vec3(3, 0, 3), glm::vec3(0.25, 0.25, 0.25)),
        VertexFormat(glm::vec3(2, 1, 3), glm::vec3(0.25, 0.25, 0.25)),
        VertexFormat(glm::vec3(3, 1, 3), glm::vec3(0.25, 0.25, 0.25)),
        //2
        VertexFormat(glm::vec3(5, 0, 4), glm::vec3(0.25, 0.25, 0.25)),
        VertexFormat(glm::vec3(6, 0, 4), glm::vec3(0.25, 0.25, 0.25)),
        VertexFormat(glm::vec3(5, 1, 4), glm::vec3(0.25, 0.25, 0.25)),
        VertexFormat(glm::vec3(6, 1, 4), glm::vec3(0.25, 0.25, 0.25)),
        VertexFormat(glm::vec3(5, 0, 3), glm::vec3(0.25, 0.25, 0.25)),
        VertexFormat(glm::vec3(6, 0, 3), glm::vec3(0.25, 0.25, 0.25)),
        VertexFormat(glm::vec3(5, 1, 3), glm::vec3(0.25, 0.25, 0.25)),
        VertexFormat(glm::vec3(6, 1, 3), glm::vec3(0.25, 0.25, 0.25)),
        //3
        VertexFormat(glm::vec3(2, 0, 0), glm::vec3(0.25, 0.25, 0.25)),
        VertexFormat(glm::vec3(3, 0, 0), glm::vec3(0.25, 0.25, 0.25)),
        VertexFormat(glm::vec3(2, 1, 0), glm::vec3(0.25, 0.25, 0.25)),
        VertexFormat(glm::vec3(3, 1, 0), glm::vec3(0.25, 0.25, 0.25)),
        VertexFormat(glm::vec3(2, 0, 1), glm::vec3(0.25, 0.25, 0.25)),
        VertexFormat(glm::vec3(3, 0, 1), glm::vec3(0.25, 0.25, 0.25)),
        VertexFormat(glm::vec3(2, 1, 1), glm::vec3(0.25, 0.25, 0.25)),
        VertexFormat(glm::vec3(3, 1, 1), glm::vec3(0.25, 0.25, 0.25)),
        //4
        VertexFormat(glm::vec3(5, 0, 0), glm::vec3(0.25, 0.25, 0.25)),
        VertexFormat(glm::vec3(6, 0, 0), glm::vec3(0.25, 0.25, 0.25)),
        VertexFormat(glm::vec3(5, 1, 0), glm::vec3(0.25, 0.25, 0.25)),
        VertexFormat(glm::vec3(6, 1, 0), glm::vec3(0.25, 0.25, 0.25)),
        VertexFormat(glm::vec3(5, 0, 1), glm::vec3(0.25, 0.25, 0.25)),
        VertexFormat(glm::vec3(6, 0, 1), glm::vec3(0.25, 0.25, 0.25)),
        VertexFormat(glm::vec3(5, 1, 1), glm::vec3(0.25, 0.25, 0.25)),
        VertexFormat(glm::vec3(6, 1, 1), glm::vec3(0.25, 0.25, 0.25))
    };
    std::vector<unsigned int> indices = {
        //ferestre
        0, 1, 2, 1, 2, 3,
        4, 5, 6, 5, 6, 7,
        8, 9, 10, 9, 10, 11,
        12, 13, 14, 13, 14, 15,
        //capota
        16, 17, 18, 17, 18, 19,
        //portbagaj
        20, 21, 22, 21, 22, 23,
        //bara fata
        24, 25, 26, 25, 26, 27,
        //bara spate
        28, 29, 30, 29, 30, 31,
        //aripi
        32, 33, 34, 33, 34, 35,
        36, 37, 38, 37, 38, 39,
        //acoperisi
        40, 41, 42, 41, 42, 43,
        //podea
        44, 45, 46, 45, 46, 47,
        //cauciuc 1
        48, 49, 50, 49, 50, 51,
        52, 53, 54, 53, 54, 55,
        49, 51, 53, 51, 53, 55,
        48, 50, 52, 50, 52, 54,
        48, 49, 52, 49, 52, 53,
        //2
        56, 57, 58, 57, 58, 59,
        60, 61, 62, 61, 62, 63,
        57, 59, 61, 59, 61, 63,
        56, 58, 60, 56, 60, 62,
        56, 57, 60, 57, 60, 61,
        //3
        64, 65, 66, 65, 66, 67,
        68, 69, 70, 69, 70, 71,
        65, 67, 69, 67, 69, 71,
        64, 66, 68, 66, 68, 70,
        64, 65, 68, 65, 68, 69,
        //4
        72, 73, 74, 73, 74, 75,
        76, 77, 78, 77, 78, 79,
        73, 75, 77, 75, 77, 79,
        72, 74, 76, 74, 76, 78,
        72, 73, 76, 73, 76, 77
    };
    

    Mesh* object = new Mesh(name);
    object->InitFromData(vertices, indices);
    return object;
}

Mesh* object3D::DrawTree(const std::string& name, glm::vec3 color1, glm::vec3 color2)
{
    std::vector<VertexFormat> vertices = {
        //trunchi
        VertexFormat(glm::vec3(0, 0, 2), color1),
        VertexFormat(glm::vec3(2, 0, 2), color1),
        VertexFormat(glm::vec3(0, 0, 0), color1),
        VertexFormat(glm::vec3(2, 0, 0), color1),
        VertexFormat(glm::vec3(0, 4, 2), color1),
        VertexFormat(glm::vec3(2, 4, 2), color1),
        VertexFormat(glm::vec3(0, 4, 0), color1),
        VertexFormat(glm::vec3(2, 4, 0), color1),
        //frunze
        VertexFormat(glm::vec3(-2, 4, 4), color2),
        VertexFormat(glm::vec3(4, 4, 4), color2),
        VertexFormat(glm::vec3(-2, 4, -2), color2),
        VertexFormat(glm::vec3(4, 4, -2), color2),
        VertexFormat(glm::vec3(-2, 12, 4), color2),
        VertexFormat(glm::vec3(4, 12, 4), color2),
        VertexFormat(glm::vec3(-2, 12, -2), color2),
        VertexFormat(glm::vec3(4, 12, -2), color2),
    };
    std::vector<unsigned int> indices = {
        //trunchi
        0, 1, 2, 1, 2, 3,
        0, 1, 4, 1, 4, 5,
        1, 3, 5, 3, 5, 7,
        3, 2, 7, 2, 7, 6,
        2, 0, 6, 0, 6, 4,
        //frunze
        8, 9, 10, 9, 10, 11,
        12, 13, 14, 13, 14, 15,
        8, 9, 12, 9, 12, 13,
        9, 11, 13, 11, 13, 15,
        11, 10, 15, 10, 15, 14,
        10, 8, 14, 8, 14, 12
    };
    Mesh* object = new Mesh(name);
    object->InitFromData(vertices, indices);
    return object;
}

float object3D::getZ(float x, float R, float cx, float cz)
{
    return cz - sqrt(R * R - (x - cx) * (x - cx));
}
Mesh* object3D::DrawTrack(const std::string &name, glm::vec3 color, std::vector<VertexFormat>* vc1, \
    std::vector<VertexFormat>* vc2, std::vector<VertexFormat>* vcTree)
{
    std::vector<VertexFormat> vertices;

    //glm::vec3 color2 = { 0, 1, 0 };
    float x, z;
    float pas = 0.5;
    for (float i = 0; i > -145; i -= pas) {
        x = i;
        z = getZ(x, 200, 50, 50);
        vertices.push_back(VertexFormat(glm::vec3(x, 0, -z), color));
    }
    for (float i = -145; i < 0; i += pas) {
        x = i;
        z = getZ(x, 150, -100, 150);
        vertices.push_back(VertexFormat(glm::vec3(x, 0, -z), color));
    }
    for (float i = -2; i < 45; i += pas) {
        x = i;
        z = getZ(x, 40, 5, 2);
        vertices.push_back(VertexFormat(glm::vec3(x, 0, z), color));
    }
    for (float i = 42; i > -1; i -= pas) {
        x = i;
        z = getZ(x, 40, 5, 24);
        vertices.push_back(VertexFormat(glm::vec3(x, 0, -z), color));
    }
    for (float i = 0; i > -80; i -= pas) {
        x = i;
        z = 16;
        vertices.push_back(VertexFormat(glm::vec3(x, 0, z), color));
    }
    for (float i = -78; i > -103; i -= pas) {
        x = i;
        z = getZ(x, 35, -70, 50);
        vertices.push_back(VertexFormat(glm::vec3(x, 0, z), color));
    }
    for (float i = -105; i < -26; i += pas) {
        x = i;
        z = 142 + x;
        vertices.push_back(VertexFormat(glm::vec3(x, 0, z), color));
    }
    for (float i = -25; i < 12; i += pas) {
        x = i;
        z = getZ(x, 33, -10, -87);
        vertices.push_back(VertexFormat(glm::vec3(x, 0, -z), color));
    }
    for (float i = 10; i < 102; i += pas) {
        x = i;
        z = 122 - x;
        vertices.push_back(VertexFormat(glm::vec3(x, 0, z), color));
    }
    for (float i = 100; i < 129; i += pas) {
        x = i;
        z = getZ(x, 30, 100, 50);
        vertices.push_back(VertexFormat(glm::vec3(x, 0, z), color));
    }
    for (float i = 130; i > 40; i -= pas) {
        x = i;
        z = 170 - x;
        vertices.push_back(VertexFormat(glm::vec3(x, 0, z), color));
    }
    for (float i = 40; i > -2; i -= pas) {
        x = i;
        z = getZ(x, 55, 4, -89);
        vertices.push_back(VertexFormat(glm::vec3(x, 0, -z), color));
    }

    std::vector<VertexFormat> allVer;
    glm::vec3 D, P, A, R;
    glm::vec3 UP = { 0, 1, 0 };
    for (int i = 1; i < vertices.size(); i++) {
        D = vertices[i].position - vertices[i - 1].position;
        P = glm::normalize(glm::cross(D, UP));
        R = vertices[i - 1].position + P * 5.5f;
        A = vertices[i - 1].position - P * 5.5f;
        allVer.push_back(VertexFormat(R, vertices[i - 1].color));
        allVer.push_back(VertexFormat(A, vertices[i - 1].color));

        if (i % 10 == 0) {
            glm::vec3 P1 = vertices[i - 1].position + P * 2.5f;
            (*vc1).push_back(VertexFormat(P1, vertices[i - 1].color));
        }
        if (i % 10 == 0) {
            glm::vec3 P2 = vertices[i - 1].position - P * 2.5f;
            (*vc2).push_back(VertexFormat(P2, vertices[i - 1].color));
        }
        if (i % 40 == 0) {
            glm::vec3 P3 = vertices[i - 1].position - P * 10.0f;
            (*vcTree).push_back(VertexFormat(P3, vertices[i - 1].color));
        }
    }

    std::vector<unsigned int> indices;
    int N = allVer.size();
    for (int i = 0; i < N; i++) {
        indices.push_back(i);
        indices.push_back((i+1) % N);
        indices.push_back((i + 2) % N);
    }

    Mesh* object = new Mesh(name);
    //object->SetDrawMode(GL_LINE_LOOP);
    object->InitFromData(allVer, indices);
    return object;
}
Mesh* object3D::DrawGround(const std::string& name, glm::vec3 color)
{
    std::vector<VertexFormat> vertices;
    for (int i = -250; i < 250; i++) {
        for (int j = -250; j < 250; j++) {
            vertices.push_back(VertexFormat(glm::vec3(j, -0.05, i), color));
        }
    }
    std::vector<unsigned int> indices;
    for (int i = 0; i < 499; i++) {
        for (int j = 0; j < 499; j++) {
            int x = i * 500 + j;
            indices.push_back(x);
            indices.push_back(x + 1);
            indices.push_back(x + 500);

            indices.push_back(x + 1);
            indices.push_back(x + 500);
            indices.push_back(x + 501);
        }
    }
    Mesh* object = new Mesh(name);
    object->InitFromData(vertices, indices);
    return object;
}
