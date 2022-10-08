/*
Структуры снимают с нас изрядную часть когнитивной нагрузки. 
Когда вы работаете с набором данных как с чем-то концептуально единым, 
возможно, стоит объединить их в структуру.

Научимся использовать структуры чтобы работать с массивом и его длиной 
как с единой сущностью. Создайте структуру array_int из двух полей:

int64_t* data,  указатель на данные;
size_t size, размер массива.
Добавьте функции для:

доступа к элементу
записи в элемент
вывода массива
подсчёта минимума.
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
  if (i >= a.size || a.size == 0)
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
    int64_t min = *array.data;
    size_t min_i = 0;
    if (array.size == 0) {
        return none_int64;
    }
    else {
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

void main() {
	struct array_int array = array_int_read();
	if (array.size) {
	struct maybe_int64 min = array_int_min( array );
	array_int_print( array );
	printf("%" PRId64 " " , min.value);
	array_int_free( array );
	}
}