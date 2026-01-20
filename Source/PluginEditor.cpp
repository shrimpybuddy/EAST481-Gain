/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Gain1AudioProcessorEditor::Gain1AudioProcessorEditor (Gain1AudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);

	gainSlider.setSliderStyle(juce::Slider::Rotary);
	gainSlider.setRange(0, 200);
	gainSlider.setValue(100);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 90, 0);
	gainSlider.setTextValueSuffix(" %");   
    gainSlider.setPopupDisplayEnabled(false, true, this);
	addAndMakeVisible(&gainSlider);
}

Gain1AudioProcessorEditor::~Gain1AudioProcessorEditor()
{
}

//==============================================================================
void Gain1AudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (juce::FontOptions (15.0f));
    g.drawFittedText ("Gain", getLocalBounds(), juce::Justification::top, 1);
}

void Gain1AudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    gainSlider.setBounds(
        (getWidth() - 150) / 2,
        (getHeight() - 150) / 2,
        150,
        150
    );
}
