#include "../s21_test_decimal.h"

START_TEST(test_s21_sub_1) {
  // тест 1
  s21_decimal decimal1 = {{0, 0, 0, 0}};
  s21_decimal decimal2 = {{0, 0, 0, 0}};
  s21_decimal decimal3 = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int check = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(s21_is_equal(result, decimal3), 1);
  ck_assert_int_eq(check, S21_SUCCES);
}
END_TEST

START_TEST(test_s21_sub_2) {
  // тест 2
  s21_decimal decimal1 = {{1, 0, 0, 0}};
  s21_decimal decimal2 = {{2, 0, 0, 0}};
  s21_decimal decimal3 = {{1, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_negate(decimal3, &decimal3);
  int check = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(s21_is_equal(result, decimal3), 1);
  ck_assert_int_eq(check, S21_SUCCES);
}
END_TEST

START_TEST(test_s21_sub_3) {
  // тест 3
  s21_decimal decimal1 = {{55, 0, 0, 0}};
  s21_decimal decimal2 = {{100, 0, 0, 0}};
  s21_decimal decimal3 = {{45, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_negate(decimal3, &decimal3);
  int check = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(s21_is_equal(result, decimal3), 1);
  ck_assert_int_eq(check, S21_SUCCES);
}
END_TEST

START_TEST(test_s21_sub_4) {
  // тест 4
  bit32_t max = 0b11111111111111111111111111111111;
  s21_decimal decimal1 = {{max, max, max, 0}};
  s21_decimal decimal2 = {{max, max, max, 0}};
  s21_decimal decimal3 = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int check = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(s21_is_equal(result, decimal3), 1);
  ck_assert_int_eq(check, S21_SUCCES);
}
END_TEST

START_TEST(test_s21_sub_5) {
  // тест 5
  bit32_t max = 0b11111111111111111111111111111111;
  s21_decimal decimal1 = {{max, max, max, 0}};
  s21_decimal decimal2 = {{max, max, max, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_negate(decimal1, &decimal1);
  int check = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(check, S21_TOO_SMALL);
}
END_TEST

START_TEST(test_s21_sub_6) {
  // тест 6
  bit32_t max = 0b11111111111111111111111111111111;
  s21_decimal decimal1 = {{max, max, max, 0}};
  s21_decimal decimal2 = {{0, 0, 0, 0}};
  s21_decimal decimal3 = {{max, max, max, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int check = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(s21_is_equal(result, decimal3), 1);
  ck_assert_int_eq(check, S21_SUCCES);
}
END_TEST

START_TEST(test_s21_sub_7) {
  // тест 7
  bit32_t max = 0b11111111111111111111111111111111;
  int result1 = 0b11111111111111111111111110011011;
  s21_decimal decimal1 = {{max, max, max, 0}};
  s21_decimal decimal2 = {{100, 0, 0, 0}};
  s21_decimal decimal3 = {{result1, max, max, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int check = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(s21_is_equal(result, decimal3), 1);
  ck_assert_int_eq(check, S21_SUCCES);
}
END_TEST

START_TEST(test_s21_sub_8) {
  // тест 8
  bit32_t max = 0b11111111111111111111111111111111;
  int result1 = 0b11111111111111111111111110011011;
  s21_decimal decimal1 = {{result1, max, max, 0}};
  s21_decimal decimal2 = {{100, 0, 0, 0}};
  s21_decimal decimal3 = {{max, max, max, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_negate(decimal1, &decimal1);
  s21_negate(decimal3, &decimal3);
  int check = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(s21_is_equal(result, decimal3), 1);
  ck_assert_int_eq(check, S21_SUCCES);
}
END_TEST

START_TEST(test_s21_sub_9) {
  // тест 9
  bit32_t max = 0b11111111111111111111111111111111;
  s21_decimal decimal1 = {{max, max, max, 0}};
  s21_decimal decimal2 = {{100, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_negate(decimal1, &decimal1);
  int check = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(check, S21_TOO_SMALL);
}
END_TEST

START_TEST(test_s21_sub_10) {
  // тест 10
  bit32_t max = 0b11111111111111111111111111111111;
  s21_decimal decimal1 = {{max, max, max, 0}};
  s21_decimal decimal2 = {{100, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_negate(decimal2, &decimal2);
  int check = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(check, S21_TOO_LARGE);
}
END_TEST

START_TEST(test_s21_sub_11) {
  // тест 11
  bit32_t max = 0b11111111111111111111111111111111;
  s21_decimal decimal1 = {{max, max, max, 0}};
  s21_decimal decimal2 = {{max, max, max, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_negate(decimal2, &decimal2);
  int check = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(check, S21_TOO_LARGE);
}
END_TEST

START_TEST(test_s21_sub_12) {
  // тест 12
  bit32_t max = 0b11111111111111111111111111111111;
  s21_decimal decimal1 = {{max, max, max, 0}};
  s21_decimal decimal2 = {{max, max, 0, 0}};
  s21_decimal decimal3 = {{0, 0, max, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int check = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(s21_is_equal(result, decimal3), 1);
  ck_assert_int_eq(check, S21_SUCCES);
}
END_TEST

START_TEST(test_s21_sub_13) {
  // тест 13
  bit32_t max = 0b11111111111111111111111111111111;
  s21_decimal decimal1 = {{max, max, max, 0}};
  s21_decimal decimal2 = {{max, 0, 0, 0}};
  s21_decimal decimal3 = {{0, max, max, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int check = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(s21_is_equal(result, decimal3), 1);
  ck_assert_int_eq(check, S21_SUCCES);
}
END_TEST

START_TEST(test_s21_sub_14) {
  // тест 14
  s21_decimal decimal1 = {{100, 0, 0, 0}};
  s21_decimal decimal2 = {{5, 0, 0, 0b10000000000000000}};
  s21_decimal decimal3 = {{995, 0, 0, 0b10000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int check = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(s21_is_equal(result, decimal3), 1);
  ck_assert_int_eq(check, S21_SUCCES);
}
END_TEST

START_TEST(test_s21_sub_15) {
  // тест 15
  s21_decimal decimal1 = {{1, 0, 0, 0b11000000000000000}};
  s21_decimal decimal2 = {{5, 0, 0, 0b1000000000000000}};
  s21_decimal decimal3 = {{49, 0, 0, 0b10000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_negate(decimal3, &decimal3);
  int check = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(s21_is_equal(result, decimal3), 1);
  ck_assert_int_eq(check, S21_SUCCES);
}
END_TEST

START_TEST(test_s21_sub_16) {
  s21_decimal decimal1 = {{5, 0, 0, 0b10000000000000000}};
  s21_decimal decimal2 = {{5, 0, 0, 0b10000000000000000}};
  s21_decimal decimal3 = {{1, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_negate(decimal2, &decimal2);
  int check = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(s21_is_equal(result, decimal3), 1);
  ck_assert_int_eq(check, S21_SUCCES);
}
END_TEST

START_TEST(test_s21_sub_17) {
  // тест 17
  s21_decimal decimal1 = {{99, 0, 0, 0b1000000000000000}};
  s21_decimal decimal2 = {{5, 0, 0, 0b1000000000000000}};
  s21_decimal decimal3 = {{104, 0, 0, 0b1000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_negate(decimal2, &decimal2);
  int check = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(s21_is_equal(result, decimal3), 1);
  ck_assert_int_eq(check, S21_SUCCES);
}
END_TEST

START_TEST(test_s21_sub_18) {
  // тест 18
  s21_decimal decimal1 = {{153, 0, 0, 0b1000000000000000}};
  s21_decimal decimal2 = {{25, 0, 0, 0b1000000000000000}};
  s21_decimal decimal3 = {{128, 0, 0, 0b1000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int check = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(s21_is_equal(result, decimal3), 1);
  ck_assert_int_eq(check, S21_SUCCES);
}
END_TEST

START_TEST(test_s21_sub_19) {
  // тест 18
  bit32_t max = 0b11111111111111111111111111111111;
  s21_decimal decimal1 = {{max, max, max, 0}};
  s21_decimal decimal2 = {{3, 0, 0, 0}};
  s21_decimal decimal3 = {{max, max, max, 0}};
  decimal2 = s21_decimal_set_scale(decimal2, 1);
  s21_decimal result = {{0, 0, 0, 0}};
  int check = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(s21_is_equal(result, decimal3), 1);
  ck_assert_int_eq(check, S21_SUCCES);
}
END_TEST

START_TEST(test_s21_sub_20) {
  // тест 18
  bit32_t max = 0b11111111111111111111111111111111;
  s21_decimal decimal1 = {{max, max, max, 0}};
  s21_decimal decimal2 = {{5, 0, 0, 0}};
  s21_decimal decimal3 = {{0, 0, 0, 0}};
  decimal2 = s21_decimal_set_scale(decimal2, 1);
  decimal2 = s21_decimal_set_sign(decimal2, 1);
  s21_decimal result = {{0, 0, 0, 0}};
  int check = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(s21_is_equal(result, decimal3), 1);
  ck_assert_int_eq(check, S21_TOO_LARGE);
}
END_TEST

START_TEST(test_s21_sub_21) {
  // тест 18
  bit32_t max = 0b11111111111111111111111111111111;
  s21_decimal decimal1 = {{max, max, max, 0}};
  s21_decimal decimal2 = {{6, 0, 0, 0}};
  s21_decimal decimal3 = {{max - 1, max, max, 0}};
  decimal2 = s21_decimal_set_scale(decimal2, 1);
  s21_decimal result = {{0, 0, 0, 0}};
  int check = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(s21_is_equal(result, decimal3), 1);
  ck_assert_int_eq(check, S21_ANFUNC_SUCCESS);
}
END_TEST

Suite *test_s21_sub_suite() {
  // создаем новый набор для тестов функции
  Suite *suite = suite_create("test_s21_sub");
  TCase *tc_core = tcase_create("core_of_s21_sub");

  // каждый тест добавляем
  tcase_add_test(tc_core, test_s21_sub_1);
  tcase_add_test(tc_core, test_s21_sub_2);
  tcase_add_test(tc_core, test_s21_sub_3);
  tcase_add_test(tc_core, test_s21_sub_4);
  tcase_add_test(tc_core, test_s21_sub_5);
  tcase_add_test(tc_core, test_s21_sub_6);
  tcase_add_test(tc_core, test_s21_sub_7);
  tcase_add_test(tc_core, test_s21_sub_8);
  tcase_add_test(tc_core, test_s21_sub_9);
  tcase_add_test(tc_core, test_s21_sub_10);
  tcase_add_test(tc_core, test_s21_sub_11);
  tcase_add_test(tc_core, test_s21_sub_12);
  tcase_add_test(tc_core, test_s21_sub_13);
  tcase_add_test(tc_core, test_s21_sub_14);
  tcase_add_test(tc_core, test_s21_sub_15);
  tcase_add_test(tc_core, test_s21_sub_16);
  tcase_add_test(tc_core, test_s21_sub_17);
  tcase_add_test(tc_core, test_s21_sub_18);
  tcase_add_test(tc_core, test_s21_sub_19);
  tcase_add_test(tc_core, test_s21_sub_20);
  tcase_add_test(tc_core, test_s21_sub_21);

  // тест кейс добавляем в suite
  suite_add_tcase(suite, tc_core);
  return suite;
}