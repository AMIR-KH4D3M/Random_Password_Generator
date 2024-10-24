// Project Name -> Random Password Generator
// Programmer -> Amir Khadem

#include <stdio.h>
#include <windows.h> // for Sleep
#include <stdlib.h> // for srand
#include <time.h> // for time
#include <stdlib.h>

//this funktion print a message
void bar(char* message , int counter)
{
    for(int i = 0;i < counter;i++)
    {
        printf("%c" , message[i]);
        Sleep(30); // 30 millisecond
    }
}

// this function will print a menu for our program
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
// This function will give us a strong random password in cmd/terminal and FILE 
void password(int password_length , int choice , int counter , FILE *file)
{
    char list[] = "1234567890qwertyuiopasdfghjklzxcvbnm,.<>/?;:'|{}[]!@#$^&*()_+=/*\""; 
    char fmsg[] = "\tpassword -> ";

    int fcnt = sizeof(fmsg) / sizeof(fmsg[0]);

    if(choice == 1) // show password in terminal or cmd
    {
        printf("\n");

        bar(fmsg , fcnt);

        char generated_password[100]; // save our password
        int password_index = 0; 

        for(int i = 0; i < password_length; i++)
        {
            generated_password[password_index] = list[rand() % (sizeof (list) - 1)];
            password_index++;
        }   
        generated_password[password_index] = '\0';
        bar(generated_password , password_index);
        printf("\n");

    }
    else if(choice == 2) // write password in password.txt file
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

    system("cls");
    FILE *file = fopen("password.txt" , "w"); // for write password in list

    char link[] = "https://github.com/AMIR-KH4D3M";
    char fmsg[] = "Enter a number -> ";
    char smsg[] = "Enter password length -> ";
    char tmsg[] = "How many password you want -> ";

    int password_length , counter , choice;
    int fcount = sizeof(fmsg) / sizeof(fmsg[0]);
    int scount = sizeof(smsg) / sizeof(smsg[0]);
    int tcount = sizeof(tmsg) / sizeof(tmsg[0]);
    int lcount = sizeof(link) / sizeof(link[0]);

    menu();
    bar(fmsg , fcount);
    scanf("%d" , &choice);

    if(choice == 1) // show password in terminal or cmd
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

    printf("\n");

    bar(link , lcount);

    printf("\n");

    return 0;
}