# Minimal printf() for OSDev and Embedded Devices

This repository provides a minimalistic, custom, dependency-free and SSE free implementation of the printf() function.

## Feature List

This implementation is (mostly) compatible with the libc <stdio.h> definition.

> %[flags][width][.precision][length]specifier

<table>
    <tbody>
        <tr>
            <th><i>specifier</i></th>
            <th>Output</th>
            <th>Example</th>
        </tr>
        <tr>
            <td><tt>b</tt></td>
            <td>Unsigned binary integer</td>
            <td><tt>0b10010</tt></td>
        </tr>
        <tr>
            <td><tt>d</tt> <i>or</i> <tt>i</tt></td>
            <td>Signed decimal integer</td>
            <td><tt>392</tt></td>
        </tr>
        <tr>
            <td><tt>u</tt></td>
            <td>Unsigned decimal integer</td>
            <td><tt>7235</tt></td>
        </tr>
        <tr>
            <td><tt>o</tt></td>
            <td>Unsigned octal integer</td>
            <td><tt>610</tt></td>
        </tr>
        <tr>
            <td><tt>x</tt></td>
            <td>Unsigned hexadecimal integer</td>
            <td><tt>7fa</tt></td>
        </tr>
        <tr>
            <td><tt>X</tt></td>
            <td>Unsigned hexadecimal integer (uppercase)</td>
            <td><tt>7FA</tt></td>
        </tr>
        <tr>
            <td><tt>f</tt> <i>or</i> <tt>F</tt></td>
            <td>Decimal floating point</td>
            <td><tt>392.65</tt></td>
        </tr>
        <tr>
            <td><tt>e</tt> <i>or</i> <tt>E</tt></td>
            <td>Scientific notation (mantissa/exponent), lowercase</td>
            <td><tt>3.9265e+2</tt></td>
        </tr>
        <tr>
            <td><tt>g</tt> <i>or</i> <tt>G</tt></td>
            <td>Use the shortest representation: <tt>%e</tt> or <tt>%f</tt></td>
            <td><tt>392.65</tt></td>
        </tr>
        <tr>
            <td><tt>c</tt></td>
            <td>Character</td>
            <td><tt>a</tt></td>
        </tr>
        <tr>
            <td><tt>s</tt></td>
            <td>String of characters</td>
            <td><tt>sample</tt></td>
        </tr>
        <tr>
            <td><tt>p</tt></td>
            <td>Pointer address</td>
            <td><tt>b8000000</tt></td>
        </tr>
        <tr>
            <td><tt>%</tt></td>
            <td>
                A <tt>%</tt> followed by another <tt>%</tt> character will write
                a single <tt>%</tt> to the stream.
            </td>
            <td><tt>%</tt></td>
        </tr>
    </tbody>
</table>

<table>
    <tbody>
        <tr>
            <th>
                <i>flags</i>
            </th>
            <th>description</th>
        </tr>
        <tr>
            <td><tt>-</tt></td>
            <td>
                Left-justify within the given field width; Right justification is the default.
            </td>
        </tr>
        <tr>
            <td><tt>+</tt></td>
            <td>
                Forces to preceed the result with a plus or minus sign (<tt
                    >+</tt
                >
                or <tt>-</tt>) even for positive numbers. By default, only
                negative numbers are preceded with a <tt>-</tt> sign.
            </td>
        </tr>
        <tr>
            <td><i>(space)</i></td>
            <td>
                If no sign is going to be written, a blank space is inserted
                before the value.
            </td>
        </tr>
        <tr>
            <td><tt>#</tt></td>
            <td>
                Used with <tt>b</tt>, <tt>o</tt>, <tt>x</tt> or <tt>X</tt> specifiers the
                value is preceeded with <tt>0b</tt>, <tt>0</tt>, <tt>0x</tt> or
                <tt>0X</tt> respectively for values different than zero.<br />
                Used with <tt>f</tt>, <tt>F</tt>, it forces the
                written output to contain a decimal point even if no more digits
                follow. By default, if no digits follow, no decimal point is
                written.
            </td>
        </tr>
        <tr>
            <td><tt>0</tt></td>
            <td>
                Left-pads the number with zeroes (<tt>0</tt>) instead of spaces
                when padding is specified (see <i>width</i> sub-specifier).
            </td>
        </tr>
    </tbody>
