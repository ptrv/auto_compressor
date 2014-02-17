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

//[Headers] You can add your own extra header files here...
#include "PluginProcessor.h"
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
AutoCompressorAudioProcessorEditor::AutoCompressorAudioProcessorEditor (AutoCompressorAudioProcessor* ownerFilter)
    : AudioProcessorEditor (ownerFilter)
{
    addAndMakeVisible (slider = new Slider ("new slider"));
    slider->setRange (0, 10, 0);
    slider->setSliderStyle (Slider::Rotary);
    slider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    slider->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (400, 300);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

AutoCompressorAudioProcessorEditor::~AutoCompressorAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    slider = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void AutoCompressorAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff393939));

    g.setColour (Colour (0xff355c2e));
    g.fillRoundedRectangle (0.0f, 0.0f, 400.0f, 48.0f, 10.000f);

    g.setColour (Colours::black);
    g.setFont (Font (28.00f, Font::plain));
    g.drawText (TRANS("auto_compressor"),
                8, 8, 208, 30,
                Justification::centredLeft, true);

    g.setColour (Colour (0xff5e6c61));
    g.fillRoundedRectangle (0.0f, 48.0f, 400.0f, 252.0f, 10.000f);

    g.setColour (Colours::black);
    g.setFont (Font (24.00f, Font::plain));
    g.drawText (TRANS("ptrv.org"),
                312, 8, 80, 30,
                Justification::centredRight, true);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void AutoCompressorAudioProcessorEditor::resized()
{
    slider->setBounds (8, 84, 80, 76);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void AutoCompressorAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == slider)
    {
        //[UserSliderCode_slider] -- add your slider handling code here..
        //[/UserSliderCode_slider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void AutoCompressorAudioProcessorEditor::timerCallback()
{
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="AutoCompressorAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="AutoCompressorAudioProcessor* ownerFilter"
                 variableInitialisers="AudioProcessorEditor (ownerFilter)" snapPixels="4"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="1"
                 initialWidth="400" initialHeight="300">
  <BACKGROUND backgroundColour="ff393939">
    <ROUNDRECT pos="0 0 400 48" cornerSize="10" fill="solid: ff355c2e" hasStroke="0"/>
    <TEXT pos="8 8 208 30" fill="solid: ff000000" hasStroke="0" text="auto_compressor"
          fontname="Default font" fontsize="28" bold="0" italic="0" justification="33"/>
    <ROUNDRECT pos="0 48 400 252" cornerSize="10" fill="solid: ff5e6c61" hasStroke="0"/>
    <TEXT pos="312 8 80 30" fill="solid: ff000000" hasStroke="0" text="ptrv.org"
          fontname="Default font" fontsize="24" bold="0" italic="0" justification="34"/>
  </BACKGROUND>
  <SLIDER name="new slider" id="ffe07162fd997e54" memberName="slider" virtualName=""
          explicitFocusOrder="0" pos="8 84 80 76" min="0" max="10" int="0"
          style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
