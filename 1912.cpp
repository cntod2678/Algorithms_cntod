//
//  1912.cpp
//  Session02
//
//  Created by 최동진 on 2017. 4. 7..
//  Copyright © 2017년 최동진. All rights reserved.
//


#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int arr[100001];
int inf = 1001;

int main() {
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    int maxSoFar = -inf;
    int maxEndingHere = 0;
    
    for(int i = 1; i <= n; i++) {
        maxEndingHere = max(maxEndingHere + arr[i], arr[i]);
        maxSoFar = max(maxEndingHere, maxSoFar);
    }
    
    cout << maxSoFar << "\n";
    
    return 0;
}
