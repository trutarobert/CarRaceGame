#include "lab_m1/tema2/tema2.h"
#include "lab_m1/tema2/object3D.h"
#include "lab_m1/tema2/transform3D.h"

#include <vector>
#include <string>
#include <iostream>

using namespace std;
using namespace m1;


/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */


tema2::tema2()
{
}


tema2::~tema2()
{
}


void tema2::Init()
{   
    Mesh* track = object3D::DrawTrack("track", glm::vec3(0.6, 0.3, 0), &vc1, &vc2, &vcTree);
    AddMeshToList(track);
    vertices =  &(track->vertices);
    cout << (*vertices).size() << '\n';

    Mesh* car = object3D::DrawCar("car", glm::vec3(0, 0.47, 0.47), glm::vec3(1, 0, 0));
    AddMeshToList(car);
    Mesh* car1= object3D::DrawCar("car1", glm::vec3(0, 0.47, 0.47), glm::vec3(0, 1, 0));
    AddMeshToList(car1);
    Mesh* car2 = object3D::DrawCar("car2", glm::vec3(0, 0.47, 0.47), glm::vec3(0, 0, 1));
    AddMeshToList(car2);

    Mesh* tree = object3D::DrawTree("tree", glm::vec3(0.4, 0.2, 0), glm::vec3(0.2, 0.4, 0));
    AddMeshToList(tree);

    Mesh* ground = object3D::DrawGround("ground", glm::vec3(0, 0.6, 0));
    AddMeshToList(ground);

    GO = false;
    trackM = glm::mat4(1);
    trackM *= transform3D::Scale(0.15, 0.15, 0.15);

    dirCar = 3.14;
    xcar = 0;
    zcar = 21.5;
    ycar = 0;
    speed = 3;
    carPoz = 0;

    pc1 = 1;
    xc1 = 0;
    zc1 = 21;
    sc1 = 2.5;
    dc1 = 3.14;

    pc2 = 1;
    xc2 = 0;
    zc2 = 22;
    sc2 = 2.5;
    dc2 = 3.14;
    
    isOrtho = false;
    cameraP = new implemented::Camera_lab();
    cameraP->Set(glm::vec3(-2.5, 1.5, 0), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0));
    cameraP->distanceToTarget = 2.5;
    cameraP->TranslateRight(zcar);
    cameraP->RotateThirdPerson_OY(dirCar);
    projectionP = glm::perspective(RADIANS(60), window->props.aspectRatio, 0.01f, 200.0f);

    cameraO = new implemented::Camera_lab();
    cameraO->Set(glm::vec3(0.1, 2, 0), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0));
    cameraO->TranslateRight(-zcar);
    projectionO = glm::ortho(-6.0f, 6.0f, -3.0f, 3.0f, -20.0f, 20.0f);

    Shader* shader = new Shader("MyShader");
    shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "tema2", "shaders", "VertexShader.glsl"), GL_VERTEX_SHADER);
    shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "tema2", "shaders", "FragmentShader.glsl"), GL_FRAGMENT_SHADER);
    shader->CreateAndLink();
    shaders[shader->GetName()] = shader;
}


void tema2::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0.8, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
}

