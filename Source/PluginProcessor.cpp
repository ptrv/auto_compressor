/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

const float defaultActive = 1.f;
const float defaultThreshold = 0.f;
const float defaultRatio = 0.f;
const float defaultGain = 0.f;
const float defaultAttack = (float) LOG2PARAM(0.005, MINATTACKTIME, MAXATTACKTIME);
const float defaultRelease = (float) LOG2PARAM(0.05, MINRELEASETIME, MAXRELEASETIME);

const float defaultMetaKneeMult = (float) LIN2PARAM(2.0, MINKNEEMULT, MAXKNEEMULT);
const float defaultMetaMaxAttack = (float) LOG2PARAM(0.08, MINATTACKTIME, MAXATTACKTIME);
const float defaultMetaMaxRelease = (float) LOG2PARAM(1.0, MINRELEASETIME, MAXRELEASETIME);
const float defaultMetaCrest = (float) LOG2PARAM(0.2, MINCRESTTIME, MAXCRESTTIME);
const float defaultMetaAdapt = (float) LOG2PARAM(2.5, MINADAPTTIME, MAXADAPTTIME);
const float defaultMetaNoClipping =  1.f;


//==============================================================================
AutoCompressorAudioProcessor::AutoCompressorAudioProcessor()
    : currentPreset(0)
{
    const int CONST_NUM_PRESETS = 2;
    String presetNames[] = {"Default", "Manual"};

    using namespace std::placeholders;
    typedef std::function<float(int)> tDefaultValueFn;
    tDefaultValueFn defaultFuncs[] = {
        std::bind(&AutoCompressorAudioProcessor::getParameterDefaultValue, this, _1),
        std::bind(&AutoCompressorAudioProcessor::getParameterDefaultValueManual, this, _1)
    };

    for (int i = 0; i < CONST_NUM_PRESETS; ++i)
    {
        Preset preset;
        preset.name = presetNames[i];
        presets.add(preset);
        setCurrentProgram(i);

        for (int j = 0; j < numAllParams; ++j)
        {
            setParameter(j, defaultFuncs[i](j));
        }
    }

    setCurrentProgram(0);
}

AutoCompressorAudioProcessor::~AutoCompressorAudioProcessor()
{
}

//==============================================================================

//==============================================================================
const String AutoCompressorAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int AutoCompressorAudioProcessor::getNumParameters()
{
    return numAllParams;
}

float AutoCompressorAudioProcessor::getParameter (int index)
{
    return presets[getCurrentProgram()].params[index];
}

float AutoCompressorAudioProcessor::getParameterDefaultValue(int index)
{
    switch(index) {
    case activeParam: return 1.f;
    case thresholdParam: return 0.f;
    case ratioParam: return 0.f;
    case gainParam: return 0.f;
    case attackParam: return (float) LOG2PARAM(0.005, MINATTACKTIME, MAXATTACKTIME);
    case releaseParam: return (float) LOG2PARAM(0.05, MINRELEASETIME, MAXRELEASETIME);

    case autoAttackParam:
    case autoReleaseParam:
    case autoKneeParam:
    case autoGainParam:
        return 1.f;

    case metaKneeMultParam: return (float) LIN2PARAM(2.0, MINKNEEMULT, MAXKNEEMULT);
    case metaMaxAttackParam: return (float) LOG2PARAM(0.08, MINATTACKTIME, MAXATTACKTIME);
    case metaMaxReleaseParam: return (float) LOG2PARAM(1.0, MINRELEASETIME, MAXRELEASETIME);
    case metaCrestParam: return (float) LOG2PARAM(0.2, MINCRESTTIME, MAXCRESTTIME);
    case metaAdaptParam: return (float) LOG2PARAM(2.5, MINADAPTTIME, MAXADAPTTIME);
    case metaNoClippingParam: return 1.f;
    }
    return 0.f;
}

float AutoCompressorAudioProcessor::getParameterDefaultValueManual(int index)
{
    switch(index) {
    case autoAttackParam:
    case autoReleaseParam:
    case autoKneeParam:
    case autoGainParam:
        return 0.f;
    default:
        return getParameterDefaultValue(index);
    }
}

float AutoCompressorAudioProcessor::getParameterFromString(int index, const String& text)
{
    double x = text.getDoubleValue();
    switch (index)
    {
    case thresholdParam: return (float) CLAMP(fabs(x) / MAXGAINDB, 0.0, 1.0);
    case ratioParam: return (float) (1.0 - 1.0 / CLAMP(fabs(x), 1.0, 100.0));
    case kneeWidthParam: return (float) CLAMP(fabs(x) / MAXGAINDB, 0.0, 1.0);
    case gainParam: return (float) CLAMP(fabs(x) / MAXGAINDB, 0.0, 1.0);
    case attackParam: return (float) LOG2PARAM(CLAMP(fabs(x) / 1000.0, MINATTACKTIME, MAXATTACKTIME), MINATTACKTIME, MAXATTACKTIME);
    case releaseParam: return (float) LOG2PARAM(CLAMP(fabs(x) / 1000.0, MINRELEASETIME, MAXRELEASETIME), MINRELEASETIME, MAXRELEASETIME);
    }
    return getParameter(index);
}

