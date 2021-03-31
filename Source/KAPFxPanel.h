/*
  ==============================================================================

    KAPFxPanel.h
    Created: 11 Mar 2021 3:33:20pm
    Author:  dev

  ==============================================================================
*/

#pragma once
#include "KAPPanelBase.h"
#include "KAPParameterSlider.h"

enum KAPFxPanelStyle
{
    kKAPFxPanelStyle_Delay,
    kKAPFxPanelStyle_Chorus,
    kKAPFxPanelStyle_TotalNumStyles
};

class KAPFxPanel : public KAPPanelBase
{
public:
    KAPFxPanel(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPFxPanel();
    
    void paint (Graphics& g) override;
    
    void setFxPanelStyle(KAPFxPanelStyle inStyle);
    
private:
    
    KAPFxPanelStyle mStyle;
    OwnedArray<KAPParameterSlider> mSliders;
};
