#include<iostream>
using namespace std;
class AmountApproximation{
    public:
    int approximate(int D, int p1, int p2)
    {
        int x,y;
        if(p1>D && p2>D)
        {
            x=p1>p2?0:1;
            y=p1<p2?0:1;
            return x*p1+y*p2;
        }
        if(p1==D)
        {
            x=1;
            y=0;
            return x*p1+y*p2;
        }
        if(p2==D)
        {
            x=0;
            y=1;
            return x*p1+y*p2;
        }
        int ret=0;
        for(x=0;x<=D;++x)
        {
            for(y=0;y<=D;++y)
            {
                auto expr=x*p1+y*p2;
                if(expr==D)
                {
                    return D;
                }
                if(ret==0 && expr>D)
                {
                	ret=expr;
                	continue;
				}
                if(expr>D && expr<ret)
                {
                   	ret=expr;
                }
                if(expr>D)
                	break;
            }
        }
        cout<<"x = "<<x<<" , y = "<<y<<endl;
        return ret;
    }
};
int main()
{
    AmountApproximation obj;
    cout<<"The approximation is "<<obj.approximate(287341,2345,7253)<<"\n";
    return 0;
}
