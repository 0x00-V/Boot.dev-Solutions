#include "vm.h"

vm_t *vm_new() {
  vm_t *new_vm = malloc(sizeof(vm_t));
  new_vm->frames = stack_new(8);
  new_vm->objects = stack_new(8);
  return new_vm;
}

void vm_free(vm_t *vm) {
  stack_free(vm->frames);
  stack_free(vm->objects);
  free(vm);
}
