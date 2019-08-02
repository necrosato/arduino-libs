//
// toggleable.cpp
// Naookie Sato
//
// Created by Naookie Sato on 07/24/2019
// Copyright © 2018 Naookie Sato. All rights reserved.
//

#include <Arduino.h>
#include "toggleable.h"

Toggleable::Toggleable(int pin) : pin_(pin) {
  pinMode(pin, INPUT);
  current_state_ = digitalRead(pin);
}

int Toggleable::PinState() {
  return digitalRead(pin_);
}

bool Toggleable::IsToggled() {
  int state_tmp = PinState();
  if (current_state_ != state_tmp) {
    current_state_ = state_tmp;
    return true;
  }
  return false;
}
