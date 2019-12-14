#include "config.h"
#include "funcs.h"

void pool1(hls::stream<spike>& fifo_layer1,hls::stream<spike>& fifo_pool1,data pool1[POOL_NUM_1][POOL_1][POOL_1])
{
    spike temp;
    addr row,col,l;
    while(!fifo_layer1.empty()){
        temp = fifo_layer1.read();
        l = temp.l;
        row = temp.x;
        col = temp.y;
        pool1[l][row/2][col/2] += 64;
        if(pool1[l][row/2][col/2] >= THRESHOLD)
        {
        	spike out_spike;
        	out_spike.x = row/2;
        	out_spike.y = col/2;
        	out_spike.l = l;
        	fifo_pool1.write(out_spike);
        	pool1[l][row/2][col/2] = 0;
        }
    	}
/*    if(!fifo_layer1.empty()){
        temp = fifo_layer1.read();
        l = temp.l;
        row = temp.x;
        col = temp.y;
        pool1[l][row/2][col/2] += 55;
        if(pool1[l][row/2][col/2] > THRESHOLD)
        {
        	temp.x = row/2;
        	temp.y = col/2;
        	fifo_pool1.write(temp);
        	pool1[l][row/2][col/2] = 0;
        }
    	} */
}
