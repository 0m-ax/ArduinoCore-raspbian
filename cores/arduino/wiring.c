/*
  wiring.c - Partial implementation of the Wiring API for the ATmega8.
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2005-2006 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA
*/

#include "wiring_private.h"
#include <time.h>
static unsigned char timer0_fract = 0;


unsigned long millis()
{
     return 0;
}

unsigned long micros() {
    return 0;
}

/* Delay for the given number of microseconds.  Assumes a 1, 8, 12, 16, 20 or 24 MHz clock. */
void delayMicroseconds(unsigned int us)
{
   struct timespec req, rem;
 
   req.tv_sec = 0;                         /* Must be Non-Negative */
   req.tv_nsec = us * 1000;    /* Must be in range of 0 to 999999999 */
   nanosleep(&req , &rem);

}

void delay(unsigned long ms)
{
       struct timespec req, rem;

   if(ms > 999)
   {   
        req.tv_sec = (int)(ms*1000);                            /* Must be Non-Negative */
        req.tv_nsec = (ms - ((long)req.tv_sec * 1000)) * 1000000; /* Must be in range of 0 to 999999999 */
   }   
   else
   {   
        req.tv_sec = 0;                         /* Must be Non-Negative */
        req.tv_nsec = ms * 1000000;    /* Must be in range of 0 to 999999999 */
   }   

   nanosleep(&req , &rem);
}
void init()
{
}
