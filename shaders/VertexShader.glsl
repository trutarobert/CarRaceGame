#version 330

// Input
layout(location = 0) in vec3 v_position;
layout(location = 1) in vec3 v_normal;
layout(location = 2) in vec2 v_coord;
layout(location = 3) in vec3 v_color;

// Uniform properties
uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;
uniform vec3 CarPos;
uniform float mapColor;

// Output
out vec3 s_position;
out vec3 s_color;
out vec2 s_coord;
out vec3 s_normal;

void main()
{
    vec4 pos = Projection * View * Model * vec4(v_position, 1.0);
    vec4 cpos = Projection * View * vec4(CarPos, 1.0);
    pos.y = pos.y - length(cpos - pos) * length(cpos - pos) * 0.05;
    gl_Position = pos;
    s_position = v_position;
    s_color = v_color * mapColor;
    s_coord = v_coord;
    s_normal = v_normal;
}
