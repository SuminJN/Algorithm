#include <iostream>
#include <ctime>

using namespace std;

int main(){
    time_t timer = time(NULL);
    struct tm* t = localtime(&timer);

    printf("%04d-%02d-%02d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);

    return 0;
}