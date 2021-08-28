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

//全域變數global variable，宣告data是一個靜態陣列，在這個陣列裡面存放100000筆資料
int data [100000];
//為了避免傳入已排序的資料，所以多宣告一個變數original_data，之後會再將original_data的資料複製到data裡
int original_data [100000];
int n;

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

void SelectionSort(int data[], int n) // 需要的參數有data陣列，和有多少資料要參與sorting
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
	{   //要由小到大排序，有錯就中斷
		if (data[i] > data[i+1]) break;
	}
	//上面中斷之後，i的值就無法到達n-1
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
{   // n 進來只是字元，還要再轉為數字
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
		{   //? 為什麼這樣設range最大會是1000
			data[i] = rand() % range + 1;
			if (CheckBox1->Checked)
				//字串可以相加，i不是字串，要轉成字串
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
		//為什麼要多一個get data?
		//把data和original_data兩個陣列的值傳入，再把original_data的資料複製到data去，共n個數
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

