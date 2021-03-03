/*
  ==============================================================================

    KAPGain.cpp
    Created: 3 Mar 2021 11:32:35am
    Author:  dev

  ==============================================================================
*/

#include "KAPGain.h"

KAPGain::KAPGain(){
    
}

KAPGain::~KAPGain(){
    
}

void KAPGain::process(float* inAudio,
             float inGain,
             float* outAudio,
                      int inNumSamplesToRender){
    
    for (int i = 0; i < inNumSamplesToRender; i++) {
        outAudio[i] = inAudio[i] * inGain;
    }
}
