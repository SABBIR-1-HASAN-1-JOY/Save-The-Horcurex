#include "iGraphics.h"
#include "header.h"
#include<stdio.h>
// Structure for homepage,profile page , about page

//Timer
struct Time{
	int min;
	int sec;
    int corx;
	int cory;
	char time[7];
}timer={0,0,875,500,"00:00"};
int speedenemy=40,speedini=450,speedbomb=5,senemycnt=0,acenemy=4,acini=50,acbomb=1,actime=0,noenemy=0;
//Win Page
int gamewin = -1;
char declare[25]="YOU WON";
int win=0,page=0;
struct Graph{
	int health;
	int score;
    int rank;
	char club[10]; 
}graph;
int cr=0,cg=0,cb=0;
int comh,comt,coms=0,scrcnt=0,scrcnts,bombcnt=0,bcnts=0;

//High Score
char name[6][20];
int position[6];

// All x,y,state variable
int menux, menuy, menu = 1; // menu variables
int aboutx, abouty, about = 0;
int profilex, profiley, profile = 0;
int instructionx, instructiony, instruction = 0;
int clevel=0;
int play = 0;
int hscr=0;

// All menu variables
int r = 0, g = 0, b = 0;				// color variable
int posx = 350, posy = 550, width = 50; // Button variables
bool click = false;						// Button click check

//All level variables
int lr=255,lb=255,lg=255,decrease=255;
int lr3=0,lr6=0,lr9=0;
int lg3=100,lg6=100,lg9=100;
int lb3=100,lb6=100,lb9=100;

// All Profile variables

int level = 0, club = 0, exper = 0;
char lev[6][20] = {"Save Heal Horcurex", "Save soul Horcurex", "Kill Hydra"};
char clu[4][20] = {"Amateur", "Master", "Expert", "Professional"};
char dead[4];
char nam[20] = "Joy";
int nedit = 1,yedit=0;
int i=0;
// All Instruction variables
int ipage = 0;
char slide[5][20] = {"img\\ins1.bmp", "img\\ins2.bmp", "img\\ins3.bmp","img\\ins4.bmp","img\\ins5.bmp"};

