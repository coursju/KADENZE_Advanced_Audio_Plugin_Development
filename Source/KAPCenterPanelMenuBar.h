/*
  ==============================================================================

    KAPCenterPanelMenuBar.h
    Created: 11 Mar 2021 3:32:52pm
    Author:  dev

  ==============================================================================
*/

#pragma once

#include "KAPPanelBase.h"
#include "KAPParameterComboBox.h"

class KAPCenterPanelMenuBar
: public KAPPanelBase
{
public:
    KAPCenterPanelMenuBar(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPCenterPanelMenuBar();
    
    void addFxTypeComboBoxListener( ComboBox::Listener* inListener);
    
    void removeFxTypeComboBoxListener( ComboBox::Listener* inListener);
    
private:
    ScopedPointer<KAPParameterComboBox> mFxTypeComboBox;
};
