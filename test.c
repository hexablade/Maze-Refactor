#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int Txx, NB, vars;
    float ST, mu, R0, DC;
    
    FILE *fp = fopen(argv[1], "r");
    
    char varname[60];
    char c;
    
    while(fscanf(fp,"%s%c", varname, &c) != EOF)
    {
   
//        while((strcmp(varname, "vars")==0)){
 //           fscanf(fp,"%s%c", varname, &c);

   //     }
        if(strcmp(varname, "vars")==0)
            fscanf(fp,"%d \n %c", &vars, &c);
        printf("1: %s\n", varname);

        if(strcmp(varname, "Txx")==0)
            fscanf(fp, "%d \n %c", &Txx, &c);
        if(strcmp(varname, "ST")==0)
            fscanf(fp, "%f \n %c", &ST, &c);
        if(strcmp(varname, "mu")==0)
            fscanf(fp, "%f \n %c", &mu, &c);
        if(strcmp(varname, "R0")==0)
            fscanf(fp, "%f%c", &R0, &c);
        if(strcmp(varname, "DC")==0)
            fscanf(fp, "%f%c", &DC, &c);
        if(strcmp(varname, "NB")==0)
            fscanf(fp, "%d%c", &NB, &c);
        
        
    }
    
    
    printf("vars %d\n", vars);
    printf("Txx %d\n", Txx);
    printf("ST %f\n", ST);
    printf("mu %f\n", mu);
    printf("R0 %f\n", R0);
    printf("DC %f\n", DC);
    printf("NB %d\n", NB);
    return(0);
}
