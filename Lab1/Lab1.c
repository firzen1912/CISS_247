/*
 * Lab1.c
 * CSCI 247, Lab exercise 1, Fall, 2017
 * 
 * Trevin Morrison, October, 2017
 * 
 */



#include <stdio.h>
#include <string.h>

#define MAX_LINE    1024

// function find()
// searches for a substring in a string
// parameters:
//      substr: the substring to be found
//      str: the string to be searched for the substring
// return:
//      position in str where the substring starts, or
//      -1, if the substring was not found in str

int find(char *substr, char *str);

int find(char *substr, char *str) {
	int pos = -1;        // return value
	int len = strlen(str);  //length of passed string
	for (int i = 0; i < len; i++) { //continue loop until the end of string
 		    if ((str[i] == substr[0]) && (((str[i+1]) != '\0'))) {
		 	    pos = i; //^ If it starts with S, and if it can continue, if the next has a t
			    break;
 		    }
	}
	return pos;
}

// function replace
// replace part of a string by another string
// parameters:
//      str: the string to be modified
//      pos: the index in str where the modified string is to start
//      newstr: the substring to be used to modify str
void replace(char *str, int pos, char *substr);

void replace(char *str, int pos, char *substr) {
    int sublen = strlen(substr);//length of the substring 
    for(int x = 0; x < sublen; x++)
    {
        str[pos+x] = substr[x];//The substring will now be replace base on it length
    }
}




int main (int argc, char *argv[]) {
    
    // check for 3 command-line arguments
    if (argc < 3) {
        puts("Usage: ./Lab1 word1 word2\n");
        return 1;
    }
    
    // check that word1 and word2 are of equal length
    if (strlen(argv[1]) != strlen(argv[2])) {
        puts("The two words must have the same length\n");
        return 1;
    }
    
    // for each line of input, perform string replacement
    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, stdin)) {
        
        // remove the \n from the end of the line
        line[strlen(line)-1] = 0;
        
        // find word1 in line
        int pos = find(argv[1], line);
        
        // while word1 found in line, replace it
        while (pos >= 0) {
            replace(line, pos, argv[2]);
            pos = find(argv[1], line);
        } 
        puts(line);
    }
}
