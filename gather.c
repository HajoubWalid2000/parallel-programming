#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>
#define nbr 128 

int main(int argc,char** argv)
{
int rang,tasks,i,code,nbprocs;
float * vect,*data;
code = MPI_Init(&argc,&argv);
code = 	MPI_Comm_size(MPI_COMM_WORLD,&nbprocs);
code = MPI_Comm_rank(MPI_COMM_WORLD,&rang);
tasks = nbr / nbprocs;

data = (float*)malloc(tasks * sizeof(float));
vect = (float*)malloc(nbr * sizeof(float));
for(i=0;i<tasks;i++)
{
  data[i] = 1000 + rang*tasks;
}
code = MPI_Gather(data,tasks,MPI_FLOAT,vect,tasks,MPI_FLOAT,2,MPI_COMM_WORLD);
if(rang == 2)
{
	printf("id = %d , [%.0f,%.0f,%.0f,%.0f] . \n",rang,vect[0],vect[tasks],vect[2*tasks],vect[3*tasks]);	
}

MPI_Finalize();
return 0;
}
