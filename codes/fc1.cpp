#include "config.h"
#include "funcs.h"
 
void fc1(hls::stream<spike>& fifo_pool2,hls::stream<addr>& vec40,kernel kvec40[FC_NUM_1][POOL_NUM_2][FC_1_IN][FC_1_OUT],data vec[FC_1_OUT])
 {
     spike temp;
     addr row;
     addr col;
     addr l;
     while(!fifo_pool2.empty()){
         temp = fifo_pool2.read();
         l = temp.l;
         row = temp.x;
         col = temp.y;
         for(addr i=0;i<FC_1_OUT;i++)
         {
        	 for(addr j=0;j<FC_NUM_1;j++)
        	 {
        		 vec[i] += kvec40[j][l][row*4+col][i];
        		 if(vec[i] >= THRESHOLD)
        		 {
        			 vec40.write(i);
        			 vec[i] = 0;
        		 }
        	 }
         }
     }
 }
/*     if(!fifo_pool2_b.empty()){
         temp = fifo_pool2_b.read();
     row = temp.x;
     col = temp.y;
     for(int i=0;i<=FC_1_OUT-1;i++)
     {
         vec[i] += kvec40_b[row*4+col][i];
         if(vec[i] > THRESHOLD)
         {
             vec40.write(i);
             vec[i] = 0;
         }
     }
     }

     if(!fifo_pool2_c.empty()){
         temp = fifo_pool2_c.read();
     row = temp.x;
     col = temp.y;
     for(int i=0;i<=FC_1_OUT-1;i++)
     {
         vec[i] += kvec40_c[row*4+col][i];
         if(vec[i] > THRESHOLD)
         {
             vec40.write(i);
             vec[i] = 0;
         }
     }
     }
     
     if(!fifo_pool2_d.empty()){
         temp = fifo_pool2_d.read();
     row = temp.x;
     col = temp.y;
     for(int i=0;i<=FC_1_OUT-1;i++)
     {
         vec[i] += kvec40_d[row*4+col][i];
         if(vec[i] > THRESHOLD)
         {
             vec40.write(i);
             vec[i] = 0;
         }
     }
     }
 }
*/
