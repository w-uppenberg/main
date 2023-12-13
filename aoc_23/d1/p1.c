#include <stdio.h>
#include <stdlib.h>

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
            tmp[0]=str[i];
            if (str[i]>47 && str[i]<58){
                if(first == -1){
                    first = atoi(tmp);
                } else {
                    last = atoi(tmp);
                }
            }
            else if(str[i] == 10) { // break on newline
                break;
            } 
        }
        if(last == -1){ 
            last = first;
        }
        sum += first*10;
        sum += last;
        
    }
    printf("Total sum: %d", sum);
}