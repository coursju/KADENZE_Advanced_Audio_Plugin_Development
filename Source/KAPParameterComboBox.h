/*
  ==============================================================================

    KAPParameterComboBox.h
    Created: 25 Mar 2021 7:09:37pm
    Author:  dev

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
using namespace juce;

class KAPParameterComboBox
: public ComboBox
{
public:
    KAPParameterComboBox(AudioProcessorValueTreeState& stateToControl,
                       const String& parameterID);
    
    ~KAPParameterComboBox();
    
private:
    ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> mAttachment;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KAPParameterComboBox);
};
