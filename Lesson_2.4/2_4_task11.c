/*
И, наконец, реализуем чтение списка со входа. Читать числа будем пока это возможно.

Например, если на вход подаются числа 1, 3, 5, 8, нужно вернуть из функции список 
с этими числами в том же порядке.

Вы можете использовать функции node_create и maybe_read_int64  из предыдущего шага 
(она и реализует чтение "пока возможно").
*/

struct list* list_read() {
    struct maybe_int64 n = maybe_read_int64();
    if (n.valid) {
    struct list* a = node_create(n.value);
    struct list** z = &a;
    while (n.valid) {
        n = maybe_read_int64();
        if (n.valid) {
        a->next = node_create(n.value);
        a = a->next;
        }
    }
    return *z;
    }
    else
        return NULL;
}
