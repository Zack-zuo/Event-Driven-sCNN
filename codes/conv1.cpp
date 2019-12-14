#include "config.h"
#include "funcs.h"

void conv1(hls::stream<spike>& input, hls::stream<spike>& fifo_layer1, kernel klayer1[LAYER_NUM_1][INPUT_NUM][KERNEL_SIZE][KERNEL_SIZE], data layer1[LAYER_NUM_1][LAYER_1][LAYER_1])
{
    spike temp;
    addr l,row,col;
while(!input.empty()){
    temp = input.read();
    l = temp.l;
    row = temp.x;
    col = temp.y;
    conv1_label1:for(addr i=0; i<KERNEL_SIZE; i++)
    {
        conv1_label2:for(addr j=0; j<KERNEL_SIZE; j++)
        {
        	conv1_label3:for (addr k = 0; k < LAYER_NUM_1; k ++)
        	{
				if((row-i>=0) && (row-i<LAYER_1) && (col-j>=0) && (col-j< LAYER_1))
				{
					layer1[k][row-i][col-j] += klayer1[k][l][i][j];
					if(layer1[k][row-i][col-j]>=THRESHOLD)
					{
						spike output_spike;
						output_spike.l = k;
						output_spike.x = row-i;
						output_spike.y = col-j;
						fifo_layer1.write(output_spike);
						layer1[k][row-i][col-j] = zero;
					}
				}
        	}
        }
    }
}
}
