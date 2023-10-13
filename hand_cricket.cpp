#include<bits/stdc++.h>
#include<time.h>
#include<string.h>
#include<windows.h>
using namespace std;

void setcolorandbackground(int textc,int backg){          //with this we can set text color and background color
    WORD color = ((backg & 0x0F)<<4) + (textc & 0x0F);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}

void title(){      //prints title of the program
    system("CLS");
    cout << endl;
    setcolorandbackground(9,0);  //  void SetColorAndBackground (int FontC, int BackC)
    cout << "\t\t\t|******************************************|\n" << endl;
    cout << "\t\t\t ";
    setcolorandbackground(9,0);
    cout << "\t Welcome  to  Hand  Cricket!!"<<endl<<endl<<endl;
    setcolorandbackground(9,0);  //Green color
    cout << "\t\t\t|******************************************|\n" << endl;


}

void mainmenu(){//Function for printing Main menu options
    setcolorandbackground(6,0);
    cout << "\n\n\t\t";
    setcolorandbackground(9,15);
    cout << "\t\t\tMAIN MENU";
    setcolorandbackground(9,0);
    cout << "\n\n\t\t\t\t1.Start a new game" << endl;
    cout << "\n\t\t\t\t2.Instructions" << endl;
    cout << "\n\t\t\t\tPress any other key to exit the game" << endl;
    cout << "\n\t\t\t\tEnter your Choice: ";
    setcolorandbackground(15,0);
}

