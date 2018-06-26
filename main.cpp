//
//  main.cpp
//  poject1
//
//  Created by 20161104571 on 18/6/26.
//  Copyright © 2018年 20161104571. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class result
{
private:
    int id;
    string name;
    float score[5];
    float ave;
public:
    result(int i,string n,float s[5])
    {
        float sum=0,max=s[0],min=s[0];
        int j;
        id=i;
        name.assign(n);
        for(j=0;j<5;j++)
        {
            score[j]=s[j];
            if(max<s[j])
                max=s[j];
            if(min>s[j])
                min=s[j];
            sum+=s[j];
        }
        ave=(sum-min-max)/5;
    }
    float get_ave()
    {
        return ave;
    }
    int get_id()
    {
        return id;
    }
    string get_name()
    {
        return name;
    }
    void display()
    {
        int i;
        cout<<"编号:"<<id<<"姓名:"<<name<<endl;
        cout<<"最终评分="<<ave<<endl;
        cout<<"评委打分:";
        for(i=0;i<5;i++)
            cout<<score[i]<<"   "<<endl;
    }
};
int main()
{
    int i,j;
    int m;
    int idsize;
    cout<<"请输入参赛选手人数"<<endl;
    cin>>m;
    idsize=m;
    int *id;
    id=new int[idsize];
    vector<float>aver;
    vector<string>name;
    vector<vector<float>>x(m,vector<float>(5));
    cout<<"请输入所有参赛选手信息"<<endl;
    for(i=0;i<m;i++)
    {
        string na;
        cout<<"第"<<i+1<<"名选手编号"<<endl;
        cin>>id[i];
        cout<<"第"<<i+1<<"名选手姓名"<<endl;
        cin>>na;
        name.push_back(na);
    }
    cout<<endl<<endl<<"==========比赛开始请裁判打分==========="<<endl<<endl;
    for(i=0;i<m;i++)
    {
        cout<<"第"<<i+1<<"名选手打分"<<endl;
        for(j=0;j<5;j++)
        {
            cout<<"第"<<i+1<<"名选手打分"<<endl;
            cin>>x[i][j];
        }
    }
    cout<<endl<<endl<<"========去掉一个最高分，去掉一个最低分，选手得分======="<<endl<<endl;
    for(i=0;i<m;i++)
    {
        float s[5];
        for(j=0;j<5;j++)
            s[j]=x[i][j];
        result a(id[i],name[i],s);
        a.display();
        aver.push_back(a.get_ave());
    }
    for(i=1;i<m;i++)
        for (j=i;j>0;j--)
        {
            if(aver[j]<aver[j-1])
            {
                float temp=aver[j];
                aver[j]=aver[j-1];
                aver[j-1]=temp;
                int sum=id[j];
                id[j]=id[j-1];
                id[j-1]=sum;
                string pname=name[j];
                name[j]=name[j-1];
                name[j-1]=pname;
            }
        }
    cout<<endl<<endl<<"======按名次显示得分======="<<endl<<endl;
    cout<<"名次"<<""<<"编号"<<""<<"姓名"<<""<<"得分"<<endl;
    for(i=m-1;i>=0;i--)
        cout<<"第"<<m-1<<"名"<<"   "<<id[i]<<"    "<<name[i]<<"    "<<aver[i]<<endl;
    
}
