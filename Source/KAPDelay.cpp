/*
  ==============================================================================

    KAPDelay.cpp
    Created: 3 Mar 2021 11:32:55am
    Author:  dev

  ==============================================================================
*/

#include "KAPDelay.h"
#include "JuceHeader.h"
#include "KAPAudioHelpers.h"

using namespace juce;

KAPDelay::KAPDelay(): mSampleRate(-1),
                    mFeedbackSample(0.0),
                    mTimeSmoothed(0),
                    mDelayIndex(0)
{
    reset();
}
KAPDelay::~KAPDelay(){
    
}

void KAPDelay::setSampleRate(double inSampleRate){
    mSampleRate = inSampleRate;
}

void KAPDelay::reset(){
    mTimeSmoothed = 0.0f;
    zeromem(mBuffer,  (sizeof(double)) * maxBufferDelaySize);
}

void KAPDelay::process(float* inAudio,
                       float inTime,
                       float inFeedback,
                       float inWetDry,
                       float inType,
                       float* inModulationBuffer,
                       float* outAudio,
                       int inNumSamplesToRender){
    
    const float wet = inWetDry;
    const float dry = 1.0f - wet;
    const float feedbackMapped = jmap(inFeedback, 0.0f, 1.0f, 0.0f, 0.95f);
//    const float feedbackMapped =
//    ( inType == kKAPDelayType_Delay) ? jmap(inFeedback, 0.0f, 1.0f, 0.0f, 1.2f) : jmap(inFeedback, 0.0f, 1.0f, 0.0f, 0.95f);

    for (int i = 0; i < inNumSamplesToRender; i++) {
        
        if ((int)inType == kKAPDelayType_Delay) {
            mTimeSmoothed = mTimeSmoothed - kParameterSmoothingCoeff_Fine * ( mTimeSmoothed -  inTime);
        }else{
            const float delayTimeModulation = (0.003 + (0.002 * inModulationBuffer[i]));
            mTimeSmoothed = mTimeSmoothed - kParameterSmoothingCoeff_Fine * ( mTimeSmoothed -  delayTimeModulation);
        }
        
        const double delayTimeInSamples = ( mTimeSmoothed * mSampleRate);
        
        const double sample = getInterpolatedSample(delayTimeInSamples);


//        mBuffer[mDelayIndex] = tanh_clip(inAudio[i] + (mFeedbackSample * feedbackMapped));
        mBuffer[mDelayIndex] = inAudio[i] + (mFeedbackSample * feedbackMapped);

        mFeedbackSample = sample;


        outAudio[i] = inAudio[i] * dry + sample * wet;

        mDelayIndex = mDelayIndex + 1;

        if (mDelayIndex >= maxBufferDelaySize) {  // was just >
            mDelayIndex = mDelayIndex - maxBufferDelaySize;
        }
    }
}

double KAPDelay::getInterpolatedSample(float inDelayTimeInSamples){
    
    double readPosition = (double) mDelayIndex - inDelayTimeInSamples;
    
    if (readPosition < 0.0f) {
        readPosition = readPosition + maxBufferDelaySize;
    }
    
    int index_y0 = (int)readPosition -1;
    
    if (index_y0 < 0) {
        index_y0 = index_y0 + maxBufferDelaySize;
    }
    
    int index_y1 = readPosition;
    
    if (index_y1 >= maxBufferDelaySize) { // was just >
        index_y1 = index_y1 - maxBufferDelaySize;
    }
    
    const float sample_y0 = mBuffer[index_y0];
    const float sample_y1 = mBuffer[index_y1];
    const float t = readPosition - (int)readPosition;
    
    double outSample = kap_linear_interp(sample_y0, sample_y1, t);
    
    return  outSample;;
}

