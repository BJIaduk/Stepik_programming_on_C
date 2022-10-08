/*
Напишите две функции, которые переворачивают массив, 
принимая его первым и вторым способом. 
В перевернутом массиве элементы идут в обратном порядке, 
например, массив 10 24 3 4 5 станет 5 4 3 24 10. 
Изменить нужно тот массив, который функция получает в качестве аргумента;
его не нужно выводить.
*/

void array_reverse(int* array, int size) {
    for (int i = 0; i < size/2; i++) {
        int t = array[i];
        array[i] = array[size - i - 1];
        array[size - i - 1] = t;
    }
}

void array_reverse_ptr(int* array, int* limit) {
     for (int* current = array, i = 0; current < limit; i++) {
         if (array[i] == *(limit - i - 1)) break;
        int t = array[i];
        array[i] = *(limit - i -1);
        *(limit - i -1) = t;
         current+=1;
    }
}