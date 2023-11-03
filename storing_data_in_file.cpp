#include <bits/stdc++.h>
using namespace std;
int main()

{
    string name;
    int age;

    ofstream file;
    file.open("student_details.txt",ios::out|ios::app);
    for (int i=0; i<3; i++)
        
    {

        cout << "Enter your name :" ;
        getline(cin,name);

        file <<"Name :" << name << "\n";
        cout  << "enter your age : ";
        cin>>age;

        file <<"Age:"<< age << endl;
        cin.ignore();
    }
    
    file.close();
    return 0; 
    
}
