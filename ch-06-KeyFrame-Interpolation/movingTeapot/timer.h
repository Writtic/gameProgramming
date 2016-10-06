#ifndef __KANGSTIMER2006_
#define __KANGSTIMER2006_

// Timer Class
// Young-Min Kang (c) 2006
// -----------------------------------

class CTimer {
	bool mWorking;
	// Time variables (second)
	double mET; // 시간 측정 개시 이후에 흐른 총 시간
	double mDT; // 직전 프레임과 현재 프레임 사이의 시간 차이
	// Time variables (millisecond)
	long mStartTime;
	long mPreviousTime;
	long mCurrentTime;
	long mTotalElapsedTime;
	long mDiffTime;
public:
	CTimer();
	void Init(void);
	void Reset(void);
	void UpdateTime(void);
	double GetElapsedTime(void);
	double GetTimeDifference(void);
};
#endif
