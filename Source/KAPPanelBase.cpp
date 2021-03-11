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
    g.setColour(Colours::whitesmoke);
    g.fillAll();
    
    g.setColour(Colours::black);
    g.drawRect(1, 1, getWidth()-1, getHeight()-1, 2);
}
