//
//  GlobalSettings.hpp
//  Talentastic2024
//
//  Created by daixque on 2024/02/07.
//

#ifndef GlobalSettings_hpp
#define GlobalSettings_hpp

#include "ofMain.h"

class GlobalSettings {
private:
    // Private Constructor
    GlobalSettings() {}

    // Stop the compiler generating methods of copy the object
    GlobalSettings(GlobalSettings const& copy);            // Not Implemented
    GlobalSettings& operator=(GlobalSettings const& copy); // Not Implemented

public:
    const ofColor dark = ofColor(128, 128, 128);
    const ofColor liteGray = ofColor(245, 245, 245);
    const ofColor nude = ofColor(238, 231, 218);
    const ofColor khaki = ofColor(175, 200, 173);
    const ofColor rose = ofColor(218, 12, 129);
    const ofColor& backgroundColor = nude;
    const ofColor lineColor = ofColor(255, 255, 255, 128);
    const ofColor polygonColor = ofColor(255, 255, 255, 30);
    //ofColor lineColor = ofColor(0, 0, 0, 128);
    
public:
    static GlobalSettings& getInstance() {
        // The only instance of the class is created on the first call
        // and will be the same for all subsequent calls
        static GlobalSettings instance;
        return instance;
    }

    
};

#endif /* GlobalSettings_hpp */
