#include <iostream>
#include <fstream>
#include <math.h>
#define N 20
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
    int num_of;
    struct item *head;
    public: 
    calculator(){}
    ~calculator()
    {
    	struct item *pre;
    	pre=head;
    	while(head!=NULL)
    	{
    		delete pre;
    		head=head->next;
    		pre=head;
    	}
    }   //析构函数
    void links(int a,double *);
    void create(int a);//创建链表
    void input(double *);//输入函数
    void outs();//输出函数
    void order();//排序
    void add(struct item *a,struct item *b); //加操作
    void jian(struct item *a,struct item *b);//减 
	struct item * node(){return head;	}; 
	void insert(double cof1,double exp1);//插入 
    
};
void calculator::links(int a, double * line)
{
	create(a);
	input(line);
	order();
}
void calculator::create(int d)
{
	int numoflink;
    num_of=numoflink=d;
    if(numoflink<=0)
    {
    	cout<<"输入错误，退出"<<endl;
    	exit(1);
    }
    numoflink++;
    int counter=0;
    bool h=true;
    struct item *a,*b,*c;
    while(numoflink--)
    {
    	c = new struct item;
    	if (h==true)
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
void calculator::input(double *line)
{
	struct item *a;
	a=head;
	a=a->next;
	int counter=0;
	while(a!=NULL)
	{
		a->cof=line[counter];
		a->exp=line[counter+1];
		a=a->next;
		counter=counter+2;
	}
}
void calculator::outs()
{
	calculator::order();
	struct item *a;
	a=head;
	a=a->next;
	bool h=true;
	while(a!=NULL)
	{
		if(a->cof==0&&a->exp==0)
		{a=a->next;continue;
		}
		if(h==false&&a->cof>0)
		cout<<"+";
		if(a->exp==0)
		{cout<<a->cof;a=a->next;h=false;continue;
		}
		if(a->exp==1)
		{
			if(a->cof==1){
			cout<<"x";
			a=a->next;
			h=false;
			continue;}
			else
			{
				if(a->cof==-1)
				{
					cout<<"-x";
					a=a->next;
	         		h=false;
		        	continue;
				}
				else
				{
				cout<<a->cof<<"x";
				a=a->next;
	    		h=false;
		    	continue;
		        }
			}
		}
		else
		{
			if(a->cof==1)
			{
				cout<<"x^"<<a->exp;
				a=a->next;
				h=false;
				continue;
			}
			else
			{
				if(a->cof==-1)
				{
					cout<<"-x^"<<a->exp;
					a=a->next;
			    	h=false;
			    	continue;
				}
				else
				{
				cout<<a->cof<<"x^"<<a->exp;
				a=a->next;
				h=false;
				continue;
			}
	    	}	
		}
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
				double temp,temp_1;
				temp=a->exp;
				a->exp=b->exp;
				b->exp=temp;
				temp_1=a->cof;
				a->cof=b->cof;
				b->cof=temp_1;
			}
		}
	}
}
void calculator::add(struct item *a,struct item *b)
{
	calculator::create(1);
	a=a->next;
	b=b->next;
	while(a!=NULL&&b!=NULL)
	{
		double temp;
		if(a->exp==b->exp)
		{
			temp=a->cof+b->cof;
			if(fabs(temp)>0.001)
     			calculator::insert(temp,a->exp);
			a=a->next;b=b->next;
		}
		else if(a->exp<b->exp)
		{
			calculator::insert(a->cof,a->exp);
			a=a->next;
		}
		else
		{
			calculator::insert(b->cof,b->exp);
			b=b->next;
		}
	}
	if(a!=NULL)
	b=a;
	while(b!=NULL)
	{
		calculator::insert(b->cof,b->exp);
		b=b->next;
	}
	
}
void calculator::insert(double cof1,double exp1)
{
	static int counter=0;
	struct item *a,*b;
	b=head;
	a=new struct item;
	a->cof=cof1;
	a->exp=exp1;
	while(b->next!=NULL)
	b=b->next;
	b->next=a;
	a->next=NULL;
	counter++;
} 
void calculator::jian(struct item *a,struct item *b) 
{
	struct item *c;
	c=b;
	while(c!=NULL)
	{
		c->cof=c->cof*(-1.0);
		c=c->next;
	}
	calculator::add(a,b);
}
int main ()
{
	ifstream fin;
	fin.open("data.txt");
	char inf[][2]={"+","-"};
	char inf1[4];
	int num[2];double line[N],rank[N],counter=0;
	while(1)
	{
		for(int i=0;i<4;i++)
		{
			calculator obj1,obj2,obj3;
			fin>>inf1[i];
			for(int j=0;j<2;j++)
			fin>>num[j];
			for(int j=0;j<num[0]*2;j++)
			fin>>line[j];
			for(int j=0;j<num[1]*2;j++)
			fin>>rank[j];
			if(inf1[i]==*inf[0])
			{
				obj1.links(num[0],line);
            	obj2.links(num[1],rank);
            	obj3.add(obj1.node(),obj2.node());
             	cout<<"(";
            	obj1.outs();
            	cout<<")+(";
            	obj2.outs();
            	cout<<")";
            	cout<<"=";
            	obj3.outs();	
            	cout<<endl<<endl;
			}
			else
			{
	        	obj1.links(num[0],line);
            	obj2.links(num[1],rank);
            	obj3.jian(obj1.node(),obj2.node());
            	cout<<"(";
            	obj1.outs();
            	cout<<")-(";
            	obj2.outs();
            	cout<<")";
            	cout<<"=";
            	obj3.outs();	
            	cout<<endl<<endl;
			}
    	}break;
    }
	return 0;
}



77777777777777777777777
dddddddddddddddd
