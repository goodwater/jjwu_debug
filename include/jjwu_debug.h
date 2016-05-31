/*
 * Copyright (c) 2016, WU, JHENG-JHONG <goodwater.wu@gmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *    This product includes software developed by the WU, JHENG-JHONG.
 * 4. Neither the name of the WU, JHENG-JHONG nor the
 *    names of its contributors may be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY WU, JHENG-JHONG ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL WU, JHENG-JHONG BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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

static inline char *timestamp(char *timestr)
{
	time_t timer;
	struct tm* tm_info;

	time(&timer);
	tm_info = localtime(&timer);
	strftime(timestr, TIME_LENGTH, "%Y-%m-%d %H:%M:%S", tm_info);

	return timestr;
}

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

#else //else of #ifdef JJWU_DEBUG

#define JJWU_MSG(LEVEL, FMT, ...)

#endif //end of #ifdef JJWU_DEBUG

#endif //end of #ifndef __JJWU_DEBUG__
