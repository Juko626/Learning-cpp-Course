#include <iostream>
#include <string>
using namespace std;


int main(void)
{
    for (int i = 2; i < 999; i++)
    {
        if (used[i] == 0)
        {
        for (int j = i + i; j < 999; j += i)
        {
            used[j] = 1;
        }
        
            
    }
    int de = 0;
    int T;
    cin >> T;
    
    for (int tc = 0; tc < T; tc++)
    {
        int N;
        cin >> N;
    }
    /*20
    2 3 5 7 11 13 17*/
  
    return 0;
}