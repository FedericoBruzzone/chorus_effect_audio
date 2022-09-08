/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 6.1.6

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
#include "../Parameters.h"
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PluginEditor::PluginEditor (Chorus_effectAudioProcessor& p, AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), processor (p), valueTreeState (vts)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    depth.reset (new juce::Slider ("Depth"));
    addAndMakeVisible (depth.get());
    depth->setRange (0, 10, 0);
    depth->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    depth->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    depth->addListener (this);

    depth->setBounds (32, 24, 72, 80);

    drywet.reset (new juce::Slider ("Dry / Wet"));
    addAndMakeVisible (drywet.get());
    drywet->setRange (0, 10, 0);
    drywet->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    drywet->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);

    drywet->setBounds (352, 88, 72, 80);

    rate.reset (new juce::Slider ("Rate"));
    addAndMakeVisible (rate.get());
    rate->setRange (0, 10, 0);
    rate->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    rate->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    rate->addListener (this);

    rate->setBounds (32, 128, 72, 80);

    delayTime.reset (new juce::Slider ("Delay Time"));
    addAndMakeVisible (delayTime.get());
    delayTime->setRange (0, 10, 0);
    delayTime->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    delayTime->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    delayTime->addListener (this);

    delayTime->setBounds (184, 80, 72, 80);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

PluginEditor::~PluginEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    depth = nullptr;
    drywet = nullptr;
    rate = nullptr;
    delayTime = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PluginEditor::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colours::white);

    {
        int x = -116, y = -308, width = 244, height = 556;
        juce::Colour fillColour = juce::Colour (0xff1598b2);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 132, y = 4, width = 104, height = 188;
        juce::Colour fillColour = juce::Colour (0xff1568f2);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 308, y = 12, width = 128, height = 204;
        juce::Colour fillColour = juce::Colour (0xff00508c);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PluginEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PluginEditor::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == depth.get())
    {
        //[UserSliderCode_depth] -- add your slider handling code here..
        //[/UserSliderCode_depth]
    }
    else if (sliderThatWasMoved == rate.get())
    {
        //[UserSliderCode_rate] -- add your slider handling code here..
        //[/UserSliderCode_rate]
    }
    else if (sliderThatWasMoved == delayTime.get())
    {
        //[UserSliderCode_delayTime] -- add your slider handling code here..
        //[/UserSliderCode_delayTime]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PluginEditor" componentName=""
                 parentClasses="public juce::AudioProcessorEditor" constructorParams="Chorus_effectAudioProcessor&amp; p, AudioProcessorValueTreeState&amp; vts"
                 variableInitialisers="AudioProcessorEditor (&amp;p), processor (p), valueTreeState (vts)&#10;"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff">
    <RECT pos="-116 -308 244 556" fill="solid: ff1598b2" hasStroke="0"/>
    <RECT pos="132 4 104 188" fill="solid: ff1568f2" hasStroke="0"/>
    <RECT pos="308 12 128 204" fill="solid: ff00508c" hasStroke="0"/>
  </BACKGROUND>
  <SLIDER name="Depth" id="f05ee267c1b07946" memberName="depth" virtualName=""
          explicitFocusOrder="0" pos="32 24 72 80" min="0.0" max="10.0"
          int="0.0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="Dry / Wet" id="767ca0bf8fccbdc6" memberName="drywet" virtualName=""
          explicitFocusOrder="0" pos="352 88 72 80" min="0.0" max="10.0"
          int="0.0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="Rate" id="e32b3ec20dccaa69" memberName="rate" virtualName=""
          explicitFocusOrder="0" pos="32 128 72 80" min="0.0" max="10.0"
          int="0.0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="Delay Time" id="7ca3599c485e4cde" memberName="delayTime"
          virtualName="" explicitFocusOrder="0" pos="184 80 72 80" min="0.0"
          max="10.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

