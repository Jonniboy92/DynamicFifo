#ifndef __DynamicFifo__
#define __DynamicFifo__

  #define Version_DynamicFifo 0

/* Fifo:
     der Fifo ist Dynaich, das bedeutet, das erst wenn ein element hinzugefügt wird, speicherplatz für diesen reserviert wird.
*/

    #include <Arduino.h>

    template <typename T> class DynamicFifo {
      private:
        struct Node {
          T data;
          Node* next;
        };

        Node* head;
        Node* tail;
        uint16_t max_length;
        uint16_t current_length;

      public:
        explicit DynamicFifo(uint16_t max_length);

        ~DynamicFifo();

        bool enqueue(const T& data);  // True = Store / False = Fifo full

        bool dequeue(T& data);        // True = ok    / False = FiFo is Empty

        bool isEmpty() const;         // Fifo is empty
	   
        bool isFull() const;          // Fifo is full

        uint16_t length() const;      // No. of ellements in FiFo
	   
        uint16_t maxlength() const;   // Maximal sice / space of Fifo

    };


//--------------------------------------------------------------------------------------------------------------------------------
// Konstroktor
//--------------------------------------------------------------------------------------------------------------------------------

  template <typename T> DynamicFifo<T>::DynamicFifo(uint16_t max_length) : head(nullptr), tail(nullptr), max_length(max_length), current_length(0) {}

//--------------------------------------------------------------------------------------------------------------------------------
// Dekonstroktor
//--------------------------------------------------------------------------------------------------------------------------------

  template <typename T> DynamicFifo<T>::~DynamicFifo() {
    while (!isEmpty()) {
      Node* temp = head;
      head = head->next;
      delete temp;
    }
  }

//--------------------------------------------------------------------------------------------------------------------------------
// enqueue
//--------------------------------------------------------------------------------------------------------------------------------

  template <typename T> bool DynamicFifo<T>::enqueue(const T& data) {
    if (isFull()) { // FIFO voll, Element wird nicht hinzugefügt
      return false;
    }

    Node* newNode = new Node;
    memcpy(&newNode->data, &data, sizeof(T)); // Kopiere die Daten in den neuen Node

    newNode->next = nullptr;

    if (isEmpty()) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }

    current_length++;
    
    return true;
  }

//--------------------------------------------------------------------------------------------------------------------------------
// dequeue
//--------------------------------------------------------------------------------------------------------------------------------

  template <typename T> bool DynamicFifo<T>::dequeue(T& data) {
    if (isEmpty()) {
      return false;
    }

    Node* temp = head;
    memcpy(&data, &temp->data, sizeof(T));

    head = head->next;

    delete temp;
    current_length--;

    if (head == nullptr) {
      tail = nullptr;
      current_length = 0;
    }

    return true;
  }

//--------------------------------------------------------------------------------------------------------------------------------
// isEmpty
//--------------------------------------------------------------------------------------------------------------------------------

  template <typename T> bool DynamicFifo<T>::isEmpty() const {
    return head == nullptr;
  }

//--------------------------------------------------------------------------------------------------------------------------------
// isFull
//--------------------------------------------------------------------------------------------------------------------------------

  template <typename T> bool DynamicFifo<T>::isFull() const {
      return current_length >= max_length ? true : false;
  }

//--------------------------------------------------------------------------------------------------------------------------------
// length
//--------------------------------------------------------------------------------------------------------------------------------

  template <typename T> uint16_t DynamicFifo<T>::length() const {
    return current_length;
  }
  
//--------------------------------------------------------------------------------------------------------------------------------
// maxlength
//--------------------------------------------------------------------------------------------------------------------------------

  template <typename T> uint16_t DynamicFifo<T>::maxlength() const {
    return max_length;
  }

//--------------------------------------------------------------------------------------------------------------------------------
#endif