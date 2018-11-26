#include <iostream>
#include <string.h>
using namespace std; 
class calculator
{
	private:
	struct item
	{
		double cof;
		double exp;
		struct item *next;
    };
    struct item *head;
    public: 
    calculator(){}
    ~calculator()
    {
    	struct item *pre;
    	pre=head->next;
    	while(head!=NULL)
    	{
    		delete head;
    		head=pre;
    		pre=pre->next;
    	}
    }   //析构函数
    void links();
    void create();//创建链表
    void input();//输入函数
    void outs();//输出函数
    void order();//排序
};
void calculator::links()
{
	create();
	input();
	order();
	outs();
}
void calculator::create()
{
    int numoflink;
    cout<<"请输入项数:";
    cin>>numoflink;
    if(numoflink<=0)
    {
    	cout<<"输入错误，退出"<<endl;
    	exit(1);
    }
    cin>>numoflink;
    numoflink++;
    int counter=0;
    bool h=true;
    struct item *a,*b,*c;
    while(numoflink--)
    {
    	c = new struct item;
    	if (h=true)
    	{
    		a=b=c;
    		c->next=NULL;
    		h=false;
    	}
    	else
    	{
    		b->next=c;
    		c->next=NULL;
    		b=c;
    	}
   	}
   	head=a;
}
void calculator::input()
{
	struct item *a;
	a=head;
	a=a->next;
	int counter=0;
	while(a!=NULL)
	{
		cout<<"第"<<counter+1<<"项的系数";
		cin>>a->cof;
		cout<<"第"<<counter+1<<"项的指数";
		cin>>a->exp;
		a=a->next;
	}
}
void calculator::outs()
{
	struct item *a;
	a=head;
	a=a->next;
	while(a!=NULL)
	{
		if(a->exp==0)
		cout<<a->cof;
	    if(a->cof>0)
	    cout<<"+"<<a->cof<<"X^"<<a->exp;
	    else
	    cout<<a->cof<<"X^"<<a->exp;
	    a=a->next;
	}
}
void calculator::order()
{
	struct item *a,*b;
	a=head;
	a=a->next;
	for(;a!=NULL;a=a->next)
	{
		for(b=a;b!=NULL;b=b->next)
		{
			if(a->exp>=b->exp)
			{
				int temp,temp_1;
				temp=a->exp;
				a->exp=b->exp;
				b->exp=temp;
				temp_1=a->cof;
				a->cof=b->cof;
				b->cof=temp_1;
			}
		}
	}
	head=a;
}

int main ()
{
	calculator obj1,obj2;
	obj1.links();
	obj2.links();
	return 0;
}
