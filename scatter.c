#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>
#define nbr 8

int main(int argc,char** argv)
{
int rang,tasks,i,code,nbprocs;   // declaration variable et tableau
float * vect,*data;

code = MPI_Init(&argc,&argv); // debut MPI

code = 	MPI_Comm_size(MPI_COMM_WORLD,&nbprocs); // nbr processeur
code = MPI_Comm_rank(MPI_COMM_WORLD,&rang);     // le rang

tasks = nbr / nbprocs; //nombre element stocker chaque processeur // Tache
 
data = (float*)malloc(tasks * sizeof(float));

if(rang == 2)
{
	vect = (float*)malloc(nbr * sizeof(float));     // initialser tableau process 2
	for(i=0;i<nbr;i++)
		vect[i] = i ;
}

code = MPI_Scatter(vect,tasks,MPI_FLOAT,data,tasks,MPI_FLOAT,2,MPI_COMM_WORLD);  // distribusion 
printf("id = %d , [%f,%f] . \n",rang,data[0],data[tasks-1]);


MPI_Finalize();
return 0;
}
