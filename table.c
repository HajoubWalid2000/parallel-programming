#include<stdio.h>
#include<mpi.h>
#include<stdlib.h>
#define N 10

int main(int argc , char** argv)
{
	int rang,*tab,i,code;
	const int etiquette = 100;
	tab = (int*)malloc(N * sizeof(int)); 	
	MPI_Status status; 
	code = MPI_Init(&argc,&argv);
	code = MPI_Comm_rank(MPI_COMM_WORLD,&rang);
	if(rang == 1)
	{
	code = MPI_Send(tab,N,MPI_INT,3,etiquette,MPI_COMM_WORLD);
	//Wait	
	code = MPI_Recv(tab,N,MPI_INT,3,etiquette,MPI_COMM_WORLD,&status);
	printf("Table recu par processus 3 est : \n");
	for(i=0;i<N;i++)
	{
		printf("%d\t",*(tab+i));	
	}	
	printf("\n");
	}else if(rang == 3){
	code = MPI_Recv(tab,N,MPI_INT,1,etiquette,MPI_COMM_WORLD,&status);
	for(i=0;i<N;i++)
	{
		*(tab+i) = i;	
	}	
	code = MPI_Send(tab,N,MPI_INT,1,etiquette,MPI_COMM_WORLD);
	}	
	MPI_Finalize();
	return 0;
}



