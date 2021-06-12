/*
  ==============================================================================

    KAPPresetManager.h
    Created: 10 Jun 2021 6:27:04pm
    Author:  dev

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

#define PRESET_FILE_EXTENTION ".kpf"

using namespace juce;

class KAPPresetManager
{
public:
    
    KAPPresetManager(AudioProcessor* inProcessor);
    ~KAPPresetManager();
    
    void getXmlForPreset(XmlElement* inElement);
    
    void loadXmlForPreset(XmlElement* inElement);
    
    int getNumberOfPresets();
    
    String getPresetName(int inPresetIndex);
    
    void createNewPreset();
    
    void savePreset();
    
    void saveAsPreset(String inPresetName);
    
    void loadPreset(int inPresetIndex);
    
    bool getIsCurrentPresetSaved();
    
    String getCurrentPresetName();
    
    
private:
    
    void storeLocalPreset();
    
    bool mCurrentPresetIsSaved;
    
    File mCurrentlyLoadedPreset;
    
    Array<File> mLocalPresets;
    
    String mCurrentPresetName;
    
    String mPresetDirectory;
    
    XmlElement* mCurrentPresetXml;
    
    AudioProcessor* mProcessor;
    
};
