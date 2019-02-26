//Modificado de https://www.geeksforgeeks.org/measure-execution-time-with-high-precision-in-c-c/
#include <sys/time.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdio.h>
 
 
int main() 
{ 
    long int i;
    int x;
    double tempo_bloco; 

    FILE *file = fopen("teste.csv", "w");
 
    for (x=0;x<100;x++) {
    	if (fork()==0) {
    		struct timeval start, end; 
 
    		gettimeofday(&start, NULL); 
 
                for (i=0; i<10000000000L; i++)  {  // loop de interesse
                } 
    		gettimeofday(&end, NULL);   
 
    		tempo_bloco = (end.tv_sec - start.tv_sec) * 1e6; 
    		tempo_bloco = (tempo_bloco + (end.tv_usec -  
                              start.tv_usec)) * 1e-6; 
 
    		printf("Tempo = %lf\n", tempo_bloco);

    		fprintf(file, "Processo, %d, tempo, %lf\n", x, tempo_bloco);

    		return 0; 
    	}
    }
    fclose(file);
 
}
