#version 150
// in_Position was bound to attribute index 0 
in  vec3 in_Position;


void main(void) {
    // Since we are using flat lines, our input only had two points: x and y.
    // Set the Z coordinate to 0 and W coordinate to 1

    gl_Position = vec4(in_Position.x, in_Position.y, in_Position.z, 1.0);
	
    
}