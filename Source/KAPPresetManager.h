/*
  ==============================================================================

    KAPPresetManager.h
    Created: 10 Jun 2021 6:27:04pm
    Author:  dev

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

using namespace juce;

class KAPPresetManager
{
public:
    KAPPresetManager(AudioProcessor* inProcessor);
    ~KAPPresetManager();
    
    void getXmlForPreset(XmlElement* inElement);
    
    void loadXmlForPreset(XmlElement* inElement);
    
private:
    
    XmlElement* mCurrentPresetXml;
    
    AudioProcessor* mProcessor;
    
};
