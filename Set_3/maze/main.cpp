#include <iostream>
#include <stdlib.h>  
using namespace std;

void printPlayground();
void movePlayer();
void collisionDetection(int, int);

// global variables
int x = 5;
int y = 5;
int x2 = 0;
int y2 = 0;
char c = ' ';

typedef enum {wood , stone, player} material;

typedef struct{
    int x,y;
    bool isWall;
    material type;
}field;

#define n 12
#define m 16
field playground[n][m];

char printCharacters(material mat){
    	switch(mat){
	case wood:
		return ' ';
        break;
	case stone:
		return '*';
        break;
    case player:
		return 'O';
        break;
	default:
		return '?';
	}
}

void printPlayground(){
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            playground[i][j].x=i;
            playground[i][j].y=j;
            playground[i][j].isWall = (i==0 || i == (n-1) || (j==0 && i) || j==(m-1));

            if (playground[i][j].isWall && !(i == 0 && j==3)){
                playground [i][j].type=stone;
            }
            else {
                if(i == x && j == y){
                    playground[i][j].type = player;
                } else {
                    playground [i][j].type=wood;
                }
            }
        }
    }

    // printing the playground
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout << printCharacters(playground[i][j].type);
        }
		cout << endl;
	}
    movePlayer();
}

void movePlayer(){
    cin >> c;

    switch (c) {
    case 'l':
        y2 = y;
        y = y - 1;
        collisionDetection(y2, x);
        break;
    case 'r':
        y2 = y;
        y = y + 1;
        collisionDetection(y2, x);
        break;
    case 'u':
        x2 = x;
        x = x - 1;
        collisionDetection(y, x2);
        break;
    case 'd':
        x2 = x;
        x = x + 1;
        collisionDetection(y, x2);
        break;
    case 'q':
        exit(0);   
    default:
        break;
    }
}

void collisionDetection(int y2, int x2){
    if(playground[x][y].type==stone){
        y = y2;
        x = x2;
        printPlayground();  
    } else {
        printPlayground();
    }
}

int main(){
    printPlayground();
    return 0;
}