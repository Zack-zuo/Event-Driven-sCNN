#include "snn.h"
#include <queue>
#include <fstream>
#include <iostream>

using namespace std;
using namespace hls;

int main()
{
	ifstream input;
	spike temp;
	stream<spike> instr;  //input
	stream<spike> outstr;  //output

	input.open("input.txt",ios::in);

	if(!input){
		cout<<"can't open input"<<endl;
		exit(1);
	}
	while(!input.eof()){
		input >> temp.l;
		input >> temp.x;
		input >> temp.y;
		instr << temp;
	}
	input.close();      //input

	snn(instr,outstr);  //go through the network

	ofstream st_out;
	st_out.open("layer2.txt",ios::out);
	if(!st_out){
		cout<<"can't open layer"<<endl;
		exit(1);
	}

		while(!outstr.empty()){
			spike out ;
			outstr >> out;
			st_out << out.l  << ' ';
			st_out << out.x <<' ';
			st_out << out.y << ' '<< '\n' ;
		}

	st_out.close();
	/*data layer1[LAYER_NUM_1][LAYER_1][LAYER_1]={zero};
	snn(instr,outstr,layer1);
	spike a;
	spike b;
	int score = 0;
	queue<spike> not_equal;
	while(!(outstr.empty()||stand.empty())){
		a = outstr.read();
		b = stand.front();
		stand.pop();
		not_equal.push(a);
	//	if((a.l==b.l)&&(a.x==b.x)&&(a.y==b.y)){
	//		score += 1;
			//not_equal.push(b);
	//	}
	}
	ofstream res;
	res.open("result.txt",ios::out);
	if(!res)
	{
		cout<<"not open res"<<endl;
	}
	while(!not_equal.empty())
		{
			temp = not_equal.front();
			not_equal.pop();
			res << temp.l << ' ' <<temp.x<<' '<<temp.y<<endl;
		}
	res.close();
	//output V of layer1
	ofstream outV;
	outV.open("layer1.txt",ios::out);
		if(!outV)
		{
			cout<<"not open outV"<<endl;
		}
	for(addr i=0;i<LAYER_NUM_1;i++)
	{
		for(addr j=0;j<LAYER_1;j++)
		{
			for(addr k=0;k<LAYER_1;k++)
			{
				outV << layer1[i][j][k];
				outV << ' ';
			}
			outV << endl;
		}
		outV << endl;
	}
	outV.close();*/
	return 0;

}
