#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Percussa.h"

#include <atomic>

inline float constrain(float v, float vMin, float vMax) {
    return std::max<float>(vMin, std::min<float>(vMax, v));
}

struct Msw8Data {
    Msw8Data() {
        inSel_      = 0.0f;
        outSel_     = 0.0f;
        useActive_  = false;
        inCount_    = 0;
        outCount_   = 0;
        lastInIdx_  = 0;
        lastOutIdx_  = 0;
        soft_ = false;
    }
    ~Msw8Data() {
    }

    // params - user
    std::atomic<float> inSel_;
    std::atomic<float> outSel_;
    std::atomic<bool>  useActive_; // only use active in/out for selection
    std::atomic<bool>  soft_; // fade switch


    // working data

    // processor updates
    std::atomic<unsigned> lastInIdx_;
    std::atomic<unsigned> lastOutIdx_;

    unsigned inCount_;
    unsigned outCount_;
};


class Msw8  : public AudioProcessor
{
public:
    Msw8();
    ~Msw8();

    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    const String getName() const override;

    int getNumParameters() override;
    float getParameter (int index) override;
    void setParameter (int index, float newValue) override;

    const String getParameterName (int index) override;
    const String getParameterText (int index) override;

    const String getInputChannelName (int channelIndex) const override;
    const String getOutputChannelName (int channelIndex) const override;
    bool isInputChannelStereoPair (int index) const override;
    bool isOutputChannelStereoPair (int index) const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool silenceInProducesSilenceOut() const override;
    double getTailLengthSeconds() const override;

    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    Msw8Data& data() { return data_;}

    bool isInputEnabled(unsigned idx) { return params_[Percussa::sspInEn1 + I_SIG_1 + idx] > 0.5f;}
    bool isOutputEnabled(unsigned idx) { return params_[Percussa::sspOutEn1 + O_SIG_A + idx] > 0.5f;}
    void getLastSel(unsigned& in, unsigned& out) { in = data_.lastInIdx_, out = data_.lastOutIdx_;}

protected:

private:
        enum {
        I_IN_SEL,
        I_OUT_SEL,
        I_SIG_1,
        I_SIG_2,
        I_SIG_3,
        I_SIG_4,
        I_SIG_5,
        I_SIG_6,
        I_SIG_7,
        I_SIG_8,
        I_MAX
    };
    enum {
        O_SIG_A,
        O_SIG_B,
        O_SIG_C,
        O_SIG_D,
        O_SIG_E,
        O_SIG_F,
        O_SIG_G,
        O_SIG_H,
        O_MAX
    };

public:
    static constexpr unsigned MAX_SIG_IN = (I_SIG_8 - I_SIG_1) + 1;
    static constexpr unsigned MAX_SIG_OUT = (O_SIG_H - O_SIG_A) + 1;

private:
    void writeToXml(juce::XmlElement& xml);
    void readFromXml(juce::XmlElement& xml);

    AudioSampleBuffer lastBuffer_;
    AudioSampleBuffer inputBuffer_;
    Msw8Data data_;
    float params_[Percussa::sspLast];

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Msw8)
};


