#pragma once

#include "ofMain.h"
#include "RectAnalyzer.hpp"
#include "Attractor.hpp"
#include "Field.hpp"
#include "Timer.h"
#include "RandomCubes.hpp"
#include "GlobalSettings.hpp"
#include "RandomRectangles.hpp"

class ofApp : public ofBaseApp{
    Timer timer;
    
    ofSoundPlayer player;
    static constexpr size_t nBandsToGet = 128;
    std::array<float, nBandsToGet> fftSmoothed{{0}};
    RectAnalyzer rectAnalyzer;
    
    Attractor attractor;
    Field field;
    RandomCubes cubes;
    RandomRectangles rects;
    
    DrawableObject* currentTarget;

	public:
		void setup() override;
		void update() override;
		void draw() override;
        void audioIn(float * input, int bufferSize, int nChannels) override;
		void exit() override;

		void keyPressed(int key) override;
		void keyReleased(int key) override;
		void mouseMoved(int x, int y ) override;
		void mouseDragged(int x, int y, int button) override;
		void mousePressed(int x, int y, int button) override;
		void mouseReleased(int x, int y, int button) override;
		void mouseScrolled(int x, int y, float scrollX, float scrollY) override;
		void mouseEntered(int x, int y) override;
		void mouseExited(int x, int y) override;
		void windowResized(int w, int h) override;
		void dragEvent(ofDragInfo dragInfo) override;
		void gotMessage(ofMessage msg) override;
};
