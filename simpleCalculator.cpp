#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string input;
    double num1, num2, result;
    char operation, choice;

    do {
        cout << "Nhap phep tinh: ";
        getline(cin, input);

        stringstream ss(input);
        ss >> num1 >> operation >> num2;

        switch(operation) {
            case '+':
                result = num1 + num2;
                cout << result << endl;
                break;
            case '-':
                result = num1 - num2;
                cout << result << endl;
                break;
            case '*':
                result = num1 * num2;
                cout << result << endl;
                break;
            case '/':
                if(num2 != 0) {
                    result = num1 / num2;
                    cout << result << endl;
                } else {
                    cout << "Loi: Khong the chia cho 0!" << endl;
                }
                break;
            default:
                cout << "Loi: Phep tinh khong hop le!" << endl;
        }

        cout << "Ban co muon tiep tuc? (c: tiep tuc, k: thoat): ";
        cin >> choice;
        cin.ignore();

    } while (choice == 'c' || choice == 'C');

    return 0;
}