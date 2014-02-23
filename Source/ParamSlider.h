/*
  ==============================================================================

    ParamSlider.h
    Created: 23 Feb 2014 2:28:22pm
    Author:  peter

  ==============================================================================
*/

#ifndef PARAMSLIDER_H_INCLUDED
#define PARAMSLIDER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include <functional>

class ParamSlider : public Slider
{
public:
    ParamSlider(const String& name);

    virtual double getValueFromText(const String& text);
    virtual String getTextFromValue(double value);

    typedef std::function<double(const String&)> tFnTextToValue;
    typedef std::function<String(double)> tFnValueToText;

    void setTextToValueConverter(const tFnTextToValue& fnTextToValue);
    void setValueToTextConverter(const tFnValueToText& fnValueToText);

private:
    tFnTextToValue textToValueConverter;
    tFnValueToText valueToTextConverter;
};


#endif  // PARAMSLIDER_H_INCLUDED
