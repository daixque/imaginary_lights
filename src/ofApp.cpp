#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    scene = 1;
    player.load("imaginary+lights+short.mp3");
    //cameraMovement.loadCSV("camera.csv");
    
    ofSetFrameRate(60);
    
    /*
    ofSetFrameRate(30);
    ofSetLogLevel(OF_LOG_VERBOSE);
    vidGrabber.setDesiredFrameRate(30);
    vidGrabber.initGrabber(640, 480);
    
    sampleRate = 44100;
    channels = 2;
    fileName = "testMovie";
    fileExt = ".mov";
     */
    
//    vidRecorder.setVideoCodec("mpeg4");
//    vidRecorder.setVideoBitrate("800k");
//    vidRecorder.setAudioCodec("mp3");
//    vidRecorder.setAudioBitrate("192k");
//    vidRecorder.setup("output.mp4", ofGetWidth(), ofGetHeight(), 30); // Set the output file name and size
  
//    ofSetFrameRate(30); // It's important to set a frame rate for smooth video
//    vidRecorder.setFfmpegLocation("/Users/daixque/local/homebrew/bin/ffmpeg"); // Use the correct location of ffmpeg
//    vidRecorder.setup("myVideo.mov", ofGetWidth(), ofGetHeight(), 30); // name of output file, width, height, frameRate
//    vidRecorder.start();
    
//    ofAddListener(vidRecorder.outputFileCompleteEvent, this, &ofApp::recordingComplete);
//    soundStream.setup(this, 0, channels, sampleRate, 256, 4);
//
//    ofSetWindowShape(vidGrabber.getWidth(), vidGrabber.getHeight()    );
//    bRecording = false;
    
    cout << "OpenGL version :" << glGetString(GL_VERSION) << endl;
    cout << "GLSL version :" << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
    
    
    rects.setup(&timer);
    field.setup(&timer);
    cubes.setup(&timer);
    rectAnalyzer.setup(&timer);
    field.setFFT(&fftSmoothed);
    rectAnalyzer.setFFT(&fftSmoothed);
    attractor.setup(&timer);
    
    currentTarget = &field;
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
    if (currentTarget) {
        currentTarget->draw();
    }
//    switch (scene) {
//        case 1:
//            rectAnalyzer.draw();
//            break;
//        case 2:
//            field.draw();
//            break;
//        case 3:
//            rects.draw();
//            break;
//        case 4:
//            cubes.draw();
//            break;
//        default:
//            break;
//    }
    
//    
//    ofPixels pixels;
//    ofImage img;
//    int width = ofGetWidth();
//    int height = ofGetHeight();
//    img.grabScreen(0, 0, width, height);
//    pixels = img.getPixels();
//    vidRecorder.addFrame(pixels);
    
//    ofLog() << "Frame rate: " << ofGetFrameRate();
}

void ofApp::audioIn(float *input, int bufferSize, int nChannels){
    if(bRecording)
        vidRecorder.addAudioSamples(input, bufferSize, nChannels);
}

//--------------------------------------------------------------
void ofApp::exit(){

//    ofRemoveListener(vidRecorder.outputFileCompleteEvent, this, &ofApp::recordingComplete);
    vidRecorder.close();
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
        case 'a':
            timer.reset();
            break;
        case 't':
            ofLog() << "Time: " << timer.getElapsedTime();
            break;
        
        case '1':
            currentTarget = &rectAnalyzer;
            break;
        case '2':
            currentTarget = &field;
            break;
        case '3':
            currentTarget = &rects;
            rects.reset();
            break;
        case '4':
            currentTarget = &cubes;
            break;
        case '5':
            currentTarget = &attractor;
            break;
        case '0':
            currentTarget = &field;
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
