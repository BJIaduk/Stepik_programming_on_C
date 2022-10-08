/*
Опциональный тип
Теперь мы покажем, как вернуть из функции "результат или ошибку" более чётко и корректно: с помощью упаковки для результата, например, для чисел типа int64_t.  Мы упакуем результат в структурный тип, хранящий также булево значение "успех или провал". В случае успеха второе поле будет равно корректному результату, а в случае провала оно может быть равно чему угодно -- нам это уже не важно.

// Один из двух случаев:
// - valid = true и value содержит осмысленный результат
// - valid = false и value может быть любым

struct maybe_int64 {
  bool valid;
  int64_t value;
};

// Первый случай; создаем функцию в помощь
// Не бойтесь за производительность
struct maybe_int64 some_int64( int64_t i ) {
  return (struct maybe_int64) { .value = i, .valid = true };
}

// Второй случай; можно создать не функцию, 
// а константный экземпляр структуры
// Все поля инициализированы нулями
// .value = 0, .valid = false
const struct maybe_int64 none_int64 = { 0 };
Напишите функции вывода на экран упакованного числа и подсчёта минимума из двух упакованных чисел.
*/


// упакованное число 42 выводится как "Some 42"
// Ошибка выводится как None
void maybe_int64_print( struct maybe_int64 i ) {
    if (i.valid)
        printf("Some %" PRId64 , i.value );
    else
        printf("None");
}

// Если обе упаковки содержат ошибку, то результат ошибка
// Если ровно одна упаковка содержит ошибку, то результат -- вторая
// Если обе упаковки содержат число, то результат это минимум из двух чисел.
struct maybe_int64 maybe_int64_min(struct maybe_int64 a, struct maybe_int64 b) {
    if (!(a.valid || b.valid)) {
        return (none_int64);
    }
    else {
        if (a.valid == false)
            return (some_int64(b.value));
        else if (b.valid == false) {
                return (some_int64(a.value));
             }
            else if (a.value <= b.value) {
                    return (some_int64(a.value));
                 }
                 else
                     return (some_int64(b.value));
    }
}