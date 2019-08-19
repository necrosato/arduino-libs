//
// unique_ptr.h
// Naookie Sato
//
// Created by Naookie Sato on 08/19/2019
// Copyright © 2018 Naookie Sato. All rights reserved.
//

#ifndef _HOME_NSATO_DOCUMENTS_ARDUINO_LIB_SMART_POINTERS_UNIQUE_PTR_H_
#define _HOME_NSATO_DOCUMENTS_ARDUINO_LIB_SMART_POINTERS_UNIQUE_PTR_H_

/**
 * An implementation of a unique pointer (see std::unique_ptr)
 */
template <class T>
class unique_ptr {
 public:
  unique_ptr() = delete;
  unique_ptr(const unique_ptr<T>& other) = delete;
  unique_ptr& operator=(const unique_ptr<T>& other) = delete;

  /**
   * Move constructor
   */
  unique_ptr(unique_ptr&& other) : ptr_(other.ptr_) { other.ptr_ = nullptr; }

  /**
   * Constructor taking a raw pointer to own
   */
  unique_ptr(T* ptr) : ptr_(ptr) {}

  /**
   * Destructor
   */
  virtual ~unique_ptr() {
    erase();
  }

  const T& operator*() {
    return *ptr_;
  }

  T* operator->() {
    return ptr_;
  }

  T* get() {
    return ptr_;
  }

  /**
   * Destroy the object owned by this pointer if it is not null.
   */
  void erase() {
    if (ptr_ != nullptr) {
      ptr_->~T();
    }
  }

  /**
   * Set this unique ptr to own a new pointer. Destroys old ptr object.
   */
  void reset(T* ptr) {
    erase();
    ptr_ = ptr;
  }

 private:
  T* ptr_;
};

#endif  // _HOME_NSATO_DOCUMENTS_ARDUINO_LIB_SMART_POINTERS_UNIQUE_PTR_H_
