#include "mpi.h"
#include <stdlib.h>
#include <stdio.h>

int main( int argc , char * argv[]){
int rang, valeur=14;
MPI_Init (&argc ,&argv);
MPI_Comm_rank ( MPI_COMM_WORLD , &rang);
if (rang == 2)
   valeur += 1;
   MPI_Bcast (&valeur,1, MPI_INT ,2, MPI_COMM_WORLD);

printf("Moi, processus %d, j’ai recu %d du processus 2 \n",rang ,valeur);
MPI_Finalize ();
return(0);
}
