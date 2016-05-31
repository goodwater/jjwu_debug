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

#include <linux/init.h>
#include <linux/module.h>
#include <linux/delay.h>
#include "jjwu_debug.h"

MODULE_DESCRIPTION("Test jjwu_debug");
MODULE_AUTHOR("WU, JHENG-JHONG <goodwater@gmail.com>");
MODULE_LICENSE("BSD");

#define FMT "%s: %d\n"

static int __init test_init(void)
{
	char *str = "Level";
	int debug_level = 0;

	JJWU_MSG(0, FMT, str, debug_level++);
	mdelay(1000);
	JJWU_MSG(1, FMT, str, debug_level++);
	mdelay(1000);
	JJWU_MSG(2, FMT, str, debug_level++);
	mdelay(1000);
	JJWU_MSG(3, FMT, str, debug_level++);
	mdelay(1000);
	JJWU_MSG(4, FMT, str, debug_level++);
	mdelay(1000);
	JJWU_MSG(5, FMT, str, debug_level++);
	mdelay(1000);
	JJWU_MSG(6, FMT, str, debug_level++);
	mdelay(1000);
	JJWU_MSG(7, FMT, str, debug_level);

	return 0;
}

static void __exit test_exit(void)
{
	
	JJWU_MSG(0, "Bye-bye\n");
}

module_init(test_init);
module_exit(test_exit);
