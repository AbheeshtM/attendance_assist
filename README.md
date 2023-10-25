# Attendance Calculator

The Attendance Calculator is a command-line tool designed to help students determine how many leave days they can take while maintaining a required percentage of attendance. This tool is particularly useful for students who need to balance their attendance records when planning to take time off from their educational institutions.

## How It Works

1. **Date Input**: The program first prompts you to input the start and end dates of your leave, including the day, month, and year. It validates these inputs to ensure they represent valid dates.

2. **Lecture Count**: You are then asked to provide the number of lectures scheduled for each day during your leave period. This data helps calculate the total lectures you'll miss.

3. **Attendance Plan**: Next, the program prompts you to specify how many lectures you plan to attend on each day of your leave period. It accumulates the total number of lectures you will attend during your leave.

4. **Past Attendance Data**: The tool also collects data regarding the total number of lectures that have occurred in the past and the number of lectures you've already attended in the past.

5. **Attendance Calculation**: It calculates the total attendance percentage for the entire duration, past and future, and the past attendance percentage based on past data. It also calculates the drop in percentage, which is the change in attendance percentage due to taking leave.

6. **Additional Lectures**: If you wish to add more lectures to your plan, the tool allows you to input additional data for future lectures you plan to attend. It updates the attendance calculations accordingly.

7. **Results**: The program then displays various statistics, including the total number of lectures attended during the leave period, total lectures attended in the past, total lectures in both the past and future, and the resulting attendance percentages.

## How to Use

1. Compile the C code using a C compiler such as GCC.

   ```bash
   gcc attendance_calculator.c -o attendance_calculator
   ```

2. Run the compiled program.

   ```bash
   ./attendance_calculator
   ```

3. Follow the prompts to input the necessary data and make attendance calculations.

4. The tool will display the attendance percentages, helping you plan your leave while staying within your desired attendance range.

## Example Usage

Suppose you have a minimum required attendance percentage, and you're planning to take leave. This tool will guide you on the number of leave days you can afford to maintain your required attendance.

---

**README.md**

# Attendance Calculator

The Attendance Calculator is a simple command-line tool to help students manage their attendance records when planning to take leave from their educational institutions. By providing essential data, it calculates the number of leave days you can take while maintaining the required attendance percentage.

## Table of Contents

- [How It Works](#how-it-works)
- [How to Use](#how-to-use)
- [Example Usage](#example-usage)

## How It Works

1. **Date Input**: Input the start and end dates of your leave, including the day, month, and year. The tool validates these dates.

2. **Lecture Count**: Specify the number of lectures scheduled for each day of your leave, allowing the tool to calculate the total lectures missed.

3. **Attendance Plan**: Indicate how many lectures you plan to attend on each day of your leave.

4. **Past Attendance Data**: Provide data on total past lectures and lectures attended.

5. **Attendance Calculation**: The tool calculates the overall attendance percentage and the drop in percentage caused by taking leave.

6. **Additional Lectures**: If needed, you can add more lectures to your plan, updating the attendance calculations.

7. **Results**: The program displays attendance statistics, helping you plan your leave within your desired attendance range.

## How to Use

1. Compile the C code using a C compiler like GCC.

   ```bash
   gcc attendance_calculator.c -o attendance_calculator
   ```

2. Run the compiled program.

   ```bash
   ./attendance_calculator
   ```

3. Follow the prompts to input data and make attendance calculations.

4. Review the displayed attendance percentages to assist your leave planning.

## Example Usage

Suppose you have a minimum required attendance percentage, and you're planning to take leave. Use the Attendance Calculator to find out how many leave days you can take while still meeting your attendance goal.

---

Feel free to use and modify this tool to suit your specific attendance calculation needs.
