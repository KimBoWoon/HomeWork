#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable : 4996)

typedef struct Point{
	int x;
	int y;
}Point;

typedef struct CafeInfo{
	int x;
	int y;
	int number;
}CafeInfo;

int x_sort(const void *a, const void *b);
int y_sort(const void *a, const void *b);
int ySumSearch(Point* point, int i);
void monotoneWalkway(CafeInfo* cafe, Point* point, int pointNum);
Point* part_y_Sort(Point* point, int i, int ySum);


int main(void){
	FILE *inFile;
	inFile = fopen("input.txt", "r");

	int numTestCases, pointNum, cafeNum;
	int T = 0;
	int i = 0;
	int j = 0;
	Point* point;
	CafeInfo* cafe;
	int *cafe_Question;

	fscanf(inFile, "%d", &numTestCases);

	for (T = 0; T < numTestCases; T++){
		fscanf(inFile, "%d", &pointNum);
		point = (Point*)malloc(sizeof(Point)*pointNum);
		cafe = (CafeInfo*)malloc(sizeof(CafeInfo)*pointNum);

		for (i = 0; i < pointNum; i++){
			fscanf(inFile, "%d %d", &point[i].x, &point[i].y);
			//cout << point[i].x << " " << point[i].y<<endl;
		}
		fscanf(inFile, "%d", &cafeNum);
		cafe_Question = (int*)malloc(sizeof(int)*cafeNum);
		for (i = 0; i < cafeNum; i++)
			fscanf(inFile, "%d", &cafe_Question[i]);

		qsort(point, pointNum, sizeof(struct Point), x_sort);

		monotoneWalkway(cafe, point, pointNum);

		for (i = 0; i < cafeNum; i++){

			for (j = 0; j < pointNum; j++){
				if (cafe_Question[i] == cafe[j].number){
					printf("%d %d\n", cafe[j].x, cafe[j].y);
					break;
				}
			}
		}
	}
	return 0;
}

void monotoneWalkway(CafeInfo* cafe, Point* point, int pointNum){

	int now_y = 0;
	int cafeNum = 0;
	Point *cafe_ysort;
	int i = 0;
	int j = 0;
	int ySum;
	for (i; i < pointNum; i++){
		if (point[i].x == point[i + 1].x){
			//y비교
			ySum = ySumSearch(point, i);  //x가 같은 y 갯수.
			cafe_ysort = (Point*)malloc(sizeof(Point)*ySum);
			cafe_ysort = part_y_Sort(point, i, ySum);

			qsort(cafe_ysort, ySum, sizeof(struct Point), y_sort);
			if (now_y == cafe_ysort[0].y){

				for (j = 0; j < ySum; j++){
					cafe[cafeNum].x = cafe_ysort[j].x;
					cafe[cafeNum].y = cafe_ysort[j].y;
					cafe[cafeNum].number = cafeNum + 1;
					now_y = cafe_ysort[j].y;
					cafeNum++;
				}
			}
			else{
				for (j = ySum - 1; j >= 0; j--){
					cafe[cafeNum].x = cafe_ysort[j].x;
					cafe[cafeNum].y = cafe_ysort[j].y;
					cafe[cafeNum].number = cafeNum + 1;
					now_y = cafe_ysort[j].y;
					cafeNum++;
				}
			}
			i = i + ySum - 1;
		}
		else{
			cafe[cafeNum].x = point[i].x;
			cafe[cafeNum].y = point[i].y;
			cafe[cafeNum].number = cafeNum + 1;
			cafeNum++;
			now_y = point[i].y;
		}
	}
}

int ySumSearch(Point* point, int i){

	int sum = 1;
	while (point[i].x == point[i + 1].x){
		sum++;
		i++;
	}
	return sum;
}

Point* part_y_Sort(Point* point, int i, int ySum){
	int a = 0;
	Point* ySort = (Point*)malloc(sizeof(Point)*ySum);
	for (a = 0; a < ySum; a++){
		ySort[a].x = point[i].x;
		ySort[a].y = point[i].y;
		i++;
	}
	return ySort;
}

int x_sort(const void *a, const void *b) // 넘어온 포인터는 void
{
	const int *m, *n;
	m = (const int *)a;
	n = (const int *)b;
	if (*m < *n) // *(const int*) : 강제 int 포인터로 형변환
	{
		return (-1);
	}
	else if (*m == *n)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

int y_sort(const void *a, const void *b) // 넘어온 포인터는 void
{
	Point* a1 = (Point*)a;
	Point* a2 = (Point*)b;

	if (a1->y < a2->y) // *(const int*) : 강제 int 포인터로 형변환
	{
		return (-1);
	}
	else if (a1->y == a2->y)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

//#include <iostream>
//#include <cstdlib>
//#include <fstream>
//using namespace std;
//struct pos {
//	int x;
//	int y;
//	int c;
//};
//pos p[100000];
//
//int compareVAL(const void *arg1, const void *arg2) {
//	return ((*(pos *)arg1).x != (*(pos *)arg2).x) ?
//		(*(pos *)arg1).x - (*(pos *)arg2).x :
//		(*(pos *)arg1).y - (*(pos *)arg2).y;
//}
//
//void cafeSort(pos *p, int n) {
//	int tempValue = 0;//값이 바뀔 때 임의적으로 저장해놓는 int
//	pos tmp;
//	for (int i = 0; i <= n; i++) {
//		for (int j = 0; j <= n - 1; j++) {
//			if (p[j].x != p[j + 1].x) {//x 값이 바뀔 때 tempValue에 값을 저장한다.
//				tempValue = p[j].y;//y값을 저장해 논다.
//			}
//			else if (p[j].x == p[j + 1].x) {
//				if (tempValue > p[j].y) {//내림차순 해줘야한다.
//					if (p[j].y < p[j + 1].y) {
//						tmp = p[j];
//						p[j] = p[j + 1];
//						p[j + 1] = tmp;
//					}
//				}
//				else if (tempValue < p[j].y) {//오름차순 해줘야한다.
//					if (p[j].y > p[j + 1].y) {
//						tmp = p[j];
//						p[j] = p[j + 1];
//						p[j + 1] = tmp;
//					}
//				}
//			}
//		}
//	}
//}
//
//int main(void) {
//	ifstream in;
//	in.open("input.txt");
//	int testcases, numOfcafe, QAnum, QAcafeNum;
//	in >> testcases;
//	for (int i = 0; i < testcases; i++) {
//		in >> numOfcafe;
//		p[0].x = 0, p[0].y = 0;//출발지 설정
//		for (int j = 1; j <= numOfcafe; j++) { in >> p[j].x >> p[j].y; }
//		qsort(p, numOfcafe + 1, sizeof(pos), compareVAL);
//		cafeSort(p, numOfcafe);//cafeSort
//		in >> QAnum;
//		for (int j = 0; j < QAnum; j++) {
//			in >> QAcafeNum;
//			cout << p[QAcafeNum].x << ' ' << p[QAcafeNum].y << endl;
//		}
//	}
//}