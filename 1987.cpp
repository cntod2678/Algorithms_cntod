//
//  1987.cpp
//  Session0412
//
//  Created by 최동진 on 2017. 4. 12..
//  Copyright © 2017년 최동진. All rights reserved.
//
//  알파벳
//


#include <iostream>
#include <algorithm>
using namespace std;

int R,C;
char m[21][21];
char ans[401];
int ret = 0;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void func(int x, int y, int cnt) {
    bool chk = false;
    for(int i = 0; i < cnt; i++) {
        if(ans[i] == m[y][x])
            chk = true;
    }
    
    if(!chk) {
        ans[cnt] = m[y][x];
        ret = max(cnt, ret);
        
        int tempX, tempY;
        for(int i = 0; i < 4; i++) {
            tempX = x + dx[i];
            tempY = y + dy[i];
            if(tempX >= 1 && tempX <= C && tempY >= 1 && tempY <= R)
                func(tempX, tempY, cnt+1);
        }
    }
    
    return;
}

int main() {
    cin >> R >> C;
    
    char c;
    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            cin >> c;
            m[i][j] = c;
        }
    }
    
    func(1,1,1);
    cout << ret << "\n";
    
    
    return 0;
}


