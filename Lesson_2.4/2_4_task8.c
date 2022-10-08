/*
В массивах мы можем легко добраться до любого элемента, так как они лежат в памяти последовательно. Достаточно к адресу начала массива прибавить правильное смещение. Со связными списками сложнее: нужно пройтись по списку с начала, считая элементы.

Напишите функцию list_at, возвращающую экземпляр maybe_int64. Структуру мы берём из предыдущего урока:

struct maybe_int64 {
  bool valid;
  int64_t value;
};

struct maybe_int64 some_int64( int64_t i ) {
  return (struct maybe_int64) { .value = i, .valid = true };
}

const struct maybe_int64 none_int64 = { 0 };
Тесты для этого задания принимают сначала индекс в списке, затем список.

Sample Input:

3 0 9 8 7 6

Sample Output:

Some 7
*/

struct maybe_int64 list_at(  const struct list* a, size_t idx ) {
    if (a) {
        for(size_t i = 0; i < idx; i++) {
            if (!a) {
                return none_int64;
            }
            a = a->next;
        }
        return some_int64( a->value);
    }
    else {
        return none_int64;
    }
}
