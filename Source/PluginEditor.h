/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class Gain1AudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    Gain1AudioProcessorEditor (Gain1AudioProcessor&);
    ~Gain1AudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Gain1AudioProcessor& audioProcessor;

	juce::Slider gainSlider;

	std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> gainSliderAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Gain1AudioProcessorEditor)
};
