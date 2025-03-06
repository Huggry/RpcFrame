#include <bits/stdc++.h>
using namespace std;

bool isprime(const int& x){
    if(x <= 3){
        return x > 1;
    }

    int temp = sqrt(x);
    for(int i = 2; i <= temp; i++){
        if(x % i == 0){
            return false;
        }
    }

    return true;
}

int main(){
    int num;
    cin >> num;

    for(int i = 1; i <= num; i++){
        if(isprime(i)){
            cout << i << " ";
        }
    }
    cout << '\n';

    return 0;
}