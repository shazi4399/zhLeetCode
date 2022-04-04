//
//  main.cpp
//  lanqiao
//
//  Created by zhanghao on 2022/3/31.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main()
{
  // 请在此输入您的代码
    vector<int> arr(26);
  string s;
  cin>>s;
  int n = s.size();
  for(int i = 0; i < n; i++){
    arr[s[i]-'a']++;
  }
  int ans = 0,maxIndex = 0;
  for(int i =  0; i < 26;++i){
    if(arr[i]>ans){
      ans = arr[i];
      maxIndex = i;
    }
  }
  cout<<char(maxIndex+'a')<<endl;
    cout<<ans<<endl;

  return 0;

}
