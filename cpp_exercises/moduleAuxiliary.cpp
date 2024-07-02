int fatorial(int number)
{
    int fat = 1;

    for (int i = 1; i < number; i++)
    {
        fat = fat * (i + 1);
    }

    return fat;
}

int area_of_square(int side)
{
    return side * side;
}
