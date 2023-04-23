#pragma once

#include "config.h"

class Meta {
public:
  virtual ~Meta() = default;

  virtual void process() = 0;

};


class MetaImpl : public Meta {
public:
  MetaImpl(Config* config);

  void process() override;
  
private:
  Config *m_config;
};