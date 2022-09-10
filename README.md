# Chorus VST3 - Effect Audio

[![License](https://img.shields.io/badge/License-MIT-blue)](https://github.com/FedericoBruzzone/chorus_audio/edit/master/License)
[![c++Make with](https://img.shields.io/badge/C%2B%2B-v12.1.0-orange)](https://en.wikipedia.org/wiki/C%2B%2B)
[![JUCE](https://img.shields.io/badge/JUCE-v6.1.6-green)](https://juce.com)
[![stability-stable](https://img.shields.io/badge/stability-stable-green.svg)](https://github.com/emersion/stability-badges#stable)


<img src="./Docs/Shimmer_VST3.png" width="600" heigth="600"/>

# Introduction
The chorus effect is by far one of the most popular phase modulation effects used in music. 

“Chorusing” is meant to simulate the subtle pitch and timing differences that occur when multiple musicians or vocalists play the same note, but vary slightly in pitch and timing. We can describe the sound of “chorusing” as a doubling effect that adds thickness, shimmer, and helps a signal sound “larger” than it would on its own. 

---

# Setup 
1. Install [juce framework](https://juce.com/get-juce/download)
2. Install [Visual studio 2022](https://visualstudio.microsoft.com)

---

### First step
Now, you can try to open the Projucer.exe and open shimmer.jucer file. If there are no problems, you can run Visual Studio 2022 from the appropriate button at the top-right of Projucer.

### Second step

In the JUCE folder in documents (JUCE/extras/AudioPluginHost), there is juce Host called AudioPluginHost, this allows to test our code without a DAW (Digital Audio Workstation).

You have to open AudioPluginHost.jucer on Projucer and later in Visual Studio 2022, and compile it in debug mode.

### Third step

Now, you can re-open the "Shimmer" project, and pressing with the right button on "Shimmer_VST3" and in debug menu you can set the path of your AudioPluginHost (.\Documents\JUCE\extras\AudioPluginHost\Builds\VisualStudio2022\x64\Debug\App\AudioPluginHost.exw) on command space.

And, pressing with the right button on "Shimmer_VST3" another time, and click
"Set as Sturtup project".

Now, try to run the Shimmer with Local Windows Debugger button.

# Troubleshooting
If you find problems with the source code or configuration, please contact me at federico.bruzzone.i@gmail.com.

If this is your first time using juce, i understand that the configuration of this project is not easy.

# Full screen GUI
![Shimmer_VST3](./Docs/Shimmer_VST3.png)
