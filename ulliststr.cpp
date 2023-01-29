#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val){
  if(size_ == 0){
    head_ = new Item();
    tail_ = head_;
  }
  else if(tail_->last == ARRSIZE){
    tail_->next = new Item();
    tail_ = tail_->next;
    tail_->next = nullptr;
  }
  tail_->val[tail_->last] = val;
  tail_->last ++;
  size_ ++;
}

void ULListStr::pop_back(){
  if(tail_->last == 1){
    tail_ = tail_->prev;
    delete tail_->next;
    tail_->next = nullptr;
    tail_->last = ARRSIZE;
  }
  else{
    tail_->last --;
  }
  size_ --;
}

void ULListStr::push_front(const std::string& val){
  if(size_ == 0){
    head_ = new Item();
    tail_ = head_;
    head_->val[0] = val;
    head_->last = 1;
  }
  else if(tail_->first == 0){
    head_->prev = new Item;
    head_->prev->next = head_;
    head_ = head_->prev;
    head_->prev = nullptr;
    head_->val[ARRSIZE-1] = val;
    head_->last = ARRSIZE;
    head_->first = ARRSIZE-1;
  }
  else{
    head_->val[head_->first-1] = val;
    head_->first --;
  }
  size_ ++;
}

void ULListStr::pop_front(){
  if(head_->first == ARRSIZE-1){
    head_ = head_->next;
    delete head_->prev;
    head_->prev = nullptr;
    head_->first = 0;
  }
  else{
    head_->first ++;
  }
  size_ --;
}

std::string const & ULListStr::front() const{
  return head_->val[head_->first];
}

std::string const & ULListStr::back() const{
  return tail_->val[tail_->last-1];
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  size_t cur = 0;
  Item* nod = head_;
  while(nod != nullptr){
    size_t s = nod->last - nod->first;
    if(cur + s > loc){
      return &nod->val[loc-cur+nod->first];
    }
    else{
      cur += s;
      nod = nod->next;
    }
  }
  return nullptr;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
