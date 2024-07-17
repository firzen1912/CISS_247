#include <stdio.h>
#include <stdlib.h>

// function func1()
//Computing the bit-wise AND of two integers, using only the ~ and |
// parameters:
//      int x, int y
//return:
//      bit-wise AND of x and y using only ~ and | without &
  int func1(int x, int y ) {
    return (~(~x|~y));
  }

// function func2()
//Computing the bit-wise exclusive-or of two integers, using only the ~ and & operators.
// parameters:
//      int x, int y
//return:
//      bit-wise XOR of x and y using only ~ and & without |
  int func2(int x, int y){
    //return ((x+y)-((x&y)+(x&y)));
    return ~((~(~x & y))&(~(x & ~y)));
  }

// function func3()
//Return 1 if any odd-numbered bit in an integer is set to 1, and return 0 otherwise.
// parameters:
//      int x
//return:
//      1 if odd number bit is set to 1
  int func3(int x){
    int mask = (0xAA << 24)+(0xAA << 16)+(0xAA << 8)+(0xAA);
    return 0 != (x & mask);
  }

// function func4()
//Return 1 if all the odd-numbered bits in an integer are set to 1, and return 0 otherwise.
// parameters:
//      int x
//return:
//      1 if all number bit is set to 1
  int func4(int x){
    int mask = ((0xAA<<24) | (0xAA<<16) | (0xAA<<8) | (0xAA));
    return !((x & mask)^mask);
  }

  int main(){
    int Num1, Num2;
    int Option;
    unsigned int Hex;
    printf("Please Choose what function you want to use based on it number 1-4: ");
    scanf("%d",&Option);
    
    if(Option ==1 ){//Choose option 1
    printf("Welcome to function 1\n");
    printf("Please enter number x: ");
    scanf("%d",&Num1);
    printf("Please enter number y: ");
    scanf("%d",&Num2);
    printf("the AND of x and y is %d\n", func1(Num1,Num2));
    }
    if(Option == 2 ){//Choose option 2
    printf("Welcome to function 2\n");
    printf("Please enter number x: ");
    scanf("%d",&Num1);
    printf("Please enter number y: ");
    scanf("%d",&Num2);
    printf("the XOR of x and y is %d\n", func2(Num1,Num2));
    }

    if(Option == 3){//Choose option 3
    printf("Welcome to function 3\n");
    printf("Enter hexadecimal value without \"0X\": ");
    scanf("%X",&Hex);
    printf("The assessment are as follow: The return is %x\n", func3(Hex));
      if(func4(Hex)==1){
        printf("there are odd numbered bit set to 1\n");
      }else{
        printf("there are NO odd numbered bit set to 1\n");
      }
    }

    if(Option == 4){//Choose option 4
    printf("Welcome to function 4\n");
    printf("Enter hexadecimal value without \"0X\": ");
    scanf("%X",&Hex);
    printf("The assessment are as follow: The return is %x\n", func4(Hex));
      if(func4(Hex)==1){
        printf("all odd-numbered bits in the hex value set to 1\n");
      }else{
        printf("NOT all odd-numbered bits in the hex value are set to 1\n");
      }
    }
    if(Option !=1 && Option !=2 && Option !=3 && Option !=4){
    printf("invalid input, Please restart\n");
    }
}
