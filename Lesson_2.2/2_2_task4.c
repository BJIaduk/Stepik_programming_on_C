/*
Массив массивов
Теперь перейдём к другому практически важному случаю -- массиву, 
содержащему указатели на другие массивы. Это разновидность двумерного 
массива, своеобразной таблицы, в которой каждая строчка может иметь 
разный размер.

 Научимся считывать массив массивов чисел int64_t.  Формат входа такой:

<число строк>
<количество в строке 1> <элемент11> <элемент12> ...
<количество в строке 2> <элемент21> <элемент22> ...
Для примера, пусть мы вводим следующие числа: 

3
4 1 2 5 3
0
2 1 2 
Тогда массив массивов можно изобразить следующим образом. Обратите 
внимание на пустую строчку, соответствующую пустому массиву.

1 2 5 3

1 2
Чтобы работать с массивом массивов придётся создать в памяти достаточно 
сложную структуру данных:

выделить массив, хранящий адреса строчек;
выделить память на каждую строчку;
выделить память на отдельный массив sizes, который хранит длины строчек. 
Первый элемент массива sizes это длина первой строчки, второй -- длина 
второй и т.д.

Sample Input:

3
9 3 2 4 54 9 2 1 872 123
8 123 12354 23 232 43412 534 8237 -99292
3 45 2 245

Sample Output:

3 2 4 54 9 2 1 872 123 
123 12354 23 232 43412 534 8237 -99292 
45 2 245 
*/

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

void array_int_fill(int64_t* array, size_t size) {
	for (size_t i = 0; i < size; i++) {
		scanf("%" SCNd64, &array[i]);
	    }
}

int64_t* array_int_read(size_t* size) {
	  scanf("%zu", size);
	  int64_t* array = malloc(sizeof(int64_t) * (*size));
	  array_int_fill(array, *size);
return array;
}

int64_t** marray_read(size_t* rows, size_t** sizes) {
	scanf("%zu", rows);
	*sizes = malloc(*rows * sizeof(size_t));
	int64_t** (marray) = malloc(sizeof(size_t) * (*rows));
	for (size_t i = 0; i < *rows; i++) {
		*(marray + i) = array_int_read((*sizes + i));
	       	printf("\n");
	}
	return marray;
}

void array_int_print(int64_t* marray, size_t sizes) {
	for (size_t i = 0; i < sizes; i++) {
		printf("% " PRIdPTR, marray[i]);
	}
}

void marray_print(int64_t** marray, size_t* sizes, size_t rows) {
	for (size_t i = 0; i < rows; i = i + 1) {
		array_int_print(marray[i], sizes[i]);
		printf("\n"); 
	}
}

int main() {
	size_t* size = 0;
	size_t rows = 0;
	int64_t** marray = marray_read(&rows, &size);
	marray_print(marray, size, rows);
return 0;
}
