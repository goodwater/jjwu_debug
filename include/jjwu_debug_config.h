/* Copyright (c) 2016, WU, JHENG-JHONG <goodwater.wu@gmail.com>
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
