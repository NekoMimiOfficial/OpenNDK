#include "../../libs/types.cpp"
#include <vector>

class Ram
{
  public:
    std::vector<i16> ram;

    Ram(size_t size) {ram.resize(size);}
};
