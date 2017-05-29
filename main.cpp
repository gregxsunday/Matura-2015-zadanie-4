#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct Binary_number
{
    string number;
    size_t length;
    int ones_counter;
    int zeros_counter;
    bool divided_by_2;
    bool divided_by_8;

    Binary_number(size_t l) : length(l)
    {}

    Binary_number(string n) :
        number(n),
        length(n.size()),
        ones_counter(0),
        zeros_counter(0),
        divided_by_2(0),
        divided_by_8(0)
    {

        for(int i = 0; i < length; i++)
        {
            if(n.at(i) == '1')
                ones_counter++;
            else
                zeros_counter++;
        }

        if(n.at(n.size() - 1) == '0')
            divided_by_2 = 1;
        if(n.substr(n.size() - 3, 3) == "000")
            divided_by_8 = 1;
    }
};

bool check_if_greater(Binary_number n1, Binary_number n2) //return 1 if n1 bigger
{
    if(n1.length > n2.length)
        return 1;
    else if(n2.length > n1.length)
        return 0;
    else
    {
        for(int i = 0; i < n1.length; i++)
        {
            if(n1.number.at(i) == '1' && n2.number.at(i) == '0')
                return 1;
            else if(n2.number.at(i) == '1' && n1.number.at(i) == '0')
                return 0;
        }
    }
}

int main()
{
    fstream file;
    string line;
    int a = 0;
    int b_2 = 0, b_8 = 0;
    int line_counter = 1;
    int c_smallest, c_greatest;

    Binary_number greatest(0);
    Binary_number smallest(INT_MAX);

    file.open("Dane_PR2\\liczby.txt", ios::in);
    while(getline(file, line))
    {
        Binary_number current(line);

        if(current.zeros_counter > current.ones_counter)
           a++;

        if(current.divided_by_2)
            b_2++;

        if(current.divided_by_8)
            b_8++;

        if(check_if_greater(current, greatest))
        {
            greatest = current;
            c_greatest = line_counter;
        }
        if(check_if_greater(smallest, current))
        {
            smallest = current;
            c_smallest = line_counter;
        }

        line_counter++;
    }
    file.close();
    cout << "4.1" << endl << "Liczby z wieksza iloscia zer niz jedynek w zapisie binarnym: " << a << endl;
    cout << endl <<"4.2" << endl << "Liczby podzielne przez 2: " << b_2 << endl;
    cout << "Liczby podzielne przez 8: " << b_8 << endl;
    cout << endl << "4.3" << endl << "Linia z najwieksza liczba: " << c_greatest << endl;
    cout << "Linia z najmniejsza liczba: " << c_smallest << endl;
    return 0;
}
