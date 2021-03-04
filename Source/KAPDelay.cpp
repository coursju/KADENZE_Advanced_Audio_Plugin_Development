/*
  ==============================================================================

    KAPDelay.cpp
    Created: 3 Mar 2021 11:32:55am
    Author:  dev

  ==============================================================================
*/

#include "KAPDelay.h"
#include "JuceHeader.h"

using namespace juce;

KAPDelay::KAPDelay(): mSampleRate(-1){
    
}
KAPDelay::~KAPDelay(){
    
}

void KAPDelay::setSampleRate(double inSampleRate){
    mSampleRate = inSampleRate;
}

void KAPDelay::reset(){
    zeromem(mBuffer,  (sizeof(double)) * maxBufferDelaySize);
}

void KAPDelay::process(float* inAudio,
                       float inTime,
                       float inFeedback,
                       float inWetDry,
                       float* outAudio,
                       int inNumSamplesToRender){
    const float wet = inWetDry;
    const float dry = 1.0f - wet;
    const float feedbackMapped = jmap(inFeedback, 0.0f, 1.0f, 0.0f, 0.95f);
    
    for (int i = 0; i < inNumSamplesToRender; i++) {
        const double delayTimeInSamples = (inTime * mSampleRate);
        const double sample = getInterpolatedSample(delayTimeInSamples);
    }
}

double KAPDelay::getInterpolatedSample(float inDelayTimeInSamples){
    double readPosition = (double) mDelayIndex - inDelayTimeInSamples;
    
    if (readPosition < 0.0f) {
        readPosition = readPosition + 2048;
    }
}

