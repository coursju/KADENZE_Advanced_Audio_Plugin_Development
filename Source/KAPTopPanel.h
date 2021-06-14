/*
  ==============================================================================

    KAPTopPanel.h
    Created: 11 Mar 2021 3:34:38pm
    Author:  dev

  ==============================================================================
*/

#pragma once

#include "KAPPanelBase.h"

class KAPTopPanel
    :public KAPPanelBase,
    public Button::Listener,
    public ComboBox::Listener
{
public:
    KAPTopPanel(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPTopPanel();
    
    void paint (Graphics& g) override;

    void buttonClicked (Button*) override;
    
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    
private:
    
    void displaySaveAsPopup();
    
    void updatePresetComboBox();
    
    ScopedPointer<ComboBox> mPresetDisplay;
    
    ScopedPointer<TextButton> mNewPreset, mSavePreset, mSaveAsPreset;
};
