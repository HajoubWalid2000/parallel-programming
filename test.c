#include <stdio.h>
#include <mpi.h>
void main(int argc, char ** argv) {

int rang, nprocs;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rang);
  MPI_Comm_size(MPI_COMM_WORLD, &nprocs);

printf("Bonjour, je suis %d (parmi %d process)\n", rang, nprocs);

MPI_Finalize();
}
