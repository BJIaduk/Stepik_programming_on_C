/*
Структура для описания массива массивов
Наконец, перейдём к массиву массивов. Вместо того, чтобы хранить размеры строчек в отдельном блоке памяти, отдельно выделять под него память и освобождать её, мы теперь будем держать всю необходимую информацию вместе.

Напишите программу, которая:

читает со входа массив массивов чисел int64_t.  В строчках может быть разное количество элементов. Формат такой:
<число строк>
<количество в строке 1> <элемент11> <элемент12> ...
<количество в строке 2> <элемент21> <элемент22> ...
находит минимальный элемент (один на весь массив массивов);
вычитает M изо всех элементов массива массивов;
выводит результат в формате:
<элемент11> <элемент12> ...
<элемент21> <элемент22> ...
Пример:

Исходные данные:
---
3
4 1 2 5 3
0
2 1 2 
---

Результат:

---
0 1 4 2

0 1
---
Гарантируется, что в массиве массивов будет хотя бы одна строчка, но не гарантируется, 
что будет хотя бы один элемент.

Будет запущен следующий код:

void perform() {
  struct array_array_int array = array_array_int_read();
  struct maybe_int64 m = array_array_int_min( array );
  if (m.valid) {
    array_array_int_normalize( array, m.value );
    array_array_int_print( array );
  }
  array_array_int_free( array );
}
Sample Input:

3
9 3 2 4 54 9 2 1 872 123
8 123 12354 23 232 43412 534 8237 -99292
3 45 2 245
Sample Output:

99295 99294 99296 99346 99301 99294 99293 100164 99415 
99415 111646 99315 99524 142704 99826 107529 0 
99337 99294 99537 
*/

#include <stdio.h>
#include <malloc.h>
#include <inttypes.h> 
#include <stdbool.h>

struct maybe_int64 {
  int64_t value;
  bool valid;
};

struct maybe_int64 some_int64(int64_t i) {
  return (struct maybe_int64) { i, true };
}

const struct maybe_int64 none_int64 = { 0 };

size_t read_size() { size_t sz = 0; scanf("%zu", &sz); return sz; }

struct array_int {
  int64_t* data;
    size_t size;
};

void array_int_fill( int64_t* array, size_t sz ) {
  for( size_t i = 0; i < sz; i = i + 1 ) {
    scanf("%" SCNd64, &array[i]);
  }
}

struct array_int array_int_read() {
  const size_t size = read_size();
  if (size > 0) {
    int64_t* array = malloc( sizeof(int64_t) * size);
    array_int_fill( array, size );
    return (struct array_int) { .data = array, .size = size };
  }
  else return (struct array_int) {0};
}

// возвращает ошибку если индекс за пределами массива
struct maybe_int64 array_int_get( struct array_int a, size_t i ) {
  if (i >= a.size)
      return (none_int64);
  else 
      return (some_int64((a.data)[i]));
}

// возвращает false если индекс за пределами массива
bool array_int_set( struct array_int a, size_t i, int64_t value ) {
  if (i >= a.size)
      return (false);
  else {
      (a.data)[i] = value;
      return (true);
  }
}

void array_int_print( struct array_int array ) {
  for (size_t i = 0; i < array.size; i = i + 1) {
    printf("%" PRId64 " " , array_int_get( array, i).value);
  }
}

struct maybe_int64 array_int_min( struct array_int array ) {
	if (array.size == 0) {
        return none_int64;
    }
	else {
    int64_t min = *array.data;
    size_t min_i = 0;
    for (size_t i = 0; i < array.size; i++) {
        if (min > *(array.data + i)) {
            min = *(array.data + i);
            min_i = i;
        }
    }
    return some_int64(*(array.data + min_i));
    }
}

void array_int_free( struct array_int a ) { 
    if ( a.size > 0 ) {
        free(a.data); 
        a.size = 0;
    } 
}

void array_int_normalize( struct array_int array, int64_t m ) {
  for (size_t i = 0; i < array.size; i = i + 1) {
    array.data[i] = array.data[i] - m;
  }
}

/*  ---- maybe int[] ---- */

struct maybe_array_int {
  struct array_int value;
  bool valid;
};

struct maybe_array_int some_array_int(struct array_int array) {
  return (struct maybe_array_int) { array, true };
}
const struct maybe_array_int none_array_int = { {NULL, 0}, false };


/*  ---- int[][] ---- */

struct array_array_int {
  struct array_int* data;
  size_t size;
};

/*  --- строки ---  */

struct maybe_array_int array_array_int_get_row( struct array_array_int a, size_t i ) {
  if ( 0 <= i && i < a.size ) { return some_array_int( a.data[i] ); }
  else { return none_array_int; }
}

bool array_array_int_set_row( struct array_array_int a, size_t i, struct array_int value ) {
  if (0 <= i && i < a.size) {
    a.data[i] = value;
    return true;
  }
  else { return false; }
}


/*  --- get/set ---  

struct maybe_int64 array_array_int_get( struct array_array_int a, size_t i, size_t j ) {
	???
}

bool array_array_int_set( struct array_array_int a, size_t i, size_t j, int64_t value ) {
  ???
}


 --- read/print ---  */

struct array_array_int array_array_int_read() {
	size_t rows = 0;
	scanf("%zu", &rows);
	struct array_int *array = malloc(sizeof(struct array_int) * rows);
	if (rows > 0) {
		for (size_t i = 0; i < rows; i = i + 1) {
			array[i] = array_int_read();
		}
	return (struct array_array_int) {array, rows};
	}
	else
		return (struct array_array_int) {0};
}


void array_array_int_print( struct array_array_int array) {
	for (size_t i = 0; i < array.size; i++) {
		array_int_print(array.data[i]);
		printf("\n");
	}
}


/*  --- min/normalize ---  */

// найти минимальный элемент в массиве массивов
struct maybe_int64 array_array_int_min( struct array_array_int array ) {
	size_t i = 0;
	struct maybe_int64 min = array_int_min(array.data[0]);
	for (size_t i = 1; i < array.size; i++) {
		if (((min.value > array_int_min(array.data[i]).value && min.valid != 0) || min.valid == 0) && (array_int_min(array.data[i]).valid != 0)) {
			min = array_int_min(array.data[i]);
		}
	}
	if (min.valid != 0)
		return some_int64(min.value);
	else
		return none_int64;
}

// вычесть из всех элементов массива массивов число m
void array_array_int_normalize( struct array_array_int array, int64_t m) {
  for (size_t i = 0; i < array.size; i = i + 1) {
    const struct maybe_array_int cur_row = array_array_int_get_row( array, i );
    if (cur_row.valid) {
         array_int_normalize( cur_row.value, m );
    }
  }
}

void array_array_int_free( struct array_array_int array ) {
	free(array.data);
	for (size_t i = 0; i < array.size; i++) {
		array_int_free( array.data[i]);
	}
}

void main() {
	struct array_array_int array = array_array_int_read();
	if (array.size) {
	struct maybe_int64 m = array_array_int_min( array );
	if (m.valid) {
		array_array_int_normalize( array, m.value );
	}
	array_array_int_print( array );
    array_array_int_free( array );
	}
}