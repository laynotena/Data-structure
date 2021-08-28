//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "IMF_HW1.h"
#include <time.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//SWAP(Macro)
# define SWAP(x, y, t) (t=x, x=y, y=t)

//�����ܼ�global variable�A�ŧidata�O�@���R�A�}�C�A�b�o�Ӱ}�C�̭��s��100000�����
int data [100000];
//���F�קK�ǤJ�w�ƧǪ���ơA�ҥH�h�ŧi�@���ܼ�original_data�A����|�A�Noriginal_data����ƽƻs��data��
int original_data [100000];
int n;

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

void SelectionSort(int data[], int n) // �ݭn���ѼƦ�data�}�C�A�M���h�ָ�ƭn�ѻPsorting
{   int i, j, min, temp;
		for (i = 0; i < n; i++)
		{  min = i;
			for (j = i+1; j < n; j++)
			{ if (data[j] < data[min])
				{ min =j;
				}
			}
			/*
			temp = data[i];
			data[i] = data[min];
			data[min] = temp;
			*/
			SWAP(data[i], data[min], temp);
		}
}

void BubbleSort(int data[], int n)
{   int i, j, temp;
		for (i = n-1; i >= 0; i--)
		{   for (j = 1; j< i+1; j++)
				{   if (data[j-1] >data[j])
						SWAP(data[j-1], data[j], temp);
				}
		}

}

void printData( int data[], int n, int flag)
{   int i;
		if (flag == 1)
		{	for (i = 0; i < n; i++)
			{   Form1->Memo1->Lines->Add("data["+IntToStr(i)+"] = "+IntToStr(data[i]));
			}
		}
		else if (flag==2)
		{   for (i = 0; i < n; i++)
			{   Form1->Memo2->Lines->Add("data["+IntToStr(i)+"] = "+IntToStr(data[i]));
			}
		}
		else //(flag == 3)
		{   for (i = 0; i < n; i++)
			{   Form1->Memo3->Lines->Add("data["+IntToStr(i)+"] = "+IntToStr(data[i]));

			}

		}
}

void RanData (int data[], int n, int range)
{ int i;
		for (i = 0; i < n; i++)
		{   data[i] = rand() % range +1;
		}
}

void getData( int data[], int original_data[], int n)
{   int i;
	for (i = 0; i < n; i++) data[i] = original_data[i];
}

void CheckData( int data[], int n, int flag)
{   int i;
	for (i = 0; i < n-1 ; i++)
	{   //�n�Ѥp��j�ƧǡA�����N���_
		if (data[i] > data[i+1]) break;
	}
	//�W�����_����Ai���ȴN�L�k��Fn-1
	if (i == n-1)
	{   if(flag == 2)
			Form1->Memo2->Lines->Add("Correctly Sorted.");
		else if (flag == 3)
			Form1->Memo3->Lines->Add("Correctly Sorted.");
	}
	else
	{   if (flag == 2)
			Form1->Memo2->Lines->Add("NOT Sorted.");
		else if (flag ==3)
			Form1->Memo3->Lines->Add("NOT Sorted.");
	}


}


int BinarySearch (int data[], int n, int target)
{   int left = 0, right = n, middle;
		while (left <= right)
		{   middle = (left+right)/2;
			if (data[middle] == target)
				return middle;
			else if (data[middle] < target)
				left = middle+1;
			else
				right = middle-1;
		}
		return -1;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{   // n �i�ӥu�O�r���A�٭n�A�ର�Ʀr
	n = StrToInt(Edit1->Text);
	int range = StrToInt(Edit2->Text);
	int i;
		//?
		srand( time(NULL) );
		clock_t t_begin, t_end;
		t_begin = clock();
		RanData (original_data, n, range);
		t_end = clock();
		if (CheckBox1->Checked) printData(original_data, n, 1);
		Form1->Memo1->Lines->Add("CPU time (sec.) = "+FloatToStr((float)(t_end - t_begin)/CLOCKS_PER_SEC));
		/*
		for (i = 0; i < n; i++)
		{   //? ������o�˳]range�̤j�|�O1000
			data[i] = rand() % range + 1;
			if (CheckBox1->Checked)
				//�r��i�H�ۥ[�Ai���O�r��A�n�ন�r��
				Form1->Memo1->Lines->Add("data["+IntToStr(i)+"] = "+IntToStr(data[i]));
		*/

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{   clock_t t_begin, t_end;
		t_begin = clock();
		getData(data, original_data, n);
		SelectionSort(data, n);
		t_end = clock();
		if (CheckBox1->Checked) printData(data, n, 2);
		if (CheckBox2->Checked) CheckData(data, n, 2);
		Form1->Memo2->Lines->Add("CPU time (sec.) = "+FloatToStr((float)(t_end - t_begin)/CLOCKS_PER_SEC));

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{   clock_t t_begin,t_end;
		t_begin = clock();
		//������n�h�@��get data?
		//��data�Moriginal_data��Ӱ}�C���ȶǤJ�A�A��original_data����ƽƻs��data�h�A�@n�Ӽ�
		getData(data, original_data, n);
		BubbleSort(data, n);
		t_end = clock();
		if (CheckBox1->Checked) printData(data,n,3);
		if (CheckBox2->Checked) CheckData(data, n,3);
		Form1->Memo3->Lines->Add("CPU time (sec.) = "+FloatToStr((float)(t_end - t_begin)/CLOCKS_PER_SEC));




}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{   int target = StrToInt(Edit3->Text);
	int success = -1;
	success = BinarySearch(data,n,target);
	if (success >= 0 && success < n)
		Memo4->Lines->Add(IntToStr(target)+" has been found in data["+IntToStr(success)+"]!");
	else
		Memo4->Lines->Add(IntToStr(target)+" has NOT been found!");
}
//---------------------------------------------------------------------------

