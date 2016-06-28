/*
 * Copyright (c) 2016 WU, JHENG-JHONG <goodwater.wu@gmail.com>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated 
 *  documentation files (the "Software"), to deal in the Software without restriction, including without limitation 
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

#include <stdio.h>
#include <unistd.h>
#include "jjwu_debug.h"

#define FMT "%s: %d\n"

int main(int argc, const char *argv[])
{
	char *str = "Level";
	int debug_level = 0;

	JJWU_MSG(0, FMT, str, debug_level++);
	sleep(1);
	JJWU_MSG(1, FMT, str, debug_level++);
	sleep(1);
	JJWU_MSG(2, FMT, str, debug_level++);
	sleep(1);
	JJWU_MSG(3, FMT, str, debug_level++);
	sleep(1);
	JJWU_MSG(4, FMT, str, debug_level++);
	sleep(1);
	JJWU_MSG(5, FMT, str, debug_level++);
	sleep(1);
	JJWU_MSG(6, FMT, str, debug_level++);
	sleep(1);
	JJWU_MSG(7, FMT, str, debug_level);

	return 0;
}
