#include<stdio.h>

struct GameState{
	int Life;
	int TimeLeft;
	int ScoreValue;
} GameState;


void LoadGame(int LoadType){									//LoadType: 0 load saved game, 1 New Game
	FILE *InputLoadGameStatPtr;
	FILE *InputSaveGameStatPtr;
	
	if(LoadType){												// True statement Loads the default values for life, Time, Score
		InputLoadGameStatPtr = fopen("load.txt","r");			// requires to read file only
		fscanf(InputLoadGameStatPtr,"%d %d %d",&GameState.Life,&GameState.TimeLeft,&GameState.ScoreValue);
		//fclose(InputGameStatPtr);
	}
	else if(!LoadType){											// False statement Loads previously saved values of the game-play
		InputSaveGameStatPtr = fopen("saved.txt","r");			// requires to read file only
		fscanf(InputSaveGameStatPtr,"%d %d %d",&GameState.Life,&GameState.TimeLeft,&GameState.ScoreValue);
		//fclose(InputSaveGameStatPtr);
	}
}

