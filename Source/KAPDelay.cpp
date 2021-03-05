/*
  ==============================================================================

    KAPDelay.cpp
    Created: 3 Mar 2021 11:32:55am
    Author:  dev

  ==============================================================================
*/

#include "KAPDelay.h"
#include "JuceHeader.h"
#include "KAPAudioHelpers.h"

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
        
        mBuffer[mDelayIndex] = inAudio[i] + (mFeedbackSample * feedbackMapped);
        
        mFeedbackSample = sample;
        
        outAudio[i] = (inAudio[i] * dry + sample * wet);
        
        mDelayIndex = mDelayIndex + 1;
        
        if (mDelayIndex > maxBufferDelaySize) {
            mDelayIndex = mDelayIndex - maxBufferDelaySize;
        }
    }
}

double KAPDelay::getInterpolatedSample(float inDelayTimeInSamples){
    double readPosition = (double) mDelayIndex - inDelayTimeInSamples;
    
    if (readPosition < 0.0f) {
        readPosition = readPosition + 2048;
    }
    
    int index_y0 = (int)readPosition -1;
    
    if (index_y0 < 0) {
        index_y0 = index_y0 + maxBufferDelaySize;
    }
    
    int index_y1 = readPosition;
    
    if (index_y1 < maxBufferDelaySize) {
        index_y1 = index_y1 - maxBufferDelaySize;
    }
    
    const float sample_y0 = mBuffer[index_y0];
    const float sample_y1 = mBuffer[index_y1];
    const float t = (int)readPosition - readPosition;
    
    double outSample = kap_linear_interp(sample_y0, sample_y1, t);
    
    return  outSample;;
}

