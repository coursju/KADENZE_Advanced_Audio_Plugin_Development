/*
  ==============================================================================

    KAPFxPanel.cpp
    Created: 11 Mar 2021 3:33:20pm
    Author:  dev

  ==============================================================================
*/

#include "KAPFxPanel.h"
#include "KAPParameters.h"

KAPFxPanel::KAPFxPanel(KadenzeAudioPluginAudioProcessor* inProcessor)
:KAPPanelBase(inProcessor)
{
    setSize(FX_PANEL_WIDTH,
            FX_PANEL_HEIGHT);
    setFxPanelStyle(kKAPFxPanelStyle_Chorus);
}
KAPFxPanel::~KAPFxPanel()
{
    
}

void KAPFxPanel::paint (Graphics& g)
{
    KAPPanelBase::paint(g);
    
    switch (mStyle) {
        case kKAPFxPanelStyle_Delay:
            g.drawFittedText("DELAY", 0, 0, getWidth(), getHeight(), Justification::centred, 1);
            break;
            
        case kKAPFxPanelStyle_Chorus:
            g.drawFittedText("CHORUS", 0, 0, getWidth(), getHeight(), Justification::centred, 1);
            break;
            
        case kKAPFxPanelStyle_TotalNumStyles:
            //this shoudn't happend!
            g.drawFittedText("no no no", 0, 0, getWidth(), getHeight(), Justification::centred, 1);
            jassertfalse;
            break;
    }
}

void KAPFxPanel::setFxPanelStyle(KAPFxPanelStyle inStyle)
{
    mStyle = inStyle;
    mSlider.clear();
    const int slider_size = 56;
    int x = 130;
    int y =(getHeight()*0.5) - (slider_size*0.5);

    switch (mStyle) {
        case kKAPFxPanelStyle_Delay:{
             
            KAPParameterSlider* time =
            new KAPParameterSlider( mProcessor->parameters, KAPParameterID[kParameter_DelayTime]);
            time->setBounds(x, y, slider_size, slider_size);
            addAndMakeVisible(time);
            mSlider.add(time);
            x = x + (slider_size * 2);
            
            KAPParameterSlider* feedback =
            new KAPParameterSlider( mProcessor->parameters, KAPParameterID[kParameter_DelayFeedback]);
            feedback->setBounds(x, y, slider_size, slider_size);
            addAndMakeVisible(feedback);
            mSlider.add(time);
            x = x + (slider_size * 2);
            
            KAPParameterSlider* wetdry =
            new KAPParameterSlider( mProcessor->parameters, KAPParameterID[kParameter_DelayWetDry]);
            wetdry->setBounds(x, y, slider_size, slider_size);
            addAndMakeVisible(wetdry);
            mSlider.add(wetdry);
            
        }break;
            
        case kKAPFxPanelStyle_Chorus:{
            
            KAPParameterSlider* rate =
            new KAPParameterSlider( mProcessor->parameters, KAPParameterID[kParameter_ModulationRate]);
            rate->setBounds(x, y, slider_size, slider_size);
            addAndMakeVisible(rate);
            mSlider.add(rate);
            x = x + (slider_size * 2);
            
            KAPParameterSlider* deph =
            new KAPParameterSlider( mProcessor->parameters, KAPParameterID[kParameter_ModulationDeph]);
            deph->setBounds(x, y, slider_size, slider_size);
            addAndMakeVisible(deph);
            mSlider.add(deph);
            x = x + (slider_size * 2);
            
            KAPParameterSlider* wetdry =
            new KAPParameterSlider( mProcessor->parameters, KAPParameterID[kParameter_DelayWetDry]);
            wetdry->setBounds(x, y, slider_size, slider_size);
            addAndMakeVisible(wetdry);
            mSlider.add(wetdry);
            
        }break;
            
        case kKAPFxPanelStyle_TotalNumStyles:
            //this shoudn't happend!
            
            jassertfalse;
            break;
    }
}
