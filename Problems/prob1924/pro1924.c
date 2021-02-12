#include <stdio.h>


int main(void) {
    int month, day;
    int totalDay = 0;
    int plus_day[11] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30}; // 11월까지.
    char* DayOfWeek[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    int i;

    scanf("%d %d",&month, &day);
    // 이전 달까지의 날짜를 모두 더하기.
    for(i = 0; (i+1) < month; i++)
        totalDay += plus_day[i];
    // 해당되는 달의 날짜 더하기.
    totalDay += day;
    totalDay --;    // 1월 1일 제외.
    printf("%s\n", DayOfWeek[totalDay % 7]);

    return 0;
}