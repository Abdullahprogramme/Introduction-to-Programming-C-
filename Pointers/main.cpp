#include <iostream>

using namespace std;

int sumElemenets( const int values[], const size_t nums);
int sumElements( const int* values, const size_t nums);
int* createArray(size_t nums);
int* demo();

int main()
{

    int values[] = {1, 2, 3, 4, 5};
    size_t nums = sizeof(values) / sizeof(values[0]);

    cout << sumElemenets(values, nums) << endl;
    cout << sumElements(values, nums) << endl;

    int* values2 = createArray(nums);
    cout << sumElemenets(values2, nums) << endl;

    int* values3;

    values3 = demo();

    for (size_t i = 0; i < nums; i++)
    {
        cout << values3[i] << " ";
    }

    int* values4 = demo();

    for (size_t i = 0; i < nums; i++)
    {
        cout << values4[i] << " ";
    }

    return 0;
}

int sumElemenets( const int values[], const size_t nums)
{
    int sum = 0;
    for (size_t i = 0; i < nums; i++)
    {
        sum += values[i];
    }
    return sum;
}

int sumElements( const int* values, const size_t nums)
{
    int sum = 0;
    for (size_t i = 0; i < nums; i++)
    {
        sum += values[i];
    }
    return sum;
}

int* createArray(size_t nums)
{
    int* values = new int[nums];
    for (size_t i = 0; i < nums; i++)
    {
        values[i] = i + 1;
    }
    return values;
}

int* demo()
{
    static int values[] = {1, 2, 3, 4, 5};
    return values;
}