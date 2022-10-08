/*
Используя уже реализованные функции не составит труда сделать функцию list_reverse, создающую перевернутую копию списка. Не забудьте отразить в коде, что она не изменяет сам список. 

Вы можете пользоваться уже определённой функцией list_add_front.

Sample Input:

9 2 37 4 2

Sample Output:

2 4 37 2 9
*/

void list_add_front1( struct list** old, int64_t value ) {
    struct list* new = node_create( value );
    if (!*old) {
        *old = new;
    }
    else {
    new->next = *old;
    *old = new;
    }
}

size_t list_length1( const struct list* a) {
  size_t count = 0;
  while(a) {
      count++;
      a = a->next;
  }
    return count;
}

struct maybe_int64 list_at1(  const struct list* a, size_t idx ) {
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

// создать перевернутую копию списка
struct list* list_reverse(  const struct list* a ) {
    if (a) {
    struct list* c = node_create( list_at1( a, 0).value );
    for (size_t i = 1 ; i < list_length1(a); i++) {
         list_add_front1(&c, list_at1( a, i ).value);
    }
    return c;
    }
    else
        return NULL;
}