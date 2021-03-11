/*
  ==============================================================================

    KAPTopPanel.cpp
    Created: 11 Mar 2021 3:34:38pm
    Author:  dev

  ==============================================================================
*/

#include "KAPTopPanel.h"

KAPTopPanel::KAPTopPanel(KadenzeAudioPluginAudioProcessor* inProcessor)
: KAPPanelBase(inProcessor)
{
    setSize(TOP_PANEL_WIDTH,
            TOP_PANEL_HEIGHT);
}
KAPTopPanel::~KAPTopPanel()
{
    
}

void KAPTopPanel::paint (Graphics& g)
{
    KAPPanelBase::paint(g);
    
    g.drawFittedText("KADENZE AUDIO PLUGIN", 0, 0, getWidth() - 10, getHeight(), Justification::centredRight, 1);
}

