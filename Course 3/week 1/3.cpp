//Author: Pooja srivastava
#include<bits/stdc++.h>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
using namespace std;

struct node
{
       int nodenum,cost;
       node *next;
}**g;

void getInt(char *a, int nos, int *val1, int *val2, int *val3=NULL)
{
     int i,j;
     char ab[10];
     for(i=0; a[i]!=' '; i++) ab[i]=a[i];
     ab[i]='\0';
     *val1=atoi(ab);
     for(j=0, i++; (a[i]!='\n' && a[i]!=' '); i++,j++) ab[j]=a[i];
     ab[j]='\0';
     *val2=atoi(ab);
     if(nos==3)
     {
               for(j=0, i++; a[i]!='\n'; i++,j++) ab[j]=a[i];
               ab[j]='\0';
               *val3=atoi(ab);
     }
}

int main()
{
    char a[20];
    int num_nodes,num_edges;
    FILE *f=fopen("C:/Users/hp/Desktop/edges.txt","r");
    fgets(a,20,f);
    getInt(a,2,&num_nodes,&num_edges);
    g=new node*[num_nodes];
    for(int i=1; i<=num_nodes; i++)
    {
            g[i]=new node;
            g[i]->next=NULL;
            g[i]->nodenum=i;
            g[i]->cost=0;
    }
    for(int i=0; i<num_edges; i++)
    {
            int node1,node2,cost;
            fgets(a,20,f);
            getInt(a,3,&node1,&node2,&cost);
            node *newnode=new node;
            newnode->nodenum=node2;
            newnode->cost=cost;
            newnode->next=NULL;
            node *temp=g[node1];
            while(temp->next!=NULL) temp=temp->next;
            temp->next=newnode;
            
            newnode=new node;
            newnode->nodenum=node1;
            newnode->cost=cost;
            newnode->next=NULL;
            temp=g[node2];
            while(temp->next!=NULL) temp=temp->next;
            temp->next=newnode;
    }
    bool *spanned=new bool[num_nodes+1];
    for(int i=0; i<=num_nodes; spanned[i++]=false);
    spanned[1]=true;
    long long tot_cost=0;
    for(int i=1; i<num_nodes; i++)
    {
            long minedge_cost=1000000;
            int node1, node2;
            for(int j=1; j<num_nodes; j++)
            {
                    if(!spanned[j]) continue;
                    node *t=g[j];
                    while(t->next!=NULL)
                    {
                         if(!spanned[(t->next)->nodenum])
                         {
                             if((t->next)->cost<minedge_cost) {node1=j; node2=(t->next)->nodenum; minedge_cost=(t->next)->cost; }
                         }
                         t=t->next;
                    }
            }
            spanned[node2]=true;
            tot_cost+=minedge_cost;
    }
cout<<" cost of MST: "<<tot_cost<<endl;}