#include "mpi.h"
#include<stdio.h>
#include<string.h>
int main(int argc,char*argv[])
{
	
	char message[24];
	int myrank;
	MPI_Status status;
	int TAG=0;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&myrank);
	if(myrank==0)
	{
		strcpy(message,"Hi,Parallel Programmer!");
		MPI_Send(&message,24,MPI_CHAR,1,TAG,MPI_COMM_WORLD);

	}
	else
	{
        MPI_Recv(&message,24,MPI_CHAR,0,TAG,MPI_COMM_WORLD,&status);  
		printf("received:%s\n",message);

	}
MPI_Finalize();
return 0;
}