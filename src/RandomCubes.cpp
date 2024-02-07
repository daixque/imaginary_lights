//
//  RandomCubes.cpp
//  Talentastic2024
//
//  Created by daixque on 2024/02/07.
//

#include "RandomCubes.hpp"

RandomCubes::RandomCubes() : DrawableObject() {
    N = 100; // Set the number of cubes here

    // Generate new cubes and colors
    for(int i = 0; i < N; i++){
        ofBoxPrimitive cube;
        cube.setPosition(ofRandomWidth(), ofRandomHeight(), ofRandom(-500, 500));
        cubes.push_back(cube);

        ofColor c;
        c.set(ofRandom(255), ofRandom(255), ofRandom(255), 0.3 * 255);
        colors.push_back(c);
    }
}

void RandomCubes::draw() {
    for(int i = 0; i < N; i++){
        ofSetColor(colors[i]);
        cubes[i].draw();
    }
}
