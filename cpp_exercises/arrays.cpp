#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int array[5];

    for (int i = 0; i < 5; i++)
    {
        array[i] = i + 1;
        cout << array[i] << endl;
    }

    cout << "Espaço ocupado pelo array: " << sizeof(array) << " bytes." << endl;
    cout << "Quantidade de elementos no array: " << sizeof(array) / sizeof(array[1]) << " elementos." << endl;

    return 0;
}
