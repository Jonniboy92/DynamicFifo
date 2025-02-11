# DynamicFifo

DynamicFifo is a **dynamic FIFO (First In, First Out) data structure** designed for **Arduino and C++ projects**.
It enables flexible memory management by allocating memory only when an element is added.

## 📌 Features

- **Dynamic memory allocation**: Memory is allocated only when elements are added.
- **FIFO principle**: The first inserted element is removed first.
- **Maximum length**: The FIFO can have a predefined maximum length.
- **Easy to use**: Supports standard methods like `enqueue()`, `dequeue()`, `isEmpty()`, `isFull()`, etc.

## 📜 Installation

1. Download the file `DynamicFifo.h`.
2. Add it to your Arduino library.
3. Include the file using `#include "DynamicFifo.h"` in your program.

## 🚀 Usage

In the Liberi is a example includet.

## 📌 API Methods

┌─────────────────┬─────────────────────────────────────────────────────────────────────────────┐
│Method          	│ Description                                                                 │
├─────────────────┼─────────────────────────────────────────────────────────────────────────────┤
│enqueue(T data)	│ Adds an element to the queue. Returns true if successful.                   │
│dequeue(T &data)	│ Removes the first element and stores it in data. Returns true if successful.│
│isEmpty()	      │ Returns true if the queue is empty.                                         │
│isFull()	        │ Returns true if the maximum length is reached.                              │
│length()	        │ Returns the current number of elements.                                     │
│maxlength()	    │ Returns the maximum length of the queue.                                    │
└─────────────────┴─────────────────────────────────────────────────────────────────────────────┘
