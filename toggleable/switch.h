//
// switch.h
// Naookie Sato
//
// Created by Naookie Sato on 07/24/2019
// Copyright © 2018 Naookie Sato. All rights reserved.
//

#ifndef _HOME_NSATO_ARDUINO_SKETCHES_MICRO_CONTROL_PANEL_LINUX_MICRO_CONTROL_PANEL_INCLUDE_SWITCH_H_
#define _HOME_NSATO_ARDUINO_SKETCHES_MICRO_CONTROL_PANEL_LINUX_MICRO_CONTROL_PANEL_INCLUDE_SWITCH_H_

#include "toggleable.h"

/**
 * A switch associated with two action methods
 */
class Switch : public Toggleable {
 public:
  virtual ~Switch() = default;
  Switch() = delete;
  Switch(const Switch& other) = delete;
  Switch& operator=(const Switch& other) = delete;
  Switch(void (*action_low)(), void(*action_high)(), int pin, int pin_mode);

  /**
   * If the button's state has changed since the last invocation, perform the action.
   */
  bool TriggerIfToggled();

 private:
  void(*action_high_)();
  void(*action_low_)();
};


#endif  // _HOME_NSATO_ARDUINO_SKETCHES_MICRO_CONTROL_PANEL_LINUX_MICRO_CONTROL_PANEL_INCLUDE_SWITCH_H_
