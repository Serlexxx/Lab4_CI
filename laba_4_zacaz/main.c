#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>  //��� bool
#include <time.h> //��� ������������
struct networkdevice {
	char name[128];
	char IPv4[16];
	bool onlline;
};

void GnomeSort(struct networkdevice* base, size_t num, size_t size, int compare);
void ShellSort(struct networkdevice* base, size_t num, size_t size, int compare);
void DoubleSort(struct networkdevice* base, size_t num, size_t size, int compare);

int main(void)                 
{
	int size_struct = 0; //������ ������� ��������
	struct networkdevice* net = NULL;
	system("chcp 1251"); //��� ������ ��������
	bool BigExit = 1; //�������� ��� ������� ����� ������ � ������� ����� �������� ���� � ����� ��������
	while (BigExit) {
		printf("��� ������� �������?\n");
		printf("1.���� ������\n2.����� ������\n3.��������� ������\n0.�����\n");
		int bigswitch;
		scanf("%d", &bigswitch);
		switch (bigswitch)
		{
		case 1:
		{
			bool miniExit = 1;
			
			while (miniExit) {
				
				printf("���� ������?\n");
				printf("1.� ����������\n2.�� �����\n3.��������� ������\n0.�����\n");
				int miniswitch;
				scanf("%d", &miniswitch);
				switch (miniswitch)
				{
				case 1: 
				{
					int ind;
					bool exit = 1;
					while (exit) {
						printf("���� ���������?\n������� ����� �� 0..");
						printf("%d", size_struct);
						scanf("%d", &ind);
						if (ind < 0 || ind > size_struct) {
							printf("���������� �����!\n");
						}
						else {
							exit = 0;
						}
					}
					size_struct++;
					struct networkdevice* net_new = (struct networkdevice*)malloc(size_struct*sizeof(struct networkdevice)); //���������� ����� �������
					for (int i = 0; i < ind; i++) {
						strcpy(net_new[i].name, net[i].name);
						strcpy(net_new[i].IPv4, net[i].IPv4);
						net_new[i].onlline = net[i].onlline;
					}	
					for (int i = ind; i < (size_struct-1); i++) {
						strcpy(net_new[i+1].name, net[i].name);
						strcpy(net_new[i+1].IPv4, net[i].IPv4);
						net_new[i+1].onlline = net[i].onlline;
					}
					free(net);
					net = net_new;
					printf("������� ��������:	");
					scanf("%s\b", &net[ind].name);
					fflush(NULL);
					printf("������� IPv4:	");
					for (int i = 0; i < 15; i++) {
						if ((i+1) % 4 == 0) {
							net[ind].IPv4[i] = '.';
						}
						else {
							fflush(NULL);
							scanf("\r%c\b", &net[ind].IPv4[i]);
						}
					}
					net[ind].IPv4[15] = '\0';
					printf("������� ��������� ���� (1/0):	");
					fflush(NULL);
					scanf("\r%d\b", &net[ind].onlline);
					break;
				}
				case 2:
				{
					FILE* fp;
					if((fp=fopen("test.txt", "r"))== NULL){
						printf("���� �� �������!\n");
					}
					else {
						struct networkdevice net_fp;
						while ((fscanf(fp, "%s%s%d", net_fp.name, net_fp.IPv4, &net_fp.onlline)) != EOF) {
							size_struct++;
							struct networkdevice* net_new = (struct networkdevice*)malloc(size_struct * sizeof(struct networkdevice)); //���������� ����� �������
							for (int i = 0; i < (size_struct-1); i++) {
								strcpy(net_new[i].name, net[i].name);
								strcpy(net_new[i].IPv4, net[i].IPv4);
								net_new[i].onlline = net[i].onlline;
							}
							free(net);
							net = net_new;
							strcpy(net[size_struct - 1].name, net_fp.name);
							strcpy(net[size_struct - 1].IPv4, net_fp.IPv4);
							net[size_struct - 1].onlline = net_fp.onlline;
						}

						fclose(fp);
					}
					break;
				}
				case 3:
				{
					int ind;
					bool exit = 1;
					while (exit) {
						printf("���� ���������?\n������� ����� �� 0..");
						printf("%d", size_struct);
						scanf("%d", &ind);
						if (ind < 0 || ind > size_struct) {
							printf("���������� �����!\n");
						}
						else {
							exit = 0;
						}
					}
					size_struct++;
					struct networkdevice* net_new = (struct networkdevice*)malloc(size_struct * sizeof(struct networkdevice)); //���������� ����� �������
					for (int i = 0; i < ind; i++) {
						strcpy(net_new[i].name, net[i].name);
						strcpy(net_new[i].IPv4, net[i].IPv4);
						net_new[i].onlline = net[i].onlline;
					}
					for (int i = ind; i < (size_struct - 1); i++) {
						strcpy(net_new[i + 1].name, net[i].name);
						strcpy(net_new[i + 1].IPv4, net[i].IPv4);
						net_new[i + 1].onlline = net[i].onlline;
					}
					free(net);
					net = net_new;
					int size_name = rand() % 20 + 5;
					for (int i = 0; i < size_name; i++) {
						char c = rand() % (122-97+1) + 97; //��������� ���������� �������� �� ������� ����
						net[ind].name[i] = c;
					}
					net[ind].name[size_name] = '\0';
					for (int i = 0; i < 15; i++) {
						if ((i + 1) % 4 == 0) {
							net[ind].IPv4[i] = '.';
						}
						else {
							net[ind].IPv4[i] = rand() % (57 - 48 + 1) + 48; //��������� ���������� IPv4 �� ������� ����
						}
					}
					net[ind].IPv4[15] = '\0';
					int Bool = -10 + rand() % 20; //��������� ���������� ��������� ����
					if (Bool > 0) {
						net[ind].onlline = 1;
					}
					else {
						net[ind].onlline = 0;
					}
					break;
				}
				case 0: 
				{
					miniExit = 0;
					system("cls"); //������� �������
					break;
				}
				default:
					printf("���������� �����!\n"); //���� ����� ����� �������� �� ������ ����
					break;
				}
			}
			break;
		}
		case 2:
		{
			if (size_struct != 0) {
			
				bool miniexit = 1;

				while (miniexit) {
					printf("1.������ � �������\n2.����� � ����\n0.�����\n");
					int miniswitch;
					scanf("%d", &miniswitch);
					switch (miniswitch)
					{
					case 1:
					{
						for (int i = 0; i < size_struct; i++) {
							printf("%d. %s\t%s\t%d\n", i, net[i].name, net[i].IPv4, net[i].onlline);
						}
						break;
					}
					case 2:
					{
						//to do input file
						FILE* fp;
						if ((fp = fopen("test.txt", "a")) == NULL) {
							printf("���� �� �������!\n");
						}
						else {
							struct networkdevice net_fp;
							for (int i = 0; i < size_struct; i++) {
								fprintf(fp, "\n%s %s %d", net[i].name, net[i].IPv4, net[i].onlline);
							}
							
							fclose(fp);
						}
						break;
					}
					case 0:
					{
						miniexit = 0;
						system("cls");
						break;
					}
					default:
						printf("���������� �����!\n");
						break;
					}
				}
			}
			else {
				printf("�������� ������!\n");
			}
			break;
		}
		case 3:
		{
			if (size_struct != 0) {

				bool miniexit = 1;

				while (miniexit) {
					printf("1.������� ��������\n2.����������\n0.�����\n");
					int miniswitch;
					scanf("%d", &miniswitch);
					switch (miniswitch)
					{
					case 1:
					{
						int ind = 0;
						int cnt = 0;
						for (int i = 0; i < size_struct; i++) {
							printf("%d. %s\t%s\t%d\n", i, net[i].name, net[i].IPv4, net[i].onlline);
						}
						bool miniminiExit = 1;
						while (miniminiExit) {
							printf("������� � ������ ������� �������� ���� �������:   ");
							scanf("%d", &ind);
							if (ind < 0 || ind > (size_struct-1)) {
								printf("�� ����� ����������� �����!\n���������� �����!\n");
							}
							else {
								miniminiExit = 0;
							}
						}
						miniminiExit = 1;
						while (miniminiExit) {
							printf("������� ������� ���� ������� ��������� �� 1 �� %d:   ", (size_struct-1-ind));
							scanf("%d", &cnt);
							if ((ind+cnt)>(size_struct-1)) {
								printf("�� ����� ����������� �����!\n���������� �����!\n");
							}
							else {
								miniminiExit = 0;
							}
						}
						struct networkdevice* net_new = (struct networkdevice*)malloc((size_struct-cnt) * sizeof(struct networkdevice)); //���������� ����� �������
						for (int i = 0; i < ind; i++) {
							strcpy(net_new[i].name, net[i].name);
							strcpy(net_new[i].IPv4, net[i].IPv4);
							net_new[i].onlline = net[i].onlline;
						}
						for (int i = (ind + cnt); i < size_struct; i++) {
							strcpy(net_new[i-cnt].name, net[i].name);
							strcpy(net_new[i-cnt].IPv4, net[i].IPv4);
							net_new[i-cnt].onlline = net[i].onlline;
						}
						free(net);
						net = net_new;
						size_struct -= cnt;
						break;
					}
					case 2:
					{
						printf("1.������ ����������\n2.���������� �����\n3.������������� ���������� �������\n0.�����\n");
						int miniminiswitch;
						scanf("%d", &miniminiswitch);
						switch (miniminiswitch)
						{
						case 1:
						{
							printf("1.�� ��������� ����\n2.�� IPv4\n3.�� ��������\n0.�����\n");
							int miniminiminiswitch;
							clock_t begin;
							clock_t end;
							scanf("%d", &miniminiminiswitch);
							
							switch (miniminiminiswitch)
							{
							case 1: {
								begin = clock;
								GnomeSort(net, size_struct, sizeof(struct networkdevice), miniminiminiswitch);
								end = clock();
								break;
							}
							case 2:{
								begin = clock;
								GnomeSort(net, size_struct, sizeof(struct networkdevice), miniminiminiswitch);
								end = clock();
								break;
							}
							case 3: {
								begin = clock;
								GnomeSort(net, size_struct, sizeof(struct networkdevice), miniminiminiswitch);
								end = clock();
								break;
							}
							default:
								printf("���������� �����!\n");
								break;
							}
							double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
							printf("����� ����������:	%f\n", time_spent);
							break;
						}
						case 2:
						{
							printf("1.�� ��������� ����\n2.�� IPv4\n3.�� ��������\n0.�����\n");
							int miniminiminiswitch;
							clock_t begin;
							clock_t end;
							scanf("%d", &miniminiminiswitch);
							switch (miniminiminiswitch)
							{
							case 1: {
								begin = clock;
								ShellSort(net, size_struct, sizeof(struct networkdevice), miniminiminiswitch);
								end = clock();
								break;
							}
							case 2: {
								begin = clock;
								ShellSort(net, size_struct, sizeof(struct networkdevice), miniminiminiswitch);
								end = clock();
								break;
							}
							case 3: {
								begin = clock;
								ShellSort(net, size_struct, sizeof(struct networkdevice), miniminiminiswitch);
								end = clock();
								break;
							}
							default:
								printf("���������� �����!\n");
								break;
							}
							double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
							printf("����� ����������:	%f\n", time_spent);
							break;
						}
						case 3:
						{
							printf("1.�� ��������� ����\n2.�� IPv4\n3.�� ��������\n0.�����\n");
							int miniminiminiswitch;
							clock_t begin;
							clock_t end;
							scanf("%d", &miniminiminiswitch);
							switch (miniminiminiswitch)
							{
							case 1: {
								begin = clock;
								DoubleSort(net, size_struct, sizeof(struct networkdevice), miniminiminiswitch);
								end = clock();
								break;
							}
							case 2: {
								begin = clock;
								DoubleSort(net, size_struct, sizeof(struct networkdevice), miniminiminiswitch);
								end = clock();
								break;
							}
							case 3: {
								begin = clock;
								DoubleSort(net, size_struct, sizeof(struct networkdevice), miniminiminiswitch);
								end = clock();
								break;
							}
							default:
								printf("���������� �����!\n");
								break;
							}
							double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
							printf("����� ����������:	%f\n", time_spent);
							break;
						}
						default:
							printf("���������� �����!\n");
							break;
						}
						break;
					}
					case 0:
					{
						miniexit = 0;
						system("cls");
						break;
					}
					default:
						printf("���������� �����!\n");
						break;
					}
				}
			}
			else {
				printf("������������ ������!\n");
			}
			break;
		}
		case 0:
		{
			printf("����������!\n");
			free(net);
			BigExit = 0;
			break;
		}
		default:
			printf("���������� �����!\n"); //���� ����� ����� �������� �� ������ ����
			break;
		}
	}
	return 0;
}

