
#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "SSP.h"


static const char *xmlTag = JucePlugin_Name;

PluginProcessor::PluginProcessor()
{
    root_ = 0.0f;
    scale_ = 0.0f;
    quant_ = false;

    memset(params_, 0, sizeof(params_));
    memset(lastTrig_, 0, sizeof(lastTrig_));
    memset(lastSig_, 0, sizeof(lastSig_));

#ifdef __APPLE__
    {
        // gets tedious enabling these during testing ;)
        for (unsigned i = Percussa::sspInEn1; i <= Percussa::sspInEn24; i++) params_[i] = 1.0f;
        for (unsigned i = Percussa::sspOutEn1; i <= Percussa::sspOutEn24; i++) params_[i] = 1.0f;
    }
#endif

    randomGen_.setSeedRandomly();
}

PluginProcessor::~PluginProcessor()
{
    ;
}

const String PluginProcessor::getName() const
{
    return JucePlugin_Name;
}

int PluginProcessor::getNumParameters()
{
    return Percussa::sspLast;
}

float PluginProcessor::getParameter (int index)
{
    // SSP appears to only send parameters if they appear to have changed
    // so we need to track the parameters values(!)
    if (index < Percussa::sspLast) return params_[index];
    return 0.0f;
}

void PluginProcessor::setParameter (int index, float newValue)
{
    // this will have to change... as the +/-1 is larger than before
    // current idea is to move away from sendParamChangeMessageToListeners
    // to a differ 'changebroadcaster' to free up parameter change for 'proper use'
    switch (index) {
    case Percussa::sspEnc1:
    case Percussa::sspEnc2:
    case Percussa::sspEnc3:
    case Percussa::sspEnc4:
    {
        if (newValue > 0.5f) {
            params_[index - Percussa::sspFirst]++;
            AudioProcessor::sendParamChangeMessageToListeners(index, 1.0f);
        } else if (newValue < 0.5f) {
            params_[index - Percussa::sspFirst]--;
            AudioProcessor::sendParamChangeMessageToListeners(index, -1.0f);
        } else {
            params_[index] = 0.0f;
            AudioProcessor::sendParamChangeMessageToListeners(index, 0.0f);
        }
        break;
    }
    default: {
        if (index < Percussa::sspLast) params_[index] = newValue;
        AudioProcessor::sendParamChangeMessageToListeners(index, newValue);
        break;
    }
    }
}

const String PluginProcessor::getParameterName (int index)
{
    if (index < Percussa::sspLast) return percussaParamsName[index];
    return String();
}

const String PluginProcessor::getParameterText (int index)
{
    if (index < Percussa::sspLast) return percussaParamsText[index];
    return String();
}

const String PluginProcessor::getInputChannelName (int channelIndex) const
{
    switch (channelIndex) {
    case I_SIG_1:        { return String("In 1");}
    case I_TRIG_1:       { return String("Trig 1");}
    case I_SIG_2:        { return String("In 2");}
    case I_TRIG_2:       { return String("Trig 2");}
    case I_SIG_3:        { return String("In 3");}
    case I_TRIG_3:       { return String("Trig 3");}
    case I_SIG_4:        { return String("In 4");}
    case I_TRIG_4:       { return String("Trig 4");}
    case I_SCALE:        { return String("Scale");}
    case I_ROOT:         { return String("Root");}
    }
    return String("unused:") + String (channelIndex + 1);
}

const String PluginProcessor::getOutputChannelName (int channelIndex) const
{

    switch (channelIndex) {
    case O_SIG_1:        { return String("Out 1");}
    case O_TRIG_1:       { return String("Trig 1");}
    case O_SIG_2:        { return String("Out 2");}
    case O_TRIG_2:       { return String("Trig 2");}
    case O_SIG_3:        { return String("Out 3");}
    case O_TRIG_3:       { return String("Trig 3");}
    case O_SIG_4:        { return String("Out 4");}
    case O_TRIG_4:       { return String("Trig 4");}
    case O_SCALE:        { return String("Scale");}
    case O_ROOT:         { return String("Root");}
    }
    return String("unused:") + String (channelIndex + 1);
}

bool PluginProcessor::isInputChannelStereoPair (int index) const
{
    return false;
}

bool PluginProcessor::isOutputChannelStereoPair (int index) const
{
    return false;
}

bool PluginProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
    return true;
#else
    return false;
#endif
}

bool PluginProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
    return true;
#else
    return false;
#endif
}

bool PluginProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double PluginProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int PluginProcessor::getNumPrograms()
{
    return 1;
}

int PluginProcessor::getCurrentProgram()
{
    // SSP queries what program is currently loaded
    return 0;
}

void PluginProcessor::setCurrentProgram (int index)
{
}

