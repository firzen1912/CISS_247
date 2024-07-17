#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_DIGITS 15
int vertical_space = 4;
int space_between_digit = 3;

char digits[20][MAX_DIGITS* 10];
const int truthTable[MAX_DIGITS][7]={{1,1,1,0,1,1,1},{0,0,1,0,0,1,0},{1,0,1,1,1,0,1},{1,0,1,1,0,1,1},{0,1,1,1,0,1,0},{1,1,0,1,0,1,1},{1,1,0,1,1,1,1},{1,0,1,0,0,1,0},{1,1,1,1,1,1,1},{1,1,1,1,0,1,1},{0,0,0,1,0,0,0}};

void process_top_zone(int digit, int position, int scale, char *style){
    if(truthTable[digit][0]==1){
        if(style[0] == 'n'){//normal format
            if(scale>=5){
            digits[(scale-scale)][(scale-4) + position * space_between_digit]='_';//scale 5
            }
            if(scale>=4){
            digits[(scale-scale)][(scale-3) + position * space_between_digit]='_';//scale 4
            }
            if(scale>=3){
            digits[(scale-scale)][(scale-2) + position * space_between_digit]='_';//scale 3
            }
            if(scale>=2){
            digits[(scale-scale)][(scale-1) + position * space_between_digit]='_';//scale 2
            }
            if(scale>=1){
            digits[(scale-scale)][(scale) + position * space_between_digit]='_';//scale 1
            }
        }

        if(style[0] == 'f'){//forward slant format
            if (scale==5){  
                digits[(scale-scale)][(scale-3)+ 4 + position * space_between_digit]='_';
                digits[(scale-scale)][(scale-2)+ 4 + position * space_between_digit]='_';             
                digits[(scale-scale)][(scale-1)+ 4 + position * space_between_digit]='_';
                digits[(scale-scale)][(scale)+ 4 + position * space_between_digit]='_';
                digits[(scale-scale)][(scale+1)+ 4 + position * space_between_digit]='_';
            }        
            if (scale==4){  
                digits[(scale-scale)][(scale-3)+ 4 + position * space_between_digit]='_';             
                digits[(scale-scale)][(scale-2)+ 4 + position * space_between_digit]='_';
                digits[(scale-scale)][(scale-1)+ 4 + position * space_between_digit]='_';
                digits[(scale-scale)][(scale)+ 4 + position * space_between_digit]='_';
            }
            if (scale==3){
                digits[(scale-scale)][(scale-2)+ 4 + position * space_between_digit]='_';
                digits[(scale-scale)][(scale-1)+ 4 + position * space_between_digit]='_';
                digits[(scale-scale)][(scale)+ 4 + position * space_between_digit]='_';
            }
            if (scale==2){
                digits[(scale-scale)][(scale-1)+ 4 + position * space_between_digit]='_';
                digits[(scale-scale)][(scale)+ 4 + position * space_between_digit]='_';
            }
        }

    }
}
void process_middle_zone(int digit, int position, int scale, char *style){
    for(int i=1; i<4; i++){
        if(truthTable[digit][i]==1){
            if(style[0] == 'n'){//normal format
                switch(i){
                    case 1:// middle zone left region 
                    if(scale>=5){
                    digits[(scale-4)][position * space_between_digit]='|';//scale 5
                    }
                    if(scale>=4){
                    digits[(scale-3)][position * space_between_digit]='|';//scale 4
                    }
                    if(scale>=3){
                    digits[(scale-2)][position * space_between_digit]='|';//scale 3
                    }
                    if(scale>=2){
                    digits[(scale-1)][position * space_between_digit]='|';//scale 2
                    }
                    if(scale>=1){
                    digits[(scale)][position * space_between_digit]='|';//scale 1
                    }
                    break;
                    
                    case 2: // middle zone right region
                    if(scale>=5){
                    digits[(scale-4)][(scale+1)+ position * space_between_digit]='|';//scale 5
                    }
                    if(scale>=4){
                    digits[(scale-3)][(scale+1)+ position * space_between_digit]='|';//scale 4
                    }
                    if(scale>=3){
                    digits[(scale-2)][(scale+1)+ position * space_between_digit]='|';//scale 3
                    }
                    if(scale>=2){
                    digits[(scale-1)][(scale+1)+ position * space_between_digit]='|';//scale 2
                    }
                    if(scale>=1){
                    digits[(scale)][(scale+1)+ position * space_between_digit]='|';//scale 1
                    }
                    break;

                    case 3:// middle zone center region
                    if(scale>=5){
                    digits[(scale)][(scale-4)+ position * space_between_digit]='_';//scale 5
                    }
                    if(scale>=4){
                    digits[(scale)][(scale-3)+ position * space_between_digit]='_';//scale 4
                    }
                    if(scale>=3){
                    digits[(scale)][(scale-2)+ position * space_between_digit]='_';//scale 3
                    }
                    if(scale>=2){
                    digits[(scale)][(scale-1)+ position * space_between_digit]='_';//scale 2
                    }
                    if(scale>=1){
                    digits[(scale)][(scale)+ position * space_between_digit]='_';//scale 1
                    }
                    break;
                }
            }

            if(style[0] == 'f'){//forward slant format
                switch(i){         
                    case 1:// middle zone left region
                    if (scale==5){       
                    digits[(scale-4)][(scale-1) + position * space_between_digit]='/';         
                    digits[(scale-3)][(scale-2) + position * space_between_digit]='/';
                    digits[(scale-2)][(scale-3) + position * space_between_digit]='/';
                    digits[(scale-1)][(scale-4)+ position * space_between_digit]='/';
                    digits[(scale)][(scale-5)+ position * space_between_digit]='/';
                    }
                    if (scale==4){
                    digits[(scale-3)][(scale) + position * space_between_digit]='/';
                    digits[(scale-2)][(scale-1) + position * space_between_digit]='/';
                    digits[(scale-1)][(scale-2)+ position * space_between_digit]='/';
                    digits[(scale)][(scale-3)+ position * space_between_digit]='/';
                    }
                    if (scale==3){
                    digits[(scale-2)][(scale) + position * space_between_digit]='/';
                    digits[(scale-1)][(scale-1)+ position * space_between_digit]='/';
                    digits[(scale)][(scale-2)+ position * space_between_digit]='/';
                    }
                    if (scale==2){
                    digits[(scale-1)][(scale+1)+ position * space_between_digit]='/';
                    digits[(scale)][(scale)+ position * space_between_digit]='/';
                    }
                    break;

                    case 2:// middle zone right region  
                    if (scale==5){
                    digits[(scale-4)][(scale + 6)+ position * space_between_digit]='/';  
                    digits[(scale-3)][(scale + 5)+ position * space_between_digit]='/';         
                    digits[(scale-2)][(scale + 4)+ position * space_between_digit]='/';
                    digits[(scale-1)][(scale + 3)+ position * space_between_digit]='/';
                    digits[(scale)][(scale + 2)+ position * space_between_digit]='/';
                    }
                    if (scale==4){      
                    digits[(scale-3)][(scale + 5)+ position * space_between_digit]='/';         
                    digits[(scale-2)][(scale + 4)+ position * space_between_digit]='/';
                    digits[(scale-1)][(scale + 3)+ position * space_between_digit]='/';
                    digits[(scale)][(scale + 2)+ position * space_between_digit]='/';
                    }
                    if (scale==3){
                    digits[(scale-2)][(scale + 4)+ position * space_between_digit]='/';
                    digits[(scale-1)][(scale + 3)+ position * space_between_digit]='/';
                    digits[(scale)][(scale + 2)+ position * space_between_digit]='/';
                    }
                    if (scale==2){
                    digits[(scale-1)][(scale+4)+ position * space_between_digit]='/';
                    digits[(scale)][(scale+3)+ position * space_between_digit]='/';
                    }
                    break;

                    case 3:// middle zone center region
                    if (scale==5){
                    digits[(scale)][(scale - 5) + 1+ position * space_between_digit]='_';
                    digits[(scale)][(scale - 4) + 1+ position * space_between_digit]='_';
                    digits[(scale)][(scale - 3) + 1+ position * space_between_digit]='_';
                    digits[(scale)][(scale - 2) + 1+ position * space_between_digit]='_';
                    digits[(scale)][(scale - 1) + 1 + position * space_between_digit]='_';
                    }
                    if (scale==4){
                    digits[(scale)][(scale - 3) + 1+ position * space_between_digit]='_';
                    digits[(scale)][(scale - 2) + 1+ position * space_between_digit]='_';
                    digits[(scale)][(scale - 1) + 1+ position * space_between_digit]='_';
                    digits[(scale)][(scale) + 1 + position * space_between_digit]='_';
                    } 
                    if (scale==3){
                    digits[(scale)][(scale - 2) + 1+ position * space_between_digit]='_';
                    digits[(scale)][(scale - 1) + 1+ position * space_between_digit]='_';
                    digits[(scale)][(scale) + 1 + position * space_between_digit]='_';
                    }
                    if (scale==2){
                    digits[(scale)][(scale+2)+ position * space_between_digit]='_';
                    digits[(scale)][(scale+1)+ position * space_between_digit]='_';
                    }
                    break;
                }
            }
        }
    }
}

