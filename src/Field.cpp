//
//  Field.cpp
//  Talentastic2024
//
//  Created by daixque on 2024/02/06.
//

#include "Field.hpp"

Field::Field() : DrawableObject() {
    image.load("image.jpg");
    
    mesh.setMode(OF_PRIMITIVE_LINES);

    for(int x = 0; x < image.getWidth(); x++) {
        for(int z = 0; z < image.getHeight(); z++) {
            // Get the brightness of the pixel
            float brightness = image.getColor(x, z).getBrightness();

            // Map the brightness to a suitable range of y-values
            size_t index = (size_t)ofRandom(0, 128);
            float y = ofMap(brightness, 0, 255, -10, 10);

            // Add a vertex at (x, y, z)
            mesh.addVertex(ofVec3f(x, y, z));
            
            // Get the color of the pixel and add the color to the mesh
//            ofColor color = image.getColor(x, z);
//            mesh.addColor(color);
        }
    }

    // Create the lines between the vertices
    for(int x = 0; x < image.getWidth() - 1; x++) {
        for(int z = 0; z < image.getHeight() - 1; z++) {
            int i = x * image.getHeight() + z; // Index of the current vertex

            // Add a line from the current vertex to the next vertex in the x direction
            mesh.addIndex(i);
            mesh.addIndex(i + 1);

            // Add a line from the current vertex to the next vertex in the z direction
            mesh.addIndex(i);
            mesh.addIndex(i + image.getHeight());
        }
    }
}

void Field::setup() {
    shader.load("shaders/shader.vert", "shaders/shader.frag");
}

void Field::draw(std::array<float, 128>& fftSmoothed) {
    ofPushMatrix();
    
    ofTranslate(glm::vec3(-image.getWidth() / 2.0, 0, 0));
    
    float yScale = (fftSmoothed[2] + 0.2);
    ofScale(glm::vec3(1.0f, yScale, 1.0f));
    
    
    shader.begin();
    shader.setUniform1f("time", ofGetElapsedTimef());
    
    ofColor color = GlobalSettings::getInstance().lineColor;
    // Convert the color to a normalized vector
    ofVec4f colorVec(color.r / 255.0f, color.g / 255.0f, color.b / 255.0f, color.a / 255.0f);
    shader.setUniform4f("color", colorVec);

    // Pass the color to the shader
    shader.begin();
    shader.setUniform4f("u_color", colorVec);
    
    mesh.drawWireframe();
    
    shader.end();
    
    /*
    // Create a copy of the original mesh
    ofMesh tempMesh = mesh;

    // Modify the y-coordinate of each vertex
    for(int i = 0; i < tempMesh.getNumVertices(); i++) {
        ofVec3f vertex = tempMesh.getVertex(i);

        // Add a random wave to the y-coordinate
        float wave = ofNoise(ofGetElapsedTimef() + i * 0.1) * 10.0;
        vertex.y += wave;

        tempMesh.setVertex(i, vertex);
    }

    tempMesh.drawWireframe();
     */
    
    ofPopMatrix();
}
