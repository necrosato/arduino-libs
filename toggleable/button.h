//
// button.h
// Naookie Sato
//
// Created by Naookie Sato on 07/24/2019
// Copyright © 2018 Naookie Sato. All rights reserved.
//

#ifndef _HOME_NSATO_ARDUINO_SKETCHES_MICRO_CONTROL_PANEL_LINUX_MICRO_CONTROL_PANEL_INCLUDE_BUTTON_H_
#define _HOME_NSATO_ARDUINO_SKETCHES_MICRO_CONTROL_PANEL_LINUX_MICRO_CONTROL_PANEL_INCLUDE_BUTTON_H_

#include "toggleable.h"

/**
 * A button associated with an action method
 */
class Button : public Toggleable {
 public:
  virtual ~Button() = default;
  Button() = delete;
  Button(const Button& other) = delete;
  Button& operator=(const Button& other) = delete;
  Button(void (*action)(), int pin, int trigger_state, int pin_mode);

  /**
   * If the button's state has changed since the last invocation, perform the action.
   */
  bool TriggerIfToggled();

 private:
  void(*action_)();
  int trigger_state_;
};

#endif  // _HOME_NSATO_ARDUINO_SKETCHES_MICRO_CONTROL_PANEL_LINUX_MICRO_CONTROL_PANEL_INCLUDE_BUTTON_H_
