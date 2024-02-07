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
    GlobalSettings();

    // Stop the compiler generating methods of copy the object
    GlobalSettings(GlobalSettings const& copy);            // Not Implemented
    GlobalSettings& operator=(GlobalSettings const& copy); // Not Implemented

public:
    ofColor nude = ofColor(238, 231, 218);
    ofColor khaki = ofColor(175, 200, 173);
    ofColor rose = ofColor(218, 12, 129);
    ofColor& backgroundColor = rose;
    ofColor lineColor = ofColor(255, 255, 255, 128);
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
