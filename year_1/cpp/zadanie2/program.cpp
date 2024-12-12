#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

std::vector<int64_t> rozklad(int64_t n){
    std::vector<int64_t> factors;
    if(n <= 1 && n >= -1) return factors;

    if(n < -1){
        n *= -1;
        factors.push_back(-1);
    }

    while(n % 2 == 0){
        factors.push_back(2);
        n /= 2;
    }

    for (int64_t i = 3; i <= sqrt(n); i += 2){
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    if(n > 2) factors.push_back(n);
    return factors;
}


int main(int argc, char** argv){
    if(argc < 2){
        cerr << "Nie podano żadnego argumentu w argumentach wywołania." << endl << "Aby program zadziałał, wpisz: " << argv[0] << " liczba1, liczba2, ..." << endl;
        return 0;
    }

    for(int i = 1; i < argc; i++){
        try{
            int64_t a = stoll(argv[i]);
            vector<int64_t> czynniki = rozklad(a);
            
            cout << a << " = ";
            if(czynniki.empty()){
                cout << a;
            }

            for(int j = 0; j < czynniki.size(); j++){
                cout << czynniki[j];
                if(j < czynniki.size() - 1) cout << " * ";
            }
            cout << endl;
        }
        catch(exception& e){
            clog << "Niepoprawny argument: " << argv[i] << endl;
        }
    }
    
    return 0;
}   