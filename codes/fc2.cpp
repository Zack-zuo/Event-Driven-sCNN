#include "config.h"
#include "funcs.h"

void fc2(hls::stream<addr>& vec40,kernel kclasses[FC_2_IN][FC_2_OUT],data fc[FC_2_OUT],data classes[FC_2_OUT])
{
    addr temp;
    while(!vec40.empty()){
        temp = vec40.read();
    for(addr i=0;i<FC_2_OUT;i++)
    {
        fc[i] += kclasses[temp][i];
        if(fc[i]>=THRESHOLD)
        {
            classes[i] += 1;
            fc[i] = 0;
        }
    }
    }
}
