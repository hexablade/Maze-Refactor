#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 

int main(int argc, char* argv[]){

    FILE *fp;

    fp = fopen(argv[1],"r");

    int i = 0;
    int j = 0;

    int WIDTH = 0;
    int NUM1 = 5;
    char str[512];
    char ch;
        
    ch = getw(fp);
    
    while(ch != EOF){
    printf("%d", ch);  
    ch = getw(fp);
    }
/*

    for(i = 0; i < 1000){
    if(strncmp(&ch, "WIDTH", 5) == 0){
        WIDTH = NUM1;
        printf("%d LALALA %d \n", NUM1, WIDTH);
    }
    }
*/
}
