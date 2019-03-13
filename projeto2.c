#include <sys/time.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdio.h>
#include <sys/wait.h>
#include <sys/resource.h>

int main() 
{ 
    long int i;
    int x;
    double tempo_bloco; 

    FILE *file = fopen("testeAtividade2.csv", "a");
 
    for (x=0;x<100;x++) {
        if (fork()==0) {
    		struct timeval start, end; 
 
    		gettimeofday(&start, NULL); 
    		
    		int prioridade;
			if (i < 33) {
				prioridade = setpriority(PRIO_PROCESS, getpid(), 19);
			} else if (i > 66) {
				prioridade = setpriority(PRIO_PROCESS, getpid(), -20);
			}
 
            for (i=0; i<100000000L; i++)  {  // loop de interesse
                } 
    		gettimeofday(&end, NULL);   
 
    		tempo_bloco = (end.tv_sec - start.tv_sec) * 1e6; 
    		tempo_bloco = (tempo_bloco + (end.tv_usec - start.tv_usec)) * 1e-6; 
    		printf("Processo, %d, tempo, %lf\n", x, tempo_bloco);
			
			int get_prioridade = getpriority(PRIO_PROCESS, getpid());

    		fprintf(file, "Processo, %d, tempo, %lf, Prioridade,%d\n", x, tempo_bloco,prioridade);
    		
    		return 0; 
    	}
    }
    fprintf(file, "==============================\n");
    fclose(file);
}
