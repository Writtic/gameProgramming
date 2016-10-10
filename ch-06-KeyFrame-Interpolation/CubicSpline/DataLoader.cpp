#include <algorithm>
#include <vector>
#include <fstream>
#include "DataLoader.h"

using namespace std;

CDataLoader::CDataLoader() : DataLoaded(false), startTime(0.0), endTime(0.0), TotalFrames(0), loc(NULL) {}

void CDataLoader::Load(char *fileName)
{
   ifstream file;
   file.open(fileName);

   file >> startTime >> endTime >> TotalFrames;

   _LocData_ c;
   for(int i=0;i<TotalFrames;i++)   {
      file >> c.t >> c.x >> c.y >> c.z;
      loc.push_back(c);
   }
   file.close();
}
bool Pred(_LocData_ left, _LocData_ right)
{
   return left.t < right.t;
}
void CDataLoader::GetLoc(float t, float &x, float &y, float &z)
{
   _LocData_ val;
   val.t = t;
   // lower_bound 함수는 현재 값 보다 크거나 같은 위치를 반환
   // ex) t = 0.1 인 경우, t = 1인 위치를 반환하므로, 한 단계 뒤로 이동
   vector<_LocData_>::iterator p = lower_bound(loc.begin(), loc.end(), val, Pred);
   p--;

   x = p->x;
   y = p->y;
   z = p->z;
}

void CDataLoader::GetLocInt(float t, float &x, float &y, float &z)
{
   _LocData_ val;
   val.t = t;
   // lower_bound 함수는 현재 값 보다 크거나 같은 위치를 반환
   // ex) t = 0.1 인 경우, t = 1인 위치를 반환하므로, 한 단계 뒤로 이동
   vector<_LocData_>::iterator p = lower_bound(loc.begin(), loc.end(), val, Pred);
   p--;

   vector<_LocData_>::iterator q = upper_bound(loc.begin(), loc.end(), val, Pred);
   if(loc.end() == q)
      q--;

   // p와 q는 보통 한 칸 차이나지만, 모두 종료된 후에는 end()를 동일하게 지시한다.
   // 동일한 경우 양쪽중 아무것이나 사용하면 됨
   float dt = (q->t == p->t) ? 0 : (t - p->t)/(q->t - p->t);
   x = (1-dt)* p->x + dt* q->x;
   y = (1-dt)* p->y + dt* q->y;
   z = (1-dt)* p->z + dt* q->z;
}


float CDataLoader::GetStartTime(void) {
   return this->startTime;
}

float CDataLoader::GetEndTime(void) {
   return this->endTime;
}
