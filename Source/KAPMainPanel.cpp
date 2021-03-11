/*
  ==============================================================================

    KAPMainPanel.cpp
    Created: 11 Mar 2021 3:31:55pm
    Author:  dev

  ==============================================================================
*/

#include "KAPMainPanel.h"

KAPMainPanel::KAPMainPanel(KadenzeAudioPluginAudioProcessor* inProcessor)
:KAPPanelBase(inProcessor)
{
    setSize(MAIN_PANEL_WIDTH,
            MAIN_PANEL_HEIGHT);
    
    mTopPanel = new KAPTopPanel(inProcessor);
    mTopPanel->setTopLeftPosition(0, 0);
    addAndMakeVisible(mTopPanel);
}
KAPMainPanel::~KAPMainPanel()
{
    
}
