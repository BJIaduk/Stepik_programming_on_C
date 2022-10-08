/*
Напишите функцию array_fib, которая заполнит массив числами Фибоначчи 
по порядку. Первые два числа это 1 и 1; каждое следующее является суммой 
двух предыдущих:

1 1 2 3 5 8 13 ...

 

Помните, что в массиве может быть любое количество чисел.
*/

void array_fib(int* array, int* limit) {
    if (limit == array)
        return;
    if (limit - array == 1)
        *array = 1;
    else if (limit - array == 2) {
         *array = 1;
         *(array + 1) = 1;
         }
         else {
            for (int *current = array; current < limit - 2; current++) {
                *array = 1;
                *(array + 1) = 1;
                *(current + 2) = *(current + 1) + *(current);
                }
          }
}




