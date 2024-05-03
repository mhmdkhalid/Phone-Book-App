#include <iostream>
#include <string>
#include <algorithm>
#include<string.h>
#include <limits>
using namespace std;

class phoneBook{

private:
    string* names;
    string* phones;
    int phoneBookSize;
    int count = 0;

public:
    void setSize(int size){
        phoneBookSize = size;
        names = new string [phoneBookSize];
        phones = new string [phoneBookSize];
    }
    bool isPhoneValid(string s){
        for(int i = 0 ; i<s.length();i++){
            if(s[i]!='0' && s[i]!='1' && s[i]!='2' && s[i]!='3' && s[i]!='4' && s[i]!='5' && s[i]!='6' && s[i]!='7' && s[i]!='8' && s[i]!='9')
                return false;
        }
        return true;
    }

    bool addEntry(string name, string phone){
        if(isPhoneValid(phone) && phone.length()==11){
            phones[count]=phone;
            names[count]=name;
            ++count;
            return true;
        }
        else {
            cout<<"The number you entered is not valid, Please try again"<<endl;
            return false;
        }
    }

    bool displayEntryAtIndex(int index) {
        if (index < phoneBookSize && index >= 0) {
            cout << "Name is:  " << names[index] << endl << "Number is:  " << phones[index]<<endl;
            return true;
        } else {
            cout << "The index you entered is not valid, Please try again" << endl;
            return false;
        }
    }

    void displayEntryAtIndices(int* indices){
        indices = new int [phoneBookSize];
        for (int i = 0 ; i<phoneBookSize ; i++){
            if(indices[i]=1){
                cout<<names[i]<<"   "<<phones[i]<<endl;
            }
        }
    }

    void displayAll(){
        for(int i = 0; i<phoneBookSize; i++){
            cout<<names[i]<<"   "<<phones[i]<<endl;
        }
    }


    int* findByName(string nameFind) {
        int* matches = new int[phoneBookSize];

        for (int i = 0; i < phoneBookSize; i++) {
            if (names[i].find(nameFind) != -1) {
                matches[i] = 1;
                cout<<"Name: "<<names[i]<<" Phone: "<<phones[i]<<endl;
            }
            else {
                matches[i] = 0;
            }
        }

        return matches;
    }


    string findByPhone(string FBphone){
        for (int i = 0; i<phoneBookSize; i++){
            if (FBphone == phones[i]) {
                return names[i];
            }
        }
        return "";
    }

    bool updateNameAt(string name, int index){
        if (index >= 0 && index < phoneBookSize){
            names [index] = name;
            return true;
        }
        return false;
    }

    bool updatePhoneAt(string phone, int index){
        if (index >= 0 && index < phoneBookSize){
            phones [index] = phone;
            return true;
        }
        return false;
    }


    void copyPB(const phoneBook& pb2) {
        phoneBookSize = pb2.phoneBookSize ;
        names = new string [phoneBookSize];
        phones = new string [phoneBookSize];
        for (int i = 0; i < phoneBookSize; i++) {
            names[i]= pb2.names[i];
            phones[i]= pb2.phones[i];
        }
    }

    void clear() {
            delete[] names;
            names = nullptr;
            delete[] phones;
            phones = nullptr;
            phoneBookSize = 0;
    }

};

int main() {

    phoneBook PB1, PB2;
    cout << "Enter the size of your phone book: ";
    int s;
    cin >> s;
    cin.ignore();

    PB1.setSize(s);

    string name, phone;

    for (int i = 1; i <= s; i++) {
        string name, phone;

        cout << "Enter Name " << i << ": ";
        getline(std::cin, name);

        cout << "Enter Phone " << i << ": ";
        getline(std::cin, phone);

        PB1.addEntry(name, phone);
    }


    int choice;
    while (choice != 8) {
        cout << "1- Display all phone book\n"
             << "2- Search for entry/entries by name\n"
             << "3- Search for entry/entries by phone\n"
             << "4- Find an entry by index\n"
             << "5- Update name by index\n"
             << "6- Update phone by index\n"
             << "7- Copy phone book to another and display entries of the new phone book\n"
             << "8- Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        string findName;
        string FBphone;
        int index =0;
        string updatedName;
        string updatedPhone;
        switch (choice) {
            case 1:
                PB1.displayAll();
                break;

            case 2:
                cout << "Enter the name or part of a name to search: ";
                cin >> findName;
                PB1.findByName(findName);
                break;

            case 3:
                cout<<"Enter the phone you're looking for: ";
                cin>>FBphone;
                cout<<"His/her name is: "<<PB1.findByPhone(FBphone)<< endl;
                break;

            case 4:
                cout<<"Enter the index of the contact you're looking for: ";
                cin>>index;
                PB1.displayEntryAtIndex(index);
                break;

            case 5:
                cout<<"Enter the index of the contact you want to update: ";
                cin>>index;
                cin.ignore();
                cout<<"Enter the name you want to update to: ";
                getline(cin,updatedName);
                PB1.updateNameAt(updatedName,index);
                break;

            case 6:
                index=0;
                cout<<"Enter the index of the contact you want to update: ";
                cin>>index;
                cout<<"Enter the phone number you want to update to: ";
                cin>>updatedPhone;
                PB1.updatePhoneAt(updatedPhone,index);
                break;

            case 7:
                PB2.copyPB(PB1);
                PB2.displayAll();
//                PB1.clear();
                break;

            case 8:
                PB1.clear();
                break;

        }

    }

    return 0;
}