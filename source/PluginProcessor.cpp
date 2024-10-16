#include "PluginProcessor.h"

//==============================================================================
MyPluginAudioProcessor::MyPluginAudioProcessor()
{
}

MyPluginAudioProcessor::~MyPluginAudioProcessor()
{
}

//==============================================================================
const juce::String MyPluginAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool MyPluginAudioProcessor::acceptsMidi() const
{
    return false;
}

bool MyPluginAudioProcessor::producesMidi() const
{
    return false;
}

bool MyPluginAudioProcessor::isMidiEffect() const
{
    return false;
}

double MyPluginAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int MyPluginAudioProcessor::getNumPrograms()
{
    return 1; // We don't have any programs in this simple plugin
}

int MyPluginAudioProcessor::getCurrentProgram()
{
    return 0;
}

void MyPluginAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String MyPluginAudioProcessor::getProgramName (int index)
{
    return {};
}

void MyPluginAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void MyPluginAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Prepare any resources required before starting audio processing (e.g., allocate buffers)
}

void MyPluginAudioProcessor::releaseResources()
{
    // Free any resources that are no longer needed when the audio processing stops
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool MyPluginAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono())
        return false;

    return true;
}
#endif

void MyPluginAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // Clear unused output channels
    for (int i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // Pass audio through without modification (My process)
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);

        // No processing, just pass the input to the output
        for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
        {
            channelData[sample] = channelData[sample];
        }
    }
}

//==============================================================================
bool MyPluginAudioProcessor::hasEditor() const
{
    return true; // This plugin will have a GUI
}

juce::AudioProcessorEditor* MyPluginAudioProcessor::createEditor()
{
    return new juce::GenericAudioProcessorEditor (*this);
}

//==============================================================================
void MyPluginAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // Store parameters to memory (if you have any)
}

void MyPluginAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // Load parameters from memory (if you have any)
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new MyPluginAudioProcessor();
}
