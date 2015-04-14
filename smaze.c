#include <stdio.h>
#include <stdbool.h>
#include "graphics.h"
#include "maze.h"



int main(int argc, char *args[]) {
    
    printf("Generating Maze...\n");
    init_graphics(150, 150, 450, 450, BRDRC);
    int quit = 0;
    while(true) {
        
        run_game();
             
    }
    
    
    printf("Closing program...\n");
    obliterate_graphics();
    end();
    return 0;
}