</table>

<table>
    <tbody>
        <tr>
            <th><i>width</i></th>
            <th>description</th>
        </tr>
        <tr>
            <td><i>(number)</i></td>
            <td>
                Minimum number of characters to be printed. If the value to be
                printed is shorter than this number, the result is padded with
                blank spaces. The value is not truncated even if the result is larger.
            </td>
        </tr>
        <tr>
            <td><tt>*</tt></td>
            <td>
                The <i>width</i> is not specified in the <i>format</i> string,
                but as an additional integer value argument preceding the
                argument that has to be formatted.
            </td>
        </tr>
    </tbody>
</table>

<table class="boxed">
    <tbody>
        <tr>
            <th><i>.precision</i></th>
            <th>description</th>
        </tr>
        <tr>
            <td><tt>.</tt><i>number</i></td>
            <td>
                For integer specifiers (<tt>d</tt>, <tt>i</tt>, <tt>o</tt>,
                <tt>u</tt>, <tt>x</tt>, <tt>X</tt>): <i>precision</i> specifies
                the minimum number of digits to be written. If the value to be
                written is shorter than this number, the result is padded with
                leading zeros. The value is not truncated even if the result is
                longer. A <i>precision</i> of <tt>0</tt> means that no character
                is written for the value <tt>0</tt>.<br />
                For <tt>f</tt> and <tt>F</tt> specifiers: this is the number of digits to be printed <strong>after</strong> the decimal point (by default, this is 6).<br />
                For <tt>g</tt> and <tt>G</tt> specifiers: This is the maximum
                number of significant digits to be printed.<br />
                For <tt>s</tt>: this is the maximum number of characters to be
                printed. By default all characters are printed until the ending
                null character is encountered.<br />
                If the period is specified without an explicit value for
                <i>precision</i>, <tt>0</tt> is assumed.<br />
            </td>
        </tr>
        <tr>
            <td><tt>.*</tt></td>
            <td>
                The <i>precision</i> is not specified in the
                <i>format</i> string, but as an additional integer value
                argument preceding the argument that has to be formatted.
            </td>
        </tr>
    </tbody>
</table>

<table>
    <tbody>
        <tr>
            <th></th>
            <th colspan="3">specifiers</th>
        </tr>
        <tr>
            <th><i>length</i></th>
            <th><tt>d i</tt></th>
            <th><tt>u o x X</tt></th>
        </tr>
        <tr>
            <td><i>(none)</i></td>
            <td><tt>int</tt></td>
            <td><tt>unsigned int</tt></td>
        </tr>
        <tr>
            <td><tt>hh</tt></td>
            <td><tt>signed char</tt></td>
            <td><tt>unsigned char</tt></td>
        </tr>
        <tr>
            <td><tt>h</tt></td>
            <td><tt>short int</tt></td>
            <td><tt>unsigned short int</tt></td>
        </tr>
        <tr>
            <td><tt>l</tt></td>
            <td><tt>long int</tt></td>
            <td><tt>unsigned long int</tt></td>
        </tr>
        <tr>
            <td><tt>ll</tt></td>
            <td><tt>long long int</tt></td>
            <td><tt>unsigned long long int</tt></td>
        </tr>
        <tr>
            <td><tt>j</tt></td>
            <td>
                <tt>intmax_t</tt>
            </td>
            <td>
                <tt>uintmax_t</tt>
            </td>
        </tr>
        <tr>
            <td><tt>z</tt></td>
            <td>
                <tt>size_t</tt>
            </td>
            <td>
                <tt>size_t</tt>
            </td>
        </tr>
        <tr>
            <td><tt>t</tt></td>
            <td>
                <tt>ptrdiff_t</tt>
            </td>
            <td>
                <tt>ptrdiff_t</tt>
            </td>
        </tr>
    </tbody>
</table>

The total number of characters written is returned.

## Usage:

Define putc_(char c) in kprintf.c and include
the header file into your project.