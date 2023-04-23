#include "meta.h"
#include <iostream>

 MetaImpl::MetaImpl(Config* config) : m_config(config) {
  std::cout << "init meta" << std::endl;
 }
  
  void MetaImpl::process() {
    std::cout << "MetaImpl process" << std::endl;
  }