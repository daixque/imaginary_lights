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
            //ofLog() << "pos: " << data.position;
        }
    } else {
        ofLogError() << "Failed to load CSV file: " << filename;
    }
}

//*
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
}
/*/

glm::vec3 catmullRomInterpolation(const glm::vec3& p0, const glm::vec3& p1, const glm::vec3& p2, const glm::vec3& p3, float t) {
    float t2 = t * t;
    float t3 = t2 * t;
    return 0.5f * ((2.0f * p1) + (-p0 + p2) * t + (2.0f * p0 - 5.0f * p1 + 4.0f * p2 - p3) * t2 + (-p0 + 3.0f * p1 - 3.0f * p2 + p3) * t3);
}

CameraData CameraMovement::getCameraDataAtTime(float time) {
    // Find the first data point that has a time greater than the given time
    auto it = std::upper_bound(cameraData.begin(), cameraData.end(), time, [](float t, const CameraData& data) {
        return t < data.time;
    });

    // If no such data point exists, or not enough points for Catmull-Rom spline, return the last data point
    if (it == cameraData.end() || it + 1 == cameraData.end() || it == cameraData.begin() || it - 1 == cameraData.begin()) {
        return cameraData.back();
    }

    // Otherwise, interpolate between the previous data point and the one we found
    CameraData p0 = *(it - 2);
    CameraData p1 = *(it - 1);
    CameraData p2 = *it;
    CameraData p3 = *(it + 1);
    float t = (time - p1.time) / (p2.time - p1.time);
    CameraData result;
    result.time = time;
    result.position = catmullRomInterpolation(p0.position, p1.position, p2.position, p3.position, t);
    result.direction = catmullRomInterpolation(p0.direction, p1.direction, p2.direction, p3.direction, t);
    return result;
}
 */

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
