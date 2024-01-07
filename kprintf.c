/*
 * MIT License
 *
 * Copyright (c) 2024 Ruediga
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/

#include <stdarg.h>

#include "kprintf.h"

/*
#define FLAGS_ZEROPAD   (1u << 0u)
#define FLAGS_LEFT      (1u << 1u)
#define FLAGS_PLUS      (1u << 2u)
#define FLAGS_SPACE     (1u << 3u)
#define FLAGS_HASH      (1u << 4u)
#define FLAGS_UPPERCASE (1u << 5u)
#define FLAGS_CHAR      (1u << 6u)
#define FLAGS_SHORT     (1u << 7u)
#define FLAGS_LONG      (1u << 8u)
#define FLAGS_LONG_LONG (1u << 9u)
#define FLAGS_PRECISION (1u << 10u)
#define FLAGS_ADAPT_EXP (1u << 11u)*/

// defines for output formatting
#define KPRINTF_FLAGS_JUSTIFY_LEFT (1u << 0u)
#define KPRINTF_FLAGS_PRECEDE_SIGN (1u << 1u)
#define KPRINTF_FLAGS_PRECEDE_BLANK (1u << 2u)
#define KPRINTF_FLAGS_PRECEDE_BASE_X_PREFIX (1u << 3u)
#define KPRINTF_FLAGS_LEFT_PAD_ZEROS (1u << 4u)
#define FLAGS_UPPERCASE (1u << 5u)
#define FLAGS_CHAR      (1u << 6u)
#define FLAGS_SHORT     (1u << 7u)
#define FLAGS_LONG      (1u << 8u)
#define FLAGS_LONG_LONG (1u << 9u)
#define FLAGS_PRECISION (1u << 10u)
#define FLAGS_ADAPT_EXP (1u << 11u)

/*
 * IMPLEMENT THIS
 * kprintf() prints single characters to this function.
*/
static inline void putc_(char c)
{
    // [implementation]
}

int printf(const char *format, ...)
{
    va_list var_args;
    va_start(var_args, format);

    int total_char_printed = 0;
    unsigned int flags, width, precision, n;

    va_end(var_args);

    return 0;
}