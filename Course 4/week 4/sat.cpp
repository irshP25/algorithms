#include<bits/stdc++.h>
using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof(c.begin()) i=c.begin(); i!=c.end(); i++)
#define largeconstant 300

int readclause(list<pair<int,int> > &clauses){
    ifstream ipfile("C://Users//hp//Desktop//sat1.txt");	//Change the filename in this line
    int numvar;ipfile>>numvar;
    while(!ipfile.eof()){
            int a,b;ipfile>>a;ipfile>>b;
            if(ipfile.eof())
                break;
            pair<int,int> temp;temp.first=a;temp.second=b;
            clauses.pb(temp);

    }

    ipfile.close();
    return numvar;
}

void pruneclauses(list<pair<int,int> > &clauses,int numvar){

    while(true){
        vvi temps(numvar+1);
        for(int i=1;i<numvar+1;i++){
            vi temp(3);
            temp[0]=0;temp[1]=0;temp[2]=0;//if temp[0] is 0 then numnotseen if 1 then seen once, if 2 then twice ..if 1 then temp[1] indicates its sign +1 or -1
            //temp[2] indicates number of sign changes..
            temps[i]=temp;
        }
        int numofchanges=0;
        tr(clauses,it){
            if((*it).first>0){
                if(temps[abs((*it).first)][0]>0&&temps[abs((*it).first)][1]==-1&&temps[abs((*it).first)][2]==0){
                    temps[abs((*it).first)][2]=1;
                }
                temps[abs((*it).first)][1]=1;
                temps[abs((*it).first)][0]++;
            }
            else{

                if(temps[abs((*it).first)][0]>0&&temps[abs((*it).first)][1]==1&&temps[abs((*it).first)][2]==0){
                    temps[abs((*it).first)][2]=1;
                }
                temps[abs((*it).first)][1]=-1;
                temps[abs((*it).first)][0]++;
            }

            if((*it).second>0){
                if(temps[abs((*it).second)][0]>0&&temps[abs((*it).second)][1]==-1&&temps[abs((*it).second)][2]==0){
                    temps[abs((*it).second)][2]=1;
                }
                temps[abs((*it).second)][1]=1;
                temps[abs((*it).second)][0]++;
            }
            else{
                if(temps[abs((*it).second)][0]>0&&temps[abs((*it).second)][1]==1&&temps[abs((*it).second)][2]==0){
                    temps[abs((*it).second)][2]=1;
                }
                temps[abs((*it).second)][1]=-1;
                temps[abs((*it).second)][0]++;
            }
        }
        list<pair<int,int> > newclauses;
        tr(clauses,it){
            if(temps[abs((*it).first)][2]==0||temps[abs((*it).second)][2]==0){
                numofchanges++;
            }
            else{
                newclauses.pb(*it);
            }
        }
        if(numofchanges==0)
            break;
        clauses=newclauses;
        temps.erase(all(temps));
    }
}

int reduce(list<pair<int,int> > &clauses){
    vi lownum;
    int numvar=0;
    list<pair<int,int> > newclauses;
    tr(clauses,it){
        int first=(*it).first,second=(*it).second;
        int newfirst,newsecond,flag1=0,flag2=0;
        tr(lownum,iter){
            if((*iter)==abs(first)){
                newfirst=(first/abs(first))*(iter-(lownum).begin()+1);
                flag1=1;
                break;
            }
        }
        tr(lownum,iter){
            if((*iter)==abs(second)){
                newsecond=(second/abs(second))*(iter-(lownum).begin()+1);
                flag2=1;
                break;
            }
        }
        if(flag1==0){
            lownum.pb(abs(first));
            newfirst=(first/abs(first))*(lownum.end()-lownum.begin());
            numvar++;
        }
        if(flag2==0){
            lownum.pb(abs(second));
            newsecond=(second/abs(second))*(lownum.end()-lownum.begin());
            numvar++;
        }
        pair<int,int> temp(newfirst,newsecond);
        newclauses.pb(temp);
    }
    clauses=newclauses;
    return numvar;
}

void solution(list<pair<int,int> > &clauses,int numvar,int clausecount){
    if(clausecount==0){
        cout<<"1";
        return;
    }
    srand(time(NULL));
    for(int i=0;i<=int(log2(numvar));i++){
        string val;
        for(int j=0;j<largeconstant;j++){
            string str;
            ostringstream temp;
            temp<<rand()%2;
            str=temp.str();
            val=val+str;
        }
        bitset<largeconstant> strings(val);

        for(int j=0;j<(2*numvar*numvar);j++){
            int flags=0;
            tr(clauses,it){
                int firstnum,secondnum,firstneg=0,secondneg=0;
                if(((*it).first)/abs((*it).first)==1){
                    firstnum=(*it).first;
                }
                else{
                    firstnum=abs((*it).first);
                    firstneg=1;
                }
                if(((*it).second)/abs((*it).second)==1){
                    secondnum=(*it).second;
                }
                else{
                    secondnum=abs((*it).second);
                    secondneg=1;
                }
                if(firstneg==0&&secondneg==0){
                    if(strings[firstnum]||strings[secondnum]){
                        continue;
                    }
                    else{
                        int vals=rand()%2;
                        if(vals==1)
                            strings[firstnum]=!strings[firstnum];
                        else
                            strings[secondnum]=!strings[secondnum];
                        flags=1;
                    }
                }
                if(firstneg==0&&secondneg==1){
                    if(strings[firstnum]||!strings[secondnum]){
                        continue;
                    }
                    else{
                        int vals=rand()%2;
                        if(vals==1)
                            strings[firstnum]=!strings[firstnum];
                        else
                            strings[secondnum]=!strings[secondnum];
                        flags=1;
                    }
                }
                if(firstneg==1&&secondneg==0){
                    if(!strings[firstnum]||strings[secondnum]){
                        continue;
                    }
                    else{
                        int vals=rand()%2;
                        if(vals==1)
                            strings[firstnum]=!strings[firstnum];
                        else
                            strings[secondnum]=!strings[secondnum];
                        flags=1;
                    }
                }
                if(firstneg==1&&secondneg==1){
                    if(!strings[firstnum]||!strings[secondnum]){
                        continue;
                    }
                    else{
                        int vals=rand()%2;
                        if(vals==1)
                            strings[firstnum]=!strings[firstnum];
                        else
                            strings[secondnum]=!strings[secondnum];
                        flags=1;
                    }
                }
            }
            if(flags==0){
                cout<<"1";
                return;
            }
        }
    }
    cout<<"0";

}

int main(){

    list<pair<int,int> > clauses;
    int numvar=readclause(clauses);


    pruneclauses(clauses,numvar);

    int clausecount=0;
    tr(clauses,it){
        clausecount++;
    }

    numvar=reduce(clauses);

    solution(clauses,numvar,clausecount);

    return 0;
}
