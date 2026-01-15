#include "controller.h"

using namespace Steinberg;
using namespace Steinberg::Vst;

FUnknown *PassThroughController::createInstance(void *)
{
    return static_cast<IEditController *>(new PassThroughController());
}