const String PluginProcessor::getProgramName (int index)
{
    return String("");
}

void PluginProcessor::changeProgramName (int index, const String& newName)
{
    // SSP - not using
}

void PluginProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    // this is called by the SSP's software right after loading
    // the plugin and before it starts calling processBlock below
}

void PluginProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

float PluginProcessor::processCV(float v, float scale, float root) {
    if (quant_) {
        constexpr float halfSemi = 0.5;
        constexpr bool roundUp = true;
        // cv2pitch, returns fractional semitones e.g 24.0 = C2
        float voct = cv2Pitch(v) + 60.f + (roundUp ? halfSemi : 0.0f); // -5v = 0

        int oct = voct / 12;
        unsigned note = unsigned(voct) % MAX_TONICS;
        // Logger::writeToLog("float " + String(v) + " voct " + String(voct) + " oct " + String(oct) + " note " + String(note));

        quantizer_.quantize(root_, scale_, oct, note);

        float pv = float(oct * 12.0f) + float(note) - 60.0f ;
        float qv = pitch2Cv(pv);
        return qv;
    }
    return v;
}


void PluginProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    unsigned n = buffer.getNumSamples();

    bool inTrigE[MAX_SIG];
    bool inCvE[MAX_SIG];
    bool outTrigE[MAX_SIG];
    bool outCvE[MAX_SIG];

    for (unsigned i = 0; i < MAX_SIG; i++) {
        unsigned sigo = i * 2;
        inTrigE[i] = params_[Percussa::sspInEn1 + I_TRIG_1 + sigo] > 0.5f;
        inCvE[i] = params_[Percussa::sspInEn1 + I_SIG_1 + sigo] > 0.5f;
        outTrigE[i] = params_[Percussa::sspOutEn1 + O_SIG_1 + sigo] > 0.5f;
        outCvE[i] = params_[Percussa::sspOutEn1 + O_TRIG_1 + sigo] > 0.5f;
    }


    for (unsigned idx = 0; idx < n; idx++) {
        // for each sample
        bool trigAbove = false;
        bool trig[MAX_SIG];
        for (unsigned i = 0; i < MAX_SIG; i++) {
            unsigned sigo = i * 2;
            bool trigged = false;
            if (inTrigE[i]) {
                // trig in enabled

                trig[i] = buffer.getSample(I_TRIG_1 + sigo , idx) > 0.5f;
                if (trig[i] != lastTrig_[i] && trig[i]) {
                    trigged = true;
                    trigAbove = true;
                } else {
                    trigAbove = false;
                }
            } else {
                // trig not enabled
                if (i != 0) trig[i] = trig[i - 1];
                else trig[i] = 0;

                if (trigAbove) {
                    trigged = true;
                }
            } // if trig enabled

            if (trigged) {
                // triggered...
                float v = 0.0f;
                if (inCvE[i]) {
                    v = buffer.getSample(I_SIG_1 + sigo, idx);
                } else {
                    // no cv input... use random
                    v = (randomGen_.nextFloat() * 2.0f) - 1.0f;
                }

                float scale = scale_ + buffer.getSample(I_SCALE, idx);
                float root = root_ + buffer.getSample(I_ROOT, idx);
                v = processCV(v, scale, root);
                lastSig_[i] = v;
            } //if triggered

            lastTrig_[i] = trig[i];
            buffer.setSample(O_TRIG_1 + sigo, idx, trig[i]);
            buffer.setSample(O_SIG_1 + sigo, idx, lastSig_[i]);
        } // for sig pair
    } // for each samplle
}


bool PluginProcessor::hasEditor() const
{
    return true;
}

AudioProcessorEditor* PluginProcessor::createEditor()
{
    return new PluginEditor (*this);
}


void PluginProcessor::writeToXml(XmlElement & xml) {
    xml.setAttribute("root",  int(root_));
    xml.setAttribute("scale", int(scale_));
    xml.setAttribute("quant", bool(quant_));
}

void PluginProcessor::readFromXml(XmlElement & xml) {
    root_ = xml.getIntAttribute("root"  , 0.0f);
    scale_ = xml.getIntAttribute("scale" , 0.0f);
    quant_ = xml.getBoolAttribute("quant" , false);
}


void PluginProcessor::getStateInformation (MemoryBlock & destData)
{
    XmlElement xml(xmlTag);
    writeToXml(xml);
    copyXmlToBinary(xml, destData);
}

void PluginProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    XmlElement *pXML = getXmlFromBinary(data, sizeInBytes);
    if (pXML) {
        // auto root=pXML->getChildByName(xmlTag);
        // if(root) readFromXml(*root);
        readFromXml(*pXML);
        delete pXML;
    }
}

// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new PluginProcessor();
}



