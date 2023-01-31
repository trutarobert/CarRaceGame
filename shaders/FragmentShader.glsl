#version 330

in vec3 s_position;
in vec3 s_color;
in vec2 s_coord;
in vec3 s_normal;

// Output
layout(location = 0) out vec4 out_color;


void main()
{
    out_color = vec4(s_color, 1);
}
