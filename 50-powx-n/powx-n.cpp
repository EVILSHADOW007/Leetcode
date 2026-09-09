class Solution {
    double help(double x,uint n){
        if(x==0)return 0;
        if(x==1||n==0)return 1;
        double halfPwr=help(x,n/2);//If we have 2⁹ then this will give 2⁴ as 9/2=4(int division) and 2⁸ then it will have 2⁴
        if(n%2==0){
            return halfPwr*halfPwr;
            //if 2⁸ then this will 2⁴*2⁴
        }
        return x*halfPwr*halfPwr;
        //if 2⁹ then 2*2⁴*2⁴ 
    }
public:
    double myPow(double x, int n) {
        bool negPwr=(n<0)?true:false;
        uint pwr=n;
        if(negPwr){
            pwr=-pwr;  //These are basic things
        }
        double ans=help(x,pwr);
        if(negPwr)return 1/ans;//if power is negative then the required ans is 1/ans
        //lets say 2^-4, this is /2⁴
        return ans;
    }
};