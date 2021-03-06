/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "KAPGain.h"
#include "KAPDelay.h"
#include "KAPLfo.h"
#include "KAPPresetManager.h"

//==============================================================================
/**
*/
class KadenzeAudioPluginAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    KadenzeAudioPluginAudioProcessor();
    ~KadenzeAudioPluginAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    float getInputGainMeterLevel(int inChannel);
    
    float getOutputGainMeterLevel(int inChannel);
    
    juce::AudioProcessorValueTreeState parameters;
    
    KAPPresetManager* getPresetManager()
    {
        return mPresetManager;
    }

private:
    
    /**internal*/
    void initializeDSP();
    
    /**internal*/
    void initializeParameters();
    
    juce::ScopedPointer<KAPGain> mInputGain[2];  // depreciated, better to use unique_ptr
    juce::ScopedPointer<KAPGain> mOutputGain[2];  // depreciated, better to use unique_ptr

    juce::ScopedPointer<KAPDelay> mDelay[2];
    juce::ScopedPointer<KAPLfo> mLfo[2];
    
    juce::ScopedPointer<KAPPresetManager> mPresetManager;
    
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (KadenzeAudioPluginAudioProcessor)
};
