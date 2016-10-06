#include <stdio.h>
#include <vector>

// Simple Data Loader
// Young-Min Kang (c) 2006
class _LocData_ {
public:
   float t; // time
   float x;
   float y;
   float z;
};
class CDataLoader
{
   bool DataLoaded;
   float startTime;
   float endTime;
   int TotalFrames;
   std::vector <_LocData_> loc;
public:
   CDataLoader();
   void Load(char *fileName);
   void GetLoc(float t, float &x, float &y, float &z);
   void GetLocInt(float t, float &x, float &y, float &z);
   float GetStartTime(void);
   float GetEndTime(void);
};
