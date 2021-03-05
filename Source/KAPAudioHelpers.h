/*
  ==============================================================================

    KAPAudioHelpers.h
    Created: 3 Mar 2021 11:31:14am
    Author:  dev

  ==============================================================================
*/

#pragma once

inline float kap_linear_interp(float v0, float v1, float t){
    return (1-t) * v0 + t * v1;
}
