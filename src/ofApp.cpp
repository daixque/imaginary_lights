#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // Create 10,000 particles at random positions
    for(int i = 0; i < 10000; i++){
        vertices.push_back(ofVec3f(ofRandom(-500, 500), ofRandom(-500, 500), ofRandom(-500, 500)));
    }

    // Set the vertices in the VBO
    vbo.setVertexData(&vertices[0], vertices.size(), GL_STATIC_DRAW);


    // Initialize parameters
    min = 0.0f;
    max = 125.f;
    res = 1024.0f;
    X0 = 0.5f;
    N = 3000;
    beta = 5.0f;
    
    player.load("imaginary+lights.mp3");
    cameraMovement.loadCSV("camera.csv");
    
    
    /*
    ofSetFrameRate(30);
    ofSetLogLevel(OF_LOG_VERBOSE);
    vidGrabber.setDesiredFrameRate(30);
    vidGrabber.initGrabber(640, 480);
    
    sampleRate = 44100;
    channels = 2;
    fileName = "testMovie";
    fileExt = ".mov";
    
    vidRecorder.setVideoCodec("mpeg4");
    vidRecorder.setVideoBitrate("800k");
    vidRecorder.setAudioCodec("mp3");
    vidRecorder.setAudioBitrate("192k");
    vidRecorder.setup("output.mp4", ofGetWidth(), ofGetHeight(), 30); // Set the output file name and size
    
    
    ofAddListener(vidRecorder.outputFileCompleteEvent, this, &ofApp::recordingComplete);
    soundStream.setup(this, 0, channels, sampleRate, 256, 4);

    ofSetWindowShape(vidGrabber.getWidth(), vidGrabber.getHeight()    );
    bRecording = false;
     */
    cout << "OpenGL version :" << glGetString(GL_VERSION) << endl;
    cout << "GLSL version :" << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
    
    field.setup();
}


void ofApp::recordingComplete(ofxVideoRecorderOutputFileCompleteEventArgs& args){
    cout << "The recoded video file is now complete." << endl;
}

//--------------------------------------------------------------
void ofApp::update(){
    float * val = ofSoundGetSpectrum(nBandsToGet);        // request 128 values for fft
    for (int i = 0;i < nBandsToGet; i++){
        
        // let the smoothed value sink to zero:
        fftSmoothed[i] *= 0.96f;
        
        // take the max, either the smoothed or the incoming:
        if (fftSmoothed[i] < val[i]) fftSmoothed[i] = val[i];
    }
    
    /*
    vidGrabber.update();
    if(vidGrabber.isFrameNew() && bRecording){
        ofPixels& pixcels = vidGrabber.getPixels();
        bool success = vidRecorder.addFrame(pixcels);
        if (!success) {
            ofLogWarning("This frame was not added!");
        }
    }

    // Check if the video recorder encountered any error while writing video frame or audio smaples.
    if (vidRecorder.hasVideoError()) {
        ofLogWarning("The video recorder failed to write some frames!");
    }

    if (vidRecorder.hasAudioError()) {
        ofLogWarning("The video recorder failed to write some audio samples!");
    }
     */
}

//--------------------------------------------------------------
void ofApp::draw(){
    // Draw your points here

    // Draw the VBO as points
//    ofSetColor(255, 255, 255);
//    vbo.draw(GL_POINTS, 0, vertices.size());



    // Scan lambda
//    for(float lambda = min; lambda <= max; lambda += (max-min) / res){
//        float x = X0; // Set initial point
//
//        // Iteration loop
//        for(int i = 1; i <= N; i++){
//            // Generating equation
//            x = lambda * x * pow(1 + x, -beta);
//
//            // Set color based on iteration
//            float c = ofMap(i, 1, N, 0, 255);
//            ofSetColor(c, c, c);
//
//            // Plot dot at point (lambda, x)
//            ofDrawCircle(ofMap(lambda, min, max, 0, ofGetWidth()), ofMap(x, 0, 1, 0, ofGetHeight()), 1);
//            // ofDrawCircle(ofMap(x, 0, 1, ofGetHeight(), 0), ofMap(lambda, min, max, 0, ofGetWidth()), 1);
//        }
//    }
    
    //cam.begin();
    cameraMovement.begin(timer.getElapsedTime());
    
    rectAnalyzer.draw(fftSmoothed);
    //attractor.draw();
    field.draw(fftSmoothed);
    
    //cam.end();
    cameraMovement.end();

    // Draw the image
//    p.update();
//    p.draw(0, 0);
}

void ofApp::audioIn(float *input, int bufferSize, int nChannels){
    if(bRecording)
        vidRecorder.addAudioSamples(input, bufferSize, nChannels);
}

//--------------------------------------------------------------
void ofApp::exit(){

//    ofRemoveListener(vidRecorder.outputFileCompleteEvent, this, &ofApp::recordingComplete);
//    vidRecorder.close();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch (key) {
        case 's':
            player.play();
            timer.start();
            break;
        case 'e':
            player.stop();
            break;
        case 't':
            ofLog() << "Time: " << timer.getElapsedTime();
            break;

        /*
        case 'r':
            bRecording = !bRecording;
            if(bRecording && !vidRecorder.isInitialized()) {
                vidRecorder.setup(fileName+ofGetTimestampString()+fileExt, vidGrabber.getWidth(), vidGrabber.getHeight(), 30, sampleRate, channels);
    //          vidRecorder.setup(fileName+ofGetTimestampString()+fileExt, vidGrabber.getWidth(), vidGrabber.getHeight(), 30); // no audio
    //            vidRecorder.setup(fileName+ofGetTimestampString()+fileExt, 0,0,0, sampleRate, channels); // no video
    //          vidRecorder.setupCustomOutput(vidGrabber.getWidth(), vidGrabber.getHeight(), 30, sampleRate, channels, "-vcodec mpeg4 -b 1600k -acodec mp2 -ab 128k -f mpegts udp://localhost:1234"); // for custom ffmpeg output string (streaming, etc)

                // Start recording
                vidRecorder.start();
            }
            else if(!bRecording && vidRecorder.isInitialized()) {
                vidRecorder.setPaused(true);
            }
            else if(bRecording && vidRecorder.isInitialized()) {
                vidRecorder.setPaused(false);
            }
            break;
        case 'c':
            bRecording = false;
            vidRecorder.close();
            break;
            */
            
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
