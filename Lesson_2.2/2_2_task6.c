/*
Наконец, сделаем что-нибудь интересное с массивом массивов.

Считаем массив массивов;
Найдем минимальный элемент M (один на весь массив массивов);
Вычтем M изо всех элементов массива массивов;
Выведем результат.
Вы можете использовать функции из предыдущих заданий.

Возможна ситуация, когда массив массивов состоит только из пустых строчек.
*/

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <malloc.h>

void array_int_fill(int64_t* array, size_t size) {
		for (size_t i = 0; i < size; i++) {
					scanf("%" SCNd64, &array[i]);
						    }
}

//считываем размер подмассива и выделяем динамическую память на все элементы 
int64_t* array_int_read(size_t* size) {
		  scanf("%zu", size);
		  	  int64_t* array = malloc(sizeof(int64_t) * (*size));
			  	  array_int_fill(array, *size);
return array;
}

//главная функция по считыванию массива массивов
int64_t** marray_read(size_t* rows, size_t** sizes) {
		scanf("%zu", rows);
			*sizes = malloc(*rows * sizeof(size_t)); 
				int64_t** (marray) = malloc(sizeof(size_t) * (*rows)); //выделяем память на количество элементов(то есть количество! цифр содержащихся в подмассивов, а не пямять для каждого элемента) по 18 млрд * 2  
					for (size_t i = 0; i < *rows; i++) {
							*(marray + i) = array_int_read((*sizes + i)); //выделяем память на подмассив i
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

int64_t* int64_ptr_min(int64_t* x, int64_t* y) {
	if (!((x) || (y))) { 
		return NULL;
	}
	else {
       		if (!(x)) {
			 return y;
		} 
		else {
			if (!(y)) {
				 return x;
			} 
		
			else  {
				if (*x <= *y)
					return x;
				else
					return y;
			}
		}
	}
}

int64_t* array_int_min( int64_t* array, size_t* size ) {
	    if (*size == 0)
		            return NULL;
	    int8_t min = 0;
		    for (size_t i = 1; i < *size; i++) {
			            if (array[min] > array[i])
					                min = i;
		    }
return &array[min];
}

// Вернуть адрес минимального элемента массива массивов
int64_t* marray_int_min( int64_t** marray, size_t** sizes, size_t rows ) { //size_t** sizes - тк в аргументах адрес на указатель, который указывает на массив, в параметрах должен принимать это значение указатель на указатель
	int64_t* min = array_int_min( *marray, *sizes );// передаем адрес нулевого подмассива, и адрес нулевого элемента
        for(int64_t i = 1; i < rows; i++) {
	int64_t*z = array_int_min( *(marray + i), *sizes + i);
		min =  int64_ptr_min(min, z);                  
       	}
                       return min;
}

void array_int_m(int64_t* array, int64_t m, size_t* size) {
	for (size_t i = 0; i < *size; i++) {
		array[i] = array[i] - m;
        }
}

// Вычесть m изо всех элементов массива
void marray_normalize( int64_t** marray, size_t sizes[], size_t rows, int64_t m ) { //в m передается адрес минимального
	for (size_t i = 0; i < rows; i++) { 
		array_int_m(*(marray+i), m, (&sizes[i])); //marray в скобках тк указывет на какой элемент находится под этим адрессом то есть подмассив
        }
}

void marray_free( int64_t** marray, size_t rows, size_t* size) {
	    for(size_t i = 0; i < rows; i++) {
		            if (marray[i]) {
				            free(marray[i]);
					            }
			        }
	         free(marray);
		 free(size);
}

int main() {
	size_t* size = 0;
	size_t rows = 0;
	int64_t* m = 0;
	int64_t** marray = marray_read(&rows, &size);
	m = marray_int_min( marray, &size, rows ); //передаем адрес массива подмассивов, адрес указателя на массив sizes, и просто число rows оно было до этого изменено менять его нам больше не нужно
	if(!m) { //ставим условие, если указатель по прежнему хранит нулевой адрес, значит минимального элемента нет => в массиве массивов нет ни одного элемента
		marray_print(marray, size, rows); 
	}
	else {
		marray_normalize (marray, size, rows, *m);//size - передаем адрес первого элемента, чтобы потом иметь доступ ко всем значениям элементов в массиве sizes
		marray_print(marray, size, rows);
	}
	marray_free(marray, rows, size );
return 0;
}
