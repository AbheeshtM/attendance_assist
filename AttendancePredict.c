#include <stdio.h>
#include <time.h>

// Function to check if a year is a leap year
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1; // It's a leap year
    } else {
        return 0; // It's not a leap year
    }
}

// Function to get the number of days in a month
int getDaysInMonth(int month, int year) {
    int daysInMonth[] = {0, 31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return daysInMonth[month];
}

// Function to calculate the number of days between two dates
int calculateDaysBetweenDates(int day1, int month1, int year1, int day2, int month2, int year2) {
    int days = 0;

    while (year1 != year2 || month1 != month2 || day1 != day2) {
        days++;
        day1++;
        if (day1 > getDaysInMonth(month1, year1)) {
            day1 = 1;
            month1++;
            if (month1 > 12) {
                month1 = 1;
                year1++;
            }
        }
    }

    return days;
}

int main() {
    int year;

    printf("Enter a year: ");
    scanf("%d", &year);

    if (isLeapYear(year)) {
        printf("%d is a leap year.\n", year);
    } else {
        printf("%d is not a leap year.\n", year);
    }

    int day1, month1, year1, day2, month2, year2;

    printf("Enter the first date (dd mm yyyy): ");
    scanf("%d %d %d", &day1, &month1, &year1);

    printf("Enter the second date (dd mm yyyy): ");
    scanf("%d %d %d", &day2, &month2, &year2);

    if (year2 < year1 || (year2 == year1 && month2 < month1) || (year2 == year1 && month2 == month1 && day2 < day1)) {
        printf("Invalid input. The second date should be later than the first date.\n");
        return 1;
    }

    int daysBetween = calculateDaysBetweenDates(day1, month1, year1, day2, month2, year2);

    int lecturesPerDay[daysBetween + 1];
    int lecturesAttendedPerDay[daysBetween + 1];

    for (int i = 0; i <= daysBetween; i++) {
        printf("Enter the number of lectures for day %d (%d/%d/%d): ", i + 1, day1, month1, year1);
        scanf("%d", &lecturesPerDay[i]);
        day1++;
        if (day1 > getDaysInMonth(month1, year1)) {
            day1 = 1;
            month1++;
            if (month1 > 12) {
                month1 = 1;
                year1++;
            }
        }
    }

    day1 = day1 - (daysBetween + 1); // Reset day1 to the initial value
    month1 = month1 - 1; // Reset month1 to the initial value
    year1 = year1 - (daysBetween / 30); // Reset year1 to the initial value

    for (int i = 0; i <= daysBetween; i++) {
        printf("How many lectures will you attend on day %d (%d/%d/%d): ", i + 1, day1, month1, year1);
        scanf("%d", &lecturesAttendedPerDay[i]);
        day1++;
        if (day1 > getDaysInMonth(month1, year1)) {
            day1 = 1;
            month1++;
            if (month1 > 12) {
                month1 = 1;
                year1++;
            }
        }
    }

    printf("Number of days between the two dates: %d days\n", daysBetween);

    // Print the number of lectures and attended lectures for each day
    int currentDay = day1;
    int currentMonth = month1;
    int currentYear = year1;

    for (int i = 0; i <= daysBetween; i++) {
        printf("Day %d (%d/%d/%d): %d lectures, %d attended\n", i + 1, currentDay, currentMonth, currentYear, lecturesPerDay[i], lecturesAttendedPerDay[i]);

        currentDay++;
        if (currentDay > getDaysInMonth(currentMonth, currentYear)) {
            currentDay = 1;
            currentMonth++;
            if (currentMonth > 12) {
                currentMonth = 1;
                currentYear++;
            }
        }
    }

    int totalLecturesPast;
    int totalAttendedPast;

    printf("Enter the total number of lectures that took place in the past: ");
    scanf("%d", &totalLecturesPast);

    printf("Enter the total number of lectures you attended in the past: ");
    scanf("%d", &totalAttendedPast);

    printf("Total number of lectures in the past: %d\n", totalLecturesPast);
    printf("Total number of lectures attended in the past: %d\n", totalAttendedPast);

    // Add the total lectures in the past with the total lectures during leave dates
    int totalLecturesTotal = totalLecturesPast;
    for (int i = 0; i <= daysBetween; i++) {
        totalLecturesTotal += lecturesPerDay[i];
    }

    // Add the total lectures attended in the past with the number of lectures attended in leave dates
    int totalAttendedTotal = totalAttendedPast;
    for (int i = 0; i <= daysBetween; i++) {
        totalAttendedTotal += lecturesAttendedPerDay[i];
    }

    // Calculate the attendance percentage
    float attendancePercentage = ((float)totalAttendedTotal / totalLecturesTotal) * 100;

    // Calculate past attendance percentage
    float pastAttendancePercentage = ((float)totalAttendedPast / totalLecturesPast) * 100;

    // Calculate the drop in percentage
    float dropPercentage = pastAttendancePercentage - attendancePercentage;

    printf("Total number of lectures in the past and during leave dates: %d\n", totalLecturesTotal);
    printf("Total number of lectures attended in the past and during leave dates: %d\n", totalAttendedTotal);
    printf("Attendance Percentage: %.2f%%\n", attendancePercentage);
    printf("Past Attendance Percentage: %.2f%%\n", pastAttendancePercentage);
    printf("Drop in Percentage: %.2f%%\n", dropPercentage);

    while (1) {
        char moreLectures;
        printf("Do you want to add more lectures (y/n)? ");
        scanf(" %c", &moreLectures);

        if (moreLectures == 'n' || moreLectures == 'N') {
            break;
        }

        int additionalTotalLectures;
        printf("Enter the total number of additional lectures: ");
        scanf("%d", &additionalTotalLectures);

        int additionalLecturesAttended;
        printf("Enter the number of additional lectures you will attend: ");
        scanf("%d", &additionalLecturesAttended);

        if (additionalTotalLectures < 0 || additionalLecturesAttended < 0) {
            printf("Invalid input. The number of lectures should be non-negative.\n");
            continue;
        }

        totalLecturesTotal += additionalTotalLectures;
        totalAttendedTotal += additionalLecturesAttended;

        // Calculate the updated attendance percentage
        attendancePercentage = ((float)totalAttendedTotal / totalLecturesTotal) * 100;

        printf("Totals updated successfully.\n");
        printf("Total number of lectures in the past and during leave dates: %d\n", totalLecturesTotal);
        printf("Total number of lectures attended in the past and during leave dates: %d\n", totalAttendedTotal);
        printf("Attendance Percentage: %.2f%%\n", attendancePercentage);
    }

    return 0;
}
