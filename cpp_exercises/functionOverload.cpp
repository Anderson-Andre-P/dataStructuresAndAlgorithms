#include <iostream>

using namespace std;

void message(int number)
{
    cout << "Number: " << number << endl;
}

void message()
{
    cout << "Hello!" << endl;
}

int main(int argc, char *argv[])
{
    message();
    message(5);
    return 0;
}
