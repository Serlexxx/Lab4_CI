#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <time.h> //��� ������������
#include "Networkdevice.h"



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
					Reallocated(net, size_struct, ind);
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
					Reallocated(net, size_struct, ind);
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
