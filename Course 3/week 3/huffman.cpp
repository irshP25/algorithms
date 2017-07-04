//Author : Pooja srivastava
//minimum length or maximum length calculation
#include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<algorithm>
struct TreeNode{
    long int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):data(x),left(NULL),right(NULL) {}
}*temp = NULL;
using namespace std;
vector<long int> lengh;
int maxlength(TreeNode *temp, int x)
{
    if(temp->right == NULL && temp->left==NULL ){
        lengh.push_back(x);
        return x;
    }
    x++;
    maxlength(temp->left,x);
    maxlength(temp->right,x);
}
int main()
{
    long int ssize,input;
    cin>>ssize;
    priority_queue<pair<long int, TreeNode*>, vector<pair<long int, TreeNode*> >, greater<pair<long int, TreeNode*> > > pque;
    while(ssize--){
        cin>>input;
        pque.push({input,new TreeNode(input)});
    }
    while(pque.size()!=1)
    {
        int tdata = pque.top().first;
        temp = new TreeNode(tdata);
        temp->left = pque.top().second;
        pque.pop();
        temp -> data = temp-> data + pque.top().first ;
        temp -> right = pque.top().second ;
        //cout<< temp->data<<" ";
        pque.pop();
        pque.push({temp->data, temp});
    }
    cout<<"Maxx";
    cout<<temp->data;
    maxlength(temp,0);
    cout<<endl<<*min_element(lengh.begin(), lengh.end());    //minimum length or maximum length
    return 0;
}
