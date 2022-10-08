/*
Полезно уметь находить последний элемент списка. Напишите функцию list_last, которая вернёт адрес последнего элемента списка. 

Sample Input:

6 12 0893 1 2   

Sample Output:

2
*/

struct list* list_last( struct list * list ) {
  while (list) {
      if (!list->next)
          break;
      list = list->next;
  }
  return list;
}
