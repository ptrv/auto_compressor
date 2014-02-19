/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_C298BF24D05D6FA5__
#define __JUCE_HEADER_C298BF24D05D6FA5__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class AutoCompressorAudioProcessorEditor  : public AudioProcessorEditor,
                                            public Timer,
                                            public SliderListener,
                                            public ButtonListener
{
public:
    //==============================================================================
    AutoCompressorAudioProcessorEditor (AutoCompressorAudioProcessor* ownerFilter);
    ~AutoCompressorAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void timerCallback();
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void buttonClicked (Button* buttonThatWasClicked);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> slider;
    ScopedPointer<Slider> slider2;
    ScopedPointer<Label> label;
    ScopedPointer<Label> label2;
    ScopedPointer<Slider> slider3;
    ScopedPointer<Slider> slider4;
    ScopedPointer<Label> label3;
    ScopedPointer<Label> label4;
    ScopedPointer<Slider> slider5;
    ScopedPointer<Slider> slider6;
    ScopedPointer<Label> label5;
    ScopedPointer<Label> label6;
    ScopedPointer<ToggleButton> toggleButton;
    ScopedPointer<ToggleButton> toggleButton2;
    ScopedPointer<ToggleButton> toggleButton3;
    ScopedPointer<ToggleButton> toggleButton4;
    ScopedPointer<ToggleButton> toggleButton5;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AutoCompressorAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_C298BF24D05D6FA5__
