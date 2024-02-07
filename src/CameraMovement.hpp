//
//  CameraMovement.hpp
//  Talentastic2024
//
//  Created by daixque on 2024/02/07.
//

#ifndef CameraMovement_hpp
#define CameraMovement_hpp

#include "ofMain.h"

struct CameraData {
    float time;
    ofVec3f position;
    ofVec3f direction;
};

class CameraMovement {
    std::vector<CameraData> cameraData;
    ofEasyCam cam;

public:
    CameraMovement();
    void loadCSV(const std::string& filename);
    CameraData getCameraDataAtTime(float time);
    void begin(float time);
    void end();
};

#endif /* CameraMovement_hpp */
