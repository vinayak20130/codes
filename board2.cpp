#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include<time.h> 
#include <vector>
#include <cstdlib>
#include<string>  
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
#define RED "\u001B[31m"
#define GREEN "\u001B[32m"
#define YELLOW "\u001B[33m"
#define BLUE "\u001B[34m"
#define SIZE1 8
#define SIZE2 3
#define PATH 14
#define MAX_DE 4
#define START 0
#define FINISH 15
struct Point {
	int x;
	int y;
};
struct Block {

	Point center;
	int index;
};
struct Board {
	Block arr[14];
};
Board boardP1;
Board boardP2;
int c;
int currentIndex = 0;
#define MAX_DE 4
int moves;
char turn = 'w';
int piecesLeft = 7;
int piecesCompleted = 0;
int boardARR[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
struct boardInfo
{

	map<string, string> turn;
	vector<int> diceRoll;
	vector<int> moves;
};

set<int> sharedFields = { 5, 6, 7, 8, 9, 10, 11, 12 };
set<int> rerollFields = { 4, 8, 14 };
set<int> safeSharedFields = { 8 };
set<int> multiFields = { START, FINISH };
char newBoard[SIZE1][SIZE2] = {
	{'S', 'O', 'S'},
	{'O', 'O', 'O'},
	{'O', 'O', 'O'},
	{'B', 'S', 'B'},
	{' ', 'O', ' '},
	{' ', 'O', ' '},
	{'E', 'O', 'E'},
	{'O', 'O', 'O'},

};
char createBoard(int num)
{
	return 0;
}
vector<int> dice()
{
	vector<int> roll;
	/*
	rand() function is not used because the sequence of number that rand returns will be the same
	srand takes a positive sequence from where to start like srand(2345)
	to start a program with a different initial value we use the seed as time(0)
	*/
	// srand((unsigned)time(0));
	for (int i = 0; i < MAX_DE; i++)
	{
		roll.push_back(rand() % 2);
	}
	for (int i = 0; i < 4; i++)
	{
		cout << roll[i];
	}
	cout << endl;
	return roll;
}

char turnSelect(char currentPlayer)
{
	char activePlayer = (currentPlayer == 'w') ? 'b' : 'w';
	return activePlayer;
}
int player1(vector<int> diceRoll)
{
	int move = 0;
	for (int i = 0; i < diceRoll.size(); i++)
	{
		if (diceRoll[i] == 1)
		{
			move++;
		}
	}
	return move;
}
bool isMoveLegal(char player, int dest, char* board)
{
	const bool multiFieldCheck = multiFields.find(dest) != multiFields.end();
	const bool safeSharedFieldCheck = safeSharedFields.find(dest) != safeSharedFields.end();
	if (dest > FINISH || dest < START || board[dest] == player)
	{
		return false;
	}
	else if (multiFieldCheck || safeSharedFieldCheck || board[dest] != player)
	{
		return true;
	}
}
int selectPiece()
{
	return 0;
}
vector<int> possibleMoves(char player, int diceRoll, char* board)
{
	vector<int> moves;
	int field = selectPiece();
	int dest = field + diceRoll;
	if (isMoveLegal(player, dest, board))
	{
		moves.push_back(dest);
	}
	else if (!isMoveLegal(player, dest, board))
	{
		moves = { 0 };
	}
	return moves;
}
auto startTurn(char player, vector<int> diceRoll, char* board)
{
	int progression = 0;
	for (int i = 0; i < diceRoll.size(); i++)
	{
		progression++;
	}
	map<string, string> turn;
	turn["currentPlayer"] = player;
	turn["board"] = board;
	vector<int> dice = diceRoll;
	vector<int> moves = possibleMoves(player, progression, board);
	boardInfo boardinfo = {
		turn, dice, moves };
	return boardinfo;
}
void endTurn(char player, int selectField, char state)
{
	char currentPlayer = player;
	vector<int> possibleMoves;
	if (player == currentPlayer && (possibleMoves.size() == 0))
	{
		// map new board
		char newBoard[15];
		currentPlayer = turnSelect(player);
		startTurn(currentPlayer, dice(), newBoard);
	}
}
// auto startGame(int numStones, vector<int> numDice, char player)
// {
//     return startTurn(player == 'w' || player == 'b' ? player : 'w', dice(), createBoard(numStones || 7));
// }


void reshape(int, int) {
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-32, 32, -32, 32);
	glMatrixMode(GL_MODELVIEW);
}

