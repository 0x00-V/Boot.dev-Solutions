#include <stdio.h>
#include <stdlib.h>

#include "bootlib.h"
#include "munit.h"
#include "snekobject.h"

munit_case(RUN, test_int_has_refcount, {
  snek_object_t *obj = new_snek_integer(10);
  assert_int(obj->refcount, ==, 1, "Refcount should be 1 on creation");
  free(obj);
});

munit_case(SUBMIT, test_float_has_refcount, {
  snek_object_t *obj = new_snek_float(42.0);
  assert_int(obj->refcount, ==, 1, "Refcount should be 1 on creation");
  free(obj);
});

int main() {
  MunitTest tests[] = {
    munit_test("test_int_has_refcount", test_int_has_refcount),
    munit_test("test_float_has_refcount", test_float_has_refcount),
    munit_null_test,
  };

  MunitSuite suite = munit_suite("refcount", tests);

  return munit_suite_main(&suite, NULL, 0, NULL);
}
