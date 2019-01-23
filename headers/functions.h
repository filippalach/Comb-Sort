//This is funtions.h header

void pushFront();
void popFront();
void showList();

struct node
{
	int val;
	node *next;
};

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
