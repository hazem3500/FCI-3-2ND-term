/* C Example */
#include <mpi.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int rank, size, tag = 0;
    char message[100];
    MPI_Status status;

    MPI_Init(&argc, &argv);               /* starts MPI */
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); /* get current process id */
    MPI_Comm_size(MPI_COMM_WORLD, &size); /* get number of processes */
    sprintf(message, "Hello world from process %d of %d\n", rank + 1, size);
    if (rank != 0)
    {
        MPI_Send(message, strlen(message) + 1, MPI_CHAR, 0, tag, MPI_COMM_WORLD);
    }
    else
    {
        for (int i = 1; i < size; i++)
        {
            MPI_Recv(message, 100, MPI_CHAR, i, tag, MPI_COMM_WORLD, &status);
            printf("%s", message);
        }
    }
    MPI_Finalize();
    return 0;
}