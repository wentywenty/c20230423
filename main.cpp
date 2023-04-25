#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "people.hpp"
using namespace std;


int login_system(string login_passwd){
    string enter_passwd;
    ifstream passwd_output;
    cout << "Please enter your password:";
    cin >> enter_passwd;
    if (login_passwd != enter_passwd)
    {
        for (int i = 1; login_passwd != enter_passwd; i++)
        {
            cerr << "Password is not same,please enter again:";
            cin >> enter_passwd;
            if (i == 3)
            {
                cout << "password incorrect , failed login" << endl;
                passwd_output.close();
                return 0;
            }
        }
    }
}

void recise_passwd(string login_passwd)
{
    ofstream passwd_input;
    passwd_input.open("/home/flora/Desktop/passwd.txt", ios::in);
    string login_passwd1, login_passwd2;
    do
    {
        cerr << "login passwd setup:";
        cin >> login_passwd1;
        cerr << "please enter again:";
        cin >> login_passwd2;
        if (login_passwd1 != login_passwd2)
        {
            std::cout << "Password is not same,please set password again" << endl;
        }
    } while (login_passwd1 != login_passwd2);
    passwd_input << login_passwd2;
    passwd_input.close();
    login_passwd = login_passwd2;
}

string welcome(){
    std::cout << "Welcome to person manage system.\n";
    ifstream passwd_output;
    passwd_output.open("/home/flora/Desktop/passwd.txt", ios::app);
    string enter_passwd, login_passwd;
    passwd_output >> login_passwd;
    passwd_output.close();
    
    // difine password orgin password
    if (login_passwd == "\0")
    {
        recise_passwd(login_passwd);
    }
    login_system(login_passwd);
    cout << "welcome!" << endl;
    passwd_output.close();
    return login_passwd;
}


int main()
{
    string login_passwd=welcome();
    ifstream user_output;
    user_output.open("/home/flora/Desktop/user.txt", ios::app);
    user_output.close();
    int mode;
    do
    {
        cout << "please switch mode:\n"
             << "mode 1:list all people\n"
             << "mode 2:input people message\n"
             << "mode 3:delete people message\n"
             << "mode 4:level up or down people\n"
             << "mode 5:recise password\n"
             << "mode 6:caclucate saleray\n"
             << "mode 7:safe exit this program\n"
             << "please enter:";
        cin >> mode;
        if(mode!= 1&&mode!=2&&mode!=3&&mode!=4&&mode!=5&&mode!=6&&mode!=7){
            cout<<"error: invalid mode"<<endl;
            continue;
        }
        switch (mode)
        {
        case 1: {
            people list_all_people;
            list_all_people.list_all();
        }break;
        
        case 2:
        {
            people new_people; 
            new_people.add_user();
        }break;

        case 3:{
            people remove_people;
            remove_people.remove_user();
        }break;
        case 4:{
            people level_people;
            level_people.list_all();
            cout<<"up mode:1\ndown mode:2\ninput:";
            int level_mode;
            cin>>level_mode;
            if(level_mode!=1&&level_mode!=2)
            {
                cout<<"error"<<endl;
                continue;
            }
            if(level_mode==1)
                level_people.level_up();
            if(level_mode==2)
                level_people.level_down();
        }break;

        case 5:
        {
            login_system(login_passwd);
            recise_passwd(login_passwd);
        }break;

        case 6:
        {
           people caclu;
           caclu.caclu_money();
        }break;

        case 7:
            break;
        
        default:
            cout << "error: unknown mode" << endl;
            break;
        }
        
    } while (mode == 1||mode==2||mode==3||mode==4||mode==5||mode==6);

    return 0;
}