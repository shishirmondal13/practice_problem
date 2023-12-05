#include<bits/stdc++.h>
#include<time.h>
#include<string.h>
#include<windows.h>
#include <map>
using namespace std;

// Your existing code here...
void setcolorandbackground(int textc,int backg)             //with this we can set text color and background color
{
    WORD color = (( backg & 0x0F )<<4) + ( textc & 0x0F );
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}

void title()       //prints title of the program
{
    system("CLS");
    cout << endl;
    setcolorandbackground(9,0);  //  void SetColorAndBackground (int FontC, int BackC)
    cout << "\t\t\t|******************************************|\n" << endl;
    cout << "\t\t\t ";
    setcolorandbackground(15,0);
    cout << "\t Welcome  to  Hand  Cricket!!"<<endl<<endl<<endl;
    setcolorandbackground(9,0);
    cout << "\t\t\t|******************************************|\n" << endl;


}

void mainmenu() //Function for printing Main menu options
{
    setcolorandbackground(6,0);
    cout << "\n\n\t\t";
    setcolorandbackground(9,15);
    cout << "\t\t\tMAIN MENU";
    setcolorandbackground(9,0);
    cout << "\n\n\t\t\t\t1.Start a new game" << endl;
    cout << "\n\t\t\t\t2.Instructions" << endl;
    cout << "\n\t\t\t\t3.About Us" << endl;
    cout << "\n\t\t\t\tPress any other key to exit the game" << endl;
    cout << "\n\t\t\t\tEnter your Choice: ";
    setcolorandbackground(15,0);
}

void instructions()
{
    title();
    cout <<"\n";
    setcolorandbackground(9,15);
    cout << "\t\t\t\tINSTRUCTIONS AND RULES";
    setcolorandbackground(3,0);
    cout << "\n";
    cout << "\n\t1. You have to choose which format you want to play."<<endl;
    cout << "\n\t2. If you won a toss, you have to choose what you will do, i.e.: Batting or Bowling."<<endl;
    cout <<"\n\t3. You have to choose a number between 1 and 6 during your turn."<<endl;
    cout <<"\n\t4. If your choice and your opponents choice are same, then the person who is batting is considered as OUT."<<endl;
    cout <<"\n\t5. One who scores more during their batting is declared as WINNER."<<endl;
    cout <<"\n\t6. If both scores same, then the result will be 'DRAW'."<<endl;
    setcolorandbackground(15,0);
    cout << "\n\n\t\tPress '0' to go back to main menu....: ";
    setcolorandbackground(15,0);
}

void about_us()
{
    title();
    cout <<"\n";
    setcolorandbackground(9,15);
    cout << "\t\t\t\tGroup Name : BUBT_battle-buddies\n\n";
    setcolorandbackground(15,0);
    cout << "\n\tTeam Members Name     --------------------------      Member's Title ";
    setcolorandbackground(3,0);
    cout << "\n";
    cout << "\n\t1.Sudipto Mandal     ----------------------------     Game Producer"<<endl;
    cout << "\n\t2.Amina Islam Katha   -----------------------------  Narrative Writer"<<endl;
    cout << "\n\t3.Shishir Mondal      -----------------------------  Game Designer and coder"<<endl;
    cout << "\n\t4.Mehedi Hasan Ratul  ----------------------------   Idea manager and editor"<<endl;
    cout << "\n\t5.Md Arif Hossain      ---------------------------   Game Tester"<<endl;

    setcolorandbackground(15,0);
    cout << "\n\n\t\tPress '0' to go back to main menu....: ";
    setcolorandbackground(15,0);
}

bool toss(string player_name)                    //returns if the player has won the toss or not
{
    system("CLS");
    char choice;
    int t,c;
    setcolorandbackground(9,15);
    cout << "\n\n\t\t\tIt's Toss time!!\n";
    setcolorandbackground(11,0);
    cout << "\n\tChoose your call:\n\t1. Heads or 2. Tails:\t"<<endl;
    setcolorandbackground(12,0);
    cout << "\n\t(Note: If you choose another number you will lost the toss)"<<endl;
    setcolorandbackground(11,0);
    cout << "\n\t Please Select(1 or 2): ";
    cin >>choice;
    if((choice=='h'||choice=='H'||choice=='1')) c=1;
    else if((choice=='t'||choice=='T'||choice=='2')) c=2;
    srand(time(0));
    t = rand()%2+1;
    if((t==1&&c==1 )||(t==2&&c==2))
    {
        setcolorandbackground(10,0);
        cout << "\n\n===================== \tCongratulations! "<<player_name<<". You Have Won The Toss\t ==========================" << endl;
        return true;
    }
    else
    {
        setcolorandbackground(12,0);
        cout << "\n\n\t==================== \tSorry,"<<player_name<<". You Have Lost The Toss\t =======================" << endl;
        return false;
    }
}