void GnomeSort(struct networkdevice* base, size_t num, size_t size, int compare) {
	int i = 0;
	struct networkdevice tmp;
	while (i < num) {
		switch (compare)
		{
		case 1:
		{
			if (i == 0 || base[i - 1].onlline <= base[i].onlline)
				++i;
			else {
				tmp = base[i];
				base[i] = base[i - 1];
				base[i - 1] = tmp;
				--i;
			}
			break;
		}
		case 2:
		{
			while (i < num) {
				if (i == 0 || strcmp(base[i - 1].IPv4,base[i].IPv4)<=0)
					++i;
				else {
					tmp = base[i];
					base[i] = base[i - 1];
					base[i - 1] = tmp;
					--i;
				}
			}
		}
		case 3:
		{
			while (i < num) {
				if (i == 0 || strcmp(base[i - 1].name, base[i].name) <= 0)
					++i;
				else {
					tmp = base[i];
					base[i] = base[i - 1];
					base[i - 1] = tmp;
					--i;
				}
			}
		}
		}
		
	}
}

void ShellSort(struct networkdevice* base, size_t num, size_t size, int compare)
{
	int i, j, step;
	struct networkdevice tmp;
	for (step = num / 2; step > 0; step /= 2) {
		for ( i = step; i < num; i++)
		{
			tmp = base[i];
			for ( j = i; j >= step; j -= step)
			{
				if (compare == 1) {
					if (tmp.onlline < base[j - step].onlline)
						base[j] = base[j - step];
					else
						break;
				}
				else {
					if(compare == 2)
					{
						if (strcmp(tmp.IPv4, base[j - step].IPv4) < 0)
							base[j] = base[j - step];
						else
							break;
					}
					else {
						if (compare == 3) {
							if (strcmp(tmp.name, base[j - step].name) < 0)
								base[j] = base[j - step];
							else
								break;
						}
					}
				}
				
			}
			base[j] = tmp;
		}
	}
}

