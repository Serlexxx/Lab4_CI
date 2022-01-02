#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <time.h> //для таймирования
#include "Networkdevice.h"



int main(void)                 
{
	int size_struct = 0; //размер массива структур
	struct networkdevice* net = NULL;
	system("chcp 1251"); //для вывода латиницы
	bool BigExit = 1; //значение для вечного цикла работы в котором будет появлять меню и выбор действия
	while (BigExit) {
		printf("Что желаете сделать?\n");
		printf("1.Ввод данных\n2.Вывод данных\n3.Обработна данных\n0.Выход\n");
		int bigswitch;
		scanf("%d", &bigswitch);
		switch (bigswitch)
		{
		case 1:
		{
			bool miniExit = 1;
			
			while (miniExit) {
				
				printf("Ввод откуда?\n");
				printf("1.С клавиатуры\n2.Из файла\n3.Случайные данные\n0.Назад\n");
				int miniswitch;
				scanf("%d", &miniswitch);
				switch (miniswitch)
				{
				case 1: 
				{
					int ind;
					bool exit = 1;
					while (exit) {
						printf("Куда вставляем?\nВведите число от 0..");
						printf("%d", size_struct);
						scanf("%d", &ind);
						if (ind < 0 || ind > size_struct) {
							printf("Попробуйте снова!\n");
						}
						else {
							exit = 0;
						}
					}
					size_struct++;
					Reallocated(net, size_struct, ind);
					printf("Введине название:	");
					scanf("%s\b", &net[ind].name);
					fflush(NULL);
					printf("Введите IPv4:	");
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
					printf("Введите состояние сети (1/0):	");
					fflush(NULL);
					scanf("\r%d\b", &net[ind].onlline);
					break;
				}
				case 2:
				{
					FILE* fp;
					if((fp=fopen("test.txt", "r"))== NULL){
						printf("Файл не отрылся!\n");
					}
					else {
						struct networkdevice net_fp;
						while ((fscanf(fp, "%s%s%d", net_fp.name, net_fp.IPv4, &net_fp.onlline)) != EOF) {
							size_struct++;
							struct networkdevice* net_new = (struct networkdevice*)malloc(size_struct * sizeof(struct networkdevice)); //увеличение длины массива
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
						printf("Куда вставляем?\nВведите число от 0..");
						printf("%d", size_struct);
						scanf("%d", &ind);
						if (ind < 0 || ind > size_struct) {
							printf("Попробуйте снова!\n");
						}
						else {
							exit = 0;
						}
					}
					size_struct++;
					Reallocated(net, size_struct, ind);
					int size_name = rand() % 20 + 5;
					for (int i = 0; i < size_name; i++) {
						char c = rand() % (122-97+1) + 97; //генерация случайного названия по таблице аски
						net[ind].name[i] = c;
					}
					net[ind].name[size_name] = '\0';
					for (int i = 0; i < 15; i++) {
						if ((i + 1) % 4 == 0) {
							net[ind].IPv4[i] = '.';
						}
						else {
							net[ind].IPv4[i] = rand() % (57 - 48 + 1) + 48; //генерация случайного IPv4 по таблице аски
						}
					}
					net[ind].IPv4[15] = '\0';
					int Bool = -10 + rand() % 20; //генерация случайного состояния сети
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
					system("cls"); //очистка консоли
					break;
				}
				default:
					printf("Попробуйте снова!\n"); //если ввели число отличное от выбора меню
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
					printf("1.Ввывод в консоль\n2.Вывод в файл\n0.Назад\n");
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
							printf("Файл не отрылся!\n");
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
						printf("Попробуйте снова!\n");
						break;
					}
				}
			}
			else {
				printf("Выводить нечего!\n");
			}
			break;
		}
		case 3:
		{
			if (size_struct != 0) {

				bool miniexit = 1;

				while (miniexit) {
					printf("1.Удалить элементы\n2.Сортировка\n0.Назад\n");
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
							printf("Введите с какого индекса элемента надо удалить:   ");
							scanf("%d", &ind);
							if (ind < 0 || ind > (size_struct-1)) {
								printf("Вы ввели некоректное число!\nПопробуйте снова!\n");
							}
							else {
								miniminiExit = 0;
							}
						}
						miniminiExit = 1;
						while (miniminiExit) {
							printf("Введите сколько надо удалить элементов от 1 до %d:   ", (size_struct-1-ind));
							scanf("%d", &cnt);
							if ((ind+cnt)>(size_struct-1)) {
								printf("Вы ввели некоректное число!\nПопробуйте снова!\n");
							}
							else {
								miniminiExit = 0;
							}
						}
						struct networkdevice* net_new = (struct networkdevice*)malloc((size_struct-cnt) * sizeof(struct networkdevice)); //увеличение длины массива
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
						printf("1.Гномья сортировка\n2.Сортировка Шелла\n3.Двухсторонняя сортировка выбором\n0.Назад\n");
						int miniminiswitch;
						scanf("%d", &miniminiswitch);
						switch (miniminiswitch)
						{
						case 1:
						{
							printf("1.По состоянию сети\n2.По IPv4\n3.По названию\n0.Назад\n");
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
								printf("Попробуйте снова!\n");
								break;
							}
							double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
							printf("Время выполнения:	%f\n", time_spent);
							break;
						}
						case 2:
						{
							printf("1.По состоянию сети\n2.По IPv4\n3.По названию\n0.Назад\n");
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
								printf("Попробуйте снова!\n");
								break;
							}
							double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
							printf("Время выполнения:	%f\n", time_spent);
							break;
						}
						case 3:
						{
							printf("1.По состоянию сети\n2.По IPv4\n3.По названию\n0.Назад\n");
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
								printf("Попробуйте снова!\n");
								break;
							}
							double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
							printf("Время выполнения:	%f\n", time_spent);
							break;
						}
						default:
							printf("Попробуйте снова!\n");
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
						printf("Попробуйте снова!\n");
						break;
					}
				}
			}
			else {
				printf("Обрабатывать нечего!\n");
			}
			break;
		}
		case 0:
		{
			printf("Досвидания!\n");
			free(net);
			BigExit = 0;
			break;
		}
		default:
			printf("Попробуйте снова!\n"); //если ввели число отличное от выбора меню
			break;
		}
	}
	return 0;
}
