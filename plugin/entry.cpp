#include "public.sdk/source/main/pluginfactory.h"
#include "pluginids.h"
#include "processor.h"
#include "controller.h"

#define PLUGIN_VERSION_MAJOR 1
#define PLUGIN_VERSION_MINOR 0
#define PLUGIN_VERSION_PATCH 0

#define PLUGIN_VERSION_STR "1.0.0"

using namespace Steinberg;
using namespace Steinberg::Vst;

BEGIN_FACTORY_DEF(
    "VST3 Study",
    "https://example.com",
    "contact@example.com")

DEF_CLASS2(
    INLINE_UID_FROM_FUID(kPluginProcessorUID),
    PClassInfo::kManyInstances,
    kVstAudioEffectClass,
    "PassThroughFX",
    Vst::kDistributable,
    "Fx",
    PLUGIN_VERSION_STR,
    kVstVersionString,
    PassThroughProcessor::createInstance)

DEF_CLASS2(
    INLINE_UID_FROM_FUID(kPluginControllerUID),
    PClassInfo::kManyInstances,
    kVstComponentControllerClass,
    "PassThroughFXController",
    0,
    "",
    PLUGIN_VERSION_STR,
    kVstVersionString,
    PassThroughController::createInstance)

END_FACTORY
