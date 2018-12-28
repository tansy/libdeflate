/*
 * test_util.h - utility functions for test programs
 *
 * Copyright 2016 Eric Biggers
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef PROGRAMS_TEST_UTIL_H
#define PROGRAMS_TEST_UTIL_H

#include "prog_util.h"

#include <zlib.h> /* for comparison purposes */

#ifdef __GNUC__
# define _noreturn __attribute__((noreturn))
#else
# define _noreturn
#endif

extern void _noreturn
assertion_failed(const char *expr, const char *file, int line);

#define ASSERT(expr) { if (unlikely(!(expr))) \
	assertion_failed(#expr, __FILE__, __LINE__); }

extern int alloc_guarded_buffer(size_t size, u8 **start_ret, u8 **end_ret);
extern void free_guarded_buffer(u8 *start, u8 *end);

extern u64 timer_ticks(void);
extern u64 timer_ticks_to_ms(u64 ticks);
extern u64 timer_MB_per_s(u64 bytes, u64 ticks);
extern u64 timer_KB_per_s(u64 bytes, u64 ticks);

#endif /* PROGRAMS_TEST_UTIL_H */
