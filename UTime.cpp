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
	printf("���� �ð��� %d:%d:%d�Դϴ�.", hour, min, sec);
}