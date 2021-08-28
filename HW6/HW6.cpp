//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "HW6.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

String line = "";

struct BSTreeNode
{   struct BSTreeNode *leftchild;
	int data;
	struct BSTreeNode *rightchild;
};

struct BSTreeNode * root;

struct BSTreeNode * SearchBST( struct BSTreeNode *tree, int x)
{   if (tree == NULL) return NULL;
	if (x == tree->data) return tree;
	if (x < tree-> data) return SearchBST(tree->leftchild, x);
	return SearchBST(tree->rightchild, x);
}

struct BSTreeNode * NewBSTNode(int x)
{   struct BSTreeNode * node = new struct BSTreeNode;
	node -> data = x;
	node -> leftchild = NULL;
	node -> rightchild = NULL;
	return node;
}

struct BSTreeNode * InsertBSTree(struct BSTreeNode * node , int x)
{   if (node == NULL) return NewBSTNode(x);
	if (x < node -> data) node -> leftchild = InsertBSTree( node -> leftchild, x);
	else node -> rightchild = InsertBSTree(node -> rightchild, x);
	return node;
}

struct BSTreeNode * InorderSucc(struct BSTreeNode * node)
{   struct BSTreeNode * p = node;
	while (p->leftchild != NULL) p = p -> leftchild;
	return p;
}

struct BSTreeNode * DeleteBSTree( struct BSTreeNode * node, int x)
{   struct BSTreeNode * temp;
	if (node == NULL) return node;
	if (x < node -> data) node -> leftchild = DeleteBSTree(node->leftchild, x);
	else if (x > node->data) node -> rightchild = DeleteBSTree(node->rightchild, x);
	else // x found in node
	{   if ((node ->leftchild == NULL) || (node->rightchild == NULL))
		{   temp = node -> leftchild ? node->leftchild : node->rightchild;
			if (temp == NULL)// node is a leaf itself
			{   temp = node;
				node = NULL;
			}
			else * node = * temp; // copy the contents of the only/non-empty child
			free(temp);
		}
		else // node has two children
		{   temp = InorderSucc(node->rightchild);
			node -> data = temp -> data;
			node -> rightchild = DeleteBSTree(node->rightchild, temp-> data);
		}
	}
	return node;
}

struct BTreeNode
{   struct BTreeNode * leftchild;
	char data;
	struct BTreeNode * rightchild;
};

struct BTreeNode *root_0;


void inorder( struct BSTreeNode * node)
{
	if(node != NULL)
	{
		inorder(node->leftchild);
		line += IntToStr(node->data)+"_";
		inorder(node->rightchild);
	}

}

void postorder( struct BSTreeNode * node)
{
	if(node != NULL)
	{
		inorder(node->leftchild);
		inorder(node->rightchild);
		line += IntToStr(node->data)+"_";
	}
}

void preorder( struct BSTreeNode * node)
{
	if(node != NULL)
	{   line += IntToStr(node->data)+"_";
		inorder(node->leftchild);
		inorder(node->rightchild);

	}
}

struct QNode
{   struct BSTreeNode * treenode;
	struct QNode * next;
};

struct QNode * front, *rear;

void AddQueue(struct BSTreeNode * Tnode)
{   struct QNode * node;
	node = (struct QNode *) malloc (sizeof(struct QNode));
	node->treenode = Tnode;
	node->next = NULL;
	if (front == NULL) front = node;
	else rear->next = node;
	rear = node;
}

void QueueEmpty()
{
	ShowMessage("Queue Empty!");
}

struct BSTreeNode * DeleteQueue()
{   struct BSTreeNode *Tnode;
	struct QNode *old_front;
	if (rear == NULL) QueueEmpty();
	else
	{   Tnode = front->treenode;
		old_front = front;
		front = front->next;
		free(old_front);
		return Tnode;
	}
}

void LevelOrder(struct BSTreeNode *node)
{   AddQueue(node);
	while (front != NULL)
	{   node = DeleteQueue();
		line += IntToStr(node->data)+"_";
		if (node->leftchild != NULL) AddQueue(node->leftchild);
		if (node->rightchild != NULL) AddQueue(node->rightchild);
    }

}


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{	int n = StrToInt(Edit3->Text);
	int range = StrToInt(Edit4->Text);
	int * data = new int [n];

	for (int i= 0; i < n; i++)
	{   data[i] = rand() % range +1;
		root = InsertBSTree(root,data[i]);
	}
	line = "";
	inorder(root);
	Form1->Memo1->Lines->Add(line);
	line = "";
	postorder(root);
	Form1->Memo2->Lines->Add(line);
	line = "";
	preorder(root);
	Form1->Memo3->Lines->Add(line);
	line = "";
	LevelOrder(root);
	Form1->Memo4->Lines->Add(line);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int x = StrToInt(Edit1->Text);
	root = InsertBSTree(root, x);
	line = "";
	inorder(root);
	Form1->Memo1->Lines->Add(line);
    line = "";
	postorder(root);
	Form1->Memo2->Lines->Add(line);
	line = "";
	preorder(root);
	Form1->Memo3->Lines->Add(line);
    line = "";
	LevelOrder(root);
	Form1->Memo4->Lines->Add(line);


}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{   int x = StrToInt(Edit2->Text);
	root = DeleteBSTree(root, x);
	line = "";
	inorder(root);
	Form1->Memo1->Lines->Add(line);
    line = "";
	postorder(root);
	Form1->Memo2->Lines->Add(line);
	line = "";
	preorder(root);
	Form1->Memo3->Lines->Add(line);
    line = "";
	LevelOrder(root);
	Form1->Memo4->Lines->Add(line);

}
//---------------------------------------------------------------------------
