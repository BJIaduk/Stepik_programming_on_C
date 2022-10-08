/*
Реализуйте упакованный указатель на строку, которая выделена в куче.
*/

struct heap_string {
  char* addr;
};

// скопировать в кучу
struct heap_string halloc( const char* s ) {
    //s = malloc(sizeof(s));
    struct heap_string c;
    size_t i = 0;
    while (s[i] != '\0')
        i++;
    i++;
    c.addr = malloc(sizeof(char)*i);
    for (size_t j = 0; j < i; j++) {
       // &(c->addr[j]) = malloc(sizeof(char));
        c.addr[j] = s[j];
    }
    return c;
}

// освободить память
void heap_string_free( struct heap_string h ) {
    free(h.addr);
}