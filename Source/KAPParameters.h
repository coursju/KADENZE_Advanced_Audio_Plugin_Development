/*
  ==============================================================================

    KAPParameters.h
    Created: 22 Mar 2021 6:23:08pm
    Author:  dev

  ==============================================================================
*/

#pragma once

enum KAPParameter
{
    kParameter_InputGain = 0,
    kParameter_DelayTime,
    kParameter_DelayFeedback,
    kParameter_DelayWetDry,
    kParameter_DelayType,//chorus or delay?
    kParameter_OutputGain,
    kParameter_ModulationRate,
    kParameter_ModulationDeph,
    kParameter_TotalNumParameters,
};

static String KAPParameterID [kParameter_TotalNumParameters] =
{
    "InputGain",
    "Time",
    "Feedback",
    "WetDry",
    "Type",
    "OutputGain",
    "ModulationRate",
    "ModulationDepth",
};
