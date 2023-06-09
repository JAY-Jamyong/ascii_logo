#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void gotoxy(int x, int y)
{
    COORD Pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

const char data[] = ""
"################################";

void printArt()
{
    int seed = time(NULL);
    srand(seed);

    char *buffer = (char*)malloc(sizeof(data));
    int n = 0;
    while(TRUE)
    {
        if(n == sizeof(data)) break;
        if(data[n] == 0) break;
        buffer[n] = data[n];
        if(buffer[n] != ' ') 
        {
            if(buffer[n] != '\r')
            {
                if(buffer[n] != '\n')
                {
                    int c = 0;
                    while(TRUE)
                    {
                        c = rand() % 120;
                        if(c >= 65)
                        {
                            break;
                        }
                    }
                    buffer[n] = c;                    
                }
            }
        }
        n++;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);

    buffer[n] = 0;
    printf("%s\n", buffer);
    
    free(buffer);
}

void play()
{
    while(TRUE)
    {
        Sleep(1500);
        gotoxy(0, 0);
        printArt();
        gotoxy(60, 0);
    }
}

int main()
{
    HANDLE hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)play, NULL, 0, NULL);

    while(TRUE)
    {
        gotoxy(60, 0);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

        char data[256] = {0,};
        fgets(data, 256, stdin);
        Sleep(1000);
    }

    return 0;
}
