// CFB encrypt.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string.h>
#include <>

using namespace std;

vector<char> encrypt(string text, char key = 'a') {
    vector<char> tmp = vector<char>();
    tmp.push_back(key);
    for (auto iterator = text.begin(); iterator != text.end(); iterator++) {
        tmp.push_back(*iterator ^ tmp[0]);
        tmp[0] = *(tmp.end() - 1);
    }
    return vector<char>(tmp.begin() + 1, tmp.end());
}

vector<char> decrypt(vector<char> encrypted_text, char key = 'a') {
    vector<char> tmp = vector<char>();
    tmp.push_back(key);
    for (auto iterator = encrypted_text.begin(); iterator != encrypted_text.end(); iterator++) {
        tmp.push_back(*iterator ^ tmp[0]);
        tmp[0] = *iterator;
    }
    return vector<char>(tmp.begin() + 1, tmp.end());
}

void print(vector<char> text) {
    for (auto iterator = text.begin(); iterator != text.end(); iterator++) {
        cout << *iterator;
    }
}
int main()
{

    vector<char> tmp = vector<char>();
    
    string input_text;
    
    std::basic_istream::getline(cin, input_text);
    string temp;
    while (cin >> temp)
        input_text += " " + temp;
    input_text = string(input_text.begin() + 1, input_text.end());
    auto encrypted_text = encrypt(input_text, 'a');
    print(encrypted_text);
    cout<<endl;
    print(decrypt(encrypted_text, 'a'));

}