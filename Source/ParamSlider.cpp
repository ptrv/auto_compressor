/*
  ==============================================================================

    ParamSlider.cpp
    Created: 23 Feb 2014 2:28:22pm
    Author:  peter

  ==============================================================================
*/

#include "ParamSlider.h"


ParamSlider::ParamSlider(const String& text) : Slider(text)
{
}

double ParamSlider::getValueFromText(const String &text)
{
    try
    {
        return textToValueConverter(text);
    }
    catch (const std::bad_function_call&)
    {
        return 0.0;
    }
}

String ParamSlider::getTextFromValue(double value)
{
    try
    {
        return valueToTextConverter(value) + " " + getTextValueSuffix();
    }
    catch (const std::bad_function_call&)
    {
        return String::empty;
    }
}

void ParamSlider::setTextToValueConverter(const tFnTextToValue &fnTextToValue)
{
    textToValueConverter = fnTextToValue;
}

void ParamSlider::setValueToTextConverter(const tFnValueToText &fnValueToText)
{
    valueToTextConverter = fnValueToText;
}
