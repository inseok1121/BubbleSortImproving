#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *BubbleMerge(int *Front_Target, int *Back_Target, int front_len, int back_len);
int *BubbleSort(int *TargetNum, int len);
void Swap(int *num1, int *num2);
int main(int argc, char *argv[]) {

	int *Target;
	int *Front_Target, *Back_Target;
	int i = 0;
	int len;
	int front_len, back_len;
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

	front_len = len / 2;
	back_len = len - front_len;
	start_Time = clock();
	Front_Target = BubbleSort(&Target[0], front_len);
	Back_Target = BubbleSort(&Target[front_len], back_len);
	Target = BubbleMerge(Front_Target, Back_Target, front_len, back_len);
	end_Time = clock();

	execute_Time = (float)(end_Time - start_Time) / (CLOCKS_PER_SEC);

	printf("Execute Time : %lf\n", execute_Time);
	return 0;
}
int *BubbleMerge(int *Front_Target, int *Back_Target, int front_len, int back_len) {

	int len;
	int *Full_Target;
	int front_index, back_index, full_index;
	len = front_len + back_len;

	Full_Target = (int *)malloc(sizeof(int)*len);
	front_index = 0;
	back_index = 0;
	full_index = 0;
	while (1) {
		if (full_index == len) {
			break;
		}
		if (front_index != front_len && back_index != back_len) {
			if (Front_Target[front_index] >= Back_Target[back_index]) {
				Full_Target[full_index] = Back_Target[back_index];
				back_index++;
				full_index++;
			}
			else {
				Full_Target[full_index] = Front_Target[front_index];
				front_index++;
				full_index++;
			}
		}
		else {
			if (front_index >= front_len) {
				while (1) {
					Full_Target[full_index] = Back_Target[back_index];
					back_index++;
					full_index++;
					if (back_index == back_len) {
						break;
					}
				}
			}
			else if (back_index >= back_len) {
				while (1) {
					Full_Target[full_index] = Front_Target[front_index];
					front_index++;
					full_index++;
					if (front_index == front_len) {
						break;
					}
				}
			}
		}
	}

	return Full_Target;

}
int *BubbleSort(int *TargetNum, int len) {

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

	return Target;

}
void Swap(int *num1, int *num2) {

	int temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}