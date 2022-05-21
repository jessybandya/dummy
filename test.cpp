#include <iostream>
#include <cmath>
using namespace std;

float Q;
float D = 202.3;
float R = 202.3/2;


void iteration1(){
	float hl;
	float pipes_q;
	float sumHL = 0;
	float sumHL1 = 0;
	//	2*R*Q

	for(int i=0;i<=4;++i){
   cout<<"Enter Flow rate for Pipe "<<i+1<<endl;
  cin>>pipes_q;
  hl = (R* (pow(pipes_q,1.85)));
  sumHL = sumHL + hl;
  sumHL1 = sumHL1 + (2*R*pipes_q);
}
  cout<<"Head Loss Summation: "<<sumHL<<endl;
  cout<<"Summation: "<<sumHL1<<endl;  
  cout <<"Del_Q: "<<sumHL/sumHL1<<endl;
  cout<<"Iteration 1"<<endl;

}

void iteration2(){
	float hl;
	int pipes_q;
	float sumHL = 0;
	float sumHL1 = 0;
	float pipes_q1;
	//	2*R*Q

	for(int i=0;i<=4;++i){
   cout<<"Enter Flow rate for Pipe "<<i+1<<endl;
  cin>>pipes_q;
  hl = (R* (pow(pipes_q,2)));
  sumHL = sumHL + hl;
  sumHL1 = sumHL1 + (2*R*pipes_q);
}
//  cout<<"Head Loss Summation: "<<sumHL<<endl;
//  cout<<"Summation: "<<sumHL1<<endl;  
  cout <<"Del_Q: "<<sumHL/sumHL1<<endl;
  pipes_q1 = pipes_q - (sumHL/sumHL1);
  
    hl = (R* (pow(pipes_q1,2)));
  sumHL = sumHL + hl;
  sumHL1 = sumHL1 + (2*R*pipes_q1);
  
  
    cout <<"Del_Q1: "<<sumHL/sumHL1<<endl;


}

void loop1(){
	int ch;
	
	cout<<"Select Iteration"<<endl;
	cout<<"------------------------"<<endl;
	cout<<"1. Iteration 1"<<endl;
	cout<<"2. Iteration 2"<<endl;
	cout<<"3. Iteration 3"<<endl;
	cout<<"4. Iteration 4"<<endl;
	cout<<"5. Iteration 5"<<endl;
	cout<<"6. Iteration 6"<<endl;
	cout<<"7. Iteration 7"<<endl;
	cout<<"8. Iteration 8"<<endl;
	cout<<"9. Iteration 9"<<endl;
	cin>>ch;
	
	switch(ch){
		case 1:
		iteration1();
		break;
		case 2:
		iteration2();
		break;
		
		default:
		cout<<"Invalid Input!"<<endl;	
	}
	

  
  
  

}
void loop2(){
	
}
void loop3(){
	
}

int main(){
	loop1();
}
