/*
  ==============================================================================

    KAPHelperFunctions.h
    Created: 31 Mar 2021 5:39:13pm
    Author:  dev

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"

inline void paintComponentLabel(Graphics& g, Component* inComponent )
{
    const int x = inComponent->getX() - (inComponent->getWidth() * 0.25f);
    const int y = inComponent->getY() + inComponent->getHeight();
    const int w = inComponent->getWidth() * 1.5f;
    const int h = 20;
    
    const String label = inComponent->getName();
    
    const float cornerSize = 3.0f;
    
    g.setColour(Colours::darkgrey);
    g.drawFittedText(label, x, y, w, h, Justification::centred, 1);
}
