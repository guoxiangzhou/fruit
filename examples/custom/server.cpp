#include "server.h"
#include <iostream>

 ServerImpl::ServerImpl(Config* config, Meta *meta, Storage* storage) {
  m_config = config;
  m_meta = meta;
  m_storage = storage;
  std::cout << "init server" << std::endl;
 }

 void ServerImpl::run(){
  m_meta->process();
  m_storage->run();
 }