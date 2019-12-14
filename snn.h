#ifndef __SNN_H__
#define __SNN_H__

#include "spike.h"
#include <hls_stream.h>
using namespace hls;
void snn(stream<spike> &input,data res[FC_2_OUT]);

#endif