void instructions(){
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

bool toss(string player_name){                   //returns if the player has won the toss or not
     system("CLS");
    char choice;
    int t,c;
    setcolorandbackground(4,15);
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
    if((t==1&&c==1 )||(t==2&&c==2)){
        setcolorandbackground(10,0);
        cout << "\n\n===================== \tCongratulations! "<<player_name<<". You Have Won The Toss\t ==========================" << endl;
        return true;
    }else{
        setcolorandbackground(12,0);
        cout << "\n\n\t==================== \tSorry,"<<player_name<<". You Have Lost The Toss\t =======================" << endl;
        return false;
    }
}

int player(){   //asks player to enter his score/choice
    int res;
    setcolorandbackground(14,0);
    cout << "\n\tChoose a number between 1 and 6: ";
    while(1){
        cin >> res;
        if(res>6||res<1){
            setcolorandbackground(12,0);
            cout << "\tPlease select a number between 1 and 6: ";
            continue;
        }else break;
    }
    return res;
}

int comp(){ //generates random number between 1 and 6
    int res;
    res = rand()%6+1;
    setcolorandbackground(12,0);
    cout << "\n\tYour opponent's choice is: " << res << endl;
    return res;
}

void start_game(string player_name){
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
    while(1){   //calculate total number of balls in an innings based on match format
        if(overs==1){
            balls = 6;
            break;
        }else if(overs==2){
            balls = 12;
            break;
        }else if(overs==5){
            balls = 30;
            break;
        }else{
            setcolorandbackground(4,0);
            cout << "\n\tPlease select a valid format!";
            continue;
        }
    }
    bool tossres = toss(player_name),out=false;
    if(tossres){    //based on toss result player gets to choose his choice
            setcolorandbackground(11,0);
        cout << "\n\tSelect your choice:\n\t1.Batting\t\t2.Bowling\n\t";
        cout << "Select ( 1 or 2 ) :";
        cin >> choice;
        if(choice==1){
            bat = "player";
            bowl = "comp";
        }else{
            bat = "comp";
            bowl = "player";
        }
    }else{
        choice = rand()%2+1;
        if(choice==1){
            cout << "\n\tYour opponent chose to Bat first!";
            bat = "comp";
            bowl = "player";
        }else{
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
    while((!out)&&(b<balls)){   //First Innings
        t1=player();
        t2=comp();
        if(t1==t2) {
            out = true;
            setcolorandbackground(4,15);
            cout << "\n\tIt's OUT!!!\n";
        }
        else{
            if(bat=="player") player_score += t1;
            else comp_score += t2;
        }
        b++;
    }
    //Before second innings need to change bat and bowl
    if(bat=="player"){
        bat = "comp";
        bowl = "player";
        first = player_score;
        int Target=1+first;
        setcolorandbackground(4,0);
        cout << "\n\tFirst Innings Ended!!\n";
        setcolorandbackground(9,0);
        cout<<"\n\tYour Score is "<< first <<endl;
         cout<<"\n\tTarget is: "<< Target <<endl;
        setcolorandbackground(9,0);
        cout << "\n\n\t\t\t\t";
        setcolorandbackground(9,15);
        cout << "SECOND INNINGS";
        setcolorandbackground(10,0);
        cout << "\n\n================================  "<<player_name<<" You are Bowling Now!!  ====================================";
    }else{
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
        setcolorandbackground(14,13);
        cout << "SECOND INNINGS";
        setcolorandbackground(9,0);
        cout << "\n\n---------------------------------"<<player_name<<" You are Batting Now!!---------------------------------";
    }
    out = false;
    b=0;

    while((!out)&&(b<balls)&&(second<=first)){//Second Innings

        t1=player();
        t2=comp();
        if(t1==t2){
            out = true;
            setcolorandbackground(4,0);
            cout << "\n\tIt's OUT!!!\n";
        }
        else{
            if(bat=="player") {
                player_score += t1;
                second+=t1;
            }else{
                comp_score += t2;
                second+=t2;
            }
        }
        b++;
    }
    if(bat=="player"){
        setcolorandbackground(4,0);
        cout << "\n\tSecond Innings Ended!!\n";
        setcolorandbackground(10,0);
        cout <<"\n\tYour Score is "<< second <<endl;
        setcolorandbackground(9,0);
        cout <<"=============================================================================================================";
        setcolorandbackground(6,0);
        cout << "\n\n\t\t\t\t\t";
        setcolorandbackground(14,13);
        cout << "RESULT";
        if(first>second) {
            setcolorandbackground(4,0);
            cout << "\n\n\t\t\t\t"<<player_name<<" You Lost the Match!!";
             setcolorandbackground(10,0);//Green color
            cout << "\n\n\t\t\t\t  Better Luck next time";
        }else if(first == second) {
            setcolorandbackground(14,0);
            cout << "\n\n\t\t\t\t Match Draw!!";
        }else{
            setcolorandbackground(10,0);
            cout << "\n\n\t\t\t\t"<<player_name<<"Hurray You Won the Match!!";
            cout << "\n\n\t\t\t\t"<<player_name<<" Your Guessing power is good!!";
        }
    }else{
        setcolorandbackground(4,0);
        cout << "\n\tSecond Innings Ended!!\n\n";
        setcolorandbackground(10,0);
        cout <<"\tYour Opponent's Score is "<< second <<endl;
        setcolorandbackground(9,0);
        cout <<"=============================================================================================================";
        setcolorandbackground(6,0);
        cout << "\n\n\t\t\t\t\t";
        setcolorandbackground(14,13);
        cout << "RESULT";
        if(first>second) {
            setcolorandbackground(10,0);
            cout << "\n\n\t\t\t\t  Hurray!"<<player_name<<" You Won the Match!!";
              cout << "\n\n\t\t\t\t"<<player_name<<" your Guessing power is good!!";
        }else if(first == second) {
            setcolorandbackground(14,0);
            cout << "\n\n\t\t\t\t Match Draw!!";
        }else {
            setcolorandbackground(4,0);
            cout << "\n\n\t\t\t\t"<<player_name<<"  Lost the Match!!";
             setcolorandbackground(10,0);//Green color
            cout << "\n\n\t\t\t\t  Better Luck next time";
        }
    }
    setcolorandbackground(9,0);
    cout <<"\n\n=============================================================================================================";
    setcolorandbackground(10,0);
    cout << "\n\n\tPress '0' to go back to main menu....";
    setcolorandbackground(15,0);
}

int main(){
    while(1){
        title();
        mainmenu();
        char choice;
        cin >> choice;
        if(choice=='1'){
            string player_name;
            cout<<endl;
             setcolorandbackground(10,0);//Green color
         cout << "\tEnter your name:";
            cin >> player_name;
            start_game(player_name);
            char ch;
            cin >> ch;
            while(ch!='0'){
                setcolorandbackground(4,0);
                cout << "\t\tPlease press '0' to go back to main menu....";
                setcolorandbackground(15,0);
                cin >> ch;
            }
            continue;
        }else if(choice=='2'){
            instructions();
            char ch;
            cin >> ch;
            while(ch!='0'){
                setcolorandbackground(4,0);
                cout << "\t\tPlease press '0' to go back to main menu....:  ";
                setcolorandbackground(15,0);
                cin >> ch;
            }
            continue;
        }else    break;
    }
    return 0;
}
