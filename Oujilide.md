# 欧几里得定理  
+ 原理：  
>  gcd(a,b)=gcd(b,a%b)  
> 当a%b==0时，b即为最小公倍数  
+ 代码实现  
```c
int gcd(int a,int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}
```
