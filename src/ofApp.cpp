#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    player.load("imaginary+lights+short.mp3");
    ofSetFrameRate(60);
    
    cout << "OpenGL version :" << glGetString(GL_VERSION) << endl;
    cout << "GLSL version :" << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
    
    rects.setup(&timer);
    field.setup(&timer);
    field.setFFT(&fftSmoothed);
    cubes.setup(&timer);
    rectAnalyzer.setup(&timer);
    rectAnalyzer.setFFT(&fftSmoothed);
    attractor.setup(&timer);
    
    currentTarget = &field;
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
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (currentTarget) {
        currentTarget->draw();
    }
}

void ofApp::audioIn(float *input, int bufferSize, int nChannels){
}

//--------------------------------------------------------------
void ofApp::exit(){
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
