#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[1025][1025];
int n,ans;

int Pulling(int x, int y)
{
    vector <int > a;
    for (int i = x; i < x + 2; i++)
        for (int j = y; j < y + 2; j++)
            a.push_back(arr[i][j]);
    sort(a.begin(), a.end());
    return a[2];
}
 
int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    while (n > 1){
        for (int i = 0; i < n; i+=2)
            for (int j = 0; j < n; j+=2)
                arr[i/2][j/2] = Pulling(i,j); 
        n /= 2;
    }
    cout << arr[0][0] << '\n';
}
