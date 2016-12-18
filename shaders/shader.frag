#version 330 core

in vec2 UV;

out vec3 color;

uniform sampler2D text_samp;

void main(){
	color = texture(text_samp, UV).rgb;
}
