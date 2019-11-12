#ifndef CALENDAR_H
#define CALENDAR_H

#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdio.h>
#include <time.h>

int const toYear = 2019;
bool const isLeapYear = (((toYear % 4 == 0) && (toYear % 100 != 0)) || (toYear % 400 == 0)) ? true : false;

//2019年法定假日类型休市日期
int const holidayList[] = {
	//元旦
	101,
	//春节
	202,203,204,205,206,207,208,209,210,
	//清明节
	405,406,407,
	//劳动节
	427,428,429,430,501,
	//端午节
	607,608,609,
	//中秋节，
	913,914,915,
	//国庆节
	1001,1002,1003,1004,1005,1006,1007,
	//2020元旦
	1228,1229,1230,1231
};

class Calendar
{
private:
	int startWeekday; //今年1月1号是星期几
	int holidayNomb[sizeof(holidayList) / sizeof(int)];//今年所有节假日的日历编码

	int check(int year, int month, int day);//检查输入的日期是否合法
	int monthdays(int n);//返回每个月有几天
	int getNomb(int month, int day);//返回mm月dd日的日历编码
	int deNomb(int nomb);//返回日历编码对应的 yyyymmdd
	bool isWeekend(int nomb);//判断日历编码对应的日期是否为周末
	bool isHoliday(int nomb);//判断日历编码对应的日期是否为节假日
	void setHolidayNomb();//设置节假日的日历编码
	void currentTime(int* year, int* month, int* day, int* hour);//获取当前时间
	void getTradingDate_(char* date, int year, int month, int day, bool isDay);//获取yyyymmdd日夜盘对应的交易日


public:
	Calendar();//初始化
	void getFileName(char* fileName);//输出现在时刻的交易日文件名
	void getFileName_(char* fileName, int date, int hour);//输出yyyymmdd日历的hour小时的交易日文件名
	void createCalender();//输出今年的交易日历
};





#endif