/*
  ==============================================================================

    KAPPanelBase.cpp
    Created: 11 Mar 2021 3:31:20pm
    Author:  dev

  ==============================================================================
*/

#include "KAPPanelBase.h"

KAPPanelBase::KAPPanelBase(KadenzeAudioPluginAudioProcessor* inProcessor)
: mProcessor(inProcessor)
{
    
}
KAPPanelBase::~KAPPanelBase()
{
    
}

void KAPPanelBase::paint (Graphics& g)
{
    g.setColour(Colours::lightcoral);
    g.fillAll();
    
    g.setColour(Colours::black);
    g.drawRoundedRectangle(0, 0, getWidth(), getHeight(), 20.0, 0.5);
}
