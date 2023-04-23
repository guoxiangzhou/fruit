#include "server.h"
#include <fruit/fruit.h>

// fruit::Component<Config> getConfigComponent() {
//   return fruit::createComponent()
    
// }


// fruit::Component<Meta> getMetaComponent() {
//   return fruit::createComponent()
//     ;
// }

// fruit::Component<Storage> getStorageComponent() {
//   return fruit::createComponent()
    
// }

fruit::Component<Server> getServerComponent() {
  return fruit::createComponent()
    .registerConstructor<Config()>()
    .registerConstructor<MetaImpl(Config*)>()
    .registerConstructor<StorageImpl(Config*)>()
    .registerConstructor<ServerImpl(Config*, Meta *, Storage*)>()
    .bind<Meta, MetaImpl>()
    .bind<Storage, StorageImpl>()
    .bind<Server, ServerImpl>();
}

int main() {
  fruit::Injector<Server> injector(getServerComponent);
  Server* server = injector.get<Server*>();

  server->run();


  return 0;
}
