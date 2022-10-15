#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <string.h>

//Functions Declaration
void strsplit(int firstIndex, int lastIndex, char str[],char newstr[]);
int strsplitint(int firstIndex, int lastIndex, char str[]);
void digitaleDigits(int digitNumber, char digit[][5]);
void delay(int time);
//main function executable program
void main()
{
    //Variables
    //Digits Variables
    char digit[7][5]={' '};
    int digitalDigits;
    int i,j;
    int hl,hr,minl,minr,secl,secr;
    int h,min,sec;
    time_t rawtime;
    char Time[50], timeNow[9];

    //Get Current Time
    time(&rawtime);
    strcpy(Time,asctime(localtime ( &rawtime )));
    strsplit(11,18,Time,timeNow);

    //Convert string time to Hours, Minutes and Seconds integer
    h = strsplitint(0,2,timeNow);
    min = strsplitint(3,5,timeNow);
    sec = strsplitint(6,8,timeNow);

    //initialize Hours
    hl = h/10;
    hr = h%10;
    //initialize Minutes
    minl = min/10;
    minr = min%10;
    //initialize Seconds
    secl = sec/10;
    secr = sec%10;

    //Start Clock
    for(secr;secr<10;secr++)
    {
        clrscr();

        //Affichage
        for(i=0;i<7;i++)
        {
            //Set how many digital digits want to show
            digitalDigits = 6;

            for(j=0;j<5;j++)
            {
                switch(digitalDigits)
                {
                    //Seconds
                    case 1: digitaleDigits(secr,digit);break;
                    case 2: digitaleDigits(secl,digit);break;
                    //Minutes
                    case 3: digitaleDigits(minr,digit);break;
                    case 4: digitaleDigits(minl,digit);break;
                    //Hours
                    case 5: digitaleDigits(hr,digit);break;
                    case 6: digitaleDigits(hl,digit);break;
                }

                printf("%c",digit[i][j]);

                if(j==4 && digitalDigits>1)
                {
                    j=-1;
                    digitalDigits--;
                    if((digitalDigits == 2 || digitalDigits == 4) && i==3)
                        printf("  :  ");
                    else if(digitalDigits%2 == 1)
                        printf(" ");
                    else
                        printf("     ");
                }
            }
            printf("\n");
        }

        if(secr==9)
        {
            if(!(secl==5 && secr==9))
                secr=-1;
            else
            {
                secr=-1;secl=-1;

                if(minr==9)
                {
                    if(!(minl==5 && minr==9))
                        minr=-1;
                    else
                    {
                        minr=-1;minl=-1;

                        if(hr==3)
                        {
                            if(!(hl==2 && hr==3))
                            {
                                hr=-1;
                            }
                            else
                            {
                             hl=-1;hr=-1;
                            }
                            hl++;
                        }
                        hr++;
                    }
                    minl++;
                }
                minr++;
            }
            secl++;
        }
        delay(50000);
    }
}
//Function Split String
void strsplit(int firstIndex, int lastIndex, char str[],char newstr[])
{
    int i,j;
    lastIndex -= firstIndex + 1;
    for(i=firstIndex,j=0;(unsigned)i<strlen(str)-lastIndex;i++,j++)
        newstr[j] = str[i];
}
//Function return Splited String
int strsplitint(int firstIndex, int lastIndex, char str[])
{
    int i,j,number;
    char newstr[50];

    lastIndex -= firstIndex + 1;
    for(i=firstIndex,j=0;(unsigned)i<strlen(str)-lastIndex;i++,j++)
        newstr[j] = str[i];

    sscanf(newstr, "%d", &number);

    return number;
}
//Intialize Digit Function
void digitIntializer(char digit[][5])
{
    int i,j;

    for(i=0;i<7;i++)
    {
        for(j=0;j<5;j++)
        {
            digit[i][j] = ' ';
        }
    }
}
//Digits Functions
void digitaleDigits(int digitNumber, char digit[][5])
{
    int i,j;

    //initialize digit
    digitIntializer(digit);

    switch(digitNumber)
    {
        case 0:
            for(i=0;i<7;i++)
            {
                for(j=0;j<5;j++)
                {
                    if(i==0 || i==6)
                        digit[i][j] = '-';
                    else if(j==0 || j==4)
                        digit[i][j] = '|';
                }
            }
            break;
        case 1:
            for(i=0;i<7;i++)
            {
                for(j=0;j<5;j++)
                {
                    if((j==4 && i==1)||(j==4 && i==2)||(j==4 && i==2)
                       ||(j==4 && i==3)||(j==4 && i==4)||(j==4 && i==5))
                        digit[i][j] = '|';
                }
            }
            break;
        case 2:
            for(i=0;i<7;i++)
            {
                for(j=0;j<5;j++)
                {
                    if(i==0 || i==3 || i==6)
                        digit[i][j] = '-';
                    else if((j==4 && i==1)||(j==4 && i==2)||(j==0 && i==4)||(j==0 && i==5))
                        digit[i][j] = '|';
                }
            }
            break;
        case 3:
            for(i=0;i<7;i++)
            {
                for(j=0;j<5;j++)
                {
                    if(i==0 || i==3 || i==6)
                        digit[i][j] = '-';
                    else if(j==4)
                        digit[i][j] = '|';
                }
            }
            break;
        case 4:
            for(i=0;i<7;i++)
            {
                for(j=0;j<5;j++)
                {
                    if(i==3)
                        digit[i][j] = '-';
                    else if((j==0 && i==1) || (j==0 && i==2) || (j==4 && i==1) || (j==4 && i==2)
                            || (j==4 && i==3) || (j==4 && i==4) || (j==4 && i==5))
                        digit[i][j] = '|';
                }
            }
            break;
        case 5:
            for(i=0;i<7;i++)
            {
                for(j=0;j<5;j++)
                {
                    if(i==0 || i==3 || i==6)
                        digit[i][j] = '-';
                    else if((j==0 && i==1)||(j==0 && i==2)||(j==4 && i==4)||(j==4 && i==5))
                        digit[i][j] = '|';
                }
            }
            break;
        case 6:
            for(i=0;i<7;i++)
            {
                for(j=0;j<5;j++)
                {
                    if(i==0 || i==3 || i==6)
                        digit[i][j] = '-';
                    else if(j==0 ||(j==4 && i==4)||(j==4 && i==5))
                        digit[i][j] = '|';
                }
            }
            break;
        case 7:
            for(i=0;i<7;i++)
            {
                for(j=0;j<5;j++)
                {
                    if(i==0)
                        digit[i][j] = '-';
                    else if((j==4 && i==1)||(j==4 && i==2)||(j==4 && i==2)
                       ||(j==4 && i==3)||(j==4 && i==4)||(j==4 && i==5))
                        digit[i][j] = '|';
                }
            }
            break;
        case 8:
            for(i=0;i<7;i++)
            {
                for(j=0;j<5;j++)
                {
                    if(i==0 || i==3 || i==6)
                        digit[i][j] = '-';
                    else if(j==0 || j==4)
                        digit[i][j] = '|';
                }
            }
            break;
        case 9:
            for(i=0;i<7;i++)
            {
                for(j=0;j<5;j++)
                {
                    if(i==0 || i==3)
                        digit[i][j] = '-';
                    else if((j==0 && i==1) || (j==0 && i==2) || (j==4 && i==1)||(j==4 && i==2)
                            ||(j==4 && i==2)||(j==4 && i==3)||(j==4 && i==4)||(j==4 && i==5))
                        digit[i][j] = '|';
                }
            }
            break;
        default:
            for(i=0;i<7;i++)
            {
                for(j=0;j<5;j++)
                {
                    if(i==0 || i==6)
                        digit[i][j] = '-';
                    else if(j==0 || j==4)
                        digit[i][j] = '|';
                }
            }
    }
}
//Delay Function
void delay(int time)
{
    int i;
    for(i=0;i<time*100000;i++);
}
