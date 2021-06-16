/*
  ==============================================================================

    KAPLookAndFeel.h
    Created: 16 Jun 2021 7:22:11pm
    Author:  dev

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "KAPInterfaceDefines.h"

class KAPLookAndFeel:
    public LookAndFeel_V4
{
public:
    KAPLookAndFeel()
    {
        // combox colours
        setColour(ComboBox::backgroundColourId, KAPColour_3);
        setColour(ComboBox::outlineColourId, KAPColour_2);
        setColour(ComboBox::arrowColourId, KAPColour_1);
        setColour(ComboBox::textColourId, KAPColour_1);

        // button text colours
        setColour(TextButton::buttonColourId, KAPColour_1);
        setColour(TextButton::textColourOnId, KAPColour_1);
        setColour(TextButton::textColourOffId, KAPColour_1);

    }
    
    ~KAPLookAndFeel();
    
    Font getTextButtonFont (TextButton&, int buttonHeight) override
    {
        return font_1;
    }
    
    void drawButtonBackground (Graphics& g, Button& button, const Colour& backgroundColour,
                               bool isMouseOverButton, bool isButtonDown) override
    {
        Colour fillColour;
        
        if (isButtonDown) {
            fillColour = KAPColour_5;
        } else if(isMouseOverButton){
            fillColour = KAPColour_3;
        }
        
        const float cornersize = 6.0f;
        const juce::Rectangle<float> bounds = button.getLocalBounds().toFloat().reduced(0.5f, 0.5f);
        
        g.setColour(fillColour);
        g.fillRoundedRectangle(bounds.reduced(1), cornersize);
    }
    
private:
};
