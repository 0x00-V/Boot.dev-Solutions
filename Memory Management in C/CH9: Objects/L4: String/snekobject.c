#include <stdlib.h>
#include <string.h>

#include "snekobject.h"

snek_object_t *new_snek_string(char *value) {
  snek_object_t *new_string = malloc(sizeof(snek_object_t));
  if(new_string == NULL) return NULL;
  int string_length = strlen(value);
  char *string_data = malloc(string_length+1);
  if(string_data == NULL)
  {
    free(new_string);
    return NULL;
  }
  
  strcpy(string_data, value);
  
  new_string->kind = STRING;
  new_string->data.v_string = string_data;
  return new_string;
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
