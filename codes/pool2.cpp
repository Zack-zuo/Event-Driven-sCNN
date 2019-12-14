 #include "config.h"
 #include "funcs.h"
 
 void pool2(hls::stream<spike>& fifo_layer2, hls::stream<spike>& fifo_pool2, data pool2[POOL_NUM_2][POOL_2][POOL_2])
 {
     spike temp;
     addr row;
     addr col;
     addr l;
     while(!fifo_layer2.empty()){
         temp = fifo_layer2.read();
         l = temp.l;
         row = temp.x;
         col = temp.y;
         pool2[l][row/2][col/2] += 64;
         if(pool2[l][row/2][col/2] >= THRESHOLD)
         {
        	 spike out_spike;
        	 out_spike.l = l;
        	 out_spike.x = row/2;
        	 out_spike.y = col/2;
        	 fifo_pool2.write(out_spike);
        	 pool2[l][row/2][col/2] = 0;
         }
     	 }
 }
 /*    if(!fifo_layer2_b.empty()){
         temp = fifo_layer2_b.read();
     row = temp.x;
     col = temp.y;
     pool2_b[row/2][col/2] += 55;
     if(pool2_b[row/2][col/2] > THRESHOLD)
     {
         temp.x = row/2;
         temp.y = col/2;
         fifo_pool2_b.write(temp);
         pool2_b[row/2][col/2] = 0;
     }
     }
     if(!fifo_layer2_c.empty()){
         temp = fifo_layer2_c.read();
     row = temp.x;
     col = temp.y;
     pool2_a[row/2][col/2] += 55;
     if(pool2_c[row/2][col/2] > THRESHOLD)
     {
         temp.x = row/2;
         temp.y = col/2;
         fifo_pool2_c.write(temp);
         pool2_c[row/2][col/2] = 0;
     }
     }
     if(!fifo_layer2_d.empty()){
         temp = fifo_layer2_d.read();
     row = temp.x;
     col = temp.y;
     pool2_d[row/2][col/2] += 55;
     if(pool2_d[row/2][col/2] > THRESHOLD)
     {
         temp.x = row/2;
         temp.y = col/2;
         fifo_pool2_d.write(temp);
         pool2_d[row/2][col/2] = 0;
     }
     }

 }*/
