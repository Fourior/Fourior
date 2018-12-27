#include "common/util.h"
#include "common/async.h"
#include "common/concurrent.h"
int pointor() {
    std::shared_ptr<Util> util = std::make_shared<Util>("zhangyu");
    std::cout << Util::get_random_pct() << std::endl;
    std::shared_ptr<Util> util2;
    util2 = util;

    Util *pointer = new Util("zhy");
    // copy construct
    Util pointer1(*pointer);
    // operator=
    Util p2;
    p2 = *pointer;
    std::cout << p2.get_age() << std::endl;
    delete(pointer);
    pointer = NULL;

    std::cout << p2.get_name() << std::endl;
    return 0;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
//    pointor();
//    Async<std::string> *async = new Async<std::string>("zhy");
    std::shared_ptr<Async<std::string>> asyncPtr = std::make_shared<Async<std::string>>("zhangyu");

    return 0;
}
