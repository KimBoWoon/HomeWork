#include <stdio.h>
#include "ArrayList.h"

void ListInit(List * plist)
{
	plist->numOfData=0;
	plist->curPosition=0;
}
void LInsert(List * plist, LData data)
{
	if(plist->numOfData>LIST_LEN)
		printf("���� �뷮 �ʰ�\n");

	plist->arr[plist->numOfData++]=data;
}

LData LFirst(List * plist, LData * pdata)
{
	if(plist->numOfData==0)
		return FALSE;

	plist->curPosition=1;
	*pdata=plist->arr[0];

	return TRUE;
}
LData LNext(List * plist, LData * pdata)
{
	if(plist->curPosition>=plist->numOfData)
		return FALSE;

	*pdata=plist->arr[plist->curPosition];
	plist->curPosition++;

	return TRUE;
}

LData LRemove(List * plist)
{
	int i;
	LData backUp=plist->arr[plist->curPosition];

	for(i=plist->curPosition-1;i<plist->numOfData-1;i++)
		plist->arr[i]=plist->arr[i+1];

	(plist->numOfData)--;
	(plist->curPosition)--;

	return backUp;
}
int LCount(List * plist)	{	return plist->numOfData;	}
void PrintOfElem(List * plist)
{
	LData pdata;
	if(LFirst(plist, &pdata))    // ù ��° ������ ��ȸ
	{
		printf("%d ", pdata);
		
		while(LNext(plist, &pdata))    // �� ��° ������ ������ ��ȸ
			printf("%d ", pdata);
	}
}