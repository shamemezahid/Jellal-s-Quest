# include<stdio.h> 

void BackgroundImage(){
	iShowBMP(0,0,"bg.bmp");
}

void Clouds(){
	iShowBMP(CloudX,CloudY,"cloud.bmp");
	CloudX-=4;
	if(CloudX<0){
		CloudX = ScrWidth;
		CloudY = rand()%300 + 400;
	}
}

void Clouds1(){
	iShowBMP(Cloud1X,Cloud1Y,"cloud1.bmp");
	Cloud1X-=8;
	if(Cloud1X<0){
		Cloud1X = ScrWidth + 300;
		Cloud1Y = rand()%300 + 500;
	}
}

void Birds(){
	iShowBMP(BirdX,BirdY,BirdAnime[++BirdIndex%8]);
	BirdX-=6;
	if(BirdX<0){
		BirdX=ScrWidth;
		BirdY=ScrHeight/2+rand()%300;
	}
}

void Birds1(){
	iShowBMP(Bird1X,Bird1Y,BirdAnime[++Bird1Index%8]);
	Bird1X-=9;
	if(Bird1X<0){
		Bird1X=ScrWidth+200;
		Bird1Y=ScrHeight/2+rand()%300;
	}
}