void tema2::RenderScene()
{
    RenderMesh(meshes["track"], shaders["MyShader"], trackM);

    glm::mat4 groundM = glm::mat4(1);
    groundM *= transform3D::Scale(0.1, 1, 0.1);
    RenderMesh(meshes["ground"], shaders["MyShader"], groundM);

    glm::mat4 treeM = glm::mat4(1);
    for (int i = 0; i < vcTree.size(); i++) {
        treeM = glm::mat4(1);
        glm::vec3 P = vcTree[i].position;
        P = glm::vec3(glm::vec4(P, 1) * trackM);

        treeM *= transform3D::Translate(P.x, 0, P.z);
        treeM *= transform3D::Scale(0.15, 0.15, 0.15);
        RenderMesh(meshes["tree"], shaders["MyShader"], treeM);
    }

    glm::mat4 carM = glm::mat4(1);
    carM *= transform3D::Translate(xcar, ycar, zcar);
    carM *= transform3D::Scale(0.08, 0.08, 0.08);
    carM *= transform3D::RotateOY(dirCar);
    carM *= transform3D::Translate(-4.5, 0, -2);
    RenderMesh(meshes["car"], shaders["MyShader"], carM);

    glm::mat4 c1M = glm::mat4(1);
    c1M *= transform3D::Translate(xc1, ycar, zc1);
    c1M *= transform3D::Scale(0.08, 0.08, 0.08);
    c1M *= transform3D::RotateOY(dc1);
    c1M *= transform3D::Translate(-4.5, 0, -2);
    RenderMesh(meshes["car1"], shaders["MyShader"], c1M);

    glm::mat4 c2M = glm::mat4(1);
    c2M *= transform3D::Translate(xc2, ycar, zc2);
    c2M *= transform3D::Scale(0.08, 0.08, 0.08);
    c2M *= transform3D::RotateOY(dc2);
    c2M *= transform3D::Translate(-4.5, 0, -2);
    RenderMesh(meshes["car2"], shaders["MyShader"], c2M);
}
void tema2::Update(float deltaTimeSeconds)
{
    if (GO) {
        translateEnemy1(deltaTimeSeconds);
        translateEnemy2(deltaTimeSeconds);
    }
    if (checkColision()) {
        speed = 0.1;
    }
    else {
        speed = 3;
    }
    RenderScene();
    //DrawCoordinateSystem(cameraP->GetViewMatrix(), projectionP);

    isOrtho = true;
    glClear(GL_DEPTH_BUFFER_BIT);
    glm::ivec2 resolution = window->GetResolution();
    glViewport(20, 20, resolution.x / 4, resolution.y / 4);
    RenderScene();
    //DrawCoordinateSystem(cameraO->GetViewMatrix(), projectionO);
    isOrtho = false;
}
bool tema2::checkColision()
{
    if (distance(glm::vec3(xcar, ycar, zcar), glm::vec3(xc1, ycar, zc1)) < 0.5 || \
        distance(glm::vec3(xcar, ycar, zcar), glm::vec3(xc2, ycar, zc2)) < 0.5)
        return true;
    else
        return false;
}
bool tema2::checkOnTrack(float xc, float zc)
{
    int pozL = carPoz - 50;
    int pozR = carPoz + 50;
    glm::vec3 P = { xc, 0, zc };
    for (int i = pozL; i < pozR; i++) {
        int poz = i;
        if (poz < 0) {
            poz += (*vertices).size();
        }
        else if(poz >= (*vertices).size()) {
            poz -= (*vertices).size();
        }
        if (poz < 2)
            poz += 2;

        glm::vec3 A = (*vertices)[poz].position;
        glm::vec3 B = (*vertices)[poz-1].position;
        glm::vec3 C = (*vertices)[poz-2].position;

        A = glm::vec3(glm::vec4(A, 1) * trackM);
        B = glm::vec3(glm::vec4(B, 1) * trackM);
        C = glm::vec3(glm::vec4(C, 1) * trackM);

        float area1 = triangleArea(A, B, C);
        float area2 = 0;
        area2 += triangleArea(A, B, P);
        area2 += triangleArea(A, C, P);
        area2 += triangleArea(B, C, P);

        if (abs(area1 - area2) < 0.01) {
            carPoz = poz;
            return true;
        }
    }
    return false;
}
float tema2::triangleArea(glm::vec3 A, glm::vec3 B, glm::vec3 C)
{
    glm::vec3 AB = A - B;
    glm::vec3 AC = A - C;
    float area = glm::length(glm::cross(AB, AC));
    return area;
}
void tema2::translateEnemy1(float deltaTime)
{
    pc1 %= vc1.size();

    glm::vec3 P = vc1[pc1].position;
    P = glm::vec3(glm::vec4(P, 1) * trackM);
    glm::vec3 D = normalize(P - glm::vec3(xc1, 0, zc1));

    dc1 = (D.z > 0) ? -acos(D.x) : acos(D.x);
    xc1 += sc1 * D.x * deltaTime;
    zc1 += sc1 * D.z * deltaTime;

    if (abs(P.x - xc1) < 0.1 && abs(P.z - zc1) < 0.1)
        pc1++;
}
void tema2::translateEnemy2(float deltaTime)
{
    pc2 %= vc2.size();

    glm::vec3 P = vc2[pc2].position;
    P = glm::vec3(glm::vec4(P, 1) * trackM);
    glm::vec3 D = normalize(P - glm::vec3(xc2, 0, zc2));

    dc2 = (D.z > 0) ? -acos(D.x) : acos(D.x);
    xc2 += sc2 * D.x * deltaTime;
    zc2 += sc2 * D.z * deltaTime;

    if (abs(P.x - xc2) < 0.1 && abs(P.z - zc2) < 0.1)
        pc2++;
}

void tema2::FrameEnd()
{
    //DrawCoordinateSystem(camera->GetViewMatrix(), projectionMatrix);
}


