#include "../std_lib_facilities.h"
#include <float.h>

void task1()
{
    int num1 = 0;
    int num2 = 0;
    while (cin >> num1 >> num2)
    {
        cout << num1 << " " << num2 << endl;
        if (num1 == '|')
            break;
    }
}

void task2()
{
    int num1 = 0;
    int num2 = 0;
    while (cin >> num1 >> num2)
    {
        cout << "The smaller value is: " << min(num1, num2) << endl;
        cout << "The larger value is: " << max(num1, num2) << endl;
        if (num1 == '|')
            break;
    }
}

void task3()
{
    int num1 = 0;
    int num2 = 0;
    while (cin >> num1 >> num2)
    {
        if (num1 == num2)
        {
            cout << "The numbers are equal" << endl;
        }
        else
        {
            cout << "The smaller value is: " << min(num1, num2) << endl;
            cout << "The larger value is: " << max(num1, num2) << endl;
        }
        if (num1 == '|')
            break;
    }
}

//task4 itself is only a type change
void task5()
{
    double num1 = 0;
    double num2 = 0;
    while (cin >> num1 >> num2)
    {
        if (abs(num1 - num2) < 1.0 / 100)
        {
            cout << "The numbers are almost equal" << endl;
        }
        else
        {
            cout << "The smaller value is: " << min(num1, num2) << endl;
            cout << "The larger value is: " << max(num1, num2) << endl;
        }
        if (num1 == '|')
            break;
    }
}

void task6()
{
    double smallest = DBL_MAX;
    double largest = DBL_MIN;
    double current = 0;
    while (cin >> current)
    {
        cout << current;
        if (current > largest)
        {
            largest = current;
            cout << " the largest so far" << endl;
        }
        else if (current < smallest)
        {
            smallest = current;
            cout << " the smallest so far" << endl;
        }
        else
        {
            cout << endl;
        }
        if (current == '|')
            break;
    }
}

class InvalidUnit
{
};

double toMeter(double num, string unit)
{
    if (unit == "cm")
    {
        return num / 100.0;
    }
    else if (unit == "m")
    {
        return num;
    }
    else if (unit == "in")
    {
        return num * 0.0254;
    }
    else if (unit == "ft")
    {
        return num * 0.3048;
    }
    else
    {
        throw InvalidUnit();
    }
}

void task11()
{
    double smallest = DBL_MAX;
    double largest = DBL_MIN;
    double current = 0;
    double sum = 0;
    double count = 0;
    vector<double> elements;
    string unit;
    while (cin >> current >> unit)
    {
        double meters = toMeter(current, unit);
        if (meters > largest)
        {
            largest = meters;
        }
        else if (meters < smallest)
        {
            smallest = meters;
        }
        count++;
        sum += meters;
        elements.push_back(meters);
        if (current == '|')
            break;
    }
    sort(elements);
    cout << endl;
    cout << "Largest: " << largest << endl;
    cout << "Smallest: " << smallest << endl;
    cout << "Sum of numbers (in meter): " << sum << endl;
    cout << "Count of numbers: " << count << endl;
    cout << "Elements: " << endl;
    for (auto element : elements)
        cout << element << endl;
}

int main()
{
    //the fancy task chooser
    int task;
    cout << "Enter a task number to execute specific task: ";
    cin >> task;
    cout << endl
         << endl;

    switch (task)
    {
    case 1:
        task1();
        break;
    case 2:
        task2();
        break;
    case 3:
        task3();
        break;
    case 4:
    case 5:
        task5();
        break;
    case 6:
        task6();
        break;
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
        task11();
        break;
    default:
        cout << "Invalid task id: " << task << endl;
        break;
    }
}