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
#include "ParamButton.h"
#include "ParamSlider.h"
#include "AboutComponent.h"
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
AutoCompressorAudioProcessorEditor::AutoCompressorAudioProcessorEditor (AutoCompressorAudioProcessor* ownerFilter)
    : AudioProcessorEditor (ownerFilter)
{
    addAndMakeVisible (ratioSlider = new ParamSlider (*getProcessor(), ACProc::ratioParam));
    ratioSlider->setName ("ratioSlider");

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("compression ratio")));
    label->setFont (Font (15.00f, Font::plain));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("knee width")));
    label2->setFont (Font (15.00f, Font::plain));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label3 = new Label ("new label",
                                           TRANS("attack time")));
    label3->setFont (Font (15.00f, Font::plain));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label4 = new Label ("new label",
                                           TRANS("release time")));
    label4->setFont (Font (15.00f, Font::plain));
    label4->setJustificationType (Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label5 = new Label ("new label",
                                           TRANS("make-up gain")));
    label5->setFont (Font (15.00f, Font::plain));
    label5->setJustificationType (Justification::centredLeft);
    label5->setEditable (false, false, false);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label6 = new Label ("new label",
                                           TRANS("threshold")));
    label6->setFont (Font (15.00f, Font::plain));
    label6->setJustificationType (Justification::centredLeft);
    label6->setEditable (false, false, false);
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (meterLabel = new Label ("meterLabel",
                                               TRANS("label text")));
    meterLabel->setFont (Font (15.00f, Font::plain));
    meterLabel->setJustificationType (Justification::centredLeft);
    meterLabel->setEditable (false, false, false);
    meterLabel->setColour (TextEditor::textColourId, Colours::black);
    meterLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (aboutButton = new ImageButton ("aboutButton"));
    aboutButton->setButtonText (String::empty);
    aboutButton->addListener (this);

    aboutButton->setImages (false, true, true,
                            Image(), 1.000f, Colour (0x00000000),
                            Image(), 1.000f, Colour (0x00000000),
                            Image(), 1.000f, Colour (0x00000000));
    addAndMakeVisible (presetBox = new ComboBox ("presetBox"));
    presetBox->setEditableText (true);
    presetBox->setJustificationType (Justification::centredLeft);
    presetBox->setTextWhenNothingSelected (String::empty);
    presetBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    presetBox->addListener (this);

    addAndMakeVisible (thresholdSlider = new ParamSlider (*getProcessor(), ACProc::thresholdParam));
    thresholdSlider->setName ("thresholdSlider");

    addAndMakeVisible (kneeWidthSlider = new ParamSlider (*getProcessor(), ACProc::kneeWidthParam));
    kneeWidthSlider->setName ("kneeWidthSlider");

    addAndMakeVisible (gainSlider = new ParamSlider (*getProcessor(), ACProc::gainParam));
    gainSlider->setName ("gainSlider");

    addAndMakeVisible (attackSlider = new ParamSlider (*getProcessor(), ACProc::attackParam));
    attackSlider->setName ("attackSlider");

    addAndMakeVisible (releaseSlider = new ParamSlider (*getProcessor(), ACProc::releaseParam));
    releaseSlider->setName ("releaseSlider");

    addAndMakeVisible (activeButton = new ParamButton (*getProcessor(), ACProc::activeParam, true));
    activeButton->setName ("activeButton");

    addAndMakeVisible (autoKneeButton = new ParamButton (*getProcessor(), ACProc::autoKneeParam));
    autoKneeButton->setName ("autoKneeButton");

    addAndMakeVisible (autoGainButton = new ParamButton (*getProcessor(), ACProc::autoGainParam));
    autoGainButton->setName ("autoGainButton");

    addAndMakeVisible (autoAttackButton = new ParamButton (*getProcessor(), ACProc::autoAttackParam));
    autoAttackButton->setName ("autoAttackButton");

    addAndMakeVisible (autoReleaseButton = new ParamButton (*getProcessor(), ACProc::autoReleaseParam));
    autoReleaseButton->setName ("autoReleaseButton");


    //[UserPreSize]
    aboutComp = new AboutComponent();

    for (int i = 0; i < getProcessor()->getNumPrograms(); ++i)
    {
        presetBox->addItem(getProcessor()->getProgramName(i), i + 1);
    }
    presetBox->setSelectedId(getProcessor()->getCurrentProgram() + 1, dontSendNotification);
    //[/UserPreSize]

    setSize (460, 400);


    //[Constructor] You can add your own custom stuff here..

    startTimer(50);

    //[/Constructor]
}

