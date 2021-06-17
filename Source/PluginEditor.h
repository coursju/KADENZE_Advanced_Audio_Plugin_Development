/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "KAPMainPanel.h"
#include "KAPLookAndFeel.h"

//==============================================================================
/**
*/
class KadenzeAudioPluginAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    KadenzeAudioPluginAudioProcessorEditor (KadenzeAudioPluginAudioProcessor&);
    ~KadenzeAudioPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    KadenzeAudioPluginAudioProcessor& audioProcessor;
    
    ScopedPointer<KAPMainPanel> mMainPanel;
    KAPLookAndFeel* mLookAndFeel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (KadenzeAudioPluginAudioProcessorEditor)
};