void AutoCompressorAudioProcessor::setParameter (int index, float newValue)
{
    // params[index] = newValue;
    Preset* presetsRaw = presets.getRawDataPointer();
    presetsRaw[getCurrentProgram()].params[index] = newValue;
    double fs = getSampleRate();

    switch(index) {
    case thresholdParam:
        logThreshold[kTarget] = log(pow(10.0, newValue * -MAXGAINDB / 20.0));
        break;
    case ratioParam:
        slope = -newValue;
        break;
    case kneeWidthParam:
        logKneeWidth = log(pow(10.0, newValue * MAXGAINDB / 20.0));
        break;
    case gainParam:
        logGain[kTarget] = log(pow(10.0, newValue * MAXGAINDB / 20.0));
        break;

    case attackParam:
        attackTime = PARAM2LOG(newValue, MINATTACKTIME, MAXATTACKTIME);
        attackCoeff = onePoleCoeff(fs, attackTime);
        break;

    case releaseParam:
        releaseTime = PARAM2LOG(newValue, MINRELEASETIME, MAXRELEASETIME);
        releaseCoeff = onePoleCoeff(fs, releaseTime);
        break;

    case activeParam: active = (newValue >= 0.5f); break;
    case autoKneeParam: autoKnee = (newValue >= 0.5f); break;
    case autoGainParam: autoGain = (newValue >= 0.5f); break;
    case autoAttackParam: autoAttack = (newValue >= 0.5f); break;
    case autoReleaseParam: autoRelease = (newValue >= 0.5f); break;

    case metaKneeMultParam:
        metaKneeMult = PARAM2LIN(newValue, MINKNEEMULT, MAXKNEEMULT);
        break;

    case metaMaxAttackParam:
        metaMaxAttackTime = PARAM2LOG(newValue, MINATTACKTIME, MAXATTACKTIME);
        break;

    case metaMaxReleaseParam:
        metaMaxReleaseTime = PARAM2LOG(newValue, MINRELEASETIME, MAXRELEASETIME);
        break;

    case metaCrestParam:
        metaCrestTime = PARAM2LOG(newValue, MINCRESTTIME, MAXCRESTTIME);
        metaCrestCoeff = onePoleCoeff(fs, metaCrestTime);
        break;

    case metaAdaptParam:
        metaAdaptTime = PARAM2LOG(newValue, MINADAPTTIME, MAXADAPTTIME);
        metaAdaptCoeff = onePoleCoeff(fs, metaAdaptTime);
        break;

    case metaNoClippingParam:
        metaNoClipping = (newValue >= 0.5f);
        break;
    }
}

const String AutoCompressorAudioProcessor::getParameterName (int index)
{
    switch(index) {
    case activeParam: return "Active";
    case thresholdParam: return "Thresh";
    case kneeWidthParam: return "Width";
    case autoKneeParam: return "AutoKnee";
    case gainParam: return "Gain";
    case autoGainParam: return "AutoGain";
    case ratioParam: return "Ratio";
    case attackParam: return "Attack";
    case autoAttackParam: return "AutoAtt";
    case releaseParam: return "Release";
    case autoReleaseParam: return "AutoRel";

    case metaKneeMultParam: return "KneeMult";
    case metaMaxAttackParam: return "MaxAtt";
    case metaMaxReleaseParam: return "MaxRel";
    case metaCrestParam: return "Crest";
    case metaAdaptParam: return "Adapt";
    case metaNoClippingParam: return "NoClip";
    }

    return String::empty;
}

const String db2str(float value)
{
    if (value <= 0)
    {
        return "-oo";
    }
    else
    {
        return String(20. * log10 (value), 2);
    }
}

