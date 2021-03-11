/*
  ==============================================================================

    KAPCenterPanel.cpp
    Created: 11 Mar 2021 3:32:17pm
    Author:  dev

  ==============================================================================
*/

#include "KAPCenterPanel.h"

KAPCenterPanel::KAPCenterPanel(KadenzeAudioPluginAudioProcessor* inProcessor)
: KAPPanelBase(inProcessor)
{
    setSize(CENTER_PANEL_WIDTH,
            CENTER_PANEL_HEIGHT);
    
    mMenuBar = new KAPCenterPanelMenuBar(inProcessor);
    mMenuBar->setTopLeftPosition(0, 0);
    addAndMakeVisible(mMenuBar);
}
KAPCenterPanel::~KAPCenterPanel()
{}
