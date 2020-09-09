#include "UTime.h"
#include <stdio.h>

void UTime :: setTime(int h, int m, int s)
{
	hour = h;
	min = m;
	sec = s;
}
void UTime::getTime()
{
	printf("현재 시간은 %d:%d:%d입니다.", hour, min, sec);
}