AutoCompressorAudioProcessorEditor::~AutoCompressorAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    ratioSlider = nullptr;
    label = nullptr;
    label2 = nullptr;
    label3 = nullptr;
    label4 = nullptr;
    label5 = nullptr;
    label6 = nullptr;
    meterLabel = nullptr;
    aboutButton = nullptr;
    presetBox = nullptr;
    thresholdSlider = nullptr;
    kneeWidthSlider = nullptr;
    gainSlider = nullptr;
    attackSlider = nullptr;
    releaseSlider = nullptr;
    activeButton = nullptr;
    autoKneeButton = nullptr;
    autoGainButton = nullptr;
    autoAttackButton = nullptr;
    autoReleaseButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    aboutComp = nullptr;
    //[/Destructor]
}

//==============================================================================
void AutoCompressorAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff393939));

    g.setColour (Colour (0xff355c2e));
    g.fillRoundedRectangle (0.0f, 0.0f, 460.0f, 48.0f, 10.000f);

    g.setColour (Colours::black);
    g.setFont (Font (28.00f, Font::plain));
    g.drawText (TRANS("auto_compressor"),
                8, 8, 208, 30,
                Justification::centredLeft, true);

    g.setColour (Colours::black);
    g.setFont (Font (24.00f, Font::plain));
    g.drawText (TRANS("ptrv.org"),
                354, 8, 80, 30,
                Justification::centredRight, true);

    g.setColour (Colour (0xff5e6c61));
    g.fillRoundedRectangle (0.0f, 48.0f, 460.0f, 352.0f, 10.000f);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void AutoCompressorAudioProcessorEditor::resized()
{
    ratioSlider->setBounds (144, 148, 212, 32);
    label->setBounds (12, 152, 120, 24);
    label2->setBounds (12, 192, 80, 24);
    label3->setBounds (16, 312, 80, 24);
    label4->setBounds (16, 360, 94, 24);
    label5->setBounds (12, 248, 100, 24);
    label6->setBounds (16, 104, 80, 24);
    meterLabel->setBounds (12, 60, 92, 24);
    aboutButton->setBounds (356, 16, 76, 20);
    presetBox->setBounds (144, 60, 208, 20);
    thresholdSlider->setBounds (144, 100, 212, 32);
    kneeWidthSlider->setBounds (144, 188, 212, 32);
    gainSlider->setBounds (144, 244, 212, 32);
    attackSlider->setBounds (144, 308, 212, 32);
    releaseSlider->setBounds (144, 356, 212, 32);
    activeButton->setBounds (392, 60, 52, 24);
    autoKneeButton->setBounds (392, 172, 52, 24);
    autoGainButton->setBounds (392, 248, 52, 24);
    autoAttackButton->setBounds (392, 316, 52, 24);
    autoReleaseButton->setBounds (392, 356, 52, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void AutoCompressorAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == aboutButton)
    {
        //[UserButtonCode_aboutButton] -- add your button handler code here..
        DialogWindow::showModalDialog("About", aboutComp, this, Colours::black, true);
        //[/UserButtonCode_aboutButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void AutoCompressorAudioProcessorEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == presetBox)
    {
        //[UserComboBoxCode_presetBox] -- add your combo box handling code here..
        AutoCompressorAudioProcessor* const processor = getProcessor();

        // const int selectedId = presetBox->getSelectedId();
        const int selectedItem = presetBox->getSelectedItemIndex();
        if (processor->getCurrentProgram() != selectedItem)
        {
            processor->setCurrentProgram(selectedItem);
            processor->updateHostDisplay();
        }
        const String& currentText = presetBox->getText();
        if (processor->getProgramName(processor->getCurrentProgram()).compare(currentText) != 0)
        {
            processor->changeProgramName(processor->getCurrentProgram(), currentText);
            presetBox->changeItemText(selectedItem, currentText);
        }

        //[/UserComboBoxCode_presetBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void AutoCompressorAudioProcessorEditor::timerCallback()
{
    updateWidgets(dontSendNotification);
}

void AutoCompressorAudioProcessorEditor::updateWidgets(const NotificationType notification)
{
    AutoCompressorAudioProcessor* const processor = getProcessor();

    ratioSlider->setValue(processor->getParameter(ACProc::ratioParam), notification);
    kneeWidthSlider->setValue(processor->getParameter(ACProc::kneeWidthParam), notification);
    gainSlider->setValue(processor->getParameter(ACProc::gainParam), notification);
    thresholdSlider->setValue(processor->getParameter(ACProc::thresholdParam), notification);
    attackSlider->setValue(processor->getParameter(ACProc::attackParam), notification);
    releaseSlider->setValue(processor->getParameter(ACProc::releaseParam), notification);

    const bool activeState = processor->getParameter(ACProc::activeParam) >= 0.5f;
    if (activeState != activeButton->getToggleState())
    {
        activeButton->setToggleState(activeState, notification);
    }
    const bool autoKneeActive = processor->getParameter(ACProc::autoKneeParam) >= 0.5f;
    if (autoKneeActive != autoKneeButton->getToggleState())
    {
        autoKneeButton->setToggleState(autoKneeActive, notification);
    }
    const bool autoGainActive = processor->getParameter(ACProc::autoGainParam) >= 0.5f;
    if (autoGainActive != autoGainButton->getToggleState())
    {
        autoGainButton->setToggleState(autoGainActive, notification);
    }
    const bool autoAttackActive = processor->getParameter(ACProc::autoAttackParam) >= 0.5f;
    if (autoAttackActive != autoAttackButton->getToggleState())
    {
        autoAttackButton->setToggleState(autoAttackActive, notification);
    }
    const bool autoReleaseActive = processor->getParameter(ACProc::autoReleaseParam) >= 0.5f;
    if (autoReleaseActive != autoReleaseButton->getToggleState())
    {
        autoReleaseButton->setToggleState(autoReleaseActive, notification);
    }

    meterLabel->setText(String(processor->getMeter(), 2), notification);

    const bool currentPreset = processor->getCurrentProgram();
    if (currentPreset != presetBox->getSelectedId() - 1)
    {
        presetBox->setSelectedId(currentPreset+1, notification);
    }
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
                 initialWidth="460" initialHeight="400">
  <BACKGROUND backgroundColour="ff393939">
    <ROUNDRECT pos="0 0 460 48" cornerSize="10" fill="solid: ff355c2e" hasStroke="0"/>
    <TEXT pos="8 8 208 30" fill="solid: ff000000" hasStroke="0" text="auto_compressor"
          fontname="Default font" fontsize="28" bold="0" italic="0" justification="33"/>
    <TEXT pos="354 8 80 30" fill="solid: ff000000" hasStroke="0" text="ptrv.org"
          fontname="Default font" fontsize="24" bold="0" italic="0" justification="34"/>
    <ROUNDRECT pos="0 48 460 352" cornerSize="10" fill="solid: ff5e6c61" hasStroke="0"/>
  </BACKGROUND>
  <GENERICCOMPONENT name="ratioSlider" id="e051fdb064a119b2" memberName="ratioSlider"
                    virtualName="" explicitFocusOrder="0" pos="144 148 212 32" class="ParamSlider"
                    params="*getProcessor(), ACProc::ratioParam"/>
  <LABEL name="new label" id="28411f247b38ffe2" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="12 152 120 24" edTextCol="ff000000"
         edBkgCol="0" labelText="compression ratio" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="dc3bfe5fa125e797" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="12 192 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="knee width" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="2a1d30cbfcf1fbc8" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="16 312 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="attack time" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="e0cf7038120d40c1" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="16 360 94 24" edTextCol="ff000000"
         edBkgCol="0" labelText="release time" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="2c2c65be9dad5998" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="12 248 100 24" edTextCol="ff000000"
         edBkgCol="0" labelText="make-up gain" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="18f79e7fdd006853" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="16 104 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="threshold" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="meterLabel" id="bde683baa9c34be7" memberName="meterLabel"
         virtualName="" explicitFocusOrder="0" pos="12 60 92 24" edTextCol="ff000000"
         edBkgCol="0" labelText="label text" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <IMAGEBUTTON name="aboutButton" id="82925c62ef6980b6" memberName="aboutButton"
               virtualName="" explicitFocusOrder="0" pos="356 16 76 20" buttonText=""
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="" opacityNormal="1" colourNormal="0" resourceOver=""
               opacityOver="1" colourOver="0" resourceDown="" opacityDown="1"
               colourDown="0"/>
  <COMBOBOX name="presetBox" id="2afad6bbbce571cd" memberName="presetBox"
            virtualName="" explicitFocusOrder="0" pos="144 60 208 20" editable="1"
            layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <GENERICCOMPONENT name="thresholdSlider" id="f502a58f03897f59" memberName="thresholdSlider"
                    virtualName="" explicitFocusOrder="0" pos="144 100 212 32" class="ParamSlider"
                    params="*getProcessor(), ACProc::thresholdParam"/>
  <GENERICCOMPONENT name="kneeWidthSlider" id="66cef75557d4caa0" memberName="kneeWidthSlider"
                    virtualName="" explicitFocusOrder="0" pos="144 188 212 32" class="ParamSlider"
                    params="*getProcessor(), ACProc::kneeWidthParam"/>
  <GENERICCOMPONENT name="gainSlider" id="bda53adc9c018a6a" memberName="gainSlider"
                    virtualName="" explicitFocusOrder="0" pos="144 244 212 32" class="ParamSlider"
                    params="*getProcessor(), ACProc::gainParam"/>
  <GENERICCOMPONENT name="attackSlider" id="a9bc4498946458b" memberName="attackSlider"
                    virtualName="" explicitFocusOrder="0" pos="144 308 212 32" class="ParamSlider"
                    params="*getProcessor(), ACProc::attackParam"/>
  <GENERICCOMPONENT name="releaseSlider" id="f87ba8db7f623ed0" memberName="releaseSlider"
                    virtualName="" explicitFocusOrder="0" pos="144 356 212 32" class="ParamSlider"
                    params="*getProcessor(), ACProc::releaseParam"/>
  <GENERICCOMPONENT name="activeButton" id="2e5d635360384691" memberName="activeButton"
                    virtualName="" explicitFocusOrder="0" pos="392 60 52 24" class="ParamButton"
                    params="*getProcessor(), ACProc::activeParam, true"/>
  <GENERICCOMPONENT name="autoKneeButton" id="955f50f500671424" memberName="autoKneeButton"
                    virtualName="" explicitFocusOrder="0" pos="392 172 52 24" class="ParamButton"
                    params="*getProcessor(), ACProc::autoKneeParam"/>
  <GENERICCOMPONENT name="autoGainButton" id="f7873d23c60f1105" memberName="autoGainButton"
                    virtualName="" explicitFocusOrder="0" pos="392 248 52 24" class="ParamButton"
                    params="*getProcessor(), ACProc::autoGainParam"/>
  <GENERICCOMPONENT name="autoAttackButton" id="364752664359d1ff" memberName="autoAttackButton"
                    virtualName="" explicitFocusOrder="0" pos="392 316 52 24" class="ParamButton"
                    params="*getProcessor(), ACProc::autoAttackParam"/>
  <GENERICCOMPONENT name="autoReleaseButton" id="e81e1fc3121ab8f1" memberName="autoReleaseButton"
                    virtualName="" explicitFocusOrder="0" pos="392 356 52 24" class="ParamButton"
                    params="*getProcessor(), ACProc::autoReleaseParam"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
