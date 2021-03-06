/*
  ==============================================================================

    KAPPresetManager.cpp
    Created: 10 Jun 2021 6:27:04pm
    Author:  dev

  ==============================================================================
*/

#include "KAPPresetManager.h"

#if JUCE_WINDOWS
    static const String directorySeparator = "\\";
#elif JUCE_MAC
    static const String directorySeparator = "/";
//#elif JUCE_LINUX
#endif

KAPPresetManager::KAPPresetManager(AudioProcessor* inProcessor)
: mCurrentPresetIsSaved(false),
  mCurrentPresetName("Untitled"),
  mProcessor(inProcessor)
{
    const String pluginName = (String) mProcessor->getName();
    
    mPresetDirectory =
    (File::getSpecialLocation(File::userDesktopDirectory)).getFullPathName()+directorySeparator+pluginName;
    
    if (!File(mPresetDirectory).exists()) {
        File(mPresetDirectory).createDirectory();
    }
    
    storeLocalPreset();
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

int KAPPresetManager::getNumberOfPresets()
{
    return mLocalPresets.size();
}

String KAPPresetManager::getPresetName(int inPresetIndex)
{
    return mLocalPresets[inPresetIndex].getFileNameWithoutExtension();
}

void KAPPresetManager::createNewPreset()
{
    const int numParameters = mProcessor->getNumParameters();
    
    for (int i =0; i < numParameters; i++) {
        mProcessor->setParameterNotifyingHost(i, mProcessor->getParameterDefaultValue(i));
    }
    
    mCurrentPresetIsSaved = false;
    mCurrentPresetName = "Untitled";
}

void KAPPresetManager::savePreset()
{
    MemoryBlock destinationData;
    mProcessor->getStateInformation(destinationData);
    
    mCurrentlyLoadedPreset.deleteFile();
    
    mCurrentlyLoadedPreset.appendData(destinationData.getData(),
                                      destinationData.getSize());
    
    mCurrentPresetIsSaved = true;
}

void KAPPresetManager::saveAsPreset(String inPresetName)
{
    File presetFile = File(mPresetDirectory + directorySeparator + inPresetName + PRESET_FILE_EXTENTION);
    
    if (!presetFile.exists()) {
        presetFile.create();
    } else {
        presetFile.deleteFile();
    }
    
    MemoryBlock destinationData;
    mProcessor->getStateInformation(destinationData);
    
    presetFile.appendData(destinationData.getData(),
                          destinationData.getSize());
    
    mCurrentPresetIsSaved = true;
    mCurrentPresetName = inPresetName;
    
    storeLocalPreset();
}

void KAPPresetManager::loadPreset(int inPresetIndex)
{
    DBG("into loadPreset");
    mCurrentlyLoadedPreset = mLocalPresets[inPresetIndex];
    
    MemoryBlock presetBinary;
    
    if (mCurrentlyLoadedPreset.loadFileAsData(presetBinary)) {
        mCurrentPresetIsSaved = true;
        mCurrentPresetName = getPresetName(inPresetIndex);
        mProcessor->setStateInformation(presetBinary.getData(),
                                        (int)presetBinary.getSize());
        DBG("into loadPreset if"+presetBinary.toString());

    }
}

bool KAPPresetManager::getIsCurrentPresetSaved()
{
    return mCurrentPresetIsSaved;
}

String KAPPresetManager::getCurrentPresetName()
{
    return mCurrentPresetName;
}

void KAPPresetManager::storeLocalPreset()
{
    mLocalPresets.clear();
    
    for (DirectoryIterator di (File(mPresetDirectory),
                               false,
                               "*"+(String)PRESET_FILE_EXTENTION,
                               File::TypesOfFileToFind::findFiles); di.next();) {
        File preset = di.getFile();
        mLocalPresets.add(preset);
        DBG("storeLocalPreset"+preset.getFileName());
    }
}
