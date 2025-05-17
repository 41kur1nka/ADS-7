// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : first(nullptr), countOp(0) {}

Train::~Train() {
  if (!first) return;
  Car* cur = first->next;
  while (cur != first) {
    Car* toDel = cur;
    cur = cur->next;
    delete toDel;
  }
  delete first;
}

void Train::addCar(bool light) {
  Car* c = new Car(light);
  if (!first) {
    first = c;
  } else {
    Car* last = first->prev;
    last->next = c;
    c->prev = last;
    c->next = first;
    first->prev = c;
  }
}

std::size_t Train::getLength() {
  if (!first) return 0;
  countOp = 0;

  std::size_t len = 1;
  Car* cur = first->next;
  ++countOp;
  while (cur != first) {
    ++len;
    cur = cur->next;
    ++countOp;
  }
  return len;
}

std::size_t Train::getOpCount() const { return countOp; }
