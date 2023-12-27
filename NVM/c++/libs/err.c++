enum NERROR {
  RAM_ALLOC = 7,
  EMPTY_ROM
};

namespace NVM {
  void raise(NERROR err)
  {
    switch (err) {
      default:
        std::cout << "Internal ERR_HANDLE fault, contact dev team err[" << err << "]" << std::endl;
        break;

      case RAM_ALLOC:
        std::cout << "Insufficent memory, allocating 0xFFFF" << std::endl;
        break;
    }
  }
}
