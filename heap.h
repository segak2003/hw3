#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>

template <typename T, typename PComparator = std::less<T> >
class Heap 
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  
  std::vector<T> data_;
  int m_;
  PComparator comp_;
  void heapifyUp(int idx);
  void heapifyDown(int idx);
};

// Add implementation of member functions here

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item)
{
  data_.push_back(item);
  heapifyUp(data_.size() - 1);
}


template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c)
{
  m_ = m;
  comp_ = c;
}


template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{}


template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const
{
  return data_.size();
}
 

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    
    throw std::out_of_range("heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  
  return data_[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    
    throw std::out_of_range("heap is empty");
  }

  std::swap(data_[0], data_[data_.size() - 1]);

  data_.pop_back();


  if(this -> empty() != true) {
    heapifyDown(0);
  }
}



template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
  return (data_.size() == 0);
}



template <typename T, typename PComparator>
void Heap<T,PComparator>::heapifyUp(int idx)
{
  std::size_t parent_index = (idx - 1) / m_;
  while(idx != 0 && comp_(data_[idx], data_[parent_index] )) {
    std::swap(data_[idx], data_[parent_index]);
    idx = parent_index;
    parent_index = (idx - 1) / m_;
  }
}



template <typename T, typename PComparator>
void Heap<T,PComparator>::heapifyDown(int idx)
{
  
  //loop until you reach the end of the tree
  while(idx < data_.size()) 
  {
    std::size_t child_index = idx;
    std::size_t child_index2;

    for(int i = 1; i <= m_; i++ ) {
      child_index2 = m_*idx+i;

      //check if this child node exists
      if(child_index2 < data_.size()) {
        if(comp_(data_[child_index2], data_[child_index])){
          child_index = child_index2;
        }
      }
    }

    if(child_index == idx) {
      break;
    }
    
    std::swap(data_[idx], data_[child_index]);
    idx = child_index;
  }

}

#endif

