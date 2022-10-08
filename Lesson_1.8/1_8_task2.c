/*
Рассмотрим реализацию простейшего стека из чисел размера 3. 
В него можно положить число и забрать его с вершины стека. 
При этом мы кодируем проверки: нельзя забрать число из пустого стека 
или положить его в заполненный полностью стек.
*/

#include "stack.h"

void stack_try_push( int i ) {
    if ( stack_push( i ) ) { 
        printf( "Pushed %d\n", i);
    } else { printf( "Can't push %d\n", i); }
}

void stack_try_pop() {
    int i = 0;
    if ( stack_pop( &i ) ) {
        printf( "Popped %d\n", i);
    } else { printf( "Can't pop\n" ); }
}

int main() {
    stack_try_push( 42 );
    stack_try_push( 44 );
    stack_try_push( 48 ); 
    stack_try_pop();
    stack_try_pop();
    stack_try_pop(); 

    return 0;
}