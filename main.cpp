//��������2
#include<iostream>
using namespace std;
#include<stdlib.h>
#include<time.h>
void display(int number,int column,int mul,int range,int neg,int remainder)//���Զ����������
{
    int first[1000],second[1000],opt[1000];//�ֱ�����һ�������ڶ����������
    for(int i=0;i<number;i++)//��������������������
    { 
        int m=1;//������Ŀ�ظ�����ʼ��
        first[i]=rand()%range;//���������һ����
        second[i]=rand()%range;//��������ڶ�����
        if(mul==0)//û�г˳���
        {  
            opt[i]=rand()%2;//�������0~1�����֣��ֱ��ʾ�Ӽ�
        }
        if(mul==1)
        {
            opt[i]=rand()%4;//�������0~3�����֣��ֱ��ʾ�Ӽ��˳�
        }
        for(int j=0;j<i;j++)
        {
            if(first[j]==first[i]&&second[j]==second[i]&&opt[j]==opt[i])//�Ƚ��²�������ʽ��ԭ�����Ƿ��ظ�
            {
                i=i-1;
                m=0;
            }
        }
        while(m)//����ʽ�����ظ������
        {
            switch(opt[i])
            {
            case 0:
                cout<<first[i]<<"+"<<second[i]<<"=";break;
            case 1:
                if(neg==0)//0��ʾ���������������ָ�����1��ʾ������ָ���
                {
                    int temp;//�м����
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
                if(second[i]==0)//�����ĸΪ��Ĵ���
                {  
                    i=i-1;break;
                }
                else
                {
                    if(remainder==0)//0��ʾ��������������
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
                else if(remainder==1)//1��ʾ��������������
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
            break;//����ѭ��
        }
    }
}
void main()
{
    srand((unsigned) time(NULL));//��ʼ���������������ʹ��ÿ���������ɵ��������ͬ
    int number;//������Ŀ����
    int column;//�������������
    int mul;//�Ƿ���Ҫ�˳���
    int range;//������ֵ��Χ
    int neg;//���Ƽ�������Ƿ������и���
    int remainder;//���Ƴ����Ƿ�����������
    cout<<"������Ҫ��ӡ����Ŀ����:";
    cin>>number;
    cout<<endl;
    cout<<"������Ҫ���������(1-10):";
    cin>>column;
    cout<<endl;
    cout<<"����������������ֵ��Χ(�������):";
    cin>>range;
    cout<<endl;
    cout<<"�Ƿ��г˳���(0��ʾû�У�1��ʾ��):";
    cin>>mul;
    cout<<endl;
    if(mul==1)//�г˳���ʱ����ѡ���Ƿ������������������û��Ҫѡ�������������
    {
        cout<<"������������(0��ʾû�У�1��ʾ��):";
        cin>>remainder;
    }
    else
    {
        remainder=1;
    }
    cout<<endl;
    cout<<"�Ӽ����޸���(0��ʾû�У�1��ʾ��):";
    cin>>neg;
    cout<<endl;
    display(number,column,mul,range,neg,remainder);//���ú���
}