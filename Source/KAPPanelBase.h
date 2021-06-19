/*
  ==============================================================================

    KAPPanelBase.h
    Created: 11 Mar 2021 3:31:20pm
    Author:  dev

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "KAPInterfaceDefines.h"

using namespace juce;

class KAPPanelBase: public Component{
    
public:
    KAPPanelBase(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPPanelBase();
    
    void paint (Graphics& g) override;
    
    void mouseEnter (const MouseEvent& event) override;
    
    void mouseExit (const MouseEvent& event) override;
    
    
protected:
    KadenzeAudioPluginAudioProcessor* mProcessor;
    
private:
    
};
