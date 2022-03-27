#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkVowel (char *s)
{
 if (*s == 'a' || *s == 'e' || *s == 'i' || *s == 'o' || *s == 'u') return 1;
 return 0;
}

int contaVogais (char * s)
{
 int r = 0;
 while (*s){ 
  if (checkVowel(s)) r++;
  s++;
 }
 return r; 
}

void retiraVogaisRep (char *s) // this is not an array
{
 char temp[sizeof(s)/sizeof(char)];
 int j = 0;
 for (int i = 0; s[i] != '\0'; i++){
  if (s[i] == temp[j] && checkVowel(s)) j++;
  else temp[j] = s[i];
 }
 temp[j] = '\0';
 s = temp;
}

main()
{
 char * s = "Hello World"; // Pointer to string
 char * i = "aa";
 printf("%d\n", contaVogais(s));
 retiraVogaisRep(i);
 printf("%s\n",i);
}
