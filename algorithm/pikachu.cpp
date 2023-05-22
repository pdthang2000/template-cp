#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define see(x) cout<< #x <<" = "<< x <<' ';
#define seen(x) cout<< #x <<" = "<< x <<'\n';
#define UWU cout<<'\n';
int m[10][18],z[22],t1,t2;
bool stt;
vector<pair<int,int>> v;
bool check(int x,int y){
    if(x >= 0 && x <= 9 && y >= 0 && y <= 17) return true;
    else return false;
}
void Find(int r,int c,int pr,int pc,int val,char dir,int cnt){
    if(cnt > 3) return;
    cout<<r<<'-'<<c<<','<<cnt<<" "<<dir<<"  ";
    if(m[r][c+1] == 0 && (r != pr || c+1 != pc) && check(r,c+1)){
        if(dir == 'R') Find(r,c+1,r,c,val,'R',cnt);
        else Find(r,c+1,r,c,val,'R',cnt+1);
    }else if(m[r][c+1] == val && (r != pr || c+1 != pc) && check(r,c+1)){
        if(dir != 'R') cnt++;
        if(cnt <= 3){cout<<r<<':'<<c+1<<' '<<cnt;UWU;v.pb({r,c+1});}
    }
    if(m[r][c-1] == 0 && (r != pr || c-1 != pc) && check(r,c-1)){
        if(dir == 'L') Find(r,c-1,r,c,val,'L',cnt);
        else Find(r,c-1,r,c,val,'L',cnt+1);
    }else if(m[r][c-1] == val && (r != pr || c-1 != pc) && check(r,c-1)){
        if(dir != 'L') cnt++;
        if(cnt <= 3){cout<<r<<':'<<c-1<<' '<<cnt;UWU;v.pb({r,c-1});}
    }
    if(m[r+1][c] == 0 && (r+1 != pr || c != pc) && check(r+1,c)){
        if(dir == 'D') Find(r+1,c,r,c,val,'D',cnt);
        else Find(r+1,c,r,c,val,'D',cnt+1);
    }else if(m[r+1][c] == val && (r+1 != pr || c != pc) && check(r+1,c)){
        if(dir != 'D') cnt++;
        if(cnt <= 3){cout<<r+1<<':'<<c<<' '<<cnt;UWU;v.pb({r+1,c});}
    }
    if(m[r-1][c] == 0 && (r-1 != pr || c != pc) && check(r-1,c)){
        if(dir == 'U') Find(r-1,c,r,c,val,'U',cnt);
        else Find(r-1,c,r,c,val,'U',cnt+1);
    }else if(m[r-1][c] == val && (r-1 != pr || c != pc) && check(r-1,c)){
        if(dir != 'U') cnt++;
        if(cnt <= 3){cout<<r-1<<':'<<c<<' '<<cnt;UWU;v.pb({r-1,c});}
    }
}
void show(){
    int x = 0;see(x);
    for(int i = 0 ; i < 10 ; ++i) cout<<i<<"  ";
    for(int i = 10 ; i < 19 ; ++i) cout<<i<<' ';UWU;
    for(int i = 0 ; i <= 9 ; ++i){
        see(i);
        for(int j = 0 ; j <= 17 ; ++j){
            if(m[i][j] < 10) cout<<m[i][j]<<"  ";
            else cout<<m[i][j]<<' ';
        }UWU;
    }
}
int main(){
//ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i = 0 ; i <= 17 ; ++i){
            m[0][i] = 0;
            m[9][i] = 0;
        }
        for(int i = 0 ; i <= 9 ; ++i){
            m[i][0] = 0;
            m[i][17] = 0;
        }
        for(int i = 1 ; i <= 21 ; ++i){
            z[i] = 6;
        }
        z[21]+=2;
        for(int i = 1 ; i <= 8 ; ++i){
            for(int j = 1 ; j <= 16 ; ++j){
                while(true){
                    int t = rand() % 21 + 1;
                    if(z[t] > 0){
                        m[i][j] = t;
                        z[t]--;
                        break;
                    }
                }

            }
        }
        ll process = 128;
        while(process--){
            system("cls");
            show();
            v.clear();
            int r1,c1,r2,c2;cin>>r1>>c1>>r2>>c2;
            int val = m[r2][c2];
            if(m[r1][c1] != m[r2][c2]) continue;
            Find(r1,c1,r1,c1,val,'R',1);//UWU;
            Find(r1,c1,r1,c1,val,'D',1);//UWU;
            Find(r1,c1,r1,c1,val,'U',1);//UWU;
            Find(r1,c1,r1,c1,val,'L',1);//UWU;
            for(auto [x,y] : v){
                if(x == r2 && y == c2)
                m[r1][c1] = m[r2][c2] = 0;
            }
            int x;cin>>x;
            if(x == 1) continue;
            else break;
        }
//        for(int i = 1 ; i < 9 ; ++i){
//            for(int j = 1 ; j < 17 ; ++j){
//                int val = m[i][j];see(i);see(j);seen(val);
//                    Find(i,j,i,j,val,'R',1);//UWU;
//                    Find(i,j,i,j,val,'D',1);//UWU;
//                    Find(i,j,i,j,val,'U',1);//UWU;
//                    Find(i,j,i,j,val,'L',1);//UWU;
//            }
//            UWU;
//        }
}

