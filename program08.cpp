#include <iostream>
#pragma warning(disable : 4996) //needed to disable windows warning to use localtime function
#include <ctime>

using namespace std;

void getInput(int&, int&);
bool isLeapYear(int);
int numberOfDays(int, int, const int[]);
void getCurrentMonthAndYear(int&, int&);

int main()
{
  int month, year;

  const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

  const string monthName[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

  getInput(month, year);

  while (month != 0)
  {
    month--; //adjusting month value to match the indexes of the array for daysInMonth
    cout << numberOfDays(month, year, daysInMonth) << " days\n\n";

    getInput(month, year);
  }
  
  cout << endl;

  getCurrentMonthAndYear(month, year);
  cout << "The current month, " << monthName[month] << " " << year << "," << " has " << numberOfDays(month, year, daysInMonth) << " days\n\n";

  return 0;
}

void getInput(int& month, int& year)
{
  cout << "Enter a month (1-12) and a 4 digit year \n separated by a space (or 0 0 to quit): ";
  cin >> month >> year;

  while (month < 0 || month > 12)
  {
    cout << "Month number must be between 1 and 12 (or 0 to quit)\n";
    cout << "Please re-enter month: ";
    cin >> month;
  }
}

bool isLeapYear(int year)
{
  if (year % 100 == 0)
  {
    return true;
  }
  else if (year % 4 == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int numberOfDays(int month, int year, const int days[])
{
  int numberDays = days[month];

  if (month == 1 && isLeapYear(year)) 
  {
    numberDays++;
  }
  return numberDays;
}

void getCurrentMonthAndYear(int& month, int& year)
{
  time_t currentTime = time(NULL);

  tm* tm_ptr = localtime(&currentTime);

  month = tm_ptr->tm_mon;
  year = tm_ptr->tm_year + 1900;
}