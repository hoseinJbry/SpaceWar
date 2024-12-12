/*

Name: <Space War>
Date: <1402/11/5>
programer: <Hossein Jabary>

*/
//////////////////////////////////////////////////////////////////////// includes
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <windows.h>
#include <conio.h>
#include <wchar.h>
#include <locale.h>
#include <math.h>
#include <time.h>
#pragma comment(lib, "winmm.lib")
#pragma warning(disable:4996)

//////////////////////////////////////////////////////////////////////// Defines & variables

#define red colorh,4
#define purple colorh,5
#define blue colorh,9
#define green colorh,10
#define cyan colorh,11
#define pink colorh,13
#define yellow colorh,14
#define reset colorh,15
#define bblue colorh, 22
#define bred colorh, 78
#define breset colorh, 63
#define color (SetConsoleTextAttribute)
#define sleep(x) (Sleep(1000*x))
#define randomize() (srand (time (0) ) )
#define random(x) (rand()%x)

HANDLE colorh = GetStdHandle(STD_OUTPUT_HANDLE);

struct information {
    char name[100];
    char pass[100];
    char email[100];
};
struct information human[100];

struct player {
    int spx, spy;
    int npx, npy;
    int ppx, ppy;
    int hp;
    char name[100];
    int dire = 0;
    int wins = 0;
    int bb = 0;
    int sup=0;

};
struct player player1;
struct player player2;

struct teleporter {
    int x;
    int y;
};
struct teleporter teleporter1;
struct teleporter teleporter2;

struct blackhole {
    int x;
    int y;
};
struct blackhole blackholes[100];

struct heart {
    int x;
    int y;
};
struct heart hearts[100];

struct bullet {
    int act = 0;
    int dire;
    int x, px, y, py;
    int sup = 0;

};
struct bullet bullets[3000];

struct bomb {
    int act = 0;
    int dire;
    int x, px, y, py;
    int pn;

};
struct bomb bombs[50];

struct sup {
    int x;
    int y;
};
struct sup super[50];

int humani=0;
FILE* f = NULL;

int mapchecker = 0;
const int mapi = 29, mapj = 81;


//////////////////////////////////////////////////////////////////////// prototypes

void gotoxy(int , int );
void cs();

void Title_screen();
void print_human(int , int );
void Title_screen_after();
void big_bang(int , int );
void star_wars_intro();
void print_backg();
int enterch();

void start_menu();
void sign_up();
void sign_in();

void Menu();
void cui();

void Start_game(char[][mapj]);
void position_setup();
void map1();
void map2();
void map3();

//////////////////////////////////////////////////////////////////////// main 

