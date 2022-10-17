//
// Created by zhanghao on 22-10-15.
//https://www.lanqiao.cn/courses/4469/learning/?id=233731&compatibility=false
#include <stdio.h>


//int main(){
//    double n;       scanf("%lf", &n);
//    double l = -1e4, r = 1e4;
//    // 查找的为六位，一般取再加两位的精度
//    while(r - l > 1e-8){
//        double mid = (l + r) / 2;
//        // n在mi的左边，则r = mid
//        if(mid * mid * mid > n)    r = mid;
//            // n在mid的右边，则l = mid
//        else    l = mid;
//    }
//    printf("%lf", l);
//
//    return 0;
//}


#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int cnt; cin >> cnt;
    while(cnt--){
        double x;
        cin >> x;
        if(x == 0) {
            printf("0.000\n");
            continue;
        }
        double l = -100, r = 100;       // 最大值为10e4,那么其实取100也可
        while (r - l > 1e-8)
        {
            double mid = (l + r) / 2;
            if (mid * mid * mid >= x)
                r = mid;
            else
                l = mid;
        }

        printf("%.3lf\n", l);
    }

    return 0;
}
