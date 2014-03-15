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
#include <functional>

#include "PluginProcessor.h"
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
    addAndMakeVisible (ratioSlider = new ParamSlider ("ratioSlider"));
    ratioSlider->setRange (0, 1, 0);
    ratioSlider->setSliderStyle (Slider::LinearHorizontal);
    ratioSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    ratioSlider->addListener (this);

    addAndMakeVisible (kneeWidthSlider = new ParamSlider ("kneeWidthSlider"));
    kneeWidthSlider->setRange (0, 1, 0);
    kneeWidthSlider->setSliderStyle (Slider::LinearHorizontal);
    kneeWidthSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    kneeWidthSlider->addListener (this);

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

    addAndMakeVisible (attackSlider = new ParamSlider ("attackSlider"));
    attackSlider->setRange (0, 1, 0);
    attackSlider->setSliderStyle (Slider::LinearHorizontal);
    attackSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    attackSlider->addListener (this);

    addAndMakeVisible (releaseSlider = new ParamSlider ("releaseSlider"));
    releaseSlider->setRange (0, 1, 0);
    releaseSlider->setSliderStyle (Slider::LinearHorizontal);
    releaseSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    releaseSlider->addListener (this);

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

    addAndMakeVisible (gainSlider = new ParamSlider ("gainSlider"));
    gainSlider->setRange (0, 1, 0);
    gainSlider->setSliderStyle (Slider::LinearHorizontal);
    gainSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    gainSlider->addListener (this);

    addAndMakeVisible (thresholdSlider = new ParamSlider ("thresholdSlider"));
    thresholdSlider->setRange (0, 1, 0);
    thresholdSlider->setSliderStyle (Slider::LinearHorizontal);
    thresholdSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    thresholdSlider->addListener (this);

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

    addAndMakeVisible (imageButton = new ImageButton ("new button"));
    imageButton->addListener (this);

    imageButton->setImages (false, true, true,
                            ImageCache::getFromMemory (bt_off_png, bt_off_pngSize), 1.000f, Colour (0x00000000),
                            Image(), 1.000f, Colour (0x00000000),
                            ImageCache::getFromMemory (bt_on_png, bt_on_pngSize), 1.000f, Colour (0x00000000));
    addAndMakeVisible (autoKneeButton = new ImageButton ("autoRatioButton"));
    autoKneeButton->setButtonText (String::empty);
    autoKneeButton->addListener (this);

    autoKneeButton->setImages (false, true, true,
                               ImageCache::getFromMemory (bt_off2_png, bt_off2_pngSize), 1.000f, Colour (0x00000000),
                               Image(), 1.000f, Colour (0x00000000),
                               ImageCache::getFromMemory (bt_on2_png, bt_on2_pngSize), 1.000f, Colour (0x00000000));
    addAndMakeVisible (autoGainButton = new ImageButton ("autoGainButton"));
    autoGainButton->setButtonText (String::empty);
    autoGainButton->addListener (this);

    autoGainButton->setImages (false, true, true,
                               ImageCache::getFromMemory (bt_off2_png, bt_off2_pngSize), 1.000f, Colour (0x00000000),
                               Image(), 1.000f, Colour (0x00000000),
                               ImageCache::getFromMemory (bt_on2_png, bt_on2_pngSize), 1.000f, Colour (0x00000000));
    addAndMakeVisible (autoAttackButton = new ImageButton ("autoAttackButton"));
    autoAttackButton->setButtonText (String::empty);
    autoAttackButton->addListener (this);

    autoAttackButton->setImages (false, true, true,
                                 ImageCache::getFromMemory (bt_off2_png, bt_off2_pngSize), 1.000f, Colour (0x00000000),
                                 Image(), 1.000f, Colour (0x00000000),
                                 ImageCache::getFromMemory (bt_on2_png, bt_on2_pngSize), 1.000f, Colour (0x00000000));
    addAndMakeVisible (autoReleaseButton = new ImageButton ("autoReleaseButton"));
    autoReleaseButton->setButtonText (String::empty);
    autoReleaseButton->addListener (this);

    autoReleaseButton->setImages (false, true, true,
                                  ImageCache::getFromMemory (bt_off2_png, bt_off2_pngSize), 1.000f, Colour (0x00000000),
                                  Image(), 1.000f, Colour (0x00000000),
                                  ImageCache::getFromMemory (bt_on2_png, bt_on2_pngSize), 1.000f, Colour (0x00000000));
    addAndMakeVisible (aboutButton = new ImageButton ("aboutButton"));
    aboutButton->setButtonText (String::empty);
    aboutButton->addListener (this);

    aboutButton->setImages (false, true, true,
                            Image(), 1.000f, Colour (0x00000000),
                            Image(), 1.000f, Colour (0x00000000),
                            Image(), 1.000f, Colour (0x00000000));

    //[UserPreSize]
    using namespace std::placeholders;

    ratioSlider->setTextValueSuffix(getProcessor()->getParameterLabel(ACProc::ratioParam));
    ratioSlider->setTextToValueConverter(std::bind(&ACEditor::convertTextToValue, this,
                                                   ACProc::ratioParam, _1));
    ratioSlider->setValueToTextConverter(std::bind(&ACEditor::convertValueToText, this,
                                                   ACProc::ratioParam, _1));
    ratioSlider->updateText();

    kneeWidthSlider->setTextValueSuffix(getProcessor()->getParameterLabel(ACProc::kneeWidthParam));
    kneeWidthSlider->setTextToValueConverter(std::bind(&ACEditor::convertTextToValue, this,
                                                   ACProc::kneeWidthParam, _1));
    kneeWidthSlider->setValueToTextConverter(std::bind(&ACEditor::convertValueToText, this,
                                                   ACProc::kneeWidthParam, _1));
    kneeWidthSlider->updateText();

    gainSlider->setTextValueSuffix(getProcessor()->getParameterLabel(ACProc::gainParam));
    gainSlider->setTextToValueConverter(std::bind(&ACEditor::convertTextToValue, this,
                                                   ACProc::gainParam, _1));
    gainSlider->setValueToTextConverter(std::bind(&ACEditor::convertValueToText, this,
                                                   ACProc::gainParam, _1));
    gainSlider->updateText();

    thresholdSlider->setTextValueSuffix(getProcessor()->getParameterLabel(ACProc::thresholdParam));
    thresholdSlider->setTextToValueConverter(std::bind(&ACEditor::convertTextToValue, this,
                                               ACProc::thresholdParam, _1));
    thresholdSlider->setValueToTextConverter(std::bind(&ACEditor::convertValueToText, this,
                                               ACProc::thresholdParam, _1));
    thresholdSlider->updateText();

    attackSlider->setTextValueSuffix(getProcessor()->getParameterLabel(ACProc::attackParam));
    attackSlider->setTextToValueConverter(std::bind(&ACEditor::convertTextToValue, this,
                                               ACProc::attackParam, _1));
    attackSlider->setValueToTextConverter(std::bind(&ACEditor::convertValueToText, this,
                                               ACProc::attackParam, _1));
    attackSlider->updateText();

    releaseSlider->setTextValueSuffix(getProcessor()->getParameterLabel(ACProc::releaseParam));
    releaseSlider->setTextToValueConverter(std::bind(&ACEditor::convertTextToValue, this,
                                               ACProc::releaseParam, _1));
    releaseSlider->setValueToTextConverter(std::bind(&ACEditor::convertValueToText, this,
                                               ACProc::releaseParam, _1));
    releaseSlider->updateText();

    aboutComp = new AboutComponent();
    //[/UserPreSize]

    setSize (460, 400);


    //[Constructor] You can add your own custom stuff here..

    startTimer(50);

    imageButton->setClickingTogglesState(true);
    autoKneeButton->setClickingTogglesState(true);
    autoGainButton->setClickingTogglesState(true);
    autoAttackButton->setClickingTogglesState(true);
    autoReleaseButton->setClickingTogglesState(true);

    //[/Constructor]
}

