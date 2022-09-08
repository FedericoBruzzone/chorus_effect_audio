//Chorus_effectAudioProcessor
#pragma once
#include <JuceHeader.h>

// Useful constants
#define MAX_DELAY_TIME 0.08f//5.00f
#define TIME_SMOOTHING 0.02f
#define FBK_SMOOTHING  0.02f

#define LEVEL_SMOOTHING_TIME 0.02f

#define GLIDE_TIME 0.01
#define SMOOTHING_TIME 0.04

// Actual parameters
#define NAME_DW "dw"
#define NAME_DT "dt"
#define NAME_FB "fb"
#define NAME_FREQ "lfoFreq"
#define NAME_MOD "timeMod"
#define NAME_WF "waveform"

#define DEFAULT_DW 0.5f
#define DEFAULT_DT 0.05f
#define DEFAULT_FB 0.0f
#define DEFAULT_FREQ 0.5f
#define DEFAULT_MOD 0.0f
#define DEFAULT_WF 0

namespace Parameters
{
	static AudioProcessorValueTreeState::ParameterLayout createParameterLayout()
	{
		std::vector<std::unique_ptr<RangedAudioParameter>> params;

		params.push_back(std::make_unique<AudioParameterFloat>(NAME_DW, "Dry/Wet", 0.0f, 1.0f, DEFAULT_DW));
		params.push_back(std::make_unique<AudioParameterFloat>(NAME_DT, "Delay time (s)", NormalisableRange<float>(0.02f, MAX_DELAY_TIME, 0.001f), DEFAULT_DT));
		params.push_back(std::make_unique<AudioParameterFloat>(NAME_FREQ, "LFO Freq (Hz) - Rate", NormalisableRange<float>(0.1f, 1.0f, 0.01f), DEFAULT_FREQ));
		params.push_back(std::make_unique<AudioParameterFloat>(NAME_MOD, "Mod amount (s) - Depth", NormalisableRange<float>(0.001f, 0.01f, 0.001f), DEFAULT_MOD));
		

		return {params.begin(), params.end()};
	}
}