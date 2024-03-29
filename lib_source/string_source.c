#include "../../tib_includes/libtibstrings.h"
#include <stdlib.h>
// to change:
// stop allocating shit when u can

int where_dot(char *text) {

  int i = 0;
  while (text[i] != '.' && i < len(text) - 1) {
    i++;
  }
  if (text[i] != '.')
    return -1;
  return i;
}

char *substring(int begin, int end, char *text) {
  // Edge case 1:
  // begin >= end
  // how the fuck do pointers work
  char *result;
  result = (char *)calloc(100, sizeof(char));
  if (begin >= end)
    return result;
  int i;
  for (i = 0; i + begin < end; i++) {
    *(result + i) = *(text + begin + i);
  }
  *(result + i) = '\0';
  return result;
}

long long int exponentiate(long long int a, long long int b) {
  // Edge case 1:
  //
  if (b == 0)
    return 1;
  return a * exponentiate(a, b - 1);
}

int len(char *text) {
  int i = 0, result = 0;
  while (*(text + i) != '\0') {
    result++;
    i++;
  }
  return result;
}

int string_to_int(char *input) {
  char *text = calloc(100, sizeof(char));
  text = input;
  double nFlag = 1.0;

  if (*text == '-') {
    nFlag = -1.0;
    text = substring(1, len(input), input);
  }
  return to_int(text) * nFlag;
}

double string_to_float(char *input) {
  char *text = calloc(100, sizeof(char));
  text = input;
  double nFlag = 1.0;
  static double result = 0.0;

  if (*text == '-') {
    nFlag = -1.0;
    text = substring(1, len(input), input);
  }
  int periodPos = where_dot(text);
  if (periodPos == -1)
    return (double)to_int(text);
  long long int integralPart = to_int(substring(0, periodPos, text));
  result =
      integralPart + to_fraction(substring(periodPos + 1, len(text), text));
  return result * nFlag;
}

int string_to_intarr(char *substrate, int *returned_array) {
  int i = 0, result_index_counter = 0, cache_index_counter = 0;
  char cache[30];

  // okay, so i run through the string
  // do while loop maybe
  // putting the numbers into a smaller, temp string along the way
  // and if i reach a space, i get that string, and to_int it.
  do {
    if (*(substrate + i) == '\0' || *(substrate + i) == ' ') {
      cache[cache_index_counter] = '\0';
      *(returned_array + result_index_counter) = to_int(cache);
      result_index_counter++;
      cache_index_counter = 0;
      if (*(substrate + i) == '\0')
        break;
    } else {
      cache[cache_index_counter] = *(substrate + i);
      cache_index_counter++;
    }
    i++;
  } while (1);
  return result_index_counter;
}

long long int to_int_letter(char n) {
  long long int result = n;
  return result - 48;
}

long long int to_int(char *text) {
  long long int r = 0;
  int i;
  char *reversed = calloc(100, sizeof(char));
  reversed = reverse_c(text, len(text));
  for (i = 0; reversed[i] != '\0'; i++) {
    r += (long long int)((long long int)to_int_letter(reversed[i]) *
                         (long long int)exponentiate(10, i));
  }
  return r;
}

double to_fraction(char *text) {
  // how the fuck do pointers work
  double r = 0, letterValue = 0, coefficient = 0;
  int i;
  char *reversed = calloc(100, sizeof(char));
  reversed = reverse_c(text, len(text));
  for (i = 0; reversed[i] != '\0'; i++) {
    letterValue = (double)to_int_letter(reversed[i]);
    coefficient = (double)(1.0 / exponentiate(10, i + 1));
    r += (double)(letterValue * coefficient);
  }
  return r;
}

char *reverse_c(char *input, int length) {
  char *result;
  int length_counter = 0;
  result = calloc(length, sizeof(char));

  for (; length_counter < length; length_counter++)
    *(result + length_counter) = *(input + length - length_counter - 1);
  *(result + length) = '\0';
  return result;
}

/**
 * This function splits the string input based on the delimiter and puts in in
 * output->string_array
 */
int tokenize(char *input, char delimeter, struct output_string_array *output) {
  size_t o_size = 0;
  char *result;
  result = calloc(128, sizeof(char));
  int result_counter = 0;
  // TODO: fix logic: o_size is used in the first if when it should be a
  // different variable
  while (*(input + o_size) != '\0') {
    if (*(input + o_size) != ' ' && *(input + o_size) != '\0') {
      *(result + result_counter) = *(input + o_size);
      result_counter++;
    } else if (*(input + o_size) == ' ') {
      output->size = o_size;
      output->string_array[output->size - 1] = result;
    }
    o_size++;
  }
  return 1;
}

int string_to_doublearr(char *substrate, double *returned_array) {
  int i = 0, result_index_counter = 0, cache_index_counter = 0;
  char cache[30];

  // okay, so i run through the string
  // do while loop maybe
  // putting the numbers into a smaller, temp string along the way
  // and if i reach a space, i get that string, and to_int it.
  do {
    if (*(substrate + i) == '\0' || *(substrate + i) == ' ') {
      cache[cache_index_counter] = '\0';
      *(returned_array + result_index_counter) = string_to_float(cache);
      result_index_counter++;
      cache_index_counter = 0;
      if (*(substrate + i) == '\0')
        break;
    } else {
      cache[cache_index_counter] = *(substrate + i);
      cache_index_counter++;
    }
    i++;
  } while (1);
  return result_index_counter;
}
