#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char* ONE = "one";
static char* TWO = "two";
static char* THREE = "three";
static char* FOUR = "four";
static char* FIVE = "five";
static char* SIX = "six";
static char* SEVEN = "seven";
static char* EIGHT = "eight";
static char* NINE = "nine";

int findSpelledNumber(char* str){
    if(strncmp(str, ONE, 3) == 0) {return 1;}
    if(strncmp(str, TWO, 3)== 0) {return 2;}
    if(strncmp(str, THREE, 5)== 0) {return 3;}
    if(strncmp(str, FOUR, 4)== 0) {return 4;}
    if(strncmp(str, FIVE, 4)== 0) {return 5;}
    if(strncmp(str, SIX, 3)== 0) {return 6;}
    if(strncmp(str, SEVEN, 5)== 0) {return 7;}
    if(strncmp(str, EIGHT, 5)== 0) {return 8;}
    if(strncmp(str, NINE, 4)== 0) {return 9;}
    return 0;
}
int getNumLength(int i){
    if(i == 1) {return 3;}
    if(i == 2) {return 3;}
    if(i == 3) {return 5;}
    if(i == 4) {return 4;}
    if(i == 5) {return 4;}
    if(i == 6) {return 3;}
    if(i == 7) {return 5;}
    if(i == 8) {return 5;}
    if(i == 9) {return 4;}
    return 0;
}

int main(int argc, char** argv) {
    FILE *fptr = fopen("./input.txt", "r");
    char str[999];
    int sum = 0;
    int numlines = 0;
    char tmp[2];
    tmp[1]='\n';

    while(fgets(str, 999, fptr)) {
        numlines++;
        int first = -1;
        int last = -1;
        for(int i = 0; i < 999; i++) {
            if(str[i] == 10) { // break on newline
                break;
            }
            int spelledNum = findSpelledNumber(str+i);
            if (spelledNum==0){
                tmp[0]=str[i];
                if (str[i]>47 && str[i]<58){
                    if(first == -1){
                        first = atoi(tmp);
                    } else {
                        last = atoi(tmp);
                    }
                }
            } else {
                if(first == -1){
                    first = spelledNum;
                } else {
                    last = spelledNum;
                }
                //i+=(getNumLength(spelledNum)-1);
                printf("found spelled number: %d\n", spelledNum);
            }    
        }
        if(last == -1){ 
            last = first;
        }
        sum += first*10;
        sum += last;
        printf("f:%d, l:%d\n",first, last);
        
    }
    printf("Total sum: %d\nNumLines: %d\n", sum, numlines);
}