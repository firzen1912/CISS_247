#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int pCounter = 200;
char *pointer;
char memory[30][5][5];
int registers[33];


int registerCtoI(char *thisRegister){//convert value of a Register from Character to Int decimal
   char returnVal[5];
   sscanf(thisRegister, "X%s", returnVal);
   return strtol(returnVal, &pointer, 10);
}

int locateSource(char *src, char *val){
   int returnSrc = 0;
   char reg0[5], reg1[5];
   int hold1 = 0, hold2 = 0;

   sscanf(src,"[%s",reg0);
   hold1 = registerCtoI(reg0);

   sscanf(val, "%[^]]", reg1);
   sscanf(val, "#%s", reg0);
   hold2 = strtol(reg0, &pointer, 10);

   returnSrc = registers[hold1] + hold2;
   return returnSrc;
}

void ADDI(char *dest,char *src, char *immVal){
   char temp[5];
   int destInt = 0;
   int srcInt = 0; 
   int immValInt = 0;

   destInt = registerCtoI(dest);
   srcInt = registerCtoI(src);
   sscanf(immVal,"#%s",temp);
   immValInt = strtol(temp, &pointer, 10);

   registers[destInt] = registers[srcInt] + immValInt;
}

void ADD(char *dest,char *src, char *val){
   int destInt = 0;
   int srcInt = 0; 
   int valInt = 0;

   destInt = registerCtoI(dest);
   srcInt = registerCtoI(src);
   valInt = registerCtoI(val);

   registers[destInt] = registers[srcInt] + registers[valInt];
}

void SUBI(char *dest,char *src, char *immVal){
   char temp[5];
   int destInt = 0;
   int srcInt = 0; 
   int immValInt = 0;

   destInt = registerCtoI(dest);
   srcInt = registerCtoI(src);
   sscanf(immVal,"#%s",temp);
   immValInt = strtol(temp, &pointer, 10);
   
   registers[destInt] = registers[srcInt] - immValInt;
}

void SUB(char *dest,char *src, char *val){
   int destInt = 0;
   int srcInt = 0; 
   int valInt = 0;

   destInt = registerCtoI(dest);
   srcInt = registerCtoI(src);
   valInt = registerCtoI(val);
   
   registers[destInt] = registers[srcInt] - registers[valInt];
}

void STUR(char *dest,char *src, char *val){
   int returnVal = 0;
   char temp[5];
   int destInt = 0;
   int srcInt = 0;

   destInt = registerCtoI(dest);
   srcInt = locateSource(src,val);
   sprintf(temp, "%d\n", registers[destInt]);
   returnVal = (srcInt - 100)/4;
    
   strncpy(memory[returnVal][1], temp, sizeof(memory));
}

void LDUR(char *dest,char *src, char *val){
   int returnVal = 0;
   int hold = 0;
   int destInt = 0;
   int srcInt = 0;

   destInt = registerCtoI(dest);
   srcInt = locateSource(src,val);
   hold = (srcInt - 100)/4;
   returnVal = strtol(memory[hold][1], &pointer, 10);

   registers[destInt] = returnVal;
}

void B(char *dest) {
    int branchDest = 0;
    branchDest = strtol(dest, &pointer, 10);
    pCounter = branchDest;
}

int main(int argc, char* argv[]) 
{
	char buff[255];
   char insCounter[5];//instruction counter
   char instruction[5];//operation code
   char destRegister[5];//destination register 
   char srcRegister[5];//source register
   char enterValue[5];//the value will be operated on 
   int memoryLocation;
   int under200 = 0;//value under 200 counter
   int over200 = 0;// value over 200 counter
   char* fields[] = {insCounter, instruction, destRegister, srcRegister, enterValue};
   
   char fname[20];
	printf("Input the filename to be opened : ");
	scanf("%s",fname);//scan for the file name from user 
   FILE *fptr = fopen(fname, "r");

   printf("\n");
   registers[32] = 0; //set XZR register to zero
   while(fgets(buff, 50, fptr)) 
	{
      sscanf (buff,"%s %s %[^,], %[^,], %s\n", insCounter, instruction, destRegister, srcRegister, enterValue);
      for(int i = 0; i < 5; i++){
      strncpy(memory[under200+over200][i],fields[i],sizeof(memory));
      }
      memoryLocation = strtol(insCounter, &pointer, 10);
      if (memoryLocation < 200){
         under200++;
      }else if(memoryLocation >= 200){
         over200++;
      }
   }

   int progFinish = memoryLocation+ 4;

   while (pCounter < progFinish){

      int this = (pCounter-200)/4;
      this += under200;

      if((strcmp(memory[this][1], "ADDI") == 0)){
         ADDI(memory[this][2], memory[this][3], memory[this][4]);
         pCounter += 4;
      }
      if((strcmp(memory[this][1], "ADD") == 0)){
         ADD(memory[this][2], memory[this][3], memory[this][4]);
         pCounter += 4;
      }
      if((strcmp(memory[this][1], "SUBI") == 0)){
         SUBI(memory[this][2], memory[this][3], memory[this][4]);
         pCounter += 4;
      }
      if((strcmp(memory[this][1], "SUB") == 0)){
         SUB(memory[this][2], memory[this][3], memory[this][4]);
         pCounter += 4;
      }
      if((strcmp(memory[this][1], "LDUR") == 0)){
         LDUR(memory[this][2], memory[this][3], memory[this][4]);
         pCounter += 4;
      }
      if((strcmp(memory[this][1], "STUR") == 0)){
         STUR(memory[this][2], memory[this][3], memory[this][4]);
         pCounter += 4;
      }
      if((strcmp(memory[this][1], "B") == 0)){
         B(memory[this][2]);
      }

      printf("program count = %d", pCounter); //print program count
      printf(" Instruction: %s %s, %s, %s", memory[this][1], memory[this][2], memory[this][3], memory[this][4]); //print instructions 
      printf("\n"); 
      for (int k = 0; k < 32; k++){
         if (registers[k] > 0){
               printf("register X%d = %d \n", k, registers[k]); //print register values after following instructions
         }
      }
   printf("\n");
   }
}