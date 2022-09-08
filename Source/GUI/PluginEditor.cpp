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

    depth->setBounds (40, 48, 104, 120);

    drywet.reset (new juce::Slider ("Dry / Wet"));
    addAndMakeVisible (drywet.get());
    drywet->setRange (0, 10, 0);
    drywet->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    drywet->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);

    drywet->setBounds (448, 144, 104, 120);

    rate.reset (new juce::Slider ("Rate"));
    addAndMakeVisible (rate.get());
    rate->setRange (0, 10, 0);
    rate->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    rate->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    rate->addListener (this);

    rate->setBounds (40, 240, 104, 120);

    delayTime.reset (new juce::Slider ("Delay Time"));
    addAndMakeVisible (delayTime.get());
    delayTime->setRange (0, 10, 0);
    delayTime->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    delayTime->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    delayTime->addListener (this);

    delayTime->setBounds (240, 144, 104, 120);


    //[UserPreSize]
    depth_attachment.reset(new SliderAttachment(valueTreeState, NAME_MOD, *depth));
    drywet_attachment.reset(new SliderAttachment(valueTreeState, NAME_DW, *drywet));
    rate_attachment.reset(new SliderAttachment(valueTreeState, NAME_FREQ, *rate));
    delayTime_attachment.reset(new SliderAttachment(valueTreeState, NAME_DT, *delayTime));

    depth->setLookAndFeel(&myLookAndFeel);
    drywet->setLookAndFeel(&myLookAndFeel);
    rate->setLookAndFeel(&myLookAndFeel);
    delayTime->setLookAndFeel(&myLookAndFeel);

    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

PluginEditor::~PluginEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    depth_attachment.reset();
    drywet_attachment.reset();
    rate_attachment.reset();
    delayTime_attachment.reset();

    depth->setLookAndFeel(nullptr);
    drywet->setLookAndFeel(nullptr);
    rate->setLookAndFeel(nullptr);
    delayTime->setLookAndFeel(nullptr);
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
        int x = 0, y = 0, width = 194, height = 400;
        juce::Colour fillColour1 = juce::Colour (0xffce9c00), fillColour2 = juce::Colour (0xff00113e);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (juce::ColourGradient (fillColour1,
                                             96.0f - 0.0f + x,
                                             static_cast<float> (-120) - 0.0f + y,
                                             fillColour2,
                                             88.0f - 0.0f + x,
                                             352.0f - 0.0f + y,
                                             false));
        g.fillRect (x, y, width, height);
    }

    {
        int x = 192, y = 0, width = 200, height = 400;
        juce::Colour fillColour1 = juce::Colour (0xffe25200), fillColour2 = juce::Colour (0xff00113e);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (juce::ColourGradient (fillColour1,
                                             296.0f - 192.0f + x,
                                             static_cast<float> (-168) - 0.0f + y,
                                             fillColour2,
                                             304.0f - 192.0f + x,
                                             360.0f - 0.0f + y,
                                             false));
        g.fillRect (x, y, width, height);
    }

    {
        int x = 392, y = -8, width = 216, height = 408;
        juce::Colour fillColour1 = juce::Colour (0xff890404), fillColour2 = juce::Colour (0xff00113e);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (juce::ColourGradient (fillColour1,
                                             496.0f - 392.0f + x,
                                             static_cast<float> (-64) - static_cast<float> (-8) + y,
                                             fillColour2,
                                             472.0f - 392.0f + x,
                                             360.0f - static_cast<float> (-8) + y,
                                             false));
        g.fillRect (x, y, width, height);
    }

    {
        int x = 397, y = 119, width = 200, height = 30;
        juce::String text (TRANS("Dry / Wet"));
        juce::Colour fillColour = juce::Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (18.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 189, y = 119, width = 200, height = 30;
        juce::String text (TRANS("Delay Time"));
        juce::Colour fillColour = juce::Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (18.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = -11, y = 23, width = 200, height = 30;
        juce::String text (TRANS("Depth"));
        juce::Colour fillColour = juce::Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (18.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = -11, y = 215, width = 200, height = 30;
        juce::String text (TRANS("Rate"));
        juce::Colour fillColour = juce::Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (18.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 293, y = 359, width = 328, height = 33;
        juce::String text (TRANS("Chorus RDL"));
        juce::Colour fillColour = juce::Colour (0xff25099d);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Book Antiqua", 60.00f, juce::Font::plain).withTypefaceStyle ("Bold Italic"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
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
                 fixedSize="1" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff">
    <RECT pos="0 0 194 400" fill="linear: 96 -120, 88 352, 0=ffce9c00, 1=ff00113e"
          hasStroke="0"/>
    <RECT pos="192 0 200 400" fill="linear: 296 -168, 304 360, 0=ffe25200, 1=ff00113e"
          hasStroke="0"/>
    <RECT pos="392 -8 216 408" fill="linear: 496 -64, 472 360, 0=ff890404, 1=ff00113e"
          hasStroke="0"/>
    <TEXT pos="397 119 200 30" fill="solid: ff000000" hasStroke="0" text="Dry / Wet"
          fontname="Default font" fontsize="18.0" kerning="0.0" bold="1"
          italic="0" justification="36" typefaceStyle="Bold"/>
    <TEXT pos="189 119 200 30" fill="solid: ff000000" hasStroke="0" text="Delay Time"
          fontname="Default font" fontsize="18.0" kerning="0.0" bold="1"
          italic="0" justification="36" typefaceStyle="Bold"/>
    <TEXT pos="-11 23 200 30" fill="solid: ff000000" hasStroke="0" text="Depth"
          fontname="Default font" fontsize="18.0" kerning="0.0" bold="1"
          italic="0" justification="36" typefaceStyle="Bold"/>
    <TEXT pos="-11 215 200 30" fill="solid: ff000000" hasStroke="0" text="Rate"
          fontname="Default font" fontsize="18.0" kerning="0.0" bold="1"
          italic="0" justification="36" typefaceStyle="Bold"/>
    <TEXT pos="293 359 328 33" fill="solid: ff25099d" hasStroke="0" text="Chorus RDL"
          fontname="Book Antiqua" fontsize="60.0" kerning="0.0" bold="1"
          italic="1" justification="36" typefaceStyle="Bold Italic"/>
  </BACKGROUND>
  <SLIDER name="Depth" id="f05ee267c1b07946" memberName="depth" virtualName=""
          explicitFocusOrder="0" pos="40 48 104 120" min="0.0" max="10.0"
          int="0.0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="Dry / Wet" id="767ca0bf8fccbdc6" memberName="drywet" virtualName=""
          explicitFocusOrder="0" pos="448 144 104 120" min="0.0" max="10.0"
          int="0.0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="Rate" id="e32b3ec20dccaa69" memberName="rate" virtualName=""
          explicitFocusOrder="0" pos="40 240 104 120" min="0.0" max="10.0"
          int="0.0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="Delay Time" id="7ca3599c485e4cde" memberName="delayTime"
          virtualName="" explicitFocusOrder="0" pos="240 144 104 120" min="0.0"
          max="10.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

