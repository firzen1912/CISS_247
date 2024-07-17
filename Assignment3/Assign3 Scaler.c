//
//output should be        _   _        _   _   _   _   _   _
//                     |  _|  _|  |_| |_  |_    | |_| |_| | |
//                     | |_   _|    |  _| |_|   | |_|   | |_|

#include <stdio.h>
#define MAX_DIGITS 10

char digits[3][MAX_DIGITS*4];
const int array[MAX_DIGITS][7]={{1,1,1,0,1,1,1},{0,0,1,0,0,1,0},{1,0,1,1,1,0,1},{1,0,1,1,0,1,1},{0,1,1,1,0,1,0},{1,1,0,1,0,1,1},{1,1,0,1,1,1,1},{1,0,1,0,0,1,0},{1,1,1,1,1,1,1},{1,1,1,1,0,1,1},};

void clear_digits_array(void){
    for(int i=0;i<3;i++){
        for(int j=0;j<MAX_DIGITS*4;j++){
            digits[i][j]=' ';
        }
    }
}

void process_digit(int digit, int position){
    for(int i=0;i<7;i++){
        if(array[digit][i]==1){
            switch(i){
                case 0: digits[0][1+position*4]='_';
                    break;
                case 1: digits[1][0+position*4]='|';
                    break;
                case 2: digits[1][2+position*4]='|';
                    break;
                case 3: digits[1][1+position*4]='_';
                    break;
                case 4: digits[2][0+position*4]='|';
                    break;
                case 5: digits[2][2+position*4]='|';
                    break;
                case 6: digits[2][1+position*4]='_';
                    break;
            }
        }    
    }
}

void process_digit_forward_slanted(int digit, int position,int scale){
    int test = 4;
    for(int i=0;i<7;i++){
        if(truthTable[digit][i]==1){
            switch(i){
                case 0: 
                digits[(scale-scale)][(scale-1)+ test +position*SPACE_BETWEEN_DIGIT]='_';// top zone
                digits[(scale-scale)][(scale)+ test +position*SPACE_BETWEEN_DIGIT]='_';// top zone
                break;
                case 1: 
                digits[(scale-1)][(test-1)+position*SPACE_BETWEEN_DIGIT]='/';// middle zone left region
                digits[(scale)][(test-2)+position*SPACE_BETWEEN_DIGIT]='/';// middle zone left region
                break;
                case 2: 
                digits[(scale-1)][(test+2)+position*SPACE_BETWEEN_DIGIT]='/';// middle zone right region
                digits[(scale)][(test+1)+position*SPACE_BETWEEN_DIGIT]='/';// middle zone right region
                break;
                case 3: 
                digits[(scale)][(test)+position*SPACE_BETWEEN_DIGIT]='_';// middle zone center region
                digits[(scale)][(test-1)+position*SPACE_BETWEEN_DIGIT]='_';// middle zone center region
                break;
                case 4: 
                digits[(scale+1)][(test-test+1)+position*SPACE_BETWEEN_DIGIT]='/';// bottom zone left region
                digits[(scale+scale)][(test-test)+position*SPACE_BETWEEN_DIGIT]='/';// bottom zone left region
                break;
                case 5: 
                digits[(scale+1)][(test)+position*SPACE_BETWEEN_DIGIT]='/';// bottom  zone right region
                digits[(scale+scale)][(test-1)+position*SPACE_BETWEEN_DIGIT]='/';// bottom  zone right region
                break;
                case 6: 
                digits[(scale+scale)][(test-test+1)+position*SPACE_BETWEEN_DIGIT]='_';// bottom  zone center region
                digits[(scale+scale)][(test-test+2)+position*SPACE_BETWEEN_DIGIT]='_';
                break;
            }
        }    
    }
}

void print_digits_array(void){
    for(int a = 0; a < 3; a++){
        for(int b = 0; b <MAX_DIGITS*4; b++)
            printf("%c",digits[a][b]);
        printf("\n");
    }
    printf("\n");
}

int main(void) {
    char character_number='\0';
    int a=0;
    clear_digits_array();
    printf("Enter a number:");
    while ((character_number=getchar())!='\n') {
        int number=MAX_DIGITS;
        switch(character_number){
            case '0': number=0;
                break;
            case '1': number=1;
                break;
            case '2': number=2;
                break;
            case '3': number=3;
                break;
            case '4': number=4;
                break;
            case '5': number=5;
                break;
            case '6': number=6;
                break;
            case '7': number=7;
                break;
            case '8': number=8;
                break;
            case '9': number=9;
                break;
            default: number=' ';
        }
        if(a<MAX_DIGITS){
            process_digit(number,a);
            a++;
        }
    }
    print_digits_array();
    return 0;
}