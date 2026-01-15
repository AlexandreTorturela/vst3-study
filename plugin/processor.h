#pragma once

#include "public.sdk/source/vst/vstaudioeffect.h"
#include "pluginids.h"

namespace Steinberg
{
    namespace Vst
    {

        class PassThroughProcessor : public AudioEffect
        {
        public:
            PassThroughProcessor();

            static FUnknown *createInstance(void *);

            tresult PLUGIN_API initialize(FUnknown *context) override;
            tresult PLUGIN_API process(ProcessData &data) override;
        };

    } // namespace Vst
} // namespace Steinberg
