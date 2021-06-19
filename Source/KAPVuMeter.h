/*
  ==============================================================================

    KAPVuMeter.h
    Created: 19 Jun 2021 11:32:38am
    Author:  dev

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "PluginProcessor.h"

class KAPVuMeter:
    public Component,
    public Timer
{
public:
    KAPVuMeter(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPVuMeter();
    
    void paint (Graphics& g) override;
    
    void timerCallback() override;
    
    void setParameterID(int inParameterID);
    
private:
    
    int mParameterID;
    
    float mCh0Level;
    float mCh1Level;
    
    KadenzeAudioPluginAudioProcessor* mProcessor;
};
