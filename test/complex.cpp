/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2013-2015 Morwenn
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include <static_math/complex.h>
#include <static_math/formula.h>

using namespace smath;

int main()
{
    // Constructor tests
    constexpr auto i1 = imaginary<float>(5.8f);
    static_assert(smath::is_close(i1.value, 5.8f), "");

    constexpr auto c1 = complex<float>(1.2f, 2.5f);
    static_assert(smath::is_close(c1.real, 1.2f), "");
    static_assert(smath::is_close(c1.imag.value, 2.5f), "");

    constexpr auto imag0 = imaginary<int>(0);
    constexpr auto imag1 = imaginary<int>(1);
    constexpr auto imag2 = imaginary<int>(-2);
    constexpr auto comp0 = complex<int>(5, 0);
    constexpr auto comp1 = complex<int>(0, 1);
    constexpr auto comp2 = complex<int>(-1, 3);
    constexpr auto comp3 = complex<long long int>(5, 0);
    constexpr auto comp4 = complex<int>(-2, 4);
    constexpr auto comp5 = complex<int>(3, -1);

    // Unary + and -
    static_assert(-imag1 == imaginary<int>(-1), "");
    static_assert(+imag1 == imaginary<int>(1), "");
    static_assert(+comp0 == complex<int>(5, 0), "");
    static_assert(-comp0 == complex<int>(-5, 0), "");

    // Comparison tests
    static_assert(comp0 == 5, "");
    static_assert(comp1 == imag1, "");
    static_assert(comp0 == comp3, "");
    static_assert(comp0 != 3, "");
    static_assert(imag0 != imag1, "");
    static_assert(comp0 != comp1, "");

    // imaginary-imaginary arithmetic
    static_assert(imag1 + imag1 == 2_i, "");
    static_assert(imag1 - imag0 == 1_i, "");
    static_assert(imag1 * imag1 == -1, "");
    static_assert(4_i / 2_i == 2, "");

    // imaginary-scalar arithmetic
    static_assert(imag1 + 2 == complex<int>(2, 1), "");
    static_assert(-3 + imag1 == complex<int>(-3, 1), "");
    static_assert(imag2 - 5 == complex<int>(-5, -2), "");
    static_assert(2 - imag2 == complex<int>(2, 2), "");
    static_assert(imag1 * 3 == imaginary<int>(3), "");
    static_assert(-4 * imag2 == imaginary<int>(8), "");
    static_assert(imag2 / 2 == -1_i, "");
    static_assert(5 / imag1 == 5_i, "");

    // complex-complex arithmetic
    static_assert(comp4 + comp5 == complex<int>(1, 3), "");
    static_assert(comp5 - comp4 == complex<int>(5, -5), "");
    static_assert(comp4 * comp5 == complex<int>(-2, 14), "");
    static_assert(comp4 / comp5 == complex<int>(-1, 1), "");

    // complex-scalar arithmetic
    static_assert(comp4 + 5 == complex<int>(3, 4), "");
    static_assert(-2 + comp5 == complex<int>(1, -1), "");
    static_assert(comp1 - 2 == complex<int>(-2, 1), "");
    static_assert(3 - comp2 == complex<int>(4, -3), "");
    static_assert(comp4 * 5 == complex<int>(-10, 20), "");
    static_assert(-2 * comp5 == complex<int>(-6, 2), "");
    static_assert(comp4 / 2 == complex<int>(-1, 2), "");
    static_assert(4 / complex<int>(2, 2) == complex<int>(1, -1), "");

    // complex-imaginary arithmetic
    static_assert(comp1 + 5_i == complex<int>(0, 6), "");
    static_assert(-2_i + comp0 == complex<int>(5, -2), "");
    static_assert(comp2 - -1_i == complex<int>(-1, 4), "");
    static_assert(8_i - comp3 == complex<int>(-5, 8), "");
    static_assert(comp4 * 2_i == complex<int>(-8, -4), "");
    static_assert(-3_i * comp5 == complex<int>(-3, -9), "");
    static_assert(comp4 / 2_i == complex<int>(2, 1), "");
    static_assert(4_i / complex<int>(2, 2) == complex<int>(1, 1), "");

    // Mathematical functions
    constexpr auto c2 = 3.0f + 4.0_if;
    static_assert(smath::is_close(smath::norm(c2), 25.0f), "");
    static_assert(smath::is_close(smath::abs(c2), 5.0f), "");

    static_assert(smath::conj(comp4) == complex<int>(-2, -4), "");
    static_assert(smath::conj(comp5) == complex<int>(3, 1), "");
}
