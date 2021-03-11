/*
  ==============================================================================

    KAPMainPanel.h
    Created: 11 Mar 2021 3:31:55pm
    Author:  dev

  ==============================================================================
*/

#pragma once

#include "KAPPanelBase.h"
#include "KAPTopPanel.h"
#include "KAPGainPanel.h"
#include "KAPCenterPanel.h"

class KAPMainPanel
: public KAPPanelBase
{
public:
    KAPMainPanel(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPMainPanel();
    
private:
    ScopedPointer<KAPTopPanel> mTopPanel;
    ScopedPointer<KAPGainPanel> mInputGainPanel;
    ScopedPointer<KAPGainPanel> mOutputGainPanel;
    ScopedPointer<KAPCenterPanel> mCenterPanel;
};
