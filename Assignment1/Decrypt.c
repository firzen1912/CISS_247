#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function getKeys()
// returns two smaller key with the same length base on the length of the bigkeys
// parameters:
//      bigkeys, the key this function will take in
//      key1, first 4 character of big key turn into int version of them
//      key2, last 4 character of big key turn into int version of them
void getKeys (char *bigkeys,unsigned *key1,unsigned *key2)
{
    int keyLen = strlen(bigkeys);//length of big key
    unsigned return1 = 0;
    unsigned return2 = 0;

    for(int i = 0; i < keyLen; i++){
        if(i<keyLen/2){ //this make sure two split the key in half base on it length
        return1 |= (bigkeys[i] << 7 * (3-i));
        }
        else{
        return2 |= (bigkeys[i] << 7 * (7-i));
        }
    }

    *key1 = return1;//return key1 
    *key2 = return2;//return key2
}

// function shuffleNibbles()
// shuffle the bit base on given algorithm 
// parameters:
//      bits, the bit value that will be shuffle then return after
void shuffleNibbles (unsigned *bits)
{
    unsigned holder = *bits;
    unsigned shuffle = 0;

    shuffle |= (holder&0x000000F) << 24; //shuffle n6 from index 6 to 0
    shuffle |= (holder&0x00000F0) << 16; //shuffle n5 from index 5 to 1
    shuffle |= (holder&0x0000F00) << 8;  //shuffle n4 from index 4 to 2
    shuffle |= (holder&0x000F000) >> 12; //shuffle n3 from index 0 to 3
    shuffle |= (holder&0x00F0000) >> 8;  //shuffle n2 from index 2 to 4
    shuffle |= (holder&0x0F00000) >> 16; //shuffle n1 from index 1 to 5
    shuffle |= (holder&0xF000000) >> 12; //shuffle n0 from index 3 to 6

    *bits = shuffle;//return the bits
}

// function get_n_bits()
// mask the bit by each septep then put them into 28bits format
// parameters:
//      bits, the bit value that will be cut base on width
//      index, how far will in move 
// return:
//      scaler, the septet value after being scale base on index
unsigned int scaleSeptet(unsigned bits, int index)
{
    unsigned holder = bits;
    unsigned scaler = 0;

    if(index == 3){scaler = (holder & 0xfe00000) >> (index * 7);}// mask the first set of 7 bit then shift it by 21
    
    if(index == 2){scaler = (holder & 0x01fc000) >> (index * 7);}// mask the second set of 7 bit then shift it by 14

    if(index == 1){scaler = (holder & 0x0003f80) >> (index * 7);}// mask the third set of 7 bit then shift it by 7

    if(index == 0){scaler = (holder & 0x000007f) >> (index * 7);}// mask the fourth set of 7 bit then shift it by 0
    
    return scaler;
}

// function rotateSeptet()
// rotate the septet base on the given algorithm
// parameters:
//      bits, the bit value that will be rotate in septet then return after
// return:
//      returnBits, the bit value that is rotated
unsigned int rotateSeptet(unsigned bits)
{
    unsigned rotate = 0;
    unsigned bitToGrab = 0;
    unsigned bitRemain = 0;
    unsigned returnBits = 0; 

    for (int i = 3; i >= 0; i--){//separate bits into septeps for each increment start at index 3 from right to left
        rotate = scaleSeptet(bits,i);                 // order the septep base on their index
        bitToGrab = (rotate & 112) >> 4;              // mask, shift and store first 3 bit -->0000|bitToGrab(111)|
        bitRemain = (rotate & 15) << 3;               // mask, shift and store last 4 bit  -->|bitRemain(1111)|000
        returnBits |= (bitRemain|bitToGrab) << (i*7); // OR bitToGrab and bitRemain        -->|bitRemain(1111)||bitToGrab(111)|
    }
    
    return returnBits;
}

//void decode_28bits (unsigned cipher,char *plain,unsigned key1,unsigned key2);
// function decode28bits()
// turn the 28 bits into 32 bit format
// parameters:
//      bits, the bits that will be decode
void decode28bits(unsigned bits)
{
    char printThis;

    for (int i = 3; i >= 0; i--)
    {
        printThis = scaleSeptet(bits,i);
        printf("%c", printThis);
    }
} 

// function main()
// returns the character for the digit with value in base
// parameters:
//      argc, argument counter
//      argv, agrment array 
int main (int argc, char *argv[])
{
    char line[8];
    unsigned int bits;
    unsigned key1, key2;
    char *bigkeys = argv[1];

    // check for the correct number of command-line arguments
    if (argc < 2) {
        printf("Usage: ./Decrypt passkey\n");
        return 0;
    }

    getKeys(bigkeys,&key1, &key2);// Get the 2 small keys from 1 big key base on user input
    printf("\n");
    while (fgets(line, 8, stdin))//grab and store .txt file 8 character each until the end of the text file 
    {
        sscanf(line, "%x", &bits);//turn 8 character into int value 

        bits = bits ^ key2;// XOR with key2

        shuffleNibbles(&bits);// deshuffle the nibbles 

        bits = bits ^ key1;// XOR with key1

        bits = rotateSeptet(bits);// rotate the septets first 3 bit 

        decode28bits(bits);//decode the septet 
    }
    printf("\n\n");
}
