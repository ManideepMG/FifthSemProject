#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

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

ull gcd(ull firstNum,ull secondNum){
    ull temp;
    while(secondNum){
        temp=firstNum%secondNum;
        firstNum=secondNum;
        secondNum=temp;
    }
    return firstNum;
}
bool isPrime(ull number,int iterations){
    if(number<4) return number==2 || number==3;
    ull testNum;
    while(iterations--){
        testNum = rand()%(number-2)+2;
        if(gcd(testNum,number)!=1) return false;
        if(power(testNum,number-1,number)!=1) return false;
    }
    return true;
}

int main(){
    int t;
    ull input;
    
    cin>>t;
    while(t--){
        cin>>input;
        //cout<<power(3,5,300)<<'\n';
        isPrime(input,30)? cout<<"YES"<<'\n' : cout<<"NO"<<'\n';

    }    
    return 0;
}