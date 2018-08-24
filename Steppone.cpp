/*
 * Steppone.h - Stepper library for Wiring/Arduino - Version 0.1

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
 */

#include "Arduino.h"
#include "Steppone.h"


Steppone::Steppone(int pin1, int pin2, int pin3, int pin4)
{
  this->step_number = 0;    // which step the motor is on
  this->direction = 0;      // motor direction
  this->last_time = 0; // time stamp in us of the last step taken

  // Arduino pins for the motor control connection:
  this->pin1 = pin1;
  this->pin2 = pin2;
  this->pin3 = pin3;
  this->pin4 = pin4;

  // setup the pins on the microcontroller:
  pinMode(this->pin1, OUTPUT);
  pinMode(this->pin2, OUTPUT);
  pinMode(this->pin3, OUTPUT);
  pinMode(this->pin4, OUTPUT);

}

void Steppone::step(int steps_to_move,int  direction){
  this->direction = direction;
  while (steps_to_move > 0) {
    this->currentMillis = micros();
    if (this->currentMillis - this->last_time >= 1000) {
      this->motor();
      this->last_time = micros();
      steps_to_move--;
    }
  }
}


void Steppone::motor() {
  switch (this->step_number) {
    case 0:
      digitalWrite(this->pin1, LOW);
      digitalWrite(this->pin2, LOW);
      digitalWrite(this->pin3, LOW);
      digitalWrite(this->pin4, HIGH);
      break;
    case 1:
      digitalWrite(this->pin1, LOW);
      digitalWrite(this->pin2, LOW);
      digitalWrite(this->pin3, HIGH);
      digitalWrite(this->pin4, HIGH);
      break;
    case 2:
      digitalWrite(this->pin1, LOW);
      digitalWrite(this->pin2, LOW);
      digitalWrite(this->pin3, HIGH);
      digitalWrite(this->pin4, LOW);
      break;
    case 3:
      digitalWrite(this->pin1, LOW);
      digitalWrite(this->pin2, HIGH);
      digitalWrite(this->pin3, HIGH);
      digitalWrite(this->pin4, LOW);
      break;
    case 4:
      digitalWrite(this->pin1, LOW);
      digitalWrite(this->pin2, HIGH);
      digitalWrite(this->pin3, LOW);
      digitalWrite(this->pin4, LOW);
      break;
    case 5:
      digitalWrite(this->pin1, HIGH);
      digitalWrite(this->pin2, HIGH);
      digitalWrite(this->pin3, LOW);
      digitalWrite(this->pin4, LOW);
      break;
    case 6:
      digitalWrite(this->pin1, HIGH);
      digitalWrite(this->pin2, LOW);
      digitalWrite(this->pin3, LOW);
      digitalWrite(this->pin4, LOW);
      break;
    case 7:
      digitalWrite(this->pin1, HIGH);
      digitalWrite(this->pin2, LOW);
      digitalWrite(this->pin3, LOW);
      digitalWrite(this->pin4, HIGH);
      break;
    default:
      digitalWrite(this->pin1, LOW);
      digitalWrite(this->pin2, LOW);
      digitalWrite(this->pin3, LOW);
      digitalWrite(this->pin4, LOW);
      break;
  }
  this->nextStep();
}


void  Steppone::nextStep(){
  if (this->direction == 1) {
    this->step_number++;
  }
  if (this->direction == 0) {
    this->step_number--;
  }
  if (step_number > 7) {
    this->step_number = 0;
  }
  if (step_number < 0) {
    this->step_number = 7;
  }
}