void process_bottom_zone(int digit, int position, int scale, char *style){
    for(int i=4; i<7; i++){
        if(truthTable[digit][i]==1){
            if(style[0] == 'n'){//normal format
                switch(i){
                    case 4: // bottom zone left region
                    if(scale>=5){
                    digits[(scale+4)][position * space_between_digit]='|';//scale 5
                    }
                    if(scale>=4){
                    digits[(scale+3)][position * space_between_digit]='|';//scale 4
                    }
                    if(scale>=3){
                    digits[(scale+2)][position * space_between_digit]='|';//scale 3
                    }
                    if(scale>=2){
                    digits[(scale+1)][position * space_between_digit]='|';//scale 2
                    }
                    if(scale>=1){
                    digits[(scale+scale)][position * space_between_digit]='|';//scale 1
                    }
                    break;

                    case 5:// bottom  zone right region
                    if(scale>=5){
                    digits[scale+4][(scale+1)+ position * space_between_digit]='|';//scale 5
                    }
                    if(scale>=4){
                    digits[scale+3][(scale+1)+ position * space_between_digit]='|';//scale 4
                    }
                    if(scale>=3){
                    digits[scale+2][(scale+1)+ position * space_between_digit]='|';//scale 3
                    }
                    if(scale>=2){
                    digits[scale+1][(scale+1)+ position * space_between_digit]='|';//scale 2
                    }
                    if(scale>=1){
                    digits[(scale+scale)][(scale+1)+ position * space_between_digit]='|';//scale 1
                    }
                    break;

                    case 6: // bottom  zone center region
                    if(scale>=5){
                    digits[(scale+scale)][(scale-4)+ position * space_between_digit]='_';//scale 5
                    }
                    if(scale>=4){
                    digits[(scale+scale)][(scale-3)+ position * space_between_digit]='_';//scale 4
                    }
                    if(scale>=3){
                    digits[(scale+scale)][(scale-2)+ position * space_between_digit]='_';//scale 3
                    }
                    if(scale>=2){
                    digits[(scale+scale)][(scale-1)+ position * space_between_digit]='_';//scale 2
                    }
                    if(scale>=1){
                    digits[(scale+scale)][(scale)+ position * space_between_digit]='_';//scale 1
                    }
                    break;
                }
            }

            if(style[0] == 'f'){//forward slant format
                switch(i){
                    case 4:// bottom zone left region  
                    if (scale==5){
                    digits[(scale+4)][(scale-9)+ position * space_between_digit]='/';  
                    digits[(scale+3)][(scale-8)+ position * space_between_digit]='/';     
                    digits[(scale+2)][(scale-7)+ position * space_between_digit]='/';
                    digits[(scale+1)][(scale-6)+ position * space_between_digit]='/';
                    digits[(scale+scale)][(scale-10)+ position * space_between_digit]='/';
                    }
                    if (scale==4){         
                    digits[(scale+3)][(scale-6)+ position * space_between_digit]='/';     
                    digits[(scale+2)][(scale-5)+ position * space_between_digit]='/';
                    digits[(scale+1)][(scale-4)+ position * space_between_digit]='/';
                    digits[(scale+scale)][(scale-7)+ position * space_between_digit]='/';
                    }
                    if (scale==3){
                    digits[(scale+2)][(scale-4)+ position * space_between_digit]='/';
                    digits[(scale+1)][(scale-3)+ position * space_between_digit]='/';
                    digits[(scale+scale)][(scale-5)+ position * space_between_digit]='/';
                    }
                    if (scale==2){
                    digits[(scale+1)][(scale-1)+ position * space_between_digit]='/';
                    digits[(scale+scale)][(scale-scale)+ position * space_between_digit]='/';
                    }
                    break;

                    case 5:// bottom  zone right region
                    if (scale==5){ 
                    digits[(scale+4)][(scale-2)+ position * space_between_digit]='/';
                    digits[(scale+3)][(scale-1)+ position * space_between_digit]='/';
                    digits[(scale+2)][(scale)+ position * space_between_digit]='/';
                    digits[(scale+1)][(scale+1)+ position * space_between_digit]='/';
                    digits[(scale+scale)][(scale-3)+ position * space_between_digit]='/';
                    } 
                    if (scale==4){
                    digits[(scale+3)][(scale-1)+ position * space_between_digit]='/';
                    digits[(scale+2)][(scale)+ position * space_between_digit]='/';
                    digits[(scale+1)][(scale+1)+ position * space_between_digit]='/';
                    digits[(scale+scale)][(scale-2)+ position * space_between_digit]='/';
                    }
                    if (scale==3){
                    digits[(scale+2)][(scale)+ position * space_between_digit]='/';
                    digits[(scale+1)][(scale+1)+ position * space_between_digit]='/';
                    digits[(scale+scale)][(scale-1)+ position * space_between_digit]='/';
                    }
                    if (scale==2){
                    digits[(scale+1)][(scale+2)+ position * space_between_digit]='/';
                    digits[(scale+scale)][(scale+1)+ position * space_between_digit]='/';
                    }
                    break;

                    case 6:// bottom  zone center region 
                    if (scale==5){
                    digits[(scale+scale)][(scale-9)+ position * space_between_digit]='_';
                    digits[(scale+scale)][(scale-8)+ position * space_between_digit]='_';
                    digits[(scale+scale)][(scale-7)+ position * space_between_digit]='_';
                    digits[(scale+scale)][(scale-6)+ position * space_between_digit]='_';
                    digits[(scale+scale)][(scale-5)+ position * space_between_digit]='_';
                    }
                    if (scale==4){
                    digits[(scale+scale)][(scale-6)+ position * space_between_digit]='_';
                    digits[(scale+scale)][(scale-5)+ position * space_between_digit]='_';
                    digits[(scale+scale)][(scale-4)+ position * space_between_digit]='_';
                    digits[(scale+scale)][(scale-3)+ position * space_between_digit]='_';
                    }
                    if (scale==3){
                    digits[(scale+scale)][(scale-4)+ position * space_between_digit]='_';
                    digits[(scale+scale)][(scale-3)+ position * space_between_digit]='_';
                    digits[(scale+scale)][(scale-2)+ position * space_between_digit]='_';
                    }
                    if (scale==2){
                    digits[(scale+scale)][(scale-1)+ position * space_between_digit]='_';
                    digits[(scale+scale)][(scale)+ position * space_between_digit]='_';
                    }
                    break;
                }
            } 
        }    
    }
}

