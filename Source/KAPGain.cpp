/*
  ==============================================================================

    KAPGain.cpp
    Created: 3 Mar 2021 11:32:35am
    Author:  dev

  ==============================================================================
*/

#include "KAPGain.h"
#include "KAPAudioHelpers.h"

using namespace juce; // pas dans video

KAPGain::KAPGain()
: mOutputSmoothed(0)
{
    
}

KAPGain::~KAPGain(){
    
}

void KAPGain::process(float* inAudio,
             float inGain,
             float* outAudio,
                      int inNumSamplesToRender){
    
    float gainMapped = jmap(inGain, 0.0f,1.0f, -24.0f, 24.0f);
    gainMapped = Decibels::decibelsToGain(gainMapped, -24.0f);
    
    for (int i = 0; i < inNumSamplesToRender; i++) {
        outAudio[i] = inAudio[i] * gainMapped;
    }
    
    float absValue = fabs(outAudio[0]);
    mOutputSmoothed = kMeterSmoothingCoeff * (mOutputSmoothed - absValue) + absValue;
}

float KAPGain::getMeterLevel()
{
    return mOutputSmoothed;
}
