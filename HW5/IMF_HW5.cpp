//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "IMF_HW5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

struct node
{   int data;
	struct node * next;
};


struct node * first;
struct node * last;
struct node * top;
struct node * front;
struct node * rear;


struct node * NewNode(int element)
{   struct node * p;
	p = new node;
	p -> data = element;
	p -> next = NULL;
	return p;
};


void insertFirst(int element)
{   struct node *p = NewNode(element);
	p -> next = first -> next;
	first -> next = p;
	if (last == first) last = p;
}

void insertLast(int element)
{   struct node *p = NewNode(element);
	p -> next = last -> next;
	last -> next = p;
	last = p;
}

void printList(struct node* first)
{   struct node *p;
	String list = "";
	for (p = first->next ; p!= first ; p = p->next)
		list += IntToStr(p -> data) + "==>";
	Form1->Memo1->Lines->Add(list+"<");
}

struct node *searchTarget(int target)
{   struct node *p;
	for (p = first->next ; (p != first && p->data != target) ; p = p -> next);
	if (p == first) return NULL;
	return p;
}

void insertAfter(int element, struct node *x)
{   struct node *p = NewNode(element);
	p -> next = x -> next;
	x -> next = p;

}

struct node *searchTargetBefore(int target)
{   struct node *p, *q;
	for (q = first, p = first->next ; (p != first && p->data != target) ; q = p, p = p -> next);
	if (p == first) return NULL;
	return q;
}

void deleteAfter(struct node *x)
{	struct node *p = x -> next;
	x -> next = p -> next;
	if (p == last) last = x;
	free(p);

}

void clearList(struct node *first)
{   struct node *p;
	for (p = first -> next; p != first; p = first -> next)
	{   first -> next = p -> next;
		free(p);
	}
	last = first;
}

void push(int element)
{   struct node *p = NewNode(element);
	p -> next = top -> next;
	top -> next = p;

}

void printStack(struct node* first)
{   struct node *p;
	String list = "";
	for (p = first->next ; p!= first ; p = p->next)
		list += IntToStr(p -> data) + "==>";
	Form1->Memo2->Lines->Add(list+"<");
}

int pop()
{   struct node *p = top -> next;
	if (p == top) return -1;
	int result = p -> data;
	top -> next = p -> next;
	free(p);
	return result;
}


void InsertQ(int element)
{   struct node *p = NewNode(element);
	if ( rear == NULL)
	{front = p;
	 rear = p;
	}
	else if (front == NULL) front = p;
	else rear -> next = p ;
	rear = p;
}



int DeleteQ()
{   struct node *p;
	int element;
	if (front == NULL)
	{
		return -1;
	}
	else
	{   p = front;
		front = front -> next;
		element = p -> data;
		free(p);
		return element;
    }

}

void printQueue(struct node* first)
{   struct node *p;
	String list = "";
	for (p = first ; p!= NULL ; p = p->next)
		list += IntToStr(p -> data) + "==>";
	Form1->Memo3->Lines->Add(list+"<");
}


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{	first = NewNode(0);
	first->next = first;
	last = first;

	top = NewNode(0);
	top -> next = top;

	front = NewNode(0);
	front -> next = front;



}



//---------------------------------------------------------------------------


void __fastcall TForm1::Button7Click(TObject *Sender)
{	int n = StrToInt(Edit3->Text);
	int range = StrToInt(Edit4->Text);
	int * data = new int [n];
	String line = "";
	for (int i= 0; i < n; i++)
	{   data[i] = rand() % range +1;
		line += IntToStr(data[i])+"_";
		insertLast(data[i]);
	}
	Form1->Memo1->Lines->Add(IntToStr(n)+" random numbers :"+line);
	printList(first);



}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{   int element = StrToInt(Edit1->Text);
	insertFirst(element);
	printList(first);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{   int element = StrToInt(Edit1->Text);
	insertLast(element);
	printList(first);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{   int target = StrToInt(Edit2->Text);
	struct node *x;
	x = searchTarget(target);
	if (x) Form1->Memo1->Lines->Add(IntToStr(x ->data)+" has been found.");
	else Form1->Memo1->Lines->Add(IntToStr(target)+" has NOT been found.");


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{   int target = StrToInt(Edit2->Text);
	int element = StrToInt(Edit1->Text);
	struct node *x;
	x = searchTarget(target);
	if (x)
	{	insertAfter(element, x);
		printList(first);
	}
	else Form1->Memo1->Lines->Add(IntToStr(target)+" has NOT been found.");


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{   int target = StrToInt(Edit2->Text);
	int element = StrToInt(Edit1->Text);
	struct node *x;
	x = searchTargetBefore(target);
	if (x)
	{	insertAfter(element, x);
		printList(first);
	}
	else Form1->Memo1->Lines->Add(IntToStr(target)+" has NOT been found.");



}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{   int target = StrToInt(Edit2->Text);
	struct node *x;
	x = searchTargetBefore(target);
	if (x)
	{	deleteAfter(x);
		printList(first);
	}
	else Form1->Memo1->Lines->Add(IntToStr(target)+" has NOT been found.");


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{   clearList(first);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{   int element = StrToInt(Edit5->Text);
	push(element);
	printStack(top);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{   int result = pop();
	if (result != -1) printStack(top);
	else Form1->Memo2->Lines->Add("Stack is empty.");
	Label6->Caption = "pop result = " +IntToStr(result);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::TabSheet1Show(TObject *Sender)
{
	TabSheet2->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TabSheet3Show(TObject *Sender)
{
	TabSheet4->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TabSheet5Show(TObject *Sender)
{
    TabSheet6->Show();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button11Click(TObject *Sender)
{   int element = StrToInt(Edit7->Text);
	InsertQ(element);
	printQueue(front);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{   int result = DeleteQ();
	if (result != -1) printQueue(front);
    else Form1->Memo3->Lines->Add("Queue is empty.");

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button13Click(TObject *Sender)
{   int n = StrToInt(Edit6->Text);
	int range = StrToInt(Edit8->Text);
	int * data = new int [n];
	String line = "";
	for (int i= 0; i < n; i++)
	{   data[i] = rand() % range +1;
		line += IntToStr(data[i])+"_";
		InsertQ(data[i]);
	}
	Form1->Memo3->Lines->Add(IntToStr(n)+" random numbers :"+line);
	printQueue(front);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button14Click(TObject *Sender)
{   int n = StrToInt(Edit9->Text);
	int range = StrToInt(Edit10->Text);
	int * data = new int [n];
	String line = "";
	for (int i= 0; i < n; i++)
	{   data[i] = rand() % range +1;
		line += IntToStr(data[i])+"_";
		push(data[i]);
	}
	Form1->Memo2->Lines->Add(IntToStr(n)+" random numbers :"+line);
	printStack(top);


}
//---------------------------------------------------------------------------

