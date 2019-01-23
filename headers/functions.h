//This is funtions.h header

#include <fstream>
#include <time.h>

struct node
{
	int val;
	node *next;
};

void pushFront();
void popFront();
void showList();
unsigned int countList(node);

void uploadToFile();
void loadFromFile(node *&,char*);
void newGap(int&);

void combSort(node *&H);

void pushFront(node *&H, int x)
{
	node *p=new node;
	p->val=x;
	p->next=H;
	H=p;
}

void popFront(node *&H)
{
	node *p=H;
	if (p)
	{
		H=p->next;
		delete p;
	}
}

void showList(node *H)
{
	node *p=H;
	while (p)
	{
		std::cout << p->val << " ";
		p=p->next;
	}
}

unsigned int countList(node *H)
{
	unsigned int c=0;
	node *p=H;
	while (p)
	{
		c++;
		p=p->next;
	}	
	return c;
}	

void uploadToFile()
{
	int x;
	srand(time(NULL));	
	std::fstream data ("file.txt", std::ios::out );
	for (int i=0; i<10; i++)
	{
		x=rand()%1000;
		if (rand()%2==1) data << -1*x << std::endl;
		else data << x << std::endl;
	}
}
void loadFromFile(node*&H, char*filename)
{
	std::ifstream data;
	data.open(filename);
	if (data.good())
	{
		int x;
		node *p=H;
		while (!data.eof())
		{
			data >> x;
			pushFront(H,x);
		}
	}
}

void newGap(int &x)
{
	if (x>1) x/=1.3;
	else if (x==0) x=1;
}

void combSort(node *&H)
{
	pushFront(H,0); //pushing up guardian
	node *p1=H, *p2=H, *e=NULL;
	int x=countList(H)-1;
	bool sorted=false;

	while (sorted==false)
	{
		newGap(x);
		p1=H, p2=H;
		for (int i=0; i<x; i++)
		{
			p2=p2->next;
		}
		if (x>1)
		{
			while (p2->next)
			{
				node *e=p1->next, *f=p2->next->next;
				if (p1->next->val > p2->next->val)
				{
					p2->next->next=p1->next->next;
					p1->next=p2->next;
					p2->next=e;
					e->next=f;
				}
				p1=p1->next;
				p2=p2->next;
			}
		}
		else if (x==1)
		{
			node *p1=H,*p2=H;			
			p2=p1->next;
			sorted=true;
			while (p2->next!=e)
			{
				if(p1->next->val > p2->next->val)	
				{
					sorted=false;
					p1->next=p1->next->next;
					p2->next=p2->next->next;
					p1->next->next=p2;
					p1=p1->next;
				}
				else
				{
					p1=p1->next;
					p2=p2->next;
				}
			}
			e=p1->next;
		}
	}
	popFront(H);	
}
