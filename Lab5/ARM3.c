#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int pCounter = 200;
char memory[1000][5][5];
int registers[32];

//function registerCtoI()
//this function convert value of a Register from Character to Integer decimal
//parameters:
//      registerChar: the character that will be change to integer
//return:
//      return ReturnVal: the integer value of the character 
int registerCtoI(char *registerChar){
   int returnVal = 0;
   char tempChar[5];

   if(strcmp(registerChar, "SP") == 0){// identify Stack Pointer
      return 28;
   }else if(strcmp(registerChar, "LR") == 0){// identify Link Register
      return 30;
   }else if(strcmp(registerChar, "ZR") == 0){// identify XZR Register
      return 31;
   }else{
      sscanf(registerChar, "X%s", tempChar);//identify current Register if not above 
   }

   returnVal = atoi(tempChar);
   return returnVal;
   
}

//function locateSource()
//this function locate the source for STUR and LDUR funtion 
//parameters:
//      src: the source register 
//      val: the value that appear in STUR and LDUR
//return:
//      return the location of the register 
int locateSource(char *src, char *val){
   char location[5], exclude[5];
   int hold1 = 0, hold2 = 0;

   sscanf(src,"[%s",location);// handle the register location in STUR and LDUR
   hold1 = registerCtoI(location);

   sscanf(val, "%[^]]", exclude);// excluding the ] in STUR and LDUR
   sscanf(val, "#%s", location);// handle the value being used in STUR and LDUR 
   hold2 = atoi(location);

   int registerLocation = registers[hold1] + hold2;//identify the location to STUR and LDUR 

   if(hold1 == 28){
      return registerLocation / 5;// if the register is Stack Pointer divide by 5
   }else{
      return registerLocation;// else return the register location 
   }
}

//function ADDI()
//this function will emulate ARM ADDI function 
//parameters:
//      dest: the destination register 
//      src: the source register 
//      immval: the value being use 
void ADDI(char *dest,char *src, char *immVal){
   char temp[5];
   int destInt = 0;
   int srcInt = 0; 
   int immValInt = 0;

   destInt = registerCtoI(dest);
   srcInt = registerCtoI(src);

   sscanf(immVal,"#%s",temp);
   immValInt = atoi(temp);

   registers[destInt] = registers[srcInt] + immValInt;
}

//function ADD()
//this function will emulate ARM ADD function 
//parameters:
//      dest: the destination register 
//      src: the source register 
//      val: the value being use from a register
void ADD(char *dest,char *src, char *val){
   int destInt = 0;
   int srcInt = 0; 
   int valInt = 0;

   destInt = registerCtoI(dest);
   srcInt = registerCtoI(src);
   valInt = registerCtoI(val);

   registers[destInt] = registers[srcInt] + registers[valInt];
}

//function SUBI()
//this function will emulate ARM SUBI function 
//parameters:
//      dest: the destination register 
//      src: the source register 
//      immval: the value being use 
void SUBI(char *dest,char *src, char *immVal){
   char temp[5];
   int destInt = 0;
   int srcInt = 0; 
   int immValInt = 0;

   destInt = registerCtoI(dest);
   srcInt = registerCtoI(src);

   sscanf(immVal,"#%s",temp);
   immValInt = atoi(temp);
   
   registers[destInt] = registers[srcInt] - immValInt;
}

//function SUB()
//this function will emulate ARM SUB function 
//parameters:
//      dest: the destination register 
//      src: the source register 
//      val: the value being use from a register
void SUB(char *dest,char *src, char *val){
   int destInt = 0;
   int srcInt = 0; 
   int valInt = 0;

   destInt = registerCtoI(dest);
   srcInt = registerCtoI(src);
   valInt = registerCtoI(val);
   
   registers[destInt] = registers[srcInt] - registers[valInt];
}

//function STUR()
//this function will emulate ARM STUR function 
//parameters:
//      dest: the destination register 
//      src: the source register 
//      val: the value being use from a register
void STUR(char *dest,char *src, char *val){
   int returnVal = 0;
   char temp[5];
   int destInt = 0;
   int srcInt = 0;

   destInt = registerCtoI(dest);
   srcInt = locateSource(src,val);

   sprintf(temp, "%d\n", registers[destInt]);
   
   if(strcmp(src, "[SP") == 0){
      returnVal = srcInt;
      strcpy(memory[returnVal][1], temp);
   }else{
      returnVal = (srcInt - 100)/4;
      strcpy(memory[returnVal][1], temp);
   }
}

//function LDUR()
//this function will emulate ARM LDUR function 
//parameters:
//      dest: the destination register 
//      src: the source register 
//      val: the value being use from a register
void LDUR(char *dest,char *src, char *val){
   int returnVal = 0;
   int destInt = 0;
   int srcInt = 0;

   destInt = registerCtoI(dest);
   srcInt = locateSource(src,val);

   if(strcmp(src, "[SP") == 0){
      returnVal = srcInt;
      registers[destInt] = atoi(memory[returnVal][1]); 
   }else{
      returnVal = (srcInt - 100)/4;
      registers[destInt] = atoi(memory[returnVal][1]);
   }
}

