#include<iostream>
#include<iomanip>
using namespace std;
 
class Date
{
public:
 Date(int year = 1990, int month = 1, int day = 1) //���캯��
 :_year(year), _month(month), _day(day)
 {
 if (JudgeRightDate())   //�жϴ����ֵ�Ƿ��ǺϷ��ģ����Ϸ����ó�1990��1��1��
 {
  _year = 1990;
  _month = 1;
  _day = 1;
 }
 }
 
 bool JudgeRightDate()  //�ж�ֵ�Ƿ�Ϸ�����
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
 
 int JudgeYear(int year)  //�ж��Ƿ�������ĺ���
 {
 if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
 {
  return 1;
 }
 else
  return 0;
 }
 
 int GetMonthDay(int year, int month) //ͨ������µõ���Ӧ������
 {
 int arr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
 int days = arr[month];
 if (month == 2)
 {
  days += JudgeYear(year);  //���������Ķ�����������1
 }
 return days;
 }
 
 
 Date operator +(int days)  //���ڼ��������������ء�+��ʵ��
 {
 _day += days;      //�Ƚ�����ȫ���ӵ��������ڵġ��족��
 GetRightDate(_year, _month, _day); //��ͨ������õ���ȷ�����ڡ�
 return *this;
 }
 
 void GetRightDate(int &year, int &month, int &day)  //�������ȷ������
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
 
 Date operator -(int days)  //���ء�-��ʵ�����ڼ�����
 {
 _day -= days;
 GetRightDate(_year, _month, _day);
 return *this;
 }
 
 bool operator >(const Date &d)  //�ж��������ڵĴ�С
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
 
 bool operator ==(const Date &d)  //�ж����������Ƿ����
 {
 if (_year == d._year && _month == d._month && _day == d._day)
 {
  return true;
 }
 else
  return false;
 }
 
 int operator -( Date &d) //�������ڲ�������ء�-��ʵ��
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
 
 
 void print()    //��ӡ����
 {
 cout << _year << "-" << _month << "-" << _day;
 }
 
 
 int week()  //������ڶ�Ӧ�����ں���
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
 cout << "������ ����һ ���ڶ� ������ ������ ������ ������" << endl;
 }
 
 void print_day() //�������ں����ڣ���ȷ���������
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
 cout << setw(40) <<"������"<< endl;
 cout << "1.���ڼӼ�����" << endl;
 cout << "2.���ڼ�����" << endl;
 cout << "3.����������ʾ��������" << endl;
}
void choice()
{
 int num = 0;
 int year, month, day, days;
 char ch = '+';
 cin >> num;
 if (num == 1)
 {
 cout << "���������ڣ�" << endl;
 cin >> year >> month >> day;
 cout << "����������:" << endl;
 cin >> days;
 cout << "������'+'����'-':" << endl;
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
  cout << "��Ч������!" << endl;
 }
 cout << "����������Ϊ��";
 d2.print();
 cout << endl;
 }
 else if (num==2)
 {
 cout << "���������ڣ�" << endl;
 cin >> year >> month >> day;
 Date d3(year, month, day);
 cout << "���������ڣ�" << endl;
 cin >> year >> month >> day;
 Date d4(year, month, day);
 int ret = d3 - d4;
 cout << "�ڼ���" << ret << endl;
 }
 else if (num == 3)
 {
 cout << "����������:" << endl;
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
