/*
  ==============================================================================

    KAPLfo.cpp
    Created: 3 Mar 2021 11:32:09am
    Author:  dev

  ==============================================================================
*/

#include "KAPLfo.h"
#include "JuceHeader.h"

using namespace juce;

KAPLfo::KAPLfo():mPhase (0.0f)
{
    reset();
}

KAPLfo::~KAPLfo(){
    
}

void KAPLfo::reset(){
    zeromem(mBuffer, sizeof(float) * maxBufferDelaySize);
}

void KAPLfo::setSampleRate(double inSampleRate){
    mSampleRate = inSampleRate;
}

void KAPLfo::process(float inRate, float inDepth, int inNumSamples){
    const float rate = jmap(inRate, 0.0f, 1.0f, 0.01f, 10.0f);
    
    for (int i = 0; i < inNumSamples; i++) {
        mPhase = mPhase + (rate / mSampleRate);
        
        if (mPhase > 1.0f) {
            mPhase = mPhase - 1.0f;
        }
        
        const float lfoPosition = sin(mPhase * k2PI * inDepth);
        mBuffer[i] = lfoPosition;
    }
}

float* KAPLfo::getBuffer(){
    return mBuffer;
}