const String AutoCompressorAudioProcessor::getParameterText (int index)
{
    switch(index) {
    case ratioParam:
        if(slope > -0.99) {
            return String(1.0 / (1.0 + slope), 2) + ":1";
        }
        else {
            return "oo:1";
        }

    case thresholdParam:
        return db2str((float) exp(logThreshold[kTarget]));

    case gainParam:
        return db2str((float) exp(logGain[kTarget]));
    case kneeWidthParam:
        return db2str((float) exp(logKneeWidth));
    case attackParam:
        return String((float) (attackTime * 1000.0),2);
    case releaseParam:
        return String((float) (releaseTime * 1000.0), 2);

    case metaKneeMultParam:
        return String((float) metaKneeMult, 2);
    case metaMaxAttackParam:
        return String((float) (metaMaxAttackTime * 1000.0), 2);
    case metaMaxReleaseParam:
        return String((float) (metaMaxReleaseTime * 1000.0), 2);
    case metaCrestParam:
        return String((float) (metaCrestTime * 1000.0), 2);
    case metaAdaptParam:
        return String((float) (metaAdaptTime * 1000.0), 2);
    }

    return (getParameter(index) >= 0.5f) ? "On" : "Off";
}

const String AutoCompressorAudioProcessor::getParameterLabel(int index)
{
    switch(index) {
    case thresholdParam:
    case gainParam:
    case kneeWidthParam:
        return "dB";

    case attackParam:
    case releaseParam:
    case metaMaxAttackParam:
    case metaMaxReleaseParam:
    case metaCrestParam:
    case metaAdaptParam:
        return "ms";
    }

    return String::empty;
}

const String AutoCompressorAudioProcessor::getInputChannelName (int channelIndex) const
{\
    return String (channelIndex + 1);
}

const String AutoCompressorAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool AutoCompressorAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool AutoCompressorAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool AutoCompressorAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool AutoCompressorAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool AutoCompressorAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double AutoCompressorAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int AutoCompressorAudioProcessor::getNumPrograms()
{
    return presets.size();
}

int AutoCompressorAudioProcessor::getCurrentProgram()
{
    return currentPreset;
}

void AutoCompressorAudioProcessor::setCurrentProgram (int index)
{
    currentPreset = jlimit(0, getNumPrograms(), index);
    setParameters();
}

const String AutoCompressorAudioProcessor::getProgramName (int index)
{
    return presets[index].name;
}

void AutoCompressorAudioProcessor::changeProgramName (int index, const String& newName)
{
    if (index != 0 && index < presets.size())
    {
        presets[index].name = newName;
    }
}

//==============================================================================
void AutoCompressorAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    rampCoeff = onePoleCoeff(sampleRate, 0.05);

    crestRms = crestPeak = MINVAL;
    cvSmooth = cvAttack = cvRelease = 0.0;
    logThreshold[kCurrent] = logThreshold[kTarget];
    logGain[kCurrent] = logGain[kTarget];
}

void AutoCompressorAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void AutoCompressorAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    int numSamples = buffer.getNumSamples();

    if (buffer.getNumChannels() >= 2)
    {
        float* dataL = buffer.getSampleData(0);
        float* dataR = buffer.getSampleData(1);

        while(--numSamples >= 0)
        //for (int i = 0; i < numSamples; ++i)
        {
            float inL = *dataL;
            float inR = *dataR;

            float absL = ABS(inL);
            float absR = ABS(inR);
            float maxLR = MAX(absL, absR);

            float mult = (float) processSidechain(maxLR);
            float outL = inL;
            float outR = inR;

            if (active)
            {
                outL *= mult;
                outR *= mult;
            }


            *dataL++ = outL;
            *dataR++ = outR;

            logThreshold[kCurrent] = MIX(logThreshold[kTarget], logThreshold[kCurrent], rampCoeff);
            logGain[kCurrent] = MIX(logGain[kTarget], logGain[kCurrent], rampCoeff);
        }

        cvAttack = killDenormal(cvAttack);
        cvRelease = killDenormal(cvRelease);
        cvSmooth = killDenormal(cvSmooth);
        crestRms = killDenormal(crestRms);
        crestPeak = killDenormal(crestPeak);

        logThreshold[kCurrent] = killDenormal(logThreshold[kCurrent]);
        logGain[kCurrent] = killDenormal(logGain[kCurrent]);
    }

    // In case we have more outputs than inputs, we'll clear any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
    {
        buffer.clear (i, 0, buffer.getNumSamples());
    }
}

//==============================================================================

