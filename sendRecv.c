
#include<stdio.h>
#include<mpi.h>


int main(int argc , char** argv)
{
	int rang,valeur=0,code;
	const int etiquette = 100; // crée tag
	int resultat;  
	MPI_Status status;  // crée status
	code = MPI_Init(&argc,&argv);  // debut MPI
	
	code = MPI_Comm_rank(MPI_COMM_WORLD,&rang); // recuperer rang
	if(rang == 1)
	{
	valeur= 1000;
	code = MPI_Send(&valeur,1,MPI_INT,3,etiquette,MPI_COMM_WORLD);
	   								// traitement process 1
	code = MPI_Recv(&resultat,1,MPI_INT,3,etiquette,MPI_COMM_WORLD,&status);
	printf("le resultat recu est : %d \n",resultat);
	
	}else if(rang == 3){
	code = MPI_Recv(&valeur,1,MPI_INT,1,etiquette,MPI_COMM_WORLD,&status);		// traitement process 2
	printf("process with id = 3 , i received this value %d ...\n",valeur);
	valeur = valeur * 3;
	code = MPI_Send(&valeur,1,MPI_INT,1,etiquette,MPI_COMM_WORLD);
	}	
	MPI_Finalize();
	return 0;
}

