#pragma once

#include "ofMain.h"
#include "ofxVideoRecorder.h"
#include "RectAnalyzer.hpp"
#include "Attractor.hpp"
#include "Field.hpp"

class ofApp : public ofBaseApp{

	protected:
    ofVideoGrabber      vidGrabber;
    ofxVideoRecorder vidRecorder;
    ofSoundStream soundStream;
    bool bRecording;
    int sampleRate;
    int channels;
    string fileName;
    string fileExt;
    
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
    RectAnalyzer rectAnalyzer;
    
    
    Attractor attractor;
    Field field;

	public:
		void setup() override;
		void update() override;
		void draw() override;
        void audioIn(float * input, int bufferSize, int nChannels);
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
		
        void recordingComplete(ofxVideoRecorderOutputFileCompleteEventArgs& args);
};
