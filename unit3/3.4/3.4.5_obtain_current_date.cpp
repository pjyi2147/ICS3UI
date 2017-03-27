// Lab 3.4.5 by Jeongseop Yi
#include <iostream>
#include <ctime>

using namespace std;

struct Date {
    int year, month, day;
};

Date today() {
    Date today1;
    time_t t = time(NULL);
    tm t1 = *localtime(&t);
    today1.year = t1.tm_year+1900;
    today1.month = t1.tm_mon+1;
    today1.day = t1.tm_mday;
    return today1;
}

int main() {
    Date t = today();
    cout << t.year << "-" << t.month << "-" << t.day << endl;
    return 0;
}
