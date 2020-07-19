#include <iostream>
#include <cmath>

using namespace std;

double povorot(double xa,double xb, double xc, double ya,double yb, double yc)
{
    if ((xb-xa)*(yc-ya)-(xc-xa)*(yb-ya)<=0)
        return -1;
    else
        return 1;
}

int main()
{
    bool proverka = true;
    int n;
    int znak;
    cin>>n;
    pair<double, double> dots[n];
    for (int i=0;i<n;i++)
        cin>>dots[i].first>>dots[i].second;
    znak = povorot(dots[0].first, dots[1].first, dots[2].first, dots[0].second, dots[1].second, dots[2].second);
    for (int i=2; i<n; i++)
       if (povorot(dots[i-2].first,dots[i-1].first,dots[i].first,dots[i-2].second,dots[i-1].second,dots[i].second) * znak <= 0 )
           {
               proverka=false;
               break;
       }
    double last=povorot(dots[n-1].first, dots[0].first, dots[1].first,dots[n-1].second, dots[0].second, dots[1].second);
    if (last*znak<=0)
        proverka=false;
    if (proverka)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
