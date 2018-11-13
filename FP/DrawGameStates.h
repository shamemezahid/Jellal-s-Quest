# include <stdio.h>

void DrawMainMenu(){
	//main menu goes here
	iPauseTimer(0);
	iPauseTimer(1);
	iPauseTimer(2);
	iPauseTimer(3);
	iPauseTimer(4);
	FILE *HighScoreShow;
	HighScoreShow = fopen("highscore.txt","r");
	fscanf(HighScoreShow,"%d",&HighScore);
	iShowBMP(0,0,"menu.bmp");
	iShowBMP(100,600,"newgame.bmp");
	iShowBMP(100,500,"loadgame.bmp");
	iShowBMP(100,400,"highscore.bmp");
	iShowBMP(100,300,"settings.bmp");
	iShowBMP(100,200,"about.bmp");
	iShowBMP(100,100,"exit.bmp");
}

void DrawPauseMenu(){
	iShowBMP(0,0,"pausebg.bmp");
	iPauseTimer(0);
	iPauseTimer(1);
	iPauseTimer(2);
	iPauseTimer(3);
	iPauseTimer(4);
	iShowBMP(600, 600,"presume.bmp");
	iShowBMP(600, 500,"psaveexit.bmp");
	iShowBMP(600, 400,"pquit.bmp");
	
}

void DrawGamePlay(){
	iResumeTimer(0);
	iResumeTimer(1);
	iResumeTimer(2);
	iResumeTimer(3);
	iResumeTimer(4);
	BackgroundImage();

	Birds();
	Birds1();
	Clouds();
	Clouds1();
	
	iShowBMP(50,ScrHeight-100,"pause.bmp");
	DrawObstacle();
	if(GameMode==2) DrawObstacle1();
	DetectCollision();
	if(GameMode==2) DetectCollision1();
	Missile();
	DetectExplosion();
	RunAnimation();
	
	ShowStats();

	if(GameState.Life<1 || GameState.TimeLeft<0){
		GameCurrentState=GameOverState;
	}
}

void DrawHighScore(){
	iShowBMP(0,0,"menu.bmp");
	iShowBMP(50,ScrHeight-100,"backtohome.bmp");
	iFilledRectangle(164,ScrHeight*0.05,5,ScrHeight*0.9);
	FILE *HighScoreShow;
	HighScoreShow = fopen("highscore.txt","r");
	fscanf(HighScoreShow,"%d",&HighScore);

	sprintf(HighScoreValue,"HIGHSCORE: %d",HighScore);
	iText(ScrWidth/3,ScrHeight/2,HighScoreValue,GLUT_BITMAP_TIMES_ROMAN_24);
}

void DrawSettings(){
	iShowBMP(0,0,"menu.bmp");
	iShowBMP(50,ScrHeight-100,"backtohome.bmp");
	iFilledRectangle(164,ScrHeight*0.05,5,ScrHeight*0.9);
	iShowBMP(200,ScrHeight*0.85,"difficulty.bmp");
	iShowBMP(800,500,"pro.bmp");
	iShowBMP(400,500,"regular.bmp");
	if(GameMode ==1) iText(900,100,"REGULAR DIFFICULTY SELECTED",GLUT_BITMAP_HELVETICA_18);
	if(GameMode ==2) iText(900,100,"PRO DIFFICULTY SELECTED",GLUT_BITMAP_HELVETICA_18);
	iShowBMP(200,ScrHeight*0.15,"restore.bmp");	
}

void DrawAbout(){
	iShowBMP(0,0,"menu.bmp");
	iShowBMP(50,ScrHeight-100,"backtohome.bmp");
	iFilledRectangle(164,ScrHeight*0.05,5,ScrHeight*0.9);
}

void DrawGameOver(){
	iShowBMP(0,0,"menu.bmp");
	iShowBMP(50,ScrHeight-100,"backtohome.bmp");
	iShowBMP(ScrWidth/2-128,ScrHeight/2-32,"gg.bmp");
	sprintf(ScoreValueStr,"Score: %d",GameState.ScoreValue); 
	iText(ScrWidth/2-50,ScrHeight/2-50,ScoreValueStr,GLUT_BITMAP_HELVETICA_18);
	if(GameState.ScoreValue>HighScore){
		HighScore = GameState.ScoreValue;
		FILE *HighScorePtr;
		HighScorePtr = fopen("highscore.txt","w");
		fprintf(HighScorePtr,"%d\n",HighScore);
		fclose(HighScorePtr);
	}
	iPauseTimer(0);
}