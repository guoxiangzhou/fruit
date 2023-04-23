
#include <fruit/fruit.h>
#include <iostream>

using fruit::Component;
using fruit::Injector;

class Writer {
public:
  virtual void write(std::string s) = 0;
};

class StdoutWriter : public Writer {
public:
  // Like "StdoutWriter() = default;" but also marks this constructor as the
  // one to use for injection.
  StdoutWriter() = default;

  virtual void write(std::string s) override {
    std::cout << s;
  }
};

class Reader {
public:
  virtual void read(std::string s) = 0;
};

class StdoutReader : public Reader {
public:
  // Like "StdoutWriter() = default;" but also marks this constructor as the
  // one to use for injection.
  StdoutReader() = default;

  virtual void read(std::string s) override {
    std::cout << s;
  }
};


class Greeter {
public:
  virtual void greet() = 0;
};

class GreeterImpl : public Greeter {
private:
  Writer* writer;
  Reader* reader;

public:
  // Like "GreeterImpl(Writer* writer) {...}" but also marks this constructor
  // as the one to use for injection.
  GreeterImpl(Writer* writer, Reader* reader) : writer(writer), reader(reader) {}

  virtual void greet() override {
    writer->write("Hello world!\n");
    reader->read("00000022200xxx000000\n");
  }
};

Component<Greeter> getGreeterComponent() {
  return fruit::createComponent()
    .registerConstructor<StdoutReader()>()
    .registerConstructor<StdoutWriter()>()
    .registerConstructor<GreeterImpl(Writer*, Reader*)>()
    .bind<Writer, StdoutWriter>()
    .bind<Reader, StdoutReader>()
    .bind<Greeter, GreeterImpl>();
}

int main() {

  Injector<Greeter> injector(getGreeterComponent);
  Greeter* greeter = injector.get<Greeter*>();

  greeter->greet();

  return 0;
}
