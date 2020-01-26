#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
long long primeSeive[100000]={1};
void calcuatePrimeSeve(long long n)
{

    for(long long i=2;i<=n;i++)primeSeive[i]=1;
    primeSeive[0]=primeSeive[1]=0;
    for(long long i=2;i<=n;i++){
        if(primeSeive[i]){
                for(long long j=i*i;j<=n;j+=i){
                primeSeive[j]=0;
            }
        }

    }

}
void primeInRange(long long a,long long b){
    calcuatePrimeSeve(b);
    long long arr[b-a+1];
    for(long long i=0;i<=b-a;i++)arr[i]=1;

    for(long long i=2;i*i<=b-a;i++){
             for(long long j=a;j<=b;j++){
        if(primeSeive[i]){

                if(i==j)continue;
                if(j%i==0){
                    arr[j-a]=0;
                }
            }
        }
    }
    for(long long i=1;i<=b-a;i++){
        if(arr[i]){
            cout<<a+i<<" ";
        }
    }
}

void primeFactor(long long n){
    calcuatePrimeSeve(sqrt(n));
    vector<long long> ans;

    for(int i=2;i<=sqrt(n);i++){
        if(primeSeive[i]){
           while(n%i==0){
                 ans.push_back(i);
                 n/=i;
            }
        }
    }

    if(n!=1){
        ans.push_back(n);
    }
    for(auto a : ans){
        cout<<a<<" ";
    }



}
int main()
{
    long long n,a,b;
    cin>>n;
    primeFactor(n);
    //cin>>a>>b;
    //primeInRange(a,b);
    //calcuatePrimeSeve(n);
    //for(long long i=2;i<=n;i++){
       // if(primeSeive[i]==1){
          //  cout<<i<<" ";
      //  }
    //}
}
