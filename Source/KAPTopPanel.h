/*
  ==============================================================================

    KAPTopPanel.h
    Created: 11 Mar 2021 3:34:38pm
    Author:  dev

  ==============================================================================
*/

#pragma once

#include "KAPPanelBase.h"

class KAPTopPanel
: public KAPPanelBase
{
public:
    KAPTopPanel(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPTopPanel();
    
    void paint (Graphics& g) override;

    
private:
};
