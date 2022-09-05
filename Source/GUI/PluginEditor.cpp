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
# include "Parameters.h"
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PluginEditor::PluginEditor (DelayFXAudioProcessor& p, AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), processor (p), valueTreeState (vts)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    timeSlider.reset (new juce::Slider ("Delay Time (s)"));
    addAndMakeVisible (timeSlider.get());
    timeSlider->setRange (0, 10, 0);
    timeSlider->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    timeSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);

    timeSlider->setBounds (56, 72, 112, 120);

    fbSlider.reset (new juce::Slider ("Feedback"));
    addAndMakeVisible (fbSlider.get());
    fbSlider->setRange (0, 10, 0);
    fbSlider->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    fbSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);

    fbSlider->setBounds (248, 72, 112, 120);

    dwSlider.reset (new juce::Slider ("Dry/Wet"));
    addAndMakeVisible (dwSlider.get());
    dwSlider->setRange (0, 10, 0);
    dwSlider->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    dwSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);

    dwSlider->setBounds (432, 72, 112, 120);

    rateSlider.reset (new juce::Slider ("Mod freq. (Hz)"));
    addAndMakeVisible (rateSlider.get());
    rateSlider->setRange (0, 10, 0);
    rateSlider->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    rateSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);

    rateSlider->setBounds (61, 256, 99, 109);

    amtSlider.reset (new juce::Slider ("Mod amount (s)"));
    addAndMakeVisible (amtSlider.get());
    amtSlider->setRange (0, 10, 0);
    amtSlider->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    amtSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);

    amtSlider->setBounds (253, 256, 99, 109);

    wfSlider.reset (new juce::Slider ("Mod shape"));
    addAndMakeVisible (wfSlider.get());
    wfSlider->setRange (0, 10, 0);
    wfSlider->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    wfSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);

    wfSlider->setBounds (440, 256, 99, 109);

    internalPath1.startNewSubPath (0.0f, 400.0f);
    internalPath1.lineTo (0.0f, 0.0f);
    internalPath1.lineTo (600.0f, 0.0f);
    internalPath1.lineTo (600.0f, 400.0f);
    internalPath1.closeSubPath();


    //[UserPreSize]
    timeAttachment.reset(new SliderAttachment(valueTreeState, NAME_DT, *timeSlider));
    fbAttachment.reset(new SliderAttachment(valueTreeState, NAME_FB, *fbSlider));
    dwAttachment.reset(new SliderAttachment(valueTreeState, NAME_DW, *dwSlider));
    rateAttachment.reset(new SliderAttachment(valueTreeState, NAME_FREQ, *rateSlider));
    amtAttachment.reset(new SliderAttachment(valueTreeState, NAME_MOD, *amtSlider));
    wfAttachment.reset(new SliderAttachment(valueTreeState, NAME_WF, *wfSlider));

    //dwSlider->setLookAndFeel(&temaBellissimo);
    this->setLookAndFeel(&temaBellissimo);

    temaBellissimo_con_4_tick.setNumTicks(4);
    wfSlider->setLookAndFeel(&temaBellissimo_con_4_tick);

    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

PluginEditor::~PluginEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    timeAttachment.reset();
    fbAttachment.reset();
    dwAttachment.reset();
    rateAttachment.reset();
    amtAttachment.reset();
    wfAttachment.reset();

    this->setLookAndFeel(nullptr);
    //[/Destructor_pre]

    timeSlider = nullptr;
    fbSlider = nullptr;
    dwSlider = nullptr;
    rateSlider = nullptr;
    amtSlider = nullptr;
    wfSlider = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PluginEditor::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    {
        float x = 0, y = 0;
        juce::Colour fillColour1 = juce::Colour (0xff26262a), fillColour2 = juce::Colour (0xff212026);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (juce::ColourGradient (fillColour1,
                                             264.0f - 0.0f + x,
                                             24.0f - 0.0f + y,
                                             fillColour2,
                                             288.0f - 0.0f + x,
                                             384.0f - 0.0f + y,
                                             false));
        g.fillPath (internalPath1, juce::AffineTransform::translation(x, y));
    }

    {
        int x = 64, y = 34, width = 104, height = 30;
        juce::String text (TRANS("Delay time"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 248, y = 34, width = 104, height = 30;
        juce::String text (TRANS("Feedback"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 432, y = 34, width = 104, height = 30;
        juce::String text (TRANS("Dry / Wet"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 56, y = 218, width = 104, height = 30;
        juce::String text (TRANS("Mod freq."));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 248, y = 218, width = 104, height = 30;
        juce::String text (TRANS("Mod amount"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 440, y = 218, width = 104, height = 30;
        juce::String text (TRANS("Mod shape"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
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



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PluginEditor" componentName=""
                 parentClasses="public juce::AudioProcessorEditor" constructorParams="DelayFXAudioProcessor&amp; p, AudioProcessorValueTreeState&amp; vts"
                 variableInitialisers="AudioProcessorEditor (&amp;p), processor (p), valueTreeState (vts)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44">
    <PATH pos="0 0 100 100" fill="linear: 264 24, 288 384, 0=ff26262a, 1=ff212026"
          hasStroke="0" nonZeroWinding="1">s 0 400 l 0 0 l 600 0 l 600 400 x</PATH>
    <TEXT pos="64 34 104 30" fill="solid: ffffffff" hasStroke="0" text="Delay time"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="248 34 104 30" fill="solid: ffffffff" hasStroke="0" text="Feedback"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="432 34 104 30" fill="solid: ffffffff" hasStroke="0" text="Dry / Wet"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="56 218 104 30" fill="solid: ffffffff" hasStroke="0" text="Mod freq."
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="248 218 104 30" fill="solid: ffffffff" hasStroke="0" text="Mod amount"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="440 218 104 30" fill="solid: ffffffff" hasStroke="0" text="Mod shape"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
  </BACKGROUND>
  <SLIDER name="Delay Time (s)" id="cc736db3b544a332" memberName="timeSlider"
          virtualName="" explicitFocusOrder="0" pos="56 72 112 120" min="0.0"
          max="10.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="Feedback" id="59032ff359869ccb" memberName="fbSlider" virtualName=""
          explicitFocusOrder="0" pos="248 72 112 120" min="0.0" max="10.0"
          int="0.0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="Dry/Wet" id="a0b2390addcbc82e" memberName="dwSlider" virtualName=""
          explicitFocusOrder="0" pos="432 72 112 120" min="0.0" max="10.0"
          int="0.0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="Mod freq. (Hz)" id="b5d241807fb34503" memberName="rateSlider"
          virtualName="" explicitFocusOrder="0" pos="61 256 99 109" min="0.0"
          max="10.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="Mod amount (s)" id="dc850824bdf0b9b7" memberName="amtSlider"
          virtualName="" explicitFocusOrder="0" pos="253 256 99 109" min="0.0"
          max="10.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="Mod shape" id="af64f4447a327b0" memberName="wfSlider" virtualName=""
          explicitFocusOrder="0" pos="440 256 99 109" min="0.0" max="10.0"
          int="0.0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

