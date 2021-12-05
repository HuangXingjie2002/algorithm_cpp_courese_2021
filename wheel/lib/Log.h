#pragma once
#include <ctime>
#include <chrono>
#include <iostream>
#define ERROR 0
#define WARN 1
#define INFO 2
using std::string;
using std::ostream;

class Log
{
private:
	int m_logLevel = 2;
	std::chrono::high_resolution_clock::time_point clockInit;

public:
	static const int logLevelInfo = 2;
	static const int logLevelWarn = 1;
	static const int logLevelError = 0;

	Log();

	Log(int logLevel);

	void setLogLevel(int);

	std::string currTime();

	void Info(string);

	void Warn(string);

	void Error(string);

	void clockStart();

	void clockStop();

	void sleep(int milliseconds);

    Log & operator<<(const string & outMessage);
};