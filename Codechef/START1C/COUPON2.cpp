//Problem - https://www.codechef.com/START1C/problems/COUPON2

#include <iostream>
using namespace std;
int wC(int a[], int b[], int coupon,int dc){
int cost = 0, costA = 0, costB = 0;
for (int i = 0; i < 3; i++)
{
    costA += a[i];
}
for(int i = 0; i < 3; i++)
{
    costB += b[i];
}
cost += coupon + costA + costB;

if (costA < 150)
{
    cost += dc;
}
if (costB < 150)
{
    cost += dc;
}
return (cost);
}
int woC(int a[], int b[],int dc)
{
    int cost = 0;
    for (int i = 0; i < 3; i++)
    {
        cost += a[i];
    }
    for (int i = 0; i < 3; i++)
    {
        cost += b[i];
    }
    cost += dc * 2;
    return (cost);
}
int main()
{
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        int coupon, dc, a[3], b[3];
        cin >> dc >> coupon;
        for (int m = 0; m < 3; m++)
        {
            cin >> a[m];
        }
        for (int n = 0; n < 3; n++)
        {
            cin >> b[n];
        }
        if (wC(a, b, coupon, dc) < woC(a, b, dc))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}