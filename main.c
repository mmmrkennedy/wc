#include <stdio.h>
#include <string.h>

int main() {
    int newLines = 0;
    int words = 0;
    unsigned long long chars = 0;

    int prevCharDelim;

    int stringLen = 2000;

    char currString[stringLen];

    while(fgets(currString, stringLen, stdin) != NULL){

        // Windows Only
        if(currString[0] == '^' && currString[1] == 'Z'){
            break;
        }

        words++;

        for(int i = 0; i < strlen(currString); i++){

            if(i != 0 && (currString[i-1] == ' ' || currString[i-1] == '.' || currString[i-1] == ':' || currString[i-1] == ';')){
                prevCharDelim = 1;
            } else {
                prevCharDelim = 0;
            }

            if(currString[i] == '\n'){
                newLines++;
            }
            if(prevCharDelim == 0 && (currString[i] == ' ' || currString[i] == '.' || currString[i] == ':' || currString[i] == ';' || currString[i] == '\t')){
                words++;
            }
        }

        chars += (strlen(currString)-1);
    }

    printf("%d\t%d\t%llu",newLines,words,chars);

    return 0;
}

