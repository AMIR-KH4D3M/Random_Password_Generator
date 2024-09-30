// project name -> password generator
// programmer -> Amir Khadem

#include <stdio.h>
#include <windows.h>

void bar(char* message , int counter)
{
    for(int i = 0;i < counter;i++)
    {
        printf("%c" , message[i]);
        Sleep(30); // 30 millisecond
    }
    printf("\n\n");
}


void menu()
{
    char fmsg[] = "Welcome to the password generator";
    char smsg[] = "[1] >>> create a random password";
    char tmsg[] = "[2] >>> create a random password list";

    int fcount = sizeof(fmsg) / sizeof(fmsg[0]);
    int scount = sizeof(smsg) / sizeof(smsg[0]);
    int tcount = sizeof(tmsg) / sizeof(tmsg[0]);

    bar(fmsg , fcount);
    bar(smsg , scount);
    bar(tmsg , tcount);
}   

int main()
{
    menu(); 
    return 0;
}