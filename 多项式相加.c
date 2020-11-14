#include <stdio.h>
#include <stdlib.h>

#define ERROR 0

typedef struct LNode
{
	int coef;
	int expn;
	struct LNode *next;
} LNode, *LinkList;

void CreateList_L(LinkList *L)
{
	printf("The sum of Node:");
	int n;
	scanf("%d", &n);
	if (n <= 0)
		return;
	*L = (LinkList)malloc(sizeof(LNode));
	if (!(*L))
		exit(ERROR);
	(*L)->next = NULL;
	LinkList r = *L;
	for (int i = 0; i < n; ++i)
	{
		LinkList p = (LinkList)malloc(sizeof(LNode));
		if (!p)
			exit(ERROR);
		printf("Input coef and expn:");
		scanf("%d %d", &p->coef, &p->expn);
		p->next = NULL;
		r->next = p;
		r = p;
	}
}

void Display(LinkList L)
{
	LNode *q = L->next;
	if (NULL != q)
		printf("%dX^%d", q->coef, q->expn);
	q = q->next;
	while (NULL != q)
	{
		printf(" + %dX^%d", q->coef, q->expn);
		q = q->next;
	}
	printf("\n");
}

void MergeList_L(LinkList *La, LinkList *Lb, LinkList *Lc)
{
	*Lc = *La;
	LinkList pa = (*La)->next, pb = (*Lb)->next, pc = *La;
	while (pa && pb)
	{
		if (pa->expn < pb->expn)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else if (pa->expn == pb->expn)
		{
			pa->coef += pb->coef;
			pc->next = pa;
			pc = pa;
			pa = pa->next;
			pb = pb->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;
	free(*Lb);
}

int main()
{
	LinkList q1 = (LinkList)malloc(sizeof(LNode)), q2 = (LinkList)malloc(sizeof(LNode)), ans = (LinkList)malloc(sizeof(LNode));
	printf("Enter pa:\n");
	CreateList_L(&q1);
	printf("p1 is:\n");
	Display(q1);
	printf("Enter Pb:\n");
	CreateList_L(&q2);
	printf("p2 is:\n");
	Display(q2);

	MergeList_L(&q1, &q2, &ans);
	printf("\nans is: ");
	Display(ans);
	return 0;
}