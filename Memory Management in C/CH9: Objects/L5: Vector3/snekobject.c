#include <stdlib.h>
#include <string.h>
#include "snekobject.h"


snek_object_t *new_snek_vector3(snek_object_t *x, snek_object_t *y, snek_object_t *z) 
{
  if(x == NULL || y == NULL || z == NULL) return NULL;
  snek_object_t *new_vec3 = malloc(sizeof(snek_object_t));
  if(new_vec3 == NULL) return NULL;
  (*new_vec3).kind = VECTOR3;
  (*new_vec3).data.v_vector3 = (snek_vector_t){.x = x, .y = y, .z = z};
  return new_vec3;
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

snek_object_t *new_snek_float(float value) {
  snek_object_t *obj = malloc(sizeof(snek_object_t));
  if (obj == NULL) {
    return NULL;
  }

  obj->kind = FLOAT;
  obj->data.v_float = value;
  return obj;
}

snek_object_t *new_snek_string(char *value) {
  snek_object_t *obj = malloc(sizeof(snek_object_t));
  if (obj == NULL) {
    return NULL;
  }

  int len = strlen(value);
  char *dst = malloc(len + 1);
  if (dst == NULL) {
    free(obj);
    return NULL;
  }

  strcpy(dst, value);

  obj->kind = STRING;
  obj->data.v_string = dst;
  return obj;
}
