#include<iostream>
#include<graphics.h>
#include<cstdlib>
#include<fstream>

using namespace std;

/////////////////////////////////////////////////////////
class game
{
public:
    void writescore(int sc);
    void readscore();
    void show();
    void treasure();
    void help();
    void intro();

};
void game :: intro()
{
        int y=0;
        setcolor(GREEN);
        setfillstyle(SOLID_FILL,GREEN);
        rectangle(10,10,getmaxx()-10,getmaxy()-10);
        floodfill(20,20,GREEN);
        settextstyle(GOTHIC_FONT,0,5);
        outtextxy(40,170," TREASURE  RUN ");
        settextstyle(SANS_SERIF_FONT,0,3);
        outtextxy(90,400," Press ENTER to continue ");
        getch();
}
void game :: help()
{
    settextstyle(SANS_SERIF_FONT,0,4);
    outtextxy(180,80,"GAME      RULES");
    settextstyle(SANS_SERIF_FONT,0,2);
    outtextxy(140,150,"Race till the end and the treasure will be yours");
    outtextxy(60,200,"Use left and right navigation keys to avoid incoming OBSTACLES!");
    outtextxy(200,250,"You have to cross 5 levels!");
    outtextxy(140,300,"Your speed will increase after each level");
    outtextxy(120,350,"You have only 3 LIVES to complete your quest");
    outtextxy(250,450,"ALL THE BEST");
    getch();
}
void game :: treasure()
{
        setcolor(BROWN);
        setfillstyle(SOLID_FILL,BROWN);
        bar3d(200,250,400,350,80,1);
        floodfill(410,320,BROWN);
        bar3d(280,80,478,205,20,1);
        floodfill(300,78,BROWN);
        floodfill(480,195,BROWN);
        setfillstyle(SOLID_FILL,YELLOW);
        floodfill(250,248,BROWN);
        setcolor(BLACK);
        setfillstyle(SOLID_FILL,BLACK);
        delay(500);
}

void game :: show()
{
    int col[25];

    setcolor(RED);
    setfillstyle(SOLID_FILL,RED);
    col[0]=525;
    col[1]=350;
    col[2]=col[0]-40;
    col[3]=col[1]-40;
    col[4]=col[0]-20;
    col[5]=col[1]-40;
    col[6]=col[0]+15;
    col[7]=col[1]-10;
    col[8]=col[0]+50;
    col[9]=col[1]-40;
    col[10]=col[0]+70;
    col[11]=col[1]-40;
    col[12]=col[0]+30;
    col[13]=col[1];
    col[14]=col[0]+70;
    col[15]=col[1]+35;
    col[16]=col[0]+50;
    col[17]=col[1]+35;
    col[18]=col[0]+15;
    col[19]=col[1]+10;
    col[20]=col[0]-20;
    col[21]=col[1]+35;
    col[22]=col[0]-40;
    col[23]=col[1]+35;
    col[24]=col[0];
    col[25]=col[1];
    drawpoly(13,col);
    fillpoly(13,col);
    Beep(600,700);
    delay(2000);
    setcolor(GREEN);
    setfillstyle(SOLID_FILL,GREEN);
    rectangle(col[2],col[3],col[14],col[15]);
    floodfill(col[0]-5,col[1],GREEN);
    drawpoly(13,col);
    fillpoly(13,col);
}
void game :: writescore(int sc)
{
    ofstream f;
    char name[10];
    f.open("scores.txt",ios::app);
    settextstyle(SANS_SERIF_FONT,0,2);
    setcolor(WHITE);
    outtextxy(150,420,"Enter first three letters of your name : ");
    cin>>name;
    outtextxy(480,420,name);
    getch();
    f<<name;
    f<<" ";
    f<<sc;
    f<<endl;
    f.close();
}

void game :: readscore()
{
  ifstream f;
  char data[20];

  f.open("scores.txt",ios::in);
  int x=150,y=80;
  while(f)
  {
      f.getline(data,20);
      outtextxy(x,y,data);
      y=y+40;
  }
  f.close();
}

