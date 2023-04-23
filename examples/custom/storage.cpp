#include "storage.h"
#include <iostream>


  StorageImpl::StorageImpl(Config* config) : m_config(config){
    std::cout << "init Storage" << std::endl;
 }
  
  void StorageImpl::run() {
    std::cout << "StorageImpl process" << std::endl;
  }