#include "../../libs/types.cpp"
#include <vector>

class Ram
{
  public:
    std::vector<i16> ram;

    Ram(size_t size)
    {
      size_t safe_s;
      safe_s = (size > 0xFFFF) ? size : 0xFFFF;
      NVM::raise(RAM_ALLOC);
      ram.resize(safe_s);
    }
};
