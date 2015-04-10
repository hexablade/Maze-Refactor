#include <stdio.h>
#include <stdbool.h>
#include "graphics.h"
#include "maze.h"


int px = S;
int py = S;
int key;
int quit = 0;
int count = 0;

int maze[ROW][COL] =
{ {B, B, B, B, B, B, B, B, B},
    {B, _, P, J, B, L, P, _, B},
    {B, P, B, B, B, B, B, P, B},
    {B, _, P, _, P, _, B, _, B},
    {B, P, B, P, B, P, B, P, B},
    {B, _, B, _, P, _, B, _, B},
    {B, P, B, P, B, P, B, P, B},
    {B, _, P, _, P, B, B, E, B},
    {B, B, B, B, B, B, B, B, B}};



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
bool run_game(){
    
    render_board();
    process_input();
    render_board();
    
    return true;
    
}
