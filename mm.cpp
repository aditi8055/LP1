#include<iostream>
#include<omp.h>
#include<stdlib.h>
#include<unistd.h>
#include<cstring>
using namespace std;

int mat1[1000][1000],mat2[1000][1000],n;

void serialadd()
{
int result[1000][1000];

memset(result,0,sizeof(result[0][0]*1e6));
double start=omp_get_wtime();
for(int i=0;i<1000;i++)
{
for(int j=0;j<1000;j++)
{
for(int k=0;k<1000;k++)
{
result[i][j]+=mat1[i][k]*mat2[k][j];
}
}
}
double s1=omp_get_wtime()-start;

memset(result,0,sizeof(result[0][0]*1e6));
start=omp_get_wtime();
for(int i=0;i<100;i++)
{
for(int j=0;j<100;j++)
{
for(int k=0;k<100;k++)
{
result[i][j]+=mat1[i][k]*mat2[k][j];
}
}
}
double s2=omp_get_wtime()-start;

memset(result,0,sizeof(result[0][0]*1e6));
start=omp_get_wtime();
for(int i=0;i<10;i++)
{
for(int j=0;j<10;j++)
{
for(int k=0;k<10;k++)
{
result[i][j]+=mat1[i][k]*mat2[k][j];
}
}
}
double s3=omp_get_wtime()-start;


cout<<"\nSerial addition :\n";
cout<<"\nFor 10000 : "<<s1;
cout<<"\nFor 1000  : "<<s2;
cout<<"\nFor 100   : "<<s3;
}

void paradd(int t)
{
int result[1000][1000];


memset(result,0,sizeof(result[0][0]*1e6));
double start=omp_get_wtime();
#pragma omp parallel for collapse(3) num_threads(t)
for(int i=0;i<1000;i++)
{
for(int j=0;j<1000;j++)
{
for(int k=0;k<1000;k++)
{
result[i][j]+=mat1[i][k]*mat2[k][j];
}
}
}
double s1=omp_get_wtime()-start;

memset(result,0,sizeof(result[0][0]*1e6));
start=omp_get_wtime();
#pragma omp parallel for collapse(3) num_threads(t)
for(int i=0;i<100;i++)
{
for(int j=0;j<100;j++)
{
for(int k=0;k<100;k++)
{
result[i][j]+=mat1[i][k]*mat2[k][j];
}
}
}
double s2=omp_get_wtime()-start;

memset(result,0,sizeof(result[0][0]*1e6));
start=omp_get_wtime();
#pragma omp parallel for collapse(3) num_threads(t)
for(int i=0;i<10;i++)
{
for(int j=0;j<10;j++)
{
for(int k=0;k<10;k++)
{
result[i][j]+=mat1[i][k]*mat2[k][j];
}
}
}
double s3=omp_get_wtime()-start;


cout<<"\nSerial addition :\n";
cout<<"\nFor 10000 : "<<s1;
cout<<"\nFor 1000  : "<<s2;
cout<<"\nFor 100   : "<<s3;
}


int main()
{
n=1000;
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
mat1[i][j]=rand()%1000000;

mat2[i][j]=rand()%1000000;
}

int choice;
do
{
cout<<"\nEnter choice:\n1.serial addition\n2.parallel addition\n3.exit\n";
cin>>choice;
if(choice==1)
serialadd();
else if(choice==2)
{
cout<<"\nparallel n=2 \n";paradd(2);
cout<<"\nparallel n=3 \n";paradd(3);
cout<<"\nparallel n=4 \n";paradd(4);
}
else
{
break;
}
}while(choice!=0);
}
}

