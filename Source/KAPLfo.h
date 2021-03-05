/*
  ==============================================================================

    KAPLfo.h
    Created: 3 Mar 2021 11:32:09am
    Author:  dev

  ==============================================================================
*/

#pragma once
#include "KAPAudioHelpers.h"

class KAPLfo{
public:
    
    KAPLfo();
    ~KAPLfo();
    
    void reset();
    void setSampleRate(double inSampleRate);
    void process(float inRate, float inDepth, int inNumSamples);
    float* getBuffer();
    
private:
    
    double mSampleRate;
    float mPhase;
    float mBuffer[maxBufferDelaySize];
    
};
