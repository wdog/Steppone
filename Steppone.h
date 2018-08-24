/*
 * Steppone.h - Stepper library for Wiring/Arduino - Version 0.1
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

 *
 * The sequence of control signals for 4 control wires is as follows:
 *
 * Step C0 C1 C2 C3
 *    1  1  0  1  0
 *    2  0  1  1  0
 *    3  0  1  0  1
 *    4  1  0  0  1
 */

#ifndef Steppone_h
#define Steppone_h
#include "Arduino.h"
class Steppone

{
  public:
    Steppone(int pin1, int pin2, int pin3, int pin4);
    void step(int steps, int direction);
  private:
    void motor(); 
    void nextStep(); 

    int step_number;
    int pin1;
    int pin2;
    int pin3;
    int pin4;
    int direction = 0;
    unsigned long last_time;
    unsigned long currentMillis; 
};


#endif;
