# include<stdio.h>

void RunAnimation(){								// Includes Drawing functions for Jumping, Crouching And Running			
    if(Jump){										//Jump Animations 
		iShowBMP2(boyX,boyY,JumpAnime,-1);
		if(up) boyY+=JumpSpeed[GameMode];			//upward direction : true
		else boyY-=JumpSpeed[GameMode];				//upward direction : false
		if(boyY>JumpLimit[GameMode]){
            up=0;
        }
		if(boyY<=initialBoyY){						//Prevents character from going underground
            Jump=false;
            up=1;
        }
    }
    else if(Crouch){														//Crouch
		iShowBMP2(boyX,boyY,CrouchAnime,-1);
	}
    else{																	//Runs by default
		iShowBMP2(boyX,boyY,RunAnime[++RunIndex % 5],-1);					//keep index between 0 to 4
    }
}