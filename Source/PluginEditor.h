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
class ParamSlider;
class AboutComponent;
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
                                            public ButtonListener,
                                            public ComboBoxListener
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
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);

    // Binary resources:
    static const char* bt_off_png;
    static const int bt_off_pngSize;
    static const char* bt_on_png;
    static const int bt_on_pngSize;
    static const char* bt_off2_png;
    static const int bt_off2_pngSize;
    static const char* bt_on2_png;
    static const int bt_on2_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    typedef AutoCompressorAudioProcessor ACProc;
    typedef AutoCompressorAudioProcessorEditor ACEditor;

    AutoCompressorAudioProcessor* getProcessor() const
    {
        return static_cast<AutoCompressorAudioProcessor*>(getAudioProcessor());
    }

    double convertTextToValue(int index, const String& text);
    String convertValueToText(int index, double value);

    ScopedPointer<AboutComponent> aboutComp;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<ParamSlider> ratioSlider;
    ScopedPointer<ParamSlider> kneeWidthSlider;
    ScopedPointer<Label> label;
    ScopedPointer<Label> label2;
    ScopedPointer<ParamSlider> attackSlider;
    ScopedPointer<ParamSlider> releaseSlider;
    ScopedPointer<Label> label3;
    ScopedPointer<Label> label4;
    ScopedPointer<ParamSlider> gainSlider;
    ScopedPointer<ParamSlider> thresholdSlider;
    ScopedPointer<Label> label5;
    ScopedPointer<Label> label6;
    ScopedPointer<Label> meterLabel;
    ScopedPointer<ImageButton> imageButton;
    ScopedPointer<ImageButton> autoKneeButton;
    ScopedPointer<ImageButton> autoGainButton;
    ScopedPointer<ImageButton> autoAttackButton;
    ScopedPointer<ImageButton> autoReleaseButton;
    ScopedPointer<ImageButton> aboutButton;
    ScopedPointer<ComboBox> presetBox;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AutoCompressorAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_C298BF24D05D6FA5__