void init() {
	glClearColor(0.65, 0.85, 0.85, 1.0);
}
void createBlock(Block b) {
	glBegin(GL_POLYGON); //top left
	glVertex2f(b.center.x-2.5,b.center.y+2.5);
	glVertex2f(b.center.x+2.5, b.center.y + 2.5);
	glVertex2f(b.center.x + 2.5, b.center.y - 2.5);
	glVertex2f(b.center.x - 2.5, b.center.y - 2.5);
	glEnd();
}
void displayBoard() {
	//Background Board
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-9, 24);
	glVertex2f(9, 24);
	glVertex2f(9, -0.5);
	glVertex2f(3.5, -0.5);
	glVertex2f(3.5, -11.5);
	glVertex2f(9, -11.5);
	glVertex2f(9, -24);
	glVertex2f(-9, -24);
	glVertex2f(-9, -11.5);
	glVertex2f(-3.5, -11.5);
	glVertex2f(-3.5, -0.5);
	glVertex2f(-9, -0.5);
	glEnd();

	//safe points
	Block topLeft;
	topLeft.center.x = -6;
	topLeft.center.y = 21;
	topLeft.index = 4;
	createBlock(topLeft); //top left
	
	//center (-6,21)
	int indexTL = 4;
	int centerTLX = -6;
	int centerTLY = 21;
	

	Block topRight;
	topRight.center.x = 6;
	topRight.center.y = 21;
	topRight.index = 4;
	createBlock(topRight); //top right

	int indexTR = 4;
	int centerTRX = 6;
	int centerTRY = 21;
	//center(6,21)
	

	Block middle;
	middle.center.x = 0;
	middle.center.y = 3;
	middle.index = 8;
	createBlock(middle); //middle
	//center(0,3)
	int index = 8;
	int centerMX = 0;
	int centerMY = 0;


	Block bottomLeft;
	bottomLeft.center.x = -6;
	bottomLeft.center.y = -15;
	bottomLeft.index = 14;
	createBlock(bottomLeft);
	//center(-6,-15)
	int indexBL = 14;
	int centerBLX = -6;
	int centerBLY = -15;


	Block bottomRight;
	bottomRight.center.x = 6;
	bottomRight.center.y = -15;
	bottomRight.index = 14;
	createBlock(bottomRight);
	//center(6,-15)
	int indexBR = 14;
	int centerBRX = 6;
	int centerBRY = -15;
	

	glColor3f(0.76, 0.35, 0.54);
	Block block1;
	block1.center.x = -6;
	block1.center.y = 3;
	block1.index = 1;
	createBlock(block1);
	//center(-6,3)
	int index1 = 1;
	int center1X = -6;
	int center1Y = 3;
	

	Block block2;
	block2.center.x = -6;
	block2.center.y = 9;
	block2.index = 2;
	createBlock(block2);
	//center(-6,9)
	int center2X = -6;
	int center2Y = 9;


	Block block3;
	block3.center.x = -6;
	block3.center.y = 15;
	block3.index = 3;
	createBlock(block3);
	//center(-6,15)
	int center3X = -6;
	int center3Y = 15;
	

	Block block4;
	block4.center.x =0;
	block4.center.y = 21;
	block4.index = 4;
	createBlock(block4);
	//center(0,21)

	int center4X = 0;
	int center4Y = 21;


	Block block5;
	block5.center.x = 0;
	block5.center.y = 15;
	block5.index = 5;
	createBlock(block5);
	//center(0,15)

	int center5X = 0;
	int center5Y = 15;
	

	Block block6;
	block6.center.x = 0;
	block6.center.y = 9;
	block6.index = 6;
	createBlock(block6);
	//center(0,9)

	int center6X = 0;
	int center6Y = 9;


	Block block7;
	block7.center.x = 6;
	block7.center.y = 15;
	block7.index = 7;
	createBlock(block7);
	//center(6,15)

	int center7X = 6;
	int center7Y = 15;

	Block block8;
	block8.center.x = 6;
	block8.center.y = 9;
	block8.index = 8;
	createBlock(block8);
	//center(6,9)

	int center8X = 6;
	int center8Y = 9;

	Block block9;
	block9.center.x = 6;
	block9.center.y = 3;
	block9.index = 9;
	createBlock(block9);
	//center(6,3)

	int center9X = 6;
	int center9Y = 3;

	Block block10;
	block10.center.x = 0;
	block10.center.y = -3;
	block10.index = 10;
	createBlock(block10);
	//center(0,-3)

	int center10X = 0;
	int center10Y = 3;

	Block block11;
	block11.center.x = 0;
	block11.center.y = -9;
	block11.index = 11;
	createBlock(block11);
	//center(0,-9)

	int center11X = 0;
	int center11Y = -9;

	Block block12;
	block12.center.x = 0;
	block12.center.y = -15;
	block12.index = 12;
	createBlock(block12);
	//center(0,-15)

	int center12X = 0;
	int center12Y = -15;


	Block block13;
	block13.center.x = 0;
	block13.center.y = -21;
	block13.index = 13;
	createBlock(block13);
	//center(0,-21)

	int center13X = 0;
	int center13Y = -21;
	
	Block block14;
	block14.center.x = -6;
	block14.center.y = -21;
	block14.index = 14;
	createBlock(block14);
	//center(-6,-21)

	int center14X = -6;
	int center14Y = -21;
	
	Block block15;
	block15.center.x = 6;
	block15.center.y = -21;
	block1.index = 15;
	createBlock(block15);
	//center(6,-21)

	int center15X = 6;
	int center15Y = -21;
	
	
	boardP1.arr[0] = block1;
	boardP1.arr[1] = block2;
	boardP1.arr[2] = block3;
	boardP1.arr[3] = topLeft;
	boardP1.arr[4] = block4;
	boardP1.arr[5] = block5;
	boardP1.arr[6] = block6;
	boardP1.arr[7] = middle;
	boardP1.arr[8] = block10;
	boardP1.arr[9] = block11;
	boardP1.arr[10] = block12;
	boardP1.arr[11] = block13;
	boardP1.arr[12] = block14;
	boardP1.arr[13] = bottomLeft;
	
	boardP2.arr[0] = block7;
	boardP2.arr[1] = block8;
	boardP2.arr[2] = block9;
	boardP2.arr[3] = topRight;
	boardP2.arr[4] = block4;
	boardP2.arr[5] = block5;
	boardP2.arr[6] = block6;
	boardP2.arr[7] = middle;
	boardP2.arr[8] = block10;
	boardP2.arr[9] = block11;
	boardP2.arr[10] = block12;
	boardP2.arr[11] = block13;
	boardP2.arr[12] = block15;
	boardP2.arr[13] = bottomRight;
}
void renderBitmapString(float x, float y, void* font, const char* string)
{
	const char* c;
	glRasterPos3f(x - 10, y, 0);
	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(font, *c);
	}
}
void roll() {

	glColor3f(0.1, 0.1, 1.0);
	renderBitmapString(24.00, 16.00, GLUT_BITMAP_TIMES_ROMAN_24, "Press SPACE to roll");
	if (c == 1)
	{
		moves = 0;
		vector<int> roll;
		for (int i = 0; i < MAX_DE; i++)
		{
			roll.push_back(rand() % 2);
		}

		if (roll[0] == 1) {
			glColor3f(0.0, 0.0, 0.0);
			glBegin(GL_POLYGON);
			glVertex2f(16, 6.5);
			glVertex2f(18.5, 11.5);
			glVertex2f(16, 11.5);
			glVertex2f(21, 11.5);
			glVertex2f(21, 6.5);
			glEnd();
		}
		else {
			glColor3f(1.0, 1.0, 1.0);
			glBegin(GL_POLYGON);
			glVertex2f(16, 6.5);
			glVertex2f(16, 11.5);
			glVertex2f(21, 11.5);
			glVertex2f(21, 6.5);
			glEnd();
		}
		if (roll[1] == 1) {
			glColor3f(0.0, 0.0, 0.0);
			glBegin(GL_POLYGON);
			glVertex2f(16, 5.5);
			glVertex2f(21, 5.5);
			glVertex2f(21, 0.5);
			glVertex2f(16, 0.5);
			glEnd();
		}
		else {
			glColor3f(1.0, 1.0, 1.0);
			glBegin(GL_POLYGON);
			glVertex2f(16, 5.5);
			glVertex2f(21, 5.5);
			glVertex2f(21, 0.5);
			glVertex2f(16, 0.5);
			glEnd();
		}
		if (roll[2] == 1) {
			glColor3f(0.0, 0.0, 0.0);
			glBegin(GL_POLYGON);
			glVertex2f(16, -0.5);
			glVertex2f(16, -5.5);
			glVertex2f(21, -5.5);
			glVertex2f(21, -0.5);
			glEnd();
		}
		else {
			glColor3f(1.0, 1.0, 1.0);
			glBegin(GL_POLYGON);
			glVertex2f(16, -0.5);
			glVertex2f(16, -5.5);
			glVertex2f(21, -5.5);
			glVertex2f(21, -0.5);
			glEnd();
		}
		if (roll[3] == 1) {
			glColor3f(0.0, 0.0, 0.0);
			glBegin(GL_POLYGON);
			glVertex2f(16, -6.5);
			glVertex2f(16, -11.5);
			glVertex2f(21, -11.5);
			glVertex2f(21, -6.5);
			glEnd();
		}
		else {
			glColor3f(1.0, 1.0, 1.0);
			glBegin(GL_POLYGON);
			glVertex2f(16, -6.5);
			glVertex2f(16, -11.5);
			glVertex2f(21, -11.5);
			glVertex2f(21, -6.5);
			glEnd();
		}
		c = 0;
		for (int i = 0; i < roll.size(); i++) {
			if (roll[i] == 1) {
			moves++;

			}
		}
	}
	
}

