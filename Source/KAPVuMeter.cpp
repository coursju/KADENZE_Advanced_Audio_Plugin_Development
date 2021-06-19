/*
  ==============================================================================

    KAPVuMeter.cpp
    Created: 19 Jun 2021 11:32:38am
    Author:  dev

  ==============================================================================
*/

#include "KAPVuMeter.h"
#include "KAPInterfaceDefines.h"

KAPVuMeter::KAPVuMeter(KadenzeAudioPluginAudioProcessor* inProcessor)
: mParameterID(-1),
  mCh0Level(0),
  mCh1Level(0),
  mProcessor(inProcessor)
{
    
}

KAPVuMeter::~KAPVuMeter(){
    
}

void KAPVuMeter::paint(Graphics& g)
{
    const int meter_width = getWidth() / 3;
    
    g.setColour(KAPColour_6);
    // left
    g.fillRect(0, 0, meter_width, getHeight());
    // right
    g.fillRect(meter_width * 2, 0, meter_width, getHeight());
    
    int ch0fill = getHeight() - (getHeight() * mCh0Level);
    int ch1fill = getHeight() - (getHeight() * mCh1Level);
    
    if (ch0fill < 0) {
        ch0fill = 0;
    }
    
    if (ch1fill < 0) {
        ch1fill = 0;
    }
    
    g.setColour(KAPColour_7);
    g.fillRect(0, ch0fill, meter_width, getHeight());
    g.fillRect(meter_width*2, ch1fill, meter_width, getHeight());
}

void KAPVuMeter::timerCallback()
{
    
}

void KAPVuMeter::setParameterID(int inParameterID)
{
    mParameterID = inParameterID;
    
    startTimerHz(15);
}