// All Play variables
char ground[3][20]={"img\\play1.bmp","img\\play2.bmp","img\\play1.bmp"};
int aren = 0, kill = 0, timelimit = 3600, tim=0, enemy = 10;
int score=0;
char totalscore[20];
int health=1000,hre1=0,hre2=0,hre3=0;
char healthr[20];
int gameover=0;
int kpm=0,star=0,rank=0,starw=0,starcmp=0,strkpm=0;
char brust[15][20]={"img\\exploid.bmp","img\\exploid.bmp","img\\exploid.bmp","img\\exploid.bmp","img\\exploid.bmp",
"img\\exploid.bmp","img\\exploid.bmp","img\\exploid.bmp","img\\exploid.bmp","img\\exploid.bmp",
"img\\exploid.bmp","img\\exploid.bmp","img\\exploid.bmp","img\\exploid.bmp","img\\exploid.bmp"};
int brustno[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int brustxy[2][15]={-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000};
int brustime[15]={0,0,0,0,0};
int brustin=-300;
//hero variables
int stormo=0,runlr=1,index=0;
char runright[4][30]={"Final\\standright.bmp","Final\\run1right.bmp","Final\\run2right.bmp","Final\\run3right.bmp"};
char runleft[4][30]={"Final\\standleft.bmp","Final\\run1left.bmp","Final\\run2left.bmp","Final\\run2left.bmp"};
int herox=0,heroy=100,runcnt=0,wcnt=0;
  //Shoot
  int shot=0,sr=255,sg=0,sb=0,sx=herox,sy=heroy,scnt=0;
  int sdx1=10,sdy1=10,mul=-1,sdx2=10,sdy2=10,sdx3=10,sdy3=10,sdx4=10,sdy4=10,sdx5=10,sdy5=10;
  int sno=0,range[15];
  int ball1x=-30,ball1y=-30,ball2x=-30,ball2y=-30,ball3x=-30,ball3y=-30,ball4x=-30,ball4y=-30,ball5x=-30,ball5y=-30,b1=0,b2=0,b3=0,b4=0,b5=0;
  
//Enemy variables

int ecnt=0,ex,ey,eno=4,brek=0,t=30;
int edx=0,edy=-10,fall=0;
int ex1=-500,ex2=-500,ex3=-500,ey1=-500,ey2=-500,ey3=-500;
int e1=0,e2=0,e3=0;
char ufo[3][20]={"img\\ufo1.bmp","img\\ufo2.bmp","img\\ufo3.bmp"};
struct enem{
	int x;
	int y;
	int state;
};
struct enem villains[8];
char bomb[2][20]={"img\\bomb.bmp","img\\exploid.bmp"};
char launch[1][20]={"img\\launch90.bmp"};
int expx=-1000,expy=-1000;

// all pages initialization
int winmusic=0;
// all my images for pages
char pimg[3][20] = {"img\\homepage.bmp", "img\\profile.bmp", "img\\About.bmp"};

//Functions
void menupage();
void instructionPage();
void profilepage();
void aboutpage();
void playgame();
void winpage();
void highscore();
void chooselevel();

void iDraw()
{
	iClear();
	
	// Menu
	if (menu == 1)
	{
		menupage();
	}
	
	// About
	if (about == 1)
	{
      aboutpage();
	}

	// Profile
	if (profile == 1)
	{
         profilepage();
	}
	
	// Instruction
	if (instruction == 1)
	{
		instructionPage();
	}
	
	// Play
	if (play == 1)
	{
		playgame();
	}
   
   //Levvel Page
   if(clevel==1){
	  chooselevel();
   }

   //Final Page

   if(page==1){
	   winpage();
   }

//Highscorepage
   if(hscr==1){
	highscore();
   }


}

void iMouseMove(int mx, int my)
{
}

void iMouse(int button, int state, int mx, int my)
{
	
	if ((button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)||(button==GLUT_LEFT_BUTTON &&state==GLUT_DOWN))
	{
		// Button click
		if (menu == 1)
		{
			if ((mx >= 350 && mx <= 650))
			{
				// Quit Button Click

				if (my >= 200 && my <= 250)
				{
					exit(0);
				}

				// About Button Click

				if (my >= 275 && my <= 325)
				{
					menu = 0;
					about = 1;
				}

				// Instruction  Button Click

				if (my >= 350 && my <= 400)
				{
					menu = 0;
					instruction = 1;
				}

				// Profile Button Click

				if (my >= 425 && my <= 475)
				{
					menu = 0;
					profile = 1;
				}

				// Play Button Click

				if (my >= 500 && my <= 550)
				{
					menu = 0;
					clevel=1;
				}
			}
		}

		// About to menu
		if (about == 1)
		{
			// Back to Menu
			if ((mx >= 850 && mx <= 1000) && (my >= 50 && my <= 100))
			{
				menu = 1;
				about = 0;
			}
		}
		// Profile to menu
		if (profile == 1)
		{
			// Back to Menu
			if ((mx >= 900 && mx <= 1000) && (my >= 10 && my <= 35))
			{
				menu = 1;
				profile = 0;
			}
			//Highscore
			if((mx>=350&&mx<=650)&&(my>=350 && my<=400)){
                hscr=1;
				profile=0;
			}
			// Edit Name
			if ((mx >= 675 && mx <= 725) && (my >= 500 && my <= 525))
			{
				if(yedit==1) {
					nedit=1;
					yedit=0;
				}
				else {
					nedit=0;
					yedit=1;
				}
			}
		
		    
		}

		if (instruction == 1)
		{
			if (mx >= 900 && mx <= 1000)
			{
				if (my >= 0 && my <= 25)
				{
					ipage = 0;
					menu = 1;
					instruction = 0;
				}
				if (my >= 50 && my <= 75)
				{
					if(ipage<=3) ipage++;
				}
			}
		}
      
	    if(clevel==1){

			//start the game
           if((mx>=800&&mx<=900)&&(my>=100 && my<=150)){
			 clevel=0;
			 play=1;
			 lr3=lr6=lr9=0;
			 lg3=lg6=lg9=lb3=lb6=lb9=100;
			
		   }  

		   //Back to menu
		   if((mx>=800&&mx<=900)&&(my>=5 && my<=55)){
			 clevel=0;
			 menu=1;
			 lr3=lr6=lr9=0;
			 lg3=lg6=lg9=lb3=lb6=lb9=100;

		   }

		   //Play 30 minutes
          if((mx>=350 && mx<=650)&&(my>=500 && my<=550)){
			lr3=255,lg3=0,lb3=0;
            lr6=0,lg6=100,lb6=100;
			lr9=0,lg9=100,lb9=100;
			timelimit=1800;
			health=1000;
            speedini=450;
		  }
         //Play 60 minutes

          if((mx>=350 && mx<=650)&&(my>=425 && my<=475)){
			lr6=255,lg6=0,lb6=0;
            lr3=0,lg3=100,lb3=100;
			lr9=0,lg9=100,lb9=100;
			timelimit=3600;
			health=1500;
			speedini=600;
		  }
		   
		//Play 90 minutes
		if((mx>=350 && mx<=650)&&(my>=350 && my<=400)){
			lr9=255,lg9=0,lb9=0;
            lr6=0,lg6=100,lb6=100;
			lr3=0,lg3=100,lb3=100;
			timelimit=5400;
			health=2000;
			speedini=750;
		  }
          timer.sec=0;
	    }

	    if(play==1){
			//Quit button
			if((mx>=875 && mx<=985)&&(my>=550 && my<=575)){
				
              menu=1;
			  play=0;
			  //Reset variables
  ex1=-500,ex2=-500,ex3=-500,ey1=-500,ey2=-500,ey3=-500,e1=0,e2=0,e3=0;//enemy positions
  ball1x=-30,ball1y=-30,ball2x=-30,ball2y=-30,ball3x=-30,ball3y=-30,ball4x=-30,ball4y=-30,ball5x=-30,ball5y=-30,b1=0,b2=0,b3=0,b4=0,b5=0;//Ball variables
  health=2000,timer.sec=0;//Health and timer

				FILE *fp=fopen("score.txt","a");
	            fprintf(fp,"%s %d",nam,score);
	            fclose(fp);
			}

			if(mx>=875&& mx<=925){
                if(my>=0 && my <=50){
					sno=1;
					sx=herox;
					sy=heroy+5;
					scnt++;
					if(scnt==1){
                       ball1x=sx;
					   ball1y=sy;
					   b1=1;
					   sdx1=-10;
					   sdy1=0;
                       bombcnt++;
					}
			else if(scnt==2){
                       ball2x=sx;
					   ball2y=sy;
					   b2=1;
					   sdx2=-10;
					   sdy2=0;
					   bombcnt++;
					}
			else if(scnt==3){
                      ball3x=sx;
					   ball3y=sy;
					   b3=1;
					   sdx3=-10;
					   sdy3=0;
					   bombcnt++;
					}
			else if(scnt==4){
				ball4x=sx;
				ball4y=sy;
				b4=1;
				sdx4=-10;
				sdy4=0;
				bombcnt++;
			}
			else if(scnt==5){
				ball5x=sx;
				ball5y=sy;
				b5=1;
				sdx5=-10;
				sdy5=0;
				bombcnt++;
			}
					
			else   {
						scnt=0;
					}
					
				}
				if(my>=60 && my <=110){
					sno=2;
					sx=herox;
					sy=heroy;
					scnt++;
					if(scnt==1){
                       ball1x=sx;
					   ball1y=sy;
					   b1=1;
					   sdx1=-8;
					   sdy1=8;
                       bombcnt++;
					}
			else if(scnt==2){
                       ball2x=sx;
					   ball2y=sy;
					   b2=1;
					   sdx2=-8;
					   sdy2=8;
					   bombcnt++;
					}
			else if(scnt==3){
                      ball3x=sx;
					   ball3y=sy;
					   b3=1;
					   sdx3=-8;
					   sdy3=8;
					   bombcnt++;
					}
			else if(scnt==4){
				ball4x=sx;
				ball4y=sy;
				b4=1;
				sdx4=-8;
				sdy4=8;
				bombcnt++;
			}
			else if(scnt==5){
				ball5x=sx;
				ball5y=sy;
				b5=1;
				sdx5=-8;
				sdy5=8;
				bombcnt++;
			}
			else   {
						scnt=0;
					}
					
					
				}
			}

			if(mx>=935&& mx<=985){
                if(my>=0 && my <=50){
					sno=3;
					sx=herox;
					sy=heroy+5;
					scnt++;
					if(scnt==1){
                       ball1x=sx;
					   ball1y=sy;
					   b1=1;
					   sdx1=10;
					   sdy1=0;
                       bombcnt++;
					}
			else if(scnt==2){
                       ball2x=sx;
					   ball2y=sy;
					   b2=1;
					   sdx2=10;
					   sdy2=0;
					   bombcnt++;
					}
			else if(scnt==3){
                      ball3x=sx;
					   ball3y=sy;
					   b3=1;
					   sdx3=10;
					   sdy3=0;
					   bombcnt++;
					}
			else if(scnt==4){
				ball4x=sx;
				ball4y=sy;
				b4=1;
				sdx4=10;
				sdy4=0;
				bombcnt++;
			}
			else if(scnt==5){
				ball5x=sx;
				ball5y=sy;
				b5=1;
				sdx5=10;
				sdy5=0;
				bombcnt++;
			}
			else   {
						scnt=0;
					}
					
					
				}
				if(my>=60 && my <=110){
					sno=4;
					sx=herox;
					sy=heroy;
					scnt++;
					if(scnt==1){
                       ball1x=sx;
					   ball1y=sy;
					   b1=1;
					   sdx1=8;
					   sdy1=8;
                    bombcnt++;
					}
			else if(scnt==2){
                       ball2x=sx;
					   ball2y=sy;
					   b2=1;
					   sdx2=8;
					   sdy2=8;
					   bombcnt++;
					}
			else if(scnt==3){
                      ball3x=sx;
					   ball3y=sy;
					   b3=1;
					   sdx3=8;
					   sdy3=8;
					   bombcnt++;
					}
			else if(scnt==4){
				ball4x=sx;
				ball4y=sy;
				b4=1;
				sdx4=8;
				sdy4=8;
				bombcnt++;
			}
			else if(scnt==5){
				ball5x=sx;
				ball5y=sy;
				b5=1;
				sdx5=8;
				sdy5=8;
				bombcnt++;
			}
			else   {
						scnt=0;
					}
					
					
				}
				if(my>=120 && my <=170){
					sno=5;
					sx=herox;
					sy=heroy;
					scnt++;
					if(scnt==1){
                       ball1x=sx;
					   ball1y=sy;
					   b1=1;
					   sdx1=0;
					   sdy1=10;
                       bombcnt++;
					}
			else if(scnt==2){
                       ball2x=sx;
					   ball2y=sy;
					   b2=1;
					   sdx2=0;
					   sdy2=10;
					   bombcnt++;
					}
			else if(scnt==3){
                      ball3x=sx;
					   ball3y=sy;
					   b3=1;
					   sdx3=0;
					   sdy3=10;
					   bombcnt++;
					}
			else if(scnt==4){
				ball4x=sx;
				ball4y=sy;
				b4=1;
				sdx4=0;
				sdy4=10;
				bombcnt++;
			}
			else if(scnt==5){
				ball5x=sx;
				ball5y=sy;
				b5=1;
				sdx5=0;
				sdy5=10;
				bombcnt++;
			}
			else   {
						scnt=0;
					}
					
					
				}
			}

		}
	
	    if(page==1){
			if((mx>=0&&mx<=100)&&(my>=5&&my<=30)){
				page=0;
				profile=1;
			}
			if((mx>=800 && mx<=900)&& (my>=5&&my<=30)){
				page=0;
				exit(0);
			}
		}
	
	    if(hscr==1){
			if((mx>=800&& mx<=990)&&(my>=25 && my<=65)){
                menu=1;
				hscr=0;
			}
		}
	
	}
}

void iKeyboard(unsigned char key)
{
	
	if(profile==1){
		
		if(key!='\b'){
       
	   if(key=='\r' || key=='\n' || key==' '){
		profile=0;
		menu=1;
        nam[i+1]='\0';
		kpm=0;
		star=0;
		starcmp=0,starw=0,strkpm=0;
		comh=0,comt=0,coms=0,scrcnt=0,scrcnts=0;
	   }
			
		else{	nam[i]=key;
			nam[i+1]='\0';
			i+=1;
        
		}
	}
	else{

	   if(i>0) nam[i-1]='\0';
	   if(i>1){
		i--;
	   }
	   else{
		nam[0]='\0';
		i=0;
	   }
	   

	}
		}

if(play==1){
	//Start enemy fall

	if(key=='a'){
     //move left
      stormo=1;
		runlr=1;
		if(herox-10>=0) {
			herox-=10;
			

		index++;
		}
		if(index>=4){
			index=1;
		}
	}
	if(key=='s'){
       //move down
	   if(heroy-25>=100) {
		heroy-=25;
		
	   }

	}
	if(key=='d'){
      //move right
	  stormo=1;
       if(herox+25<775){
		herox+=10;
		
	   }
		runlr=0;
		index++;
		
		if(index>=4){
			index=1;
		}

	}
	if(key=='w'){
    //move up
    if(heroy+25<=150) {
		heroy+=25;
		wcnt++;
		
	}
	}
}
   
}

void iSpecialKeyboard(unsigned char key)
{

	/*if (key == GLUT_KEY_END)
	{
		exit(0);
	}*/
}

void menupage(){
        iShowBMP(menux, menuy, pimg[0]);
		r = 0, g = 100, b = 100;
		// Play button
		iSetColor(0, 0, 0);
		iFilledRectangle(348, 498, 304, 54);
		iSetColor(r, g, b);
		iFilledRectangle(350, 500, 300, 50);
		iSetColor(255, 255, 255);
		iText(450, 510, "Play", GLUT_BITMAP_TIMES_ROMAN_24);

		// Profile button
		iSetColor(0, 0, 0);
		iFilledRectangle(348, 423, 304, 54);
		iSetColor(r, g, b);
		iFilledRectangle(350, 425, 300, 50);
		iSetColor(255, 255, 255);
		iText(450, 435, "Profile", GLUT_BITMAP_TIMES_ROMAN_24);

		// Instruction Button
		iSetColor(0, 0, 0);
		iFilledRectangle(348, 348, 304, 54);
		iSetColor(r, g, b);
		iFilledRectangle(350, 350, 300, 50);
		iSetColor(255, 255, 255);
		iText(450, 360, "Instruction", GLUT_BITMAP_TIMES_ROMAN_24);

		// About Button
		iSetColor(0, 0, 0);
		iFilledRectangle(348, 273, 304, 54);
		iSetColor(r, g, b);
		iFilledRectangle(350, 275, 300, 50);
		iSetColor(255, 255, 255);
		iText(450, 285, "About", GLUT_BITMAP_TIMES_ROMAN_24);

		// Quit Button
		iSetColor(0, 0, 0);
		iFilledRectangle(348, 198, 304, 54);
		iSetColor(r, g, b);
		iFilledRectangle(350, 200, 300, 50);
		iSetColor(255, 0, 0);
		iText(450, 210, "Quit", GLUT_BITMAP_TIMES_ROMAN_24);		
         
		 timer.min=0,timer.sec=0,
speedenemy=50,speedini=800,speedbomb=10,senemycnt=0,acenemy=4,acini=50,acbomb=1,actime=0,noenemy=0,
gamewin = -1,win=0,
page=0,
comh=0,comt=0,coms=0,scrcnt=0,scrcnts=0,
menu = 1,about = 0,profile=0,instruction=0,play=0,
ipage = 0,
aren = 0, kill = 0, tim = 0,  enemy = 10,
score=0,health=2000,hre1=0,hre2=0,hre3=0,gameover=0,
kpm=0,star=0,rank=0,starw=0,starcmp=0,strkpm=0,
stormo=0,runlr=1,index=0,
herox=0,heroy=100,runcnt=0,wcnt=0,
shot=0,sr=255,sg=0,sb=0,sx=herox,sy=heroy,scnt=0,
sdx1=10,sdy1=10,mul=-1,sdx2=10,sdy2=10,sdx3=10,sdy3=10,sdx4=10,sdy4=10,sdx5=10,sdy5=10,
sno=0,
ball1x=-30,ball1y=-30,ball2x=-30,ball2y=-30,ball3x=-30,ball3y=-30,ball4x=-30,ball4y=-30,ball5x=-30,ball5y=-30,b1=0,b2=0,b3=0,b4=0,b5=0,
ecnt=0,ex,ey,eno=4,brek=0,t=30,
edx=0,edy=-10,fall=0,
ex1=-500,ex2=-500,ex3=-500,ey1=-500,ey2=-500,ey3=-500,
e1=0,e2=0,e3=0,

strcpy(timer.time,"00:00");
}

void instructionPage(){
  iShowBMP(0, 0, slide[ipage]);
		iSetColor(r, g, b);
		iFilledRectangle(900, 0, 100, 25);
		iSetColor(255, 255, 255);
		iText(903, 5, "Home");

		if (ipage < 4)
		{
			iSetColor(r, g, b);
			iFilledRectangle(900, 50, 100, 25);
			iSetColor(255, 255, 255);
			iText(903, 55, "Next");
		}
}

void profilepage(){
   // Back Button
		iShowBMP(0, 0, pimg[1]);
		iSetColor(r, g, b);
		iFilledRectangle(900, 10, 100, 25);
		iSetColor(255, 255, 255);
		iText(903, 15, "BACK", GLUT_BITMAP_TIMES_ROMAN_24);

		// All other entities
// Edit
		iSetColor(r, g, b);
		iFilledRectangle(675, 500, 50, 25);
		iSetColor(255, 255, 255);
		iText(676, 501, "Edit");

		// Name

		iSetColor(0, 0, 0);
		iFilledRectangle(348, 498, 304, 54);
		iSetColor(r, g, b);
		iFilledRectangle(350, 500, 300, 50);
		iSetColor(255, 255, 255);
		iText(450, 510, nam, GLUT_BITMAP_TIMES_ROMAN_24);


		// Level button
		iSetColor(0, 0, 0);
		iFilledRectangle(348, 423, 304, 54);
		iSetColor(r, g, b);
		iFilledRectangle(350, 425, 300, 50);
		iSetColor(255, 255, 255);
		char rating[10];
		star=starw+starcmp+strkpm;
		sprintf(rating,"Rating %d.0",star);
		iText(450, 435,rating, GLUT_BITMAP_TIMES_ROMAN_24);

		// Highscore button
		iSetColor(0, 0, 0);
		iFilledRectangle(348, 348, 304, 54);
		iSetColor(r, g, b);
		iFilledRectangle(350, 350, 300, 50);
		iSetColor(255, 255, 255);
		
		iText(450, 360,"TOP 5", GLUT_BITMAP_TIMES_ROMAN_24);

		// Kill Button
		iSetColor(0, 0, 0);
		iFilledRectangle(348, 273, 304, 54);
		iSetColor(r, g, b);
		iFilledRectangle(350, 275, 300, 50);
		iSetColor(255, 255, 255);
		char scr[15];
		sprintf(scr,"%d kills",coms/10);
		iText(450, 285, scr, GLUT_BITMAP_TIMES_ROMAN_24);

		// Kill per minute Button
		iSetColor(0, 0, 0);
		iFilledRectangle(348, 198, 304, 54);
		iSetColor(r, g, b);
		iFilledRectangle(350, 200, 300, 50);
		iSetColor(255, 255, 255);
		char killperminute[10];
		sprintf(killperminute,"%d KPM",kpm);
		iText(450, 210,killperminute, GLUT_BITMAP_TIMES_ROMAN_24);

        //Total Score
		iSetColor(0, 0, 0);
		iFilledRectangle(348, 123, 304, 54);
		iSetColor(r, g, b);
		iFilledRectangle(350, 125, 300, 50);
		iSetColor(255, 255, 255);
		char scores[10];
		sprintf(scores,"%d points",score);
		iText(450, 135,scores, GLUT_BITMAP_TIMES_ROMAN_24);

}

void aboutpage(){
   
		iShowBMP(0, 0, pimg[2]);
		// Back Button
		iSetColor(r, g, b);
		iFilledRectangle(850, 50, 150, 50);
		iSetColor(255, 255, 255);
		iText(875, 60, "BACK", GLUT_BITMAP_TIMES_ROMAN_24);
}

void playgame(){
   iShowBMP(0,0,ground[aren]);
   iSetColor(0,0,0);
   iFilledRectangle(873,0,112,172);
   iSetColor(r,g,b);
   iFilledRectangle(875,0,110,170);
   iSetColor(153,50,204);//dark orchid
   //left buttons
   iFilledRectangle(875,0,50,50);
   iFilledRectangle(875,60,50,50);
   iFilledRectangle(875,120,50,50);
   //right buttons
   iFilledRectangle(935,0,50,50);
   iFilledRectangle(935,60,50,50);
   iFilledRectangle(935,120,50,50);

   //angles
   iSetColor(255,255,255);
   iText(880,10,"180");
   iText(880,70,"135");
   iText(880,130,"NO");

   iText(940,10,"0");
   iText(940,70,"45");
   iText(940,130,"90");

   //Quit
   iSetColor(r,g,b);
   iFilledRectangle(875,550,110,25);
   iSetColor(255,255,255);
   iText(885,554,"Quit",GLUT_BITMAP_TIMES_ROMAN_24);

   //Timer
   iSetColor(r,g,b);
   iFilledRectangle(timer.corx,timer.cory,110,25);
   iSetColor(255,255,255);
   timer.min=timer.sec/60;
   sprintf(timer.time,"%02d:%02d",timer.min,timer.sec%60);
   iText(timer.corx+2,timer.cory+2,timer.time,GLUT_BITMAP_TIMES_ROMAN_24);
   //Health
   iSetColor(r,g,b);
   iFilledRectangle(875,450,100,40);
   iSetColor(255,0,0);
   sprintf(healthr,"Health:%d",health);
   iText(880,455,healthr,GLUT_BITMAP_TIMES_ROMAN_24);

   //Scores
   iSetColor(r,g,b);
   iFilledRectangle(875,350,200,50);
   iSetColor(255,255,255);
   sprintf(totalscore,"Score:%d",score);
   iText(880,355,totalscore,GLUT_BITMAP_TIMES_ROMAN_24);

   //Hero Move
   if(stormo==0) {
	        heroy=100;
			if(runlr==1)
			iShowBMP2(herox,heroy,runleft[0],255); //Standing left position
            else if(runlr==0)
			iShowBMP2(herox,heroy,runright[0],255);//Standing right position

		}
		else{
			if(runlr==1){
				iShowBMP2(herox,heroy,runleft[index],255);//runleft
				runcnt++;
				if(runcnt>=15){
					index=0;
					runcnt=0;
					stormo=0;
					heroy=100;
				}
				
			}
			else{
				iShowBMP2(herox,heroy,runright[index],255);//runright
				runcnt++;
				if(runcnt>=15){
					index=0;
					runcnt=0;
					stormo=0;
					heroy=100;
				}
			}
		}
	//Pos Color
	iSetColor(0,0,0);
	iFilledRectangle(herox,heroy-50,2,50);

	//HeroShot

	//Enemy
	iSetColor(0,0,0);
	iFilledRectangle(0,498,800,104);

 iShowBMP(700,500,ufo[0]);
 iShowBMP(0,500,ufo[0]);
 iShowBMP(100,500,ufo[0]);
 iShowBMP(200,500,ufo[0]);
 iShowBMP(300,500,ufo[0]);
 iShowBMP(400,500,ufo[0]);
 iShowBMP(500,500,ufo[0]);
 iShowBMP(600,500,ufo[0]);

 
 
 iFilledRectangle(100,500,2,100);
 iFilledRectangle(200,500,2,100);
 iFilledRectangle(300,500,2,100);
 iFilledRectangle(400,500,2,100);
 iFilledRectangle(500,500,2,100);
 iFilledRectangle(600,500,2,100);
 iFilledRectangle(700,500,2,100);

 //herohot
 if(ball1x>=800 || ball1x<=0 || ball1y>=500) {
	b1=0;
	ball1x=-30;
	ball1y=-30;
 }
 if(ball2x>=800 || ball2x<=0 || ball2y>=500) {
	b2=0;
	ball2x=-30;
	ball2y=-30;
 }
 if(ball3x>=800 || ball3x<=0 || ball3y>=500) {
	b3=0;
	ball3x=-30;
	ball3y=-30;
 }
 if(ball4x>=800 || ball4x<=0 || ball4y>=500) {
	b4=0;
	ball4x=-30;
	ball4y=-30;
 }
 if(ball5x>=800 || ball5x<=0 || ball5y>=500) {
	b5=0;
	ball5x=-30;
	ball5y=-30;
 }
 iSetColor(0,255,0);
 //iFilledCircle(ball1x,ball1y,5,100);
   iShowBMP2(ball1x,ball1y,launch[0],0);
   iShowBMP2(ball2x,ball2y,launch[0],0);
 //iFilledCircle(ball2x,ball2y,5,100);
   iShowBMP2(ball3x,ball3y,launch[0],0);
   iShowBMP2(ball4x,ball4y,launch[0],0);
   iShowBMP2(ball5x,ball5y,launch[0],0);
 //iFilledCircle(ball3x,ball3y,5,100);



//enemy disappear

 iSetColor(255,0,0);
 if(ey1<=100 && e1==1){

    ex1=-500;
	ey1=-500;
	e1=0;
	PlaySound("music\\blast-37988.wav",NULL,SND_ASYNC);
	
 }
 if(ey2<=100 && e2==1 ){
    ex2=-500;
	ey2=-500;
	e2=0;
	PlaySound("music\\blast-37988.wav",NULL,SND_ASYNC);
 }
 if(ey3<=100 && e3==1){
    ex3=-500;
	ey3=-500;
	e3=0;
	PlaySound("music\\blast-37988.wav",NULL,SND_ASYNC);
 }
 
 iShowBMP2(ex1,ey1,bomb[0],255);
 iShowBMP2(ex2,ey2,bomb[0],255);
 iShowBMP2(ex3,ey3,bomb[0],255);
 
 //Brust
	if(brustno[0]) iShowBMP2(brustxy[0][0],brustxy[1][0],brust[0],255);
	if(brustno[1])iShowBMP2(brustxy[0][1],brustxy[1][1],brust[1],255);
	if(brustno[2])iShowBMP2(brustxy[0][2],brustxy[1][2],brust[2],255);
	if(brustno[2])iShowBMP2(brustxy[0][3],brustxy[1][3],brust[3],255);
	if(brustno[4])iShowBMP2(brustxy[0][4],brustxy[1][4],brust[4],255);
	if(brustno[5])iShowBMP2(brustxy[0][5],brustxy[1][5],brust[5],255);
	if(brustno[6])iShowBMP2(brustxy[0][6],brustxy[1][6],brust[6],255);
	if(brustno[7])iShowBMP2(brustxy[0][7],brustxy[1][7],brust[7],255);
	if(brustno[8])iShowBMP2(brustxy[0][8],brustxy[1][8],brust[8],255);
	if(brustno[9])iShowBMP2(brustxy[0][9],brustxy[1][9],brust[9],255);
	if(brustno[10])iShowBMP2(brustxy[0][10],brustxy[1][10],brust[10],255);
	if(brustno[11])iShowBMP2(brustxy[0][11],brustxy[1][11],brust[11],255);
	if(brustno[12])iShowBMP2(brustxy[0][12],brustxy[1][12],brust[12],255);
	if(brustno[13])iShowBMP2(brustxy[0][13],brustxy[1][13],brust[13],255);
	if(brustno[14])iShowBMP2(brustxy[0][14],brustxy[1][14],brust[14],255);

 
 if(gameover==1){
	comh=health;
	coms=score;
	if(bombcnt !=0)
	bcnts=((score*10)/bombcnt);
	else bcnts=0;
	comt=timer.sec;
	scrcnts=scrcnt;
    //Score fixing
    
	if(bombcnt!=0 && comt !=0 && scrcnts !=0)
	score=score+((coms*10)/bombcnt)+((coms*60)/comt)*50+((coms*10)/scrcnts);
   else score=0;

	//Sorting the array of high score
   FILE *fh=fopen("highscore.txt","r");
	int r=0;
    while(1){
		int status=fscanf(fh,"%s %d",name[r],&position[r]);
		r++;
		if(status==EOF) break;
	}
	fclose(fh);
    //Sort

	for(int h=0;h<5;h++){
		if(score>=position[h]){
			for(int k=4;k>h;k--){
                strcpy(name[k],name[k-1]);
				position[k]=position[k-1];
			}
			strcpy(name[h],nam);
			position[h]=score;
			break;
		}
	}
	//Write new leaderboard
FILE *f=fopen("highscore.txt","w+");
  for(int h=0;h<5;h++){
	fprintf(f,"%s %d\n",name[h],position[h]);
  }
  fclose(f);
  
  //Reset variables
  play=0,gameover=0;
  ex1=-500,ex2=-500,ex3=-500,ey1=-500,ey2=-500,ey3=-500,e1=0,e2=0,e3=0;//enemy positions
  ball1x=-30,ball1y=-30,ball2x=-30,ball2y=-30,ball3x=-30,ball3y=-30,ball4x=-30,ball4y=-30,ball5x=-30,ball5y=-30,b1=0,b2=0,b3=0,b4=0,b5=0;//Ball variables
  health=2000,timer.sec=0;//Health and timer

	if(win!=0){
       page=1;
	   
	}
	else{
		menu=1;
	}
 }
}

void enemyfall(){
	noenemy++;
   if(e1==1){
	ey1-=4;
	if(ey1<=100){
	health-=hre1*100;
	hre1=0;
	if(health==0){
		win=-1;
		gameover=1;
	}
	}
	
   }
   if(e2==1){
	ey2-=4;
	if(ey2<=100){
	health-=100*hre2;
	hre2=0;
	if(health==0){
		win=-1;
		gameover=1;
	}
	}
	
   }
   if(e3==1){
	ey3-=4;
	if(ey3<=100){
	health-=100*hre3;
	hre3=0;
	if(health==0){
		win=-1;
		gameover=1;
		comt=timer.sec;
	}
	}
	
   }
   timer.sec+=3;
   
   if(timer.sec==timelimit) {
	comt=timer.sec;
	if(health==0) win=-1;
	else win=1;
	gameover=1;
   }
   speedenemy=speedenemy-(noenemy/5)*acenemy;
   speedbomb=speedbomb-(noenemy/8)*acbomb;
}

 void enemyfallini(){
	senemycnt++;
	if(ecnt%4==0){
   if(e1==0){
      ex1=(rand()%8)*100+50;
	  ey1=400;
	  e1=1;
	  hre1=1;
	  scrcnt++;
	   
	   if(play==1) PlaySound("music\\falling-bomb-41038.wav",NULL,SND_ASYNC);
   }
   else if(e2==0){
	ex2=(rand()%8)*100+50;
	  ey2=400;
	  e2=1;
	  hre2=1;
	  scrcnt++;
	  
	if(play==1)  PlaySound("music\\falling-bomb-41038.wav",NULL,SND_ASYNC);
   }
   else if(e3==0){
	  ex3=(rand()%8)*100+50;
	  ey3=400;
	  e3=1;
	  hre3=1;
	  scrcnt++;
	   
	 if(play==1) PlaySound("music\\falling-bomb-41038.wav",NULL,SND_ASYNC);
   }
	}
 ecnt++;
 
 speedini=speedini-(senemycnt/5)*acini;
 
}

void herosht(){

   if(b1==1){
	ball1x+=sdx1;
	ball1y+=sdy1;
   }
   if(b2==1){
	ball2x+=sdx2;
	ball2y+=sdy2;
   }
   if(b3==1){
	ball3x+=sdx3;
	ball3y+=sdy3;
   }
   if(b4==1){
	ball4x+=sdx4;
	ball4y+=sdy4;
   }
   if(b5==1){
	ball5x+=sdx5;
	ball5y+=sdy5;
   }
}

void scoring(){
    range[0]=(ball1x-ex1)*(ball1x-ex1)+(ball1y-ey1)*(ball1y-ey1);
range[1]=(ball1x-ex2)*(ball1x-ex2)+(ball1y-ey2)*(ball1y-ey2);
range[2]=(ball1x-ex3)*(ball1x-ex3)+(ball1y-ey3)*(ball1y-ey3);

range[3]=(ball2x-ex1)*(ball2x-ex1)+(ball2y-ey1)*(ball2y-ey1);
range[4]=(ball2x-ex2)*(ball2x-ex2)+(ball2y-ey2)*(ball2y-ey2);
range[5]=(ball2x-ex3)*(ball2x-ex3)+(ball2y-ey3)*(ball2y-ey3);

range[6]=(ball3x-ex1)*(ball3x-ex1)+(ball3y-ey1)*(ball3y-ey1);
range[7]=(ball3x-ex2)*(ball3x-ex2)+(ball3y-ey2)*(ball3y-ey2);
range[8]=(ball3x-ex3)*(ball3x-ex3)+(ball3y-ey3)*(ball3y-ey3);

range[9]=(ball4x-ex1)*(ball4x-ex1)+(ball4y-ey1)*(ball4y-ey1);
range[10]=(ball4x-ex2)*(ball4x-ex2)+(ball4y-ey2)*(ball4y-ey2);
range[11]=(ball4x-ex3)*(ball4x-ex3)+(ball4y-ey3)*(ball4y-ey3);

range[12]=(ball5x-ex1)*(ball5x-ex1)+(ball5y-ey1)*(ball5y-ey1);
range[13]=(ball5x-ex2)*(ball5x-ex2)+(ball5y-ey2)*(ball5y-ey2);
range[14]=(ball5x-ex3)*(ball5x-ex3)+(ball5y-ey3)*(ball5y-ey3);

if(range[0]<=3000){
	brustxy[0][0]=ball1x;
    brustxy[1][0]=ball1y;
	brustno[0]=1;
   ball1x=ball1y=-30;
   ex1=ey1=-500;
   b1=e1=0;
   score+=10;
   PlaySound("music\\smoke-bomb-6761.wav",NULL,SND_ASYNC);
}
else if(range[1]<=3000){
	brustxy[0][1]=ball1x;
    brustxy[1][1]=ball1y;
	brustno[1]=1;
	ball1x=ball1y=-30;
	ex2=ey2=-500;
   b2=e2=0;
   score+=10;
   PlaySound("music\\smoke-bomb-6761.wav",NULL,SND_ASYNC);
}
else if(range[2]<=3000){
   brustxy[0][2]=ball1x;
    brustxy[1][2]=ball1y;
	brustno[2]=1;
	ball1x=ball1y=-30;
	ex3=ey3=-500;
   b3=e3=0;
   score+=10;
   PlaySound("music\\smoke-bomb-6761.wav",NULL,SND_ASYNC);
}

else if(range[3]<=3000){
	brustxy[0][3]=ball2x;
    brustxy[1][3]=ball2y;
	brustno[3]=1;
	ball2x=ball2y=-30;
	ex1=ey1=-500;
   b2=e1=0;
   score+=10;
   PlaySound("music\\smoke-bomb-6761.wav",NULL,SND_ASYNC);
}
else if(range[4]<=3000){
	brustxy[0][4]=ball2x;
    brustxy[1][4]=ball2y;
	brustno[4]=1;
	ball2x=ball2y=-30;
	ex2=ey2=-500;
   b2=e2=0;
   score+=10;
   PlaySound("music\\smoke-bomb-6761.wav",NULL,SND_ASYNC);
}
else if(range[5]<=3000){
	brustxy[0][5]=ball2x;
    brustxy[1][5]=ball2y;
	brustno[5]=1;
	ball2x=ball2y=-30;
	ex3=ey3=-500;
   b2=e3=0;
   score+=10;
   PlaySound("music\\smoke-bomb-6761.wav",NULL,SND_ASYNC);
}

else if(range[6]<=3000){
	brustxy[0][6]=ball3x;
    brustxy[1][6]=ball3y;
	brustno[6]=1;
	ball3x=ball3y=-30;
	ex1=ey1=-500;
   b3=e1=0;
   score+=10;
   PlaySound("music\\smoke-bomb-6761.wav",NULL,SND_ASYNC);
}
else if(range[7]<=3000){
	brustxy[0][7]=ball3x;
    brustxy[1][7]=ball3y;
	brustno[7]=1;
	ball3x=ball3y=-30;
	ex2=ey2=-500;
   b3=e2=0;
   score+=10;
   PlaySound("music\\smoke-bomb-6761.wav",NULL,SND_ASYNC);
}
else if(range[8]<=3000){
	brustxy[0][8]=ball3x;
    brustxy[1][8]=ball3y;
	brustno[8]=1;
	ball3x=ball3y=-30;
	ex3=ey3=-500;
   b3=e3=0;
   score+=10;
   PlaySound("music\\smoke-bomb-6761.wav",NULL,SND_ASYNC);
}

else if(range[9]<=3000){
	brustxy[0][9]=ball4x;
    brustxy[1][9]=ball4y;
	brustno[9]=1;
	ball4x=ball4y=-30;
	ex1=ey1=-500;
   b4=e1=0;
   score+=10;
   PlaySound("music\\smoke-bomb-6761.wav",NULL,SND_ASYNC);
}
else if(range[10]<=3000){
	brustxy[0][10]=ball4x;
    brustxy[1][10]=ball4y;
	brustno[10]=1;
	ball4x=ball4y=-30;
	ex2=ey2=-500;
   b4=e2=0;
   score+=10;
   PlaySound("music\\smoke-bomb-6761.wav",NULL,SND_ASYNC);
}
else if(range[11]<=3000){
	brustxy[0][11]=ball4x;
    brustxy[1][11]=ball4y;
	brustno[11]=1;
	ball4x=ball4y=-30;
	ex3=ey3=-500;
   b4=e3=0;
   score+=10;
   PlaySound("music\\smoke-bomb-6761.wav",NULL,SND_ASYNC);
}

else if(range[12]<=3000){
	brustxy[0][12]=ball5x;
    brustxy[1][12]=ball5y;
	brustno[12]=1;
	ball5x=ball5y=-30;
	ex1=ey1=-500;
   b5=e1=0;
   score+=10;
   PlaySound("music\\smoke-bomb-6761.wav",NULL,SND_ASYNC);
}
else if(range[13]<=3000){
	brustxy[0][13]=ball5x;
    brustxy[0][13]=ball5y;
	brustno[13]=1;
	ball5x=ball5y=-30;
	ex2=ey2=-500;
   b5=e2=0;
   score+=10;
   PlaySound("music\\smoke-bomb-6761.wav",NULL,SND_ASYNC);
}
else if(range[14]<=3000){
	brustxy[0][14]=ball5x;
    brustxy[1][14]=ball5y;
	brustno[14]=1;
	ball5x=ball5y=-30;
	ex3=ey3=-500;
   b5=e3=0;
   score+=10;
   PlaySound("music\\smoke-bomb-6761.wav",NULL,SND_ASYNC);
}


}

void winpage(){
   iShowBMP(0,0,"img\\endpage.bmp");
   iSetColor(0,0,0);
   iFilledRectangle(0,550,1000,30);
   if(win==1){
	iSetColor(0,255,0);//Green
	 strcpy(declare,"CONGRATULATIONS,YOU WON!!!");
	 starw=4;
	 if(winmusic==0){
		PlaySound("music\\win.wav",NULL,SND_ASYNC);
		winmusic=1;
	 }
   }
   else if (win==-1){
	iSetColor(255,0,0);
	strcpy(declare,"SORRY, YOU LOST!!!");
   }
 
   iText(355,555,declare,GLUT_BITMAP_TIMES_ROMAN_24);
   
   //Menu Button
   iSetColor(r,g,b);
   iFilledRectangle(0,5,100,25);
   iSetColor(255,255,255);
   iText(5,6,"Profile",GLUT_BITMAP_TIMES_ROMAN_24);

   //Next Level Button
   iSetColor(r,g,b);
   iFilledRectangle(800,5,100,25);
   iSetColor(255,255,255);
   iText(802,6,"Quit",GLUT_BITMAP_TIMES_ROMAN_24);

   //Graph

   iSetColor(128,0,0);//badami
   iFilledRectangle(150,50,600,450);
   iSetColor(r,g,b);
   iFilledRectangle(153,53,594,444);//Graph
   iSetColor(128,0,0);
   iFilledRectangle(150,80,600,3);//Base Line
  //Health Graph 
  int comhs;
   if(timelimit==1800){
      comhs=(comh*100)/1000;
   }
   else if(timelimit==3600){
      comhs=(comh*100)/1500;
   }
   else if(timelimit==5400){
     comhs=(comh*100)/2000;
   }

   if(comhs>80){
	 cr=0,cg=255,cb=0;
   }
   else if(comhs>50){
	cr=255,cg=255,cb=0;
   }
   else{
	cr=255,cg=0,cb=0;
   }
   iSetColor(cr,cg,cb);
   iFilledRectangle(200,80,50,comhs*4);//My lasting health
   iText(195,60,"Health",GLUT_BITMAP_TIMES_ROMAN_24);
   iSetColor(0,255,0);
   iFilledRectangle(275,80,50,400);//Best health
   iText(270,60,"Best-Health",GLUT_BITMAP_TIMES_ROMAN_24);
    
	if(comt!=0)
    kpm=(coms*60)/comt;
	else kpm=0;
	if(kpm>=4) strkpm=3;
	else if(kpm>=3) strkpm=2;
	else if(kpm>=1) strkpm=1;

//Score Graph
int comps;
if(scrcnts!=0)
comps=(coms*10)/scrcnts;
else 
comps=0;

if(comps>80){
	cr=0,cg=255,cb=0;
	starcmp=3;
}
else if(comps>50){
	cr=255,cg=255,cb=0;
	starcmp=2;
}
else {
	cr=255,cg=0,cb=0;
	if(comps>=20) starcmp=1;
	else starcmp=0;
}  

  char sc[5];
   iSetColor(cr,cg,cb);
   iFilledRectangle(500,80,50,comps*4);//My Score
   iText(495,60,"Score",GLUT_BITMAP_TIMES_ROMAN_24);
   sprintf(sc,"%d",coms);
   iText(495,60+comps*4+25,sc,GLUT_BITMAP_TIMES_ROMAN_24);
   iSetColor(0,255,0);
   iFilledRectangle(575,80,50,400);//Best Score
   iText(570,60,"Best-Score",GLUT_BITMAP_TIMES_ROMAN_24);


}

void exploid(){
   if(brustno[0]!=0 && brustno[0]!=3) brustno[0]++;
   else if(brustno[0]==3){
	brustno[0]=0;
	brustxy[0][0]=brustin;
	brustxy[1][0]=brustin;
}

if(brustno[1]!=0&& brustno[1]!=3) brustno[1]++;
else if(brustno[1]==3){
	brustno[1]=0;
	brustxy[0][1]=brustin;
	brustxy[1][1]=brustin;
}

if(brustno[2]!=0&& brustno[2]!=3) brustno[2]++;
else if(brustno[2]==3){
	brustno[2]=0;
	brustxy[0][2]=brustin;
	brustxy[1][2]=brustin;
}

if(brustno[3]!=0 && brustno[3]!=3) brustno[3]++;
else if(brustno[3]==3){
	brustno[3]=0;
	brustxy[0][3]=brustin;
	brustxy[1][3]=brustin;
}

if(brustno[4]!=0 && brustno[4]!=3) brustno[4]++;
else if(brustno[4]==3){
	brustno[4]=0;
	brustxy[0][4]=brustin;
	brustxy[1][4]=brustin;
}

if(brustno[5]!=0 && brustno[5]!=3) brustno[5]++;
   else if(brustno[5]==3){
	brustno[5]=0;
	brustxy[0][5]=brustin;
	brustxy[1][5]=brustin;
}

if(brustno[6]!=0 && brustno[6]!=3) brustno[6]++;
else if(brustno[6]==3){
	brustno[6]=0;
	brustxy[0][6]=brustin;
	brustxy[1][6]=brustin;
}

if(brustno[7]!=0 && brustno[7]!=3) brustno[7]++;
else if(brustno[7]==3){
	brustno[7]=0;
	brustxy[0][7]=brustin;
	brustxy[1][7]=brustin;
}

if(brustno[8]!=0 && brustno[8]!=3) brustno[8]++;
if(brustno[8]==3){
	brustno[8]=0;
	brustxy[0][8]=brustin;
	brustxy[1][8]=brustin;
}

if(brustno[9]!=0 && brustno[9]!=3) brustno[9]++;
else if(brustno[9]==3){
	brustno[9]=0;
	brustxy[0][9]=brustin;
	brustxy[1][9]=-brustin;
}

if(brustno[10]!=0 && brustno[10]!=3) brustno[10]++;
   else if(brustno[10]==3){
	brustno[10]=0;
	brustxy[0][10]=brustin;
	brustxy[1][10]=brustin;
}

if(brustno[11]!=0 && brustno[11]!=3) brustno[11]++;
else if(brustno[11]==3){
	brustno[11]=0;
	brustxy[0][11]=brustin;
	brustxy[1][11]=brustin;
}

if(brustno[12]!=0 && brustno[12]!=3) brustno[12]++;
else if(brustno[12]==3){
	brustno[12]=0;
	brustxy[0][12]=brustin;
	brustxy[1][12]=brustin;
}

if(brustno[13]!=0 && brustno[13]!=3) brustno[13]++;
if(brustno[13]==3){
	brustno[13]=0;
	brustxy[0][13]=brustin;
	brustxy[1][13]=brustin;
}

if(brustno[14]!=0 && brustno[14]!=3) brustno[14]++;
else if(brustno[14]==3){
	brustno[14]=0;
	brustxy[0][14]=brustin;
	brustxy[1][14]=brustin;
}

}

void highscore(){
    FILE *fh=fopen("highscore.txt","r");
	int r=0;
    while(1){
		int status=fscanf(fh,"%s %d",name[r],&position[r]);
		r++;
		if(status==EOF) break;
	}
	fclose(fh);
	char n[30],s[10];
	int sc;
	iShowBMP(0,0,"img//highscore.bmp");

	iSetColor(r,g,b);
	iFilledRectangle(125,490,300,80);
	iFilledRectangle(500,490,80,80);
	iSetColor(255,255,255);
    sprintf(n,"%s",name[0]);
	iText(127,510,n,GLUT_BITMAP_TIMES_ROMAN_24);
    sprintf(s,"%d",position[0]);
	iText(520,510,s,GLUT_BITMAP_TIMES_ROMAN_24);

	iSetColor(r,g,b);
	iFilledRectangle(125,380,300,80);
	iFilledRectangle(500,380,80,80);
	iSetColor(255,255,255);
	strcpy(n,"");
	sprintf(n,"%s",name[1],position[1]);
	iText(127,400,n,GLUT_BITMAP_TIMES_ROMAN_24);
	strcpy(s,"");
	sprintf(s,"%d",position[1]);
	iText(520,400,s,GLUT_BITMAP_TIMES_ROMAN_24);


	iSetColor(r,g,b);
	iFilledRectangle(125,270,300,80);
	iFilledRectangle(500,270,80,80);
	iSetColor(255,255,255);
	strcpy(n,"");
	sprintf(n,"%s",name[2],position[2]);
	iText(127,290,n,GLUT_BITMAP_TIMES_ROMAN_24);
	strcpy(s,"");
	sprintf(s,"%d",position[2]);
	iText(520,290,s,GLUT_BITMAP_TIMES_ROMAN_24);

	iSetColor(r,g,b);
	iFilledRectangle(125,150,300,80);
	iFilledRectangle(500,150,80,80);
	iSetColor(255,255,255);
	strcpy(n,"");
	sprintf(n,"%s",name[3],position[3]);
	iText(127,160,n,GLUT_BITMAP_TIMES_ROMAN_24);
	strcpy(s,"");
	sprintf(s,"%d",position[3]);
	iText(520,160,s,GLUT_BITMAP_TIMES_ROMAN_24);

	iSetColor(r,g,b);
	iFilledRectangle(125,40,300,80);
	iFilledRectangle(500,40,80,80);
	iSetColor(255,255,255);
	strcpy(n,"");
	sprintf(n,"%s",name[4],position[4]);
	iText(127,60,n,GLUT_BITMAP_TIMES_ROMAN_24);
	strcpy(s,"");
	sprintf(s,"%d",position[4]);
	iText(520,60,s,GLUT_BITMAP_TIMES_ROMAN_24);
	//
	iSetColor(r,g,b);
	iFilledRectangle(800,25,190,30);
	iSetColor(255,255,255);
	iText(820,29,"Menu",GLUT_BITMAP_TIMES_ROMAN_24);
}

void chooselevel(){
	  
	     iShowBMP(0,0,pimg[0]);
    
	//Level one 30 minutes game
		iSetColor(0, 0, 0);
		iFilledRectangle(348, 498, 304, 54);
		iSetColor(lr3, lg3, lb3);
		iFilledRectangle(350, 500, 300, 50);
		iSetColor(255, 255, 255);
		iText(450, 510, "Play 30 minutes", GLUT_BITMAP_TIMES_ROMAN_24);

		// Level two 60 minutes game
		iSetColor(0, 0, 0);
		iFilledRectangle(348, 423, 304, 54);
		iSetColor(lr6, lg6, lb6);
		iFilledRectangle(350, 425, 300, 50);
		iSetColor(255, 255, 255);
		iText(450, 435, "Play 60 minutes", GLUT_BITMAP_TIMES_ROMAN_24);

		// Instruction Button
		iSetColor(0, 0, 0);
		iFilledRectangle(348, 348, 304, 54);
		iSetColor(lr9, lg9, lb9);
		iFilledRectangle(350, 350, 300, 50);
		iSetColor(255, 255, 255);
		iText(450, 360, "Play 90 minutes", GLUT_BITMAP_TIMES_ROMAN_24);
     
	 /*//Play your custom time
	   
	   iSetColor(0, 0, 0);
		iFilledRectangle(348, 273, 304, 54);
		iSetColor(lr, lg, lb);
		iFilledRectangle(350, 275, 300, 50);
		iSetColor(255, 255, 255);
		iText(450, 285, "Write custom time", GLUT_BITMAP_TIMES_ROMAN_24);
    */

    //Back Button
		iSetColor(r, g, b);
		iFilledRectangle(800, 5, 100, 50);
		iSetColor(255, 255, 255);
		iText(830, 10, "Back", GLUT_BITMAP_TIMES_ROMAN_24);
   
   //Start
       
        iSetColor(r, g, b);
		iFilledRectangle(800, 100, 100, 50);
		iSetColor(255, 255, 255);
		iText(830, 105, "Start", GLUT_BITMAP_TIMES_ROMAN_24);

}

int main()
{   
	iSetTimer(speedbomb,herosht);
	iSetTimer(speedbomb,scoring);
	iSetTimer(5,exploid);
	iSetTimer(speedini,enemyfallini);
	iSetTimer(speedenemy,enemyfall);
    
	iInitialize(1000, 600, "ron");
	return 0;
}
