#ifndef __CONFIG_H__
#define __CONFIG_H__
#include <ap_int.h>
#include <hls_stream.h>
using namespace std;

//data type
typedef short data;
typedef short addr;
typedef short kernel;

//constants
const addr KERNEL_SIZE = 5;
const addr INPUT_NUM = 1;
const addr LAYER_1 = 24;
const addr LAYER_NUM_1 = 2;
const addr POOL_1 = LAYER_1 / 2;
const addr POOL_NUM_1 = LAYER_NUM_1;
const addr LAYER_2 = POOL_1 - KERNEL_SIZE + 1;
const addr LAYER_NUM_2 = 4;
const addr POOL_2 = LAYER_2 / 2;
const addr POOL_NUM_2 =  LAYER_NUM_2;
const addr FC_1_IN = POOL_2 * POOL_2;
const addr FC_1_OUT = 40;
const addr FC_NUM_1 = 1;
const addr FC_2_IN = FC_1_OUT;
const addr FC_2_OUT = 10;
const data THRESHOLD = 255;
const data zero = 0;



#endif
