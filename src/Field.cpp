//
//  Field.cpp
//  Talentastic2024
//
//  Created by daixque on 2024/02/06.
//

#include "Field.hpp"

Field::Field() {
    image.load("image.jpg");
}

void Field::draw(std::array<float, 128>& fftSmoothed) {
    ofPushMatrix();
    
    /*
    for (int i = 0; i < 1000; i++) {
        glm::vec3 from = glm::vec3(-100.0f, 0.0f, (float)-i);
        glm::vec3 to = glm::vec3(100.0f, 0.0f, (float)-i);
        
        ofLine(from, to);
    }
    
    // Create an ofMesh object
    ofMesh mesh;

    // Set the mode to lines to draw a wireframe
    mesh.setMode(OF_PRIMITIVE_LINES);

    // Define the size of the grid
    int gridSize = 200;

    // Create the grid of vertices
    for(int x = -gridSize; x <= gridSize; x++) {
        for(int z = -gridSize; z <= gridSize; z++) {
            // Add a vertex at (x, 0, z)
            mesh.addVertex(ofVec3f(x, 0, z));
        }
    }

    // Create the lines between the vertices
    for(int x = -gridSize; x < gridSize; x++) {
        for(int z = -gridSize; z < gridSize; z++) {
            int i = (x + gridSize) * (2 * gridSize + 1) + (z + gridSize); // Index of the current vertex

            // Add a line from the current vertex to the next vertex in the x direction
            mesh.addIndex(i);
            mesh.addIndex(i + 1);

            // Add a line from the current vertex to the next vertex in the z direction
            mesh.addIndex(i);
            mesh.addIndex(i + (2 * gridSize + 1));
        }
    }

    // Draw the mesh
    mesh.draw();
     
     */
    
    ofMesh mesh;
    mesh.setMode(OF_PRIMITIVE_LINES);

    for(int x = 0; x < image.getWidth(); x++) {
        for(int z = 0; z < image.getHeight(); z++) {
            // Get the brightness of the pixel
            float brightness = image.getColor(x, z).getBrightness();

            // Map the brightness to a suitable range of y-values
            size_t index = (size_t)ofRandom(0, 128);
            float y = ofMap(brightness, 0, 255, -10, 10) * (fftSmoothed[2] + 0.2);

            // Add a vertex at (x, y, z)
            mesh.addVertex(ofVec3f(x, y, z));
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
    mesh.drawWireframe();
    
    ofPopMatrix();
}
