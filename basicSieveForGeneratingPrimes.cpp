#include<bits/stdc++.h>
using namespace std;
int primes[1002];

void GeneratePrimes(int curLimit){
    memset(primes,0,sizeof(primes));
    primes[1]=primes[0]=1;
    primes[2]=0;
    for(int i=2;i*i<=curLimit;i++){
        if(!primes[i]){
            for(int j=i*i;j<=curLimit;j+=i){
                primes[j]=1;
            }
        }
    }

    for(int primeIterator=1;primeIterator<=curLimit;primeIterator++){
        if(!primes[primeIterator]) cout<<primeIterator<<" ";
    }
    cout<<'\n';
}
int main(){
    int n;
    cin>>n;
    GeneratePrimes(n);
    return 0;
}