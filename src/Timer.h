//
//  Timer.h
//  Talentastic2024
//
//  Created by daixque on 2024/02/07.
//

#ifndef Timer_h
#define Timer_h

class Timer {
public:
    Timer() : start_time(0), started(false) {}

    void start() {
        start_time = ofGetElapsedTimef();
        started = true;
    }

    float getElapsedTime() const {
        if(!started) return 0;
        return ofGetElapsedTimef() - start_time;
    }

    void reset() {
        started = false;
    }

private:
    float start_time;
    bool started;
};

#endif /* Timer_h */
