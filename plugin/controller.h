#pragma once

#include "public.sdk/source/vst/vsteditcontroller.h"

namespace Steinberg
{
    namespace Vst
    {

        class PassThroughController : public EditController
        {
        public:
            static FUnknown *createInstance(void *);
        };

    } // namespace Vst
} // namespace Steinberg
