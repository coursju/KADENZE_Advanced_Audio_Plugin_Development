/*
  ==============================================================================

    KAPDelay.h
    Created: 3 Mar 2021 11:32:55am
    Author:  dev

  ==============================================================================
*/

#pragma once
#include "KAPAudioHelpers.h"

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
                 float* inModulationBuffer,
                 float* outAudio,
                 int inNumSamplesToRender);
    
private:
    
    /** internal */
    double getInterpolatedSample(float inDelayTimeInSamples);
    
    double mSampleRate;
    double mBuffer[maxBufferDelaySize];
    double mFeedbackSample;
    
    int mDelayIndex;
};

