#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort(int *TargetNum, int len);
void Swap(int *num1, int *num2);
int main(int argc, char *argv[]) {

	int *Target;
	int i = 0;
	int len;
	float execute_Time;
	time_t start_Time = 0, end_Time = 0;
	srand(time(NULL));

	if (argc == 1) {
		printf("Please Enter like %s (len)", argv[0]);
		exit(1);
	}
	else if (argc > 2) {
		printf("Too much Argument..!! Please Enter like %s (len)", argv[0]);
		exit(1);
	}
	else {
		
		len = atoi(argv[1]);
		Target = (int *)malloc(sizeof(int)*len);
		for (i = 0; i < len; i++) {
			Target[i] = rand() % len;
		}
	}
	start_Time = clock();
	BubbleSort(Target, len);
	end_Time = clock();

	execute_Time = (float)(end_Time - start_Time) / (CLOCKS_PER_SEC);

	printf("Execute Time : %lf\n", execute_Time);
	return 0;
}
void BubbleSort(int *TargetNum, int len) {

	int *Target;
	int check_changed = 0;
	int i, j;
	int index1, index2;
	Target = (int *)malloc(sizeof(int)*len);
	
	Target = TargetNum;

	for (i = 0; i < len; i++) {
		for (j = 0; j < len - i - 1; j++) {
			index1 = Target[j];
			index2 = Target[j + 1];
			if (index1 > index2) {
				Swap(&Target[j], &Target[j + 1]);
				check_changed = 1;
			}
			else {
				continue;
			}
		}
		if (check_changed == 0) {
			break;
		}
	}


}
void Swap(int *num1, int *num2) {

	int temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}