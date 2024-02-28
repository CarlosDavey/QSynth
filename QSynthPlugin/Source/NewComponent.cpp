/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 6.0.7

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "NewComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
NewComponent::NewComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    juce__slider.reset (new juce::Slider ("wetDrySlider"));
    addAndMakeVisible (juce__slider.get());
    juce__slider->setRange (0, 1, 0);
    juce__slider->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    juce__slider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    juce__slider->addListener (this);

    juce__slider->setBounds (282, 287, 84, 84);

    juce__slider2.reset (new juce::Slider ("gainSlider"));
    addAndMakeVisible (juce__slider2.get());
    juce__slider2->setRange (0, 1, 0);
    juce__slider2->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    juce__slider2->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    juce__slider2->addListener (this);

    juce__slider2->setBounds (374, 287, 72, 84);

    juce__label.reset (new juce::Label ("wetDryLabel",
                                        TRANS("label text")));
    addAndMakeVisible (juce__label.get());
    juce__label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label->setJustificationType (juce::Justification::centred);
    juce__label->setEditable (false, false, false);
    juce__label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label->setBounds (288, 276, 74, 12);

    juce__label3.reset (new juce::Label ("gainLabel",
                                         TRANS("label text")));
    addAndMakeVisible (juce__label3.get());
    juce__label3->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label3->setJustificationType (juce::Justification::centred);
    juce__label3->setEditable (false, false, false);
    juce__label3->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label3->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label3->setBounds (372, 276, 74, 12);

    juce__slider3.reset (new juce::Slider ("releaseSlider"));
    addAndMakeVisible (juce__slider3.get());
    juce__slider3->setRange (0, 10, 0);
    juce__slider3->setSliderStyle (juce::Slider::LinearVertical);
    juce__slider3->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    juce__slider3->addListener (this);

    juce__slider3->setBounds (20, 121, 77, 252);

    juce__label2.reset (new juce::Label ("releaseLabel",
                                         TRANS("label text")));
    addAndMakeVisible (juce__label2.get());
    juce__label2->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label2->setJustificationType (juce::Justification::centredLeft);
    juce__label2->setEditable (false, false, false);
    juce__label2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label2->setBounds (24, 96, 72, 24);

    juce__slider4.reset (new juce::Slider ("waveSpeedSlider"));
    addAndMakeVisible (juce__slider4.get());
    juce__slider4->setRange (0, 10, 0);
    juce__slider4->setSliderStyle (juce::Slider::LinearHorizontal);
    juce__slider4->setTextBoxStyle (juce::Slider::TextBoxRight, false, 80, 20);
    juce__slider4->addListener (this);

    juce__slider4->setBounds (120, 132, 312, 24);

    juce__slider5.reset (new juce::Slider ("inputLocSlider"));
    addAndMakeVisible (juce__slider5.get());
    juce__slider5->setRange (0, 10, 0);
    juce__slider5->setSliderStyle (juce::Slider::LinearHorizontal);
    juce__slider5->setTextBoxStyle (juce::Slider::TextBoxRight, false, 80, 20);
    juce__slider5->addListener (this);

    juce__slider5->setBounds (120, 216, 312, 24);

    juce__label4.reset (new juce::Label ("waveSpeedLabel",
                                         TRANS("label text")));
    addAndMakeVisible (juce__label4.get());
    juce__label4->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label4->setJustificationType (juce::Justification::centredLeft);
    juce__label4->setEditable (false, false, false);
    juce__label4->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label4->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label4->setBounds (120, 108, 150, 24);

    juce__label5.reset (new juce::Label ("inputLocLabel",
                                         TRANS("label text")));
    addAndMakeVisible (juce__label5.get());
    juce__label5->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label5->setJustificationType (juce::Justification::centredLeft);
    juce__label5->setEditable (false, false, false);
    juce__label5->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label5->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label5->setBounds (120, 192, 150, 24);

    juce__slider6.reset (new juce::Slider ("pulseWidthSlider"));
    addAndMakeVisible (juce__slider6.get());
    juce__slider6->setRange (0, 10, 0);
    juce__slider6->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    juce__slider6->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    juce__slider6->addListener (this);

    juce__slider6->setBounds (71, 250, 228, 132);

    juce__label6.reset (new juce::Label ("pulseWidthLabel",
                                         TRANS("label text")));
    addAndMakeVisible (juce__label6.get());
    juce__label6->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label6->setJustificationType (juce::Justification::centredLeft);
    juce__label6->setEditable (false, false, false);
    juce__label6->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label6->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label6->setBounds (151, 296, 72, 24);

    internalPath1.startNewSubPath (12.0f, 72.0f);
    internalPath1.lineTo (12.0f, 12.0f);
    internalPath1.lineTo (468.0f, 12.0f);
    internalPath1.lineTo (468.0f, 72.0f);
    internalPath1.closeSubPath();

    internalPath2.startNewSubPath (12.0f, 384.0f);
    internalPath2.lineTo (12.0f, 84.0f);
    internalPath2.lineTo (468.0f, 84.0f);
    internalPath2.lineTo (468.0f, 384.0f);
    internalPath2.closeSubPath();


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

