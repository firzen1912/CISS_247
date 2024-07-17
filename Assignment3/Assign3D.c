#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_DIGITS 12

int vertical_space = 4;
int space_between_digit = 4;

char digits[20][120];
const int truthTable[MAX_DIGITS][7]={{1,1,1,0,1,1,1},{0,0,1,0,0,1,0},{1,0,1,1,1,0,1},{1,0,1,1,0,1,1},{0,1,1,1,0,1,0},{1,1,0,1,0,1,1},{1,1,0,1,1,1,1},{1,0,1,0,0,1,0},{1,1,1,1,1,1,1},{1,1,1,1,0,1,1},{0,0,0,1,0,0,0}};

//void display_digit_top_zone()
//using a truth table to load the top zone into digits[] array base on number being enter 
// parameters:
//      int number: number being load in 
//      int position: position within the digits array
//      int scale: scale of the number being load 
//      char *style: style of the number being load
void display_digit_top_zone(int number, int position, int scale, char *style){
    if(truthTable[number][0]==1){
        if(style[0] == 'n'){//normal format
            if(scale>=5){//scale5//scale 5
            digits[(scale-scale)][(scale-4) + position * space_between_digit]='_';
            }
            if(scale>=4){//scale4//scale 4
            digits[(scale-scale)][(scale-3) + position * space_between_digit]='_';
            }
            if(scale>=3){//scale3//scale 3
            digits[(scale-scale)][(scale-2) + position * space_between_digit]='_';
            }
            if(scale>=2){//scale2//scale 2
            digits[(scale-scale)][(scale-1) + position * space_between_digit]='_';
            }
            if(scale>=1){//scale1
            digits[(scale-scale)][(scale) + position * space_between_digit]='_';
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
        if(style[0] == 'b'){ //back slant format    
            if (scale==5){  
                digits[(scale-scale)][(scale-3)- 4 +position*space_between_digit]='_';
                digits[(scale-scale)][(scale-2)- 4 +position*space_between_digit]='_';             
                digits[(scale-scale)][(scale-1)- 4 +position*space_between_digit]='_';
                digits[(scale-scale)][(scale)- 4 +position*space_between_digit]='_';
                digits[(scale-scale)][(scale+1)- 4 +position*space_between_digit]='_';
            }        
            if (scale==4){  
                digits[(scale-scale)][(scale-3)- 2 +position*space_between_digit]='_';             
                digits[(scale-scale)][(scale-2)- 2 +position*space_between_digit]='_';
                digits[(scale-scale)][(scale-1)- 2 +position*space_between_digit]='_';
                digits[(scale-scale)][(scale)- 2 +position*space_between_digit]='_';
            }
            if (scale==3){
                digits[(scale-scale)][(scale-2)-1+position*space_between_digit]='_';
                digits[(scale-scale)][(scale-1)-1+position*space_between_digit]='_';
                digits[(scale-scale)][(scale)-1+position*space_between_digit]='_';
            }
            if (scale==2){
                digits[(scale-scale)][(scale-1)+position*space_between_digit]='_';
                digits[(scale-scale)][(scale)+position*space_between_digit]='_';
            }
        }
    }
}

//void display_digit_middle_zone()
//using a truth table to load the middle zone into digits[] array base on number being enter 
// parameters:
//      int number: number being load in 
//      int position: position within the digits array
//      int scale: scale of the number being load 
//      char *style: style of the number being load
void display_digit_middle_zone(int number, int position, int scale, char *style){
    for(int i=1; i<4; i++){
        if(truthTable[number][i]==1){
            if(style[0] == 'n'){//normal format
                switch(i){
                    case 1:// middle zone left region 
                    if(scale>=5){//scale5
                    digits[(scale-4)][position * space_between_digit]='|';
                    }
                    if(scale>=4){//scale4
                    digits[(scale-3)][position * space_between_digit]='|';
                    }
                    if(scale>=3){//scale3
                    digits[(scale-2)][position * space_between_digit]='|';
                    }
                    if(scale>=2){//scale2
                    digits[(scale-1)][position * space_between_digit]='|';
                    }
                    if(scale>=1){//scale1
                    digits[(scale)][position * space_between_digit]='|';
                    }
                    break;
                    
                    case 2: // middle zone right region
                    if(scale>=5){//scale5
                    digits[(scale-4)][(scale+1)+ position * space_between_digit]='|';
                    }
                    if(scale>=4){//scale4
                    digits[(scale-3)][(scale+1)+ position * space_between_digit]='|';
                    }
                    if(scale>=3){//scale3
                    digits[(scale-2)][(scale+1)+ position * space_between_digit]='|';
                    }
                    if(scale>=2){//scale2
                    digits[(scale-1)][(scale+1)+ position * space_between_digit]='|';
                    }
                    if(scale>=1){//scale1
                    digits[(scale)][(scale+1)+ position * space_between_digit]='|';
                    }
                    break;

                    case 3:// middle zone center region
                    if(scale>=5){//scale5
                    digits[(scale)][(scale-4)+ position * space_between_digit]='_';
                    }
                    if(scale>=4){//scale4
                    digits[(scale)][(scale-3)+ position * space_between_digit]='_';
                    }
                    if(scale>=3){//scale3
                    digits[(scale)][(scale-2)+ position * space_between_digit]='_';
                    }
                    if(scale>=2){//scale2
                    digits[(scale)][(scale-1)+ position * space_between_digit]='_';
                    }
                    if(scale>=1){//scale1
                    digits[(scale)][(scale)+ position * space_between_digit]='_';
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
                    digits[(scale)][(scale -1) + 1 + position * space_between_digit]='_';
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
            if(style[0] == 'b'){//back slant format   
                switch(i){    
                    case 1:// middle zone left region
                    if (scale==5){       
                    digits[(scale-4)][(scale-1)-8 +position*space_between_digit]='\\';         
                    digits[(scale-3)][(scale-2)-6 +position*space_between_digit]='\\';
                    digits[(scale-2)][(scale-3)-4 +position*space_between_digit]='\\';
                    digits[(scale-1)][(scale-4)-2 +position*space_between_digit]='\\';
                    digits[(scale)][(scale-5)+position*space_between_digit]='\\';
                    }
                    if (scale==4){
                    digits[(scale-3)][(scale)-6 +position*space_between_digit]='\\';
                    digits[(scale-2)][(scale-1)-4 +position*space_between_digit]='\\';
                    digits[(scale-1)][(scale-2)-2+position*space_between_digit]='\\';
                    digits[(scale)][(scale-3)+position*space_between_digit]='\\';
                    }
                    if (scale==3){
                    digits[(scale-2)][(scale)-4 +position*space_between_digit]='\\';
                    digits[(scale-1)][(scale-1)-2+position*space_between_digit]='\\';
                    digits[(scale)][(scale-2)+position*space_between_digit]='\\';
                    }
                    if (scale==2){
                    digits[(scale-1)][(scale+1)-2+position*space_between_digit]='\\';
                    digits[(scale)][(scale)+position*space_between_digit]='\\';
                    }
                    break;

                    case 2:// middle zone right region  
                    if (scale==5){
                    digits[(scale-4)][(scale + 6)-8+position*space_between_digit]='\\';  
                    digits[(scale-3)][(scale + 5)-6+position*space_between_digit]='\\';         
                    digits[(scale-2)][(scale + 4)-4+position*space_between_digit]='\\';
                    digits[(scale-1)][(scale + 3)-2+position*space_between_digit]='\\';
                    digits[(scale)][(scale + 2)+position*space_between_digit]='\\';
                    }
                    if (scale==4){      
                    digits[(scale-3)][(scale + 5)-6+position*space_between_digit]='\\';         
                    digits[(scale-2)][(scale + 4)-4+position*space_between_digit]='\\';
                    digits[(scale-1)][(scale + 3)-2+position*space_between_digit]='\\';
                    digits[(scale)][(scale + 2)+position*space_between_digit]='\\';
                    }
                    if (scale==3){
                    digits[(scale-2)][(scale + 4)-4+position*space_between_digit]='\\';
                    digits[(scale-1)][(scale + 3)-2+position*space_between_digit]='\\';
                    digits[(scale)][(scale + 2)+position*space_between_digit]='\\';
                    }
                    if (scale==2){
                    digits[(scale-1)][(scale+4)-2+position*space_between_digit]='\\';
                    digits[(scale)][(scale+3)+position*space_between_digit]='\\';
                    }
                    break;
                    
                    case 3:// middle zone center region
                    if (scale==5){
                    digits[(scale)][(scale - 5) + 1+ position * space_between_digit]='_';
                    digits[(scale)][(scale - 4) + 1+ position * space_between_digit]='_';
                    digits[(scale)][(scale - 3) + 1+ position * space_between_digit]='_';
                    digits[(scale)][(scale - 2) + 1+ position * space_between_digit]='_';
                    digits[(scale)][(scale -1) + 1 + position * space_between_digit]='_';
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

//void display_digit_bottom_zone()
//using a truth table to load the bottom zone into digits[] array base on number being enter 
// parameters:
//      int number: number being load in 
//      int position: position within the digits array
//      int scale: scale of the number being load 
//      char *style: style of the number being load
void display_digit_bottom_zone(int number, int position, int scale, char *style){
    for(int i=4; i<7; i++){
        if(truthTable[number][i]==1){
            if(style[0] == 'n'){//normal format
                switch(i){
                    case 4: // bottom zone left region
                    if(scale>=5){//scale5
                    digits[(scale+4)][position * space_between_digit]='|';
                    }
                    if(scale>=4){//scale4
                    digits[(scale+3)][position * space_between_digit]='|';
                    }
                    if(scale>=3){//scale3
                    digits[(scale+2)][position * space_between_digit]='|';
                    }
                    if(scale>=2){//scale2
                    digits[(scale+1)][position * space_between_digit]='|';
                    }
                    if(scale>=1){//scale1
                    digits[(scale+scale)][position * space_between_digit]='|';
                    }
                    break;

                    case 5:// bottom  zone right region
                    if(scale>=5){//scale5
                    digits[scale+4][(scale+1)+ position * space_between_digit]='|';
                    }
                    if(scale>=4){//scale4
                    digits[scale+3][(scale+1)+ position * space_between_digit]='|';
                    }
                    if(scale>=3){//scale3
                    digits[scale+2][(scale+1)+ position * space_between_digit]='|';
                    }
                    if(scale>=2){//scale2
                    digits[scale+1][(scale+1)+ position * space_between_digit]='|';
                    }
                    if(scale>=1){//scale1
                    digits[(scale+scale)][(scale+1)+ position * space_between_digit]='|';
                    }
                    break;

                    case 6: // bottom  zone center region
                    if(scale>=5){//scale5
                    digits[(scale+scale)][(scale-4)+ position * space_between_digit]='_';
                    }
                    if(scale>=4){//scale4
                    digits[(scale+scale)][(scale-3)+ position * space_between_digit]='_';
                    }
                    if(scale>=3){//scale3
                    digits[(scale+scale)][(scale-2)+ position * space_between_digit]='_';
                    }
                    if(scale>=2){//scale2
                    digits[(scale+scale)][(scale-1)+ position * space_between_digit]='_';
                    }
                    if(scale>=1){//scale1
                    digits[(scale+scale)][(scale)+ position * space_between_digit]='_';
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
            if(style[0] == 'b'){//back slant format
                switch(i){
                    case 4:// bottom zone left region  
                    if (scale==5){
                    digits[(scale+4)][(scale-9)+8+position*space_between_digit]='\\';  
                    digits[(scale+3)][(scale-8)+6+position*space_between_digit]='\\';     
                    digits[(scale+2)][(scale-7)+4+position*space_between_digit]='\\';
                    digits[(scale+1)][(scale-6)+2+position*space_between_digit]='\\';
                    digits[(scale+scale)][(scale-10)+10+position*space_between_digit]='\\';
                    }
                    if (scale==4){         
                    digits[(scale+3)][(scale-6)+6+position*space_between_digit]='\\';     
                    digits[(scale+2)][(scale-5)+4+position*space_between_digit]='\\';
                    digits[(scale+1)][(scale-4)+2+position*space_between_digit]='\\';
                    digits[(scale+scale)][(scale-7)+8+position*space_between_digit]='\\';
                    }
                    if (scale==3){
                    digits[(scale+2)][(scale-4)+4+position*space_between_digit]='\\';
                    digits[(scale+1)][(scale-3)+2+position*space_between_digit]='\\';
                    digits[(scale+scale)][(scale-5)+6+position*space_between_digit]='\\';
                    }
                    if (scale==2){
                    digits[(scale+1)][(scale-1)+2+position*space_between_digit]='\\';
                    digits[(scale+scale)][(scale-scale)+4+position*space_between_digit]='\\';
                    }
                    break;

                    case 5:// bottom  zone right region
                    if (scale==5){ 
                    digits[(scale+4)][(scale-2)+8+position*space_between_digit]='\\';
                    digits[(scale+3)][(scale-1)+6+position*space_between_digit]='\\';
                    digits[(scale+2)][(scale)+4+position*space_between_digit]='\\';
                    digits[(scale+1)][(scale+1)+2+position*space_between_digit]='\\';
                    digits[(scale+scale)][(scale-3)+10+position*space_between_digit]='\\';
                    } 
                    if (scale==4){
                    digits[(scale+3)][(scale-1)+6+position*space_between_digit]='\\';
                    digits[(scale+2)][(scale)+4+position*space_between_digit]='\\';
                    digits[(scale+1)][(scale+1)+2+position*space_between_digit]='\\';
                    digits[(scale+scale)][(scale-2)+8+position*space_between_digit]='\\';
                    }
                    if (scale==3){
                    digits[(scale+2)][(scale)+4+position*space_between_digit]='\\';
                    digits[(scale+1)][(scale+1)+2+position*space_between_digit]='\\';
                    digits[(scale+scale)][(scale-1)+6+position*space_between_digit]='\\';
                    }
                    if (scale==2){
                    digits[(scale+1)][(scale+2)+2+position*space_between_digit]='\\';
                    digits[(scale+scale)][(scale+1)+4+position*space_between_digit]='\\';
                    }
                    break;

                    case 6:// bottom  zone center region 
                    if (scale==5){
                    digits[(scale+scale)][(scale-9)+10+position*space_between_digit]='_';
                    digits[(scale+scale)][(scale-8)+10+position*space_between_digit]='_';
                    digits[(scale+scale)][(scale-7)+10+position*space_between_digit]='_';
                    digits[(scale+scale)][(scale-6)+10+position*space_between_digit]='_';
                    digits[(scale+scale)][(scale-5)+10+position*space_between_digit]='_';
                    }
                    if (scale==4){
                    digits[(scale+scale)][(scale-6)+8+position*space_between_digit]='_';
                    digits[(scale+scale)][(scale-5)+8+position*space_between_digit]='_';
                    digits[(scale+scale)][(scale-4)+8+position*space_between_digit]='_';
                    digits[(scale+scale)][(scale-3)+8+position*space_between_digit]='_';
                    }
                    if (scale==3){
                    digits[(scale+scale)][(scale-4)+6+position*space_between_digit]='_';
                    digits[(scale+scale)][(scale-3)+6+position*space_between_digit]='_';
                    digits[(scale+scale)][(scale-2)+6+position*space_between_digit]='_';
                    }
                    if (scale==2){
                    digits[(scale+scale)][(scale-1)+4+position*space_between_digit]='_';
                    digits[(scale+scale)][(scale)+4+position*space_between_digit]='_';
                    }
                    break;
                }  
            } 
        }    
    }
}

//void clear_digits_array()
//clear the digits array to make sure the display is correct
void clear_digits_array(void){
    for(int a = 0; a < vertical_space; a++){
        for(int b = 0; b<MAX_DIGITS* space_between_digit; b++){
            digits[a][b]=' ';
        }
    }
}

//void display_all_top_zone()
//load the all top zone display into digits[] array base on the user input  
// parameters:
//      char *input: the user input to determine many number will be load into digits array
//      int scale: scale of the number being load 
//      char *style: style of the number being load
void display_all_top_zone(char *input, int scale, char *style){
    int number = 0;
    int position = 0;
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
            display_digit_top_zone(number,position + 1,scale, style);
            position++;
        }
    }
}

//void display_all_middle_zone()
//load the all middle zone display into digits[] array base on the user input  
// parameters:
//      char *input: the user input to determine many number will be load into digits array
//      int scale: scale of the number being load 
//      char *style: style of the number being load
void display_all_middle_zone(char *input, int scale, char *style){
    int number = 0;
    int position = 0;
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
            display_digit_middle_zone(number,position + 1,scale, style);
            position++;
        }
    }
}

//void display_all_bottom_zone()
//load the all bottom zone display into digits[] array base on the user input  
// parameters:
//      char *input: the user input to determine many number will be load into digits array
//      int scale: scale of the number being load 
//      char *style: style of the number being load
void display_all_bottom_zone(char *input, int scale, char *style){
    int number = 0;
    int position = 0;
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
            display_digit_bottom_zone(number,position + 1,scale, style);
            position++;
        }
    }
    for(int a = 0; a < vertical_space; a++){
        for(int b = 0; b <MAX_DIGITS*space_between_digit; b++){
        printf("%c",digits[a][b]);
        }
        printf("\n");
    }
}

//void display_all_zone()
//display content of the digits array base on user input, scale and style of the digit
// parameters:
//      char *input: the user input to determine many number will be load into digits array
//      int scale: scale of the number being load 
//      char *style: style of the number being load
void display_all_zone (char *input, char *scaler, char *style){
    int scale = atoi(scaler);
    if ((style[0] == 'f' ||style[0] == 'b') && scale ==1){//make sure scale 1 will turn into 2 in forward and back slant
        scale = 2;
    }

    for (int a = 1; a < scale;a++){//create space according to the current scale
    space_between_digit++;
    vertical_space = vertical_space + 2;
    }

    if(scale == 5){space_between_digit++;}//special case to create proper out put for scale 5

    clear_digits_array();// clear digits array

    display_all_top_zone(input, scale, style);
    display_all_middle_zone(input, scale, style);
    display_all_bottom_zone(input, scale, style);
}

int main(int argc, char *argv[]) {
    char *input = argv[1];// user input number
    char *scaler = argv[2];// user input scale
    char *style = argv[3];// user input style
   
    if(argc < 2){// if no scale or style specify default to scale 1 and style normal (no slant)
    printf("No number where enter, please try again\n");

    }else if(argc == 2){// if no scale or style specify default to scale 1 and style normal (no slant)
    display_all_zone(input, "1", "n");

    }else if(argc == 3){// if scale is specified while style is not, default to style normal (no slant)
        if (strcmp(scaler,"1")==0||strcmp(scaler,"2")==0||strcmp(scaler,"3")==0||strcmp(scaler,"4")==0||strcmp(scaler,"5")==0){// scale have to be between 1 and 5
            display_all_zone(input, scaler, "n");
        }else{
            printf("Cannot scale any bigger than 5\n");// if scale is bigger than 5 report this error 
            vertical_space = 0;
        }

    }else if(argc == 4){// if scale and style is specified
        if (strcmp(scaler,"1")==0||strcmp(scaler,"2")==0||strcmp(scaler,"3")==0||strcmp(scaler,"4")==0||strcmp(scaler,"5")==0){// scale have to be between 1 and 5
            if (style[0] == 'n' || style[0] == 'f'|| style[0] == 'b'){// only allow n(normal), f(forward),b(back) to be use as style
                display_all_zone(input, scaler, style);
            }else {
                printf("invalid format, Please try again\n");// if invalid format is inputted report this error
                vertical_space = 0;
            }
        }else{
            printf("Cannot scale any bigger than 5\n");// if scale is bigger than 5 report this error
            vertical_space = 0;
        }
    }else {
        printf("Invalid input, please only enter 3 agurment\n");
    }
}
    