#include <fstream>
#include "snn.h"
#include <iostream>
using namespace std;

bool compare(data A[],data B[])
{
	if(sizeof(A) != sizeof(B))
		return false;
	else
	{
		for(int i=0;i<sizeof(A)/sizeof(A[0]);i++)
		{
			if(A[i] != B[i])
				return false;
		}
	}
	return true;
}

int main()
{
	ifstream input;
	spike temp;
	stream<spike> instr; //snn input
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
	data res[10] = {0}; //snn output
	data cor_res[10] = {0, 0, 2, 3, 0, 0, 0, 1, 0, 0}; //correct output

	snn(instr,res);

	ofstream out; //outputs result
	out.open("output.txt",ios::out);

	if(!out){
		cout<<"can not open output"<<endl;
		exit(1);
	}
	for(int i=0;i<sizeof(res)/sizeof(res[0]);i++)
			{
				out<<res[i]<<' ';
			}
	out.close();

	return 0;



}