//function CBNZ()
//this function will emulate ARM CBNZ function 
//parameters:
//      dest: the destination register 
//      src: the source register 
void CBNZ(char *dest, char *src){
   int branchDest = 0;
   int destInt = 0;

   destInt = registerCtoI(dest);

   if(registers[destInt] == 0){for(int i = 0; i < 4; i++){pCounter++;}}
   if(registers[destInt] != 0){
      branchDest = atoi(src);
      pCounter = branchDest;
   }
}

//function B()
//this function will emulate ARM B function 
//parameters:
//      dest: the destination register 
void B(char *dest) {
    int branchDest = 0;
    branchDest = atoi(dest);
    pCounter = branchDest;
}

//function BR()
//this function will emulate ARM BR function 
//parameters:
//      dest: the destination register 
void BR(char *dest) {
    int branchDest = 0;
    branchDest = registerCtoI(dest);
    pCounter = registers[branchDest];
}

//function BL()
//this function will emulate ARM BL function 
//parameters:
//      dest: the destination register 
void BL(char *dest) {
    int branchDest = 0;
    int progDest = 0;
    branchDest = registerCtoI("LR");
    registers[branchDest] = pCounter += 4;
    progDest = atoi(dest);
    pCounter = progDest;
}

int main(int argc, char* argv[]) 
{
	char buff[255];
   char progCounter[5];//program counter
   char instruction[5];//operation code
   char destRegister[5];//destination register 
   char srcRegister[5];//source register
   char enterValue[5];//the value will be operated on 
   int under200 = 0;//row under 200 counter
   int over200 = 0;//row over 200 counter
   int memoryLocation;
   registers[31] = 0; //set XZR register to zero
   registers[28] = 1000;// set Stack Pointer 
   
   FILE *file = fopen(argv[1], "r");
   if(argc == 2){
      while(fgets(buff, 50, file)) 
      {
         // Separate data from Instruction file to different chunk of smaller data 
         sscanf (buff,"%s %s %[^,], %[^,], %s\n", progCounter, instruction, destRegister, srcRegister, enterValue);

         strncpy(memory[under200+over200][0], progCounter, 6);// load from Instruction file Program Counter to memory 
         strncpy(memory[under200+over200][1], instruction, 6);// load from Instruction file Instruction to memory 
         strncpy(memory[under200+over200][2], destRegister, 6);// load from Instruction file Destination Register to memory 
         strncpy(memory[under200+over200][3], srcRegister, 6);// load from Instruction file Source Register to memory 
         strncpy(memory[under200+over200][4], enterValue, 6);// load from Instruction file Value to memory 

         memoryLocation = atoi(progCounter);
         if (memoryLocation < 200){
            under200++;
         }else if(memoryLocation >= 200){
            over200++;
         }
      }
   }else{
      printf("Bad Input.Please Again With this format './ARM filename.txt'\n");
   }

   int progFinish = memoryLocation+ 4;
   char input[5];
   while (pCounter < progFinish && pCounter != 0 && strlen(input) != 0){

      printf("Please press 'Enter' to continue");
      fgets(input, 5, stdin);

      int this = (pCounter - 200)/4;
      this += under200;

      //Register Change Instruction 
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
      //Condition Branch Instruction
      if((strcmp(memory[this][1], "CBNZ") == 0)){
         CBNZ(memory[this][2], memory[this][3]);
      }
      //Brach Instruction
      if((strcmp(memory[this][1], "B") == 0)){
         B(memory[this][2]);
      }
      if((strcmp(memory[this][1], "BL") == 0)){
         BL(memory[this][2]);
      }
      if((strcmp(memory[this][1], "BR") == 0)){
         BR(memory[this][2]);
      }

      printf("\nInstruction Executed: %s %s, %s, %s", memory[this][1], memory[this][2], memory[this][3], memory[this][4]); //print instructions set
      printf("\nPC = %d, ", pCounter); //print program counter
      printf("SP = %d, ", registers[28]);
      printf("LR = %d ", registers[30]);
      printf("\n"); 
      for (int k = 0; k < 32; k++){
            if(k == 28 || k == 30){
               continue;
            }else if(registers[k] != 0){
               printf("X%d = %d\n", k, registers[k]);
            }
      }
      
      printf("Stack:");
      for(int i = 200; i >= registers[28]/5; i--){
         if (memory[i][0] != NULL){
            printf("\n%d: %s", i*5, memory[i][1]);
         }
      }

      if(registers[28] < 30 || registers[28] > 1000){//Stack will overflow if it under 30 or over 1000
         printf("\nStack Overflow\n");
         exit(0);
      }
   printf("\n");
   }
}