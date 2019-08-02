//
// switch.cpp
// Naookie Sato
//
// Created by Naookie Sato on 07/24/2019
// Copyright © 2018 Naookie Sato. All rights reserved.
//

#include <Arduino.h>
#include "switch.h"

Switch::Switch(void (*action_low)(), void(*action_high)(), int pin) :
    Toggleable(pin), action_low_(action_low), action_high_(action_high) {}

bool Switch::TriggerIfToggled() {
  if (IsToggled()) {
    if (current_state_ == HIGH) {
      action_high_();
    } else {
      action_low_();
    }
    return true;
  }
  return false;
}
