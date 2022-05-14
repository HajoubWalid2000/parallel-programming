#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>
#define NBRVAL 128


int main(int argc,char** argv)
{
int rank, code , nbrProcs ,value , sum;
code = MPI_Init(&argc,&argv);
code = MPI_Comm_size(MPI_COMM_WORLD,&nbrProcs);
code = MPI_Comm_rank(MPI_COMM_WORLD,&rank);
if(rank == 0)
{
value = 1000;
}else{
value = rank;
}

code = MPI_Reduce(&value,&sum,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
printf("Moi , Processus %d , value = %d .\n",rank,sum);


code = MPI_Finalize();

return 0;
}
