#include "iGraphics.h"
#include<stdlib.h>
#include<math.h>
#define MAZEWIDTH 20
#define MAZELENGTH 20
#define SCREENLENGTH 800
#define SCREENWIDTH 700                                                                                                                                                                                                                                                                    
#define BRICKLENGTH 25
#define BRICKWIDTH 25
#define INITIALMAZEX 120
#define INITIALMAZEY 120
void drawMaze();
int mazeChanger=13;
char pacMan[2][20]={"pacforward\\pac0.bmp","pacforward\\pac5.bmp"};
float x = 700, y = 100, r = 10;
int pacMan_X=INITIALMAZEX-BRICKLENGTH/2, pacMan_Y=INITIALMAZEY-BRICKWIDTH/2,pacManIndex=0;
int score = 0;
struct maze{
	int bit[MAZEWIDTH];
	int cordinateX[MAZEWIDTH];
	int cordinateY[MAZEWIDTH];
	bool eaten[MAZEWIDTH];
};
 maze mazeline[MAZELENGTH];
bool pacCollition=false;
/*
	function iDraw() is called again and again by the system.

	*/

void iDraw()
{
	// place your drawing codes here
	iClear();
	iSetColor(0,200,100);
	for(int i=0;i<MAZELENGTH;i++){
		for(int j=0;j<MAZEWIDTH;j++){
			if(mazeline[i].bit[j]==1){
				iRectangle(i*BRICKLENGTH+INITIALMAZEX,j*BRICKWIDTH+INITIALMAZEY,BRICKLENGTH-7,BRICKWIDTH-7);
			}
			
			else if( mazeline[i].bit[j]==0 && !mazeline[i].eaten[j]){
				iPoint(i*BRICKLENGTH+INITIALMAZEX+(BRICKLENGTH/2.5),j*BRICKWIDTH+INITIALMAZEY+(BRICKWIDTH/2.5),2.3);
			} 
		}
	 }
	iLine(INITIALMAZEX-BRICKLENGTH,INITIALMAZEY-BRICKWIDTH,(MAZELENGTH+1)*BRICKLENGTH+INITIALMAZEX,INITIALMAZEY-BRICKWIDTH);
	iLine(INITIALMAZEX-BRICKLENGTH,INITIALMAZEY-BRICKWIDTH,INITIALMAZEX-BRICKLENGTH,(MAZEWIDTH+1)*BRICKWIDTH+INITIALMAZEY);
	iLine((MAZELENGTH+1)*BRICKLENGTH+INITIALMAZEX,INITIALMAZEY-BRICKWIDTH,(MAZELENGTH+1)*BRICKLENGTH+INITIALMAZEX,(MAZEWIDTH+1)*BRICKWIDTH+INITIALMAZEY);
	iLine(INITIALMAZEX-BRICKLENGTH,(MAZEWIDTH+1)*BRICKWIDTH+INITIALMAZEY,(MAZELENGTH+1)*BRICKLENGTH+INITIALMAZEX,(MAZEWIDTH+1)*BRICKWIDTH+INITIALMAZEY);
	//iShowBMP(0,0,"Pictures - Copy\\L1maze.BMP");
	iSetColor(0, 0, 200);
	//iFilledCircle(pacMan_X, pacMan_Y,BRICKWIDTH/2.2);
    iShowBMP2 (pacMan_X, pacMan_Y,pacMan[pacManIndex],0);
	if (pacMan_X > x)
		x +=0.03;
	if (pacMan_X < x)
		x -=0.03;
	if (pacMan_Y > y)
		y +=0.03;
	if (pacMan_Y < y)
		y -=0.03;
	iSetColor(220, 0, 0);
	//iFilledCircle(x, y, 10);
	// iLine(100,0,100,100);
	iSetColor(20, 200, 0);
	

	if (pacMan_X <= x + 1 && pacMan_Y <= y + 1 && pacMan_X >= x - 1 && pacMan_Y >= y - 1){
		iText(50, 50, "GAME OVER");
	}
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my)
{
	printf("x = %d, y= %d\n", mx, my);
	pacMan_X = mx;
	pacMan_Y = my;
	// place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		// place your codes here
		//	printf("x = %d, y= %d\n",mx,my);
		x += 10;
		y += 10;
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		// place your codes here
		x -= 10;
		y -= 10;
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCIt score of the key pressed.
	*/
void iKeyboard(unsigned char key)
{ {
	if (key == 'q')
	{
	//	exit(0);
	} int nextX = pacMan_X;
    int nextY = pacMan_Y;

    if (key == 'a') {
        nextX -= 5;
    }
    else if (key == 's') {
        nextY -= 5;
    }
    else if (key == 'd') {
        nextX += 5;
    }
    else if (key == 'w') {
        nextY += 5;
    }

    // Calculate the grid cell that Pac-Man will move into
    int i = (nextX - INITIALMAZEX + BRICKLENGTH / 2) / BRICKLENGTH;
    int j = (nextY - INITIALMAZEY + BRICKWIDTH / 2) / BRICKWIDTH;

    // Only update Pac-Man's position if the next position is not a wall
    if (mazeline[i].bit[j] != 1) {
        pacMan_X = nextX;
        pacMan_Y = nextY;
    }
	if(key == 'c'){
		mazeChanger++;
	}
	//printf("pacMan_X=%d  pacMan_Y=%d\n", pacMan_X, pacMan_Y);
	//printf("x1=%d    y1=%d\n",x1,y1);
	// place your codes for other keys here
  }
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	// place your codes for other keys here
}
void collision() {
    int i = (pacMan_X - INITIALMAZEX) / BRICKLENGTH;
    int j = (pacMan_Y - INITIALMAZEY) / BRICKWIDTH;

    // Check for out-of-bounds and wrap around
    if (i < 0) {
        pacMan_X = (MAZELENGTH) * BRICKLENGTH + INITIALMAZEX - 5;
    } else if (i > MAZELENGTH - 1) {
        pacMan_X = INITIALMAZEX - BRICKLENGTH + 5;
    }
    if (j < 0) {
        pacMan_Y = (MAZEWIDTH) * BRICKWIDTH + INITIALMAZEY - 5;
    } else if (j > MAZEWIDTH - 1) {
        pacMan_Y = INITIALMAZEY - BRICKWIDTH + 5;
    }
	if(mazeline[i].bit[j]==0){
		mazeline[i].eaten[j]=true;
		score++;
		printf("score=%d\n",score);
	}
    // Check for collision with a wall
    // if (mazeline[i].bit[j] == 1) {
    //     // If a collision is detected, move Pac-Man back to its previous position
    //     pacMan_X -= (pacMan_X - INITIALMAZEX) % BRICKLENGTH;
    //     pacMan_Y -= (pacMan_Y - INITIALMAZEY) % BRICKWIDTH;
    // }
}
void mazeRead(int *a,int *b,int *c,int *d,int *e){
	int counter=0;
	int neighbour[4]={*b,*c,*d,*e};
	if(*a==0){
		for(int i=0;i<4;i++){
			if(neighbour[i]==0) counter++;
		}
	    if(counter<3){
		    for(int i=0;i<4;i++){
			    if(neighbour[i]==1){
				    neighbour[i]=0;
				    break;
			    }
            }
		}
    }
    *b=neighbour[0];
    *c=neighbour[1];
    *d=neighbour[2];
    *e=neighbour[3];
}
void drawMaze(){
	for(int i=0;i<MAZELENGTH;i++){
		srand(i*mazeChanger);
		for(int j=0;j<MAZEWIDTH;j++){
			mazeline[i].bit[j]=rand()%2;
			//printf("%d",mazeline[i].bit[j]);
			mazeline[i].cordinateX[j]=i*BRICKLENGTH+INITIALMAZEX;
			mazeline[i].cordinateY[j]=j*BRICKWIDTH+INITIALMAZEY;
		}
	}
	for(int i=1;i<MAZELENGTH-1;i++){
		for(int j=1;j<MAZEWIDTH-1;j++){
		    mazeRead(&mazeline[i].bit[j],&mazeline[i+1].bit[j],&mazeline[i-1].bit[j],&mazeline[i].bit[j+1],&mazeline[i].bit[j-1]);
		}
	}
}
void change(){
	pacManIndex++;
	if(pacManIndex>=2){
		pacManIndex=0;
	}
}
int main()
{
	drawMaze();
	iSetTimer(50,drawMaze);
	collision();
	iSetTimer(50,collision);
	change();
	iSetTimer(125,change);
	// place your own initialization codes here.
	iInitialize(SCREENLENGTH,SCREENWIDTH, "demo");
	return 0;
}
