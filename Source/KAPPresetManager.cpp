/*
  ==============================================================================

    KAPPresetManager.cpp
    Created: 10 Jun 2021 6:27:04pm
    Author:  dev

  ==============================================================================
*/

#include "KAPPresetManager.h"

KAPPresetManager::KAPPresetManager(AudioProcessor* inProcessor)
:mProcessor(inProcessor)
{
    
}
KAPPresetManager::~KAPPresetManager()
{
    
}

void KAPPresetManager::getXmlForPreset(XmlElement* inElement)
{
    const int numParameters = mProcessor->getNumParameters();
    
    for (int i = 0; i < numParameters; i++) {
        inElement->setAttribute(mProcessor->getParameterName(i),
                                mProcessor->getParameter(i)); 
    }
}

void KAPPresetManager::loadXmlForPreset(XmlElement* inElement)
{
    mCurrentPresetXml = inElement;
    
    for (int i = 0; i < mCurrentPresetXml->getNumAttributes(); i++) {
        const String name = mCurrentPresetXml->getAttributeName(i);
        const float value = mCurrentPresetXml->getDoubleAttribute(name);
        
        for (int j = 0; j < mProcessor->getNumParameters(); j++) {
            if (mProcessor->getParameterName(j) == name) {
                mProcessor->setParameterNotifyingHost(j, value);
            }
        }
    }
}
