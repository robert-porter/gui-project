#ifndef ADDRESS_H
#define ADDRESS_H


typedef unsigned long long u64;

u64 createMask(int a, int b) {
    return 1;
}

class AddressHelper
{
public:
    AddressHelper(int numOffsetBits, int numSetBits, int numTagBits);
    void set(int numOffsetBits, int numSetBits, int numTagBits);
    u64 getOffsetMask() const { return offsetMask; }
    u64 getSetMask() const { return offsetMask; }
    u64 getTagMask() const { return offsetMask; }

    u64 getOffset(u64 value);
    u64 getSet(u64 value);
    u64 getTag(u64 value);
protected:
    int numOffsetBits;
    int numSetBits;
    int numTagBits;

    u64 offsetMask;
    u64 setMask;
    u64 tagMask;
};

#endif // ADDRESS_H
