#include <stdio.h>

int main() {

	int i;

	printf("[*]Start to Compare..!!\n");
	for (i = 0; i < 10; i++) {
		printf("[*]Original Bubble Sort ");
		system("BubbleSort 10000");
		printf("[*]New Bubble Sort ");
		system("\"New New BubbleSort.exe\" 10000");
	}
}