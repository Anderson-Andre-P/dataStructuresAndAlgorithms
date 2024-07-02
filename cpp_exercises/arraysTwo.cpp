#include <iostream>

using namespace std;

int main()
{
    char name[] = {'I',
                   'R',
                   'I',
                   'S', '\0'};

    int i = 0;

    while (name[i])
    {
        cout << name[i] << endl;
        i++;
    }

    cout << name << endl;

    cout << "Espaço ocupado pelo array: " << sizeof(name) << " bytes." << endl;
    cout << "Quantidade de elementos no array: " << sizeof(name) / sizeof(name[1]) << " elementos." << endl;

    return 0;
}
