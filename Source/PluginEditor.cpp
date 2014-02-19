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

    addAndMakeVisible (slider2 = new Slider ("new slider"));
    slider2->setRange (0, 10, 0);
    slider2->setSliderStyle (Slider::Rotary);
    slider2->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    slider2->addListener (this);

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("label text")));
    label->setFont (Font (15.00f, Font::plain));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("label text")));
    label2->setFont (Font (15.00f, Font::plain));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (slider3 = new Slider ("new slider"));
    slider3->setRange (0, 10, 0);
    slider3->setSliderStyle (Slider::Rotary);
    slider3->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    slider3->addListener (this);

    addAndMakeVisible (slider4 = new Slider ("new slider"));
    slider4->setRange (0, 10, 0);
    slider4->setSliderStyle (Slider::Rotary);
    slider4->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    slider4->addListener (this);

    addAndMakeVisible (label3 = new Label ("new label",
                                           TRANS("label text")));
    label3->setFont (Font (15.00f, Font::plain));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label4 = new Label ("new label",
                                           TRANS("label text")));
    label4->setFont (Font (15.00f, Font::plain));
    label4->setJustificationType (Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (slider5 = new Slider ("new slider"));
    slider5->setRange (0, 10, 0);
    slider5->setSliderStyle (Slider::Rotary);
    slider5->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    slider5->addListener (this);

    addAndMakeVisible (slider6 = new Slider ("new slider"));
    slider6->setRange (0, 10, 0);
    slider6->setSliderStyle (Slider::Rotary);
    slider6->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    slider6->addListener (this);

    addAndMakeVisible (label5 = new Label ("new label",
                                           TRANS("label text")));
    label5->setFont (Font (15.00f, Font::plain));
    label5->setJustificationType (Justification::centredLeft);
    label5->setEditable (false, false, false);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label6 = new Label ("new label",
                                           TRANS("label text")));
    label6->setFont (Font (15.00f, Font::plain));
    label6->setJustificationType (Justification::centredLeft);
    label6->setEditable (false, false, false);
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (toggleButton = new ToggleButton ("new toggle button"));
    toggleButton->setButtonText (String::empty);
    toggleButton->addListener (this);

    addAndMakeVisible (toggleButton2 = new ToggleButton ("new toggle button"));
    toggleButton2->setButtonText (String::empty);
    toggleButton2->addListener (this);

    addAndMakeVisible (toggleButton3 = new ToggleButton ("new toggle button"));
    toggleButton3->setButtonText (String::empty);
    toggleButton3->addListener (this);

    addAndMakeVisible (toggleButton4 = new ToggleButton ("new toggle button"));
    toggleButton4->setButtonText (String::empty);
    toggleButton4->addListener (this);

    addAndMakeVisible (toggleButton5 = new ToggleButton ("new toggle button"));
    toggleButton5->setButtonText (String::empty);
    toggleButton5->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (550, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

AutoCompressorAudioProcessorEditor::~AutoCompressorAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    slider = nullptr;
    slider2 = nullptr;
    label = nullptr;
    label2 = nullptr;
    slider3 = nullptr;
    slider4 = nullptr;
    label3 = nullptr;
    label4 = nullptr;
    slider5 = nullptr;
    slider6 = nullptr;
    label5 = nullptr;
    label6 = nullptr;
    toggleButton = nullptr;
    toggleButton2 = nullptr;
    toggleButton3 = nullptr;
    toggleButton4 = nullptr;
    toggleButton5 = nullptr;


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
    g.fillRoundedRectangle (0.0f, 0.0f, 548.0f, 48.0f, 10.000f);

    g.setColour (Colours::black);
    g.setFont (Font (28.00f, Font::plain));
    g.drawText (TRANS("auto_compressor"),
                8, 8, 208, 30,
                Justification::centredLeft, true);

    g.setColour (Colour (0xff5e6c61));
    g.fillRoundedRectangle (0.0f, 48.0f, 548.0f, 352.0f, 10.000f);

    g.setColour (Colours::black);
    g.setFont (Font (24.00f, Font::plain));
    g.drawText (TRANS("ptrv.org"),
                454, 11, 80, 30,
                Justification::centredRight, true);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void AutoCompressorAudioProcessorEditor::resized()
{
    slider->setBounds (80, 156, 76, 80);
    slider2->setBounds (76, 292, 80, 76);
    label->setBounds (80, 124, 80, 24);
    label2->setBounds (76, 260, 80, 24);
    slider3->setBounds (382, 150, 76, 80);
    slider4->setBounds (378, 286, 80, 76);
    label3->setBounds (382, 118, 80, 24);
    label4->setBounds (378, 254, 80, 24);
    slider5->setBounds (232, 96, 76, 80);
    slider6->setBounds (208, 240, 124, 124);
    label5->setBounds (232, 64, 80, 24);
    label6->setBounds (232, 208, 80, 24);
    toggleButton->setBounds (32, 252, 20, 24);
    toggleButton2->setBounds (340, 88, 20, 24);
    toggleButton3->setBounds (484, 168, 20, 24);
    toggleButton4->setBounds (488, 296, 20, 24);
    toggleButton5->setBounds (484, 64, 20, 24);
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
    else if (sliderThatWasMoved == slider2)
    {
        //[UserSliderCode_slider2] -- add your slider handling code here..
        //[/UserSliderCode_slider2]
    }
    else if (sliderThatWasMoved == slider3)
    {
        //[UserSliderCode_slider3] -- add your slider handling code here..
        //[/UserSliderCode_slider3]
    }
    else if (sliderThatWasMoved == slider4)
    {
        //[UserSliderCode_slider4] -- add your slider handling code here..
        //[/UserSliderCode_slider4]
    }
    else if (sliderThatWasMoved == slider5)
    {
        //[UserSliderCode_slider5] -- add your slider handling code here..
        //[/UserSliderCode_slider5]
    }
    else if (sliderThatWasMoved == slider6)
    {
        //[UserSliderCode_slider6] -- add your slider handling code here..
        //[/UserSliderCode_slider6]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void AutoCompressorAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == toggleButton)
    {
        //[UserButtonCode_toggleButton] -- add your button handler code here..
        //[/UserButtonCode_toggleButton]
    }
    else if (buttonThatWasClicked == toggleButton2)
    {
        //[UserButtonCode_toggleButton2] -- add your button handler code here..
        //[/UserButtonCode_toggleButton2]
    }
    else if (buttonThatWasClicked == toggleButton3)
    {
        //[UserButtonCode_toggleButton3] -- add your button handler code here..
        //[/UserButtonCode_toggleButton3]
    }
    else if (buttonThatWasClicked == toggleButton4)
    {
        //[UserButtonCode_toggleButton4] -- add your button handler code here..
        //[/UserButtonCode_toggleButton4]
    }
    else if (buttonThatWasClicked == toggleButton5)
    {
        //[UserButtonCode_toggleButton5] -- add your button handler code here..
        //[/UserButtonCode_toggleButton5]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
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
                 initialWidth="550" initialHeight="400">
  <BACKGROUND backgroundColour="ff393939">
    <ROUNDRECT pos="0 0 548 48" cornerSize="10" fill="solid: ff355c2e" hasStroke="0"/>
    <TEXT pos="8 8 208 30" fill="solid: ff000000" hasStroke="0" text="auto_compressor"
          fontname="Default font" fontsize="28" bold="0" italic="0" justification="33"/>
    <ROUNDRECT pos="0 48 548 352" cornerSize="10" fill="solid: ff5e6c61" hasStroke="0"/>
    <TEXT pos="454 11 80 30" fill="solid: ff000000" hasStroke="0" text="ptrv.org"
          fontname="Default font" fontsize="24" bold="0" italic="0" justification="34"/>
  </BACKGROUND>
  <SLIDER name="new slider" id="ffe07162fd997e54" memberName="slider" virtualName=""
          explicitFocusOrder="0" pos="80 156 76 80" min="0" max="10" int="0"
          style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="f291c6e207934e0e" memberName="slider2"
          virtualName="" explicitFocusOrder="0" pos="76 292 80 76" min="0"
          max="10" int="0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="28411f247b38ffe2" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="80 124 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="label text" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="dc3bfe5fa125e797" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="76 260 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="label text" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="8a15b9bd1874de96" memberName="slider3"
          virtualName="" explicitFocusOrder="0" pos="382 150 76 80" min="0"
          max="10" int="0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="5b7ca9c55f02943" memberName="slider4" virtualName=""
          explicitFocusOrder="0" pos="378 286 80 76" min="0" max="10" int="0"
          style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="2a1d30cbfcf1fbc8" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="382 118 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="label text" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="e0cf7038120d40c1" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="378 254 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="label text" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="581538f5944b4752" memberName="slider5"
          virtualName="" explicitFocusOrder="0" pos="232 96 76 80" min="0"
          max="10" int="0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="d44fe020750dd2e" memberName="slider6" virtualName=""
          explicitFocusOrder="0" pos="208 240 124 124" min="0" max="10"
          int="0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="2c2c65be9dad5998" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="232 64 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="label text" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="18f79e7fdd006853" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="232 208 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="label text" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="new toggle button" id="2b6e627686026dba" memberName="toggleButton"
                virtualName="" explicitFocusOrder="0" pos="32 252 20 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="ebb900b3a9252c8b" memberName="toggleButton2"
                virtualName="" explicitFocusOrder="0" pos="340 88 20 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="3a2d3f97bb2f6da3" memberName="toggleButton3"
                virtualName="" explicitFocusOrder="0" pos="484 168 20 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="af3dc783c6af6d5c" memberName="toggleButton4"
                virtualName="" explicitFocusOrder="0" pos="488 296 20 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="dc991aa816067dbd" memberName="toggleButton5"
                virtualName="" explicitFocusOrder="0" pos="484 64 20 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
