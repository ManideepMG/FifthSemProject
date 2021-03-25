#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull base[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
ull mod(ull a, ull b, ull m)
{
    ull r = 0;
    a = a%m;

    while(b > 0)
    {
        if(b&1)
            r = (r+a)%m;
        b = (b >> 1); /*** b = b/2 ***/
        a = (a+a)%m;
    }

    return r;
}

ull power(ull a, ull d, ull n)
{
    ull r = 1;
    a = a%n;

    while(d > 0)
    {
        if(d&1) /*** d%2 == 1 ***/
            r = mod(r, a, n);

        d = (d >> 1); /*** d = d/2 ***/
        a = mod(a, a, n);
    }

    return r;
}

ull binpow(ull a, ull b, ull m) {
    a %= m;
    ull res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
bool checkComposite(ull n, ull a , ull d){
    ull x=power(a,d,n);
    if(x==1|| x==n-1) return false;
    while(d!=n-1){
        //if(power(a,power(2,i,n)*d%n,n)==n-1) return false;
        x=mod(x,x,n);
        if(x==n-1) return false;
        //if(x == 1)
        //    return true;
        d<<=1;
    }
    return true;

}
bool millerRabinPrimalityTest(ull input){
    if(input<4) return input==2 || input==3;
    ull tmp=input-1;
    while(!(tmp&1)) tmp/=2;
    for(int i=0;i<12;i++){
        //ull a = rand()%(input-3)+2;
        if(input==base[i]) return true;
        if(checkComposite(input,base[i],tmp)) return false;
    }
    return true;
}

int main(){
    int t,i;
    ull number;
    cin>>t;
    while(t--){
        cin>>number;
        millerRabinPrimalityTest(number)?cout<<"YES"<<'\n':cout<<"NO"<<'\n';
    }
    return 0;
}