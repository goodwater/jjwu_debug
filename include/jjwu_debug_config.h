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

#ifndef __JJWU_DEBUG_CONFIG_H__
#define __JJWU_DEBUG_CONFIG_H__

/* The follow definition can change according to your need */

#define KERNEL_SPACE 0

#define PRINT_TIMESTAMP 1
#define PRINT_FILE_NAME 1
#define PRINT_FILE_LINE 1
#define PRINT_FUNCTION_NAME 1
#define PRINT_RESERVE_0 0
#define PRINT_RESERVE_1 0
#define PRINT_RESERVE_2 0
#define PRINT_RESERVE_3 0

#define DEBUG_LEVEL 7

/* The following definition should not change manually. */

#define LEVEL_EMERG 0
#define LEVEL_ALERT 1
#define LEVEL_CRIT 2
#define LEVEL_ERR 3
#define LEVEL_WARNING 4
#define LEVEL_NOTICE 5
#define LEVEL_INFO 6
#define LEVEL_DEBUG 7

#define EMERG "EMERG"
#define ALERT "ALERT"
#define CRIT "CRIT"
#define ERR "ERR"
#define WARNING "WARNING"
#define NOTICE "NOTICE"
#define INFO "INFO"
#define DEBUG "DEBUG"

#define PRINT_TIMESTAMP_SHIFT 0
#define PRINT_FILE_NAME_SHIFT 1
#define PRINT_FILE_LINE_SHIFT 2
#define PRINT_FUNCTION_NAME_SHIFT 3
#define PRINT_RESERVE_0_SHIFT 4
#define PRINT_RESERVE_1_SHIFT 5
#define PRINT_RESERVE_2_SHIFT 6
#define PRINT_RESERVE_3_SHIFT 7

#define PRINT_TIMESTAMP_MASK 0x1
#define PRINT_FILE_NAME_MASK 0x2
#define PRINT_FILE_LINE_MASK 0x4
#define PRINT_FUNCTION_NAME_MASK 0x8
#define PRINT_RESERVE_0_MASK 0x10
#define PRINT_RESERVE_1_MASK 0x20
#define PRINT_RESERVE_2_MASK 0x40
#define PRINT_RESERVE_3_MASK 0x80

#endif
