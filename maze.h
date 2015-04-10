#ifndef MAZE_H_
#define MAZE_H_

#define MW 20
#define MH 20
#define W 50
#define H 50
#define PW 15
#define PH 15
#define MOVING_SQUAREX 10
#define MOVING_SQUAREY 10
#define SQUARESIZEX 50
#define SQUARESIZEY 50
#define ROW 9
#define COL 9
#define PORTALC color(200,0,0)
#define BRDRC color(200,100,255)
#define PIECEB color(0,0,0)
#define PIECEE color(100,100,100)
#define PIECEC color(250,250,0)
#define PIECEF color(0,0,255)
#define PIECEP color(0,255,255)
#define PIECEM color(255,0,0)
#define MPC color(255,0,0)
#define ENDF color(0,0,0)
#define B 0
#define S 1
#define _ 2
#define P 3
#define E 4
#define I 5
#define F 6
#define J 7
#define L 8
#define UP key==81
#define DOWN key==82
#define LEFT key==80
#define RIGHT key==79





bool move_player(int x, int y);
void interact();
void render_board();
bool process_input();
bool run_game();





#endif
