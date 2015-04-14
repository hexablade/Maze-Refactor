#include <stdio.h>
#include <string.h>



typedef struct VAR {
char *name;
void *pointer;
    
}var;

int search(var *vars, const char *name){
int i;
for(i=0; vars[i].name ; ++i){
if(strcmp(vars[i].name, name)==0)
return i;
}
return -1;//not found
}

int main(int argc, char *argv[]){

int px, py, ST, mu, R0, DC;
    
var vars[] = {
{"positiony", &py},
{"positionx", &px},
{"maze", &maze},
{"mu", &mu},
{"R0", &R0},
{"DC", &DC},
{NULL, NULL}
};
    
FILE *fp = fopen(argv[1], "r");
char buff[1000];
int i;

while(1==fscanf(fp, "%s", buff)){
if(-1!=(i=search(vars, buff))){
fscanf(fp, " %*c %d;", (int*)vars[i].pointer);
}
}
fclose(fp);
printf("py = %d\n", py);
printf("ST  = %d\n", ST);
printf("mu  = %d\n", mu);
printf("R0  = %d\n", R0);
printf("DC  = %d\n", DC);
printf("px  = %d\n", px);
return 0;
}
