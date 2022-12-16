#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;


int main() {

    int t;
    cin >> t;
    while (t--)
    {
        unsigned long long int n;
        cin >> n;
        unsigned long long int temp = n;

        unsigned long long int div2 = 1;
        unsigned long long int sum = 0;

        while (temp > 0)
        {
            int x = temp % 10;
            if (x > 4)
            {
                if(x==9)
                {
                    if(temp>9)
                    sum = (sum + (9 - x) * div2);  
                    else
                     sum = (sum + 9* div2);  
 
                 
                }
                else
                     sum = (sum + (9 - x)* div2);
            }
            
            else {
                sum = (sum + (x) * div2);
            }

            div2 = div2 * 10;
            temp = temp / 10;

        }
        cout << sum << endl;
    }
    return 0;
}