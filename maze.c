#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "graphics.h"
#include "maze.h"


 
int px = S;
int py = S;
int key;
int count = 0;
int quit = 0;
int B, S, T, P, E, I, F, J, L;





int maze[ROW][COL] = {};









int search(struct var *vars, const char *name){
    int i;
    for(i=0; vars[i].name ; ++i){
        if(strcmp(vars[i].name, name)==0)
            return i;
    }
    return -1;//not found
}

bool move_player(int y, int x){ // Moves the Player
    py = y;
    px = x;
    
    
    
    
    return true;
}
void interact(){ // Pellet Count & Jump Feature & quit
    
    if(maze[py][px]== P){ // Pelet count
        count += 1;
        maze[py][px] = F;
    }
    
    else if(maze[py][px] == J){ // Jump Right
        px += 2;
        
    }
    
    
    else if(maze[py][px] == L){ // Jump Left
        px -= 2;
        
    }
    
    
    //Quit
    if(maze[py][px] == E||maze[py][px] == E || maze[py][px] == E || maze[py][px] == E){
        quit = 1;
    }
    
    return;
    
}
void render_board(){ // creates the board
    
    clear_graphics();
    int y;
    int x;
    Color sc;
    
    
    for(y=0; y < COL; y++){
        for(x=0; x < ROW; x++){
            if(maze[y][x]== _){
                sc = PIECEE;
                drawRect(sc, x*SQUARESIZEX , y*SQUARESIZEY, W, H);
            }
            else if(maze[y][x]== S){
                sc = PIECEC;
                drawRect(sc, x*SQUARESIZEX , y*SQUARESIZEY, W, H);
            }
            else if(maze[y][x]== E){
                sc = PIECEM;
                drawRect(sc, x*SQUARESIZEX , y*SQUARESIZEY, W, H);
            }
            else if(maze[y][x]== B){
                sc = PIECEB;
                drawRect(sc, x*SQUARESIZEX , y*SQUARESIZEY, W, H);
            }
            else if(maze[y][x]==P){
                sc = PIECEP;
                drawRect(sc, x*SQUARESIZEX + PW , y*SQUARESIZEY + PH, MW, MH);
            }
            else if(maze[y][x]== F){
                sc = BRDRC;
                drawRect(sc, x*SQUARESIZEX , y*SQUARESIZEY, W, H);
            }
            else if(maze[y][x]== J ||  maze[y][x]== L){
                sc = PORTALC;
                drawRect(sc, x*SQUARESIZEX , y*SQUARESIZEY, W, H);
            }
            
            
        }
    }
    
    
    drawRect(MPC, px*SQUARESIZEX , py*SQUARESIZEY, W, H);
    
    
    render_graphics();
    
    return;
}
bool process_input(){
    
    key = getKeyB();
    
    
    
    if(key == -1 || key == 44){
        quit = 1;
    }
    
    
    if(RIGHT && maze[py][px+1] != B){
        
        move_player(py, px+1);
        interact();
        
    }
    
    
    if(LEFT &&  maze[py][px-1]!= B ){
        
        move_player(py, px-1);
        interact();
    }
    
    
    if(UP && maze[py+1][px] != B){
        
        move_player(py+1, px);
        interact();
    }
    
    
    if(DOWN && maze[py-1][px] != B){
        
        move_player(py-1, px);
        interact();
        
        
    }
    
    
    
    return true;
    
}

int exit_game(){
    return quit = 1;
    
}
bool run_game(){

   if(!quit){    
    render_board();
    process_input();
    render_board();     
       return true;
   }
    else 
   

    return false; 
    
 
}


void end(){
     fclose(fp); 
     printf("Pellets eaten: %i\n", count);
}