AutoCompressorAudioProcessorEditor::~AutoCompressorAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    ratioSlider = nullptr;
    kneeWidthSlider = nullptr;
    label = nullptr;
    label2 = nullptr;
    attackSlider = nullptr;
    releaseSlider = nullptr;
    label3 = nullptr;
    label4 = nullptr;
    gainSlider = nullptr;
    thresholdSlider = nullptr;
    label5 = nullptr;
    label6 = nullptr;
    meterLabel = nullptr;
    imageButton = nullptr;
    autoKneeButton = nullptr;
    autoGainButton = nullptr;
    autoAttackButton = nullptr;
    autoReleaseButton = nullptr;
    aboutButton = nullptr;


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
    kneeWidthSlider->setBounds (144, 192, 212, 20);
    label->setBounds (12, 152, 120, 24);
    label2->setBounds (12, 192, 80, 24);
    attackSlider->setBounds (144, 316, 212, 20);
    releaseSlider->setBounds (144, 360, 212, 20);
    label3->setBounds (16, 312, 80, 24);
    label4->setBounds (16, 360, 94, 24);
    gainSlider->setBounds (144, 248, 212, 20);
    thresholdSlider->setBounds (144, 104, 216, 20);
    label5->setBounds (12, 248, 100, 24);
    label6->setBounds (16, 104, 80, 24);
    meterLabel->setBounds (12, 60, 150, 24);
    imageButton->setBounds (392, 56, 52, 24);
    autoKneeButton->setBounds (392, 172, 50, 24);
    autoGainButton->setBounds (392, 248, 50, 24);
    autoAttackButton->setBounds (392, 316, 50, 24);
    autoReleaseButton->setBounds (392, 356, 50, 24);
    aboutButton->setBounds (356, 16, 76, 20);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void AutoCompressorAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == ratioSlider)
    {
        //[UserSliderCode_ratioSlider] -- add your slider handling code here..
        getProcessor()->setParameterNotifyingHost(ACProc::ratioParam,
                                                  (float) ratioSlider->getValue());
        //[/UserSliderCode_ratioSlider]
    }
    else if (sliderThatWasMoved == kneeWidthSlider)
    {
        //[UserSliderCode_kneeWidthSlider] -- add your slider handling code here..
        getProcessor()->setParameterNotifyingHost(ACProc::kneeWidthParam,
                                                  (float) kneeWidthSlider->getValue());
        //[/UserSliderCode_kneeWidthSlider]
    }
    else if (sliderThatWasMoved == attackSlider)
    {
        //[UserSliderCode_attackSlider] -- add your slider handling code here..
        getProcessor()->setParameterNotifyingHost(ACProc::attackParam,
                                                  (float) attackSlider->getValue());
        //[/UserSliderCode_attackSlider]
    }
    else if (sliderThatWasMoved == releaseSlider)
    {
        //[UserSliderCode_releaseSlider] -- add your slider handling code here..
        getProcessor()->setParameterNotifyingHost(ACProc::releaseParam,
                                                  (float) releaseSlider->getValue());
        //[/UserSliderCode_releaseSlider]
    }
    else if (sliderThatWasMoved == gainSlider)
    {
        //[UserSliderCode_gainSlider] -- add your slider handling code here..
        getProcessor()->setParameterNotifyingHost(ACProc::gainParam,
                                                  (float) gainSlider->getValue());
        //[/UserSliderCode_gainSlider]
    }
    else if (sliderThatWasMoved == thresholdSlider)
    {
        //[UserSliderCode_thresholdSlider] -- add your slider handling code here..
        getProcessor()->setParameterNotifyingHost(ACProc::thresholdParam,
                                                  (float) thresholdSlider->getValue());
        //[/UserSliderCode_thresholdSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void AutoCompressorAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == imageButton)
    {
        //[UserButtonCode_imageButton] -- add your button handler code here..
        const bool activeState = imageButton->getToggleState();
        getProcessor()->setParameterNotifyingHost(ACProc::activeParam,
                                                  activeState ? 1.f : 0.f);
        //[/UserButtonCode_imageButton]
    }
    else if (buttonThatWasClicked == autoKneeButton)
    {
        //[UserButtonCode_autoKneeButton] -- add your button handler code here..
        const bool autoKneeActive = autoKneeButton->getToggleState();
        getProcessor()->setParameterNotifyingHost(ACProc::autoKneeParam,
                                                  autoKneeActive ? 1.f : 0.f);
        //[/UserButtonCode_autoKneeButton]
    }
    else if (buttonThatWasClicked == autoGainButton)
    {
        //[UserButtonCode_autoGainButton] -- add your button handler code here..
        const bool autoGainActive = autoGainButton->getToggleState();
        getProcessor()->setParameterNotifyingHost(ACProc::autoGainParam,
                                                  autoGainActive ? 1.f : 0.f);
        //[/UserButtonCode_autoGainButton]
    }
    else if (buttonThatWasClicked == autoAttackButton)
    {
        //[UserButtonCode_autoAttackButton] -- add your button handler code here..
        const bool autoAttackActive = autoAttackButton->getToggleState();
        getProcessor()->setParameterNotifyingHost(ACProc::autoAttackParam,
                                                  autoAttackActive ? 1.f : 0.f);
        //[/UserButtonCode_autoAttackButton]
    }
    else if (buttonThatWasClicked == autoReleaseButton)
    {
        //[UserButtonCode_autoReleaseButton] -- add your button handler code here..
        const bool autoReleaseActive = autoReleaseButton->getToggleState();
        getProcessor()->setParameterNotifyingHost(ACProc::autoReleaseParam,
                                                  autoReleaseActive ? 1.f : 0.f);
        //[/UserButtonCode_autoReleaseButton]
    }
    else if (buttonThatWasClicked == aboutButton)
    {
        //[UserButtonCode_aboutButton] -- add your button handler code here..
        DialogWindow::showModalDialog("About", aboutComp, this, Colours::black, true);
        //[/UserButtonCode_aboutButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void AutoCompressorAudioProcessorEditor::timerCallback()
{
    AutoCompressorAudioProcessor* const processor = getProcessor();

    ratioSlider->setValue(processor->getParameter(ACProc::ratioParam), dontSendNotification);
    kneeWidthSlider->setValue(processor->getParameter(ACProc::kneeWidthParam), dontSendNotification);
    gainSlider->setValue(processor->getParameter(ACProc::gainParam), dontSendNotification);
    thresholdSlider->setValue(processor->getParameter(ACProc::thresholdParam), dontSendNotification);
    attackSlider->setValue(processor->getParameter(ACProc::attackParam), dontSendNotification);
    releaseSlider->setValue(processor->getParameter(ACProc::releaseParam), dontSendNotification);

    const bool activeState = processor->getParameter(ACProc::activeParam) >= 0.5f;
    if (activeState != imageButton->getToggleState())
    {
        imageButton->setToggleState(activeState, dontSendNotification);
    }
    const bool autoKneeActive = processor->getParameter(ACProc::autoKneeParam) >= 0.5f;
    if (autoKneeActive != autoKneeButton->getToggleState())
    {
        autoKneeButton->setToggleState(autoKneeActive, dontSendNotification);
    }
    const bool autoGainActive = processor->getParameter(ACProc::autoGainParam) >= 0.5f;
    if (autoGainActive != autoGainButton->getToggleState())
    {
        autoGainButton->setToggleState(autoGainActive, dontSendNotification);
    }
    const bool autoAttackActive = processor->getParameter(ACProc::autoAttackParam) >= 0.5f;
    if (autoAttackActive != autoAttackButton->getToggleState())
    {
        autoAttackButton->setToggleState(autoAttackActive, dontSendNotification);
    }
    const bool autoReleaseActive = processor->getParameter(ACProc::autoReleaseParam) >= 0.5f;
    if (autoReleaseActive != autoReleaseButton->getToggleState())
    {
        autoReleaseButton->setToggleState(autoReleaseActive, dontSendNotification);
    }

    meterLabel->setText(String(processor->getMeter(), 2), dontSendNotification);
}

double AutoCompressorAudioProcessorEditor::convertTextToValue(int index, const String& text)
{
    return getProcessor()->getParameterFromString(index, text);
}

String AutoCompressorAudioProcessorEditor::convertValueToText(int index, const double /*value*/)
{
    return getProcessor()->getParameterText(index);
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
  <SLIDER name="ratioSlider" id="ffe07162fd997e54" memberName="ratioSlider"
          virtualName="ParamSlider" explicitFocusOrder="0" pos="144 148 212 32"
          min="0" max="1" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="kneeWidthSlider" id="f291c6e207934e0e" memberName="kneeWidthSlider"
          virtualName="ParamSlider" explicitFocusOrder="0" pos="144 192 212 20"
          min="0" max="1" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
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
  <SLIDER name="attackSlider" id="8a15b9bd1874de96" memberName="attackSlider"
          virtualName="ParamSlider" explicitFocusOrder="0" pos="144 316 212 20"
          min="0" max="1" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="releaseSlider" id="5b7ca9c55f02943" memberName="releaseSlider"
          virtualName="ParamSlider" explicitFocusOrder="0" pos="144 360 212 20"
          min="0" max="1" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
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
  <SLIDER name="gainSlider" id="581538f5944b4752" memberName="gainSlider"
          virtualName="ParamSlider" explicitFocusOrder="0" pos="144 248 212 20"
          min="0" max="1" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="thresholdSlider" id="d44fe020750dd2e" memberName="thresholdSlider"
          virtualName="ParamSlider" explicitFocusOrder="0" pos="144 104 216 20"
          min="0" max="1" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
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
         virtualName="" explicitFocusOrder="0" pos="12 60 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="label text" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <IMAGEBUTTON name="new button" id="a12c78ba715400e7" memberName="imageButton"
               virtualName="" explicitFocusOrder="0" pos="392 56 52 24" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="bt_off_png" opacityNormal="1" colourNormal="0"
               resourceOver="" opacityOver="1" colourOver="0" resourceDown="bt_on_png"
               opacityDown="1" colourDown="0"/>
  <IMAGEBUTTON name="autoRatioButton" id="19b4c8f5dee0efb5" memberName="autoKneeButton"
               virtualName="" explicitFocusOrder="0" pos="392 172 50 24" buttonText=""
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="bt_off2_png" opacityNormal="1" colourNormal="0"
               resourceOver="" opacityOver="1" colourOver="0" resourceDown="bt_on2_png"
               opacityDown="1" colourDown="0"/>
  <IMAGEBUTTON name="autoGainButton" id="c8f862ce9708f18" memberName="autoGainButton"
               virtualName="" explicitFocusOrder="0" pos="392 248 50 24" buttonText=""
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="bt_off2_png" opacityNormal="1" colourNormal="0"
               resourceOver="" opacityOver="1" colourOver="0" resourceDown="bt_on2_png"
               opacityDown="1" colourDown="0"/>
  <IMAGEBUTTON name="autoAttackButton" id="5f462b4a4228f13a" memberName="autoAttackButton"
               virtualName="" explicitFocusOrder="0" pos="392 316 50 24" buttonText=""
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="bt_off2_png" opacityNormal="1" colourNormal="0"
               resourceOver="" opacityOver="1" colourOver="0" resourceDown="bt_on2_png"
               opacityDown="1" colourDown="0"/>
  <IMAGEBUTTON name="autoReleaseButton" id="f78e3c201b4952ba" memberName="autoReleaseButton"
               virtualName="" explicitFocusOrder="0" pos="392 356 50 24" buttonText=""
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="bt_off2_png" opacityNormal="1" colourNormal="0"
               resourceOver="" opacityOver="1" colourOver="0" resourceDown="bt_on2_png"
               opacityDown="1" colourDown="0"/>
  <IMAGEBUTTON name="aboutButton" id="82925c62ef6980b6" memberName="aboutButton"
               virtualName="" explicitFocusOrder="0" pos="356 16 76 20" buttonText=""
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="" opacityNormal="1" colourNormal="0" resourceOver=""
               opacityOver="1" colourOver="0" resourceDown="" opacityDown="1"
               colourDown="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: bt_off_png, 1615, "BinaryData/bt_off.png"
static const unsigned char resource_AutoCompressorAudioProcessorEditor_bt_off_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,60,0,0,0,33,8,6,0,0,0,133,180,200,55,0,0,0,6,98,75,71,68,0,255,
0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,222,2,23,19,59,23,242,239,156,111,0,0,5,220,73,68,65,84,88,195,197,153,77,111,19,71,24,199,127,
207,120,214,14,113,32,9,9,41,162,18,45,74,67,69,145,16,165,84,170,122,64,234,87,168,160,234,13,33,193,167,224,76,175,253,2,145,16,23,144,90,85,189,245,132,144,170,170,189,244,77,234,173,82,15,133,138,
40,64,130,223,226,216,235,221,153,233,161,179,238,100,217,77,156,56,50,35,141,118,118,109,175,247,183,255,255,51,47,207,8,187,23,97,239,82,244,29,183,199,111,28,175,169,200,30,215,165,160,30,164,184,224,
152,175,175,21,88,128,235,192,219,5,144,7,1,126,2,220,15,224,108,80,93,112,116,175,75,237,47,75,84,24,167,126,7,188,1,44,2,243,192,49,96,26,168,1,26,80,99,56,103,44,133,197,191,113,46,95,190,204,252,252,
252,171,190,116,110,95,231,143,30,61,202,154,159,0,143,129,20,24,248,154,248,243,20,48,147,138,109,93,4,63,59,59,203,226,226,226,14,136,16,102,55,208,162,239,3,239,1,109,32,6,250,65,37,103,111,38,5,188,
35,62,211,52,37,73,146,195,0,205,202,156,183,244,54,208,5,42,1,172,41,129,21,96,202,135,192,172,15,3,252,61,90,254,5,246,247,235,138,80,97,149,53,78,157,58,197,233,211,167,17,145,33,68,88,173,181,175,
28,179,118,120,30,148,5,224,36,208,241,177,171,252,131,166,222,218,198,159,103,214,174,120,200,143,129,171,192,37,17,89,242,159,61,23,145,223,68,228,27,99,204,143,30,222,236,7,248,149,33,231,218,181,107,
92,185,114,5,165,20,34,130,115,14,99,12,198,24,146,36,25,58,32,95,7,131,193,142,243,213,213,213,80,225,133,224,5,103,177,156,89,91,5,15,45,30,246,115,224,150,136,156,141,170,181,90,109,106,90,1,164,131,
248,196,96,208,95,22,145,139,81,20,173,38,73,114,31,104,140,170,116,97,12,91,107,73,211,20,165,212,14,133,141,49,88,107,135,199,124,205,59,33,40,71,61,180,243,138,246,188,210,145,87,51,124,225,83,94,217,
91,213,106,245,220,210,201,55,107,139,139,39,217,216,220,196,57,75,146,36,98,76,58,221,105,110,156,115,206,222,172,213,106,143,227,56,126,232,239,185,103,81,1,236,208,210,198,152,161,138,105,154,238,104,
103,74,231,161,139,44,30,148,35,64,221,199,225,84,14,86,229,128,143,1,87,69,228,236,91,103,86,106,231,207,95,192,225,152,153,153,193,57,136,162,136,74,69,51,123,124,169,42,34,103,157,115,159,213,235,245,
217,81,45,173,138,46,102,192,121,232,172,142,2,157,83,184,234,33,107,190,173,75,96,241,118,190,164,148,170,46,47,175,208,217,218,226,131,75,23,121,103,249,12,173,230,6,253,126,143,65,220,39,238,247,169,
207,28,173,138,200,251,74,169,185,131,116,90,59,128,147,36,65,68,134,49,156,193,132,176,33,116,145,205,115,255,19,249,99,6,91,41,153,116,76,139,200,210,194,194,98,165,221,238,240,116,109,141,245,245,103,
195,251,247,123,93,68,20,211,245,163,36,113,87,57,231,150,106,181,90,189,211,233,140,7,156,166,233,176,151,206,226,184,12,184,12,58,231,36,21,0,170,130,73,207,142,210,108,54,92,171,213,146,56,238,51,24,
196,36,131,152,40,170,161,148,34,73,98,223,215,152,97,63,51,214,196,163,76,225,176,183,30,5,58,119,239,34,251,22,205,207,183,129,231,214,218,133,70,99,83,245,123,219,88,107,16,17,84,165,194,202,202,89,
214,214,214,168,84,52,221,246,134,213,90,191,136,162,104,123,44,75,103,177,90,164,112,86,51,23,236,6,95,50,153,216,107,17,210,18,145,223,157,115,203,141,205,103,21,93,157,146,255,239,37,116,58,91,76,79,
215,89,127,250,55,192,32,138,162,63,180,214,173,67,139,225,16,56,180,117,25,116,104,251,3,150,182,181,246,107,173,245,5,99,210,115,42,141,171,149,104,74,42,186,202,241,227,11,244,123,219,188,120,246,15,
192,64,107,253,87,20,69,95,25,99,154,99,3,151,41,92,20,203,101,208,7,44,125,224,39,107,237,170,136,220,76,146,228,93,107,109,213,36,125,213,105,26,186,221,174,13,96,239,106,173,127,88,91,91,235,29,10,
112,126,222,92,100,235,125,90,122,212,100,65,203,90,251,32,138,162,39,206,185,79,129,15,147,36,89,106,183,219,104,173,95,104,173,127,173,86,171,223,122,216,145,103,89,187,198,112,182,120,200,58,173,178,
56,206,102,101,69,208,99,164,120,12,208,136,227,248,97,189,94,255,89,41,53,87,175,215,235,0,81,20,109,107,173,91,198,152,166,87,246,192,139,135,145,98,56,132,46,139,229,172,93,0,185,159,236,134,3,122,
221,110,183,7,172,143,58,206,142,213,75,151,41,92,212,121,229,97,115,33,49,40,1,158,120,122,71,231,99,7,152,29,85,225,189,98,217,151,4,120,89,146,203,154,120,22,83,130,73,65,21,184,1,124,225,231,179,135,
85,126,1,254,244,75,184,151,192,115,96,29,120,6,188,240,215,182,131,180,207,196,20,6,120,0,124,15,124,228,161,231,125,166,226,152,95,237,228,151,116,69,83,195,48,37,219,240,48,61,159,222,137,61,88,26,
100,58,94,177,245,245,219,119,37,88,118,200,48,40,178,101,8,64,3,71,253,191,230,189,59,55,220,126,21,22,15,50,229,193,230,128,227,192,146,207,56,102,217,198,35,254,47,43,123,100,27,195,180,108,226,199,
214,54,208,4,54,189,178,155,94,221,166,255,60,1,210,235,119,238,10,41,226,95,133,160,144,97,110,36,155,149,87,0,139,67,112,164,56,166,225,222,237,209,160,67,96,237,21,60,226,225,50,232,19,94,237,25,255,
66,194,117,236,110,59,15,25,112,234,149,237,120,232,204,218,13,223,103,116,60,112,186,159,84,205,56,150,14,45,104,130,7,220,246,106,70,254,218,110,89,138,221,134,160,44,157,211,5,182,60,116,215,67,14,
130,124,150,155,116,47,109,115,138,132,42,198,254,33,163,130,228,185,236,50,169,200,178,146,153,173,179,172,101,55,176,177,41,232,181,39,54,44,101,15,23,170,103,188,186,97,166,98,212,109,151,236,158,38,
232,180,194,188,116,152,177,156,232,56,236,10,20,33,104,247,114,153,138,81,128,109,206,57,73,201,206,131,157,84,18,190,104,88,178,193,11,176,65,76,171,0,84,237,177,243,88,182,99,104,130,142,201,4,86,158,
216,54,75,217,238,161,228,50,20,249,244,140,236,3,56,95,109,193,46,226,68,103,90,255,2,205,240,57,177,40,229,140,156,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* AutoCompressorAudioProcessorEditor::bt_off_png = (const char*) resource_AutoCompressorAudioProcessorEditor_bt_off_png;
const int AutoCompressorAudioProcessorEditor::bt_off_pngSize = 1615;

// JUCER_RESOURCE: bt_on_png, 2017, "BinaryData/bt_on.png"
static const unsigned char resource_AutoCompressorAudioProcessorEditor_bt_on_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,60,0,0,0,33,8,6,0,0,0,133,180,200,55,0,0,0,6,98,75,71,68,0,255,
0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,222,2,23,20,0,3,209,200,177,175,0,0,7,110,73,68,65,84,88,195,205,153,205,111,29,87,25,198,127,
231,99,238,189,190,182,227,92,199,78,234,166,197,181,99,154,38,77,131,16,21,46,172,144,80,133,2,82,165,34,121,197,162,251,252,19,237,178,75,54,17,11,182,236,82,84,33,20,33,65,23,80,65,20,54,8,209,36,150,
163,72,109,104,176,93,37,142,175,227,235,143,185,51,231,188,44,230,140,51,153,204,92,219,168,117,56,210,171,57,115,103,238,156,243,156,231,61,239,215,81,60,221,84,197,189,42,61,83,53,239,230,77,6,92,165,
230,221,35,107,106,31,160,117,114,80,192,131,228,185,0,183,21,64,223,3,94,41,1,27,196,174,170,152,116,222,191,7,252,6,240,225,55,191,15,240,35,99,89,1,26,248,229,1,152,57,172,252,30,24,5,218,64,11,104,
132,133,54,97,76,5,40,217,147,113,45,140,24,97,40,18,154,77,161,209,18,162,33,97,180,157,201,177,33,225,120,75,24,109,100,239,96,4,180,156,207,254,127,80,176,132,193,211,111,104,81,191,11,124,17,190,239,
130,236,177,254,1,168,247,179,190,130,113,13,91,6,180,6,101,64,12,136,2,29,230,105,194,218,196,14,188,3,237,193,56,104,121,120,36,1,148,236,167,210,69,224,92,190,124,153,185,185,57,68,4,239,253,158,56,
231,42,251,117,207,174,92,185,146,127,242,12,176,28,22,53,41,140,239,243,113,175,130,94,96,72,67,207,64,203,66,106,193,91,208,54,3,237,85,224,68,178,5,83,41,52,18,112,233,147,169,143,123,56,37,176,200,
161,0,207,206,206,114,241,226,197,103,0,29,86,10,173,1,52,195,24,79,169,252,143,104,235,243,104,153,69,107,216,53,160,44,196,141,109,76,235,54,140,46,145,116,86,97,108,11,218,224,24,134,237,147,208,61,
139,89,191,128,223,108,35,113,166,1,189,0,103,209,203,0,150,109,105,15,103,22,71,4,231,28,34,178,199,114,222,47,75,165,153,126,246,89,14,56,103,213,3,254,21,96,147,109,183,78,83,157,64,204,67,136,38,32,
90,198,12,223,32,153,252,24,63,255,25,254,82,23,206,197,168,113,143,48,10,221,17,212,173,239,224,255,240,14,246,198,91,232,7,167,113,192,144,128,23,152,18,88,25,168,210,101,119,179,199,106,17,88,249,190,
12,110,159,69,200,1,251,226,30,78,137,228,36,232,6,162,154,104,29,161,236,54,170,117,3,55,249,107,220,207,151,144,5,131,76,15,89,27,205,99,116,83,28,159,139,116,238,33,167,255,42,242,218,186,36,87,193,
126,116,9,179,218,38,14,251,57,246,193,8,86,178,92,84,105,93,7,56,239,87,253,54,72,10,173,25,196,5,195,101,0,151,144,232,17,34,38,16,21,145,26,131,181,183,145,209,143,73,231,151,144,133,99,198,206,190,
61,121,210,78,143,180,153,248,247,42,211,94,120,228,82,117,83,185,230,159,27,118,230,86,210,95,184,230,221,253,151,144,79,230,105,36,217,183,183,52,140,9,188,88,185,151,117,29,195,197,189,88,92,128,253,
128,214,180,70,193,37,69,97,161,245,113,172,110,97,244,14,162,183,177,86,35,118,9,215,249,23,254,167,91,74,190,245,139,51,51,246,205,185,57,198,187,61,166,162,6,109,231,120,65,107,94,22,197,89,231,173,
82,106,250,51,163,127,118,199,70,227,224,77,38,86,101,235,90,109,184,116,21,195,101,235,92,148,65,160,203,42,94,2,220,40,251,224,4,209,187,120,213,164,161,52,162,20,202,172,194,216,6,188,214,68,71,115,
47,207,160,151,87,152,254,225,15,216,120,117,150,187,226,185,233,29,95,34,164,105,202,204,72,59,90,55,230,220,67,163,59,193,133,105,232,171,204,162,79,169,67,237,225,220,202,22,85,184,78,213,247,219,231,
129,213,40,0,205,3,14,237,113,170,1,58,198,40,133,86,10,116,15,25,222,129,241,55,231,102,245,238,242,10,201,253,101,238,172,60,192,165,49,45,160,139,160,16,78,104,67,99,55,81,59,34,157,237,134,25,38,118,
193,87,55,20,88,152,90,129,149,193,161,229,64,163,85,197,250,33,44,184,9,99,217,28,44,160,60,168,77,156,0,106,11,212,56,178,23,44,125,241,249,61,122,39,78,114,188,31,51,130,163,131,208,66,179,6,60,66,
179,226,29,169,247,7,136,173,170,25,126,170,85,49,92,101,180,246,51,102,165,173,99,10,96,195,2,27,0,214,17,60,34,160,165,13,219,195,176,190,41,126,108,245,113,215,156,34,226,69,60,103,177,180,180,166,
55,209,97,121,109,141,86,20,209,247,169,31,181,186,219,214,102,11,68,192,121,136,4,118,97,101,138,42,138,117,85,230,115,144,200,106,16,232,26,192,85,25,23,9,70,197,36,226,81,34,224,38,161,123,12,189,152,
8,233,63,227,62,119,233,35,104,90,205,6,116,142,51,172,35,38,134,134,88,106,68,220,53,42,153,208,102,233,5,212,70,22,94,34,176,35,160,107,125,113,173,74,87,49,92,229,162,170,64,231,215,1,113,59,128,218,
192,241,24,228,17,86,118,240,206,99,211,111,103,17,212,181,158,200,171,55,53,51,78,171,8,159,176,30,167,76,157,234,96,197,243,43,11,159,58,151,142,89,115,255,13,81,215,206,196,201,26,164,41,104,151,49,
221,19,56,87,105,169,109,85,78,154,131,216,15,112,85,191,248,94,233,219,229,148,80,20,70,186,32,61,156,108,130,115,232,244,44,126,243,93,236,223,215,37,185,122,71,252,194,162,82,211,247,34,19,253,5,165,
198,147,29,212,230,142,252,201,197,73,39,178,247,207,139,254,232,109,207,245,215,227,248,49,216,20,250,14,70,61,196,181,110,201,86,229,165,121,104,89,21,77,149,65,214,221,151,24,246,165,12,41,60,116,172,
131,127,8,190,71,164,251,36,73,11,244,91,232,7,96,127,123,205,187,255,220,50,234,39,235,138,11,55,69,78,236,174,173,201,49,107,187,51,198,220,122,195,201,31,127,44,234,111,223,223,142,191,26,38,138,3,
195,158,204,8,202,160,88,250,80,12,15,2,93,102,187,208,92,85,90,216,5,223,198,242,21,169,236,160,211,45,140,86,136,58,141,145,75,176,250,18,250,147,59,74,255,227,161,210,153,235,1,134,181,221,62,5,221,
51,113,178,246,122,188,251,120,24,19,131,244,97,55,133,73,15,15,228,32,21,15,41,3,174,99,184,14,112,21,219,133,150,214,228,194,178,76,234,59,77,228,118,60,228,103,241,2,41,19,24,223,38,117,243,152,100,
62,245,143,73,253,151,153,159,5,136,37,51,80,62,205,212,216,133,107,219,101,86,250,156,40,22,7,38,15,229,98,27,215,175,95,103,105,105,233,153,36,161,124,61,68,44,189,1,244,67,46,92,6,77,43,70,110,209,
149,243,140,200,247,64,192,251,76,61,243,184,219,235,39,5,0,17,72,124,102,160,250,33,97,232,249,44,23,190,32,138,79,101,191,138,135,45,4,6,247,129,227,95,115,181,163,7,188,3,108,5,217,14,18,135,5,72,1,
247,1,120,38,225,253,7,69,139,222,212,89,108,220,87,79,215,206,242,138,80,236,179,68,97,67,56,143,112,123,112,181,35,255,176,41,200,123,192,135,192,216,215,8,248,67,224,119,1,228,78,144,221,26,198,145,
39,238,68,193,88,72,4,188,202,114,15,194,95,117,112,61,79,52,83,29,176,32,168,10,17,80,14,122,50,212,160,242,204,166,24,248,71,85,33,98,97,224,60,185,207,247,236,34,176,22,102,89,148,126,144,34,88,127,
20,37,91,85,152,120,14,186,12,178,89,186,218,138,170,163,148,220,79,26,216,235,23,36,46,92,147,2,187,254,89,119,245,205,214,165,139,1,65,113,194,69,214,114,198,250,229,140,167,2,112,25,116,89,210,10,159,
124,228,133,120,41,168,148,43,21,219,138,0,108,65,19,202,113,113,113,242,69,191,155,86,72,153,89,158,7,224,50,163,101,176,166,164,254,170,34,211,146,210,94,118,229,58,86,161,255,76,168,121,212,71,45,82,
50,28,161,14,134,171,1,58,8,112,25,184,47,29,183,120,158,211,81,75,221,89,145,42,149,111,15,122,160,54,232,32,109,208,185,146,28,53,224,131,156,32,242,63,158,30,242,255,114,114,88,7,114,63,45,56,104,81,
165,238,156,248,185,158,15,255,23,242,251,166,249,231,151,7,67,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* AutoCompressorAudioProcessorEditor::bt_on_png = (const char*) resource_AutoCompressorAudioProcessorEditor_bt_on_png;
const int AutoCompressorAudioProcessorEditor::bt_on_pngSize = 2017;

// JUCER_RESOURCE: bt_off2_png, 1627, "BinaryData/bt_off2.png"
static const unsigned char resource_AutoCompressorAudioProcessorEditor_bt_off2_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,60,0,0,0,33,8,6,0,0,0,133,180,200,55,0,0,0,6,98,75,71,68,0,
255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,222,2,23,23,21,44,79,234,212,187,0,0,5,232,73,68,65,84,88,195,197,153,93,107,21,71,24,199,
127,207,156,217,115,146,172,53,137,137,177,4,106,95,20,223,46,108,43,10,165,160,208,175,80,180,244,174,20,244,27,20,250,13,10,133,66,191,64,160,119,10,45,165,119,189,18,161,74,123,211,55,232,93,65,41,
10,198,24,141,39,39,39,231,109,119,103,166,23,157,77,39,235,110,114,146,35,199,129,97,103,207,57,217,236,111,254,255,103,94,158,17,118,46,194,238,165,236,55,110,151,191,113,188,164,34,187,124,46,37,117,
63,197,5,215,98,125,169,192,2,124,2,188,81,2,185,31,224,7,192,245,0,206,6,213,5,87,247,178,212,254,186,66,133,81,234,143,192,17,96,30,152,5,14,2,83,64,3,208,128,26,193,57,35,41,44,190,199,57,127,254,60,
179,179,179,207,251,210,185,61,221,223,186,117,43,111,126,0,220,7,50,32,241,53,245,247,25,96,198,21,219,186,12,126,122,122,154,249,249,249,109,16,33,204,78,160,101,191,7,206,0,27,192,0,232,7,149,130,189,
25,23,240,182,248,204,178,140,52,77,95,4,104,94,102,188,165,187,64,7,168,5,176,166,2,86,128,9,31,2,211,62,12,240,207,104,249,14,236,239,213,21,161,194,42,111,44,46,46,114,244,232,81,68,100,11,34,172,214,
218,231,174,121,59,188,15,202,28,240,42,208,246,177,171,252,139,102,222,218,198,223,231,214,174,121,200,247,129,203,192,57,17,89,240,223,173,138,200,31,34,242,189,49,230,103,15,111,246,2,252,220,148,115,
229,202,21,46,93,186,132,82,10,17,193,57,135,49,6,99,12,105,154,110,57,160,88,147,36,217,118,191,180,180,20,42,60,23,116,112,30,203,185,181,85,240,210,226,97,63,6,174,137,82,39,34,221,104,68,19,177,114,
8,38,237,31,206,146,238,49,17,121,39,138,162,165,52,77,175,3,205,97,149,46,141,97,107,45,89,150,161,148,218,166,176,49,6,107,237,214,181,88,139,78,8,202,43,30,218,121,69,123,94,233,200,171,25,118,248,
132,87,246,90,84,175,159,62,124,228,104,99,118,110,145,167,107,107,56,28,105,146,136,181,217,84,175,245,232,180,115,246,106,163,209,184,63,24,12,110,250,103,238,90,84,0,187,101,105,99,204,150,138,89,150,
109,107,231,74,23,161,203,44,30,148,73,32,246,113,56,81,128,85,5,224,131,192,101,17,57,241,218,235,39,27,167,206,188,141,195,17,199,7,112,214,17,213,235,40,165,153,154,89,172,139,200,9,231,220,71,113,
28,79,15,107,105,85,246,97,14,92,132,206,235,48,208,5,133,235,30,178,225,219,186,2,22,111,231,115,74,169,250,91,199,79,209,110,111,114,225,220,89,78,28,127,147,118,235,9,253,94,135,52,233,145,12,122,76,
198,7,235,34,242,174,82,106,102,63,131,214,54,224,52,77,17,145,173,24,206,97,66,216,16,186,204,230,133,255,19,249,107,14,91,171,88,116,76,137,200,194,161,185,249,90,171,213,230,225,242,35,86,30,175,98,
140,193,89,67,210,223,68,68,49,49,53,141,77,219,202,57,183,208,104,52,226,118,187,61,26,112,150,101,91,163,116,30,199,85,192,85,208,5,39,169,0,80,149,44,122,182,149,245,102,211,181,90,45,25,36,3,210,164,
79,58,232,81,211,13,84,173,70,150,254,55,133,91,243,255,56,51,210,194,163,74,225,112,180,30,6,186,240,236,50,251,150,173,207,187,192,170,115,118,174,217,124,170,6,189,46,214,26,68,41,84,77,115,252,248,
73,150,151,31,81,171,213,216,232,172,88,173,245,147,40,138,186,35,89,58,143,213,50,133,243,154,187,96,39,248,138,197,196,110,155,144,150,136,252,233,156,59,214,110,62,172,169,232,128,108,61,203,65,187,
189,201,228,228,20,107,43,247,192,185,36,170,215,255,210,90,183,94,88,12,135,192,161,173,171,160,67,219,239,179,108,88,107,191,211,90,159,181,38,59,173,84,167,94,211,177,40,221,224,208,236,60,131,126,
151,103,171,255,32,66,162,181,190,27,69,209,183,198,152,245,145,129,171,20,46,139,229,42,232,125,150,62,240,139,181,118,73,68,174,102,105,122,178,102,219,117,178,142,234,109,36,116,58,155,86,32,209,53,
125,55,138,162,111,180,214,119,150,151,151,123,47,4,184,184,110,46,179,245,30,45,61,108,178,160,101,173,189,17,69,209,3,231,220,135,192,133,52,77,23,54,54,90,104,173,159,104,173,127,175,215,235,63,120,
216,161,87,89,59,198,112,190,121,200,7,173,170,56,206,87,101,101,208,35,164,120,12,208,28,12,6,55,227,56,254,85,41,53,19,199,113,12,16,69,81,87,107,221,50,198,172,123,101,247,189,121,24,42,134,67,232,
170,88,206,219,37,144,123,201,110,56,160,215,233,116,122,192,202,176,243,236,72,163,116,149,194,101,131,87,17,182,16,18,73,5,240,216,211,59,186,24,59,192,244,176,10,239,22,203,190,164,192,179,138,92,214,
216,179,152,18,44,10,234,192,167,192,23,126,61,251,162,202,111,192,223,126,11,247,12,88,5,86,128,199,192,19,255,89,55,72,251,140,77,97,128,27,192,79,192,123,30,122,214,103,42,14,250,221,78,113,75,87,182,
52,12,83,178,77,15,211,243,233,157,129,7,203,130,76,199,115,182,190,248,249,109,9,54,150,255,181,219,193,70,19,224,30,14,159,18,184,243,229,37,183,87,133,197,131,76,120,176,25,224,16,176,224,51,142,121,
182,113,210,59,161,182,75,182,49,76,203,166,126,110,221,0,214,129,53,175,236,154,87,119,221,127,159,2,217,197,175,110,11,125,132,12,176,8,26,193,6,187,221,200,191,65,134,67,225,232,225,56,12,119,62,27,
14,58,4,214,94,193,73,15,151,67,31,246,106,31,240,29,18,238,99,119,58,121,200,129,51,175,108,219,67,231,214,110,250,49,163,237,129,179,189,164,106,70,177,116,104,65,19,188,96,215,247,101,228,63,219,41,
75,177,211,20,148,167,115,58,192,166,135,238,120,200,36,200,103,185,113,143,210,182,160,72,168,226,192,191,100,84,146,60,151,29,22,21,121,86,50,183,117,158,181,236,4,54,54,37,163,246,216,166,165,252,229,
66,245,140,87,55,204,84,12,123,236,146,63,211,4,131,86,152,151,14,51,150,99,157,135,93,137,34,4,237,94,33,83,49,12,176,45,56,39,173,56,121,176,227,74,194,151,77,75,54,232,0,27,196,180,10,64,213,46,39,
143,85,39,134,38,24,152,76,96,229,177,29,179,84,157,30,74,33,67,81,76,207,200,30,128,139,213,150,156,34,142,117,165,245,47,10,171,58,177,216,236,123,154,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* AutoCompressorAudioProcessorEditor::bt_off2_png = (const char*) resource_AutoCompressorAudioProcessorEditor_bt_off2_png;
const int AutoCompressorAudioProcessorEditor::bt_off2_pngSize = 1627;

// JUCER_RESOURCE: bt_on2_png, 2076, "BinaryData/bt_on2.png"
static const unsigned char resource_AutoCompressorAudioProcessorEditor_bt_on2_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,60,0,0,0,33,8,6,0,0,0,133,180,200,55,0,0,0,6,98,75,71,68,0,255,
0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,222,2,23,23,22,24,69,115,115,205,0,0,7,169,73,68,65,84,88,195,205,153,203,111,27,199,29,199,
63,51,187,75,82,164,36,154,18,229,183,35,91,82,109,199,175,162,104,80,25,237,165,64,17,20,110,145,0,45,234,75,123,200,185,190,248,79,104,143,57,21,232,193,200,161,215,158,234,20,65,15,70,129,54,135,182,
104,108,183,64,210,71,108,57,114,156,214,78,20,69,142,41,145,18,197,199,114,119,230,215,131,150,244,122,181,36,229,192,145,59,192,15,187,203,199,206,124,230,59,143,223,239,55,138,39,139,74,121,86,137,
239,84,159,223,118,139,12,184,74,159,223,238,90,81,67,64,251,217,78,129,7,217,115,1,119,83,64,95,3,142,38,192,6,169,171,82,26,221,189,127,0,252,26,176,209,103,118,8,248,174,0,199,33,126,1,92,126,198,117,
188,2,252,24,48,81,29,54,178,120,231,40,46,71,236,37,20,1,10,131,198,162,17,20,130,34,23,181,83,33,104,4,131,37,68,104,69,157,184,128,112,10,248,165,146,97,67,186,11,172,129,240,75,234,216,175,1,247,163,
247,155,200,30,171,126,254,231,138,249,159,109,129,151,208,52,113,208,104,20,14,130,131,160,208,81,59,157,168,11,124,12,54,234,22,7,67,22,75,53,26,49,3,160,221,20,112,46,93,186,196,220,220,28,34,130,181,
182,103,198,152,212,251,126,223,93,185,114,165,251,202,89,96,57,234,212,32,86,191,237,213,251,225,85,205,185,139,154,6,14,57,92,66,92,44,46,26,23,193,193,162,34,73,4,48,40,66,50,4,24,194,94,203,75,88,
246,13,158,38,169,192,51,51,51,156,59,119,110,27,208,211,90,172,100,128,108,84,199,147,115,248,248,183,53,71,78,9,165,25,141,193,65,225,226,147,193,54,115,84,22,198,88,93,44,209,88,41,18,52,242,0,120,
133,38,249,189,53,38,79,84,41,159,169,227,228,125,4,69,35,162,249,0,203,101,233,171,178,27,131,213,189,73,37,130,49,6,17,233,169,220,189,79,90,234,50,189,253,187,46,48,177,57,108,25,63,10,181,186,161,
81,85,76,76,58,180,43,30,35,101,143,246,114,129,143,111,78,241,225,91,243,60,122,255,2,126,237,69,140,63,129,88,200,140,213,240,70,111,179,247,171,191,231,248,171,55,57,120,254,17,249,67,48,130,96,17,
246,35,172,32,195,22,173,39,20,238,170,26,7,75,62,39,225,134,116,66,23,216,62,49,135,157,80,40,238,213,168,140,194,203,106,60,207,197,54,115,44,221,156,226,95,191,250,33,213,197,139,224,76,187,222,136,
199,225,121,45,100,145,141,255,150,88,127,112,72,150,254,122,82,218,213,171,8,111,50,115,97,5,63,191,53,159,253,104,154,244,81,57,62,164,117,63,224,238,125,218,103,131,44,86,178,145,153,104,225,114,0,
131,31,104,188,81,200,149,21,214,115,16,199,165,178,48,198,226,91,243,84,23,47,58,217,241,153,169,211,47,187,163,147,211,124,108,203,216,177,105,76,115,77,169,135,183,178,153,229,63,29,11,42,183,47,218,
123,215,150,24,61,252,54,71,230,3,32,164,137,166,136,112,32,93,101,221,79,225,248,92,140,119,192,48,208,62,37,3,228,162,171,23,117,180,166,176,71,147,201,105,130,150,134,166,11,218,101,117,177,196,163,
127,127,15,191,241,194,236,183,126,226,206,157,121,137,154,51,129,87,60,128,113,242,232,194,126,100,252,8,102,207,9,87,41,53,237,172,189,255,125,119,253,238,4,22,7,139,131,139,194,0,31,164,55,68,167,41,
156,92,157,227,54,8,58,57,196,19,192,93,115,35,133,53,38,208,4,109,197,72,86,129,86,104,229,208,88,41,226,175,159,84,94,214,59,50,59,199,114,93,243,205,179,211,28,47,172,35,107,247,176,143,110,65,253,
19,66,19,82,152,56,230,57,126,245,69,167,93,41,69,91,152,166,131,194,162,216,159,238,9,186,131,20,142,3,36,161,211,192,251,205,243,72,85,47,2,117,162,206,213,132,86,65,70,19,250,10,173,20,74,105,58,155,
5,194,214,196,236,169,151,244,114,181,205,210,90,192,103,239,222,37,244,13,56,57,240,107,128,66,231,39,241,235,25,37,65,171,148,49,205,130,223,221,171,51,40,28,224,31,195,93,203,129,139,86,154,234,79,
177,130,59,81,93,110,15,22,20,98,21,173,250,150,195,17,52,20,217,137,222,159,238,223,191,207,228,11,155,116,216,3,222,40,140,150,192,203,65,107,21,218,107,216,141,207,176,38,68,169,47,238,90,50,72,225,
180,69,107,216,98,150,152,58,78,12,118,171,131,187,122,183,171,96,236,150,7,229,229,155,120,133,170,248,245,226,70,101,197,97,223,62,40,28,132,169,19,104,47,71,217,217,100,245,243,101,60,47,135,253,168,
99,221,220,88,77,103,243,13,36,114,55,61,4,63,242,237,126,51,120,14,147,84,120,144,103,53,8,186,15,112,90,196,5,42,80,180,125,1,43,136,24,70,166,106,100,199,239,136,13,66,127,229,159,80,185,7,74,200,102,
114,148,114,160,115,5,70,198,202,100,214,23,113,54,238,5,58,95,94,164,176,127,29,7,3,8,173,200,215,238,179,23,247,29,210,105,10,167,109,81,105,208,221,235,0,191,125,235,185,181,14,173,13,33,88,19,58,45,
3,54,100,242,43,85,202,103,174,73,103,243,184,94,187,117,76,139,241,44,224,55,170,236,59,116,0,209,46,238,223,223,192,60,248,75,232,230,138,75,82,62,123,205,31,155,93,37,36,68,99,16,132,77,132,147,195,
231,176,36,21,30,6,156,118,31,255,93,226,221,201,144,80,208,74,240,107,130,191,41,248,117,131,54,33,19,39,234,156,248,193,223,164,93,189,42,213,187,23,213,218,157,105,175,254,192,227,211,63,171,224,227,
9,234,161,18,243,209,31,3,111,164,180,36,19,167,222,180,71,95,190,238,23,79,111,224,18,210,193,48,138,197,239,191,45,185,105,113,105,215,181,76,243,166,146,144,253,158,19,10,219,68,132,36,189,79,27,85,
75,189,98,9,55,53,237,78,128,147,211,28,60,255,8,225,183,246,222,181,79,157,181,219,223,85,157,234,25,169,220,154,92,125,216,22,55,55,94,115,138,199,110,155,242,217,63,200,209,239,188,211,156,250,198,
67,242,5,63,82,216,98,163,247,15,240,165,159,74,225,65,208,73,181,99,197,164,134,133,126,205,146,203,67,243,161,96,91,33,182,161,113,148,162,120,72,200,94,88,97,252,240,219,170,122,247,61,213,174,148,
50,166,89,0,208,185,66,147,252,190,154,63,54,187,234,23,79,111,144,43,248,8,29,218,132,148,177,84,118,22,45,73,18,184,159,194,253,128,211,212,142,149,176,79,44,44,172,47,91,76,73,104,46,88,130,153,173,
54,56,101,139,155,55,28,154,15,194,3,243,27,161,226,19,95,162,249,47,8,78,20,254,107,66,12,33,46,33,121,12,6,203,73,132,159,14,142,135,147,201,54,174,95,191,206,226,226,226,182,32,33,121,125,10,95,122,
29,232,68,177,112,18,26,242,57,225,63,183,133,241,83,194,220,215,5,139,69,99,123,126,183,141,210,1,93,224,0,139,198,208,137,18,0,155,88,74,88,206,32,252,72,61,149,194,53,96,207,141,27,55,158,101,182,99,
19,88,0,252,8,58,220,166,242,231,239,10,51,175,8,239,45,192,193,94,91,44,89,116,180,24,41,76,44,119,166,144,30,120,17,193,71,120,7,161,186,179,172,165,19,179,215,128,215,129,226,51,4,126,29,248,29,208,
4,90,145,181,251,40,14,111,72,119,133,85,20,163,64,192,162,122,209,180,15,232,104,235,137,143,204,33,185,172,36,176,142,65,79,69,126,74,55,178,137,59,254,94,170,139,248,184,226,110,112,223,157,179,119,
128,213,8,48,110,157,200,226,176,118,55,82,182,42,214,240,46,116,18,50,155,184,186,79,68,60,143,211,54,241,237,39,140,212,235,196,204,143,93,131,152,186,118,219,118,245,37,167,105,227,14,65,188,193,113,
213,186,138,117,182,69,60,219,129,147,208,73,11,83,246,228,93,79,196,75,108,72,153,68,178,45,14,224,198,70,66,210,47,142,55,62,190,239,134,41,150,84,150,231,1,156,84,52,9,235,36,134,191,74,137,180,36,
49,151,205,182,60,214,227,251,237,174,230,46,31,181,72,98,225,144,8,200,244,1,29,4,156,4,183,137,227,22,203,115,58,106,233,119,86,164,18,233,219,157,30,168,13,58,72,27,116,174,36,187,13,188,147,19,68,
190,224,233,33,255,47,39,135,253,32,135,141,130,157,38,85,250,157,19,63,215,243,225,255,1,201,72,177,114,177,120,80,223,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* AutoCompressorAudioProcessorEditor::bt_on2_png = (const char*) resource_AutoCompressorAudioProcessorEditor_bt_on2_png;
const int AutoCompressorAudioProcessorEditor::bt_on2_pngSize = 2076;


//[EndFile] You can add extra defines here...
//[/EndFile]