int player()    //asks player to enter his score/choice
{
    int res;
    setcolorandbackground(11,0);
    cout << "\n\tChoose a number between 1 and 6: ";
    while(1)
    {
        cin >> res;
        if(res>6||res<1)
        {
            setcolorandbackground(11,0);
            cout << "\tPlease select a number between 1 and 6: ";
            continue;
        }
        else break;
    }
    return res;
}

int comp()         //generates random number between 1 and 6
{
    int res;
    res = rand()%6+1;
    setcolorandbackground(12,0);
    cout << "\n\tYour opponent's choice is: " << res << endl;
    return res;
}

void start_game(string player_name)
{
    title();
    system("CLS");
    cout <<"\n";
    setcolorandbackground(6,0);
    cout << "\n\n\t\t\t\t";
    setcolorandbackground(9,15);
    cout << "GAME STARTS!!!\n\n";
    setcolorandbackground(9,0);
    int choice,overs,balls,player_score=0,comp_score=0,b=0,t1,t2,first=0,second=0;  //first is first innings score
    //second is second innings score; t1,t2 are scores scored for each ball
    string bat,bowl;    //used to store which one is batting and who is bowling
    setcolorandbackground(11,0);
    cout << "\n\tWhich format would you like to play?\n\t1. 1 Over Match\n\t2. 2 Over Match\n\t3. 5 Over Match\n\n\t\tEnter your choice: ";
    cin>>overs;
    while(1)            //calculate total number of balls in an innings based on match format
    {
        if(overs==1)
        {
            balls = 6;
            break;
        }
        else if(overs==2)
        {
            balls = 12;
            break;
        }
        else if(overs==3)
        {
            balls = 18;
            break;
        }
        else
        {
            setcolorandbackground(4,0);
            cout << "\n\tPlease select a valid format!";
            continue;
        }
    }
    bool tossres = toss(player_name),out=false;
    if(tossres)                                        //based on toss result player gets to choose his choice
    {
        setcolorandbackground(11,0);
        cout << "\n\tSelect your choice:\n\t1.Batting\t\t2.Bowling\n\t";
        cout << "Select ( 1 or 2 ) :";
        cin >> choice;
        if(choice==1)
        {
            bat = "player";
            bowl = "comp";
        }
        else
        {
            bat = "comp";
            bowl = "player";
        }
    }
    else
    {
        choice = rand()%2+1;
        if(choice==1)
        {
            cout << "\n\tYour opponent chose to Bat first!";
            bat = "comp";
            bowl = "player";
        }
        else
        {
            cout << "\n\tYour opponent chose to Bowl first!";
            bat = "player";
            bowl = "comp";
        }
    }
    setcolorandbackground(6,0);
    cout << "\n\n\t\t\t\t";
    setcolorandbackground(9,15);
    cout << "FIRST INNINGS";
    setcolorandbackground(9,0);
    if(bat=="player") cout << "\n\n================================  "<<player_name<<" You are Batting Now!  ===============================\n";
    else              cout << "\n\n================================  "<<player_name<<" You are Bowling Now!  ===============================\n";
    while((!out)&&(b<balls))    //First Innings
    {
        t1=player();
        t2=comp();
        if(t1==t2)
        {
            out = true;
            setcolorandbackground(4,15);
            cout << "\n\tIt's OUT!!!\n";
        }
        else
        {
            if(bat=="player") player_score += t1;
            else comp_score += t2;
        }
        b++;
    }
                         //Before second innings need to change bat and bowl
    if(bat=="player")
    {
        bat = "comp";
        bowl = "player";
        first = player_score;
        int Target=1+first;
        setcolorandbackground(4,0);
        cout << "\n\tFirst Innings Ended!!\n";
        setcolorandbackground(9,0);
        cout<<"\n\tYour Score is "<< first <<endl;
        setcolorandbackground(4,0);
        cout<<"\n\tTarget is: "<< Target <<endl;
        setcolorandbackground(9,0);
        cout << "\n\n\t\t\t\t";
        setcolorandbackground(9,15);
        cout << "SECOND INNINGS";
        setcolorandbackground(9,0);
        cout << "\n\n================================  "<<player_name<<" You are Bowling Now!!  ====================================\n\n";
    }
    else
    {
        bowl = "comp";
        bat = "player";
        first = comp_score;
        int Target=1+first;
        setcolorandbackground(4,0);
        cout << "\n\tFirst Innings Ended!!\n";
        setcolorandbackground(10,0);
        cout<<"\n\tYour Opponent's Score is "<< first <<endl;
        cout<<"\n\tTarget is: "<< Target <<endl;
        setcolorandbackground(6,0);
        cout << "\n\n\t\t\t\t";
        setcolorandbackground(9,15);
        cout << "SECOND INNINGS";
        setcolorandbackground(9,0);
        cout << "\n\n====================================  "<<player_name<<" You are Batting Now!!  ====================================";
    }
    out = false;
    b=0;

    while((!out)&&(b<balls)&&(second<=first)) //Second Innings
    {

        t1=player();
        t2=comp();
        if(t1==t2)
        {
            out = true;
            setcolorandbackground(4,0);
            cout << "\n\tIt's OUT!!!\n";
        }
        else
        {
            if(bat=="player")
            {
                player_score += t1;
                second+=t1;
            }
            else
            {
                comp_score += t2;
                second+=t2;
            }
        }
        b++;
    }
    if(bat=="player")
    {
        setcolorandbackground(4,0);
        cout << "\n\tSecond Innings Ended!!\n";
        setcolorandbackground(10,0);
        cout <<"\n\tYour Score is "<< second <<endl;
        setcolorandbackground(9,0);
        cout <<"####################################################################################################################";
        setcolorandbackground(6,0);
        cout << "\n\n\t\t\t\t\t";
        setcolorandbackground(1,15);
        cout << "RESULT";
        if(first>second)
        {
            setcolorandbackground(4,0);
            cout << "\n\n\t\t\t\t"<<player_name<<" You Lost the Match!!";
            setcolorandbackground(10,0);//Green color
            cout << "\n\n\t\t\t\t  Better Luck next time";
        }
        else if(first == second)
        {
            setcolorandbackground(14,0);
            cout << "\n\n\t\t\t\t Match Draw!!";
        }
        else
        {
            setcolorandbackground(10,0);
            cout << "\n\n\t\t\t\t"<<player_name<<", Hurray!! You Won the Match!!";
            cout << "\n\n\t\t\t\t"<<player_name<<", Your Guessing power is good!!";
        }
    }
    else
    {
        setcolorandbackground(4,0);
        cout << "\n\tSecond Innings Ended!!\n\n";
        setcolorandbackground(10,0);
        cout <<"\tYour Opponent's Score is "<< second <<endl;
        setcolorandbackground(9,0);
        cout <<" ####################################################################################################################";
        setcolorandbackground(6,0);
        cout << "\n\n\t\t\t\t\t";
        setcolorandbackground(1,15);
        cout << "~~~~~~~ RESULT ~~~~~~~";
        if(first>second)
        {
            setcolorandbackground(10,0);
            cout << "\n\n\t\t\t\t  Hurray!"<<player_name<<" You Won the Match!!";
            setcolorandbackground(4,0);
            cout << "\n\n\t\t\t\t"<<player_name<<" your Guessing power is good!!";
        }
        else if(first == second)
        {
            setcolorandbackground(4,15);
            cout << "\n\n\t\t\t\t Match Draw!!";
        }
        else
        {
            setcolorandbackground(4,0);
            cout << "\n\n\t\t\t\t"<<player_name<<",  Lost the Match!!";
            setcolorandbackground(10,0);
            cout << "\n\n\t\t\t\t  Better Luck Next Time   ";
        }
    }
    setcolorandbackground(9,0);
    cout <<"\n\n####################################################################################################################";
    setcolorandbackground(10,0);
    cout << "\n\n\tPress '0' to go back to main menu....";
    setcolorandbackground(15,0);
}


