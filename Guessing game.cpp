#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std ;
int  main ()

{
    while(1)
    {
        int guessnumber, randomnumber;
        cout << "Enter your guess number between 1 to 5 :" << endl;
        cin >> guessnumber;
        randomnumber = 1 + rand ()%5 ;
        if (guessnumber == randomnumber)
        {
            cout << "You have won "<< endl << endl ;
        }
        else
        {
            cout << "You have lost ____ Please try again" << endl;
            cout << "Random number was :" << randomnumber << endl <<  endl;
        }

    }
    getch();
}