NewComponent::~NewComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    juce__slider = nullptr;
    juce__slider2 = nullptr;
    juce__label = nullptr;
    juce__label3 = nullptr;
    juce__slider3 = nullptr;
    juce__label2 = nullptr;
    juce__slider4 = nullptr;
    juce__slider5 = nullptr;
    juce__label4 = nullptr;
    juce__label5 = nullptr;
    juce__slider6 = nullptr;
    juce__label6 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void NewComponent::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff003846));

    {
        float x = 0, y = 0;
        juce::Colour fillColour = juce::Colour (0xff2aa58b);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillPath (internalPath1, juce::AffineTransform::translation(x, y));
    }

    {
        float x = 0, y = 0;
        juce::Colour fillColour1 = juce::Colour (0xff8c00ff), fillColour2 = juce::Colour (0xff710080);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (juce::ColourGradient (fillColour1,
                                             456.0f - 0.0f + x,
                                             static_cast<float> (proportionOfHeight (0.0200f)) - 0.0f + y,
                                             fillColour2,
                                             36.0f - 0.0f + x,
                                             360.0f - 0.0f + y,
                                             false));
        g.fillPath (internalPath2, juce::AffineTransform::translation(x, y));
    }

    {
        int x = 284, y = 272, width = 164, height = 80;
        juce::Colour fillColour = juce::Colour (0xa3ffc032);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 32, y = 96, width = 52, height = 264;
        juce::Colour fillColour = juce::Colour (0xff9143cb);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 105, y = 100, width = 339, height = 152;
        juce::Colour fillColour = juce::Colour (0xffbd418f);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        float x = 141.0f, y = 262.0f, width = 88.0f, height = 88.0f;
        juce::Colour fillColour = juce::Colour (0xff2aa5a1);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillEllipse (x, y, width, height);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void NewComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void NewComponent::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == juce__slider.get())
    {
        //[UserSliderCode_juce__slider] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider]
    }
    else if (sliderThatWasMoved == juce__slider2.get())
    {
        //[UserSliderCode_juce__slider2] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider2]
    }
    else if (sliderThatWasMoved == juce__slider3.get())
    {
        //[UserSliderCode_juce__slider3] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider3]
    }
    else if (sliderThatWasMoved == juce__slider4.get())
    {
        //[UserSliderCode_juce__slider4] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider4]
    }
    else if (sliderThatWasMoved == juce__slider5.get())
    {
        //[UserSliderCode_juce__slider5] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider5]
    }
    else if (sliderThatWasMoved == juce__slider6.get())
    {
        //[UserSliderCode_juce__slider6] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider6]
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

<JUCER_COMPONENT documentType="Component" className="NewComponent" componentName=""
                 parentClasses="public juce::Component" constructorParams="" variableInitialisers=""
                 snapPixels="12" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff003846">
    <PATH pos="0 0 100 100" fill="solid: ff2aa58b" hasStroke="0" nonZeroWinding="1">s 12 72 l 12 12 l 468 12 l 468 72 x</PATH>
    <PATH pos="0 0 100 100" fill="linear: 456 2.005%, 36 360, 0=ff8c00ff, 1=ff710080"
          hasStroke="0" nonZeroWinding="1">s 12 384 l 12 84 l 468 84 l 468 384 x</PATH>
    <RECT pos="284 272 164 80" fill="solid: a3ffc032" hasStroke="0"/>
    <RECT pos="32 96 52 264" fill="solid: ff9143cb" hasStroke="0"/>
    <RECT pos="105 100 339 152" fill="solid: ffbd418f" hasStroke="0"/>
    <ELLIPSE pos="141 262 88 88" fill="solid: ff2aa5a1" hasStroke="0"/>
  </BACKGROUND>
  <SLIDER name="wetDrySlider" id="9498fc0ef3acaf6c" memberName="juce__slider"
          virtualName="" explicitFocusOrder="0" pos="282 287 84 84" min="0.0"
          max="1.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="gainSlider" id="103392d7badb9a3a" memberName="juce__slider2"
          virtualName="" explicitFocusOrder="0" pos="374 287 72 84" min="0.0"
          max="1.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="wetDryLabel" id="43f7d14f2e526632" memberName="juce__label"
         virtualName="" explicitFocusOrder="0" pos="288 276 74 12" edTextCol="ff000000"
         edBkgCol="0" labelText="label text" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="gainLabel" id="76aeed76cd00fe62" memberName="juce__label3"
         virtualName="" explicitFocusOrder="0" pos="372 276 74 12" edTextCol="ff000000"
         edBkgCol="0" labelText="label text" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="releaseSlider" id="6ce5d5e374390467" memberName="juce__slider3"
          virtualName="" explicitFocusOrder="0" pos="20 121 77 252" min="0.0"
          max="10.0" int="0.0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="releaseLabel" id="c4852c352cf66879" memberName="juce__label2"
         virtualName="" explicitFocusOrder="0" pos="24 96 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="label text" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="waveSpeedSlider" id="3388aaa02bb74728" memberName="juce__slider4"
          virtualName="" explicitFocusOrder="0" pos="120 132 312 24" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="inputLocSlider" id="88ae6002cdd73606" memberName="juce__slider5"
          virtualName="" explicitFocusOrder="0" pos="120 216 312 24" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="waveSpeedLabel" id="982d5b9f146949df" memberName="juce__label4"
         virtualName="" explicitFocusOrder="0" pos="120 108 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="label text" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="inputLocLabel" id="d6986afaf2360e24" memberName="juce__label5"
         virtualName="" explicitFocusOrder="0" pos="120 192 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="label text" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="pulseWidthSlider" id="70f2334d53baaa98" memberName="juce__slider6"
          virtualName="" explicitFocusOrder="0" pos="71 250 228 132" min="0.0"
          max="10.0" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="pulseWidthLabel" id="4691cbca90d48ae5" memberName="juce__label6"
         virtualName="" explicitFocusOrder="0" pos="151 296 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="label text" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

