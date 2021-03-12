/*
  ==============================================================================

    KAPCenterPanel.h
    Created: 11 Mar 2021 3:32:17pm
    Author:  dev

  ==============================================================================
*/

#pragma once

#include "KAPPanelBase.h"
#include "KAPCenterPanelMenuBar.h"
#include "KAPFxPanel.h"

class KAPCenterPanel
: public KAPPanelBase
{
public:
    KAPCenterPanel(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPCenterPanel();
    
private:
    ScopedPointer<KAPCenterPanelMenuBar> mMenuBar;
    ScopedPointer<KAPFxPanel> mFxPanel;
};
