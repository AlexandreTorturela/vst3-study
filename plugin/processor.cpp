#include "processor.h"

using namespace Steinberg;
using namespace Steinberg::Vst;

PassThroughProcessor::PassThroughProcessor()
{
    setControllerClass(kPluginControllerUID);
}

FUnknown *PassThroughProcessor::createInstance(void *)
{
    return static_cast<IAudioProcessor *>(new PassThroughProcessor());
}

tresult PLUGIN_API PassThroughProcessor::initialize(FUnknown *context)
{
    tresult result = AudioEffect::initialize(context);
    if (result != kResultOk)
        return result;

    addAudioInput(STR16("Input"), SpeakerArr::kStereo);
    addAudioOutput(STR16("Output"), SpeakerArr::kStereo);

    return kResultOk;
}

tresult PLUGIN_API PassThroughProcessor::process(ProcessData &data)
{
    if (data.numInputs == 0 || data.numOutputs == 0)
        return kResultOk;

    auto &in = data.inputs[0];
    auto &out = data.outputs[0];

    int32 numSamples = data.numSamples;

    for (int32 ch = 0; ch < in.numChannels; ++ch)
    {
        float *inBuf = in.channelBuffers32[ch];
        float *outBuf = out.channelBuffers32[ch];

        if (!inBuf || !outBuf)
            continue;

        for (int32 i = 0; i < numSamples; ++i)
            outBuf[i] = inBuf[i];
    }

    return kResultOk;
}
