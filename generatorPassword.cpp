#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <fstream>

using namespace std;

void passwdGenerator(int sizepassw, string nameServicePasswd, string skipped){
    string dict = " !'#$%&\()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"; //строка содержит все доступные символы
    string passwd = "";
    for(int i = 0; i < sizepassw; i++) {
        int pointerx = 0;
        char c = dict[rand() % dict.size()]; //в переменную с записывается случайный из них
        for (int j = 0; j < skipped.size(); j++) {
            if (c != skipped[j])
                continue;
            else
                pointerx++;
                break;
        }
        if (pointerx != i)
        passwd += c;
    }
    cout << passwd << endl;
    ofstream myfile;
    myfile.open("password.txt",ios::out  | ios::app ) ;
    myfile << nameServicePasswd  << ':' << passwd<<"\n";
    myfile.close();
    
}

int main() {
    setlocale(LC_ALL, "rus");
    srand(time(NULL));    
    const int iSizepasswd = rand() % 14 + 8;
    string servicePasswd;
    cout << "Введите для какого сервиса вам пароль: ";
    cin >> servicePasswd;
    cout << "Какие символы пропускать: ";
    string symbolskip;
    cin >> symbolskip;
    passwdGenerator(iSizepasswd, servicePasswd, symbolskip);
}