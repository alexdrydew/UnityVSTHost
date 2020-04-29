/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/**
*/
class UnityVstHostAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    UnityVstHostAudioProcessor();
    ~UnityVstHostAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    const String getName() const override;
    AudioProcessorEditor* createEditor();

    bool hasEditor() const override { return false; } // Not there yet

    bool acceptsMidi() const override { return plugin->acceptsMidi(); }
    bool canAddBus(bool inputBus) const override { return plugin->canAddBus(inputBus); }
    bool canRemoveBus(bool inputBus) const override { return plugin->canRemoveBus(inputBus); }
    bool isMetaParameter(int parameterIndex) const override { return plugin->isMetaParameter(parameterIndex); }
    bool isMidiEffect() const override { return plugin->isMidiEffect(); }
    bool isParameterAutomatable(int parameterIndex) const override { return plugin->isParameterAutomatable(parameterIndex); }
    bool isParameterOrientationInverted(int index) const override { return plugin->isParameterOrientationInverted(index); }
    bool producesMidi() const override { return plugin->producesMidi(); }
    bool supportsDoublePrecisionProcessing() const override { return plugin->supportsDoublePrecisionProcessing(); }
    bool supportsMPE() const override { return plugin->supportsMPE(); }
    const String getParameterName(int parameterIndex) override { return plugin->getParameterName(parameterIndex); }
    const String getParameterText(int parameterIndex) override { return plugin->getParameterText(parameterIndex); }
    const String getProgramName(int index) override { return plugin->getProgramName(index); }
    double getTailLengthSeconds() const override { return plugin->getTailLengthSeconds(); }
    float getParameter(int parameterIndex) override { return plugin->getParameter(parameterIndex); }
    float getParameterDefaultValue(int parameterIndex) override { return plugin->getParameterDefaultValue(parameterIndex); }
    int getCurrentProgram() override { return plugin->getCurrentProgram(); }
    int getNumParameters() override { return plugin->getNumParameters(); }
    int getNumPrograms() override { return plugin->getNumPrograms(); }
    int getParameterNumSteps(int parameterIndex) override { return plugin->getParameterNumSteps(parameterIndex); }
    String getParameterID(int index) override { return plugin->getParameterID(index); }
    String getParameterLabel(int index) const override { return plugin->getParameterLabel(index); }
    String getParameterName(int parameterIndex, int maximumStringLength) override { return plugin->getParameterName(parameterIndex, maximumStringLength); }
    String getParameterText(int parameterIndex, int maximumStringLength) override { return plugin->getParameterText(parameterIndex, maximumStringLength); }
    void changeProgramName(int index, const String& newName) override { plugin->changeProgramName(index, newName); }
    void getCurrentProgramStateInformation(juce::MemoryBlock& destData) override { plugin->getCurrentProgramStateInformation(destData); }
    void getStateInformation(juce::MemoryBlock& destData) override { plugin->getStateInformation(destData); }
    void processBlock(AudioBuffer<float>& data, MidiBuffer& buffer) override { plugin->processBlock(data, buffer); }
    void releaseResources() override { plugin->releaseResources(); }
    void reset() override { plugin->reset(); }
    void setCurrentProgram(int index) override { plugin->setCurrentProgram(index); }
    void setCurrentProgramStateInformation(const void* data, int bytes) override { plugin->setCurrentProgramStateInformation(data, bytes); }
    void setParameter(int parameterIndex, float newValue) override { plugin->setParameter(parameterIndex, newValue); }
    void setStateInformation(const void* data, int sizeInBytes) override { plugin->setStateInformation(data, sizeInBytes); }

private:
    double sampleRate = 44100;
    int samplesPerBlock = 256;
    std::unique_ptr<AudioPluginInstance> plugin;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (UnityVstHostAudioProcessor)
};
