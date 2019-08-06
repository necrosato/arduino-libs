//
// button.cpp
// Naookie Sato
//
// Created by Naookie Sato on 07/24/2019
// Copyright © 2018 Naookie Sato. All rights reserved.
//

#include <Arduino.h>
#include "button.h"

Button::Button(void (*action)(), int pin, int trigger_state, int pin_mode) :
    Toggleable(pin, pin_mode), action_(action), trigger_state_(trigger_state) {}

bool Button::TriggerIfToggled() {
  if (IsToggled() && current_state_ == trigger_state_) {
    action_();
    return true;
  }
  return false;
}

