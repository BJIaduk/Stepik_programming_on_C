/*
Наконец, научимся считывать список. Для этого сначала научимся читать одно число без гарантии успеха, то есть напишем функцию struct maybe_int64 maybe_read_int64(). Структуру мы берём из предыдущего урока:

struct maybe_int64 {
  bool valid;
  int64_t value;
};

struct maybe_int64 some_int64( int64_t i ) {
  return (struct maybe_int64) { .value = i, .valid = true };
}

const struct maybe_int64 none_int64 = { 0 };
Функция maybe_read_int64 будет вызывать scanf и возвращать экземпляр struct maybe_int64.  

Помните, что вызов scanf с правильным спецификатором ввода -- это попытка прочитать число, которая не обязательно завершится успехом. Возвращаемое значение scanf показывает, получилось ли прочитать число или нет. Например,  число не получится прочитать если ввод уже закончился.

Советуем прочитать: справочную страницу для scanf.

Sample Input:

1

Sample Output:

Some 1
*/

struct maybe_int64 maybe_read_int64() {
    int64_t value = 0;
    if((scanf("%" SCNd64, &value)) > 0) { 
        return some_int64( value );
    }
    else
        return none_int64;
}
