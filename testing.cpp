#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Employee
{
private:
    int age;
    std::string name;
public:
    void change_age(int _age)
    {
        age = _age;
    }
    void change_name(std::string _name)
    {
        name = _name;
    }
};
class Coder: public Employee
{
private:
    std::string favourie_language;
public:
    void change_pr(std::string _fav)
    {
        favourie_language = _fav;
    }
};
int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
    }