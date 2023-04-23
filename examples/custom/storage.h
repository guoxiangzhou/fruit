#pragma once

#include "config.h"

class Storage {
public:

  virtual void run() = 0;

};

class StorageImpl : public Storage {
public:
  StorageImpl(Config* config);

  void run() override;
private:
  Config *m_config;
};