#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>

int maior ()
{
 int r = INT_MIN;
 while (1)
 {
  int n;
  assert(scanf("%d", &n) == 1);
  if (n == 0) break;
  if (n > r) r = n;
 }
 return r;
}

double average()
{
 double av; int total = 0;
 while (1) 
 {
  int n;
  assert(scanf("%d",&n) == 1);
  if (n == 0) break;
  av += n;    
  ++total;
 }
 return av / total;
}

int sGreatest () {
 int secGreat = INT_MIN;
 int Great = INT_MIN;
 while (1){
  int n;
  assert(scanf("%d", &n) == 1);
  if (n == 0) break;
  if (n > Great)
  {
   secGreat = Great;
   Great = n;
  }
 }
 return secGreat;
}

int bitsUm (unsigned int n) {
  int r = 0;
  while (n){
  r += (n%2);
  n >>= 1; 
 }    
 return r;
}

int trailingZ(unsigned int n) {
 if (n%2) return 0; // if n = 2k + 1 then we know there are no 0s at the end of the representation
 else return 1 + trailingZ(n >> 1); // recursive call, shift
}

int qDig (unsigned int n) {
 if (n/10 < 1) return 1;
 else return 1 + qDig (n/10);
}

char * mystrcat (char s1[], char s2[]) 
{
 char * cat = s1;
 while (*s1) s1++;
 while ((*s1=*s2)) {s1++;s2++;}
 *s1 = '\0';
 return cat;
}

char * mystrcpy (char s2[], char s1[])
{
 char * copy = s2;
 while ((*s2=*s1)) {s1++;s2++;}
 return copy;
}

int mystrcmp(char s1[], char s2[])
{
 while (*s1 == *s2 && *s1) 
 { 
  s1++;
  s2++;
 }
 return *s1 - *s2;
}
main(){
    // memory allocation
    char * s1 = malloc(1024 * sizeof(char));
    char * s2 = malloc(1024 * sizeof(char));
    //printf("The largest value in the given sequence is: %d\n", maior());
    //printf("The average of the given sequence is: %.5f\n",average());
    //printf("The second largest value in the given sequence is: %d\n", sGreatest());
    //printf("The number of bits that are 1 is: %d\n", bitsUm(1111001));
    //printf("The number of bits that are 0 at the end is: %d\n",trailingZ(112));
    // getting strings for testings
    printf("s1: ");
    gets(s1);
    printf("s2: ");
    gets(s2);
    // strcat testing
    //printf("concat: %s\n", mystrcat(s1,s2));
    // strcpy testing
    //printf("copy: %s\n", mystrcpy(s2,s1));
    /* STRCMP testing 
    int x = mystrcmp(s1,s2);
    if (x > 0){
     printf("S1 is greater!\n");
    }
    else if (x < 0){
     printf("S2 is greater!\n");
    } 
    else{
     printf("They are the same!\n");
    }
    */
    //memory freeing
    free(s1); free(s2);
}
