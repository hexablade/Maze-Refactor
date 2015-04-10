#include <stdio.h>
#include <stdbool.h>
#include "graphics.h"
#include "maze.h"



int main(int argc, char *args[]) {
    
    printf("Generating Maze...\n");
    init_graphics(150, 150, 450, 450, BRDRC);
    
    while(!quit) {
        
        run_game();
        
        
    }
    
    
    printf("Closing program...\n");
    obliterate_graphics();
    printf("Pellets eaten: %i\n", count);
    return 0;
}

