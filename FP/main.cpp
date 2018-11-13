# define _CRT_SECURE_NO_WARNINGS
# include "iGraphics.h"			//iGraphics Is an OpenGL wrapper developed by S.M. Shahriar Nirjon, This Version is Edited by Prof Ashikur Rahman, Buet.
# include "LoadGame.h"			//Contains Load From File & GameState Structure 
# include "GlobalVars.h"		//Contains All The Global Variables
# include "GamePlayAnimation.h"	//Contains Run, Jump, Crouch Animations
# include "Obstacle.h"			//Contains Obstacle Drawing, Movement, Collision Detection Funcs
# include "ShowStatistics.h"	//TimeCount, Score Increase, Draw Stats to the Screen
# include "SkyAnimation.h"		//Contains SkyBackGround, Cloud, Birds
# include "DrawGameStates.h"	//Draws the screen for each of the gamestates
# include <stdio.h>

using namespace std;

void iDraw(){
    iClear();													//Clear and refreshes screen every gameloop
	iSetColor(0,0,0);											//Sets Color to rgb000 as in black
	if(GameCurrentState== MainMenuState){
		DrawMainMenu();	
	}
	else if(GameCurrentState==GamePlayState){					//GamePlay
		DrawGamePlay();
	}
	else if(GameCurrentState==PauseMenuState){					//Pause Menu
		DrawPauseMenu();
	}
	else if(GameCurrentState==HighScoreState){					//HighScore
		DrawHighScore();	
	}
	else if(GameCurrentState==SettingsState){					//Settings
		DrawSettings();	
	}
	else if(GameCurrentState==AboutState){						//About
		DrawAbout();	
	}
	else if(GameCurrentState==ExitState){						//Exit
		exit(0);
	}
	else if(GameCurrentState==GameOverState){					//Game Over
		DrawGameOver();	
	}
}

void iKeyboard(unsigned char key){}

void iSpecialKeyboard(unsigned char key)
{
    if(key == GLUT_KEY_UP){
        if(Crouch) Crouch=false;
		else Jump=true;
	}
	if(key == GLUT_KEY_DOWN){
        Crouch=true;
	}
	if(key == GLUT_KEY_F1){
		GameCurrentState*=-1;
	}
	
	if(key == GLUT_KEY_END){
		exit(0);
	}
}

void iMouseMove(int mx, int my){}

void iMouse(int button, int state, int mx, int my){

	if(GameCurrentState==PauseMenuState){								//Resume
		if(mx>600 && mx<600+128 && my>600 && my<600+64 ){ 
			GameCurrentState = GamePlayState;
		}
		else if(mx>600 && mx<600+128 && my>500 && my<500+64){			//Save And Exit Button
			FILE *SaveGameStats;
			SaveGameStats = fopen("saved.txt","w");
			fprintf(SaveGameStats,"%d %d %d\n",GameState.Life,GameState.TimeLeft,GameState.ScoreValue);
			fclose(SaveGameStats);
			if(GameState.ScoreValue>HighScore){
				HighScore = GameState.ScoreValue;
				FILE *HighScorePtr;
				HighScorePtr = fopen("highscore.txt","w");
				fprintf(HighScorePtr,"%d\n",HighScore);
				fclose(HighScorePtr);
			}
			GameCurrentState=MainMenuState;
		}
		else if(mx>600 && mx<600+128 && my>400 && my<400+64){			//Main Menu
			GameCurrentState=MainMenuState;
			if(GameState.ScoreValue>HighScore){
				HighScore = GameState.ScoreValue;
				FILE *HighScorePtr;
				HighScorePtr = fopen("highscore.txt","w");
				fprintf(HighScorePtr,"%d\n",HighScore);
				fclose(HighScorePtr);
			}
		}
	}

	if(GameCurrentState==MainMenuState){
		if(mx>100 && mx<356 && my>600 && my<664){			//New Game
			GameCurrentState=GamePlayState;
			LoadNew=1;
			LoadGame(LoadNew);
		}
		else if(mx>100 && mx<356 && my>500 && my<564){		//Load Game
			GameCurrentState=GamePlayState;
			LoadNew=0;
			LoadGame(LoadNew);
		}
		else if(mx>100 && mx<356 && my>400 && my<464){		//High Score
			GameCurrentState=HighScoreState;
		}
		else if(mx>100 && mx<356 && my>300 && my<364){		//Settings 
			GameCurrentState=SettingsState;
		}
		else if(mx>100 && mx<356 && my>200 && my<264){		//About
			GameCurrentState=AboutState;
		}
		if(mx>100 && mx<356 && my>100 && my<164){			//Exit
			GameCurrentState=ExitState;
		}	
	}

	if(GameCurrentState==GamePlayState){
		if(mx>50 && mx<50+64 && my>ScrHeight-100 && my<ScrHeight-100+64){
			GameCurrentState=PauseMenuState;
		}
	}

	if(GameCurrentState==HighScoreState){
		if(mx>50 && mx<50+64 && my>ScrHeight-100 && my<ScrHeight-100+64){
			GameCurrentState=MainMenuState;
		}
	}

	if(GameCurrentState==SettingsState){
		if(mx>50 && mx<50+64 && my>ScrHeight-100 && my<ScrHeight-100+64){ 
			GameCurrentState=MainMenuState;
		}
		if(mx>400 && mx<528 && my>500 && my<564){				//difficulty level, regular selected
			GameMode = 1;
		}
		if(mx>800 && mx<928 && my>500 && my<564){				////difficulty level, pro selected
			GameMode = 2;
		}
		/*
		if(mx>200 && mx<328 && my>ScrHeight*0.15 && my<ScrHeight*0.15){
			FILE *Restore;
			Restore = fopen("Saved.txt","w");
			fprintf(Restore,"0 0 0\n");
		}
		*/
	}
	
	if(GameCurrentState==AboutState){
		if(mx>50 && mx<50+64 && my>ScrHeight-100 && my<ScrHeight-100+64){
			GameCurrentState=MainMenuState;
		}
	}

	if(GameCurrentState==ExitState){
		if(mx>50 && mx<50+64 && my>ScrHeight-100 && my<ScrHeight-100+64){
			GameCurrentState=MainMenuState;
		}
	}
	
	if(GameCurrentState==GameOverState){
		if(mx>50 && mx<50+64 && my>ScrHeight-100 && my<ScrHeight-100+64){
			GameCurrentState=MainMenuState;
			LoadNew = 1;
		}
	}
}

int main(){
	LoadGame(1);
	itoa(GameState.Life,LifeValueStr,10);
	itoa(GameState.TimeLeft,TimeValueStr,10);
	itoa(GameState.ScoreValue,ScoreValueStr,10);
	iSetTimer(250,ScoreIncrease);
	iSetTimer(1000,TimeCount);
	iSetTimer(ObstacleFrameRate,ChangeObstacle);
    iSetTimer(Obstacle1FrameRate,ChangeObstacle1);
	iSetTimer(500,Clouds);
	iInitialize(ScrWidth, ScrHeight, "Jellal's Quest");  //Window Initialization

	return 0;
}

/*

typedef AUX_RGBImageRec iImage;
iImage* TextureImage;
iImage* loadFromFile(const char* fileName){
	return auxDIBImageLoad(fileName);
}
void showImage(int x, int y, iImage* texture){
	glRasterPos2f(x, y);
	glDrawPixels(texture->sizeX, texture->sizeY, GL_RGB, GL_UNSIGNED_BYTE, texture->data);
}

//showImage(boyX,boyY,TextureImage);

//TextureImage = loadFromFile(JumpAnime);


*/