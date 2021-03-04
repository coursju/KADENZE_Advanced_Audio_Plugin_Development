/*
  ==============================================================================

    KAPDelay.h
    Created: 3 Mar 2021 11:32:55am
    Author:  dev

  ==============================================================================
*/

#pragma once

class KAPDelay{
public:
    KAPDelay();
    ~KAPDelay();
    
    void setSampleRate(double inSampleRate);
    
    void reset();
    
    void process(float* inAudio,
                 float inTime,
                 float inFeedback,
                 float inWetDry,
                 float* outAudio,
                 int inNumSamplesToRender);
    
private:
    double mSampleRate;
    double mBuffer[2048];
    double mFeedbackSample;
    
    int mDelayIndex;
};
