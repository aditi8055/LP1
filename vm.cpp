#include<iostream>
#include<omp.h>
#include<stdlib.h>
#include<unistd.h>
#include<cstring>
using namespace std;

int vect1[10000],mat[10000][10000],n;

void serialadd()
{
int result[10000];

memset(result,0,10000);
double start=omp_get_wtime();
for(int i=0;i<10000;i++)
{
for(int j=0;j<10000;j++)
{
result[i]+=mat[j][i]*vect1[i];
}
}
double s1=omp_get_wtime()-start;

memset(result,0,10000);
start=omp_get_wtime();
for(int i=0;i<1000;i++)
{
for(int j=0;j<1000;j++)
{
result[i]+=mat[j][i]*vect1[i];
}
}
double s2=omp_get_wtime()-start;


memset(result,0,10000);
start=omp_get_wtime();
for(int i=0;i<100;i++)
{
for(int j=0;j<100;j++)
{
result[i]+=mat[j][i]*vect1[i];
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
int result[100000];


memset(result,0,10000);
double start=omp_get_wtime();
#pragma omp parallel for collapse(2) num_threads(t)
for(int i=0;i<10000;i++)
{
for(int j=0;j<10000;j++)
{
result[i]+=mat[j][i]*vect1[i];
}
}
double s1=omp_get_wtime()-start;

memset(result,0,10000);
start=omp_get_wtime();
#pragma omp parallel for collapse(2) num_threads(t)
for(int i=0;i<1000;i++)
{
for(int j=0;j<1000;j++)
{
result[i]+=mat[j][i]*vect1[i];
}
}
double s2=omp_get_wtime()-start;


memset(result,0,10000);
start=omp_get_wtime();
#pragma omp parallel for collapse(2) num_threads(t)
for(int i=0;i<100;i++)
{
for(int j=0;j<100;j++)
{
result[i]+=mat[j][i]*vect1[i];
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
n=10000;
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
mat[i][j]=rand()%1000000;
}
vect1[i]=rand()%1000000;
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

