#include <iostream>
using namespace std;

int main(){
    int a[]={2,3,4,5,5,5,6,7,8,8,10};
    int h[11]={0};
    for(int i=0;i<11;i++){
        h[a[i]]++;
    }
    for(int i=0;i<11;i++){
        if(h[i]>1){
            cout<<i<<" "<<h[i]<<"times"<<endl;
        }
    }
    return 0;
}