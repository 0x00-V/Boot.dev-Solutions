#include <stdlib.h>

#include "snekobject.h"

snek_object_t *new_snek_float(float value) {
  snek_object_t *new_float = malloc(sizeof(snek_object_t));
  if(new_float == NULL) return NULL;
  new_float->kind = FLOAT;
  new_float->data.v_float = value;
  return new_float;
  
}

// don't touch below this line

snek_object_t *new_snek_integer(int value) {
  snek_object_t *obj = malloc(sizeof(snek_object_t));
  if (obj == NULL) {
    return NULL;
  }

  obj->kind = INTEGER;
  obj->data.v_int = value;
  return obj;
}