std::map<std::string, std::string> users; // Map to store usernames and passwords

bool registerUser() {
    std::string newUsername, newPassword, confirmPass;
    std::cout << "\t Enter a new username: ";
    std::cin >> newUsername;

    if (users.find(newUsername) != users.end()) {
        std::cout << "\t Username already exists. Please choose a different one." << std::endl;
        return false;
    }

    std::cout << "\t Enter a new password: ";
    std::cin >> newPassword;
    std::cout << "\t Confirm your password: ";
    std::cin >> confirmPass;

    if (newPassword != confirmPass) {
        std::cout << "\t Passwords do not match. Please try again." << std::endl;
        Sleep(5000); // Pause for 5 seconds (5000 milliseconds)
        return false;
    }

    users[newUsername] = newPassword;

    std::cout << "\t Registration successful! You can now log in." << std::endl;
    Sleep(5000); // Pause for 5 seconds (5000 milliseconds)
    return true;
}

bool login() {
    std::string username, password;
    std::cout << "\t Enter your username: ";
    std::cin >> username;

    if (users.find(username) == users.end()) {
        std::cout << "\t Username not found. Please register or try again." << std::endl;
         Sleep(5000); // Pause for 5 seconds (5000 milliseconds)
        return false;
    }

    std::cout << "\t Enter your password: ";
    std::cin >> password;

    if (users[username] != password) {
        std::cout << "\t Incorrect password. Please try again." << std::endl;
         Sleep(5000); // Pause for 5 seconds (5000 milliseconds)
        return false;
    }

    std::cout << "\t Login successful! Welcome, " << username << "!" << std::endl;
    Sleep(5000); // Pause for 5 seconds (5000 milliseconds)
    return true;
}

