#include <iostream>
using namespace std;

#define _MYDEBUG_

int main(){
    int nValue = 100;

    cout << "Value :" << nValue << endl;

    #ifdef _MYDEBUG_ // 위에 _MYDEBUG_ 가 정의되어 있다면 아래 코드를 실행한다. 
        cout << "Address :" << &nValue << endl;
    #endif

    return 0;
}