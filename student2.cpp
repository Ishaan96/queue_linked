#include<iostream>
#include<string>
class student
{
public:
    std::string name;
    int roll;
    student(std::string n,int r) : name(n),roll(r){}
};
class subject1: public student
{
public:
    int marks;
    subject1(const student& s) :student(s)
    {
        std::cout << "Subject1 Marks:";
        std::cin >> marks;
    }
};
class subject2: public student
{
public:
    int marks;
    subject2(const student& s) : student(s)
    {
        std::cout << "Subject2 Marks:";
        std::cin >> marks;
    }
};
bool operator&&(const subject1& s1,const subject2& s2)
{
    return s1.marks>60 && s2.marks>60;
}
bool operator||(const subject1& s1,const subject2& s2)
{
    return s1.marks>90 || s2.marks>90;
}
class Application
{
public:
    void check(const subject1& s1,const subject2& s2) const
    {
         if(s1 && s2) {
             if (s1 || s2)
                 std::cout << s1.name <<"("<<s1.roll<<") " <<"is granted direct promotion";
             else
                 std::cout << s1.name <<"("<<s1.roll<<") " << " is allowed to apply";
         }
             else
             std::cout << "Rejected";
    }
    friend bool operator&&(const subject1& s1,const subject2& s2);
    friend bool operator||(const subject1& s1,const subject2& s2);
};
int main()
{
    student s("Ishaan",205);
    subject1 s1(s);
    subject2 s2(s);
    Application* a = new Application;
    a->check(s1,s2);
    delete a;
    return 0;
}
