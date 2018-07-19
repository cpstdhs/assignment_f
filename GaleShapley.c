/*
Gale-Shapley Algorithm
2018.07.19 BoB7_Vulnerability_Jung SungJo
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define PEOPLE_NUM 4
#define NOT_MARRIED 0
#define MARRIED 1

typedef struct info {
	int* prefer;
	int married;
}INFO;
int men[4][4] = {
	{0, 1, 2, 3},
	{2, 1, 0, 3}, 
	{3, 2, 1, 0}, 
	{1, 0, 3, 2}
};
int women[4][4] = {
	{1, 0, 2, 3},
	{3, 1, 0, 2},
	{0, 3, 2, 1},
	{2, 1, 3, 0}
};

int all_married(INFO* MAN)
{
	int cnt = 0;
	for (int i = 0; i < PEOPLE_NUM; i++)
	{
		if (MAN[i].married == MARRIED)
			cnt++;
	}
	if (cnt == PEOPLE_NUM) return 1;
	else return 0;
}
void main()
{
	INFO MAN[PEOPLE_NUM] = { {men[0], NOT_MARRIED}, {men[1], NOT_MARRIED}, {men[2], NOT_MARRIED}, {men[3], NOT_MARRIED} };
	INFO WOMAN[PEOPLE_NUM] = { {women[0], NOT_MARRIED}, {women[1], NOT_MARRIED}, {women[2], NOT_MARRIED}, {women[3], NOT_MARRIED} };
	
	for(int j=0; all_married(MAN)!=1;j++) // any mand is unmarried
	{
		for (int i = 0; MAN[i].married == NOT_MARRIED; i++) // man is unmarried
		{
			if (WOMAN[MAN[i].prefer[j]].married == NOT_MARRIED) // if woman is unmarried
			{
				MAN[i].married = MARRIED; // woman and man get married
				WOMAN[MAN[i].prefer[j]].married = MARRIED;
				printf("MAN[%d] married with WOMAN[%d]\n", i, MAN[i].prefer[j]);
			}
			else if (MAN[WOMAN[MAN[i].prefer[j]].prefer[j]].prefer != MAN[i].prefer) // if woman prfer man to her husband
			{
				MAN[i].married = NOT_MARRIED; // woman break up with her husband
				WOMAN[MAN[i].prefer[j]].married = MARRIED; // and marries with new man
				MAN[WOMAN[MAN[i].prefer[j]].prefer[j]].married = MARRIED;
				printf("MAN[%d] broked up and MAN[%d] married with WOMAN[%d]", i, WOMAN[MAN[i].prefer[j]].prefer[j], MAN[i].prefer[j]);
			}
		}
	}
	system("pause");
}