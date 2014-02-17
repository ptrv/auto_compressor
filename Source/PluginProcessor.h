/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

// A few helpful macros
#define MIN(a, b) (((a)<(b))?(a):(b))
#define MAX(a, b) (((a)>(b))?(a):(b))
#define CLAMP(x, min, max) ((x)>(max)?(max):(((x)<(min))?(min):(x)))
#define ABS(x) ((x)<0?(-(x)):(x))
#define SQUARE(x) ((x)*(x))
#define MIX(x0, y1, coeff) (((x0)-(y1))*(coeff)+(y1))
// #define PRINTLOG(filename, ...) { FILE *f = fopen(filename, "a"); fprintf (f, __VA_ARGS__); fclose(f); }

#define PARAM2LOG(x, mn, mx) (exp(log(mn) + (x) * (log(mx) - log(mn))))
#define LOG2PARAM(x, mn, mx) ((log(x) - log(mn)) / (log(mx) - log(mn)))

#define PARAM2LIN(x, mn, mx) ((mn) + (x) * ((mx) - (mn)))
#define LIN2PARAM(x, mn, mx) (((x) - (mn)) / ((mx) - (mn)))

static const double MINVAL = 1.0e-6;
static const double MINKNEEMULT = 0.0;
static const double MAXKNEEMULT = 4.0;
static const double MINATTACKTIME = 0.0001;
static const double MAXATTACKTIME = 0.2;
static const double MINRELEASETIME = 0.005;
static const double MAXRELEASETIME = 2.0;
static const double MAXGAINDB = 60.0;
static const double MINADAPTTIME = MAXRELEASETIME / 2.0;
static const double MAXADAPTTIME = MAXRELEASETIME * 2.0;
static const double MINCRESTTIME = MINRELEASETIME;
static const double MAXCRESTTIME = MAXRELEASETIME;
static const double MINMETERLOG = log(pow(10.0, -MAXGAINDB / 20.0));
static const double MAXCLIPLOG = log(pow(10.0, -0.01 / 20.0));

// Calculate one pole filter coefficient
inline double onePoleCoeff(double fs, double tau)
{
    if(tau > 0.0)
    {
        return 1.0 - exp(-1.0 / (tau * fs));
    }
    return 1.0;
}


// Kill denormal number
inline double killDenormal(double value)
{
    static const double denormal = 1E-18;
    value += denormal;
    value -= denormal;
    return value;
}

//==============================================================================
/**
*/
class AutoCompressorAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    AutoCompressorAudioProcessor();
    ~AutoCompressorAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock);
    void releaseResources();

    void processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages);

    //==============================================================================
    AudioProcessorEditor* createEditor();
    bool hasEditor() const;

    //==============================================================================
    const String getName() const;

    int getNumParameters();

    float getParameter (int index);
    float getParameterDefaultValue(int index);

    void setParameter (int index, float newValue);

    const String getParameterName (int index);
    const String getParameterText (int index);
    const String getParameterLabel (int index);

    const String getInputChannelName (int channelIndex) const;
    const String getOutputChannelName (int channelIndex) const;
    bool isInputChannelStereoPair (int index) const;
    bool isOutputChannelStereoPair (int index) const;

    bool acceptsMidi() const;
    bool producesMidi() const;
    bool silenceInProducesSilenceOut() const;
    double getTailLengthSeconds() const;

    //==============================================================================
    int getNumPrograms();
    int getCurrentProgram();
    void setCurrentProgram (int index);
    const String getProgramName (int index);
    void changeProgramName (int index, const String& newName);

    //==============================================================================
    void getStateInformation (MemoryBlock& destData);
    void setStateInformation (const void* data, int sizeInBytes);

    void initialize();

    enum Parameters
    {
        activeParam,
        thresholdParam,
        ratioParam,
        kneeWidthParam,
        autoKneeParam,
        gainParam,
        autoGainParam,
        attackParam,
        autoAttackParam,
        releaseParam,
        autoReleaseParam,

        metaKneeMultParam,
        metaMaxAttackParam,
        metaMaxReleaseParam,
        metaCrestParam,
        metaAdaptParam,
        metaNoClippingParam,

        numAllParams,

        kCurrent = 0,
        kTarget
    };

private:

    double processSidechain(float inAbs);

    float params[numAllParams];

    double rampCoeff;

    bool active;
    bool autoKnee;
    bool autoGain;
    bool autoAttack;
    bool autoRelease;

    double cvRelease;
    double cvAttack;
    double cvSmooth;

    double logThreshold[2];
    double logKneeWidth;
    double logGain[2];
    double slope;

    double crestPeak;
    double crestRms;

    double attackTime;
    double attackCoeff;

    double releaseTime;
    double releaseCoeff;

    double metaKneeMult;
    double metaMaxAttackTime;
    double metaMaxReleaseTime;
    double metaCrestTime;
    double metaCrestCoeff;
    double metaAdaptTime;
    double metaAdaptCoeff;
    bool metaNoClipping;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AutoCompressorAudioProcessor)
};

#endif  // PLUGINPROCESSOR_H_INCLUDED
