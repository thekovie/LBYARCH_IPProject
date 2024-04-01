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

int cmpVec(float *z, float *zASM, size_t size) {
	size_t i;
	for (i = 0; i < size; i++) {
		if (z[i] != zASM[i])
			return 0;
	}
	return 1;
}

int main() {
	srand(time(NULL));
	int option;
	// declare max size for all vectors
	printf("%s\n%s\n%s\n%s\n","[1] 2^20",
						"[2] 2^24",
						"[3] 2^29",
						"[4] Custom");
	printf("Please select option: ");
	scanf_s("%d", &option);
	size_t currSize = 0;

	switch (option) {
		case 1:
			currSize = size1;
			break;
		case 2:
			currSize = size2;
			break;
		case 3:
			currSize = size3;
			break;
		case 4: {
			printf("Please input vector size: ");
			scanf_s("%lld", &currSize);
			break;
			}
	}
	float a = 1;
	printf("Please input scalar variable A: ");
	scanf_s("%f", &a);

	#ifdef _DEBUG
		printf("\n<The program is in debug mode>\n");
	#else
		printf("\n<The program is in release mode>\n");
	#endif

	float *x = (float*)malloc(sizeof(float) * currSize);
	float *y = (float*)malloc(sizeof(float) * currSize);
	float *z = (float*)malloc(sizeof(float) * currSize);
	float *zASM = (float*)malloc(sizeof(float) * currSize);
	fill_vector(x, currSize);
	fill_vector(y, currSize);
	double timesC = 0;
	double timesASM = 0;
	printf("Running saxpy for c 30 times...\n");
	size_t i;
	for (i = 0; i < 30; i++) {
		clock_t start = clock();
		saxpy(a, x, y, z, currSize);
		clock_t end = clock();
		timesC += (double)(end - start) / CLOCKS_PER_SEC;
	}
	timesC /= 30.0;
	timesC *= 1000;

	printf("Running saxpy for asm 30 times...\n");
	for (i = 0; i < 30; i++) {
		clock_t start = clock();
		saxpy_asm(a, x, y, zASM, currSize);
		clock_t end = clock();
		timesASM += (double)(end - start) / CLOCKS_PER_SEC;
	}
	timesASM /= 30.0;
	timesASM *= 1000;

	printf("\nx\n");
	print_vec(x, currSize);
	printf("\ny\n");
	print_vec(y, currSize);
	printf("\nz\n");
	print_vec(z, currSize);
	printf("\nzASM\n");
	print_vec(zASM, currSize);
	printf("\n\nBoth outputs are the same: %d\n", cmpVec(z, zASM, currSize));
	printf("average time for C: %fms\n", timesC);
	printf("average time for ASM: %fms", timesASM);
	free(x);
	free(y);
	free(z);
	free(zASM);
	return 0;
}