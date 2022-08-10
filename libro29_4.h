#ifndef COUNTER_WO_LOCKS_H_//directivas del procesador para evitar problemas si el archivo esta en varias partes
#define COUNTER_WO_LOCKS_H_
//declaracion de las variables
/*typedef struct __counter_t {    //definicion de estructura para llamarlo con counter_t en vez de struct__counter_t
  int value;
} counter_t;
//funciones que hay
void init(counter_t *c);//counter_t es la direccion donde esta la estructura
void increment(counter_t *c); 
void decrement(counter_t *c);
int get(counter_t *c);

#endif // COUNTER_WO_LOCKS_H_*/

//LOCK-BASED CONCURRENT DATA STRUCTURES 5
 typedef struct __counter_t {
 int global; // global count
 pthread_mutex_t glock; // global lock
 int local[NUMCPUS]; // per-CPU count
 pthread_mutex_t llock[NUMCPUS]; // ... and locks
 int threshold; // update frequency
 } counter_t;
 
 void int(counter_t *c, int threshold);
 void update(counter_t *c, int threadID, int amt);
int get(counter_t *c);
