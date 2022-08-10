#include "counter_wo_locks.h"

//contador sin locks
void init(counter_t *c) {//recibo la direccion de la estructura
  c->value = 0;//desreferenciacion de la estructura es la flechita
}

void increment(counter_t *c) {
  c->value++;
}

void decrement(counter_t *c) {
  c->value--;
}

int get(counter_t *c) {
  return c->value;
}
