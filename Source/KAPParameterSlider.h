/*
  ==============================================================================

    KAPParameterSlider.h
    Created: 25 Mar 2021 7:08:51pm
    Author:  dev

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
using namespace juce;

class KAPParameterSlider
: public Slider
{
public:
    KAPParameterSlider(AudioProcessorValueTreeState& stateToControl,
                       const String& parameterID);
    
    ~KAPParameterSlider();
    
private:
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> mAttachment;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KAPParameterSlider);
};
