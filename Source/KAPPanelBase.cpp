/*
  ==============================================================================

    KAPPanelBase.cpp
    Created: 11 Mar 2021 3:31:20pm
    Author:  dev

  ==============================================================================
*/

#include "KAPPanelBase.h"
#include "KAPInterfaceDefines.h"

KAPPanelBase::KAPPanelBase(KadenzeAudioPluginAudioProcessor* inProcessor)
: mProcessor(inProcessor)
{
    
}
KAPPanelBase::~KAPPanelBase()
{
    
}

void KAPPanelBase::paint (Graphics& g)
{
    if (isMouseOver()) {
//        g.setColour(KAPColour_4);
//        g.fillAll();
    }
}

void KAPPanelBase::mouseEnter (const MouseEvent& event)
{
    repaint();
}

void KAPPanelBase::mouseExit (const MouseEvent& event)
{
    repaint();
}
