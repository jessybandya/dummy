#include <iostream>
#include <conio.h>
#include <math.h>
#include <iomanip>
using namespace std;
const float PI=3.141592653589793238463;
const float n=1.85;
float pipel[2][4];
float piped[2][4];
float pipeqass[2][4];
float velocity[2][4];
float hf[2][4];
float hfbyq[2][4];
float delq[2][4];
float delq1;
float delq2;
float qdash[2][4];
float sighf[2]={0,0};
float sighfbyq[2]={0,0};
int common[2][4];
float qpn;
float dp4;
float cpn;


float area(float dia)
{
return PI*dia*dia/4;
}

void firstForLoop(){
	for(int i=0;i<2;++i)
{
cout<<"\nENTER THE VALUES OF PIPE IN LOOP"<<i+1;
for(int j=0;j<4;++j)
{
cout<<"\nPIPE NO"<<j+1;
cout<<"\nPIPE LENGTH(in m):";
cin>>pipel[i][j];
cout<<"\nPIPE DIAMETER(in mm):";
cin>>piped[i][j];
cout<<"\nIS IT A COMMON PIPE?(1-YES,0-NO)";
cin>>common[i][j];
cout<<"\nFIRST ASSUMED VALUE OF Q(in m^3/min)";
cin>>pipeqass[i][j];
velocity[i][j]=(pipeqass[i][j]/60)/area(piped[i][j]/1000);
qpn=pow(pipeqass[i][j]/60,n);
if(pipeqass[i][j]>=0)
{
dp4=pow(piped[i][j]/1000,4.87);
cpn=pow(100,n);
hf[i][j]=10.622*(pipel[i][j])*(qpn)/(cpn*dp4);
hfbyq[i][j]=hf[i][j]/pipeqass[i][j];
if(i==0)
{
sighf[0]+=hf[i][j];
sighfbyq[0]+=hfbyq[i][j];
}
if(i==1)
{
sighf[1]+=hf[i][j];
sighfbyq[1]+=hfbyq[i][j];
}
}
else
{
dp4=pow(-piped[i][j]/1000,4.87);
cpn=pow(100,n);
hf[i][j]=10.622*(pipel[i][j])*(qpn)/(cpn*dp4);
hfbyq[i][j]=hf[i][j]/pipeqass[i][j];
if(i==0)
{

sighf[0]+=hf[i][j];
sighfbyq[0]+=hfbyq[i][j];
}
if(i==1)
{
sighf[1]+=hf[i][j];
sighfbyq[1]+=hfbyq[i][j];
}
}
}
delq1=-sighf[0]/(n*sighfbyq[0]);
delq2=-sighf[1]/(n*sighfbyq[1]);
}
}


int main()
{


firstForLoop();

for(int i=0;i<2;++i)
{
for(int j=0;j<4;++j)
{
if(i==0)
delq[i][j]=delq1;
if(i==1)
delq[i][j]=delq2;
}
}
for(int i=0;i<2;++i)
{
for(int j=0;j<4;++j)
{
if(common[i][j])
{
if(i==0)
delq[i][j]=delq1-delq2;
if(i==1)
delq[i][j]=delq2-delq1;
}
}
}
for(int i=0;i<2;++i)
{
for(int j=0;j<4;++j)
{
qdash[i][j]=pipeqass[i][j]+delq[i][j];
}
}
cout<<"\n\n\nITERATION 1\n\n";
cout<<"SNO LEN(m) DIA(mm) C ASSQ(m^3/min) ASSQ(m^3/s) velocity(m/s) Hf(m) Hf/Q(m/m^3/min) delq(m^3/min) qdash(m^3/min)";
for(int i=0;i<2;++i)
{
cout<<"\n";
for(int j=0;j<4;++j)
{
cout<<i+1<<" "<<pipel[i][j]<<" "<<piped[i][j]<<" "<<100<<" ";
std::cout<<std::setprecision(4)<<pipeqass[i][j]<<" "<<pipeqass[i][j]/60<<" "<<velocity[i][j]<<" "<<hf[i][j]<<" "<<hfbyq[i][j]<<" "<<delq[i][j
]<<" "<<qdash[i][j];
}
}
getch();

}
