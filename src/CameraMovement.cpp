//
//  CameraMovement.cpp
//  Talentastic2024
//
//  Created by daixque on 2024/02/07.
//

#include "CameraMovement.hpp"
#include "ofxCsv.h"

CameraMovement:: CameraMovement() {
}

void CameraMovement::loadCSV(const std::string& filename) {
    ofxCsv csv;
    if (csv.load(filename)) {
        for (int i = 0; i < csv.getNumRows(); i++) {
            CameraData data;
            data.time = ofToFloat(csv[i][0]);
            data.position = ofVec3f(ofToFloat(csv[i][1]), ofToFloat(csv[i][2]), ofToFloat(csv[i][3]));
            data.direction = ofVec3f(ofToFloat(csv[i][4]), ofToFloat(csv[i][5]), ofToFloat(csv[i][6]));
            cameraData.push_back(data);
            ofLog() << "pos: " << data.position;
        }
    } else {
        ofLogError() << "Failed to load CSV file: " << filename;
    }
}

CameraData CameraMovement::getCameraDataAtTime(float time) {
    // Find the first data point that has a time greater than the given time
    auto it = std::upper_bound(cameraData.begin(), cameraData.end(), time, [](float t, const CameraData& data) {
        return t < data.time;
    });

    // If no such data point exists, return the last data point
    if (it == cameraData.end()) {
        return cameraData.back();
    }

    // If the first data point is the one we found, return it
    if (it == cameraData.begin()) {
        return *it;
    }

    // Otherwise, interpolate between the previous data point and the one we found
    CameraData prev = *(it - 1);
    float t = (time - prev.time) / (it->time - prev.time);
    CameraData result;
    result.time = time;
    result.position = prev.position.getInterpolated(it->position, t);
    result.direction = prev.direction.getInterpolated(it->direction, t);
    return result;
//    for (const auto& data : cameraData) {
//        if (data.time == time) {
//            return data;
//        }
//    }
//    return CameraData(); // Return default CameraData if time not found
}

void CameraMovement::begin(float time)
{
    CameraData data = getCameraDataAtTime(time);
    cam.begin();
    cam.setPosition(data.position);
    cam.lookAt(data.direction);
    
    //ofLog() << "time: " << time << ", pos: " << data.position << ", lookat: " << data.direction;
}


void CameraMovement::end()
{
    cam.end();
}
