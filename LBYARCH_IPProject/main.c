#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#define size1 1 << 20
#define size2 1 << 24
#define size3 1 << 29

extern void saxpy_asm(float a, float *x, float *y, float *z, size_t size);

void fill_vector(float vec[], size_t size) {
	size_t i;
	for (i = 0; i < size; i++) {
		vec[i] = (rand() / 100.0);
	}
}

void saxpy(float a, float x[], float y[], float z[], size_t size) {
	size_t i;
	for (i = 0; i < size; i++) {
		z[i] = a * x[i] + y[i];
	}
}

void print_vec(float vec[], size_t size) {
	size_t i;
	if (size > 10)
		size = 10;
	printf("first %lld values\n", size);
	for (i = 0; i < size; i++) {
		printf("%.2f ", vec[i]);
	}
	printf("\n");
}

int main() {
	srand(time(NULL));

	// declare max size for all vectors
	size_t currSize = size3;
	float *x = (float*)malloc(sizeof(float) * currSize);
	float *y = (float*)malloc(sizeof(float) * currSize);
	float *z = (float*)malloc(sizeof(float) * currSize);
	float *zASM = (float*)malloc(sizeof(float) * currSize);
	float a = 1.5;
	fill_vector(x, currSize);
	fill_vector(y, currSize);
	/*print_vec(x, currSize);
	print_vec(y, currSize);*/
	double timesC = 0;
	double timesASM = 0;
	size_t i;
	for (i = 0; i < 30; i++) {
		clock_t start = clock();
		saxpy(a, x, y, z, currSize);
		clock_t end = clock();
		timesC += (double)(end - start) / CLOCKS_PER_SEC;
		//printf("\nz\n");
	}
	print_vec(z, currSize);
	timesC /= 30.0;
	timesC *= 1000;
	printf("average time for C: %fms\n", timesC);

	for (i = 0; i < 30; i++) {
		clock_t start = clock();
		saxpy_asm(a, x, y, zASM, currSize);
		clock_t end = clock();
		timesASM += (double)(end - start) / CLOCKS_PER_SEC;
		//printf("\nz\n");
	}
		print_vec(zASM, currSize);
	timesASM /= 30.0;
	timesASM *= 1000;
	printf("average time for ASM: %fms", timesASM);

	free(x);
	free(y);
	free(z);
	return 0;
}