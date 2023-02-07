#include <iostream>
#include <fstream>
#include <locale.h>
#include <string>

using namespace std;
class Address {
private:
    string city;
    string street;
    int house;
    int flat;

public:

    Address()
    {
        city = "0";
        street = "0";
        house = 0;
        flat = 0;
    }

    Address(string city_, string street_, int house_, int flat_)
    {
        city = city_;
        street = street_;
        house = house_;
        flat = flat_;
    }


    string get_output_address() {
        string address_string = city + ", " + street + ", " + to_string(house) + ", " + to_string(flat);
        return address_string;
    }

    string get_city() {
        return city;
    }

};

void sort(Address* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i].get_city() > arr[j].get_city()) {
                // меняем элементы местами
                Address temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
} 

void rec(Address* arr, int size, ofstream& out) {
    out << size << endl;
    for (int i = 0; i < size; i++) {
        out << arr[i].get_output_address() << " ";
        out << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    ifstream in("in.txt");
    ofstream out("out.txt");

    if (!in.is_open() || (!out.is_open())) {
        cout << "Файл не найден";
        exit(0);
    }

    int size;
    in >> size;
    string* address_book = new string[size];
    Address* address_book2 = new Address [size];
    string city;
    string street;
    int house;
    int flat;
    int i = 0; // счётчик
    while (!in.eof()) {
        in >> city;
        in >> street;
        in >> house;
        in >> flat;
        Address address(city, street, house, flat);
        address_book2[i] = address;
        i++;
    }

    in.close();
    sort(address_book2, size);
    rec(address_book2, size, out);
    delete[] address_book;
    out.close();
    return 0;

}