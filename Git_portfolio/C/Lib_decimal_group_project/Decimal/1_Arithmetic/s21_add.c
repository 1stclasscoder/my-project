#include "./../../Headers/s21_arithmetic_function.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  bit32_t code_error = S21_SUCCES;
  *result = s21_decimal_null();
  s21_BigData val_data_1 = s21_BDecimal_get_data(value_1);
  s21_BigData val_data_2 = s21_BDecimal_get_data(value_2);
  s21_BigData result_data = s21_BDecimal_null_data();

  code_error = s21_BDecimal_basic_add(val_data_1, val_data_2, &result_data);

  *result = s21_BDecimal_set_data(result_data);
  return code_error;
}