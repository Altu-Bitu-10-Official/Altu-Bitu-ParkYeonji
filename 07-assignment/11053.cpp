#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    set<int> result;

    int count = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        result.insert(arr[i]);
    }


    /* 집합 원소의 합을 구할 때 인덱스로 접근 X
     set<int>::iterator iter;
     for(iter = result.begin(); iter!= result.end(); iter++){
         count+= *iter;
     }
     */

    cout << result.size();



    return 0;
}