void clear_digits_array(void){
    for(int a = 0; a < vertical_space; a++){
        for(int b = 0; b<MAX_DIGITS* space_between_digit; b++){
            digits[a][b]=' ';
        }
    }
}

void read_input (char *input, char *scaler, char *style){
    int number = 0;
    int position = 0;
    int scale = atoi(scaler);
    
    if (style[0] == 'f' && scale ==1){//make sure 1 f will turn into forward slant
        scale = 2;
    }

    for (int a = 1; a < scale;a++){//create space according to the current scale
    space_between_digit++;
    vertical_space = vertical_space + 2;
    }
    clear_digits_array();
    int inputLen = strlen(input);
    for(int i = 0; i < inputLen; i++){
        switch(input[i]){
            case '0': number = 0;
                break;
            case '1': number = 1;
                break;
            case '2': number = 2;
                break;
            case '3': number = 3;
                break;
            case '4': number = 4;
                break;
            case '5': number = 5;
                break;
            case '6': number = 6;
                break;
            case '7': number = 7;
                break;
            case '8': number = 8;
                break;
            case '9': number = 9;
                break;
            case '-': number = 10;// this is where minus is store in the truth table
                break;
            default: number=' ';
        }

        if(position<inputLen){
            if (scale >= 1 && scale <=5){
                if (style[0] == 'n' || style[0] == 'f'){
                    process_top_zone(number,position,scale, style);
                    process_middle_zone(number,position,scale, style);
                    process_bottom_zone(number,position,scale, style);
                }else {
                    printf("invalid format, Please try again\n");
                    vertical_space = 0;
                    break;
                }
            }else{
                printf("Cannot scale any bigger than 5\n");
                vertical_space = 0;
                break;
            }
            position++;
        }
    }
}

void print_digits_array(void){
    for(int a = 0; a < vertical_space; a++){
        for(int b = 0; b <MAX_DIGITS*space_between_digit; b++){
        printf("%c",digits[a][b]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    char *input = argv[1];
    char *scaler = argv[2];
    char *style = argv[3];
    if(argc == 2){
    read_input(input, "1", "n");
    print_digits_array();
    }else if(argc == 3){
    read_input(input, scaler, "n");
    print_digits_array();
    }else if(argc > 3){
    read_input(input, scaler, style);
    print_digits_array();
    }
    
}