int main()
{
    randomize();
    
    int passcho = 1;

    passcho = enterch();

    if (passcho == 1)
    { 
    Title_screen();
    sleep(1);
    Title_screen_after();
    star_wars_intro();
    }
    else PlaySound(TEXT("starwarsmain.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

    start_menu();



}

//////////////////////////////////////////////////////////////////////// functions

void gotoxy(int x, int y) {
    COORD pos = { x, y };
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

void cs()
{
    system("cls");
}

int enterch()
{
    _setmode(_fileno(stdout), _O_TEXT);

    char ch;

    printf("\n\n\n\t\t\tEnter any key for playing the story(s for skip):");

    ch = getch();

    cs();
    if (ch == 's' || ch == 'S')
        return 0;
    else return 1;
}

void Title_screen() {
    
    _setmode(_fileno(stdout), _O_U16TEXT);
    sleep(0.5);
    wprintf(L"\n\n\n\n\n");

    color(cyan);
    wprintf(L"\t\t     ▄█▀▀▀▄█  ▀██▀▀█▄     █       ▄▄█▀▀▀▄█  ▀██▀▀▀▀█   ▀██ ▀██▀  ▀█▀     █       ▀██▀▀█▄ \n");

    color(red);
    sleep(0.5);
    wprintf(L"\t\t    ██▄▄  ▀   ██   ██    ███    ▄█▀     ▀    ██  ▄      ▀█▄ ▀█▄  ▄▀     ███       ██   ██ \n");

    color(green);
    sleep(0.5);
    wprintf(L"\t\t     ▀▀███▄   ██▄▄▄█▀   █  ██   ██           ██▀▀█       ██  ██  █     █  ██      ██▀▀█▀ \n");

    color(blue);
    sleep(0.5);
    wprintf(L"\t\t   ▄     ▀██  ██       ▄▀▀▀▀█▄  ▀█▄      ▄   ██           ███ ███     ▄▀▀▀▀█▄     ██   █▄ \n");

    color(purple);
    sleep(0.5);
    wprintf(L"\t\t   █▀▄▄▄▄█▀  ▄██▄     ▄█▄  ▄██▄  ▀▀█▄▄▄▄▀   ▄██▄▄▄▄▄█      █   █     ▄█▄  ▄██▄   ▄██▄  ▀█▀ \n");
    sleep(1);
    cs();


    for (int i = 1; i <= 4; i++)
    {
        wprintf(L"\n\n\n\n\n");
        color(red);
        wprintf(L"\t\t     ▄█▀▀▀▄█  ▀██▀▀█▄     █       ▄▄█▀▀▀▄█  ▀██▀▀▀▀█   ▀██ ▀██▀  ▀█▀     █       ▀██▀▀█▄ \n");
        color(cyan);
        wprintf(L"\t\t    ██▄▄  ▀   ██   ██    ███    ▄█▀     ▀    ██  ▄      ▀█▄ ▀█▄  ▄▀     ███       ██   ██ \n");
        color(blue);
        wprintf(L"\t\t     ▀▀███▄   ██▄▄▄█▀   █  ██   ██           ██▀▀█       ██  ██  █     █  ██      ██▀▀█▀ \n");
        color(green);
        wprintf(L"\t\t   ▄     ▀██  ██       ▄▀▀▀▀█▄  ▀█▄      ▄   ██           ███ ███     ▄▀▀▀▀█▄     ██   █▄ \n");
        color(yellow);
        wprintf(L"\t\t   █▀▄▄▄▄█▀  ▄██▄     ▄█▄  ▄██▄  ▀▀█▄▄▄▄▀   ▄██▄▄▄▄▄█      █   █     ▄█▄  ▄██▄   ▄██▄  ▀█▀ \n");
        sleep(0.5);
        cs();

        wprintf(L"\n\n\n\n\n");
        color(cyan);
        wprintf(L"\t\t     ▄█▀▀▀▄█  ▀██▀▀█▄     █       ▄▄█▀▀▀▄█  ▀██▀▀▀▀█   ▀██ ▀██▀  ▀█▀     █       ▀██▀▀█▄ \n");
        color(red);
        wprintf(L"\t\t    ██▄▄  ▀   ██   ██    ███    ▄█▀     ▀    ██  ▄      ▀█▄ ▀█▄  ▄▀     ███       ██   ██ \n");
        color(green);
        wprintf(L"\t\t     ▀▀███▄   ██▄▄▄█▀   █  ██   ██           ██▀▀█       ██  ██  █     █  ██      ██▀▀█▀ \n");
        color(blue);
        wprintf(L"\t\t   ▄     ▀██  ██       ▄▀▀▀▀█▄  ▀█▄      ▄   ██           ███ ███     ▄▀▀▀▀█▄     ██   █▄ \n");
        color(purple);
        wprintf(L"\t\t   █▀▄▄▄▄█▀  ▄██▄     ▄█▄  ▄██▄  ▀▀█▄▄▄▄▀   ▄██▄▄▄▄▄█      █   █     ▄█▄  ▄██▄   ▄██▄  ▀█▀ \n");
        sleep(0.5);
        cs();
    }


    color(reset);
}//1F426 bird

void Title_screen_after()
{
    int x=0, y=0;
    
    for (x = 0; x < 30; x++)
    {
        if (x % 2 == 0)
            y++;

        print_human(x, y);
        gotoxy(0, 0);
        Sleep(100);
        cs();
    }
    print_human(x, y);
    Sleep(1000);
    cs();
    gotoxy(x, y);
    wprintf(L"☻");

    gotoxy(x - 1, y-1);
    wprintf(L"\\");
    gotoxy(x, y + 1);
    wprintf(L"|");
    gotoxy(x + 1, y-1);
    wprintf(L"/");

    gotoxy(x - 1, y + 2);
    wprintf(L"/");
    gotoxy(x + 1, y + 2);
    wprintf(L"\\");

    gotoxy(x, y - 1);
    wprintf(L"♥");
    gotoxy(0, 0);
    int hx = x, hy = y - 1;
    Sleep(500);

    for (int i = 0; i < 26; i++)
    {
        gotoxy(hx, hy);
        wprintf(L" ");
        if (i < 13)
            hy--;
        else  hy++;

        gotoxy(++hx, hy);
        wprintf(L"♥");
        Sleep(100);

    }
    gotoxy(hx, hy);
     wprintf(L"♥");

     for (; x > 0; x--)
     {
         if (x % 2 == 0)
             y--;

         print_human(x, y);
         gotoxy(hx, hy);
         wprintf(L"♥");
         gotoxy(0, 0);
         Sleep(100);
         cs();
     }

     gotoxy(hx, hy);
     wprintf(L"♥");
     
     gotoxy(20, 5);
     wprintf(L"3 Second To Big Bang");

     for (int i = 0; i < 3; i++)
     {
         gotoxy(hx, hy);
         wprintf(L"♥");
         gotoxy(0, 0);
         Sleep(400);
         gotoxy(hx, hy);
         wprintf(L" ");
         gotoxy(0, 0);
         Sleep(200);
     }
     cs();

     gotoxy(20, 5);
     wprintf(L"2 Second To Big Bang");

     for (int i = 0; i < 5; i++)
     {
         gotoxy(hx, hy);
         wprintf(L"♥");
         gotoxy(0, 0);
         Sleep(300);
         gotoxy(hx, hy);
         wprintf(L" ");
         gotoxy(0, 0);
         Sleep(150);
     }
     cs();

     gotoxy(20, 5);
     wprintf(L"1 Second To Big Bang");

     for (int i = 0; i < 7; i++)
     {

         gotoxy(hx, hy);
         wprintf(L"♥");
         gotoxy(0, 0);
         Sleep(200);
         gotoxy(hx, hy);
         wprintf(L" ");
         gotoxy(0, 0);
         Sleep(100);
     }
     cs();

     big_bang(hx,hy);

}

void print_human(int x, int y)
{
    gotoxy(x, y);
    wprintf(L"☻");

    gotoxy(x - 1, y + 1);
    wprintf(L"/");
    gotoxy(x, y+1);
    wprintf(L"|");
    gotoxy(x+1, y + 1);
    wprintf(L"\\");

    gotoxy(x - 1, y + 2);
    wprintf(L"/");
    gotoxy(x + 1, y + 2);
    wprintf(L"\\");
}

void big_bang(int x,int y)
{


    cs();
    for (int i = 0; i < 15; i++)
    {
        cs();

        for(int j=0 ;j < i*2 ; j++)
        { 
        gotoxy(x - j, y-i);
        wprintf(L".");
        gotoxy(x + j, y-i);
        wprintf(L".");
        }

        for (int j = 0; j < i*2; j++)
        { 
        gotoxy(x - j, y+i);
        wprintf(L".");
        gotoxy(x + j, y+i);
        wprintf(L".");
        }

        for (int j = 0; j <=i; j++)
        {
            gotoxy(x - i*2, y - j);
            wprintf(L".");
           
            gotoxy(x + i*2, y - j);
            wprintf(L".");
        }

        for (int j = 0; j <=i; j++)
        {
            gotoxy(x - i*2, y + j);
            wprintf(L".");
   
            gotoxy(x + i*2, y + j);
            wprintf(L".");
        }



        sleep(0.2);
    }
} 

void star_wars_intro()
{
    cs();
    PlaySound(TEXT("starwarsmain.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    print_backg();
    sleep(5);

    int x = 50, y = 29;
    const char* word[30][21];
     word[0][0] = "A long time ago";
     word[1][0] = "in a galaxy far,";
     word[2][0] = "far away....";
     word[3][0] = "The emperor has ";
     word[4][0] = "started the royal ";
     word[5][0] = "games.";
     word[6][0] = "Two Jedi Knights ";
     word[7][0] = "against each other.";
     word[8][0] = "Only one winner.";
     word[9][0] = "Incredible prize for";
     word[10][0] = "the winner.";
     word[11][0] = "Who can really win?";
     word[12][0] = "Let's start the game";
    


     
     for (int i = 13; i < 30; i++)
         word[i][0] = " ";

     

     _setmode(_fileno(stdout), _O_TEXT);
     color(yellow);
     for (int i = 0; i < 30 ; i++)
     {
         y = y - i;
         for (int j = 0; j < i; j++)
         {
             gotoxy(x, y);
             printf("%21s", word[j][0]);
             y++;
         }
         sleep(0.5);
         
     }
     color(reset);

     sleep(5);


}

void print_backg()
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    for (int i = 0,j=0; i < 60; i++)
    {

        int r = random(117)+1;
        int cr = random(3);

        if (r < 50 || r >75)
        {

            gotoxy(r, j);
            if (cr == 0)
            {
                wprintf(L"☼");
                color(red);
            }

            else if (cr == 1)
            {
                wprintf(L"◦");
                color(green);
            }

            else 
            {
                wprintf(L"¤");
                color(blue);
            }

        }

        
        if (i % 2 == 0)
            j++;
    }
    
    color(reset);
    _setmode(_fileno(stdout), _O_TEXT);
}

void start_menu()
{
    cs();

    f = fopen("humans.txt", "r");
    humani = 0;
    while (!feof(f))
    {
        fscanf(f, "%s %s %s\n", human[humani].name, human[humani].pass, human[humani].email);
        humani++;
    }
    fclose(f);

    print_backg();

    gotoxy(54, 15);
    color(purple);
    printf("Space ");
    color(cyan);
    printf("War ");
    color(reset);


    char ch='a';
    int c = 1;

    
    do{

        if ((ch == 'W' || ch == 'w') && c > 1)
            c--;
        else if ((ch == 'S' || ch == 's') && c < 3)
            c++;

        if (c == 1)
        {
            gotoxy(55, 16);
            color(red);
            printf("Sign up");
            color(reset);
            gotoxy(55, 17);
            printf("Sign in");
            gotoxy(56, 18);
            printf("Exit");
        }
        else if (c == 2)
        {
            gotoxy(55, 16);
            printf("Sign up");
            gotoxy(55, 17);
            color(red);
            printf("Sign in");
            color(reset);
            gotoxy(56, 18);
            printf("Exit");
        }
        else
        {
            gotoxy(55, 16);
            printf("Sign up");
            gotoxy(55, 17);
            printf("Sign in");
            gotoxy(56, 18);
            color(red);
            printf("Exit");
            color(reset);
        }
        

    } while ((ch = getch()) != 13);


    if (c == 1)
        sign_up();
    else if (c == 2)
        sign_in();
    else
        exit(1);
    

}
void sign_up()
{
    cs();
    int i = humani;
    int bol = 1;
    
    char file[1000];

    char s[20];
    
    

    cs();
    while(1)
    {
        f = fopen("humans.txt", "r");
        printf("Enter you name:");
        scanf("%s", s);

        while(fgets(file, sizeof(file), f))
        { 

            if (strstr(file, s) != NULL)
            {
                cs();
                printf("Name already exist\n");
                bol = 0;
                break;
            }
            else
                bol = 1;
            
        }
        fclose(f);
        if (bol == 0)
            continue;

        strcpy(human[i].name, s);
        break;
     }
    cs();

    char pas[20],pas2[20];
    while(1)
    {
    
        printf("Enter you password (8 char at least):");
        scanf("%s", pas);

        if (strlen(pas) < 8)
        { 
            cs();
            printf("Yout password is lower than 8 char.\n");
            continue;
        }
        cs();
        printf("Enter your password again:");
        scanf("%s", pas2);

        if (strcmp(pas, pas2) != 0)
        {
            cs();
            printf("Your passwords are not equal.\n");
            continue;
        }
        strcpy(human[i].pass, pas);
        break;
    }
    cs();
    printf("Enter you email(with @gmail.com):");
    scanf("%s", s);
    strcpy(human[i].email, s);

    f = fopen("humans.txt", "a");
    fprintf(f, "%s %s %s\n", human[i].name, human[i].pass, human[i].email);
    fclose(f);

    humani++;
    start_menu();
}
void sign_in()
{
    char pn[100],ps[100],pe[100];
    char s1[100], s2[100], s3[100];
    char passch='a';
    int passi = 0 , idc=1;
    int check = 0;
    int i = 0;
while(1)
{ 
    check = 0;
    cs();
    do{

        if (idc > 1 && (passch == 'w' || passch == 'W'))
            idc--;

        else if (idc < 2 && (passch == 's' || passch == 'S'))
            idc++;

        if (idc == 1)
        {
            cs();
            color(red);
            printf("(1) Sign in\n");
            color(reset);
            printf("(2) Forget Password");
        }
        else
        {
            cs();
            printf("(1) Sign in\n");
            color(red);
            printf("(2) Forget Password");
            color(reset);
        }


    } while ((passch = getch()) != 13);
    int name1=0;
    cs();

    if(idc == 1)
    while (1)
    {
        name1 = 0;
        f = fopen("humans.txt", "r");
        printf("enter your name:");
        scanf("%s", pn);

    do {
        fscanf(f, "%s %s %s\n", s1, s2, s3);

        if (strcmp(pn, s1) == 0)
        {
            while (1)
            {
                printf("Enter your password:");
                passi = 0;
                
                while ((passch = getch()) != 13)
                {
                    if (passch != 8)
                    {
                        printf("*");
                        ps[passi] = passch;
                        passi++;
                    }
                }
                ps[passi] = NULL;

                if (strcmp(ps, s2) == 0)
                {
                    strcpy(player1.name, human[name1].name);
                    Menu();
                }
                else
                {
                    cs();
                    printf("password is wrong try again.\n");
                }

            }
            
        }
        ++name1;
    } while (!feof(f));

    cs();
    printf("name does not exist try again.\n");
    fclose(f);

    }  

    
    else
    {
         i = 0;
        while (1)
        {
            f = fopen("humans.txt", "r");
            printf("enter your name:");
            scanf("%s", pn);

            do {
                fscanf(f, "%s %s %s\n", s1, s2, s3);

                if (strcmp(pn, s1) == 0)
                {
                    while(1)
                    { 
                        
                        printf("Enter your Email:");
                        scanf("%s", pe);
    
                        if (strcmp(pe, s3) == 0)
                        {
                            char pas[20], pas2[20];
                            while (1)
                        {

                            printf("Enter you password (8 char at least):");
                            scanf("%s", pas);

                            if (strlen(pas) < 8)
                            {
                                cs();
                                printf("Yout password is lower than 8 char.\n");
                                continue;
                            }
                            cs();
                            printf("Enter your password again:");
                            scanf("%s", pas2);

                            if (strcmp(pas, pas2) != 0)
                            {
                                cs();
                                printf("Your passwords are not equal.\n");
                                continue;
                            }
                            strcpy(human[i].pass, pas);
                            
                            i = humani;

                            fclose(f);
                            f = fopen("humans.txt", "w");
                            for (int j = 0; j <=i; j++)
                                fprintf(f, "%s %s %s\n", human[j].name, human[j].pass, human[j].email);
                            
                            check = 1;
                            fclose(f);
                            break;
                        }
                            
                        }
                        else
                        {
                            cs();
                           printf("Email is wrong try again.\n");
                        }
                        if (check)
                            break;
                    }
                }
                i++;
                if (check)
                    break;
            } while (!feof(f));

            cs();
            printf("name does not exist try again.\n");
            fclose(f);
            if (check)
                break;

        }
    }

}
}

void Menu()
{
    while (1)
    {
        cs();
        print_backg();
        char ch='.';
        int c=1;
        gotoxy(55, 15);
        color(red);
        printf("*");
        color(blue);
        printf("M");
        color(green);
        printf("E");
        color(pink);
        printf("N");
        color(cyan);
        printf("U");
        color(red);
        printf("*");
        color(reset);

        do {

            if ((ch == 'W' || ch == 'w') && c > 1)
                c--;
            else if ((ch == 'S' || ch == 's') && c < 4)
                c++;

            if (c == 1)
            {
                gotoxy(53, 16);
                color(red);
                printf("Start Game");
                color(reset);
                gotoxy(50, 17);
                printf("Change User Info");
                gotoxy(55, 18);
                printf("History");
                gotoxy(49, 19);
                printf("Return to Start_Menu");
            }
            else if (c == 2)
            {
                gotoxy(53, 16);
                printf("Start Game");
                gotoxy(50, 17);
                color(red);
                printf("Change User Info");
                color(reset);
                gotoxy(55, 18);
                printf("History");
                gotoxy(49, 19);
                printf("Return to Start_Menu");
            }
            else if (c == 3)
            {
                gotoxy(53, 16);
                printf("Start Game");
                gotoxy(50, 17);
                printf("Change User Info");
                gotoxy(55, 18);
                color(red);
                printf("History");
                color(reset);
                gotoxy(49, 19);
                printf("Return to Start_Menu");
            }
            else 
            {
                gotoxy(53, 16);
                printf("Start Game");
                gotoxy(50, 17);
                printf("Change User Info");
                gotoxy(55, 18);
                printf("History");
                gotoxy(49, 19);
                color(red);
                printf("Return to Start_Menu");
                color(reset);
            }


        } while ((ch = getch()) != 13);


        if (c == 1)
        {
            cs();
            int name2;
            char pn[100], ps[100], pe[100];
            char s1[100], s2[100], s3[100];
            char passch = 'a';
            int passi = 0;

            while (1)
            {
                
                name2 = 0;
                f = fopen("humans.txt", "r");
                printf("enter your name:");

                
                scanf("%s", pn);
                if (strcmp(pn,player1.name)==0)
                {
                    cs();
                    printf("Player %s has already signed in.Try another one...\n",pn);
                    continue;
                }
                
                    

                do {
                    fscanf(f, "%s %s %s\n", s1, s2, s3);

                    if (strcmp(pn, s1) == 0)
                    {
                        while (1)
                        {
                            printf("Enter your password:");
                            passi = 0;

                            while ((passch = getch()) != 13)
                            {
                                if (passch != 8)
                                {
                                    printf("*");
                                    ps[passi] = passch;
                                    passi++;
                                }
                            }
                            ps[passi] = NULL;

                            if (strcmp(ps, s2) == 0)
                            {
                                strcpy(player2.name, human[name2].name);
                                cs();
                                map1();
                            }
                            else
                            {
                                cs();
                                printf("password is wrong try again.\n");
                            }

                        }

                    }
                    ++name2;
                } while (!feof(f));

                cs();
                printf("name does not exist try again.\n");
                fclose(f);

            }
        }
        else if (c == 2)
        {
            cs();
            cui();
        }
        else if (c == 3)
        {
            cs();
            printf("%s,%d", player1.name, player1.wins);
            printf("%s,%d", player2.name, player2.wins);
            getch();
        }
        else
        {
            start_menu();
        }

    }
}

void cui()
{
    cs();
    char pn[100], ps[100], pe[100];
    char s1[100], s2[100], s3[100];
    int i = 0;
    char passch = 'a';
    int passi = 0, idc = 1;

    while(1)
    {
        
        i = 0;
        f = fopen("humans.txt", "r");
        printf("enter your name:");
        
        scanf("%s", pn);
            do {
                fscanf(f, "%s %s %s\n", s1, s2, s3);
                
                if (strcmp(pn, s1) == 0)
                {
                    while (1)
                    {
                        printf("Enter your password:");
                        passi = 0;

                        while ((passch = getch()) != 13)
                        {
                            if (passch != 8)
                            {
                                printf("*");
                                ps[passi] = passch;
                                passi++;
                            }
                        }
                        ps[passi] = NULL;

                        if (strcmp(ps, s2) == 0)
                        {
                            cs();
                            do {

                                if (idc > 1 && (passch == 'w' || passch == 'W'))
                                    idc--;

                                else if (idc < 3 && (passch == 's' || passch == 'S'))
                                    idc++;

                                if (idc == 1)
                                {
                                    cs();
                                    color(red);
                                    printf("(1) Change Name\n");
                                    color(reset);
                                    printf("(2) Change Password\n");
                                    printf("(3) Change Email");

                                }
                                else if (idc == 2)
                                {
                                    cs();
                                    printf("(1) Change Name\n");
                                    color(red);
                                    printf("(2) Change Password\n");
                                    color(reset);
                                    printf("(3) Change Email");
                                }
                                else
                                {
                                    cs();
                                    printf("(1) Change Name\n");
                                    printf("(2) Change Password\n");
                                    color(red);
                                    printf("(3) Change Email");
                                    color(reset);
                                }


                            } while ((passch = getch()) != 13);

                            cs();

                            if (idc == 1)
                            {
                                char name[20];
                                printf("Enter you New name:");
                                scanf("%s", name);
                                strcpy(human[i].name, name);

                                fclose(f);
                                f = fopen("humans.txt", "w");
                                for (int j = 0; j <= humani; j++)
                                    fprintf(f, "%s %s %s\n", human[j].name, human[j].pass, human[j].email);

                                fclose(f);
                                Menu();
                            }
                            else if (idc == 2)
                            {
                                char pas[20], pas2[20];
                                while (1)
                                {

                                    printf("Enter you New password (8 char at least):");
                                    scanf("%s", pas);

                                    if (strlen(pas) < 8)
                                    {
                                        cs();
                                        printf("Yout password is lower than 8 char.\n");
                                        continue;
                                    }
                                    cs();
                                    printf("Enter your New password again:");
                                    scanf("%s", pas2);

                                    if (strcmp(pas, pas2) != 0)
                                    {
                                        cs();
                                        printf("Your passwords are not equal.\n");
                                        continue;
                                    }
                                    strcpy(human[i].pass, pas);

                                    fclose(f);
                                    f = fopen("humans.txt", "w");
                                    for (int j = 0; j <= humani; j++)
                                        fprintf(f, "%s %s %s\n", human[j].name, human[j].pass, human[j].email);

                                    fclose(f);
                                    Menu();
                                }

                            }
                            else
                            {
                                char email[20];
                                printf("Enter you New email:");
                                scanf("%s", email);
                                strcpy(human[i].email, email);

                                fclose(f);
                                f = fopen("humans.txt", "w");
                                for (int j = 0; j <= humani; j++)
                                    fprintf(f, "%s %s %s\n", human[j].name, human[j].pass, human[j].email);

                                fclose(f);
                                Menu();

                            }

                        }
                        else
                        {
                            cs();
                            printf("password is wrong try again.\n");
                        }
                    }
                    
                }
                i++;
            } while (!feof(f));

                cs();
                printf("name does not exist try again.\n");
                fclose(f);
        

    }
}

void Start_game(char wallmap[][mapj])
{
    cs();
    do {
        cs();
        printf("Enter player 1 Hp(1 to 100):");
        scanf("%d", &player1.hp);
    } while (player1.hp >100 || player1.hp <1);
  
    do {
        cs();
        printf("Enter player 2 Hp(1 to 100):");
        scanf("%d", &player2.hp);
    } while (player2.hp > 100 || player2.hp < 1);;
    cs();

    int gameover = 0;
    char mch1 = '0', mch2 = '0';
    int tp_c = 0;
    int heart_i = 0;
    int black_hole_i = 0, hrx, hry;
    int bullet_i=0;
    int bomb_i = 0;
    int super_i = 0;
    
    position_setup();
    
    _setmode(_fileno(stdout), _O_U16TEXT);

    for(int i=0 ; i<mapi ; i++)
        for (int j = 0; j < mapj; j++)
        {
            gotoxy(j, i);

            if (wallmap[i][j] == '|')
                wprintf(L"█");

            else if (wallmap[i][j] == 'o')
            {
                blackholes[black_hole_i].x = j;
                blackholes[black_hole_i].y = i;

                wprintf(L"♻");
                black_hole_i++;
            }


            else if (wallmap[i][j] == 't')
            {
                if (tp_c == 0)
                {
                    tp_c = 1;
                    teleporter1.x = j;
                    teleporter1.y = i;
                }
                else
                {
                    teleporter2.x = j;
                    teleporter2.y = i;
                }
                color(purple);
                wprintf(L"ↈ");
                color(reset);
            }

            else if (wallmap[i][j] == 'm')
                wprintf(L"║");

            else if (wallmap[i][j] == 'h')
            {
                hearts[heart_i].x = j;
                hearts[heart_i].y = i;

                wprintf(L"❤");
                heart_i++;
            }

            else if (wallmap[i][j] == 'b')
            {
                bombs[bomb_i].x = j;
                bombs[bomb_i].y = i;
                color(purple);
                wprintf(L"ర");
                color(reset);
                bomb_i++;
            }

            else if (wallmap[i][j] == 'e')
            {
                super[super_i].x = j;
                super[super_i].y = i;
                color(cyan);
                wprintf(L"ɸ");
                color(reset);
                super_i++;
            }

            else if (wallmap[i][j] == 's')
            {
                if (j == player1.spx)
                {
                    color(red);
                    wprintf(L"ᗚ");
                    color(reset);
                }
                else if (j == player2.spx)
                {
                    color(blue);
                    wprintf(L"ᗛ");
                    color(reset);
                }
            }


        }


    _setmode(_fileno(stdout), _O_TEXT);

    gotoxy(0, 25);
    printf("%s hp is : %d",player1.name,player1.hp);

    gotoxy(0, 26);
    printf("%s hp is : %d",player2.name,player2.hp);
    _setmode(_fileno(stdout), _O_U16TEXT);

 while (!gameover)
 {

        if (_kbhit())
        {
            mch1 = getch();

            switch (mch1)
            {
            case 'w': case'W':

                if (wallmap[player1.npy - 1][player1.npx] != '|' && wallmap[player1.npy - 1][player1.npx] != 'm')
                {
                    
                    player1.ppy = player1.npy;
                    player1.ppx = player1.npx;
                    --player1.npy;

                    if (player1.npx == teleporter1.x && player1.npy == teleporter1.y)
                    {
                        player1.npy = teleporter2.y;
                        player1.npx = teleporter2.x;
                        --player1.npy;
                    }
                    else if(player1.npx == teleporter2.x && player1.npy == teleporter2.y)
                    {
                        player1.npy = teleporter1.y;
                        player1.npx = teleporter1.x;
                        --player1.npy;
                    }

                    for (int bi = 0; bi < black_hole_i; bi++)
                    {
                        if(player1.npx == blackholes[bi].x && player1.npy == blackholes[bi].y)
                        {
                            player1.npy = player1.spy;
                            player1.npx = player1.spx;
                            player1.hp--;
                        }
                    }


                    for (int hi = 0; hi < heart_i; hi++)
                    {
                        if (player1.npx ==hearts[hi].x && player1.npy == hearts[hi].y)
                        {

                            player1.hp+=5;
                            while (1)
                            {
                                hrx = random(81);
                                hry = random(29);
                                if (wallmap[hry][hrx] == ' ')
                                {
                                    gotoxy(hrx, hry);
                                    wprintf(L"❤");
                                    hearts[hi].x = hrx;
                                    hearts[hi].y = hry;
                                    break;
                                }
                            }
                        }
                    }

                    for (int bi = 0; bi < bomb_i; bi++)
                    {
                        if (player1.npx == bombs[bi].x && player1.npy == bombs[bi].y)
                        {

                            player1.bb = 1;
                            while (1)
                            {
                                hrx = random(81);
                                hry = random(29);
                                if (wallmap[hry][hrx] == ' ')
                                {
                                    gotoxy(hrx, hry);
                                    color(purple);
                                    wprintf(L"ర");
                                    color(reset);
                                    bombs[bi].x = hrx;
                                    bombs[bi].y = hry;
                                    break;
                                }
                            }
                        }
                    }

                    for (int si = 0; si < super_i; si++)
                    {
                        if (player1.npx == super[si].x && player1.npy == super[si].y)
                        {

                            player1.sup += 5;
                            while (1)
                            {
                                hrx = random(81);
                                hry = random(29);
                                if (wallmap[hry][hrx] == ' ')
                                {
                                    gotoxy(hrx, hry);
                                    color(cyan);
                                    wprintf(L"ɸ");
                                    color(reset);
                                    super[si].x = hrx;
                                    super[si].y = hry;
                                    break;
                                }
                            }
                        }
                    }

                    gotoxy(player1.ppx, player1.ppy);
                    wprintf(L" ");

                    gotoxy(player1.npx, player1.npy);
                    color(red);
                    wprintf(L"ᗗ");
                    color(reset);
                    player1.dire = -2;
                }
                break;

            case 's': case'S':

                if (wallmap[player1.npy + 1][player1.npx] != '|' && wallmap[player1.npy + 1][player1.npx] != 'm')
                {
                    player1.ppy = player1.npy;
                    player1.ppx = player1.npx;
                    ++player1.npy;

                    if (player1.npx == teleporter1.x && player1.npy == teleporter1.y)
                    {
                        player1.npy = teleporter2.y;
                        player1.npx = teleporter2.x;
                        ++player1.npy;
                    }
                    else if (player1.npx == teleporter2.x && player1.npy == teleporter2.y)
                    {
                        player1.npy = teleporter1.y;
                        player1.npx = teleporter1.x;
                        ++player1.npy;
                    }

                    for (int bi = 0; bi < black_hole_i; bi++)
                    {
                        if (player1.npx == blackholes[bi].x && player1.npy == blackholes[bi].y)
                        {
                            player1.npy = player1.spy;
                            player1.npx = player1.spx;
                            player1.hp--;
                        }
                    }

                    for (int hi = 0; hi < heart_i; hi++)
                    {
                        if (player1.npx == hearts[hi].x && player1.npy == hearts[hi].y)
                        {

                            player1.hp += 5;
                            while (1)
                            {
                                hrx = random(81);
                                hry = random(29);
                                if (wallmap[hry][hrx] == ' ')
                                {
                                    gotoxy(hrx, hry);
                                    wprintf(L"❤");
                                    hearts[hi].x = hrx;
                                    hearts[hi].y = hry;
                                    break;
                                }
                            }
                        }
                    }

                    for (int bi = 0; bi < bomb_i; bi++)
                    {
                        if (player1.npx == bombs[bi].x && player1.npy == bombs[bi].y)
                        {

                            player1.bb = 1;
                            while (1)
                            {
                                hrx = random(81);
                                hry = random(29);
                                if (wallmap[hry][hrx] == ' ')
                                {
                                    gotoxy(hrx, hry);
                                    color(purple);
                                    wprintf(L"ర");
                                    color(reset);
                                    bombs[bi].x = hrx;
                                    bombs[bi].y = hry;
                                    break;
                                }
                            }
                        }
                    }

                    for (int si = 0; si < super_i; si++)
                    {
                        if (player1.npx == super[si].x && player1.npy == super[si].y)
                        {

                            player1.sup += 5;
                            while (1)
                            {
                                hrx = random(81);
                                hry = random(29);
                                if (wallmap[hry][hrx] == ' ')
                                {
                                    gotoxy(hrx, hry);
                                    color(cyan);
                                    wprintf(L"ɸ");
                                    color(reset);
                                    super[si].x = hrx;
                                    super[si].y = hry;
                                    break;
                                }
                            }
                        }
                    }

                    gotoxy(player1.ppx, player1.ppy);
                    wprintf(L" ");

                    gotoxy(player1.npx, player1.npy);
                    color(red);
                    wprintf(L"ᗖ");
                    color(reset);
                    player1.dire = 2;
                }
                break;

            case 'a': case'A':

                if (wallmap[player1.npy][player1.npx - 1] != '|' && wallmap[player1.npy][player1.npx - 1] != 'm')
                {
                    player1.ppx = player1.npx;
                    player1.ppy = player1.npy;
                    --player1.npx;

                    if (player1.npx == teleporter1.x && player1.npy == teleporter1.y)
                    {
                        player1.npy = teleporter2.y;
                        player1.npx = teleporter2.x;
                        --player1.npx;
                    }
                    else if (player1.npx == teleporter2.x && player1.npy == teleporter2.y)
                    {
                        player1.npy = teleporter1.y;
                        player1.npx = teleporter1.x;
                        --player1.npx;
                    }

                    for (int bi = 0; bi < black_hole_i; bi++)
                    {
                        if (player1.npx == blackholes[bi].x && player1.npy == blackholes[bi].y)
                        {
                            player1.npy = player1.spy;
                            player1.npx = player1.spx;
                            player1.hp--;
                        }
                    }

                    for (int bi = 0; bi < black_hole_i; bi++)
                    {
                        if (player1.npx == blackholes[bi].x && player1.npy == blackholes[bi].y)
                        {
                            player1.npy = player1.spy;
                            player1.npx = player1.spx;
                            player1.hp--;
                        }
                    }

                    for (int hi = 0; hi < heart_i; hi++)
                    {
                        if (player1.npx == hearts[hi].x && player1.npy == hearts[hi].y)
                        {

                            player1.hp += 5;
                            while (1)
                            {
                                hrx = random(81);
                                hry = random(29);
                                if (wallmap[hry][hrx] == ' ')
                                {
                                    gotoxy(hrx, hry);
                                    wprintf(L"❤");
                                    hearts[hi].x = hrx;
                                    hearts[hi].y = hry;
                                    break;
                                }
                            }
                        }
                    }

                    for (int bi = 0; bi < bomb_i; bi++)
                    {
                        if (player1.npx == bombs[bi].x && player1.npy == bombs[bi].y)
                        {

                            player1.bb = 1;
                            while (1)
                            {
                                hrx = random(81);
                                hry = random(29);
                                if (wallmap[hry][hrx] == ' ')
                                {
                                    gotoxy(hrx, hry);
                                    color(purple);
                                    wprintf(L"ర");
                                    color(reset);
                                    bombs[bi].x = hrx;
                                    bombs[bi].y = hry;
                                    break;
                                }
                            }
                        }
                    }

                    for (int si = 0; si < super_i; si++)
                    {
                        if (player1.npx == super[si].x && player1.npy == super[si].y)
                        {

                            player1.sup += 5;
                            while (1)
                            {
                                hrx = random(81);
                                hry = random(29);
                                if (wallmap[hry][hrx] == ' ')
                                {
                                    gotoxy(hrx, hry);
                                    color(cyan);
                                    wprintf(L"ɸ");
                                    color(reset);
                                    super[si].x = hrx;
                                    super[si].y = hry;
                                    break;
                                }
                            }
                        }
                    }

                    gotoxy(player1.ppx, player1.ppy);
                    wprintf(L" ");

                    gotoxy(player1.npx, player1.npy);
                    color(red);
                    wprintf(L"ᗛ");
                    color(reset);
                    player1.dire = -1;
                }
                break;

            case 'd': case'D':

                if (wallmap[player1.npy][player1.npx + 1] != '|' && wallmap[player1.npy][player1.npx + 1] != 'm')
                {
                    player1.ppx = player1.npx;
                    player1.ppy = player1.npy;
                    ++player1.npx;

                    if (player1.npx == teleporter1.x && player1.npy == teleporter1.y)
                    {
                        player1.npy = teleporter2.y;
                        player1.npx = teleporter2.x;
                        ++player1.npx;
                    }
                    else if (player1.npx == teleporter2.x && player1.npy == teleporter2.y)
                    {
                        player1.npy = teleporter1.y;
                        player1.npx = teleporter1.x;
                        ++player1.npx;
                    }

                    for (int bi = 0; bi < black_hole_i; bi++)
                    {
                        if (player1.npx == blackholes[bi].x && player1.npy == blackholes[bi].y)
                        {
                            player1.npy = player1.spy;
                            player1.npx = player1.spx;
                            player1.hp--;
                        }
                    }
                    
                    for (int hi = 0; hi < heart_i; hi++)
                    {
                        if (player1.npx == hearts[hi].x && player1.npy == hearts[hi].y)
                        {

                            player1.hp += 5;
                            while (1)
                            {
                                hrx = random(81);
                                hry = random(29);
                                if (wallmap[hry][hrx] == ' ')
                                {
                                    gotoxy(hrx, hry);
                                    wprintf(L"❤");
                                    hearts[hi].x = hrx;
                                    hearts[hi].y = hry;
                                    break;
                                }
                            }
                        }
                    }

                    for (int bi = 0; bi < bomb_i; bi++)
                    {
                        if (player1.npx == bombs[bi].x && player1.npy == bombs[bi].y)
                        {

                            player1.bb = 1;
                            while (1)
                            {
                                hrx = random(81);
                                hry = random(29);
                                if (wallmap[hry][hrx] == ' ')
                                {
                                    gotoxy(hrx, hry);
                                    color(purple);
                                    wprintf(L"ర");
                                    color(reset);
                                    bombs[bi].x = hrx;
                                    bombs[bi].y = hry;
                                    break;
                                }
                            }
                        }
                    }

                    for (int si = 0; si < super_i; si++)
                    {
                        if (player1.npx == super[si].x && player1.npy == super[si].y)
                        {

                            player1.sup += 5;
                            while (1)
                            {
                                hrx = random(81);
                                hry = random(29);
                                if (wallmap[hry][hrx] == ' ')
                                {
                                    gotoxy(hrx, hry);
                                    color(cyan);
                                    wprintf(L"ɸ");
                                    color(reset);
                                    super[si].x = hrx;
                                    super[si].y = hry;
                                    break;
                                }
                            }
                        }
                    }

                    gotoxy(player1.ppx, player1.ppy);
                    wprintf(L" ");

                    gotoxy(player1.npx, player1.npy);
                    color(red);
                    wprintf(L"ᗚ");
                    color(reset);
                    player1.dire = 1;
                }
                break;

            case 'i': case'I':

                if (wallmap[player2.npy - 1][player2.npx] != '|' && wallmap[player2.npy - 1][player2.npx] != 'm')
                {
                    player2.ppy = player2.npy;
                    player2.ppx = player2.npx;
                    --player2.npy;

                    if (player2.npx == teleporter1.x && player2.npy == teleporter1.y)
                    {
                        player2.npy = teleporter2.y;
                        player2.npx = teleporter2.x;
                        --player2.npy;
                    }
                    else if (player2.npx == teleporter2.x && player2.npy == teleporter2.y)
                    {
                        player2.npy = teleporter1.y;
                        player2.npx = teleporter1.x;
                        --player2.npy;
                    }

                    for (int bi = 0; bi < black_hole_i; bi++)
                    {
                        if (player2.npx == blackholes[bi].x && player2.npy == blackholes[bi].y)
                        {
                            player2.npy = player2.spy;
                            player2.npx = player2.spx;
                            player2.hp--;
                        }
                    }

                    for (int hi = 0; hi < heart_i; hi++)
                    {
                        if (player2.npx == hearts[hi].x && player2.npy == hearts[hi].y)
                        {

                            player2.hp += 5;

                            while (1)
                            {
                                hrx = random(81);
                                hry = random(29);
                                if (wallmap[hry][hrx] == ' ')
                                {
                                    gotoxy(hrx, hry);                                    
                                    wprintf(L"❤");                                   
                                    hearts[hi].x = hrx;
                                    hearts[hi].y = hry;
                                    break;
                                }
                            }
                        }
                    }

                    for (int bi = 0; bi < bomb_i; bi++)
                    {
                        if (player2.npx == bombs[bi].x && player2.npy == bombs[bi].y)
                        {

                            player2.bb = 1;

                            while (1)
                            {
                                hrx = random(81);
                                hry = random(29);
                                if (wallmap[hry][hrx] == ' ')
                                {
                                    gotoxy(hrx, hry);
                                    color(purple);
                                    wprintf(L"ర");
                                    color(reset);
                                    bombs[bi].x = hrx;
                                    bombs[bi].y = hry;
                                    break;
                                }
                            }
                        }
                    }

                    for (int si = 0; si < super_i; si++)
                    {
                        if (player2.npx == super[si].x && player2.npy == super[si].y)
                        {

                            player2.sup += 5;
                            while (1)
                            {
                                hrx = random(81);
                                hry = random(29);
                                if (wallmap[hry][hrx] == ' ')
                                {
                                    gotoxy(hrx, hry);
                                    color(cyan);
                                    wprintf(L"ɸ");
                                    color(reset);
                                    super[si].x = hrx;
                                    super[si].y = hry;
                                    break;
                                }
                            }
                        }
                    }

                    gotoxy(player2.ppx, player2.ppy);
                    wprintf(L" ");

                    gotoxy(player2.npx, player2.npy);
                    color(blue);
                    wprintf(L"ᗗ");
                    color(reset);
                    player2.dire = -2;
                }
                break;

            case 'k': case'K':

                if (wallmap[player2.npy + 1][player2.npx] != '|' && wallmap[player2.npy + 1][player2.npx] != 'm')
                {
                    player2.ppy = player2.npy;
                    player2.ppx = player2.npx;
                    ++player2.npy;

                    if (player2.npx == teleporter1.x && player2.npy == teleporter1.y)
                    {
                        player2.npy = teleporter2.y;
                        player2.npx = teleporter2.x;
                        ++player2.npy;
                    }
                    else if (player2.npx == teleporter2.x && player2.npy == teleporter2.y)
                    {
                        player2.npy = teleporter1.y;
                        player2.npx = teleporter1.x;
                        ++player2.npy;
                    }

                    for (int bi = 0; bi < black_hole_i; bi++)
                    {
                        if (player2.npx == blackholes[bi].x && player2.npy == blackholes[bi].y)
                        {
                            player2.npy = player2.spy;
                            player2.npx = player2.spx;
                            player2.hp--;
                        }
                    }

                    for (int hi = 0; hi < heart_i; hi++)
                    {
                        if (player2.npx == hearts[hi].x && player2.npy == hearts[hi].y)
                        {

                            player2.hp += 5;
                            while (1)
                            {
                                hrx = random(81);
                                hry = random(29);
                                if (wallmap[hry][hrx] == ' ')
                                {
                                    gotoxy(hrx, hry);
                                    wprintf(L"❤");
                                    hearts[hi].x = hrx;
                                    hearts[hi].y = hry;
                                    break;
                                }
                            }
                        }
                    }

                    for (int hi = 0; hi < heart_i; hi++)
                    {
                        if (player2.npx == bombs[hi].x && player2.npy == bombs[hi].y)
                        {

                            player2.hp += 5;

                            while (1)
                            {
                                hrx = random(81);
                                hry = random(29);
                                if (wallmap[hry][hrx] == ' ')
                                {
                                    gotoxy(hrx, hry);
                                    color(purple);
                                    wprintf(L"ర");
                                    color(reset);
                                    bombs[hi].x = hrx;
                                    bombs[hi].y = hry;
                                    break;
                                }
                            }
                        }
                    }

                    for (int si = 0; si < super_i; si++)
                    {
                        if (player2.npx == super[si].x && player2.npy == super[si].y)
                        {

                            player2.sup += 5;
                            while (1)
                            {
                                hrx = random(81);
                                hry = random(29);
                                if (wallmap[hry][hrx] == ' ')
                                {
                                    gotoxy(hrx, hry);
                                    color(cyan);
                                    wprintf(L"ɸ");
                                    color(reset);
                                    super[si].x = hrx;
                                    super[si].y = hry;
                                    break;
                                }
                            }
                        }
                    }

                    gotoxy(player2.ppx, player2.ppy);
                    wprintf(L" ");

                    gotoxy(player2.npx, player2.npy);
                    color(blue);
                    wprintf(L"ᗖ");
                    color(reset);
                    player2.dire = 2;
                }
                break;

            case 'j': case'J':

                if (wallmap[player2.npy][player2.npx - 1] != '|' && wallmap[player2.npy][player2.npx - 1] != 'm')
                {
                    player2.ppx = player2.npx;
                    player2.ppy = player2.npy;
                    --player2.npx;

                    if (player2.npx == teleporter1.x && player2.npy == teleporter1.y)
                    {
                        player2.npy = teleporter2.y;
                        player2.npx = teleporter2.x;
                        --player2.npx;
                    }
                    else if (player2.npx == teleporter2.x && player2.npy == teleporter2.y)
                    {
                        player2.npy = teleporter1.y;
                        player2.npx = teleporter1.x;
                        --player2.npx;
                    }

                    for (int bi = 0; bi < black_hole_i; bi++)
                    {
                        if (player2.npx == blackholes[bi].x && player2.npy == blackholes[bi].y)
                        {
                            player2.npy = player2.spy;
                            player2.npx = player2.spx;
                            player2.hp--;
                        }
                    }

                    for (int hi = 0; hi < heart_i; hi++)
                    {
                        if (player2.npx == hearts[hi].x && player2.npy == hearts[hi].y)
                        {

                            player2.hp += 5;
                            while (1)
                            {
                                hrx = random(81);
                                hry = random(29);
                                if (wallmap[hry][hrx] == ' ')
                                {
                                    gotoxy(hrx, hry);
                                    wprintf(L"❤");
                                    hearts[hi].x = hrx;
                                    hearts[hi].y = hry;
                                    break;
                                }
                            }
                        }
                    }

                    for (int hi = 0; hi < heart_i; hi++)
                    {
                        if (player2.npx == bombs[hi].x && player2.npy == bombs[hi].y)
                        {

                            player2.hp += 5;

                            while (1)
                            {
                                hrx = random(81);
                                hry = random(29);
                                if (wallmap[hry][hrx] == ' ')
                                {
                                    gotoxy(hrx, hry);
                                    color(purple);
                                    wprintf(L"ర");
                                    color(reset);
                                    bombs[hi].x = hrx;
                                    bombs[hi].y = hry;
                                    break;
                                }
                            }
                        }
                    }

                    for (int si = 0; si < super_i; si++)
                    {
                        if (player2.npx == super[si].x && player2.npy == super[si].y)
                        {

                            player2.sup += 5;
                            while (1)
                            {
                                hrx = random(81);
                                hry = random(29);
                                if (wallmap[hry][hrx] == ' ')
                                {
                                    gotoxy(hrx, hry);
                                    color(cyan);
                                    wprintf(L"ɸ");
                                    color(reset);
                                    super[si].x = hrx;
                                    super[si].y = hry;
                                    break;
                                }
                            }
                        }
                    }

                    gotoxy(player2.ppx, player2.ppy);
                    wprintf(L" ");

                    gotoxy(player2.npx, player2.npy);
                    color(blue);
                    wprintf(L"ᗛ");
                    color(reset);
                    player2.dire = -1;
                }
                break;

            case 'l': case'L':

                if (wallmap[player2.npy][player2.npx + 1] != '|' && wallmap[player2.npy][player2.npx + 1] != 'm')
                {
                    player2.ppx = player2.npx;
                    player2.ppy = player2.npy;
                    ++player2.npx;

                    if (player2.npx == teleporter1.x && player2.npy == teleporter1.y)
                    {
                        player2.npy = teleporter2.y;
                        player2.npx = teleporter2.x;
                        ++player2.npx;
                    }
                    else if (player2.npx == teleporter2.x && player2.npy == teleporter2.y)
                    {
                        player2.npy = teleporter1.y;
                        player2.npx = teleporter1.x;
                        ++player2.npx;
                    }

                    for (int bi = 0; bi < black_hole_i; bi++)
                    {
                        if (player2.npx == blackholes[bi].x && player2.npy == blackholes[bi].y)
                        {
                            player2.npy = player2.spy;
                            player2.npx = player2.spx;
                            player2.hp--;
                        }
                    }

                    for (int hi = 0; hi < heart_i; hi++)
                    {
                        if (player2.npx == hearts[hi].x && player2.npy == hearts[hi].y)
                        {

                            player2.hp += 5;
                            while (1)
                            {
                                hrx = random(81);
                                hry = random(29);
                                if (wallmap[hry][hrx] == ' ')
                                {
                                    gotoxy(hrx, hry);
                                    wprintf(L"❤");
                                    hearts[hi].x = hrx;
                                    hearts[hi].y = hry;
                                    break;
                                }
                            }
                        }
                    }

                    for (int hi = 0; hi < heart_i; hi++)
                    {
                        if (player2.npx == bombs[hi].x && player2.npy == bombs[hi].y)
                        {

                            player2.hp += 5;

                            while (1)
                            {
                                hrx = random(81);
                                hry = random(29);
                                if (wallmap[hry][hrx] == ' ')
                                {
                                    gotoxy(hrx, hry);
                                    color(purple);
                                    wprintf(L"ర");
                                    color(reset);
                                    bombs[hi].x = hrx;
                                    bombs[hi].y = hry;
                                    break;
                                }
                            }
                        }
                    }

                    for (int si = 0; si < super_i; si++)
                    {
                        if (player2.npx == super[si].x && player2.npy == super[si].y)
                        {

                            player2.sup += 5;
                            while (1)
                            {
                                hrx = random(81);
                                hry = random(29);
                                if (wallmap[hry][hrx] == ' ')
                                {
                                    gotoxy(hrx, hry);
                                    color(cyan);
                                    wprintf(L"ɸ");
                                    color(reset);
                                    super[si].x = hrx;
                                    super[si].y = hry;
                                    break;
                                }
                            }
                        }
                    }

                    gotoxy(player2.ppx, player2.ppy);
                    wprintf(L" ");

                    gotoxy(player2.npx, player2.npy);
                    color(blue);
                    wprintf(L"ᗚ");
                    color(reset);
                    player2.dire = 1;
                }
                break;
            case 'c': case'C':
                bullets[bullet_i].act = 1;
                bullets[bullet_i].dire = player1.dire;
                switch (bullets[bullet_i].dire)
                {
                case 1: bullets[bullet_i].x = player1.npx + 1; bullets[bullet_i].y = player1.npy; if (player1.sup > 0) { player1.sup--; bullets[bullet_i].sup = 1; } break;
                case -1: bullets[bullet_i].x = player1.npx - 1; bullets[bullet_i].y = player1.npy; if (player1.sup > 0) { player1.sup--; bullets[bullet_i].sup = 1; } break;
                case 2: bullets[bullet_i].x = player1.npx; bullets[bullet_i].y = player1.npy + 1; if (player1.sup > 0) { player1.sup--; bullets[bullet_i].sup = 1; } break;
                case -2: bullets[bullet_i].x = player1.npx; bullets[bullet_i].y = player1.npy - 1; if (player1.sup > 0) { player1.sup--; bullets[bullet_i].sup = 1; } break;

                }
                bullet_i++;
                break;

            case 'n': case'N':
                bullets[bullet_i].act = 1;
                bullets[bullet_i].dire = player2.dire;
                switch (bullets[bullet_i].dire)
                {
                case 1: bullets[bullet_i].x = player2.npx + 1; bullets[bullet_i].y = player2.npy; if (player2.sup > 0) { player2.sup--; bullets[bullet_i].sup = 1; } break;
                case -1: bullets[bullet_i].x = player2.npx - 1; bullets[bullet_i].y = player2.npy; if (player2.sup > 0) { player2.sup--; bullets[bullet_i].sup = 1; }break;
                case 2: bullets[bullet_i].x = player2.npx; bullets[bullet_i].y = player2.npy + 1; if (player2.sup > 0) { player2.sup--; bullets[bullet_i].sup = 1; }break;
                case -2: bullets[bullet_i].x = player2.npx; bullets[bullet_i].y = player2.npy - 1; if (player2.sup > 0) { player2.sup--; bullets[bullet_i].sup = 1; }break;

                }
                bullet_i++;
                break;
                
         }

        }

        for (int zbi = 0; zbi < bullet_i; zbi++)
        {
            if (bullets[zbi].act == 1)
            {
                if (bullets[zbi].dire == 1)
                {

                    if (player1.bb == 1)
                    {
                        if (wallmap[bullets[zbi].y][bullets[zbi].x + 1] == ' ' || wallmap[bullets[zbi].y][bullets[zbi].x + 1] == 's')
                        {
                            bullets[zbi].px = bullets[zbi].x;
                            bullets[zbi].py = bullets[zbi].y;

                            gotoxy(bullets[zbi].px, bullets[zbi].py);
                            wprintf(L" ");

                            ++bullets[zbi].x;
                            gotoxy(bullets[zbi].x, bullets[zbi].y);
                            wprintf(L"o");
                        }
                        else
                        {
                            bullets[zbi].act = 0;
                            gotoxy(bullets[zbi].x, bullets[zbi].y);
                            wprintf(L" ");
                            player1.bb = 0;

                            if (player1.npy >= bullets[zbi].y - 3 && player1.npy <= bullets[zbi].y + 3)
                                if (player1.npx >= bullets[zbi].x - 3 && player1.npx <= bullets[zbi].x + 3)
                                    player1.hp--;

                            if (player2.npy >= bullets[zbi].y - 3 && player2.npy <= bullets[zbi].y + 3)
                                if (player2.npx >= bullets[zbi].x - 3 && player2.npx <= bullets[zbi].x + 3)
                                    player2.hp--;

                        }
                        
                    }
                    else if (player2.bb == 1)
                    {
                        if (wallmap[bullets[zbi].y][bullets[zbi].x + 1] == ' ' || wallmap[bullets[zbi].y][bullets[zbi].x + 1] == 's')
                        {
                            bullets[zbi].px = bullets[zbi].x;
                            bullets[zbi].py = bullets[zbi].y;

                            gotoxy(bullets[zbi].px, bullets[zbi].py);
                            wprintf(L" ");

                            ++bullets[zbi].x;
                            gotoxy(bullets[zbi].x, bullets[zbi].y);
                            wprintf(L"o");
                        }
                        else
                        {
                            bullets[zbi].act = 0;
                            gotoxy(bullets[zbi].x, bullets[zbi].y);
                            wprintf(L" ");
                            player2.bb = 0;

                            if (player1.npy >= bullets[zbi - 2].y && player1.npy <= bullets[zbi + 2].y)
                                if (player1.npx >= bullets[zbi - 2].x && player1.npx <= bullets[zbi + 2].x)
                                    player1.hp--;

                            if (player2.npy >= bullets[zbi - 2].y && player2.npy <= bullets[zbi + 2].y)
                                if (player2.npx >= bullets[zbi - 2].x && player2.npx <= bullets[zbi + 2].x)
                                    player2.hp--;

                        }
                    }


                    else
                    { 
                        if (player1.npx == bullets[zbi].x + 1 && player1.npy == bullets[zbi].y)
                        {
                            bullets[zbi].act = 0;
                            gotoxy(bullets[zbi].x, bullets[zbi].y);
                            wprintf(L" ");
                            if (bullets[zbi].sup)
                                player1.hp -= 2;
                            else
                                player1.hp--;
                        }
                        else if (player2.npx == bullets[zbi].x + 1 && player2.npy == bullets[zbi].y)
                        {
                            bullets[zbi].act = 0;
                            gotoxy(bullets[zbi].x, bullets[zbi].y);
                            wprintf(L" ");
                            if (bullets[zbi].sup)
                                player2.hp -= 2;
                            else
                                player2.hp--;

                        }
                        else if (wallmap[bullets[zbi].y][bullets[zbi].x + 1] == ' ' || wallmap[bullets[zbi].y][bullets[zbi].x + 1] == 's')
                        {
                            bullets[zbi].px = bullets[zbi].x;
                            bullets[zbi].py = bullets[zbi].y;

                            gotoxy(bullets[zbi].px, bullets[zbi].py);
                            wprintf(L" ");

                            ++bullets[zbi].x;
                            gotoxy(bullets[zbi].x, bullets[zbi].y);
                            wprintf(L".");
                        }
                        else if (wallmap[bullets[zbi].y][bullets[zbi].x + 1] == 'm')
                        {
                            bullets[zbi].dire *= -1;
                        }
                        else
                        {
                            bullets[zbi].act = 0;
                            gotoxy(bullets[zbi].x, bullets[zbi].y);
                            wprintf(L" ");
                        }
                    }

                }
                else if (bullets[zbi].dire == -1)
                {
                        
                        if (player1.bb == 1)
                        {
                            if (wallmap[bullets[zbi].y][bullets[zbi].x - 1] == ' ' || wallmap[bullets[zbi].y][bullets[zbi].x - 1] == 's')
                            {
                                bullets[zbi].px = bullets[zbi].x;
                                bullets[zbi].py = bullets[zbi].y;

                                gotoxy(bullets[zbi].px, bullets[zbi].py);
                                wprintf(L" ");

                                --bullets[zbi].x;
                                gotoxy(bullets[zbi].x, bullets[zbi].y);
                                wprintf(L"o");
                            }
                            else
                            {
                                bullets[zbi].act = 0;
                                gotoxy(bullets[zbi].x, bullets[zbi].y);
                                wprintf(L" ");
                                player1.bb = 0;

                                if (player1.npy >= bullets[zbi].y - 3 && player1.npy <= bullets[zbi].y + 3)
                                    if (player1.npx >= bullets[zbi].x - 3 && player1.npx <= bullets[zbi].x + 3)
                                        player1.hp--;

                                if (player2.npy >= bullets[zbi].y - 3 && player2.npy <= bullets[zbi].y + 3)
                                    if (player2.npx >= bullets[zbi].x - 3 && player2.npx <= bullets[zbi].x + 3)
                                        player2.hp--;

                            }

                        }
                        else if (player2.bb == 1)
                        {
                            if (wallmap[bullets[zbi].y][bullets[zbi].x - 1] == ' ' || wallmap[bullets[zbi].y][bullets[zbi].x - 1] == 's')
                            {
                                bullets[zbi].px = bullets[zbi].x;
                                bullets[zbi].py = bullets[zbi].y;

                                gotoxy(bullets[zbi].px, bullets[zbi].py);
                                wprintf(L" ");

                                --bullets[zbi].x;
                                gotoxy(bullets[zbi].x, bullets[zbi].y);
                                wprintf(L"o");
                            }
                            else
                            {
                                bullets[zbi].act = 0;
                                gotoxy(bullets[zbi].x, bullets[zbi].y);
                                wprintf(L" ");
                                player2.bb = 0;

                                if (player1.npy >= bullets[zbi - 2].y && player1.npy <= bullets[zbi + 2].y)
                                    if (player1.npx >= bullets[zbi - 2].x && player1.npx <= bullets[zbi + 2].x)
                                        player1.hp--;

                                if (player2.npy >= bullets[zbi - 2].y && player2.npy <= bullets[zbi + 2].y)
                                    if (player2.npx >= bullets[zbi - 2].x && player2.npx <= bullets[zbi + 2].x)
                                        player2.hp--;

                            }
                        }

                        else
                        {


                            if (player1.npx == bullets[zbi].x - 1 && player1.npy == bullets[zbi].y)
                            {
                                bullets[zbi].act = 0;
                                gotoxy(bullets[zbi].x, bullets[zbi].y);
                                wprintf(L" ");
                                if (bullets[zbi].sup)
                                    player1.hp -= 2;
                                else
                                    player1.hp--;
                            }
                            else if (player2.npx == bullets[zbi].x - 1 && player2.npy == bullets[zbi].y)
                            {
                                bullets[zbi].act = 0;
                                gotoxy(bullets[zbi].x, bullets[zbi].y);
                                wprintf(L" ");
                                if (bullets[zbi].sup)
                                    player2.hp -= 2;
                                else
                                    player2.hp--;

                            }
                            else if (wallmap[bullets[zbi].y][bullets[zbi].x - 1] == ' ' || wallmap[bullets[zbi].y][bullets[zbi].x - 1] == 's')
                            {
                                bullets[zbi].px = bullets[zbi].x;
                                bullets[zbi].py = bullets[zbi].y;

                                gotoxy(bullets[zbi].px, bullets[zbi].py);
                                wprintf(L" ");

                                --bullets[zbi].x;
                                gotoxy(bullets[zbi].x, bullets[zbi].y);
                                wprintf(L".");
                            }
                            else if (wallmap[bullets[zbi].y][bullets[zbi].x - 1] == 'm')
                            {
                                bullets[zbi].dire *= -1;
                            }
                            else
                            {
                                bullets[zbi].act = 0;
                                gotoxy(bullets[zbi].x, bullets[zbi].y);
                                wprintf(L" ");
                            }
                        }
                    
                }
                else if (bullets[zbi].dire == -2)
                {
                    if (player1.bb == 1)
                    {
                        if (wallmap[bullets[zbi].y - 1][bullets[zbi].x] == ' ' || wallmap[bullets[zbi].y - 1][bullets[zbi].x] == 's')
                        {
                            bullets[zbi].px = bullets[zbi].x;
                            bullets[zbi].py = bullets[zbi].y;

                            gotoxy(bullets[zbi].px, bullets[zbi].py);
                            wprintf(L" ");

                            --bullets[zbi].y;
                            gotoxy(bullets[zbi].x, bullets[zbi].y);
                            wprintf(L"o");
                        }
                        else
                        {
                            bullets[zbi].act = 0;
                            gotoxy(bullets[zbi].x, bullets[zbi].y);
                            wprintf(L" ");
                            player1.bb = 0;

                            if (player1.npy >= bullets[zbi].y - 3 && player1.npy <= bullets[zbi].y + 3)
                                if (player1.npx >= bullets[zbi].x - 3 && player1.npx <= bullets[zbi].x + 3)
                                    player1.hp--;

                            if (player2.npy >= bullets[zbi].y - 3 && player2.npy <= bullets[zbi].y + 3)
                                if (player2.npx >= bullets[zbi].x - 3 && player2.npx <= bullets[zbi].x + 3)
                                    player2.hp--;

                        }

                    }
                    else if (player2.bb == 1)
                    {
                        if (wallmap[bullets[zbi].y - 1][bullets[zbi].x] == ' ' || wallmap[bullets[zbi].y - 1][bullets[zbi].x] == 's')
                        {
                            bullets[zbi].px = bullets[zbi].x;
                            bullets[zbi].py = bullets[zbi].y;

                            gotoxy(bullets[zbi].px, bullets[zbi].py);
                            wprintf(L" ");

                            --bullets[zbi].y;
                            gotoxy(bullets[zbi].x, bullets[zbi].y);
                            wprintf(L"o");
                        }
                        else
                        {
                            bullets[zbi].act = 0;
                            gotoxy(bullets[zbi].x, bullets[zbi].y);
                            wprintf(L" ");
                            player2.bb = 0;

                            if (player1.npy >= bullets[zbi - 2].y && player1.npy <= bullets[zbi + 2].y)
                                if (player1.npx >= bullets[zbi - 2].x && player1.npx <= bullets[zbi + 2].x)
                                    player1.hp--;

                            if (player2.npy >= bullets[zbi - 2].y && player2.npy <= bullets[zbi + 2].y)
                                if (player2.npx >= bullets[zbi - 2].x && player2.npx <= bullets[zbi + 2].x)
                                    player2.hp--;

                        }
                    }
                    else
                    { 
                        if (player1.npx == bullets[zbi].x && player1.npy == bullets[zbi].y - 1)
                    {
                        bullets[zbi].act = 0;
                        gotoxy(bullets[zbi].x, bullets[zbi].y);
                        wprintf(L" ");
                        if (bullets[zbi].sup)
                            player1.hp -= 2;
                        else
                            player1.hp--;
                    }
                        else if (player2.npx == bullets[zbi].x && player2.npy == bullets[zbi].y - 1)
                    {
                        bullets[zbi].act = 0;
                        gotoxy(bullets[zbi].x, bullets[zbi].y);
                        wprintf(L" ");
                        if (bullets[zbi].sup)
                            player2.hp -= 2;
                        else
                            player2.hp--;

                    }
                        else if (wallmap[bullets[zbi].y - 1][bullets[zbi].x] == ' ' || wallmap[bullets[zbi].y - 1][bullets[zbi].x] == 's')
                    {
                        bullets[zbi].px = bullets[zbi].x;
                        bullets[zbi].py = bullets[zbi].y;

                        gotoxy(bullets[zbi].px, bullets[zbi].py);
                        wprintf(L" ");

                        --bullets[zbi].y;
                        gotoxy(bullets[zbi].x, bullets[zbi].y);
                        wprintf(L".");
                    }
                        else if (wallmap[bullets[zbi].y - 1][bullets[zbi].x] == 'm')
                    {
                        bullets[zbi].dire *= -1;
                    }
                        else
                    {
                        bullets[zbi].act = 0;
                        gotoxy(bullets[zbi].x, bullets[zbi].y);
                        wprintf(L" ");
                    }
                    }
                }
                else if (bullets[zbi].dire == 2)
                {
                    if (player1.bb == 1)
                    {
                        if (wallmap[bullets[zbi].y + 1][bullets[zbi].x] == ' ' || wallmap[bullets[zbi].y + 1][bullets[zbi].x] == 's')
                        {
                            bullets[zbi].px = bullets[zbi].x;
                            bullets[zbi].py = bullets[zbi].y;

                            gotoxy(bullets[zbi].px, bullets[zbi].py);
                            wprintf(L" ");

                            ++bullets[zbi].y;
                            gotoxy(bullets[zbi].x, bullets[zbi].y);
                            wprintf(L"o");
                        }
                        else
                        {
                            bullets[zbi].act = 0;
                            gotoxy(bullets[zbi].x, bullets[zbi].y);
                            wprintf(L" ");
                            player1.bb = 0;

                            if (player1.npy >= bullets[zbi].y - 3 && player1.npy <= bullets[zbi].y + 3)
                                if (player1.npx >= bullets[zbi].x - 3 && player1.npx <= bullets[zbi].x + 3)
                                    player1.hp--;

                            if (player2.npy >= bullets[zbi].y - 3 && player2.npy <= bullets[zbi].y + 3)
                                if (player2.npx >= bullets[zbi].x - 3 && player2.npx <= bullets[zbi].x + 3)
                                    player2.hp--;

                        }

                    }
                    else if (player2.bb == 1)
                    {
                        if (wallmap[bullets[zbi].y + 1][bullets[zbi].x] == ' ' || wallmap[bullets[zbi].y + 1][bullets[zbi].x] == 's')
                        {
                            bullets[zbi].px = bullets[zbi].x;
                            bullets[zbi].py = bullets[zbi].y;

                            gotoxy(bullets[zbi].px, bullets[zbi].py);
                            wprintf(L" ");

                            ++bullets[zbi].y;
                            gotoxy(bullets[zbi].x, bullets[zbi].y);
                            wprintf(L"o");
                        }
                        else
                        {
                            bullets[zbi].act = 0;
                            gotoxy(bullets[zbi].x, bullets[zbi].y);
                            wprintf(L" ");
                            player2.bb = 0;

                            if (player1.npy >= bullets[zbi - 2].y && player1.npy <= bullets[zbi + 2].y)
                                if (player1.npx >= bullets[zbi - 2].x && player1.npx <= bullets[zbi + 2].x)
                                    player1.hp--;

                            if (player2.npy >= bullets[zbi - 2].y && player2.npy <= bullets[zbi + 2].y)
                                if (player2.npx >= bullets[zbi - 2].x && player2.npx <= bullets[zbi + 2].x)
                                    player2.hp--;

                        }
                    }
                    else
                    {
                        if (player1.npx == bullets[zbi].x && player1.npy == bullets[zbi].y + 1)
                        {
                            bullets[zbi].act = 0;
                            gotoxy(bullets[zbi].x, bullets[zbi].y);
                            wprintf(L" ");
                            if (bullets[zbi].sup)
                                player1.hp -= 2;
                            else
                                player1.hp--;
                        }
                        else if (player2.npx == bullets[zbi].x && player2.npy == bullets[zbi].y + 1)
                        {
                            bullets[zbi].act = 0;
                            gotoxy(bullets[zbi].x, bullets[zbi].y);
                            wprintf(L" ");
                            if (bullets[zbi].sup)
                                player2.hp -= 2;
                            else
                                player2.hp--;

                        }
                        else if (wallmap[bullets[zbi].y + 1][bullets[zbi].x] == ' ' || wallmap[bullets[zbi].y + 1][bullets[zbi].x] == 's')
                        {
                            bullets[zbi].px = bullets[zbi].x;
                            bullets[zbi].py = bullets[zbi].y;

                            gotoxy(bullets[zbi].px, bullets[zbi].py);
                            wprintf(L" ");

                            ++bullets[zbi].y;
                            gotoxy(bullets[zbi].x, bullets[zbi].y);
                            wprintf(L".");
                        }
                        else if (wallmap[bullets[zbi].y + 1][bullets[zbi].x] == 'm')
                        {
                            bullets[zbi].dire *= -1;
                        }
                        else
                        {
                            bullets[zbi].act = 0;
                            gotoxy(bullets[zbi].x, bullets[zbi].y);
                            wprintf(L" ");
                        }
                    }
                }

            }
        }

        
        

        _setmode(_fileno(stdout), _O_TEXT);
        gotoxy(0, 25);
        printf("%s hp is : %d   ", player1.name, player1.hp);
        gotoxy(0, 26);
        printf("%s hp is : %d   ", player2.name, player2.hp);
        _setmode(_fileno(stdout), _O_U16TEXT);

        gotoxy(0, 0);
        Sleep(25);

        if (player1.hp == 0)
        {
            cs();
            gameover = 1;
            _setmode(_fileno(stdout), _O_TEXT);
            printf("Player %s is the WINER!!!", player2.name);
            player2.wins++;
            _setmode(_fileno(stdout), _O_TEXT);
            sleep(3);
            if (mapchecker)
                map3();
            else
                map2();
        }
        else if (player2.hp == 0)
        {
            cs();
            gameover = 1;
            _setmode(_fileno(stdout), _O_TEXT);
            printf("Player %s is the WINER!!!", player1.name);
            player1.wins++;
            _setmode(_fileno(stdout), _O_TEXT);
            sleep(3);
            if (mapchecker == 0)
                map2();
            else if (mapchecker == 1)
                map3();
            
                Menu();
        }
 }
}

void position_setup()
{
    player1.spx = 13;
    player1.spy = 10;
    player2.spx = 66;
    player2.spy = 10;

    player1.npx = 13;
    player1.npy = 10;
    player2.npx = 66;
    player2.npy = 10;

    player1.ppx = 13;
    player1.ppy = 10;
    player2.ppx = 66;
    player2.ppy = 10;
}

void map1()
{
    char wallmap[mapi][mapj] = {

                         "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||",
                         "|                                                                              |",
                         "|                     |m                                 |          t          |",
                         "|                     |m                                 |                     |",
                         "|                     |m               h                 |   o                 |",
                         "|                                                                              |",
                         "|           |||||                                              |||||           |",
                         "|               |m                     |                      m|               |",
                         "|               |m                     |                      m|               |",
                         "|               |                      |  ||||||               |               |",
                         "|            s  |                      m                       |  s            |",
                         "|               |              ||||||  |                       |               |",
                         "|               |m                     |                      m|               |",
                         "|               |m                     |                      m|               |",
                         "|           |||||        o                                     |||||           |",
                         "|                                                                              |",
                         "|                     |                                 m|                     |",
                         "|                     |                                 m|                     |",
                         "|         t           |                                 m|                     |",
                         "|                                                                              |",
                         "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||",

    };
    mapchecker = 0;
    Start_game(wallmap);
}
void map2()
{
    char wallmap[mapi][mapj] = {

                         "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||",
                         "|                                                                              |",
                         "|                          |m                   m|                             |",
                         "|                          |                     |                             |",
                         "|                                                                              |",
                         "|                                    |||                                       |",
                         "|                                                                              |",
                         "|                 m           |       |        |             m                 |",
                         "|                 m     e    |     ||||         |   e        m                 |",
                         "|                 m         |      |    o       m|           m                 |",
                         "|            s    m        |     |||m  h  |||     |          m    s            |",
                         "|                 m         |m      o     |      |           m                 |",
                         "|                 m          |        |||||     |            m                 |",
                         "|                 m           |       |        |             m                 |",
                         "|                                     o                                        |",
                         "|                                     b                                        |",
                         "|                                    |||                                       |",
                         "|       t                  |m                   m|                     t       |",
                         "|                          |                     |                             |",
                         "|                                                                              |",
                         "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||",

    };
    mapchecker = 1;
    Start_game(wallmap);
}
void map3()
{
    char wallmap[mapi][mapj] = {

                         "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||",
                         "|   |                              ||                                      m   |",
                         "|   m                             |  |oo                                   |   |",
                         "|   |                                 ho                                   m   |",
                         "|   m                             |  |eo                                   |   |",
                         "|   |                              ||ooo                                   m   |",
                         "|   m          ||||||||||                           ||||||||||             |   |",
                         "|   |                                                                      m   |",
                         "|   m                                                                      |   |",
                         "|   |           m                                              m           m   |",
                         "|   m        s  m                   |b|                        m  s        |   |",
                         "|   |           m                                              m           m   |",
                         "|   m                                                                      |   |",
                         "|   |                                                                      m   |",
                         "|   m          ||||||||||                           ||||||||||             |   |",
                         "|   |                           ooo||                                      m   |",
                         "|   m                           oe|  |                                     |   |",
                         "|   |                           oh                                         m   |",
                         "|   m                           oo|  |                                     |   |",
                         "|   |                              ||                                      m   |",
                         "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||",

    };
    mapchecker = 2;
    Start_game(wallmap);
}