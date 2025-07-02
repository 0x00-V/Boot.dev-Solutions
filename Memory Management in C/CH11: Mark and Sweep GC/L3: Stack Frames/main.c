#include <stdio.h>
#include <stdlib.h>

#include "bootlib.h"
#include "munit.h"
#include "vm.h"

munit_case(RUN, test_vm_new, {
  vm_t *vm = vm_new();
  vm_new_frame(vm);
  assert_int(vm->frames->count, ==, 1, "frame was pushed");
  vm_free(vm);
});

munit_case(SUBMIT, test_frames_are_freed, {
  vm_t *vm = vm_new();
  vm_new_frame(vm);
  vm_free(vm);
  assert(boot_all_freed());
});

int main() {
  MunitTest tests[] = {
    munit_test("/test_vm_new", test_vm_new),
    munit_test("/test_frames_are_freed", test_frames_are_freed),
    munit_null_test,
  };

  MunitSuite suite = munit_suite("mark-and-sweep", tests);

  return munit_suite_main(&suite, NULL, 0, NULL);
}