//////////////////////////////////////////////////////////////////////////////////
class rock
{
    int poly[20];
public:
    rock()
    {
       for(int i=0;i<=19;i++)
            poly[i]=0;
    }
    int cx()
    {
        return((poly[0]+poly[16])/2);
    }
    void rdraw(int x,int y);
    void clearme(int x,int y);
};
void rock :: clearme(int x,int y)
{
    setcolor(BLACK);
    setfillstyle(SOLID_FILL,BLACK);
    drawpoly(10,poly);
    fillpoly(10,poly);
}
void rock :: rdraw(int x,int y)
{
        poly[0]=x;
        poly[1]=y;
        poly[2]=x+4;
        poly[3]=y-50;
        poly[4]=x+9;
        poly[5]=y-60;
        poly[6]=x+19;
        poly[7]=y-70;
        poly[8]=x+33;
        poly[9]=y-75;
        poly[10]=x+47;
        poly[11]=y-70;
        poly[12]=x+57;
        poly[13]=y-60;
        poly[14]=x+62;
        poly[15]=y-50;
        poly[16]=x+67;
        poly[17]=y;
        poly[18]=poly[0];
        poly[19]=poly[1];
    setcolor(DARKGRAY);
    setfillstyle(SOLID_FILL,DARKGRAY);
    drawpoly(10,poly);
    fillpoly(10,poly);
    setcolor(BLACK);
    line(poly[8],poly[9],(poly[12]+poly[4])/2,poly[13]);
    line((poly[12]+poly[4])/2,poly[13],poly[14],poly[15]);
    line((poly[12]+poly[4])/2,poly[13],poly[2],poly[3]);
    line((poly[12]+poly[4])/2,poly[13],(poly[0]+poly[16])/2,poly[1]);
    line((poly[12]+poly[4])/2,poly[1]-20,poly[0],poly[1]);
    line((poly[12]+poly[4])/2,poly[1]-20,poly[16],poly[17]);
    line((poly[12]+poly[4])/2,poly[1]-20,poly[2],poly[3]);
    line((poly[12]+poly[4])/2,poly[1]-20,poly[14],poly[15]);
    line((poly[12]+poly[4])/2,poly[1]-20,poly[16]-2,poly[1]-20);
    line((poly[12]+poly[4])/2,poly[1]-20,poly[0],poly[1]-20);

}
///////////////////////////////////////////////////////////////////////////
class spikes
{
    int point[24];
public:
    spikes()
    {
        for(int i=0;i<=23;i++)
        {
            point[0]=0;
        }
    }
    void sdraw(int x,int y);
    int cx()
    {
        return((point[0]+point[20])/2);
    }
    void clearme(int x,int y);

};
void spikes :: sdraw(int x,int y)
{
    point[0]=x;
        point[1]=y;
        point[2]=x+9;
        point[3]=y-10;
        point[4]=x;
        point[5]=y-45;
        point[6]=x+19;
        point[7]=y-20;
        point[8]=x+24;
        point[9]=y-55;
        point[10]=x+29;
        point[11]=y-20;
        point[12]=x+44;
        point[13]=y-55;
        point[14]=x+49;
        point[15]=y-20;
        point[16]=x+67;
        point[17]=y-45;
        point[18]=x+59;
        point[19]=y-10;
        point[20]=x+67;
        point[21]=y;
        point[22]=x;
        point[23]=y;
    setcolor(GREEN);
    setfillstyle(SOLID_FILL,GREEN);
    drawpoly(12,point);
    fillpoly(12,point);
}
void spikes :: clearme(int x,int y)
{
    setcolor(BLACK);
    setfillstyle(SOLID_FILL,BLACK);
    drawpoly(12,point);
    fillpoly(12,point);
}
///////////////////////////////////////////////////////////////////////////////////////////

