/*
  ==============================================================================

    KAPAudioHelpers.h
    Created: 3 Mar 2021 11:31:14am
    Author:  dev

  ==============================================================================
*/

#pragma once

const static double kPI = 3.14159265359;
const static double k2PI = 6.28318530718;

const static int maxBufferDelaySize = 19200; //2048


inline float kap_linear_interp(float v0, float v1, float t){
    return (1-t) * v0 + t * v1;
}
