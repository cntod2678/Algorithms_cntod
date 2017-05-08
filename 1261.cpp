//
//  1261.cpp
//  Session01
//
//  Created by 최동진 on 2017. 4. 1..
//  Copyright © 2017년 최동진. All rights reserved.
//
//  알고스팟
//

#include <algorithm>
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int adj[101][101];
bool visit[101][101];
int check[101][101];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

struct point {
    int x, y;
    point(int _x, int _y) {
        x = _x;
        y = _y;
    }
};

struct cmp {
    bool operator()(point u, point y) {
        return adj[u.y][u.x] < adj[y.y][y.x];
    }
};

priority_queue< int, vector<int>, cmp > q;

int main() {
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++) {
            check[i][j] = 0;
        }
    }
    
    point p(1,1);
    
    q.push(p);
    
    int dot;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            scanf("%1d", &dot);
            adj[i][j] = dot;
        }
    }
    
    while(!q.empty()) {
        int frontX = q.top().first;
        int frontY = q.top().second;
        
        q.pop();
        
        if(n == frontX && m == frontY) {
            break;
        }
        
        int tempX, tempY;
        for (int i = 0; i < 4; i++) {
            tempX = frontX + dx[i];
            tempY = frontY + dy[i];
            
            if (tempX <= n && tempY <= m && tempX > 0 && tempY > 0) {
    
                if(adj[tempY][tempX] == 0) {
                    if(!visit[tempY][tempX]) {
                        visit[tempY][tempX] = true;
                        check[tempY][tempX] = check[frontY][frontX];
                        q.push(make_pair(tempX, tempY));
                    }
                    else {
                        if(check[frontY][frontX] < check[tempY][tempX])
                            check[tempY][tempX] = check[frontY][frontX];
                    }
                } else {
                    if(!visit[tempY][tempX]) {
                        check[tempY][tempX] = check[frontY][frontX] +1;
                        visit[tempY][tempX] = true;
                        q.push(make_pair(tempX, tempY));
                    }
                }
            }
        }
    }
    
    cout << check[m][n] << "\n";
    
    return 0;
}
