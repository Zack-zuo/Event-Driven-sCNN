#include "config.h"
#include "funcs.h"

void conv2(hls::stream<spike>& fifo_pool1,hls::stream<spike>& fifo_layer2,kernel klayer2[LAYER_NUM_2][POOL_NUM_1][KERNEL_SIZE][KERNEL_SIZE],data layer2[LAYER_NUM_2][LAYER_2][LAYER_2])
{
    spike temp;
    addr row,col,l;
while(!fifo_pool1.empty()){
    temp = fifo_pool1.read();
    row = temp.x;
    col = temp.y;
    l = temp.l;
    for(addr i=0; i<KERNEL_SIZE; i++)
    {
        for(addr j=0; j<KERNEL_SIZE; j++)
        {
        	for(addr k=0;k<LAYER_NUM_2;k++)
        	{
            if((row-i>=0) && (row-i<LAYER_2) && (col-j>=0) && (col-j< LAYER_2))
            {
                layer2[k][row-i][col-j] += klayer2[k][l][i][j];
                if(layer2[k][row-i][col-j]>=THRESHOLD)
                {
                	spike out_spike;
                	out_spike.l = k;
                	out_spike.x = row-i;
                    out_spike.y = col-j;
                    fifo_layer2.write(out_spike);
                    layer2[k][row-i][col-j] = zero;
                }
            }
        	}
        }
    }
}
}
/*    for(addr i=0; i<KERNEL_SIZE; i++)
    {
        for(addr j=0; j<KERNEL_SIZE; j++)
        {
            if(row-j>=0 && row-i<=LAYER_2-1 && col-j>=0 && col-j<= LAYER_2-1)
            {
                layer2[row-i][col-j] += klayer2[i][j];
                if(layer2[row-i][col-j]>THRESHOLD)
                {
                    temp.x = row-i;
                    temp.y = col-j;
                    fifo_layer2.write(temp);
                    layer2[row-i][col-j] = 0;
                }
            }
        }
    }
    for(addr i=0; i<KERNEL_SIZE; i++)
    {
        for(addr j=0; j<KERNEL_SIZE; j++)
        {
            if(row-j>=0 && row-i<=LAYER_2-1 && col-j>=0 && col-j<= LAYER_2-1)
            {
                layer2[row-i][col-j] += klayer2[i][j];
                if(layer2[row-i][col-j]>THRESHOLD)
                {
                    temp.x = row-i;
                    temp.y = col-j;
                    fifo_layer2.write(temp);
                    layer2[row-i][col-j] = 0;
                }
            }
        }
    }
    for(addr i=0; i<KERNEL_SIZE; i++)
    {
        for(addr j=0; j<KERNEL_SIZE; j++)
        {
            if(row-j>=0 && row-i<=LAYER_2-1 && col-j>=0 && col-j<= LAYER_2-1)
            {
                layer2[row-i][col-j] += klayer2[i][j];
                if(layer2[row-i][col-j]>THRESHOLD)
                {
                    temp.x = row-i;
                    temp.y = col-j;
                    fifo_layer2.write(temp);
                    layer2[row-i][col-j] = 0;
                }
            }
        }
    }
}
    
if(!fifo_pool1.empty()){
    temp = fifo_pool1.read();
    row = temp.x;
    col = temp.y;
    for(addr i=0; i<KERNEL_SIZE; i++)
    {
        for(addr j=0; j<KERNEL_SIZE; j++)
        {
            if(row-j>=0 && row-i<=LAYER_2-1 && col-j>=0 && col-j<= LAYER_2-1)
            {
                layer2[row-i][col-j] += klayer2[i][j];
                if(layer2[row-i][col-j]>THRESHOLD)
                {
                    temp.x = row-i;
                    temp.y = col-j;
                    fifo_layer2.write(temp);
                    layer2[row-i][col-j] = 0;
                }
            }
        }
    }
    for(addr i=0; i<KERNEL_SIZE; i++)
    {
        for(addr j=0; j<KERNEL_SIZE; j++)
        {
            if(row-j>=0 && row-i<=LAYER_2-1 && col-j>=0 && col-j<= LAYER_2-1)
            {
                layer2[row-i][col-j] += klayer2[i][j];
                if(layer2[row-i][col-j]>THRESHOLD)
                {
                    temp.x = row-i;
                    temp.y = col-j;
                    fifo_layer2.write(temp);
                    layer2[row-i][col-j] = 0;
                }
            }
        }
    }
    for(addr i=0; i<KERNEL_SIZE; i++)
    {
        for(addr j=0; j<KERNEL_SIZE; j++)
        {
            if(row-j>=0 && row-i<=LAYER_2-1 && col-j>=0 && col-j<= LAYER_2-1)
            {
                layer2[row-i][col-j] += klayer2[i][j];
                if(layer2[row-i][col-j]>THRESHOLD)
                {
                    temp.x = row-i;
                    temp.y = col-j;
                    fifo_layer2.write(temp);
                    layer2[row-i][col-j] = 0;
                }
            }
        }
    }
    for(addr i=0; i<KERNEL_SIZE; i++)
    {
        for(addr j=0; j<KERNEL_SIZE; j++)
        {
            if(row-j>=0 && row-i<=LAYER_2-1 && col-j>=0 && col-j<= LAYER_2-1)
            {
                layer2[row-i][col-j] += klayer2[i][j];
                if(layer2[row-i][col-j]>THRESHOLD)
                {
                    temp.x = row-i;
                    temp.y = col-j;
                    fifo_layer2.write(temp);
                    layer2[row-i][col-j] = 0;
                }
            }
        }
    }
}
}
*/
