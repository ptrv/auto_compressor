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
#include "jucetice_MeterComponent.h"
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

    addAndMakeVisible (ratioLabel = new Label ("ratioLabel",
                                               TRANS("compression ratio")));
    ratioLabel->setFont (Font (15.00f, Font::plain));
    ratioLabel->setJustificationType (Justification::centredLeft);
    ratioLabel->setEditable (false, false, false);
    ratioLabel->setColour (TextEditor::textColourId, Colours::black);
    ratioLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (kneeWidthLabel = new Label ("kneeWidthLabel",
                                                   TRANS("knee width")));
    kneeWidthLabel->setFont (Font (15.00f, Font::plain));
    kneeWidthLabel->setJustificationType (Justification::centredLeft);
    kneeWidthLabel->setEditable (false, false, false);
    kneeWidthLabel->setColour (TextEditor::textColourId, Colours::black);
    kneeWidthLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (attackLabel = new Label ("attackLabel",
                                                TRANS("attack time")));
    attackLabel->setFont (Font (15.00f, Font::plain));
    attackLabel->setJustificationType (Justification::centredLeft);
    attackLabel->setEditable (false, false, false);
    attackLabel->setColour (TextEditor::textColourId, Colours::black);
    attackLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (releaseLabel = new Label ("releaseLabel",
                                                 TRANS("release time")));
    releaseLabel->setFont (Font (15.00f, Font::plain));
    releaseLabel->setJustificationType (Justification::centredLeft);
    releaseLabel->setEditable (false, false, false);
    releaseLabel->setColour (TextEditor::textColourId, Colours::black);
    releaseLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (gainLabel = new Label ("gainLabel",
                                              TRANS("make-up gain")));
    gainLabel->setFont (Font (15.00f, Font::plain));
    gainLabel->setJustificationType (Justification::centredLeft);
    gainLabel->setEditable (false, false, false);
    gainLabel->setColour (TextEditor::textColourId, Colours::black);
    gainLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (thresholdLabel = new Label ("thresholdLabel",
                                                   TRANS("threshold")));
    thresholdLabel->setFont (Font (15.00f, Font::plain));
    thresholdLabel->setJustificationType (Justification::centredLeft);
    thresholdLabel->setEditable (false, false, false);
    thresholdLabel->setColour (TextEditor::textColourId, Colours::black);
    thresholdLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

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

    addAndMakeVisible (meterComp = new MeterComponent (MeterComponent::MeterHorizontal, 20, 2, Colour(0xff176fff), Colour(0xff176fff), Colour(0xff176fff), Colour(0xff393939)));
    meterComp->setName ("meterComp");

    addAndMakeVisible (autoKneeLabel = new Label ("autoKneeLabel",
                                                  TRANS("auto knee")));
    autoKneeLabel->setFont (Font (11.00f, Font::plain));
    autoKneeLabel->setJustificationType (Justification::centredLeft);
    autoKneeLabel->setEditable (false, false, false);
    autoKneeLabel->setColour (TextEditor::textColourId, Colours::black);
    autoKneeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (autoGainLabel = new Label ("autoGainLabel",
                                                  TRANS("auto gain")));
    autoGainLabel->setFont (Font (11.00f, Font::plain));
    autoGainLabel->setJustificationType (Justification::centredLeft);
    autoGainLabel->setEditable (false, false, false);
    autoGainLabel->setColour (TextEditor::textColourId, Colours::black);
    autoGainLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (autoAttackLabel = new Label ("autoAttackLabel",
                                                    TRANS("auto attack")));
    autoAttackLabel->setFont (Font (11.00f, Font::plain));
    autoAttackLabel->setJustificationType (Justification::centredLeft);
    autoAttackLabel->setEditable (false, false, false);
    autoAttackLabel->setColour (TextEditor::textColourId, Colours::black);
    autoAttackLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (autoReleaseLabel = new Label ("autoReleaseLabel",
                                                     TRANS("auto release")));
    autoReleaseLabel->setFont (Font (11.00f, Font::plain));
    autoReleaseLabel->setJustificationType (Justification::centredLeft);
    autoReleaseLabel->setEditable (false, false, false);
    autoReleaseLabel->setColour (TextEditor::textColourId, Colours::black);
    autoReleaseLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (meterLabel = new Label ("meterLabel",
                                               TRANS("gain reduction")));
    meterLabel->setFont (Font (11.00f, Font::plain));
    meterLabel->setJustificationType (Justification::centredLeft);
    meterLabel->setEditable (false, false, false);
    meterLabel->setColour (TextEditor::textColourId, Colours::black);
    meterLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (meterLabel2 = new Label ("meterLabel",
                                                TRANS("comp.\n"
                                                "active")));
    meterLabel2->setFont (Font (11.00f, Font::plain));
    meterLabel2->setJustificationType (Justification::centred);
    meterLabel2->setEditable (false, false, false);
    meterLabel2->setColour (TextEditor::textColourId, Colours::black);
    meterLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


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
    ratioLabel = nullptr;
    kneeWidthLabel = nullptr;
    attackLabel = nullptr;
    releaseLabel = nullptr;
    gainLabel = nullptr;
    thresholdLabel = nullptr;
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
    meterComp = nullptr;
    autoKneeLabel = nullptr;
    autoGainLabel = nullptr;
    autoAttackLabel = nullptr;
    autoReleaseLabel = nullptr;
    meterLabel = nullptr;
    meterLabel2 = nullptr;


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

    g.setColour (Colour (0xff5c5c5c));
    g.fillRoundedRectangle (2.0f, 2.0f, 456.0f, 44.0f, 12.000f);

    g.setColour (Colours::black);
    g.setFont (Font (28.00f, Font::plain));
    g.drawText (TRANS("auto_compressor"),
                12, 8, 208, 30,
                Justification::centredLeft, true);

    g.setColour (Colours::black);
    g.setFont (Font (24.00f, Font::plain));
    g.drawText (TRANS("ptrv.org"),
                354, 8, 80, 30,
                Justification::centredRight, true);

    g.setColour (Colour (0xff909090));
    g.fillRoundedRectangle (2.0f, 48.0f, 456.0f, 350.0f, 12.000f);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void AutoCompressorAudioProcessorEditor::resized()
{
    ratioSlider->setBounds (144, 148, 212, 32);
    ratioLabel->setBounds (16, 152, 120, 24);
    kneeWidthLabel->setBounds (16, 192, 80, 24);
    attackLabel->setBounds (16, 312, 80, 24);
    releaseLabel->setBounds (16, 360, 94, 24);
    gainLabel->setBounds (16, 248, 100, 24);
    thresholdLabel->setBounds (16, 104, 80, 24);
    aboutButton->setBounds (356, 16, 76, 20);
    presetBox->setBounds (144, 60, 212, 20);
    thresholdSlider->setBounds (144, 100, 212, 32);
    kneeWidthSlider->setBounds (144, 188, 212, 32);
    gainSlider->setBounds (144, 244, 212, 32);
    attackSlider->setBounds (144, 308, 212, 32);
    releaseSlider->setBounds (144, 356, 212, 32);
    activeButton->setBounds (392, 72, 52, 24);
    autoKneeButton->setBounds (392, 172, 52, 24);
    autoGainButton->setBounds (392, 248, 52, 24);
    autoAttackButton->setBounds (392, 316, 52, 24);
    autoReleaseButton->setBounds (392, 356, 52, 24);
    meterComp->setBounds (20, 72, 100, 12);
    autoKneeLabel->setBounds (388, 156, 56, 16);
    autoGainLabel->setBounds (388, 232, 56, 16);
    autoAttackLabel->setBounds (388, 300, 64, 16);
    autoReleaseLabel->setBounds (388, 340, 64, 16);
    meterLabel->setBounds (16, 56, 88, 16);
    meterLabel2->setBounds (396, 48, 44, 24);
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

    meterComp->setValue(1.0f - processor->getMeter());

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
    <ROUNDRECT pos="2 2 456 44" cornerSize="12" fill="solid: ff5c5c5c" hasStroke="0"/>
    <TEXT pos="12 8 208 30" fill="solid: ff000000" hasStroke="0" text="auto_compressor"
          fontname="Default font" fontsize="28" bold="0" italic="0" justification="33"/>
    <TEXT pos="354 8 80 30" fill="solid: ff000000" hasStroke="0" text="ptrv.org"
          fontname="Default font" fontsize="24" bold="0" italic="0" justification="34"/>
    <ROUNDRECT pos="2 48 456 350" cornerSize="12" fill="solid: ff909090" hasStroke="0"/>
  </BACKGROUND>
  <GENERICCOMPONENT name="ratioSlider" id="e051fdb064a119b2" memberName="ratioSlider"
                    virtualName="" explicitFocusOrder="0" pos="144 148 212 32" class="ParamSlider"
                    params="*getProcessor(), ACProc::ratioParam"/>
  <LABEL name="ratioLabel" id="28411f247b38ffe2" memberName="ratioLabel"
         virtualName="" explicitFocusOrder="0" pos="16 152 120 24" edTextCol="ff000000"
         edBkgCol="0" labelText="compression ratio" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="kneeWidthLabel" id="dc3bfe5fa125e797" memberName="kneeWidthLabel"
         virtualName="" explicitFocusOrder="0" pos="16 192 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="knee width" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="attackLabel" id="2a1d30cbfcf1fbc8" memberName="attackLabel"
         virtualName="" explicitFocusOrder="0" pos="16 312 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="attack time" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="releaseLabel" id="e0cf7038120d40c1" memberName="releaseLabel"
         virtualName="" explicitFocusOrder="0" pos="16 360 94 24" edTextCol="ff000000"
         edBkgCol="0" labelText="release time" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="gainLabel" id="2c2c65be9dad5998" memberName="gainLabel"
         virtualName="" explicitFocusOrder="0" pos="16 248 100 24" edTextCol="ff000000"
         edBkgCol="0" labelText="make-up gain" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="thresholdLabel" id="18f79e7fdd006853" memberName="thresholdLabel"
         virtualName="" explicitFocusOrder="0" pos="16 104 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="threshold" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <IMAGEBUTTON name="aboutButton" id="82925c62ef6980b6" memberName="aboutButton"
               virtualName="" explicitFocusOrder="0" pos="356 16 76 20" buttonText=""
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="" opacityNormal="1" colourNormal="0" resourceOver=""
               opacityOver="1" colourOver="0" resourceDown="" opacityDown="1"
               colourDown="0"/>
  <COMBOBOX name="presetBox" id="2afad6bbbce571cd" memberName="presetBox"
            virtualName="" explicitFocusOrder="0" pos="144 60 212 20" editable="1"
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
                    virtualName="" explicitFocusOrder="0" pos="392 72 52 24" class="ParamButton"
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
  <GENERICCOMPONENT name="meterComp" id="9671aa124d1a4c42" memberName="meterComp"
                    virtualName="" explicitFocusOrder="0" pos="20 72 100 12" class="MeterComponent"
                    params="MeterComponent::MeterHorizontal, 20, 2, Colour(0xff176fff), Colour(0xff176fff), Colour(0xff176fff), Colour(0xff393939)"/>
  <LABEL name="autoKneeLabel" id="d1e338b64af9e6d7" memberName="autoKneeLabel"
         virtualName="" explicitFocusOrder="0" pos="388 156 56 16" edTextCol="ff000000"
         edBkgCol="0" labelText="auto knee" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="11"
         bold="0" italic="0" justification="33"/>
  <LABEL name="autoGainLabel" id="b643405d2da66da2" memberName="autoGainLabel"
         virtualName="" explicitFocusOrder="0" pos="388 232 56 16" edTextCol="ff000000"
         edBkgCol="0" labelText="auto gain" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="11"
         bold="0" italic="0" justification="33"/>
  <LABEL name="autoAttackLabel" id="2d9961ef1ffa4aba" memberName="autoAttackLabel"
         virtualName="" explicitFocusOrder="0" pos="388 300 64 16" edTextCol="ff000000"
         edBkgCol="0" labelText="auto attack" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="11" bold="0" italic="0" justification="33"/>
  <LABEL name="autoReleaseLabel" id="b433d36af4f7a8c8" memberName="autoReleaseLabel"
         virtualName="" explicitFocusOrder="0" pos="388 340 64 16" edTextCol="ff000000"
         edBkgCol="0" labelText="auto release" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="11" bold="0" italic="0" justification="33"/>
  <LABEL name="meterLabel" id="e16d72ef2d78ae78" memberName="meterLabel"
         virtualName="" explicitFocusOrder="0" pos="16 56 88 16" edTextCol="ff000000"
         edBkgCol="0" labelText="gain reduction" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="11" bold="0" italic="0" justification="33"/>
  <LABEL name="meterLabel" id="3cc15c2d5c71bfdc" memberName="meterLabel2"
         virtualName="" explicitFocusOrder="0" pos="396 48 44 24" edTextCol="ff000000"
         edBkgCol="0" labelText="comp.&#10;active" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="11" bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
