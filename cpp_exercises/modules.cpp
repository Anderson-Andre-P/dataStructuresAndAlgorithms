#include <iostream>
#include "moduleAuxiliary.cpp"

using namespace std;

int main()
{
    int n = 5;
    cout << "Area de um quadrado de lado igual a " << n << " é " << area_of_square(n) << "m²." << endl;
    cout << "Fatorial de " << n << " é igual a " << fatorial(5) << "." << endl;
    return 0;
}
