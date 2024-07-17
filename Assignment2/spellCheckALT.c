//	Khang Tran
//	CISS 247
//	Assignment 2
//	FALL 2022

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_WORD_LEN 40
#define MAX_WORDS 110000
char wordlist[MAX_WORDS][MAX_WORD_LEN];
char censoredList[MAX_WORDS];
int wordListCount;
int censoredListCount=0;
int suggestionCount = 0;


//function hammingDist()
//this function will return hamming distance between two word 
// parameters:
//      word1: first word
//      word2: second word
//return:
//      hamdist: hamming distance between these two words
int hammingDist(char* word1, char* word2){
    int hamdist = 0;
    for(int i = 0; i < strlen(word1); i++){
        if (word1[i] != word2[i]){
            hamdist++;
        }
    }
    return hamdist;
}

//function sortSuggestion()
//this function sort suggestion base on alphabet and hamming dist
// parameters:
//      arr: character array that will be sorted
//      wordCount: the amount word in the array 
void sortSuggestion(char** array, int wordCount){
 	char temp[40];
 	for(int i=0; i<wordCount; i++){
        for(int j=0; j<wordCount-1-i; j++){
            if(strcmp(array[j], array[j+1]) > 0){
            //swap array[j] and array[j+1]
            strcpy(temp, array[j]);
            strcpy(array[j], array[j+1]);
            strcpy(array[j+1], temp);
            }
        }
    }  
}

//function suggestionWords()
//this function find suggestion for the spelling correction base on the input word
// parameters:
//      word: the word that will be checked
//      amount: the amount of the suggestion
//      tolerance: the difference between length of word and wordlist
//      precision: the hamming distance allowance between word and wordlist 
char** suggestionWords(char* word, int amount, int tolerance, int precision){
	char** suggestion = (char**)malloc(MAX_WORD_LEN  * sizeof(char*)); 
	for(int i = 0; i < wordListCount; i++){
        int lenDiff = strlen(wordlist[i]) - strlen(word);
        if(hammingDist(word,wordlist[i]) == precision){//check the hamming dist base on precision
            if(wordlist[i][0] == word[0]){// check if the first character of wordlist match input word
                if(abs(lenDiff) <= tolerance ){//check the length different base on Length
				    if(suggestionCount < amount){//check the amount of suggestion
                        suggestion[suggestionCount] = (char*)malloc(MAX_WORD_LEN * sizeof(char)); 
				        strncpy(suggestion[suggestionCount], wordlist[i],strlen(wordlist[i]));
                        suggestionCount++;
                    }
                }
            }
        }
    }
    sortSuggestion(suggestion, suggestionCount);
    return suggestion;
}

//function findWord()
//this function compare word to word in the dictionary
// parameters:
//      word: word to find
//return:
//      return wordlist location when matched else return 1
int findWord(char* word){
    for(int i = 0; i < wordListCount; i++){
        if(hammingDist(word,wordlist[i]) == 0 && strlen(word) == strlen(wordlist[i])-1){
        return i;
        }
    }
    return -1;
}

//function lowerCase()
//This function turn character into lower case 
// parameters:
//      word: word to turn into lower case
void lowerCase(char *word){
	for(int i = 0; i < strlen(word); i++){
        word[i] = tolower(word[i]);
	}
}

//function loadDictionary()
//This function load the dictionary text file 
// parameters:
//      filename: filename of the dictionary text file 
void loadDictionary (char *filename){
    printf("Loading dictionary\n");
    FILE *dict = fopen(filename, "r");
        while(fgets(wordlist[wordListCount], MAX_WORD_LEN, dict)){
            if(wordlist[wordListCount][strlen(wordlist[wordListCount]) - 1] == '\n'){
	            wordlist[wordListCount][strlen(wordlist[wordListCount]) - 1] = '\0';
	        }
        lowerCase(wordlist[wordListCount]);
        wordListCount++;
        }
    printf("Loading completed\n");
}    

//function loadCensored()
//This function load the censored text file 
// parameters:
//      filename: filename of the censored text file 
void loadCensored (char *filename){
    printf("Loading censored words..\n");
		FILE *censor = fopen(filename, "r");
		while(fgets(censoredList, MAX_WORD_LEN, censor)){
			if(censoredList[strlen(censoredList) - 1] == '\n'){
	            censoredList[strlen(censoredList) - 1] = '\0';
	        }
        int idx = findWord(censoredList);
	    if(idx != -1){
	    strcpy(wordlist[idx], " ");
	    }
            lowerCase(censoredList);
            censoredListCount++;
		}
	printf("Excluded censored words!\n");
}

int main(int argc, char* argv[]) 
{
    	if(argc < 2){
		printf("Please enter file name!\n");
		return -1;
	    }
        if (argc == 2){
            loadDictionary(argv[1]);
        }

    	if(argc == 3){
            loadDictionary(argv[1]);
            loadCensored(argv[2]);
		}
        if(argc > 3){
		printf("Too many argument!\n");
		return -1;
        }
        
    char word[MAX_WORD_LEN];
    
	while(strlen(word) != 0){
        printf("Input a word to be checked: ");
        fgets(word, MAX_WORD_LEN, stdin);
   
	    if(word[strlen(word) - 1] == '\n'){
		    word[strlen(word) - 1] = '\0';
	    }

        lowerCase(word);

        if(strlen(word) != 0){
		    if(findWord(word) != -1){
			    printf("'%s' is spelled correctly. ", word);
                printf("This word is located at line %d in the dictionary file\n\n",findWord(word)+1);
            }else if (findWord(word) == -1){
				char** suggestion = suggestionWords(word, 5, 2, 1);
                if(suggestion[0] != NULL){
                printf("Did you mean one of the following:\n");
                    for(int i = 0; i < suggestionCount; i++){
		                printf("-> %s\n", suggestion[i]);
	                }
                    suggestionCount = 0;
                }
		        if(suggestion[0] == NULL){
				    printf("cannot find '%s' in the dictionary file\n", word);
                    printf("Do you want to add '%s' into the dictionary Y/N\n", word);
                }
            }
        }else{
            printf("\nThank you for using this program\n");
        }
    }
}
