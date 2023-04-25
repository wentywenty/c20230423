#include "people.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> list_line;

void people::list_all()
{
    vector<string> temp_line;
    ifstream user_output;
    user_output.open("/home/flora/Desktop/user.txt", ios::app);
    cout << setiosflags(ios::left) << setw(15) << "number"
         << setiosflags(ios::left) << setw(15) << "level"
         << setiosflags(ios::left) << setw(17) << "job"
         << setiosflags(ios::left) << setw(15) << "name" << endl;
    // cacluate line
    int n = 0;
    string tmp;
    while (getline(user_output, tmp, '\n'))
    {
        temp_line.push_back(tmp);
        n++;
    }
    sort(temp_line.begin(), temp_line.end());
    for (int i = 0; i < n; i++)
        cout << setiosflags(ios::left) << setw(15) << i + 1 << temp_line[i] << endl;
    list_line.clear();
    list_line = temp_line;
    temp_line.clear();
    user_output.close();
}

void people::add_user()
{
    ofstream user_input;
    user_input.open("/home/flora/Desktop/user.txt", ios::app);
    cout << "name:";
    cin >> name;
    cout << "what job?" << endl
         << "1.zong_jinli" << endl
         << "2.jishu_jinli" << endl
         << "3.jishu_people" << endl
         << "4.xiaoshou_jinli" << endl
         << "5.xiaoshou_people" << endl;
    int temp;
    cin >> temp;
    if (temp == 1)
    {
        level = 4;
        job = "zong_jinli";
    }
    if (temp == 2)
    {
        level = 3;
        job = "jishu_jinli";
    }
    if (temp == 3)
    {
        level = 2;
        job = "jishu_people";
    }
    if (temp == 4)
    {
        level = 3;
        job = "xiaoshou_jinli";
    }
    if (temp == 5)
    {
        level = 1;
        job = "xiaoshou_people";
    }
    if (temp != 6 || temp != 5 || temp != 4 || temp != 3 || temp != 2 || temp != 1)
        cout << "error" << endl;
    user_input << setiosflags(ios::left) << setw(15) << level
               << setiosflags(ios::left) << setw(17) << job
               << setiosflags(ios::left) << setw(15) << name << endl;
    user_input.close();
}

void people::remove_user()
{
    list_all();
    cout << "remove_user_number:";
    int user_number;
    cin >> user_number;
    list_line.erase(list_line.begin() + user_number - 1);
    ofstream user_input;
    user_input.open("/home/flora/Desktop/user.txt", ios::trunc);
    for (int i = 0; i < list_line.size(); i++)
    {
        user_input << list_line[i] << endl;
    }
    user_input.close();
}

void people::level_up()
{
    cout << "level_up_number:";
    int user_number;
    cin >> user_number;
    for (;;)
    {
        if (list_line.at(user_number - 1)[0] == '3' && list_line.at(user_number - 1)[15] == 'j')
        {
            list_line.at(user_number - 1) = list_line.at(user_number - 1).replace(list_line.at(user_number - 1).begin(), list_line.at(user_number - 1).begin() + 30, "4              zong_jinli     ");
            break;
        }
        if (list_line.at(user_number - 1)[0] == '3' && list_line.at(user_number - 1)[15] == 'x')
        {
            list_line.at(user_number - 1) = list_line.at(user_number - 1).replace(list_line.at(user_number - 1).begin(), list_line.at(user_number - 1).begin() + 30, "4              zong_jinli     ");
            break;
        }
        if (list_line.at(user_number - 1)[0] == '2' && list_line.at(user_number - 1)[15] == 'j')
        {
            list_line.at(user_number - 1) = list_line.at(user_number - 1).replace(list_line.at(user_number - 1).begin(), list_line.at(user_number - 1).begin() + 30, "3              jishu_jinli    ");
            break;
        }
        if (list_line.at(user_number - 1)[0] == '1' && list_line.at(user_number - 1)[15] == 'x')
        {
            list_line.at(user_number - 1) = list_line.at(user_number - 1).replace(list_line.at(user_number - 1).begin(), list_line.at(user_number - 1).begin() + 30, "3              xiaoshou_jinli ");
            break;
        }
        cout << "error!" << endl;
        break;
    }
    sort(list_line.begin(), list_line.end());
    ofstream user_input;
    user_input.open("/home/flora/Desktop/user.txt", ios::trunc);
    for (int i = 0; i < list_line.size(); i++)
    {
        user_input << list_line[i] << endl;
    }
    user_input.close();
}

