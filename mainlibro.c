#include <stdio.h>
#include <assert.h>
#include <pthread.h>
#include <sys/time.h>
//#include "counter_wo_locks.h"
//#include "counter_locks.h"
#include "libro29_4.h"
//crea N numeros de hilos
#define N_THREADS 6//define una constante de C del preprocesador, cambia el valor por un 6

volatile counter_t my_counter;//declaro my_counter es volati informa que eso va a ser usado por varios hilos a la vez

void* my_thread(void* arg){//funcion que ejecuta todos los hilos
  
  int id = (int) arg; //declaro variable tipo Id
  printf("la variable Id es: %d \n", id);
  
  int i;
  for (i = 0; i < 100000000; i++){
    update(&my_counter, id, 1);
  }
  return NULL;
}


int main(){
  init(&my_counter, 10);//FUNCION inicializadora declaracion
  pthread_t threads[N_THREADS];//crea 6 hilos por el N_TREADS
int hil[N_THREADS];

  struct timeval start, end;//medida del tiempo interno, marca tiempo inicial y tiempo final
  gettimeofday(&start, NULL); //optiene tiempo del sistema en el instante de la linea de codigo
  int i;
  for (i = 0; i < N_THREADS; i++){
  	hil[i]=i;
    int rc = pthread_create(&threads[i], NULL, my_thread, hil[i]);//pthread_create tiene 4 argumentos (nombrefuncion,handled,parametrosyvalorquequieroenviar)
    assert(rc == 0);//verifica que no fallo es un traicatch, o excepcion controlada
  }
  
  for (i = 0; i < N_THREADS; i++){
    pthread_join(threads[i], NULL);
  }

  gettimeofday(&end, NULL);//finaliza el toma de tiempo interno
  
  int value = get(&my_counter);//obtenemos valor final del campo
  float time = ((end.tv_sec - start.tv_sec) * 1000.0) +//esta en segundos y divido por 1000 para conviertir en milisegundos
    ((end.tv_usec - start.tv_usec)/1000.0);//calculo del tiempo separado por microsegundos y segundos y milisegundos
  
  printf("My counter value is %d\n", value);
  printf("Execution time %3.2f ms\n", time);

  return 0;
}