forcedinline double AutoCompressorAudioProcessor::processSidechain(float inAbs)
{
    const double fs = getSampleRate();

    //Square of crest factor
    double inSquare = MAX(SQUARE(inAbs), MINVAL);
    crestRms = MIX(inSquare, crestRms, metaCrestCoeff);
    crestPeak = MAX(MIX(inSquare, crestPeak, metaCrestCoeff), inSquare);
    double crestSquare = crestPeak / crestRms;

    // Attack and release coefficients
    double myAttackCoeff = attackCoeff;
    double myAttackTime = attackTime;
    if (autoAttack)
    {
        myAttackTime = 2.0 * metaMaxAttackTime / crestSquare;
        myAttackCoeff = onePoleCoeff(fs, myAttackTime);
    }

    double myReleaseCoeff = releaseCoeff;
    if (autoRelease)
    {
        double myReleaseTime = 2.0 * metaMaxReleaseTime / crestSquare;
        myReleaseCoeff = onePoleCoeff(fs, myReleaseTime - myAttackTime);
    }

    // Log conversion and overshoot
    double logIn = log(MAX(inAbs, MINVAL));
    double logOvershoot = logIn - logThreshold[kCurrent];

    //set ratio/slope
    double mySlope = slope;
    if (autoKnee)
    {
        mySlope = -1.0;
    }

    // set estimate for average CV
    double cvEstimate = logThreshold[kCurrent] * -mySlope / 2.0;

    // set knee width
    double myLogWidth = logKneeWidth;
    if (autoKnee)
    {
        myLogWidth = MAX(-(cvSmooth + cvEstimate) * metaKneeMult, 0.0);
    }

    // soft knee rectification
    double cv = 0.0;
    if (logOvershoot >= myLogWidth / 2.0)
    {
        cv = logOvershoot;
    }
    else if (logOvershoot > -myLogWidth / 2.0 && logOvershoot < myLogWidth / 2.0)
    {
        cv = 1.0 / (2.0 * myLogWidth) * SQUARE(logOvershoot + myLogWidth / 2.0);
    }

    // multiply by negative slope for positive CV
    cv *= -mySlope;

    // Release and Attack
    cvRelease = MAX(cv, MIX(cv, cvRelease, myReleaseCoeff));
    cvAttack = MIX(cvRelease, cvAttack, myAttackCoeff);

    // Invert CV again
    cv = -cvAttack;

    // Smooth CV
    cvSmooth = MIX(cv - cvEstimate, cvSmooth, metaAdaptCoeff);

    // make up gain
    if (autoGain)
    {
        if (metaNoClipping && logIn + cv - (cvSmooth + cvEstimate) > MAXCLIPLOG)
        {
            cvSmooth = logIn + cv - cvEstimate - MAXCLIPLOG;
        }

        // apply auto gain
        cv -= cvSmooth + cvEstimate;
    }
    else
    {
        cv += logGain[kCurrent];
    }

    // VCA
    return exp(cv);
}

float AutoCompressorAudioProcessor::getMeter()
{
    if (active)
    {
        return (float) CLAMP((-cvAttack - MINMETERLOG) / (0.0 - MINMETERLOG), 0.0, 1.0);
    }
    return 1.f;

}
//==============================================================================
bool AutoCompressorAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* AutoCompressorAudioProcessor::createEditor()
{
    return new AutoCompressorAudioProcessorEditor (this);
}

//==============================================================================
void AutoCompressorAudioProcessor::getStateInformation (MemoryBlock& destData)
{

    XmlElement xml("PTRVAUTOCOMPRESSORSETTINGS");

    const int currProg = getCurrentProgram();

    xml.setAttribute("CURRENTPRESET", currProg);

    for (int i = 0; i < getNumPrograms(); ++i)
    {
        setCurrentProgram(i);
        XmlElement* xmlPreset = new XmlElement("PRESET");
        xmlPreset->setAttribute("NAME", getProgramName(i));
        for (int j = 0; j < numAllParams; ++j)
        {
            xmlPreset->setAttribute(getParameterName(j), getParameter(j));
        }
        xml.addChildElement(xmlPreset);
    }
    setCurrentProgram(currProg);
    copyXmlToBinary(xml, destData);

}

void AutoCompressorAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    ScopedPointer<XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));

    if (xmlState != nullptr && xmlState->hasTagName("PTRVAUTOCOMPRESSORSETTINGS")
        && xmlState->hasAttribute("CURRENTPRESET"))
    {
        int currentProgram = xmlState->getIntAttribute("CURRENTPRESET");
        presets.clear();

        int presetIdx = 0;
        forEachXmlChildElementWithTagName(*xmlState.get(), xmlPreset, "PRESET")
        {
            Preset preset;
            preset.name = xmlPreset->getStringAttribute("NAME");
            presets.add(preset);
            setCurrentProgram(presetIdx++);
            for (int i = 0; i < numAllParams; ++i)
            {
                const float paramValue =
                    (float) xmlPreset->getDoubleAttribute(getParameterName(i),
                                                          getParameter(i));
                setParameter(i, paramValue);
            }
        }
        setCurrentProgram(currentProgram);
    }
}

void AutoCompressorAudioProcessor::setParameters()
{
    for (int i = 0; i < numAllParams; ++i)
    {
        setParameter(i, getParameter(i));
    }
}
//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new AutoCompressorAudioProcessor();
}
