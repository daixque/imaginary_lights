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
    // Draw your points here

    // Draw the VBO as points
    //vbo.draw(GL_POINTS, 0, vertices.size());



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
    
    cam.begin();
    //for (float v : fftSmoothed) {
    for (int i = 0; i < fftSmoothed.size(); i++) {
        float v = fftSmoothed[i];
        float deg = ofMap(v, 0.0f, 1.0f, 0.f, 360.f);
        ofPushMatrix();
        float c = ofMap(deg, 0.0f, 360.0f, 0, 255);
        c = 255.0f;
        ofSetColor(c, c, c, 30.0f);
        glm::vec3 p = glm::vec3(0.0f, 0.0f, (float)-i);
        ofTranslate(p);
        ofRotate(deg, 0.0f, 0.0f, 1.0f);
        //ofRectangle(100.0f, 100.0f, 200.0f, 200.0f);
        ofNoFill();
        ofDrawRectangle(0, 0, 200, 200);
        ofPopMatrix();
    }
    
    cam.end();
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
            break;
        case 'e':
            player.stop();
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