void people::level_down()
{
    cout << "level_down_number:";
    int user_number;
    cin >> user_number;
    for (;;)
    {
        if (list_line.at(user_number - 1)[0] == '4' && list_line.at(user_number - 1)[15] == 'z')
        {
            cout << "1.jishu_jinli\n2.xiaoshou_jinli\nlevel_down_choose:";
            int choose;
            cin >> choose;
            if (choose != 1 && choose != 2)
            {
                cout << "error!!" << endl;
                break;
            }
            if (choose == 1)
            {
                list_line.at(user_number - 1) = list_line.at(user_number - 1).replace(list_line.at(user_number - 1).begin(), list_line.at(user_number - 1).begin() + 30, "3              jishu_jinli    ");
            }
            if (choose == 2)
            {
                list_line.at(user_number - 1) = list_line.at(user_number - 1).replace(list_line.at(user_number - 1).begin(), list_line.at(user_number - 1).begin() + 30, "3              xiaoshou_jinli ");
            }
            break;
        }
        if (list_line.at(user_number - 1)[0] == '3' && list_line.at(user_number - 1)[15] == 'j')
        {
            list_line.at(user_number - 1) = list_line.at(user_number - 1).replace(list_line.at(user_number - 1).begin(), list_line.at(user_number - 1).begin() + 30, "2              jishu_people   ");
            break;
        }
        if (list_line.at(user_number - 1)[0] == '3' && list_line.at(user_number - 1)[15] == 'x')
        {
            list_line.at(user_number - 1) = list_line.at(user_number - 1).replace(list_line.at(user_number - 1).begin(), list_line.at(user_number - 1).begin() + 30, "1              xiaoshou_people");
            break;
        }
        cout << "error!" << endl;
        break;
    }
    sort(list_line.begin(), list_line.end());
    ofstream user_input;
    user_input.open("/home/flora/Desktop/user.txt", ios::trunc);
    for (int i = 0; i < list_line.size(); i++)
    {
        user_input << list_line[i] << endl;
    }
    user_input.close();
}

void people::caclu_money()
{
    int zong_money;
    cout << "input money:";
    cin >> zong_money;

    vector<string> temp_line;
    ifstream user_output;
    user_output.open("/home/flora/Desktop/user.txt", ios::app);
    int n = 0;
    string tmp;
    while (getline(user_output, tmp, '\n'))
    {
        temp_line.push_back(tmp);
        n++;
    }
    sort(temp_line.begin(), temp_line.end());
    user_output.close();

    cout << setiosflags(ios::left) << setw(15) << "number"
         << setiosflags(ios::left) << setw(15) << "level"
         << setiosflags(ios::left) << setw(17) << "job"
         << setiosflags(ios::left) << setw(15) << "name"
         << setiosflags(ios::left) << setw(15) << "salary"
         << endl;

    for (int i = 1; i <= temp_line.size(); i++)
    {
        if (temp_line.at(i - 1)[0] == '4' && temp_line.at(i - 1)[15] == 'z')
        {
            temp_line.at(i - 1) += to_string(20000 + zong_money / 10);
        }
        if (temp_line.at(i - 1)[0] == '3' && temp_line.at(i - 1)[15] == 'j')
        {
            temp_line.at(i - 1) +=to_string(12000 + zong_money / 10);
        }
        if (temp_line.at(i - 1)[0] == '3' && temp_line.at(i - 1)[15] == 'x')
        {
            temp_line.at(i - 1) +=to_string(10000+zong_money / 10);
        }
        if (temp_line.at(i - 1)[0] == '2' && temp_line.at(i - 1)[15] == 'j')
        {
            temp_line.at(i - 1) +=to_string(10000+zong_money/20);
        }
        if (temp_line.at(i - 1)[0] == '1' && temp_line.at(i - 1)[15] == 'x')
        {
            temp_line.at(i - 1) +=to_string(8000+zong_money/100);
        }
        cout << setiosflags(ios::left) << setw(15) << i << temp_line.at(i - 1) << endl;
        
    }
    temp_line.clear();
}
