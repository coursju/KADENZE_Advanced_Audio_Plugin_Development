/*
  ==============================================================================

    KAPAudioHelpers.h
    Created: 3 Mar 2021 11:31:14am
    Author:  dev

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

#define kParameterSmoothingCoeff_Generic 0.04
#define kParameterSmoothingCoeff_Fine 0.002
#define kMeterSmoothingCoeff 0.2

const static double kPI = 3.14159265359;
const static double k2PI = 6.28318530718;

const static int maxBufferDelaySize = 1920000; //19200; //2048

static inline float dBToNormalizedGain (float inValue)
{
    float inValuedB = juce::Decibels::gainToDecibels(inValue + 0.00001f);
    inValuedB = (inValuedB + 96.0f) / 96.0f;
    
    return inValuedB;
}

inline float kap_linear_interp(float v0, float v1, float t)
{
    return (1-t) * v0 + t * v1;
}

inline float tanh_clip(float x)
{
    return x * ( 27 + x * x ) / ( 27 + 9 * x * x );
}

inline float kap_denormalize (float inValue)
{
    float absValue = fabs(inValue);
    
    // 0.000000000000001
    if (absValue < 1e-15) {
        return 0.0f;
    } else {
        return inValue;
    }
}
