#include "Networkdevice.h"


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
				if (i == 0 || strcmp(base[i - 1].IPv4, base[i].IPv4) <= 0)
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
		for (i = step; i < num; i++)
		{
			tmp = base[i];
			for (j = i; j >= step; j -= step)
			{
				if (compare == 1) {
					if (tmp.onlline < base[j - step].onlline)
						base[j] = base[j - step];
					else
						break;
				}
				else {
					if (compare == 2)
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
					if (strcmp(min, base[i].IPv4) > 0)
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
				strcpy(base[j].IPv4, min);
				base[minindex] = tmp;

				tmp = base[num - j - 1];
				strcpy(base[num - j - 1].IPv4, max);
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

void Reallocated(struct networkdevice* base, size_t num, int ind) {
	struct networkdevice* net_new = (struct networkdevice*)malloc(num * sizeof(struct networkdevice)); //увеличение длины массива
	for (int i = 0; i < ind; i++) {
		strcpy(net_new[i].name, base[i].name);
		strcpy(net_new[i].IPv4, base[i].IPv4);
		net_new[i].onlline = base[i].onlline;
	}
	for (int i = ind; i < (num - 1); i++) {
		strcpy(net_new[i + 1].name, base[i].name);
		strcpy(net_new[i + 1].IPv4, base[i].IPv4);
		net_new[i + 1].onlline = base[i].onlline;
	}
	free(base);
	base = net_new;
}