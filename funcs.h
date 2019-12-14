#ifndef __FUNCS_H__
#define __FUNCS_H__

#include "config.h"
#include "spike.h"

void conv1(hls::stream<spike>& input, hls::stream<spike>& fifo_layer1, kernel klayer1[LAYER_NUM_1][INPUT_NUM][KERNEL_SIZE][KERNEL_SIZE], data layer1[LAYER_NUM_1][LAYER_1][LAYER_1]);

void conv2(hls::stream<spike>& fifo_pool1,hls::stream<spike>& fifo_layer2,kernel klayer2[LAYER_NUM_2][POOL_NUM_1][KERNEL_SIZE][KERNEL_SIZE],data layer2[LAYER_NUM_2][LAYER_2][LAYER_2]);

void fc1(hls::stream<spike>& fifo_pool2,hls::stream<addr>& vec40,kernel kvec40[FC_NUM_1][POOL_NUM_2][FC_1_IN][FC_1_OUT],data vec[FC_1_OUT]);

void fc2(hls::stream<addr>& vec40,kernel kclasses[FC_2_IN][FC_2_OUT],data fc[FC_2_OUT],data classes[FC_2_OUT]);

void pool1(hls::stream<spike>& fifo_layer1,hls::stream<spike>& fifo_pool1,data pool1[POOL_NUM_1][POOL_1][POOL_1]);

void pool2(hls::stream<spike>& fifo_layer2_a, hls::stream<spike>& fifo_pool2, data pool2[POOL_NUM_2][POOL_2][POOL_2]);

#endif