void DoubleSort(struct networkdevice* base, size_t num, size_t size, int compare) {
	int minindex = 0, maxindex = 0;
	auto min;
	auto max;
	for (int j = 0; j < num / 2; j++)
	{
		if (compare == 1) {
			min = 1; max = 0;
		}
		else {
			if (compare == 2) {
				min = "999.999.999.999";
				max = "000.000.000.000";
			}
			else {
				if (compare == 3) {
					min = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
					max = "a";
				}
			}
		}
		struct networkdevice tmp;
		for (int i = j; i < num - j; i++)
		{
			if (compare == 1) {
				if (min > base[i].onlline)
				{
					min = base[i].onlline;
					minindex = i;
				}
				if (base[i].onlline > max)
				{
					max = base[i].onlline;
					maxindex = i;
				}
			}
			else {
				if (compare == 2) {
					if (strcmp(min, base[i].IPv4)>0)
					{
						min = base[i].IPv4;
						minindex = i;
					}
					if (strcmp(base[i].IPv4, max) > 0)
					{
						max = base[i].IPv4;
						maxindex = i;
					}
				}
				else {
					if (compare == 3) {
						if (strcmp(min, base[i].name) > 0)
						{
							min = base[i].name;
							minindex = i;
						}
						if (strcmp(base[i].name, max) > 0)
						{
							max = base[i].name;
							maxindex = i;
						}
					}
				}
			}
			
		}

		tmp = base[j];
		if (j == maxindex)
		{
			maxindex = minindex;
		}
		if (compare == 1) {
			base[j].onlline = min;
			base[minindex] = tmp;

			tmp = base[num - j - 1];
			base[num - j - 1].onlline = max;
			base[maxindex] = tmp;
		}
		else {
			if (compare == 2) {
				strcpy(base[j].IPv4,min);
				base[minindex] = tmp;

				tmp = base[num - j - 1];
				strcpy(base[num - j - 1].IPv4,max);
				base[maxindex] = tmp;
			}
			else {
				if (compare == 3) {
					strcpy(base[j].name, min);
					base[minindex] = tmp;

					tmp = base[num - j - 1];
					strcpy(base[num - j - 1].name, max);
					base[maxindex] = tmp;
				}
			}
		}
		
	}
}