class avatar
{
    int xs,ys,rs,xh,yh,rh,xll,xrl,yll,yrl,rll,rrl,rll1,rrl1,cl,cr,lla1,lla2,rla1,rla2;
    int xlh,xrh,ylh,yrh,rlh,rrh;
public:
    avatar()
    {
        xs=305;
        ys=400;
        rs=25;
        cl=7;
        cr=8;
        lla1=30;
        lla2=30;
        rla1=30;
        rla2=30;
        rll=7;
        rrl=7;
        rll1=rll;
        rrl1=rrl+3;
        rrh=7;
        rlh=7;
        rh=16;
        yrh=403;
        ylh=393;
    }
    void adraw(int xs,int ys);
    void moveright();
    void moveleft();
    int cx()
    {
        return xh;
    }
    void clearme(int xs,int ys)
    {
        xh=xs;
        yh=ys-rs-8;
        setcolor(BLACK);
        setfillstyle(SOLID_FILL,BLACK);
        ellipse(xs,ys,30,30,rs-3,rs+5);
        line(xs-rs,ys+5,xs+rs,ys+5);
        floodfill(xs,ys+8,BLACK);
        floodfill(xs,ys-4,BLACK);
        circle(xh,yh,rh);
        line(xh-rh,yh,xh+rh,yh);
        floodfill(xh,yh-1,BLACK);
        floodfill(xh,yh+1,BLACK);
        ellipse(xll,yll,lla1,lla2,rll,rrl1);
        floodfill(xll,yll,BLACK);
        ellipse(xrl,yrl,rla1,rla2,rrl,rrl1);
        floodfill(xrl,yrl,BLACK);
        circle(xlh,ylh,rlh);
        floodfill(xlh,ylh,BLACK);
        circle(xrh,yrh,rrh);
        floodfill(xrh,yrh,BLACK);
    }
};
void avatar :: adraw(int xs,int ys)
 {
        xh=xs;
        yh=ys-rs-8;
        setcolor(BLUE);
        setfillstyle(SOLID_FILL,BLUE);
        ellipse(xs,ys,30,30,rs-3,rs+5);
        line(xs-rs+4,ys+5,xs+rs-4,ys+5);
        floodfill(xs,ys+8,BLUE);
        //pant
        setfillstyle(SOLID_FILL,LIGHTMAGENTA);
        floodfill(xs,ys-4,BLUE);
        //head
        setcolor(YELLOW);
        setfillstyle(SOLID_FILL,YELLOW);
        circle(xh,yh,rh);
        line(xh-rh,yh,xh+rh,yh);
        floodfill(xh,yh-1,YELLOW);
        //hair
        setfillstyle(SOLID_FILL,BLACK);
        floodfill(xh,yh+1,YELLOW);
        xll=xs-(rs/2);
        yll=ys+rs+8;
        xrl=xs+(rs/2);
        yrl=ys+rs+8;
        //left leg
        setcolor(cl);
        setfillstyle(SOLID_FILL,cl);
        ellipse(xll,yll,lla1,lla2,rll,rll1);
        floodfill(xll,yll,cl);
        //right leg
        setcolor(cr);
        setfillstyle(SOLID_FILL,cr);
        ellipse(xrl,yrl,rla1,rla2,rrl,rrl1);
        floodfill(xrl,yrl,cr);
        //left hand
        setcolor(LIGHTMAGENTA);
        setfillstyle(SOLID_FILL,LIGHTMAGENTA);
        circle(xs-rs,ylh,rlh);
        floodfill(xs-rs,ylh,LIGHTMAGENTA);

        //right hand
        circle(xs+rs,yrh,rrh);
        floodfill(xs+rs,yrh,LIGHTMAGENTA);

        delay(100);
        setcolor(BLACK);
        setfillstyle(SOLID_FILL,BLACK);
        ellipse(xll,yll,lla1,lla2,rll,rll1);
        floodfill(xll,yll,BLACK);
        ellipse(xrl,yrl,rla1,rla2,rrl,rrl1);
        floodfill(xrl,yrl,BLACK);

        circle(xs-rs,ylh,rlh);
        floodfill(xs-rs,ylh,BLACK);
        circle(xs+rs,yrh,rrh);
        floodfill(xs+rs,yrh,BLACK);

        swap(cl,cr);
        swap(rll1,rrl1);
        swap(ylh,yrh);
}

