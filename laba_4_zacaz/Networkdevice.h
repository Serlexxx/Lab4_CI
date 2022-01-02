#pragma once
#include <stdbool.h>  //для bool
#include <stdio.h>


struct networkdevice {
	char name[128];
	char IPv4[16];
	bool onlline;
};


void GnomeSort(struct networkdevice* base, size_t num, size_t size, int compare);
void ShellSort(struct networkdevice* base, size_t num, size_t size, int compare);
void DoubleSort(struct networkdevice* base, size_t num, size_t size, int compare);

void Reallocated(struct networkdevice* base, size_t num, int ind);