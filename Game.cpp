#include "Game.h"

static Game* singleton;

void Game::app_timer(int value){
		if (singleton->gameOver){
			//game_over->advance();
		}
		if (singleton->up){
			singleton->objList[0]->objectTex->moveUp(0.05);
		}
		if (singleton->down){
			singleton->objList[0]->objectTex->moveDown(0.05);
		}
		if (singleton->left){
			singleton->objList[0]->objectTex->moveLeft(0.05);
		}
		if (singleton->right){
			singleton->objList[0]->objectTex->moveRight(0.05);
		}
		
		if (singleton->gameOver){
			//redraw();
			glutTimerFunc(100, app_timer, value);
		}
		else{
			if (singleton->up || singleton->down || singleton->left || singleton->right || singleton->moving && !singleton->gameOver){
				//redraw();
				glutTimerFunc(16, app_timer, value);
			}
		}   
	}