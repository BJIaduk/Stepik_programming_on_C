/*
Теперь на основе list_last мы можем реализовать функцию list_add_back, дописывающую элемент в конец списка.  Не забудьте про пустые списки!

Вы можете вызывать функции:

struct list* list_last( struct list * list );
void list_add_front( struct list** old, int64_t value );
struct list* node_create( int64_t value );
Sample Input:

1 2 3 4 5

Sample Output:

1 2 3 4 5 9 8 7
*/

void list_add_back( struct list** old, int64_t value ) {
    struct list* new = node_create( value );
    if (!*old) {
        *old = new;
    }
    else {
    struct list* last = list_last( *old );
    last->next = new;
    }
}
