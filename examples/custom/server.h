#pragma once

#include "config.h"
#include "meta.h"
#include "storage.h"

class Server {
public:
  virtual void run() = 0;

};

class ServerImpl : public Server {
public:
  ServerImpl(Config* config, Meta *meta, Storage* storage);

  void run() override;

private:
  Config *m_config;
  Meta *m_meta;
  Storage *m_storage;
};