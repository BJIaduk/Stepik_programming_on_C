/*
Напишите функции:

string_count: считает длину строки в байтах (не включая нуль-терминатор) 
string_words: считает количество слов в строке. 
Между словами стоит произвольное количество пробельных символов:

пробела ' '
табуляции '\t'
перевода строки '\n'
Пробельные символы также могут стоять в начале или конце строки; 
не гарантируется, что в строке будет хотя бы один символ или 
хотя бы одно слово.

Sample Input:

hello  world
Sample Output:

length: 12 words: 2
*/

int is_whitespace(char c) { return c == ' ' || c == '\t' || c == '\n'; }

int string_count(char* str) {
   int i = 0;
   while (str[i])
       i++;
   return i;
}

int string_words(char* str)  {
    int a = 0;
    for (int i = 0; str[i]; i++) {
        while (is_whitespace(str[i]) && str[i]) {
            i++;
        }
        if (str[i])
            a++;
        else
            break;
        while (!is_whitespace(str[i]) && str[i]) {
            i++;
        }
        i--;
    }
    return a;
}