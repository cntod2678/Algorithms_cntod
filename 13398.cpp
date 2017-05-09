//
//  13398.cpp
//  Session02
//
//  Created by 최동진 on 2017. 4. 7..
//  Copyright © 2017년 최동진. All rights reserved.
//

//#include <iostream>
//#include <math.h>
//using namespace std;
//
//int arr[100001];
//int inf = 1001;
//
//int main() {
//    int n;
//    cin >> n;
//    
//    for(int i = 1; i <= n; i++) {
//        cin >> arr[i];
//    }
//    
//    int ma = 0;
//    
//    for(int i = 1; i <= n; i++) {
//        int maxEndingHere = 0;
//        int maxSoFar = -inf;
//        for(int j = 1; j <= n; j++) {
//            if(j == i)
//                continue;
//            
//            maxEndingHere = max(maxEndingHere + arr[j], arr[j]);
//            maxSoFar = max(maxSoFar, maxEndingHere);
//        }
//        ma = max(ma, maxSoFar);
//    }
//    
//    cout << ma << "\n";
//    
//    return 0;
//}


#include <iostream>
#include <math.h>
using namespace std;

int arr[100001];
int dp[2][100001];
int inf = 1001;

int main() {
    int n;
    cin >> n;
    
    for(int i = 2; i <= n+1; i++) {
        cin >> arr[i];
    }

    int maxValue = -inf;
    
    for(int i = 2; i <= n+1; i++) {
        dp[0][i] = max(dp[0][i-1] + arr[i], arr[i]);
        dp[1][i] = max(dp[0][i-2] + arr[i], dp[1][i-1] + arr[i]);
        
        maxValue = max(maxValue, dp[0][i]);
        maxValue = max(maxValue, dp[1][i]);
    }

    /**
     * dp[0][i] : 0번 건너뛴 i까지의 최대 연속합 = (i-1까지의 최대 연속합 + A[i])값과 A[i]값 중 큰 값
     * dp[1][i] : 1번 건너뛴 i까지의 최대 연속합 = (i-1을 건너뛴 i까지의 최대 연속합)값과 (i-1을 안건너뛴 i까지의 최대 연속합)값 중 큰 값
     */
    
    cout << maxValue << "\n";
    
    return 0;
}
