/*
  ==============================================================================

    KAPGainPanel.cpp
    Created: 11 Mar 2021 3:34:03pm
    Author:  dev

  ==============================================================================
*/

#include "KAPGainPanel.h"
#include "KAPParameters.h"

KAPGainPanel::KAPGainPanel(KadenzeAudioPluginAudioProcessor* inProcessor)
: KAPPanelBase(inProcessor)
{
    setSize(GAIN_PANEL_WIDTH,
            GAIN_PANEL_HEIGHT);
}
KAPGainPanel::~KAPGainPanel()
{
    
}

void KAPGainPanel::setParameterID(int inParameterID)
{
    mSlider = new KAPParameterSlider(mProcessor->parameters, KAPParameterID[inParameterID]);
    const int slider_size = 54;
    mSlider->setBounds((getWidth() * 0.5) - (slider_size *0.5),
                       (getHeight()) * 0.5 - (slider_size * 0.5),
                       slider_size,
                       slider_size);
    
    addAndMakeVisible(mSlider);
}
