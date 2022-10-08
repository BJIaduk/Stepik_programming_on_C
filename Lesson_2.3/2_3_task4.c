/*
Мы уже упоминали аппаратный стек, хранящий локальные переменные функций. 
Но вообще стеком можно назвать любую сущность, которая хранит элементы и 
поддерживает операции push и pop: 

push добавляет элемент на вершину стека;
pop вынимает элемент с вершины стека.
Стек можно реализовать поверх массива: для этого достаточно хранить указатель 
на вершину стека внутри массива. Разумеется, такой стек будет ограничен размером массива, 
внутри которого он существует.

Для нескольких дальнейших заданий нам будет нужен такой стек внутри программы для хранения чисел, 
поэтому давайте реализуем его -- на основе уже имеющегося упакованного массива array_int
*/

//создаем стек, вводим размер массива, размер стека, заполняем стек, потом опустошаем в цикле
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

void maybe_int64_print( struct maybe_int64 i ) {
    if (i.valid)
        printf("Some %" PRId64 , i.value );
    else
        printf("None");
}

// структура массива - данные массива data[] и его размер
struct array_int {
	int64_t* data;
	size_t size;
};

struct array_int array_int_create( size_t sz ) {
    return (struct array_int) { .data = malloc( sizeof( int64_t ) * sz ), .size = sz };
}

/*
int64_t* array_int_last( struct array_int a ) {
	for(size_t i = 0; i < a.size; i++){
		if (!a.data[i])
			return a.data[i];
	}
}
*/
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

void array_int_free( struct array_int a ) {
    if ( a.size > 0 ) {
        free(a.data);
        a.size = 0;
    }
}

struct stack { //count - ячейка после последнего элемента в стеке, size - размер массива - то есть сколько элементов может быть в стеке, то есть массив не полный и коунт указывает на ячейку после последнего вложенного элемента
  size_t count;
  struct array_int data;
};

// Количество элементов в стеке
size_t stack_count( const struct stack* s ) {
	return s->count;
}

// Создаем и деинициализируем стек
struct stack stack_create( size_t size ) {
	 return (struct stack) { .data = array_int_create(size), .count = 0 };
}
void stack_destroy( struct stack* s ) { 
    if (s->count != 0)
		array_int_free( s->data);
}

// Стек полный
bool stack_is_full( const struct stack * s) {
	if (s->count > s->data.size)
		return true;
	else
		return false;
}
// Стек пустой
bool stack_is_empty( const struct stack * s) {
	if (s->count == 0)
		return true;
	else
		return false;
}

// Поместить значение в стек
bool stack_push( struct stack* s, int64_t value ) {
	if (stack_is_full(s)) {
        return false;
    }
	else {
		s->data.data[s->count] = value;
		s->count++;
		return true;
	}
}

// Вынуть значение с вершины стека. Может вернуть none_int64
struct maybe_int64 stack_pop( struct stack* s ) {
	if (stack_is_empty(s)) {
        return none_int64;
	}
	else {
		s->count--;
		//size_t pop_value = s->data.data[s->count];
		//free(&s->data.data[s->count]);
		return some_int64(s->data.data[s->count]);
    }
}

void print_int64 (int64_t x) {
	printf("%" PRId64, x);
}

void stack_print( const struct stack* s ) {
	if (stack_is_empty(s)) {
		return;
	}
	else {
	  for (size_t i = 0; i < stack_count( s ); i = i + 1 ) {
		print_int64( array_int_get( s->data, i).value );
		printf(" ");
	  }
	}
}

void main() {
	size_t size = 0;
	printf("array_size: ");
	scanf("%zu", &size);
	struct stack s;
	s = stack_create( size );
	size_t n = 0;
	printf("stack_size0: "); //начальный размер стека
	scanf("%zu", &n);
	size_t value = 0;
	for (size_t i = 0; i < n; i++) {
		scanf("%zu", &value);
		if (!stack_is_full(&s))
			stack_push( &s, value );
	}
	stack_print( &s );
	do {
    printf("верхний элемент % " PRId64, stack_pop(&s).value);
    printf(" в стеке осталось %zu элементов\n", stack_count(&s));
  } while (!stack_is_empty(&s));
}
