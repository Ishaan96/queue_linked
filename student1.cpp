#include<iostream>
#include<string>
class student
{
private:
    std::string name;
    int roll,marks;
public:
    student() {
        std::cout << "Name:";
        std::cin >> name;
        std::cout << "Roll:";
        std::cin >> roll;
        std::cout << "Marks:";
        std::cin >> marks;
    }
    bool operator>(student& s) const;
    bool operator<(student& s) const;
};
bool student::operator>(student& s) const {
    if (this->marks > s.marks)
        return true;
    else
        return false;
}
bool student::operator<(student& s) const {
    if (this->marks < s.marks)
        return true;
    else
        return false;
}
int main()
{
    student s1;
    student s2;
    std::cout << std::boolalpha << (s2>s1);
    return 0;
}
