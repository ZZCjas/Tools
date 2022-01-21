#include<iostream>
#include<iomanip>
using namespace std;
 
class Date
{
public:
 Date(int year = 1990, int month = 1, int day = 1) //构造函数
 :_year(year), _month(month), _day(day)
 {
 if (JudgeRightDate())   //判断传入的值是否是合法的，不合法则置成1990年1月1日
 {
  _year = 1990;
  _month = 1;
  _day = 1;
 }
 }
 
 bool JudgeRightDate()  //判断值是否合法函数
 {
 if (_year < 1 || ((_month< 1)||_month>12) ||
  (_day<1)||_day>GetMonthDay(_year,_month))
 {
  return true;
 }
 else
 {
  return false;
 }
 }
 
 int JudgeYear(int year)  //判断是否是闰年的函数
 {
 if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
 {
  return 1;
 }
 else
  return 0;
 }
 
 int GetMonthDay(int year, int month) //通过年和月得到对应的天数
 {
 int arr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
 int days = arr[month];
 if (month == 2)
 {
  days += JudgeYear(year);  //如果是闰年的二月则天数加1
 }
 return days;
 }
 
 
 Date operator +(int days)  //日期加天数函数，重载“+”实现
 {
 _day += days;      //先将天数全部加到所给日期的“天”上
 GetRightDate(_year, _month, _day); //再通过计算得到正确的日期。
 return *this;
 }
 
 void GetRightDate(int &year, int &month, int &day)  //计算出正确的日期
 {
 if (day <= 0)
 {
  while (day <= 0)
  {
  month--;
  day += GetMonthDay(year, month);
  if (month < 1)
  {
   year--;
   month = 13;
  }
  }
 }
 else
 {
  while (day>GetMonthDay(year, month))
  {
  day -= GetMonthDay(year, month);
  month++;
  if (month > 12)
  {
   year++;
   month = 1;
  }
  }
 }
 }
 
 Date operator -(int days)  //重载“-”实现日期减天数
 {
 _day -= days;
 GetRightDate(_year, _month, _day);
 return *this;
 }
 
 bool operator >(const Date &d)  //判断两个日期的大小
 {
 if (_year > d._year)
 {
  return true;
 }
 else if (_year == d._year)
 {
  if (_month > d._month)
  {
  return true;
  }
  else if (_month==d._month)
  {
  if (_day > d._day)
  {
   return true;
  }
  }
 }
 return false;
 }
 
 bool operator ==(const Date &d)  //判断两个日期是否相等
 {
 if (_year == d._year && _month == d._month && _day == d._day)
 {
  return true;
 }
 else
  return false;
 }
 
 int operator -( Date &d) //计算日期差函数，重载“-”实现
 {
 int count = 0;
 Date tmp(*this);
 if (*this > d)
 {
  tmp = d;
  d = *this;
  *this = tmp;
 }
 while (!(*this==d))
 {
  count++;
  *this =*this+1;
 }
 return count;
 }
 
 
 void print()    //打印函数
 {
 cout << _year << "-" << _month << "-" << _day;
 }
 
 
 int week()  //求出日期对应的星期函数
 {
 int w = 0;
 int y = _year;
 int m = _month;
 if (m == 1 || m == 2)
 {
  m = _month + 12;
  y = _year - 1;
 }
 w = _day + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400;
 w = w % 7 + 1;
 return w;
 }
 
 void print_week()
 {
 cout << "星期日 星期一 星期二 星期三 星期四 星期五 星期六" << endl;
 }
 
 void print_day() //根据日期和星期，正确的输出日历
 {
 int line = 1;
 int days = GetMonthDay(_year,_day);
 int w = week();
 if (w != 7)
 {
  for (int blank = w - 1; blank; --blank, ++line)
  {
  cout << setw(7) << "";
  }
 }
 for (int d = 1; d <= days; ++d, ++line)
 {
  cout << setw(7) << d;
  if (line % 7 == 0)
  {
  cout << endl;
  }
 }
 cout << endl;
 }
 
private:
 int _year;
 int _month;
 int _day;
};
void menu()
{
 cout << setw(40) <<"万年历"<< endl;
 cout << "1.日期加减天数" << endl;
 cout << "2.日期减日期" << endl;
 cout << "3.输入年月显示当月日历" << endl;
}
void choice()
{
 int num = 0;
 int year, month, day, days;
 char ch = '+';
 cin >> num;
 if (num == 1)
 {
 cout << "请输入日期：" << endl;
 cin >> year >> month >> day;
 cout << "请输入天数:" << endl;
 cin >> days;
 cout << "请输入'+'或者'-':" << endl;
 cin >> ch;
 Date d1(year, month, day);
 Date d2;
 if (ch == '+')
 {
  d2 = d1 + days;
 }
 else if (ch == '-')
 {
  d2 = d1 - days;
 }
 else
 {
  cout << "无效的输入!" << endl;
 }
 cout << "计算后的日期为：";
 d2.print();
 cout << endl;
 }
 else if (num==2)
 {
 cout << "请输入日期：" << endl;
 cin >> year >> month >> day;
 Date d3(year, month, day);
 cout << "请输入日期：" << endl;
 cin >> year >> month >> day;
 Date d4(year, month, day);
 int ret = d3 - d4;
 cout << "期间相差：" << ret << endl;
 }
 else if (num == 3)
 {
 cout << "请输入年月:" << endl;
 cin >> year >> month;
 Date d5(year, month);
 d5.print_week();
 d5.print_day();
 }
}
int main()
{
 menu();
 choice();
 system("pause");
 return 0;
}
