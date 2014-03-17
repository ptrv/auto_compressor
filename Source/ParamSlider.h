/*
  ==============================================================================

    ParamSlider.h
    Created: 23 Feb 2014 2:28:22pm
    Author:  Peter Vasil

  ==============================================================================
*/

#ifndef PARAMSLIDER_H_INCLUDED
#define PARAMSLIDER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

class ParamSlider : public Slider
{
public:
    ParamSlider(AutoCompressorAudioProcessor& p,
                const AutoCompressorAudioProcessor::Parameters index_)
        : owner(p)
        , index(index_)
    {
        setRange(0.0, 1.0, 0.0);
        setSliderStyle(Slider::LinearHorizontal);
        setTextBoxStyle(Slider::TextBoxLeft, false, 80, 20);
        setTextValueSuffix(owner.getParameterLabel(index));
        setScrollWheelEnabled(false);
    }

    void valueChanged()
    {
        const float newValue = (float) getValue();

        if (owner.getParameter(index) != newValue)
        {
            owner.setParameterNotifyingHost(index, newValue);
        }
    }

    double getValueFromText(const String& text)
    {
        return owner.getParameterFromString(index, text);
    }

    String getTextFromValue(double /*value*/)
    {
        return owner.getParameterText(index) + " " + getTextValueSuffix();
    }

private:
    AutoCompressorAudioProcessor& owner;
    const int index;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ParamSlider)
};


#endif  // PARAMSLIDER_H_INCLUDED
