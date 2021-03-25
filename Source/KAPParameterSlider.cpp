/*
  ==============================================================================

    KAPParameterSlider.cpp
    Created: 25 Mar 2021 7:08:51pm
    Author:  dev

  ==============================================================================
*/

#include "KAPParameterSlider.h"

KAPParameterSlider::KAPParameterSlider(AudioProcessorValueTreeState& stateToControl,
                                       const String& parameterID)
: Slider(parameterID)
{
    setSliderStyle(SliderStyle::RotaryHorizontalVerticalDrag);
    setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxBelow, false, 0, 0);
    
    setRange(0.0f, 1.0f, 0.001f);
    
    mAttachment =
    new AudioProcessorValueTreeState::SliderAttachment(stateToControl, parameterID, *this);
}

KAPParameterSlider::~KAPParameterSlider()
{
    
}
