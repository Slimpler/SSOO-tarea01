#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

void signal_handler(int signal_num)		//Manejo de la signal ctrl+c (SIGINT)
{										
	
	static int intentos = 0;			//Se utiliza para controlar la cantidad de veces se presiona el ctrl+c
	intentos++;						
	printf("\n");
	if(intentos == 2){					//Limita la señal SIGINT a dos para finalizar la ejecucion
		exit(signal_num);				//Finaliza la ejecucion
	}
}

void signal_sigusr1(int sig)								//Manejo de la signal SIGUSR1
{
    printf("Signal SIGUSR1 recibida: ");					//Impresion por pantalla
    
    time_t tiempo = time(0);								//Obteniendo la hora del sistema para 
    struct tm *tlocal = localtime(&tiempo);					//ser impresa por pantalla
    char output[128];										
    strftime(output,128,"%a %b  %d %X %Z %Y\n",tlocal);
    printf("%s",output);   
    return 0;
}

int main(void)													//Funcion principal main()
{
    printf("Programa hora ejecutandose. PID=%i.\n", getpid());	//Impresion por pantalla
    printf("Listo para recibir la signal SIGUSR1.\n");
    
    signal(SIGUSR1, &signal_sigusr1);							//Llamada a la funcion signal_sigusr1
    signal(SIGINT, &signal_handler);							//Llamada a la funcion signal_handler
    
    while(1);													//Se mantiene la ejecucion a la espera de las señales
    return 0;
}
