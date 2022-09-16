#include "PluginProcessor.h"
#include "Parameters.h"
#include "GUI/PluginEditor.h"

Chorus_effectAudioProcessor::Chorus_effectAudioProcessor()
    : parameters(*this, nullptr, "Chorus_effectParameters", Parameters::createParameterLayout())
{
    parameters.addParameterListener(NAME_DW, this);
    parameters.addParameterListener(NAME_DT, this);
    parameters.addParameterListener(NAME_FREQ, this);
    parameters.addParameterListener(NAME_MOD, this);

    // default value for useless parameters
    delay.setFeedback(DEFAULT_FB);
    LFO.setWaveform(DEFAULT_WF);
    LFO.setPhaseDelta(DEFAULT_FD);

    //delay.setTime(DEFAULT_DT);
    drywet.setDryWetRatio(DEFAULT_DW);
    timeAdapter.setParameter(DEFAULT_DT);
    LFO.setFrequency(DEFAULT_FREQ);
    timeAdapter.setModAmount(DEFAULT_MOD);
}

Chorus_effectAudioProcessor::~Chorus_effectAudioProcessor() {}

//==============================================================================
void Chorus_effectAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    drywet.prepareToPlay(sampleRate, samplesPerBlock);
    delay.prepareToPlay(sampleRate, samplesPerBlock);
    LFO.prepareToPlay(sampleRate);
    modulationSignal.setSize(2, samplesPerBlock);
    timeAdapter.prepareToPlay(sampleRate);
}

void Chorus_effectAudioProcessor::releaseResources()
{
    drywet.releaseResources();
    delay.releaseResurces();
    modulationSignal.setSize(0, 0);
}

void Chorus_effectAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    const auto numSamples = buffer.getNumSamples();

    LFO.getNextAudioBlock(modulationSignal, numSamples);
    timeAdapter.processBlock(modulationSignal, numSamples);
    drywet.setDry(buffer);
    delay.processBlock(buffer, modulationSignal);
    drywet.merge(buffer);
}


juce::AudioProcessorEditor* Chorus_effectAudioProcessor::createEditor()
{
    return new PluginEditor(*this, parameters);
}

void Chorus_effectAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    auto state = parameters.copyState();
    std::unique_ptr<XmlElement> xml(state.createXml());
    copyXmlToBinary(*xml, destData);
}

void Chorus_effectAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    std::unique_ptr<XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));
    if (xmlState.get() != nullptr)
        if (xmlState->hasTagName(parameters.state.getType()))
            parameters.replaceState(ValueTree::fromXml(*xmlState));
}

void Chorus_effectAudioProcessor::parameterChanged(const String& paramID, float newValue)
{
    if (paramID == NAME_DW)
        drywet.setDryWetRatio(newValue);

    if (paramID == NAME_DT)
        timeAdapter.setParameter(newValue);

    if (paramID == NAME_FREQ)
        LFO.setFrequency(newValue);

    if (paramID == NAME_MOD)
        timeAdapter.setModAmount(newValue);
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new Chorus_effectAudioProcessor();
}
