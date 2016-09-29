#include <stdio.h>
#include <time.h>
// Time variables in millisecond
clock_t StartTime, PreviousTime, CurrentTime, TotalElapsedTime, DiffTime;
// Time variables in second
float dT = 0; // time difference between the current frame and the previous frame
float cT = 0; // current time ( time spent since the execution of the program )

void InitTime(void)
{
	StartTime = CurrentTime = PreviousTime = clock();
	TotalElapsedTime = 0;
	DiffTime = 0;
	dT = 0;
	cT = 0;
}

void UpdateTime(void)
{
	// 현제시간을 다시 측정해서 기록
	CurrentTime = clock();
	TotalElapsedTime = CurrentTime - StartTime;
	DiffTime = CurrentTime - PreviousTime;
	PreviousTime = CurrentTime;
	// 밀리세컨드 단위
	// 업데이트가 불릴때마다의 구간시간을 알고 싶을 때
	dT = double(DiffTime)/CLOCKS_PER_SEC;
	// 프로그램이 시작하고 나서 흐른 전체 시간
	cT = double(TotalElapsedTime)/CLOCKS_PER_SEC;
}

void PrintTime(void)
{
	printf("[Start:%d] [Cur : %d] [Prev: %d]\n", StartTime,
		CurrentTime, PreviousTime);
	printf("[Total:%d] [Diff: %d]\n", TotalElapsedTime, DiffTime);
	printf("dT = %f seconds\n", dT);
	printf("cT = %f seconds\n", cT);
	printf("-------------------------------------------------------\n");
}

int main(int argc, char **argv)
{
	int i=0; int k;
	// 시간 초기화
	InitTime();
	while(++i<6) {
		k = 0;
		// 1억번 ++ 연산
		for(int j=0;j<100000000;j++) { k++;}
		UpdateTime();
		PrintTime();
	}
	return 0;
}
