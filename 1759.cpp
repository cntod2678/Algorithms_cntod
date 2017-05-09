//
//  1759_2.cpp
//  Session0412
//
//  Created by 최동진 on 2017. 4. 12..
//  Copyright © 2017년 최동진. All rights reserved.
//
//  암호만들기
//


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

char arr[20];
char ans[16];
int visit[200];
int L, C;

void func(int cur, int a, int b, int cnt) {
    if(cnt == L) {
        if(a >= 1 && b >= 2) {
            cout << ans << "\n";
        }
        return;
    }
    
    for(int i = cur; i < C; i++) {
        ans[cnt] = arr[i];

        if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'o' || arr[i] == 'i' || arr[i] == 'u') {
            func(i+1, a+1, b, cnt+1);
        } else {
            func(i+1, a, b+1, cnt+1);
        }
 
    }

}

int main() {
    cin >> L >> C;
    
    for(int i = 0; i < C; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+C);
    func(0,0,0,0);
    
    return 0;
}

