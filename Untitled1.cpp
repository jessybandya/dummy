#include<iostream>
#include<cmath>

using namespace std;
float Q;
float D = 0.2023;
float R = 0.2023/2;
float sumHL1 = 0;
float sumHL1a = 0;
float del_q1 = 0;


void iteration2(float pipes_q1[]){
		cout<<"pipes1: "<<pipes_q1[0]<<endl;
}
void iteration1(){
//   iteration 1
	float hl1;
	float pipes_q1[5];
	float a;
	
for(int i=0;i<=4;++i)
{
   cout<<"Enter Flow rate for Pipe "<<i+1<<":"<<endl;
  cin>>pipes_q1[i];
  pipes_q1[i]= abs(pipes_q1[i]);
  hl1 = (R* (pow(pipes_q1[i],1.85)));
  sumHL1 = sumHL1 + hl1;
  sumHL1a = sumHL1a + ( pipes_q1[i] * 1.85 * R);
  cout<<"R: "<<sumHL1a<<endl;
  del_q1 = pipes_q1[i] + del_q1;
//  cout<<"pipes_q1: "<<pipes_q1[i]<<endl;
  
} 
 
   del_q1 = sumHL1/sumHL1a;
  cout <<"Del_Q: "<<del_q1<<endl;
//  cout <<"Pipes_q1: "<<pipes_q1[0] + sumHL1/sumHL1a<<endl;
//  cout <<"Pipes_q2: "<<pipes_q1[1]<<endl;
//  cout<<"Iteration 1"<<endl;
//  a=pipes_q1[0] + sumHL1/sumHL1a;
  cout<<"------------------------"<<endl;
  iteration2(pipes_q1);
}



int main(){
	iteration1();
}
