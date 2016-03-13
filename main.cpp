//四则运算2
#include<iostream>
using namespace std;
#include<stdlib.h>
#include<time.h>
void display(int number,int column,int mul,int range,int neg,int remainder)//先自定义输出函数
{
    int first[1000],second[1000],opt[1000];//分别代表第一个数、第二数和运算符
    for(int i=0;i<number;i++)//随机两个生成运算操作数
    { 
        int m=1;//避免题目重复并初始化
        first[i]=rand()%range;//随机产生第一个数
        second[i]=rand()%range;//随机产生第二个数
        if(mul==0)//没有乘除法
        {  
            opt[i]=rand()%2;//随机生成0~1的数字，分别表示加减
        }
        if(mul==1)
        {
            opt[i]=rand()%4;//随机生成0~3的数字，分别表示加减乘除
        }
        for(int j=0;j<i;j++)
        {
            if(first[j]==first[i]&&second[j]==second[i]&&opt[j]==opt[i])//比较新产生的算式与原来的是否重复
            {
                i=i-1;
                m=0;
            }
        }
        while(m)//若算式都不重复则输出
        {
            switch(opt[i])
            {
            case 0:
                cout<<first[i]<<"+"<<second[i]<<"=";break;
            case 1:
                if(neg==0)//0表示减法结果不允许出现负数，1表示允许出现负数
                {
                    int temp;//中间变量
                    if(first[i]<second[i])
                    {
                        temp=first[i];
                        first[i]=second[i];
                        second[i]=temp;
                    }
                    cout<<first[i]<<"-"<<second[i]<<"=";break;
                }
                else
                {
                    cout<<first[i]<<"-"<<second[i]<<"=";break;
                }
            case 2:
                cout<<first[i]<<"*"<<second[i]<<"=";break;
            case 3:
                if(second[i]==0)//避免分母为零的处理
                {  
                    i=i-1;break;
                }
                else
                {
                    if(remainder==0)//0表示除法不允许余数
					{
						if(first[i]%second[i]==0)
						{
							cout<<first[i]<<"/"<<second[i]<<"=";break;
						}
						else
						{
							i=i-1;break;
						}
					}
                else if(remainder==1)//1表示除法允许有余数
                {
                    if(first[i]%second[i]!=0)
                    {
                        cout<<first[i]<<"/"<<second[i]<<"=";break;
                    }
                    else
                    {
                        i=i-1;break;
                    }
                }
                }
            }
            if((i+1)%column==0)
            {
                cout<<endl;
            }
            else
            {
                cout<<"\t";
            }
            break;//跳出循环
        }
    }
}
void main()
{
    srand((unsigned) time(NULL));//初始化随机数发生器，使得每次运行生成的随机数不同
    int number;//定制题目数量
    int column;//控制输出的列数
    int mul;//是否需要乘除法
    int range;//控制数值范围
    int neg;//控制减法结果是否允许有负数
    int remainder;//控制除法是否允许有余数
    cout<<"请输入要打印的题目数量:";
    cin>>number;
    cout<<endl;
    cout<<"请输入要输出的列数(1-10):";
    cin>>column;
    cout<<endl;
    cout<<"请输入正整数的数值范围(即最大数):";
    cin>>range;
    cout<<endl;
    cout<<"是否有乘除法(0表示没有；1表示有):";
    cin>>mul;
    cout<<endl;
    if(mul==1)//有乘除法时继续选择是否除法有无余数，否则没必要选择除法有无余数
    {
        cout<<"除法有无余数(0表示没有；1表示有):";
        cin>>remainder;
    }
    else
    {
        remainder=1;
    }
    cout<<endl;
    cout<<"加减有无负数(0表示没有；1表示有):";
    cin>>neg;
    cout<<endl;
    display(number,column,mul,range,neg,remainder);//调用函数
}