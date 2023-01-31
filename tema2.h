#pragma once

#include "components/simple_scene.h"
#include "lab_m1/tema2/lab_camera.h"


namespace m1
{
    class tema2 : public gfxc::SimpleScene
    {
     public:
        tema2();
        ~tema2();

        void Init() override;

     private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void RenderMesh(Mesh *mesh, Shader *shader, const glm::mat4 &modelMatrix) override;

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;

        void RenderScene();
        bool checkOnTrack(float xc, float zc);
        bool checkColision();
        float triangleArea(glm::vec3 A, glm::vec3 B, glm::vec3 C);
        void translateEnemy1(float deltaTime);
        void translateEnemy2(float deltaTime);

     protected:
        implemented::Camera_lab *cameraP;
        glm::mat4 projectionP;
        implemented::Camera_lab* cameraO;
        glm::mat4 projectionO;
        bool isOrtho;
        
        std::vector<VertexFormat>* vertices;
        glm::mat4 trackM;
        bool GO;

        float xcar, ycar, zcar;
        float dirCar, speed;
        int carPoz;

        std::vector<VertexFormat> vc1;
        float xc1, zc1, dc1, sc1;
        int pc1;
        std::vector<VertexFormat> vc2;
        float xc2, zc2, dc2, sc2;
        int pc2;

        std::vector<VertexFormat> vcTree;
    };
}   // namespace m1
