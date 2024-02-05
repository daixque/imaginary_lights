#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	protected:
		ofVbo vbo; // Vertex Buffer Object
    	vector<ofVec3f> vertices; // Vertices for our particles
        ofEasyCam cam; // Camera for rotating and zooming

    float min, max, res; // Parameters for lambda
    float X0; // Initial point
    int N; // Number of iterations
    float beta; // Parameter for the generating equation
    
    ofSoundPlayer player;
    static constexpr size_t nBandsToGet = 128;
    std::array<float, nBandsToGet> fftSmoothed{{0}};

	public:
		void setup() override;
		void update() override;
		void draw() override;
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