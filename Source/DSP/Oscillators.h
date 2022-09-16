#pragma once
#include <JuceHeader.h>
#include "../Parameters.h"

class NaiveOscillator
{
public:
	NaiveOscillator() {};
	~NaiveOscillator() {};

	void prepareToPlay(double sr)
	{
		samplePeriod = 1.0 / sr;
		frequency.reset(sr, GLIDE_TIME);
	}

	void setFrequency(float newValue)
	{
		frequency.setTargetValue(newValue);
	}

	void setWaveform(float newValue)
	{
		waveform = roundToInt(newValue);
	}

	void setPhaseDelta(float newValue)
	{
		phaseDelta = newValue;
	}

	void getNextAudioBlock(AudioBuffer<float>& buffer, const int numSamples)
	{
		const int numCh = buffer.getNumChannels();
		auto bufferData = buffer.getArrayOfWritePointers();

		for (int smp = 0; smp < numSamples; ++smp)
		{
			bufferData[0][smp] = getNextAudioSample(0);
			bufferData[1][smp] = getNextAudioSample(phaseDelta);

			phaseIncrement = frequency.getNextValue() * samplePeriod;
			currentPhase += phaseIncrement;
			currentPhase -= static_cast<int>(currentPhase);
				
		}
	}

	float getNextAudioSample(const float delta)
	{
		auto sampleValue = 0.0f;
		float phase = currentPhase + delta;

		switch (waveform)
		{
		case 0: // Sine
			sampleValue = sin(MathConstants<float>::twoPi * phase);
			break;
		case 1: // Triangular
			sampleValue = 4.0f * abs(phase - 0.5f) - 1.0f;
			break;
		case 2: // Saw up
			sampleValue = 2.0f * phase - 1.0f;
			break;
		case 3: // Saw down
			sampleValue = -2.0f * phase - 1.0f;
			break;
		default:
			break;
		}

		/*phaseIncrement = frequency.getNextValue() * samplePeriod;
		currentPhase += phaseIncrement;
		currentPhase -= static_cast<int>(currentPhase);*/

		return sampleValue;
	}

private:

	int waveform = 0; 

	double samplePeriod = 1.0;
	float currentPhase = 0.0f;
	float phaseIncrement = 0.0f;
	float phaseDelta = 0.0f;
	SmoothedValue<float, ValueSmoothingTypes::Multiplicative> frequency;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(NaiveOscillator)
};

class ParametrModulation
{
public:
	ParametrModulation() {}
	~ParametrModulation() {}

	void prepareToPlay(double sr)
	{
		parameter.reset(sr, SMOOTHING_TIME);
		modAmount.reset(sr, SMOOTHING_TIME);
	}

	void setParameter(float newValue)
	{
		parameter.setTargetValue(newValue);
	}

	void setModAmount(float newValue)
	{
		modAmount.setTargetValue(newValue);
	}

	void processBlock(AudioBuffer<float>& buffer, const int numSamples)
	{
		auto bufferData = buffer.getArrayOfWritePointers();
		auto numCh = buffer.getNumChannels();

		for (int ch = 0; ch < numCh; ++ch)
		{
			FloatVectorOperations::add(bufferData[ch], 1.0, numSamples);
			FloatVectorOperations::multiply(bufferData[ch], 0.5f, numSamples);
		}
		modAmount.applyGain(buffer, numSamples);

		if (parameter.isSmoothing())
			for (int smp = 0; smp < numSamples; ++smp)
			{
				const auto param = parameter.getNextValue();

				for (int ch = 0; ch < numCh; ++ch)
					bufferData[ch][smp] += param;
			}
		else
			for (int ch = 0; ch < numCh; ++ch)
				FloatVectorOperations::add(bufferData[ch], parameter.getCurrentValue(), numSamples);

		for (int ch = 0; ch < numCh; ++ch)
			FloatVectorOperations::min(bufferData[ch], bufferData[ch], MAX_DELAY_TIME, numSamples);
	}

private:

	SmoothedValue<float, ValueSmoothingTypes::Linear> modAmount;
	SmoothedValue<float, ValueSmoothingTypes::Linear> parameter;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ParametrModulation)

};