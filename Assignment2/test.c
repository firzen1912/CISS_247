#include <stdio.h>
#include <string.h>
#include <ctype.h>
  
void censoring(char* word, char* sentence){
    int len = strlen(word);
    if (len && word[len - 1] == '\n') word[--len] = '\0';
    for (char *p = sentence; (p = strstr(p, word)) != NULL; )
        while (isalpha(*p))
            *p++ = '*';
  
}
int main() {
    printf("Enter a sentence: ");
    char sentence[1024];
    fgets(sentence, sizeof sentence, stdin);
    int len = strlen(sentence);
    if (len && sentence[len - 1] == '\n') sentence[--len] = '\0';
  
    printf("Enter a word to censor: ");
    char word[128];
    fgets(word, sizeof word, stdin);
    censoring(word,sentence);
    printf("%s\n", sentence);
  
    return 0;
}