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
class ParamButton;
class ParamSlider;
class AboutComponent;
class MeterComponent;
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
    void buttonClicked (Button* buttonThatWasClicked);
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    typedef AutoCompressorAudioProcessor ACProc;
    typedef AutoCompressorAudioProcessorEditor ACEditor;

    AutoCompressorAudioProcessor* getProcessor() const
    {
        return static_cast<AutoCompressorAudioProcessor*>(getAudioProcessor());
    }

    void updateWidgets(const NotificationType notification);

    ScopedPointer<AboutComponent> aboutComp;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<ParamSlider> ratioSlider;
    ScopedPointer<Label> ratioLabel;
    ScopedPointer<Label> kneeWidthLabel;
    ScopedPointer<Label> attackLabel;
    ScopedPointer<Label> releaseLabel;
    ScopedPointer<Label> gainLabel;
    ScopedPointer<Label> thresholdLabel;
    ScopedPointer<ImageButton> aboutButton;
    ScopedPointer<ComboBox> presetBox;
    ScopedPointer<ParamSlider> thresholdSlider;
    ScopedPointer<ParamSlider> kneeWidthSlider;
    ScopedPointer<ParamSlider> gainSlider;
    ScopedPointer<ParamSlider> attackSlider;
    ScopedPointer<ParamSlider> releaseSlider;
    ScopedPointer<ParamButton> activeButton;
    ScopedPointer<ParamButton> autoKneeButton;
    ScopedPointer<ParamButton> autoGainButton;
    ScopedPointer<ParamButton> autoAttackButton;
    ScopedPointer<ParamButton> autoReleaseButton;
    ScopedPointer<MeterComponent> meterComp;
    ScopedPointer<Label> autoKneeLabel;
    ScopedPointer<Label> autoGainLabel;
    ScopedPointer<Label> autoAttackLabel;
    ScopedPointer<Label> autoReleaseLabel;
    ScopedPointer<Label> meterLabel;
    ScopedPointer<Label> meterLabel2;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AutoCompressorAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_C298BF24D05D6FA5__
