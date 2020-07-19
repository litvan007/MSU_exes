#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double eps=0.00001;

struct point
{
    int x,y;
};
double dist (point a, point b)
{
    return sqrt( 0.0 + (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double CosAngle(point prev,point cur, point next)
{
    point v1,v2;
    v1.x=next.x - cur.x;
    v1.y=next.y - cur.y;
    v2.x=prev.x - cur.x;
    v2.y=prev.y - cur.y;
    return (v1.x * v2.x + v1.y * v2.y) / (dist(prev,cur) * dist(cur,next));
}
double triangle_square(point base, point one, point two)
{
    return 0.5*abs((one.x-base.x)*(two.y-one.y)-(two.x-base.x)*(one.y-base.y));
}
bool Equal( double a, double b)
{
    return abs(a-b) <= eps;
}
bool More(double a, double b)
{
    return !Equal(a,b) && a > b;
}
bool Less( double a, double b)
{
    return !Equal(a,b) && a < b;
}
bool operator != (point a, point b)
{
    return !(a.x == b.x && a.y == b.y);
}

int main(){
	    int n;

    vector<int> convex_hull;
    double P=0,S=0;
    cin>>n;
    vector<point> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i].x>>arr[i].y;
    int base = 0;
       for (int i=1;i<n;i++)
       {
           if (arr[i].y < arr[base].y)
               base = i;
           else
               if (arr[i].y == arr[base].y &&
                   arr[i].x <  arr[base].x)
                   base = i;
       }
          convex_hull.push_back(base);

          point first = arr[base];
          point cur = first;
          point prev;
          prev.x=first.x - 1;
          prev.y=first.y;

          do
          {
              double minCosAngle = 1e9;
              double maxLen = 1e9;
              int next = -1;
              for (int i=0;i<n;i++)
              {
                  double curCosAngle = CosAngle(prev, cur, arr[i]);
                  if (Less(curCosAngle,minCosAngle))
                  {
                      next = i;
                      minCosAngle = curCosAngle;
                      maxLen = dist(cur,arr[i]);
                  }
                  else if (curCosAngle==minCosAngle)
                  {
                      double curLen = dist(cur,arr[i]);
                      if (More(curLen,maxLen))
                      {
                          next = i;
                          maxLen = curLen;
                      }
                  }
              }
              prev = cur;
              cur = arr[next];
              convex_hull.push_back(next);
          }
          while (cur != first);

    for (int i=0;i<convex_hull.size()-1;i++){
        P+= dist(arr[convex_hull[i]],arr[convex_hull[i+1]]);
        S+=arr[convex_hull[i]].x*arr[convex_hull[i+1]].y-arr[convex_hull[i]].y*arr[convex_hull[i+1]].x;
    }
    S=S/2;
    cout<<P<<endl<<S;

return 0;
}
