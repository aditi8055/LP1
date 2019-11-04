#include<iostream>
#include<omp.h>
#include<stdlib.h>
#include<unistd.h>
#include<cstring>
using namespace std;

int vect1[100000],vect2[100000],n;

void serialadd()
{
int result[100000];

memset(result,0,100000);
double start=omp_get_wtime();
for(int i=0;i<10000;i++)
{
result[i]=vect1[i]+vect2[i];
}
double s1=omp_get_wtime()-start;

memset(result,0,100000);
start=omp_get_wtime();
for(int i=0;i<1000;i++)
{
result[i]=vect1[i]+vect2[i];
}
double s2=omp_get_wtime()-start;


memset(result,0,100000);
start=omp_get_wtime();
for(int i=0;i<100;i++)
{
result[i]=vect1[i]+vect2[i];
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

memset(result,0,100000);
double start=omp_get_wtime();
#pragma omp parallel for collapse(1) num_threads(t)
for(int i=0;i<10000;i++)
{
result[i]=vect1[i]+vect2[i];
}
double s1=omp_get_wtime()-start;


memset(result,0,100000);
start=omp_get_wtime();
#pragma omp parallel for collapse(1) num_threads(t)
for(int i=0;i<1000;i++)
{
result[i]=vect1[i]+vect2[i];
}
double s2=omp_get_wtime()-start;


memset(result,0,100000);
start=omp_get_wtime();
#pragma omp parallel for collapse(1) num_threads(t)
for(int i=0;i<100;i++)
{
result[i]=vect1[i]+vect2[i];
}
double s3=omp_get_wtime()-start;
cout<<"\nparallel addition :\n";
cout<<"\nFor 10000 : "<<s1;
cout<<"\nFor 1000  : "<<s2;
cout<<"\nFor 100   : "<<s3;
}


int main()
{
n=100000;
for(int i=0;i<n;i++)
{
vect1[i]=rand()%1000000;
vect2[i]=rand()%1000000;
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

