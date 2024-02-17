#include <vector>
class RAM
{
  public:
    std::vector<uint32_t> ram;
    RAM() {ram.resize(65536);}
};
