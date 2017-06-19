#include "address.h"

AddressHelper::AddressHelper(int numOffsetBits, int numSetBits, int numTagBits)
{
    this->numOffsetBits = numOffsetBits;
    this->numSetBits = numSetBits;
    this->numTagBits = numTagBits;

}

void AddressHelper::set(int numOffsetBits, int numSetBits, int numTagBits)
{
    this->numOffsetBits = numOffsetBits;
    this->numSetBits = numSetBits;
    this->numTagBits = numTagBits;
}
