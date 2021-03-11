/*
  ==============================================================================

    KAPGainPanel.cpp
    Created: 11 Mar 2021 3:34:03pm
    Author:  dev

  ==============================================================================
*/

#include "KAPGainPanel.h"

KAPGainPanel::KAPGainPanel(KadenzeAudioPluginAudioProcessor* inProcessor)
: KAPPanelBase(inProcessor)
{
    setSize(GAIN_PANEL_WIDTH,
            GAIN_PANEL_HEIGHT);
}
KAPGainPanel::~KAPGainPanel()
{
    
}
