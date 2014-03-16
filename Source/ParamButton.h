/*
  ==============================================================================

    ParamButton.h
    Created: 16 Mar 2014 5:22:10pm
    Author:  Peter Vasil

  ==============================================================================
*/

#ifndef PARAMBUTTON_H_INCLUDED
#define PARAMBUTTON_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class ParamButton    : public ImageButton
{
public:
    ParamButton(AudioProcessor& p,
                const AutoCompressorAudioProcessor::Parameters index_,
                bool isRed = false)
        : owner(p)
        , index(index_)
    {
        setButtonText (String::empty);

        const void* imageData = isRed ? BinaryData::bt_on_png : BinaryData::bt_on2_png;
        const int dataSize = isRed ? BinaryData::bt_on_pngSize : BinaryData::bt_on2_pngSize;
        setImages (false, true, true,
                   ImageCache::getFromMemory (BinaryData::bt_off_png, BinaryData::bt_off_pngSize),
                   1.000f, Colour (0x00000000), Image(), 1.000f, Colour (0x00000000),
                   ImageCache::getFromMemory (imageData, dataSize), 1.000f, Colour (0x00000000));

        setClickingTogglesState(true);
    }

    void clicked()
    {
        const bool toggleState = getToggleState();
        if (owner.getParameter(index) >= 0.5f != toggleState)
        {
            owner.setParameterNotifyingHost(index, toggleState);
        }
    }

private:
    AudioProcessor& owner;
    const int index;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ParamButton)
};


#endif  // PARAMBUTTON_H_INCLUDED
