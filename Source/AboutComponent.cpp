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
//[/Headers]

#include "AboutComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
AboutComponent::AboutComponent ()
{
    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("Intelligent dynamic range compression")));
    label->setFont (Font (22.00f, Font::plain));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (Label::textColourId, Colours::white);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("Algorithm:")));
    label2->setFont (Font (14.00f, Font::plain));
    label2->setJustificationType (Justification::centredRight);
    label2->setEditable (false, false, false);
    label2->setColour (Label::textColourId, Colours::white);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label4 = new Label ("new label",
                                           TRANS("Dimitrios Giannoulis, Michael Massberg, Jacob Maddams, Saoirse Finn, Joshua D. Reiss")));
    label4->setFont (Font (14.00f, Font::plain));
    label4->setJustificationType (Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (Label::textColourId, Colours::white);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (githubLink = new HyperlinkButton (TRANS("https://github.com/ptrv/auto_compressor"),
                                                         URL ("http://www.juce.com")));
    githubLink->setTooltip (TRANS("http://www.juce.com"));
    githubLink->setButtonText (TRANS("https://github.com/ptrv/auto_compressor"));
    githubLink->setColour (HyperlinkButton::textColourId, Colour (0xccffffff));

    addAndMakeVisible (versionLabel = new Label ("versionLabel",
                                                 TRANS("Version:")));
    versionLabel->setFont (Font (15.00f, Font::plain));
    versionLabel->setJustificationType (Justification::centred);
    versionLabel->setEditable (false, false, false);
    versionLabel->setColour (Label::textColourId, Colours::white);
    versionLabel->setColour (TextEditor::textColourId, Colours::black);
    versionLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    String versionText = String("Version: ") + String(ProjectInfo::versionString);
    String buildDate = " (Build: " + String(__DATE__) + " " + String(__TIME__) + ")";
    versionLabel->setText(versionText + buildDate, dontSendNotification);
    //[/UserPreSize]

    setSize (400, 200);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

AboutComponent::~AboutComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    label = nullptr;
    label2 = nullptr;
    label4 = nullptr;
    githubLink = nullptr;
    versionLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void AboutComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::black);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void AboutComponent::resized()
{
    label->setBounds (8, 16, 384, 32);
    label2->setBounds (8, 72, 96, 24);
    label4->setBounds (104, 64, 288, 40);
    githubLink->setBounds (8, 128, 384, 24);
    versionLabel->setBounds (8, 168, 384, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="AboutComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="400" initialHeight="200">
  <BACKGROUND backgroundColour="ff000000"/>
  <LABEL name="new label" id="a09546e26a85705b" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="8 16 384 32" textCol="ffffffff" edTextCol="ff000000"
         edBkgCol="0" labelText="Intelligent dynamic range compression"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="22" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="3c5571406df92a9" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="8 72 96 24" textCol="ffffffff" edTextCol="ff000000"
         edBkgCol="0" labelText="Algorithm:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="14"
         bold="0" italic="0" justification="34"/>
  <LABEL name="new label" id="e034cd879cbfa610" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="104 64 288 40" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Dimitrios Giannoulis, Michael Massberg, Jacob Maddams, Saoirse Finn, Joshua D. Reiss"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="14" bold="0" italic="0" justification="33"/>
  <HYPERLINKBUTTON name="githubLink" id="a97bde346e8147bb" memberName="githubLink"
                   virtualName="" explicitFocusOrder="0" pos="8 128 384 24" tooltip="http://www.juce.com"
                   textCol="ccffffff" buttonText="https://github.com/ptrv/auto_compressor"
                   connectedEdges="0" needsCallback="0" radioGroupId="0" url="http://www.juce.com"/>
  <LABEL name="versionLabel" id="35ce77a7e38b4b75" memberName="versionLabel"
         virtualName="" explicitFocusOrder="0" pos="8 168 384 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Version:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
