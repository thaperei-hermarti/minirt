#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

/* A simple test */
static void test_sanity(void **state) {
    (void) state;  // unused
    assert_int_equal(1 + 1, 2);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_sanity),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
