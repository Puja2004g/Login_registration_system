#include <iostream>
#include <fstream>
using namespace std;

bool isLoggedIn();

int main() {
    int choice;

    cout<<"1. Register"<<endl<<"2. Login"<<endl;
    cin>>choice;

    if(choice==1){
        string username, password;

        cout<<"Select a username: ";
        cin>>username;

        cout<<"Select a password: ";
        cin>>password;

        ofstream file;
        //provide the complete of the folder to create the file
        file.open("C:/Users/KIIT/OneDrive/Desktop/codes/c++/trial_files/" + username +".txt");

        file<<username<<endl<<password;

        file.close();

        main();
    }

    else if(choice==2){
        bool status = isLoggedIn();

        if(!status){
            cout<<"False login"<<endl;
            return 0;
        }

        else {
            cout<<"Successfully logged in!"<<endl;
            return 1;
        }
    }
    return 0;
}

bool isLoggedIn(){
    string username, password, un, pw;

    cout<<"Username : ";
    cin>>username;
    cout<<"Password : ";
    cin>>password;

    ifstream read("C:/Users/KIIT/OneDrive/Desktop/codes/c++/trial_files/" + username + ".txt");

    getline(read, un);
    getline(read, pw);

    if(un==username && pw==password){
        return true;
    }
    else{
        return false;
    }
}