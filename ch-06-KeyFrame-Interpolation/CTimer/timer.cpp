#include<time.h>
#include "timer.h"

CTimer::CTimer() : mET(0.0), mDT(0.0), mWorking(false) { }

void CTimer::Init(void) {
	mWorking = true;
	mStartTime = mCurrentTime = mPreviousTime = clock();
	mTotalElapsedTime = mDiffTime = 0;
	mDT = mET = 0.0;
}

void CTimer::Reset(void) {
	mStartTime = mCurrentTime = mPreviousTime = clock();
	mTotalElapsedTime = mDiffTime = 0;
	mDT = mET = 0.0;
}

void CTimer::UpdateTime(void) {
	if(mWorking) {
		mCurrentTime = clock();
		mTotalElapsedTime = mCurrentTime - mStartTime;
		mDiffTime = mCurrentTime - mPreviousTime;
		mPreviousTime = mCurrentTime;
		mET = double(mTotalElapsedTime)/CLOCKS_PER_SEC;
		mDT = double(mDiffTime)/CLOCKS_PER_SEC;
	}
}

double CTimer::GetElapsedTime(void) {
	// 전체 총 실행 시간
	return mET;
}

double CTimer::GetTimeDifference(void) {
	// 순간순간 랩타임
	return mDT;
}
