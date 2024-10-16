#include "PluginEditor.h"

//==============================================================================
MyPluginAudioProcessorEditor::MyPluginAudioProcessorEditor (MyPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Set the size of the plugin window (width, height)
    setSize (400, 300);
}

MyPluginAudioProcessorEditor::~MyPluginAudioProcessorEditor()
{
}

//==============================================================================
void MyPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // Fill the background with a solid color
    g.fillAll (juce::Colours::darkgrey);

    // Draw some text in the middle of the plugin UI
    g.setColour (juce::Colours::white);
    g.setFont (15.0f);  
    g.drawFittedText ("My Plugin", getLocalBounds(), juce::Justification::centred, 1);
}

void MyPluginAudioProcessorEditor::resized()
{
    // Resize any GUI components (none in this case)
}
