#include <iostream>
#include <vector>
#include <string>

using namespace std;

const vector<pair<int, string>> roman = {
    {1000, "M"},
    {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
    {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"},
    {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
 };

string toRoman(int x){
    string result;
    for (int i = 0; i < roman.size(); i++){
        while (x >= roman[i].first){
            result += roman[i].second;
            x -= roman[i].first;
        }
    }
    return result;
}

int main(int argc, char** argv){
    if (argc < 2) clog << "Brak argumentow" << endl;
    for (int i = 1; i < argc; i++){
        try {
            int a = stoi(argv[i]);
            if (a < 1 || a > 3999) throw invalid_argument("nie jest z zakresu 1-3999.");
            else cout << a << " = " << toRoman(a) << endl;
        } catch (const exception &e){
            clog << "Argument '" << argv[i] << "' jest nieprawidłowy: " << e.what() << endl;
        }
    }
    return 0;
}