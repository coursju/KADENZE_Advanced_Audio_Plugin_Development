/*
  ==============================================================================

    KAPCenterPanelMenuBar.cpp
    Created: 11 Mar 2021 3:32:52pm
    Author:  dev

  ==============================================================================
*/

#include "KAPCenterPanelMenuBar.h"

KAPCenterPanelMenuBar::KAPCenterPanelMenuBar(KadenzeAudioPluginAudioProcessor* inProcessor)
: KAPPanelBase(inProcessor)
{
        setSize(CENTER_PANEL_MENU_BAR_WIDTH,
                CENTER_PANEL_MENU_BAR_HEIGHT);
}
KAPCenterPanelMenuBar::~KAPCenterPanelMenuBar()
{
    
}
