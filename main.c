// project name -> password generator
// programmer -> Amir Khadem

#include <stdio.h>
#include <windows.h>
#include <stdlib.h> // for srand
#include <time.h> // for time

void bar(char* message , int counter)
{
    for(int i = 0;i < counter;i++)
    {
        printf("%c" , message[i]);
        Sleep(30); // 30 millisecond
    }
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
    printf("\n\n");
    bar(smsg , scount);
    printf("\n\n");
    bar(tmsg , tcount);
    printf("\n\n");
    
}   

void password(int password_length , int choice , int counter , FILE *file)
{
    char list[] = "1234567890qwertyuiopasdfghjklzxcvbnm,.<>/?;:'|{}[]!@#$^&*()_+=/*\"";

    if(choice == 1)
    {
        printf("\n");

        printf("\t password -> ");

        for(int i = 0; i < password_length; i++)
        {
            printf("%c" , list[rand() % (sizeof (list) - 1)]);
        }   
        printf("\n");
    }
    else if(choice == 2)
    {
        for(int j = 0; j < counter; j++)
        {
            for(int i = 0; i < password_length; i++)
                {
                    fprintf(file, "%c", list[rand() % (sizeof(list) - 1)]);
                }
            fprintf(file , "\n");
        }
    }
}

int main()
{
    FILE *file = fopen("password.txt" , "w");

    char fmsg[] = "Enter a number -> ";
    char smsg[] = "Enter password length -> ";
    char tmsg[] = "How many password you want -> ";

    int password_length , counter , choice;
    int fcount = sizeof(fmsg) / sizeof(fmsg[0]);
    int scount = sizeof(smsg) / sizeof(smsg[0]);
    int tcount = sizeof(tmsg) / sizeof(tmsg[0]);

    menu();
    bar(fmsg , fcount);
    scanf("%d" , &choice);

    if(choice == 1)
    {
        bar(smsg , scount);
        scanf("%d" , &password_length);
    }
    else if (choice == 2)
    {   
        bar(smsg , scount);
        scanf("%d" , &password_length);
        bar(tmsg , tcount);
        scanf("%d" , &counter);
    }

    srand(time(NULL));

    password(password_length , choice , counter , file);

    fclose(file);

    return 0;
}