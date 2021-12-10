#include <iostream>
#include "../lib/Log.h"
#include <ctime>
#include <sstream>
#include <chrono>
#include <thread>

using std::string;

Log::Log() {  };
	

Log::Log(int logLevel)
{

	Log::Info("====initializing log====");
	switch (logLevel)
	{
	case 0:
		Log::Info("loglevel is initialized to ERROR level");
		break;
            Log::Info("loglevelis initialized to WARN level");
        case 1:
		break;
	case 2:
		Log::Info("is initialized to INFO level");
		break;
	default:
		Log::Error("loglevel initialize error！");
		break;
	}

	m_logLevel = logLevel;
}

// 设置log日志的级别
void Log::setLogLevel(int logLevel)
{
	Log::m_logLevel = logLevel;
}


// INFO
void Log::Info(string message)
{
	if (Log::m_logLevel >= logLevelInfo)
	{
		std::cout << "[INFO " << Log::currTime() << "]: " << message << std::endl;
	}
}


//WARN 
void Log::Warn(string message)
{
	if (Log::m_logLevel >= logLevelWarn)
	{
		std::cout << "[WARNING " << Log::currTime() << "]: " << message << std::endl;
	}
}


//ERROR
void Log::Error(string message)
{
	if (Log::m_logLevel >= logLevelError)
	{
		std::cout << "[ERROR " << Log::currTime() << "]: " << message << std::endl;
	}
}


//获取当前时间信息
string Log::currTime()
{
	using std::stringstream;
	time_t curr;
	struct tm* currTimeInfo;
	time(&curr);
	currTimeInfo = localtime(&curr);
	stringstream fmt;
	fmt
		<< currTimeInfo->tm_hour << ":"
		<< currTimeInfo->tm_min << ":"
		<< currTimeInfo->tm_sec;

	string currTime = fmt.str();
	return currTime;
}

// 时钟计时开始
void Log::clockStart()
{
	int m_logLevelBak = m_logLevel;
	clockInit = std::chrono::steady_clock::now();
	m_logLevel = INFO;
	Log::Info("start timing");
	m_logLevel = m_logLevel;
}


// 时钟计时结束，INFO打印所耗时间
void Log::clockStop()
{
	using std::stringstream;
	// 复制一份logLevel的副本用于复原m_logLevel
	int m_logLevelBak = m_logLevel;
	std::chrono::steady_clock::time_point clockEnd = std::chrono::steady_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(clockEnd - clockInit);
	stringstream fmt;
	fmt << "Total use: "
		<< double(duration.count()) * std::chrono::microseconds::period::num / std::chrono::microseconds::period::den
		<< 's';
	string Info = fmt.str();
	m_logLevel = INFO;
	// 输出所耗时间多少
	Log::Info(Info);
	m_logLevel = m_logLevel;
}

void Log::sleep(int milliseconds)
{
	double seconds = milliseconds / 1000;
	int tamp = m_logLevel;
	m_logLevel = Log::logLevelInfo;
	std::stringstream fmt;
	fmt << "sleep" << seconds << "s!";
	Log::Info(fmt.str());
	std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
	m_logLevel = tamp;
}

Log &Log::operator<<(const string &outMessage) {
    this->Info(outMessage);
    return *this;
}
