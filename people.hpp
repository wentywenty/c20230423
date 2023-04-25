#ifndef people_hpp
#define people_hpp
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
class people{
    public:
        void list_all();
        void add_user();
        void remove_user();
        void level_up();
        void level_down();
        void caclu_money();
                           
    private:
        string name;
        int level;
        float money;
        string job;

};

#endif