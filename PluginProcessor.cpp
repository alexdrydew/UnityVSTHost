/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
UnityVstHostAudioProcessor::UnityVstHostAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
    String path = "C:\\Users\\alexsuh\\source\\repos\\sample_vst\\Abstract Chamber-x64.dll";
    OwnedArray<PluginDescription> pluginDescriptions;
    KnownPluginList knownPlugins;
    AudioPluginFormatManager formatManager;
    formatManager.addDefaultFormats();
    for (auto format : formatManager.getFormats()) {
        knownPlugins.scanAndAddFile(path, true, pluginDescriptions, *format);
    }
    jassert(pluginDescriptions.size() > 0);
    plugin = formatManager.createPluginInstance(
        *(pluginDescriptions[0]), sampleRate, samplesPerBlock, String("Plugin creation failed"));
}

UnityVstHostAudioProcessor::~UnityVstHostAudioProcessor()
{
}

//==============================================================================
const String UnityVstHostAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

AudioProcessorEditor* UnityVstHostAudioProcessor::createEditor() {
    return new UnityVstHostAudioProcessorEditor(*this, plugin->createEditorIfNeeded());
}

//==============================================================================
void UnityVstHostAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    this->sampleRate = sampleRate;
    this->samplesPerBlock = samplesPerBlock;
    plugin->prepareToPlay(sampleRate, samplesPerBlock);
}


//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new UnityVstHostAudioProcessor();
}
