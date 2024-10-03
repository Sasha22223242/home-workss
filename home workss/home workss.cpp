//#include <iostream>
//#include <string>
//#include <cctype>
//
//using namespace std;
//
//bool areIdentical(const string& str1, const string& str2) {
//    string filtered1, filtered2;
//
//    for (char c : str1) {
//        if (isalpha(c)) {
//            filtered1 += tolower(c); 
//        }
//    }
//
//    for (char c : str2) {
//        if (isalpha(c)) {
//            filtered2 += tolower(c); 
//        }
//    }
//
//    return filtered1 == filtered2; 
//}
//
//int main() {
//    system("chcp 1251>null");
//    string str1, str2;
//
//    cout << "������ ������ �����: ";
//    getline(cin, str1);
//    cout << "������ ������ �����: ";
//    getline(cin, str2);
//
//    if (areIdentical(str1, str2)) {
//        cout << "�������Ͳ" << endl;
//    }
//    else {
//        cout << "�� �������Ͳ" << endl;
//    }
//
//    return 0;
//}
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

bool isPasswordStrong(const string& password) {
    if (password.length() < 8) return false;

    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;
    const string specialChars = "!@#$%^&*()-_=+";

    for (char c : password) {
        if (isupper(c)) hasUpper = true;
        else if (islower(c)) hasLower = true;
        else if (isdigit(c)) hasDigit = true;
        else if (specialChars.find(c) != string::npos) hasSpecial = true;
    }

    return hasUpper && hasLower && hasDigit && hasSpecial;
}

void suggestPassword() {
    const string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+";
    string newPassword;
    srand(time(0));

    for (int i = 0; i < 12; i++) {
        newPassword += chars[rand() % chars.length()];
    }

    cout << "�������� ������������ ������� ������: " << newPassword << endl;
}

int main() {
    system("chcp 1251>null");
    string password;

    cout << "������ ������: ";
    cin >> password;

    if (isPasswordStrong(password)) {
        cout << "������ �������." << endl;
    }
    else {
        cout << "������ ���������." << endl;
        suggestPassword();
    }

    return 0;
}
