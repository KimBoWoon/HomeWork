#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#pragma warning(disable:4996)	//scanf�� fscanf�� ����� �����ʱ����� ����

void MenuView();
int InputStudent(FILE *file, int count);	//�л������� �����ϴ� �Լ�
void print(FILE *file, int count);	//�л������� ����ϴ� �Լ�
void fprint(FILE *file, int count);	//�л������� ���Ͽ� ����ϴ� �Լ�
void namesort(FILE *file, int count);	//�л������� �̸������� �����ϴ� �Լ�
void studentidsort(FILE *file, int count);	//�л������� �й������� �����ϴ� �Լ�
void scoresort(FILE *file, int count);	//�л������� ���������� �����ϴ� �Լ�

/*���� ���� �������
���� ������ϰ� ���� �Լ����� �����ϱ����� ���� �������*/