//
//  RandomCubes.cpp
//  Talentastic2024
//
//  Created by daixque on 2024/02/07.
//

#include "RandomCubes.hpp"

RandomCubes::RandomCubes() : DrawableObject() {
    image.load("Wind-God-Fujin-and-Thunder-God-Raijin-by-Tawaraya-Sotatsu.png");
    int gridSize = 10;
    float spacing = 200;
    float baseSize = 10;
    float height = 2000;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            ofBoxPrimitive box;
            box.set(baseSize, height, baseSize);
            box.setPosition(i * spacing - (gridSize * spacing / 2), 0, -j * spacing);
            boxes.push_back(box);
        }
    }
    shader.load("shaders/cube_shader.vert", "shaders/cube_shader.frag");
}

void RandomCubes::draw() {
    ofBackground(GlobalSettings::getInstance().nude);
    image.draw(-image.getWidth() / 2.0, -image.getHeight() / 2.0, -1000);
    image.draw(-image.getWidth() / 2.0, -image.getHeight() / 2.0, 100);
    
    shader.begin();
    for (auto& box : boxes) {
        box.draw();
        box.drawWireframe();
    }
    shader.end();
}
