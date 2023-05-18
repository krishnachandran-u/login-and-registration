#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>

using namespace std;

bool DidLogin(); //Checks whether the login is successful or unsuccessful
void registration(); //Registers the username and password entered by the user

int main(){

    int choice;

    cout << "1 -> Registration\n2 -> Login"<<endl;
    cout << "Select choice: "; cin>>choice; cout<<"\n";

    //Calls registration(), hence performs the registration and calls the main function again so as to decide whether to register again or login.
    if(choice == 1){

        registration();

        main();

    }

    //Calls DidLogin() which returns true or false based on the status of login.
    if(choice == 2){

        if(!DidLogin()){

            cout<< "\nFalse Login!" <<endl;
            system("pause");
            return 0;

        }
        else{

            cout << "\nLogged in Succcessfully!" <<endl;
            system("pause");
            return 1;

        }
    }

    else exit(1);

}

bool DidLogin(){

    string username, password, usercheck, passcheck;

    //Asks the user for credentials

    cout << "Enter username: " ; cin >> username;
    cout << "Enter password: " ; cin >> password;

    //Reads the username.txt file, if present and checks whether the credentials entered by the user and the stored credentials are the same.

    ifstream readfile("credentials\\" + username + ".txt");

    //Each time getline() is called, it reads input from the next line in the text file.

    getline(readfile, usercheck);
    getline(readfile, passcheck);

    if(usercheck == username && passcheck == password) return true;
    else return false;

}

void registration(){

    string username, password;

    cout << "Enter username: " ; cin >> username;
    cout << "Enter password: " ; cin >> password; cout<<"\n";

    //The username and password is written into a dedicated username.txt file in the consecutive lines.

    ofstream writefile;

    writefile.open("credentials\\" + username + ".txt");
    writefile << username <<endl<< password;
    writefile.close();

}
