#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>
#define nbr 8

int main(int argc,char** argv)
{
int rang,tasks,i,code,nbprocs;
float * vect,*data, valeur=0;
float somme=0;
code = MPI_Init(&argc,&argv);
code = 	MPI_Comm_size(MPI_COMM_WORLD,&nbprocs);
code = MPI_Comm_rank(MPI_COMM_WORLD,&rang);
tasks = nbr / nbprocs;

data = (float*)malloc(tasks * sizeof(float));

if(rang == 0)
{
	vect = (float*)malloc(nbr * sizeof(float));
	for(i=0;i<nbr;i++)
		vect[i] = i ;
	
}

code = MPI_Scatter(vect,tasks,MPI_FLOAT,data,tasks,MPI_FLOAT,0,MPI_COMM_WORLD);

printf("id = %d , [%f,%f] . \n",rang,data[0],data[tasks-1]);
 if(rang == 0)
{
valeur = data[0] + data[tasks-1];
}else{
valeur = data[0] + data[tasks-1];
}

code = MPI_Reduce(&valeur,&somme,1,MPI_FLOAT,MPI_SUM,0,MPI_COMM_WORLD);

if(rang==0)
   printf("Moi , Processus %f , value = %f .\n",rang,somme);


code = MPI_Finalize();



return 0;
}