void piece(int centreX, int centreY) {
	glColor3f(0.5, 0.5, 1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(centreX-2, centreY-2);
	glVertex2f(centreX, centreY+2);
	glVertex2f(centreX + 2, centreY-2);
	glEnd();

}
void pieceCounter() {
	piecesLeft--;
	piecesCompleted++;
}
void movePieces(int moves) {
	currentIndex = currentIndex + moves;
	/*for (int i = 0; i < 14; i++) {
		if (boardARR[i] == 1&&(i+moves<14)) {
			boardARR[moves + i] = 1;
			boardARR[i] = 0;
			cout << "Increment" << endl;
			break;
		}
		else if (boardARR[i] == 1 && (i + moves > 14)) {
			boardARR[i] = 0;
			break;
		}
		else {
			boardARR[moves] = 1;
			break;
	}
		}*/
	
	if(currentIndex==14){
		for (int i = 0; i < 14; i++) {
			if (boardARR[i] == 1) {
				boardARR[i] = 0;
			}
		}
		currentIndex = 0;
		pieceCounter();
	}
	else if (currentIndex <= 13 && currentIndex>0) {

		boardARR[currentIndex-1] = 1;

		for (int i = 0; i < 14; i++) {
			if (boardARR[i] == 1) {
				piece(boardP1.arr[i].center.x, boardP1.arr[i].center.y);

				boardARR[i] = 0;
			}
		}
	}
	else if(currentIndex>13) {
		currentIndex = 0;
		pieceCounter();
	}
}

void startDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(1.0, 0.1, 0.1);
	renderBitmapString(0.00, 18.00, GLUT_BITMAP_TIMES_ROMAN_24, "The Royal Game of UR");

	glColor3f(0.1, 0.1, 1.0);
	renderBitmapString(2.00, -10.00, GLUT_BITMAP_TIMES_ROMAN_24, "Press X to continue");
	glFlush();
}
void winDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(0.1, 0.1, 1.0);
	renderBitmapString(5.00, 10.00, GLUT_BITMAP_TIMES_ROMAN_24, "You Win");
	glFlush();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	displayBoard();
	roll();
	string s = to_string(piecesLeft);
	char const* schar = s.c_str();
	glColor3f(1.0, 0.0, 0.0);
	renderBitmapString(-22.00, 15.80, GLUT_BITMAP_TIMES_ROMAN_24, "Remaining Pieces: ");
	renderBitmapString(-7.80, 15.80, GLUT_BITMAP_TIMES_ROMAN_24, schar);
	string p = to_string(piecesCompleted);
	char const* pchar = p.c_str();
	glColor3f(1.0, 0.0, 0.0);
	renderBitmapString(-22.00, 12.80, GLUT_BITMAP_TIMES_ROMAN_24, "Completed Pieces: ");
	renderBitmapString(-7.80, 12.80, GLUT_BITMAP_TIMES_ROMAN_24, pchar);
	//pieceCounter();
	movePieces(moves);
	cout << "moves: " << moves;

	cout << "  CurrentIndex:" << currentIndex << endl;
	glFlush();
}

void mymouse(int button, int state, int x, int y) {

	
	
}
void keys(unsigned char key, int x, int y) {
	if (key == 'x'|| key=='X') {
		glutDisplayFunc(display);
	}
	glutPostRedisplay();
	if (key == 32) {
		c = 1;
	}
	glutPostRedisplay();
	if (piecesCompleted >= 7) {
		glutDisplayFunc(winDisplay);
		glutPostRedisplay();
	}
}
void keyUpFunction(unsigned char key, int x, int y)
{
	
	
	
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	int height = GetSystemMetrics(SM_CYSCREEN);
	int width = GetSystemMetrics(SM_CXSCREEN);
	glutInitWindowSize(height, width);
	glutCreateWindow("The Royal Game Of UR");
	glutDisplayFunc(startDisplay);
	glutMouseFunc(mymouse);
	glutKeyboardFunc(keys);
	//glutKeyboardUpFunc(keyUpFunction);
	glutReshapeFunc(reshape);
	init();
	glutMainLoop();
}