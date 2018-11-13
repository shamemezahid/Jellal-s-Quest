#include<stdio.h>

void TimeCount(){
	GameState.TimeLeft--;
}

void ScoreIncrease(){
	GameState.ScoreValue++;
}

void ShowStats(){
	iText(ScrWidth-140,ScrHeight-50,"Life: ",GLUT_BITMAP_HELVETICA_18);
	sprintf(LifeValueStr,"%d",GameState.Life);
	iText(ScrWidth-100,ScrHeight-50,LifeValueStr,GLUT_BITMAP_HELVETICA_18);
	sprintf(TimeValueStr,"Time Left: %d s",GameState.TimeLeft);
	iText(ScrWidth-140,ScrHeight-75,TimeValueStr,GLUT_BITMAP_HELVETICA_18);
	sprintf(ScoreValueStr,"Score: %d",GameState.ScoreValue); 
	iText(ScrWidth-140,ScrHeight-100,ScoreValueStr,GLUT_BITMAP_HELVETICA_18);	
	iText(20,ScrHeight-20,"Press F1 To Pause/Resume",GLUT_BITMAP_HELVETICA_12);
}