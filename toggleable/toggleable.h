//
// toggleable.h
// Naookie Sato
//
// Created by Naookie Sato on 07/24/2019
// Copyright © 2018 Naookie Sato. All rights reserved.
//

#ifndef _HOME_NSATO_ARDUINO_SKETCHES_MICRO_CONTROL_PANEL_LINUX_MICRO_CONTROL_PANEL_INCLUDE_TOGGLEABLE_H_
#define _HOME_NSATO_ARDUINO_SKETCHES_MICRO_CONTROL_PANEL_LINUX_MICRO_CONTROL_PANEL_INCLUDE_TOGGLEABLE_H_

/**
 * An abstract base class for objects which are toggleable between high and low state.
 */
class Toggleable {
 public:
  virtual ~Toggleable() = default;
  Toggleable() = delete;
  Toggleable(const Toggleable& other) = delete;
  Toggleable& operator=(const Toggleable& other) = delete;
  Toggleable(int pin);

  /**
   * Perform some action when the state is toggled.
   */
  virtual bool TriggerIfToggled() = 0;

 protected:
  int PinState();

  bool IsToggled();

  int pin_;
  int current_state_;
};


#endif  // _HOME_NSATO_ARDUINO_SKETCHES_MICRO_CONTROL_PANEL_LINUX_MICRO_CONTROL_PANEL_INCLUDE_TOGGLEABLE_H_
