/* define это команда сделать текстовую замену
 * Каждое слово STACK_SIZE в этом файле 
 * будет заменено на 3 */

#define STACK_SIZE 3
int stack_contents[STACK_SIZE] = {0};
/* позиция сразу за верхушкой */
int stack_position = 0;

int stack_full() { return stack_position == STACK_SIZE; }
int stack_empty() { return stack_position == 0; }

int stack_push( int value ) {
  if (! stack_full() ) {
    stack_contents[stack_position] = value;
    stack_position = stack_position + 1;
    return 1;
  }
  else { return 0; }
}

int stack_pop( int* value ) {
  if ( ! stack_empty())  {
    stack_position = stack_position - 1;
    *value = stack_contents[stack_position];
    return 1;
  }
  else { return 0; }
}