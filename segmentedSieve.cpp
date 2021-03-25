#include<bits/stdc++.h>
using namespace std;
vector<int> primes;
int cntOfPrimes=0;
void sieve(int normalizedSize){
    // int isPrime[normalizedSize+1];
    // memset(isPrime,0,sizeof(isPrime));
    vector<bool> isPrime(normalizedSize+1,true);
    isPrime[0] = isPrime[1] = false;
    for(int i=2;i*i<=normalizedSize;++i){
        if(isPrime[i]){
            for(int j=i*i;j<=normalizedSize;j+=i){
                isPrime[j] = false;
            }
        }
    }
    for(int itr=2;itr<=normalizedSize;++itr){
        if(isPrime[itr]){ 
            primes.push_back(itr);
            cntOfPrimes++;
            cout<<itr<<' ';
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    sieve(sqrt(n));
    int left=sqrt(n)+1,right=2*sqrt(n);
    
    while(left<=n+1){
        if(right>=n+1) right=n;
        vector<bool> isLocalPrime(right-left+1,true);
        for(auto element:primes){
            int i;
            if(left%element==0) i=left;
            else i=left + (element - left%element);
            for(;i<=right;i+=element){
                if(i%element==0){
                    isLocalPrime[i-left]=false;
                }
            }
        }
        for(int i=0;i<right-left+1;i++){
            if(isLocalPrime[i]){
                cout<<left+i<<' ';
                cntOfPrimes++;
            }
        }
        left += sqrt(n);
        right += sqrt(n);
    }
    cout<<'\n'<<cntOfPrimes<<'\n';
    return 0;
}