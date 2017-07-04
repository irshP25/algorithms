//Author : Pooja srivastava
#include<iostream>
#include<vector>
using namespace std;
vector<long int> ques,a;
long int maximum(long int x, long int y)
{
    return x>y?x:y;
}
void reconstruct(vector<long int> a)
{
    int i = a.size();
    while(i>=1)
    {
        if(a[i-1]>a[i-2] + ques[i])
            i--;
        else{
            if(i==1 || i==2 || i==3 || i==4 || i==17 || i== 117 ||i== 517 || i== 997)
                cout<<i<<" ";
            i= i - 2;
        }
    }
}
int main()
{
    ques.push_back(0);
    long int vertices;
    cin>>vertices;
    while(vertices--){
        long int weight;
        cin>>weight;
        ques.push_back(weight);
    }
    a.push_back(0);
    a.push_back(ques[1]);
    for(int i=2;i<ques.size();i++){
        a.push_back( maximum(a[i-1],a[i-2] + ques[i]));
    }
    //for(int i=0;i<a.size();i++)
        //cout<<a[i]<<" ";
    //cout<<endl;
    reconstruct(a);
    return 0;
}
