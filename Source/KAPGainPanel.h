/*
  ==============================================================================

    KAPGainPanel.h
    Created: 11 Mar 2021 3:34:03pm
    Author:  dev

  ==============================================================================
*/

#pragma once

#include "KAPPanelBase.h"
#include "KAPParameterSlider.h"

class KAPGainPanel : public KAPPanelBase
{
public:
    KAPGainPanel(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPGainPanel();
    
    void paint(Graphics& g) override;
    
    void setParameterID(int inParameterID);
    
private:
    ScopedPointer<KAPParameterSlider> mSlider;
};
