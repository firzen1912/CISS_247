/*	Brian Zen Limbert
*	CISS 247
*	Assignment 2
*	FALL 2022
*/

#define MAX_WORD_LEN 40
#define MAX_WORDS 110000
#define MAX_SUGGESTIONS 5
#define SUGGESTION_LENGTH_DIFF_TOLERANCE 1
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

char wordlist[MAX_WORDS][MAX_WORD_LEN];
int wordlistCount;

int suggestedCount = 0;

int mint(int a, int b){
	return (a > b) ? b : a;
}

int hamming(char *w1, char *w2){
	/*
		Function to determine the hamming distance between two words.
		This is a modified version of the hamming distance, it takes into account to distance between the different letters.
		For each length difference, it will count the same as if the difference is 26 letters.
		If a letter is different, then it will add to the distance by 100 + the ASCII difference.
		
		w1 : the first string
		w2 : the second string
		Returns an integer which is the hamming distance of the two words.
	*/
	int minlen = mint(strlen(w1), strlen(w2));
	int diff = abs(strlen(w1) - strlen(w2)) * 26;
	int ham = 0;
	int i;
	for(i = 0; i < minlen; i++){
		ham += abs(w1[i]-w2[i]);
		if(w1[i] != w2[i]){
			ham += 100;
		}
		
	}
	
	return ham + diff;
}

void hammingSortWords(char** arr, int wordCount, char* refWord){
	/*
		Function to sort the given array of strings according to their hamming distances and alphabetical order
		arr : the array of strings to sort
		wordCount : the length of the array
		Returns nothing, directly changes the given array.
	*/
	int i, j;
	int k = wordCount;
	char tmp[40];
	
	for(i = 0; i < k; i++){
      for(j = i+1; j < k; j++){
         if(hamming(arr[i], refWord) > hamming(arr[j], refWord)){
            strcpy(tmp, arr[i]);
            strcpy(arr[i], arr[j]);
            strcpy(arr[j], tmp);
         }else if(hamming(arr[i], refWord) == hamming(arr[j], refWord)){
         	if(strcmp(arr[i],arr[j]) > 0){
	            strcpy(tmp, arr[i]);
	            strcpy(arr[i], arr[j]);
	            strcpy(arr[j], tmp);
         	}
		 }
      }
   }
}

char** suggestWords(char* word, int max, int tolerance){
	/*
		Function to suggest words according to the global word list based on hamming distances between the given word.
		word : the base (possibly misspelled) word to compare against
		max : the maximum number of suggestions
		tolerance: the max length difference of the suggested words
		Returns an array of strings of the suggested words.
	*/
	suggestedCount = 0;
	int i;
	int len = strlen(word);
	
	char** words = (char**)malloc(max * sizeof(char*)); 
	
	for(i = 0; i < wordlistCount; i++){
		int diff = strlen(wordlist[i]) - len;
		if(abs(diff) <= tolerance){
			if(suggestedCount == 0){
				words[suggestedCount] = (char*)malloc(MAX_WORD_LEN * sizeof(char)); 
				strcpy(words[suggestedCount], wordlist[i]);
				suggestedCount++;
			}else{
				int j;
				int newHamming = hamming(wordlist[i], word);
				int worstHamming = -1;
				int worstIndex = -1;
				for(j = 0; j < suggestedCount; j++){
					int ham = hamming(words[j], word);
					if(ham > worstHamming){
						worstHamming = ham;
						worstIndex = j;
					}
				}
				if(newHamming < worstHamming){
					char* tmp = words[worstIndex];
					if(suggestedCount < max){
						words[suggestedCount] = (char*)malloc(MAX_WORD_LEN * sizeof(char)); 
						strcpy(words[suggestedCount], tmp);
						strcpy(words[worstIndex], wordlist[i]);
						suggestedCount++;
					}else{
						strcpy(words[worstIndex], wordlist[i]);
					}
				}else if(suggestedCount < max){
					words[suggestedCount] = (char*)malloc(MAX_WORD_LEN * sizeof(char)); 
					strcpy(words[suggestedCount], wordlist[i]);
					suggestedCount++;
				}
				
			}
		}
	}
	
	hammingSortWords(words, suggestedCount, word);
	
	return words;
}



int findWord(char* word){
	/*
		Function to determine if the given word is inside the global word list
		word : the given word to check
		Returns the index if the word is found, -1 if not.
	*/
	int i;
	for(i = 0; i < wordlistCount; i++){
		if(strcmp(word, wordlist[i]) == 0){
			return i;
		}
	}
	return -1;
}

int findLength(char* word, int tolerance){
	/*
		Function to determine if there is a word in the global word list that has a length within a specific bounds of the given word length
		word : the given word to check
		Returns 1 if there is at least one word that fulfills the condition, 0 if not.
	*/
	int i;
	for(i = 0; i < wordlistCount; i++){
		int diff = strlen(word) - strlen(wordlist[i]);
		if(abs(diff) <= tolerance){
			return 1;
		}
	}
	return 0;
}

int main(int argc, char *argv[]) { 
	if(argc < 2){
		printf("Please provide a file name!\n");
		return -1;
	}
	int i;
	printf("Loading dictionary..\n");
	FILE *input = fopen(argv[1], "r");
	while(!feof(input)){
		fgets(wordlist[wordlistCount], MAX_WORD_LEN, input);
		if(wordlist[wordlistCount][strlen(wordlist[wordlistCount]) - 1] == '\n'){
			wordlist[wordlistCount][strlen(wordlist[wordlistCount]) - 1] = '\0';
		}
		wordlistCount++;
	}
	
	printf("Dictionary loaded!\n");
	
	if(argc > 2){
		printf("Loading censored words..\n");
		FILE *censor = fopen(argv[2], "r");
		char cword[MAX_WORD_LEN];
		while(!feof(censor)){
			fgets(cword, MAX_WORD_LEN, censor);
			if(cword[strlen(cword) - 1] == '\n'){
				cword[strlen(cword) - 1] = '\0';
			}
			int idx = findWord(cword);
			if(idx != -1){
				strcpy(wordlist[idx], "");
			}
		}
		
		printf("Excluded censored words!\n");
	}
	
	char word[MAX_WORD_LEN];
	
	do{
		printf("Input a word to be checked: ");
		fgets(word, MAX_WORD_LEN, stdin);
		if(word[strlen(word) - 1] == '\n'){
			word[strlen(word) - 1] = '\0';
		}
		int len = strlen(word);
		for(i = 0; i < len; i++){
			if(word[i] >= 'A' && word[i] <= 'Z'){
				word[i] += ('a' - 'A');
			}
		}
		if(len != 0){
			if(findWord(word) != -1){
				printf("The word '%s' is spelled correctly according to the word list.\n", word);
			}else if (findLength(word, SUGGESTION_LENGTH_DIFF_TOLERANCE)){
				printf("We cannot find '%s' in the word list. Did you mean one of the following: \n", word);
				char** suggested = suggestWords(word, MAX_SUGGESTIONS, SUGGESTION_LENGTH_DIFF_TOLERANCE);
				
				for(i = 0; i < suggestedCount; i++){
					printf("-> %s\n", suggested[i]);
				}
			}else{
				printf("We cannot find '%s' in the word list and there is no suitable word in the word list to suggest.\n", word);
			}
		}else{
			printf("\nThank you for using spellchecker\n");
		}
		
	}while(strlen(word) != 0);

	
	return 0;
}
