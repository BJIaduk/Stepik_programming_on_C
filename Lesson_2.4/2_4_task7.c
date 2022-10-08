/*
Напишите функцию, проходящуюся по всему списку и считающую сумму всех его элементов. Помните, что она должна работать для неизменяемых списков.

Sample Input:

34 2 6

Sample Output:

42
*/

int64_t list_sum( const struct list* a) {
    int64_t sum = 0;
    while(a) {
        sum = sum + a->value;
        a = a->next;
    }
    return sum;
}