///////////////////////////////////////////////////////////////////
int main()
 {
    static int counter=0;
    avatar a;
    rock r;
    spikes s;
    game g;
    int driver,mode;
    driver = DETECT;
    initgraph(&driver,&mode,"");

    int x=(getmaxx()/2),y=400,ch,life=3,score=0;
    //intro
    if(counter==0)
    {
        g.intro();
        counter++;
    }
    //menu
    cleardevice();
    setcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    rectangle(110,100,505,360);
    rectangle(130,120,485,340);
    floodfill(getmaxx()/2,getmaxy()/2,LIGHTGRAY);
    setfillstyle(SOLID_FILL,DARKGRAY);
    floodfill(220,110,LIGHTGRAY);
    settextstyle(0,0,4);
    outtextxy(165,50,"MAIN MENU");
    settextstyle(SANS_SERIF_FONT,0,2);
    outtextxy(190,140," 1.  NEW GAME  ");
    outtextxy(190,180," 2.  HELP ");
    outtextxy(190,220," 3.  HIGH SCORES  ");
    outtextxy(190,260," 4.  EXIT  ");
    outtextxy(160,300," CHOOSE AN OPTION :");
    char option=getch();
    outtextxy(430,300,&option);
    getch();
    switch(option)
    {

        case '1' :  cleardevice();
                    setcolor(GREEN);
                    setfillstyle(SOLID_FILL,GREEN);
                    rectangle(2*getmaxx()/3,0,getmaxx(),getmaxy());
                    rectangle(0,0,getmaxx()/3,getmaxy());

                    rectangle(20,150,190,210);
                    rectangle(20,350,190,410);
                    rectangle(440,150,620,210);
                    floodfill(10,10,GREEN);
                    floodfill(500,10,GREEN);

                    outtextxy(5,15," Press <Esc> to Exit ");
                    for(int level=1;(level<=2)&&(life>0);level++)
                    {
                        if(level==1)
                        {
                            outtextxy(440,50," The Hunt Has Begun ");
                            delay(1000);
                            outtextxy(440,50,"                                     ");
                        }
                        else
                        {
                            setcolor(WHITE);
                            outtextxy(440,50," Entering Next level ");
                            delay(5000);
                            outtextxy(440,50,"                                       ");
                        }
                        for(int i=0;(i<15)&&(life>0);i++)
                        {
                            if((level==2)&&(i==14))
                            {
                                cleardevice();
                                setcolor(WHITE);
                                settextstyle(SANS_SERIF_FONT,0,4);
                                outtextxy(200,30," You have Won ");
                                settextstyle(SANS_SERIF_FONT,0,2);
                                g.treasure();
                                Beep(1000,500);
                                Beep(900,500);
                                Beep(800,500);
                                Beep(900,100);
                                Beep(800,500);
                                g.writescore(score);
                                main();
                            }
                            setcolor(WHITE);
                            outtextxy(55,170,"Level = ");
                            char s_level[2];
                            itoa(level,s_level,10);
                            outtextxy(120,170,s_level);

                            outtextxy(490,170,"Lives = ");
                            char s_life[2];
                            itoa(life,s_life,10);
                            outtextxy(560,170,s_life);

                            outtextxy(55,370,"Score = ");
                            char s_score[10];
                            itoa(score,s_score,10);
                            outtextxy(130,370,s_score);

                            int accident=0;
                            int y1=1,x1=215+((rand()%3)*70);
                            int y2=1,x2=215+((rand()%3)*70);
                            score += 10;
                            while(y1<getmaxy()-1)
                            {
                                s.clearme(x1,y1);
                                r.clearme(x2,y2);
                                y1+=10*level;
                                y2+=10*level;
                                s.sdraw(x1,y1);
                                r.rdraw(x2,y2);
                                a.adraw(x,y);
                                //delay((5-level)*10);
                                if(kbhit())
                                {
                                    a.adraw(x,y);
                                    ch=getch();
                                    switch(ch)
                                    {
                                        case 27:    exit(0);   //escape
                                                    break;
                                        case 75:    a.clearme(x,y);    //left
                                                    if(x>270)
                                                        x=x-70;
                                                    a.adraw(x,y);
                                                    break;
                                        case 77:    a.clearme(x,y);    //right
                                                    if(x<375)
                                                        x=x+70;
                                                    a.adraw(x,y);
                                                    break;
                                    }
                                }
                                //check for collision
                                if(((a.cx()-s.cx())<5 && (a.cx()-s.cx())>-5) || ((a.cx()-r.cx())<5) && ((a.cx()-r.cx())>-5))
                                {
                                    if( ( ((y-y1)<100)&&((y-y1)>0) ) || ( ((y-y2)<100)&&((y-y2)>0) ) )
                                        accident=1;
                                }
                            }
                            if(accident==1)
                            {
                                setcolor(WHITE);
                                life--;
                                score-= 10;
                                if(life==0)
                                {
                                    cleardevice();
                                    settextstyle(SANS_SERIF_FONT,0,4);
                                    outtextxy(200,100,"GAME OVER ");
                                    settextstyle(SANS_SERIF_FONT,0,2);
                                    Beep(1000,500);
                                    Beep(900,500);
                                    Beep(800,500);
                                    Beep(900,100);
                                    Beep(800,500);

                                    outtextxy(180,150,"You could not make it to the treasure");
                                    g.writescore(score);
                                    main();
                                }
                                outtextxy(460,400,"  You lost a life   ");
                                g.show();
                                outtextxy(460,400,"                            ");
                            }
                        }
                    }
                    break;
                    //CASE 1 ENDS HERE

        case '2' :      cleardevice();
                        g.help();
                        main();
        case '3' :      cleardevice();
                        settextstyle(SANS_SERIF_FONT,0,4);
                        outtextxy(180,40,"HIGH SCORES");
                        settextstyle(SANS_SERIF_FONT,0,2);
                        g.readscore();
                        getch();
                        main();
        case '4' :      exit(0);
        default :   outtextxy(400,400,"invalid choice");
                    delay(200);
                    main();
    }

    getch();
    closegraph();
    return 0;
}
