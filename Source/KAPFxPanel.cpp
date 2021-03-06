/*
  ==============================================================================

 KAPFxPanel.cpp
    Created: 11 Mar 2021 3:33:20pm
    Author:  dev

  ==============================================================================
*/

#include "KAPFxPanel.h"
#include "KAPParameters.h"
#include "KAPHelperFunctions.h"

KAPFxPanel::KAPFxPanel(KadenzeAudioPluginAudioProcessor* inProcessor)
:KAPPanelBase(inProcessor)
{
    setSize(FX_PANEL_WIDTH,
            FX_PANEL_HEIGHT);
    
    const int currentStyle = (int)mProcessor->getParameter(kParameter_DelayType);
    setFxPanelStyle((KAPFxPanelStyle)currentStyle);
    DBG("KAPFxPanel : constructor");

}
KAPFxPanel::~KAPFxPanel()
{
    
}

void KAPFxPanel::paint (Graphics& g)
{
    KAPPanelBase::paint(g);
    String label;

    switch (mStyle) {
        case kKAPFxPanelStyle_Delay:
            label = "DELAY";
            break;
            
        case kKAPFxPanelStyle_Chorus:
            label = "CHORUS";
            break;
            
        default:
        case kKAPFxPanelStyle_TotalNumStyles:
            jassertfalse;
    }
    
    g.setColour(KAPColour_5);
    g.setFont(font_3);
    
    g.drawText(label, 0, 0, getWidth(), 80, Justification::centred);
    
    // paint labels
    for (int i = 0; i < mSliders.size(); i++) {
        paintComponentLabel(g, mSliders[i]);
    }
}

void KAPFxPanel::setFxPanelStyle(KAPFxPanelStyle inStyle)
{
    mStyle = inStyle;
    mSliders.clear();
    const int slider_size = 56;
    int x = 130;
    int y =(getHeight()*0.5) - (slider_size*0.5);

    switch (mStyle) {
        case kKAPFxPanelStyle_Delay:{
            
            DBG("KAPFxPanel : kKAPFxPanelStyle_Delay");

            KAPParameterSlider* time =
            new KAPParameterSlider( mProcessor->parameters, KAPParameterID[kParameter_DelayTime]);
            time->setBounds(x, y, slider_size, slider_size);
            addAndMakeVisible(time);
            mSliders.add(time);
            x = x + (slider_size * 2);
            
            KAPParameterSlider* feedback =
            new KAPParameterSlider( mProcessor->parameters, KAPParameterID[kParameter_DelayFeedback]);
            feedback->setBounds(x, y, slider_size, slider_size);
            addAndMakeVisible(feedback);
            mSliders.add(feedback);
            x = x + (slider_size * 2);
            
            KAPParameterSlider* wetdry =
            new KAPParameterSlider( mProcessor->parameters, KAPParameterID[kParameter_DelayWetDry]);
            wetdry->setBounds(x, y, slider_size, slider_size);
            addAndMakeVisible(wetdry);
            mSliders.add(wetdry);
            
        }break;
            
        case kKAPFxPanelStyle_Chorus:{
            DBG("KAPFxPanel : kKAPFxPanelStyle_Chorus");

            KAPParameterSlider* rate =
            new KAPParameterSlider( mProcessor->parameters, KAPParameterID[kParameter_ModulationRate]);
            rate->setBounds(x, y, slider_size, slider_size);
            addAndMakeVisible(rate);
            mSliders.add(rate);
            x = x + (slider_size * 2);
            
            KAPParameterSlider* deph =
            new KAPParameterSlider( mProcessor->parameters, KAPParameterID[kParameter_ModulationDeph]);
            deph->setBounds(x, y, slider_size, slider_size);
            addAndMakeVisible(deph);
            mSliders.add(deph);
            x = x + (slider_size * 2);
            
            KAPParameterSlider* wetdry =
            new KAPParameterSlider( mProcessor->parameters, KAPParameterID[kParameter_DelayWetDry]);
            wetdry->setBounds(x, y, slider_size, slider_size);
            addAndMakeVisible(wetdry);
            mSliders.add(wetdry);
            
        }break;
            
        case kKAPFxPanelStyle_TotalNumStyles:
            //this shoudn't happend!
            
            jassertfalse;
            break;
    }
    repaint();
}

void KAPFxPanel::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    KAPFxPanelStyle style = (KAPFxPanelStyle)comboBoxThatHasChanged->getSelectedItemIndex();
    setFxPanelStyle(style);
    DBG("KAPFxPanel : comboBoxChanged "<<comboBoxThatHasChanged->getSelectedItemIndex());
//    std::cout <<comboBoxThatHasChanged->getSelectedItemIndex()<< std::endl;
//    DBG(comboBoxThatHasChanged->getSelectedItemIndex());
}
