#include <iostream>

using namespace std;

bool par(int number)
{
    if (number % 2 == 0)
        return true;
    return false;
}

int main(int argc, char *argv[])
{
    int n;

    cout << "Type an number: ";
    cin >> n;

    if (par(n))
        cout << "The number " << n << " is pair!" << endl;
    else
        cout << "Tte number " << n << " not is pair!" << endl;
    return 0;
}
