/*
  ==============================================================================

    KAPGain.h
    Created: 3 Mar 2021 11:32:35am
    Author:  dev

  ==============================================================================
*/

#pragma once

class KAPGain{
public:
    KAPGain();
    ~KAPGain();
    void process(float* inAudio,
                 float inGain,
                 float* outAudio,
                 int inNumSamplesToRender);
    
    float getMeterLevel();
    
private:
    
    float mOutputSmoothed;
};
