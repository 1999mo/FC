/* 개인 명세서 처리 (입력 / 정령 / 출력)
~개인 명세서를 정의하고(연습과 동일한 구조)
~구조체 배열(10개)을 선언
~5개 이상 10개 미만의 데이터를 입력한 후
~입력된 자료를 3번 출력한다(single line)
~~입력 자료를 그대로 출력
~~입력 자료를 이름순(내림차순)으로 출력
~~입력 자료를 생년월일순(올림차순)으로 출력 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

struct date
{
	int year;
	int month;
	int day;
};

struct indi
{
	char name[20];
	struct date birth;
	int sex;
	char address[30];
	char ph_number[15];
};

void printIndi(struct indi array);

int main(void)
{
	struct indi array[10];
	
	int i, j, k = 0;
	
	int arr[5] = {0, 1, 2, 3, 4};
	
	strcpy(array[0].name, "AAA"), array[0].birth.year=1995, array[0].birth.month=10, array[0].birth.day=20, array[0].sex=1, strcpy(array[0].address, "서울시 서초구 서초3동 1719-9"), strcpy(array[0].ph_number, "01011112222");
	strcpy(array[1].name, "CCC"), array[1].birth.year=1996, array[1].birth.month=12, array[1].birth.day=10, array[1].sex=1, strcpy(array[1].address, "서울시 서초구 서초3동 1719-8"), strcpy(array[1].ph_number, "01012342222");
	strcpy(array[2].name, "DDD"), array[2].birth.year=1993, array[2].birth.month=02, array[2].birth.day=12, array[2].sex=0, strcpy(array[2].address, "서울시 서초구 서초3동 1719-7"), strcpy(array[2].ph_number, "01056782222");
	strcpy(array[3].name, "BBB"), array[3].birth.year=1994, array[3].birth.month=04, array[3].birth.day=13, array[3].sex=1, strcpy(array[3].address, "서울시 서초구 서초3동 1719-6"), strcpy(array[3].ph_number, "01011119012");
	strcpy(array[4].name, "EEE"), array[4].birth.year=1991, array[4].birth.month=06, array[4].birth.day=16, array[4].sex=0, strcpy(array[4].address, "서울시 서초구 서초3동 1719-5"), strcpy(array[4].ph_number, "01011113333");
	
	printf("이름 연  월 일 성별           주소                전화번호\n");
	
	for(i = 0; i < 5; i++)
	{
		printIndi(array[i]);
	}
	
	for(i = 0; i < 4; i++)
	{
		if(strcmp(array[arr[i]].name, array[arr[i + 1]].name) > 0)
		{
			//printf("i arr[i] arr[i+1] : %d %d %d\n", i, arr[i], arr[i + 1]);
			//printf("array[arr[i]].name, array[arr[i + 1]].name : %s %s\n", array[arr[i]].name, array[arr[i + 1]].name);
			
			//strcpy(str, array[i].name);
			j = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = j;
			//strcpy(array[i].name = array[i + 1].name);
			//strcpy(array[i + 1].name = str);
			i -= 2;
			if(i < 0) i = -1;
			k++;
			
			if(k > 50)
			{
				system("pause");
			}
		}
	}
	
	printf("\n");
	
	for(i = 0; i < 5; i++)
	{
		printIndi(array[arr[i]]);
	}
	
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 3;
	arr[4] = 4;
	
	for(i = 0; i < 4; i++)
	{
		if(array[arr[i]].birth.year > array[arr[i + 1]].birth.year)
		{
			//printf("i arr[i] arr[i+1] : %d %d %d\n", i, arr[i], arr[i + 1]);
			//printf("array[arr[i]].year, array[arr[i + 1]].year : %d %d\n", array[arr[i]].birth.year, array[arr[i + 1]].birth.year);
			
			j = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = j;
			i -= 2;
			if(i < 0) i = -1;
		}
		else if(array[arr[i]].birth.year == array[arr[i + 1]].birth.year)
		if(array[arr[i]].birth.month > array[arr[i + 1]].birth.month)
		{
			//printf("i arr[i] arr[i+1] : %d %d %d\n", i, arr[i], arr[i + 1]);
			//printf("array[arr[i]].name, array[arr[i + 1]].name : %s %s\n", array[arr[i]].name, array[arr[i + 1]].name);
			
			j = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = j;
			i -= 2;
			if(i < 0) i = -1;
		}
		else if(array[arr[i]].birth.month == array[arr[i + 1]].birth.month)
		if(array[arr[i]].birth.day > array[arr[i + 1]].birth.day)
		{
			//printf("i arr[i] arr[i+1] : %d %d %d\n", i, arr[i], arr[i + 1]);
			//printf("array[arr[i]].name, array[arr[i + 1]].name : %s %s\n", array[arr[i]].name, array[arr[i + 1]].name);
			
			j = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = j;
			i -= 2;
			if(i < 0) i = -1;
		}
	}
	
	printf("\n");
	
	for(i = 0; i < 5; i++)
	{
		printIndi(array[arr[i]]);
	}
	
	system("pause");
	
	return 0;
}

void printIndi(struct indi array)
{
	printf("%s %d %d %d ", array.name, array.birth.year, array.birth.month, array.birth.day);
	array.sex ? printf("남자") : printf("여자");
	printf(" %s %s\n", array.address, array.ph_number);
}
