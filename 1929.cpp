//
//  1929.cpp
//  Session0412
//
//  Created by 최동진 on 2017. 4. 12..
//  Copyright © 2017년 최동진. All rights reserved.
//
//  소수구하기
//

/*
#include <iostream>
#include <string.h>
using namespace std;

int N,M;
bool chk[1000001];

int main() {
    cin >> N >> M;
    memset(chk, false, sizeof(chk));
    
    for(int i = 2; i <= M; i++) {
        bool not_prime = false;
        for(int j = 2; j <= i/2; j++) {
            if(i % j == 0)
                not_prime = true;
        }
        
        if(!not_prime)
            chk[i] = true;
    }
    
    for(int i = N; i <= M; i++) {
        if(chk[i])
            cout << i << "\n";
    }
    
    return 0;
}
*/



// 에라토네스의 체
 
#include <iostream>
using namespace std;

int N, M;
int arr[1000001];


void func(int num) {
    for (int i = 2; i*i <= num; i++) {
        if (arr[i] == 0) // 이미 체크된 수의 배수는 확인하지 않는다
            continue;
        for (int j = i + i; j <= num; j += i) { // i를 제외한 i의 배수들은 0으로 체크
            arr[j] = 0;
        }
    }
    
    for (int i = N; i<= num; i++) {
        if (arr[i] != 0)
            cout << arr[i] << "\n";
    }
}

int main(void) {
    cin >> N >> M;
    
    for (int i = 2; i <= M; i++) {
        arr[i] = i;
    }
    
    func(M);
}
