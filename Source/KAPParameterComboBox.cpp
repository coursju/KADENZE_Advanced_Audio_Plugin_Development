/*
  ==============================================================================

    KAPParameterComboBox.cpp
    Created: 25 Mar 2021 7:09:37pm
    Author:  dev

  ==============================================================================
*/

#include "KAPParameterComboBox.h"

KAPParameterComboBox::KAPParameterComboBox(AudioProcessorValueTreeState& stateToControl,                                              const String& parameterID)
: ComboBox(parameterID)
{
    mAttachment =
    new AudioProcessorValueTreeState::ComboBoxAttachment (stateToControl,
                                                         parameterID,
                                                         *this);
}

KAPParameterComboBox::~KAPParameterComboBox()
{
    
}
