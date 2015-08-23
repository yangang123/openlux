/*
  Copyright (c) 2015 Anonymous Meerkat

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/

#include "gamma.h"
#include "color.h"

void
rgb_to_gamma(unsigned int color, int gamma_ramp_size, unsigned short* red,
             unsigned short* green, unsigned short* blue)
{
  /* Calculated */
  unsigned short cred   = 0;
  unsigned short cgreen = 0;
  unsigned short cblue  = 0;

  /* Current */
  unsigned int redc   = 0;
  unsigned int greenc = 0;
  unsigned int bluec  = 0;

  /* Increment */
  unsigned int redi   = 0xffff * color_red(color);
  unsigned int greeni = 0xffff * color_green(color);
  unsigned int bluei  = 0xffff * color_blue(color);

  unsigned int range = 255 * (gamma_ramp_size - 1);

  for (int i = 0; i < gamma_ramp_size; i++)
    {
      cred = redc / range;
      redc += redi;
      red[i] = cred;

      cgreen = greenc / range;
      greenc += greeni;
      green[i] = cgreen;

      cblue = bluec / range;
      bluec += bluei;
      blue[i] = cblue;
    }
}

void
identity_gamma(int gamma_ramp_size, unsigned short* red,
               unsigned short* green, unsigned short* blue)
{
  for (int i = 0; i < gamma_ramp_size; i++)
    {
      red[i] = i << 8;
      green[i] = i << 8;
      blue[i] = i << 8;
    }
}