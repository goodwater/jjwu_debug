/*
 * Copyright (c) 2016 WU, JHENG-JHONG <goodwater.wu@gmail.com>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated 
 * documentation files (the "Software"), to deal in the Software without restriction, including without limitation 
 * the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and 
 * to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of 
 * the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO 
 * THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF 
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
 * IN THE SOFTWARE.
 */

#ifndef __JJWU_DEBUG__
#define __JJWU_DEBUG__

#ifdef __linux__
#include <linux/limits.h>
#endif

#include "jjwu_debug_config.h"

#ifndef NAME_MAX
#define NAME_MAX 256
#endif

#define TIME_LENGTH 32
#define FILE_LINE_LENGTH 16
#define JJWU_MSG_FMT "<%s> %s%s%s%s- "

#ifdef JJWU_DEBUG

static inline char getPrintInfo(void)
{
	char info = 0;

	info |= (PRINT_TIMESTAMP << PRINT_TIMESTAMP_SHIFT);
	info |= (PRINT_FILE_NAME << PRINT_FILE_NAME_SHIFT);
	info |= (PRINT_FILE_LINE << PRINT_FILE_LINE_SHIFT);
	info |= (PRINT_FUNCTION_NAME << PRINT_FUNCTION_NAME_SHIFT);

	return info;
}

#if KERNEL_SPACE

#include <linux/rtc.h>

#define PRINT(FMT, ...) printk(KERN_EMERG FMT, ##__VA_ARGS__)

static inline char *timestamp(char *timestr)
{
	struct timeval time;
	struct rtc_time tm;
	unsigned long local_time;

	do_gettimeofday(&time);
	local_time = (u32)(time.tv_sec - (sys_tz.tz_minuteswest * 60));
	rtc_time_to_tm(local_time, &tm);

	snprintf(timestr, TIME_LENGTH, "%04d-%02d-%02d %02d:%02d:%02d", tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

	return timestr;
}

#else //else of #if KERNEL_SPACE

#include <stdio.h>
#include <time.h>

#define PRINT(FMT, ...) printf(FMT, ##__VA_ARGS__)

#ifdef _MSC_VER
static inline char *timestamp(char *timestr)
{
	time_t timer;
	struct tm tm_info;

	time(&timer);
	localtime_s(&tm_info, &timer);
	strftime(timestr, TIME_LENGTH, "%Y-%m-%d %H:%M:%S", &tm_info);

	return timestr;
}
#elif __GCC__ || __GNUC__
static inline char *timestamp(char *timestr)
{
	time_t timer;
	struct tm* tm_info;

	time(&timer);
	tm_info = localtime(&timer);
	strftime(timestr, TIME_LENGTH, "%Y-%m-%d %H:%M:%S", tm_info);

	return timestr;
}
#else // else of #ifdef _WIN32
static inline char *timestamp(char *timestr)
{
	snprintf(timestr, TIME_LENGTH, "%04d-%02d-%02d %02d:%02d:%02d", 0, 0, 0, 0, 0, 0);

	return timestr;
}
#endif

#endif //end of #ifdef KERNEL_SPACE

#define JJWU_MSG(LEVEL, FMT, ...)\
	while (1)\
	{\
		char print_info = 0;\
		char timestr[TIME_LENGTH] = {0};\
		char local_time[TIME_LENGTH] = {0};\
		char file_name[NAME_MAX] = {0};\
		char file_line[FILE_LINE_LENGTH] = {0};\
		char function_name[NAME_MAX] = {0};\
		char *level_str = 0;\
		int level = 0;\
\
		print_info = getPrintInfo();\
\
		if (print_info&PRINT_TIMESTAMP_MASK)\
			snprintf(local_time, sizeof(local_time), "[%s] ", timestamp(timestr));\
\
		if (print_info&PRINT_FILE_NAME_MASK)\
			snprintf(file_name, sizeof(file_name), "FILE: %s ", __FILE__);\
\
		if (print_info&PRINT_FILE_LINE_MASK)\
			snprintf(file_line, sizeof(file_line), "LINE: %d ", __LINE__);\
\
		if (print_info&PRINT_FUNCTION_NAME_MASK)\
			snprintf(function_name, sizeof(function_name), "FUNCTION: %s ", __FUNCTION__);\
\
		switch (LEVEL)\
		{\
			case 0:\
				level = LEVEL_EMERG;\
				level_str = EMERG;\
				break;\
			case 1:\
				level = LEVEL_ALERT;\
				level_str = ALERT;\
				break;\
			case 2:\
				level = LEVEL_CRIT;\
				level_str = CRIT;\
				break;\
			case 3:\
				level = LEVEL_ERR;\
				level_str = ERR;\
				break;\
			case 4:\
				level = LEVEL_WARNING;\
				level_str = WARNING;\
				break;\
			case 5:\
				level = LEVEL_NOTICE;\
				level_str = NOTICE;\
				break;\
			case 6:\
				level = LEVEL_INFO;\
				level_str = INFO;\
				break;\
			case 7:\
				level = LEVEL_DEBUG;\
				level_str = DEBUG;\
				break;\
			default:\
				level = LEVEL_EMERG;\
				level_str = EMERG;\
				break;\
		}\
\
		if (level <= DEBUG_LEVEL)\
		{\
			PRINT(JJWU_MSG_FMT, level_str, (local_time==0)? "":local_time, (file_name==0)? "":file_name, (file_line==0)? "":file_line, (function_name==0)? "":function_name);\
			PRINT(FMT, ##__VA_ARGS__);\
		}\
\
		break;\
	}

#define JJWU_EMERG_MSG(FMT, ...) JJWU_MSG(LEVEL_EMERG, FMT, ##__VA_ARGS__)
#define JJWU_ALERT_MSG(FMT, ...) JJWU_MSG(LEVEL_ALERT, FMT, ##__VA_ARGS__)
#define JJWU_CRIT_MSG(FMT, ...) JJWU_MSG(LEVEL_CRIT, FMT, ##__VA_ARGS__)
#define JJWU_ERR_MSG(FMT, ...) JJWU_MSG(LEVEL_ERR, FMT, ##__VA_ARGS__)
#define JJWU_WARNING_MSG(FMT, ...) JJWU_MSG(LEVEL_WARNING, FMT, ##__VA_ARGS__)
#define JJWU_NOTICE_MSG(FMT, ...) JJWU_MSG(LEVEL_NOTICE, FMT, ##__VA_ARGS__)
#define JJWU_INFO_MSG(FMT, ...) JJWU_MSG(LEVEL_INFO, FMT, ##__VA_ARGS__)
#define JJWU_DEBUG_MSG(FMT, ...) JJWU_MSG(LEVEL_DEBUG, FMT, ##__VA_ARGS__)

#else //else of #ifdef JJWU_DEBUG

#define JJWU_MSG(LEVEL, FMT, ...)
#define JJWU_EMER_MSG(FMT, ...)
#define JJWU_ALERT_MSG(FMT, ...)
#define JJWU_CRIT_MSG(FMT, ...)
#define JJWU_ERR_MSG(FMT, ...)
#define JJWU_WARNING_MSG(FMT, ...)
#define JJWU_NOTICE_MSG(FMT, ...)
#define JJWU_INFO_MSG(FMT, ...)
#define JJWU_DEBUG_MSG(FMT, ...)

#endif //end of #ifdef JJWU_DEBUG

#endif //end of #ifndef __JJWU_DEBUG__
