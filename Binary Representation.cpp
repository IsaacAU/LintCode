class Solution {
public:
    /**
     *@param n: Given a decimal number that is passed in as a string
     *@return: A string
     */
    string binaryRepresentation(string n) {
        // wirte your code here
        double x=stod(n);
        bool neg=false;
        if(x<0){
            neg=true;
            x=-x;
        }
        int num=x;
        x-=num;
        string res;
        while(num){
            res=char(num%2+'0')+res;
            num/=2;
        }
        if(res.empty())
            res="0";
        if(neg)
            res='-'+res;
        if(abs(x)<1e-10)
            return res;
        res+='.';
        const int limit=32;
        int cnt=0;
        while(x){
            if(cnt>limit)
                return "ERROR";
            x*=2;
            if(x>=1){
                res.push_back('1');
                x-=1;
            }else
                res.push_back('0');
            ++cnt;
        }
        return res;
    }
};

