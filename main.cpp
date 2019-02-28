#include<iostream>
#include<vector>
#include"Constant.h"

#define _USE_MATH_DEFINES
#include<math.h>
#define PI M_PI
#define pb push_back
using namespace std;
/** Header file  */
void cal(double &a,const double &b,const int &count,const vector<int> &state);

void help(const int &mode);

bool isint(const double &a);

/**              */

void help(const int &mode)
{
    printf("HELP: h \n");
    printf("Cong: %c Tru: %c Nhan: %c Chia: %c \n",ADDITION,SUBTRACTION,MULTIPLY,DIVISION);
    printf("Bang: %c Mu: %c  Phan tram: %c \n",EQUAL,POWER,PERCENTAGE);
    printf("Xoa: %c\n",AC);
    printf("Switch: FUNCTION:%c    MEMORY:%c\n",FUNCTION,MEMORY);
    cout<<endl;
    switch(mode)
    {
        case NOR:
        printf("Current Mode : Function \n");
        printf("Function first, Number later\n");
        printf("Sin:%c  Cos:%c  Tan:  %c\n",SIN,COS,TAN);
        printf("ArcSin:%c  ArcCos:%c  ArcTan:%c\n",ARCSIN,ARCCOS,ARCTAN);
        printf("Deg:%c   Rad(default):%c\n",DEG,RAD);
        break;

        case MEM:
        printf("Current Mode : Memory \n");
        printf("M:%c  M+:%c  M-:%c  MC:%c\n",MEMORY,MADD,MMIN,MCLEAR);
        break;
    }
}

void cal(double &a,const double &b,const int &count,const vector<int> &state)
{
    double t;
    bool rad = state[MRAD];
    int circle = state[MCIRCLE];
    int op = state[MOP];
    long tmp = pow(10,count);
    switch(circle)
    {
        case CIR_DF:
            t = b/tmp;
            break;
        case CIR_SIN:
            if(rad) t = sin(b/tmp); else t = sin(b/tmp*PI/180);
            break;
        case CIR_COS:
            if(rad) t = cos(b/tmp); else t = cos(b/tmp*PI/180);
            break;
        case CIR_TAN:
            if(rad) if(isint((b/tmp-PI/2)/PI)) throw 1;
            if(!rad) if(isint((b/tmp-90)/180)) throw 1;
            if(rad) t = tan(b/tmp);else t = tan(b/tmp*PI/180);
            break;
        case CIR_ASIN:
            t = asin(b/tmp);
            if(!rad) t = t/PI*180;
            break;
        case CIR_ACOS:
            t = acos(b/tmp);
            if(!rad) t = t/PI*180;
            break;
        case CIR_ATAN:
            t = atan(b/tmp);
            if(!rad) t = t/PI*180;
            break;
    }

    switch(op)
    {
        case OP_ADD:
            a+=t;
        break;

        case OP_MIN:
            a-=t;
        break;

        case OP_MUL:
            a*=t;
        break;

        case OP_DIV:
            if(t==0) throw 0;
            a = (double) a/t;
        break;

        case OP_POW:
            a = pow(a,t);
        break;
    }
}

bool isint(const double &a)
{
    long long t = a;
    return (t==a);
}

