#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LIMIT 50

int read_line(char str[], int n);
int compare_strings(const void *p, const void *q);
void empty(char *list);

int main()
{
    char input_buffer[1001];
    int length = 0;
    char *sentence = NULL;
    char *sentences[50 + 1];
    int num_sentences = 0;

    // Write code that reads many strings inputs:
    int i = 0;
    for (; i < LIMIT - 1; ++i)
    {
        printf ("Please type a sentence:\n");
        read_line(input_buffer, 1000);

        if (strcmp(input_buffer, "") == 0)
          break; 


    \section{}
        length = strlen(input_buffer);
        sentences[i] = malloc(length+1);

        if(sentences[i] == NULL)
        {
        printf("malloc failed");
        return 0;
        }
        
        strcpy(sentences[i], input_buffer);
        empty(input_buffer);
        } 
      num_sentences = i;

		
    qsort(sentences, num_sentences, sizeof(char *), compare_strings);

    for (char **p = &sentences[0]; *p; ++p)
      printf ("%s\n", *p);
	 
   return 0;
}

void empty(char *list)
{
    while(*list++)
      *list = '\0';
}

int read_line(char str[], int n)
{
  int ch, i = 0;
  
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;
  }
  str[i] = '\0';
  return i;
}

int compare_strings(const void *p, const void *q)
{
	return strcmp(*(char **)p, *(char **)q);
}