// Function for the login page
bool resetPassword() {
    std::string username, newPassword, confirmPass;
    std::cout << "\t Enter your username: ";
    std::cin >> username;

    if (users.find(username) == users.end()) {
        std::cout << "\t Username not found. Please register or try again." << std::endl;
           Sleep(5000); // Pause for 5 seconds (5000 milliseconds)
           return false;
    }

    std::cout << "\t Enter a new password: ";
    std::cin >> newPassword;
    std::cout << "\t Confirm your new password: ";
    std::cin >> confirmPass;

    if (newPassword != confirmPass) {
        std::cout << "\t Passwords do not match. Please try again." << std::endl;
           Sleep(5000); // Pause for 5 seconds (5000 milliseconds)
        return false;
    }

    users[username] = newPassword;

    std::cout << "\t Password reset successful! You can now log in with your new password." << std::endl;
       Sleep(5000); // Pause for 5 seconds (5000 milliseconds)
    return true;
}
void loginPage() {
    bool isLoggedIn = false;

    while (!isLoggedIn) {
        system("CLS"); // Clears the screen
        std::cout << "\n\n\t\t\tLOGIN PAGE\n\n";
        std::cout << "\t 1. Login\n";
        std::cout << "\t 2. Forgot Password\n";
        std::cout << "\t Enter your choice: ";

        int loginChoice;
        std::cin >> loginChoice;

        switch (loginChoice) {
            case 1:
                isLoggedIn = login(); // Call the login function
                break;
            case 2:
                resetPassword(); // Call the password reset function
                break;
            default:
                std::cout << "\t Invalid choice. Please try again." << std::endl;
                Sleep(60000); // Pause for 1 minute (60000 milliseconds)
                break;
        }
    }

    std::cout << "\n\n\t\tRedirecting to Main Menu...\n\n";
}


int main() {
    // ... (existing code)

    title(); // Display the game name before registration and login

    bool isRegistered = false;

    while (!isRegistered) {
        cout << "\t Are you a new user? Would you like to register? (Y/N): ";
        char regChoice;
        cin >> regChoice;

        if (regChoice == 'Y' || regChoice == 'y') {
            isRegistered = registerUser();
        } else {
            isRegistered = true;
        }
    }

    // Show the login page
    loginPage();

    // ... (existing game menu loop)
    while(1)
    {
        title();
        mainmenu();
        char choice;
        cin >> choice;
        if(choice=='1')
        {
            string player_name;
            cout<<endl;
            setcolorandbackground(9,0);
            cout << "\t Enter your name: ";

            cin >> player_name;
            start_game(player_name);
            char ch;
            cin >> ch;
            while(ch!='0')
            {
                setcolorandbackground(4,0);
                cout << "\t\tPlease press '0' to go back to main menu....";
                setcolorandbackground(15,0);
                cin >> ch;
            }
            continue;
        }
        else if(choice=='2')
        {

            instructions();
            char ch;
            cin >> ch;
            while(ch!='0')
            {
                setcolorandbackground(4,0);
                cout << "\t\tPlease press '0' to go back to main menu....:  ";
                setcolorandbackground(15,0);
                cin >> ch;
            }
            continue;
        }

        else if(choice=='3')
        {

            about_us();
            char ch;
            cin >> ch;
            while(ch!='0')
            {
                setcolorandbackground(4,0);
                cout << "\t\tPlease press '0' to go back to main menu....:  ";
                setcolorandbackground(15,0);
                cin >> ch;
            }
            continue;
        }

        else    break;
    }
    return 0;
}