int main()
{
    bool begin = true;

    double cur = 0 ;
    bool dot  = false;
    int count = 0;

    double m = 0;
    double ans = 0;

    vector<int> state;
    bool num = false;
    bool equal = false;

    bool quit = false;
    int flag = NOR;
    char c;

    state.pb(0);
    state.pb(0);
    state.pb(1);

    while(!quit)
    {
        cin>>c;
        if(flag==NOR)
            switch(c)
            {
                case HELP:
                    help(flag);
                break;

                case QUIT:
                    quit = true;
                break;

            //------------------------------------
                case ADDITION:
                    equal = false;
                    if(num)
                        try
                        {
                            cal(ans,cur,count,state);
                        }
                        catch(int n)
                        {
                            cout<<n<<endl;
                            break;
                        }
                    if(!begin&&num) cout<<"="<<ans<<endl;
                    begin = false;

                    state[MOP] = OP_ADD;
                    state[MCIRCLE] = CIR_DF;

                    cur = 0;
                    count = 0;
                    dot = false;
                    num = false;
                break;
                //------------------------------------
                case SUBTRACTION:
                    equal = false;
                    if(num)
                        try
                        {
                            cal(ans,cur,count,state);
                        }
                        catch(int n)
                        {
                            cout<<n<<endl;
                            break;
                        }
                    if(!begin&&num) cout<<"="<<ans<<endl;
                    begin = false;

                    state[MOP] = OP_MIN;
                    state[MCIRCLE] = CIR_DF;

                    cur = 0;
                    count = 0;
                    dot = false;
                    num = false;
                break;
                //------------------------------------
                case MULTIPLY:
                    equal = false;
                    if(num)
                        try
                        {
                            cal(ans,cur,count,state);
                        }
                        catch(int n)
                        {
                            cout<<n<<endl;
                            break;
                        }
                    if(!begin&&num) cout<<"="<<ans<<endl;
                    begin = false;

                    state[MOP] = OP_MUL;
                    state[MCIRCLE] = CIR_DF;

                    cur = 0;
                    count = 0;
                    dot = false;
                    num = false;
                break;
                //------------------------------------
                case DIVISION:
                    equal = false;
                    if(num)
                        try
                        {
                            cal(ans,cur,count,state);
                        }
                        catch(int n)
                        {
                            cout<<n<<endl;
                            break;
                        }
                    if(!begin&&num) cout<<"="<<ans<<endl;
                    begin = false;

                    state[MOP] = OP_DIV;
                    state[MCIRCLE] = CIR_DF;

                    cur = 0;
                    count = 0;
                    dot = false;
                    num = false;
                break;
                //------------------------------------
                case PERCENTAGE:
                    if(num)
                    {
                        cur = cur/100;
                        try
                        {
                            cal(ans,cur,count,state);
                        }
                        catch(int n)
                        {
                            cout<<n<<endl;
                            break;
                        }
                        cur = 0;
                        count = 0;
                        dot = false;
                        num = false;
                    }
                break;

                case POWER:
                    if(num)
                    {
                        try
                        {
                            cal(ans,cur,count,state);
                        }
                        catch(int n)
                        {
                            cout<<n<<endl;
                            break;
                        }
                        cur = 0;
                        count = 0;
                        dot = false;
                        num = false;
                        state[MOP] = OP_POW;
                    }
                break;

                //------------------------------------
                case EQUAL:
                    cal(ans,cur,count,state);
                    cur = 0;
                    cout<<ans<<endl;
                    equal = true;
                break;


                case DOT:
                    dot = true;
                break;

                case AC:
                    equal = false;
                    begin = true;
                    ans = 0;
                    cur = 0;
                    dot = false;
                    count = 0;
                    state[MOP] = OP_ADD;
                    state[MCIRCLE] = CIR_DF;
                break;

                case SIN:
                    if(equal)
                    {
                        ans = 0;
                        equal = false;
                    }
                    state[MCIRCLE] = CIR_SIN;
                break;

                case COS:
                    if(equal)
                    {
                        ans = 0;
                        equal = false;
                    }
                    state[MCIRCLE] = CIR_COS;
                break;

                case TAN:
                    if(equal)
                    {
                        ans = 0;
                        equal = false;
                    }
                    state[MCIRCLE] = CIR_TAN;
                break;

                case ARCSIN:
                    if(equal)
                        {
                            ans = 0;
                            equal = false;
                        }
                    state[MCIRCLE] = CIR_ASIN;
                break;

                case ARCCOS:
                    if(equal)
                        {
                            ans = 0;
                            equal = false;
                        }
                    state[MCIRCLE] = CIR_ACOS;
                break;

                case ARCTAN:
                    if(equal)
                        {
                            ans = 0;
                            equal = false;
                        }
                    state[MCIRCLE] = CIR_ATAN;
                break;

                case RAD:
                    state[MRAD] = 1;
                break;
                case DEG:
                    state[MRAD] = 0;
                break;

                case MEMORY:
                flag = 1;
                break;

                case FUNCTION:
                flag = 0;
                break;

                default:
                    if(c>='0'&&c<='9')
                    {
                        if(equal)
                        {
                            ans = 0;
                            equal = false;
                        }
                        num = true;
                        cur = cur * 10 + c - '0';
                        begin = false;
                        count += dot;
                    }
                    else cout<<"Unsupported Input"<<endl;
                break;
            }
        else
            switch(c)
            {
                case HELP:
                    help(flag);
                break;

                case QUIT:
                    quit = true;
                break;

            //------------------------------------
                case ADDITION:
                    equal = false;
                    if(num)
                        try
                        {
                            cal(ans,cur,count,state);
                        }
                        catch(int n)
                        {
                            cout<<n<<endl;
                            break;
                        }
                    if(!begin&&num) cout<<"="<<ans<<endl;
                    begin = false;

                    state[MOP] = OP_ADD;
                    state[MCIRCLE] = CIR_DF;

                    cur = 0;
                    count = 0;
                    dot = false;
                    num = false;
                break;
                //------------------------------------
                case SUBTRACTION:
                    equal = false;
                    if(num)
                        try
                        {
                            cal(ans,cur,count,state);
                        }
                        catch(int n)
                        {
                            cout<<n<<endl;
                            break;
                        }
                    if(!begin&&num) cout<<"="<<ans<<endl;
                    begin = false;

                    state[MOP] = OP_MIN;
                    state[MCIRCLE] = CIR_DF;

                    cur = 0;
                    count = 0;
                    dot = false;
                    num = false;
                break;
                //------------------------------------
                case MULTIPLY:
                    equal = false;
                    if(num)
                        try
                        {
                            cal(ans,cur,count,state);
                        }
                        catch(int n)
                        {
                            cout<<n<<endl;
                            break;
                        }
                    if(!begin&&num) cout<<"="<<ans<<endl;
                    begin = false;

                    state[MOP] = OP_MUL;
                    state[MCIRCLE] = CIR_DF;

                    cur = 0;
                    count = 0;
                    dot = false;
                    num = false;
                break;
                //------------------------------------
                case DIVISION:
                    equal = false;
                    if(num)
                        try
                        {
                            cal(ans,cur,count,state);
                        }
                        catch(int n)
                        {
                            cout<<n<<endl;
                            break;
                        }
                    if(!begin&&num) cout<<"="<<ans<<endl;
                    begin = false;

                    state[MOP] = OP_DIV;
                    state[MCIRCLE] = CIR_DF;

                    cur = 0;
                    count = 0;
                    dot = false;
                    num = false;
                break;
                //------------------------------------
                case PERCENTAGE:
                    if(num)
                    {
                        cur = cur/100;
                        try
                        {
                            cal(ans,cur,count,state);
                        }
                        catch(int n)
                        {
                            cout<<n<<endl;
                            break;
                        }
                        cur = 0;
                        count = 0;
                        dot = false;
                        num = false;
                    }
                break;
                //------------------------------------
                case EQUAL:
                    cal(ans,cur,count,state);
                    cur = 0;
                    cout<<ans<<endl;
                    equal = true;
                break;


                case DOT:
                    dot = true;
                break;

                case AC:
                    equal = false;
                    begin = true;
                    cur = 0;
                    dot = false;
                    count = 0;
                    state[MOP] = OP_ADD;
                    state[MCIRCLE] = CIR_DF;
                    state[MRAD] = 1;
                break;

                case MEMORY:
                flag = 1;
                break;

                case FUNCTION:
                flag = 0;
                break;

                default:
                    if(c>='0'&&c<='9')
                    {
                        if(equal)
                        {
                            ans = 0;
                            equal = false;
                        }
                        num = true;
                        cur = cur * 10 + c - '0';
                        begin = false;
                        count += dot;
                    }
                    else cout<<"Unsupported Input"<<endl;
                break;
            }
    }
}