void tema2::RenderMesh(Mesh * mesh, Shader * shader, const glm::mat4 & modelMatrix)
{
    if (!mesh || !shader || !shader->program)
        return;

    // Render an object using the specified shader and the specified position
    shader->Use();
    int locationC = glGetUniformLocation(shader->program, "CarPos");
    glm::vec3 pos = { xcar, ycar, zcar };
    int locationM = glGetUniformLocation(shader->program, "mapColor");
    if (isOrtho) {
        glUniformMatrix4fv(shader->loc_view_matrix, 1, GL_FALSE, glm::value_ptr(cameraO->GetViewMatrix()));
        glUniformMatrix4fv(shader->loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionO));
        glUniformMatrix4fv(shader->loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));
        glUniform3fv(locationC, 1, glm::value_ptr(pos));
        glUniform1f(locationM, 0.8);
    }
    else {
        glUniformMatrix4fv(shader->loc_view_matrix, 1, GL_FALSE, glm::value_ptr(cameraP->GetViewMatrix()));
        glUniformMatrix4fv(shader->loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionP));
        glUniformMatrix4fv(shader->loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));
        glUniform3fv(locationC, 1, glm::value_ptr(pos));
        glUniform1f(locationM, 1.0);
    }
    mesh->Render();
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void tema2::OnInputUpdate(float deltaTime, int mods)
{
    // move the camera only if MOUSE_RIGHT button is pressed
    if (window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT))
    {
        float cameraSpeed = 6.0f;
        if (window->KeyHold(GLFW_KEY_W)) {
            cameraP->MoveForward(deltaTime * cameraSpeed);
        }
        if (window->KeyHold(GLFW_KEY_A)) {
            cameraP->TranslateRight(-deltaTime * cameraSpeed);
        }
        if (window->KeyHold(GLFW_KEY_S)) {
            cameraP->MoveForward(-deltaTime * cameraSpeed);
        }
        if (window->KeyHold(GLFW_KEY_D)) {
            cameraP->TranslateRight(deltaTime * cameraSpeed);
        }
        if (window->KeyHold(GLFW_KEY_Q)) {
            cameraP->TranslateUpward(-deltaTime * cameraSpeed);
        }
        if (window->KeyHold(GLFW_KEY_E)) {
            cameraP->TranslateUpward(deltaTime * cameraSpeed);
        }
    }
    if (window->KeyHold(GLFW_KEY_W)) {
        float X = xcar + cos(dirCar) * speed * deltaTime;
        float Z = zcar - sin(dirCar) * speed * deltaTime;
        if (checkOnTrack(X, Z))
        {
            xcar += cos(dirCar) * speed * deltaTime;
            zcar -= sin(dirCar) * speed * deltaTime;
            cameraP->MoveForward(speed * deltaTime);
            cameraO->MoveForward(-cos(dirCar) * speed * deltaTime);
            cameraO->TranslateRight(sin(dirCar) * speed * deltaTime);
        }
        else {
            xcar += cos(dirCar) * 0.5 * deltaTime;
            zcar -= sin(dirCar) * 0.5 * deltaTime;
            cameraP->MoveForward(0.5 * deltaTime);
            cameraO->MoveForward(-cos(dirCar) * 0.5 * deltaTime);
            cameraO->TranslateRight(sin(dirCar) * 0.5 * deltaTime);
        }
    }
    if (window->KeyHold(GLFW_KEY_S)) {
        float X = xcar - cos(dirCar) * speed * deltaTime;
        float Z = zcar + sin(dirCar) * speed * deltaTime;
        if (checkOnTrack(X, Z))
        {
            xcar -= cos(dirCar) * speed * deltaTime;
            zcar += sin(dirCar) * speed * deltaTime;
            cameraP->MoveForward(-speed * deltaTime);
            cameraO->MoveForward(cos(dirCar) * speed * deltaTime);
            cameraO->TranslateRight(-sin(dirCar) * speed * deltaTime);
        }
        else {
            xcar -= cos(dirCar) * 0.5 * deltaTime;
            zcar += sin(dirCar) * 0.5 * deltaTime;
            cameraP->MoveForward(-0.5 * deltaTime);
            cameraO->MoveForward(cos(dirCar) * 0.5 * deltaTime);
            cameraO->TranslateRight(-sin(dirCar) * 0.5 * deltaTime);
        }
    }
    if (window->KeyHold(GLFW_KEY_D)) {
        dirCar -= 2 * deltaTime;
        cameraP->RotateThirdPerson_OY(-2 * deltaTime);
    }
    if (window->KeyHold(GLFW_KEY_A)) {
        dirCar += 2 * deltaTime;
        cameraP->RotateThirdPerson_OY(+2 * deltaTime);
    }
    if (window->KeyHold(GLFW_KEY_SPACE)) {
        GO = true;
    }
}


void tema2::OnKeyPress(int key, int mods)
{
    // Add key press event
}


void tema2::OnKeyRelease(int key, int mods)
{
    // Add key release event
}


void tema2::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    // Add mouse move event

    if (window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT))
    {
        float sensivityOX = 0.001f;
        float sensivityOY = 0.001f;

        if (window->GetSpecialKeyState() == 0) {
            cameraP->RotateFirstPerson_OX(-sensivityOX * deltaY);
            cameraP->RotateFirstPerson_OY(-sensivityOY * deltaX);
        }
        if (window->GetSpecialKeyState() & GLFW_MOD_CONTROL) {
            cameraP->RotateThirdPerson_OX(-sensivityOX * deltaY);
            cameraP->RotateThirdPerson_OY(-sensivityOY * deltaX);
        }
    }
}


void tema2::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button press event
}


void tema2::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
}


void tema2::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void tema2::OnWindowResize(int width, int height)
{
}
