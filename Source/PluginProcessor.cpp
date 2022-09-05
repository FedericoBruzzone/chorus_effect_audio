#include "PluginProcessor.h"
#include "Parameters.h"
#include "PluginEditor.h"

DelayFXAudioProcessor::DelayFXAudioProcessor()
    : parameters(*this, nullptr, "DelayFXParameters", Parameters::createParameterLayout())
{
    parameters.addParameterListener(NAME_DW, this);
    parameters.addParameterListener(NAME_DT, this);
    parameters.addParameterListener(NAME_FB, this);
    parameters.addParameterListener(NAME_FREQ, this);
    parameters.addParameterListener(NAME_MOD, this);
    parameters.addParameterListener(NAME_WF, this);

    delay.setFeedback(DEFAULT_FB);
    //delay.setTime(DEFAULT_DT);
    drywetter.setDryWetRatio(DEFAULT_DW);
    LFO.setFrequency(DEFAULT_FREQ);
    LFO.setWaveform(DEFAULT_WF);
    timeAdapter.setModAmount(DEFAULT_MOD);
    timeAdapter.setParameter(DEFAULT_DT);
}

DelayFXAudioProcessor::~DelayFXAudioProcessor()
{
}

//==============================================================================
void DelayFXAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    drywetter.prepareToPlay(sampleRate, samplesPerBlock);
    delay.prepareToPlay(sampleRate, samplesPerBlock);
    LFO.prepareToPlay(sampleRate);
    modulationSignal.setSize(2, samplesPerBlock);
    timeAdapter.prepareToPlay(sampleRate);
}

void DelayFXAudioProcessor::releaseResources()
{
    drywetter.releaseResources();
    delay.releaseResurces();
    modulationSignal.setSize(0, 0);
}

void DelayFXAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    const auto numSamples = buffer.getNumSamples();

    // Genero una modulante
    LFO.getNextAudioBlock(modulationSignal, numSamples);

    // Scalare modulante
    timeAdapter.processBlock(modulationSignal, numSamples);

    // Salvo il segnale in input pulito
    drywetter.setDry(buffer);

    // Applicare delay
    //delay.processBlock(buffer);
    delay.processBlock(buffer, modulationSignal);
    
    // Miscelo il segnale pulito salvato in drywetter con quello processato da delay
    drywetter.merge(buffer);

    // ~~~ Listen to the wavez ~~~
    //LFO.getNextAudioBlock(buffer, buffer.getNumSamples());
}


juce::AudioProcessorEditor* DelayFXAudioProcessor::createEditor()
{
    return new PluginEditor(*this, parameters);
}

//==============================================================================
void DelayFXAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    auto state = parameters.copyState();
    std::unique_ptr<XmlElement> xml(state.createXml());
    copyXmlToBinary(*xml, destData);
}

void DelayFXAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    std::unique_ptr<XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));
    if (xmlState.get() != nullptr)
        if (xmlState->hasTagName(parameters.state.getType()))
            parameters.replaceState(ValueTree::fromXml(*xmlState));
}

void DelayFXAudioProcessor::parameterChanged(const String& paramID, float newValue)
{
    if (paramID == NAME_DW)
        drywetter.setDryWetRatio(newValue);

    if (paramID == NAME_DT)
        timeAdapter.setParameter(newValue);
        //delay.setTime(newValue);

    if (paramID == NAME_FB)
        delay.setFeedback(newValue);

    if (paramID == NAME_FREQ)
        LFO.setFrequency(newValue);

    if (paramID == NAME_MOD)
        timeAdapter.setModAmount(newValue);

    if (paramID == NAME_WF)
        LFO.setWaveform(newValue);
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new DelayFXAudioProcessor();
}
