//Author :Pooja Srivastava
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int main()
{
    long int size,n;
    cin>>size;
    vector<pair<long double,long double> > points;
    vector<bool> visited(size,false);
    for(int i=0;i<size;i++){
        double a,b;
        cin>>n>>a>>b;
        points.push_back({a,b});
        visited[i]=false;
    }
    long int selected =0;
    visited[selected] = true;
    long double weightSum = 0 ;
    for(int i=0;i<size-1;i++)
    {
        long double minimum=1000000000.0;
         visited[selected] = true;
         long int selected2=selected;
        for(int j=0;j<size;j++)
        {

            long double co = pow(points[selected2].first - points[j].first,2);
            long double co1 = pow(points[selected2].second - points[j].second,2);

            long double temp = co+co1;
            if(temp<minimum && visited[j]==false )
            {
                selected = j;
                minimum = temp;
            }
        }
        weightSum += sqrt(minimum);
    }
    weightSum += sqrt(pow(points[0].first - points[selected].first,2) + pow(points[0].second - points[selected].second,2));
    cout<<(long long int)weightSum;
}