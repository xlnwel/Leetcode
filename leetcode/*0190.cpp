#include <cstdint>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = ((n >> 1) & M1) | ((n & M1) << 1);
        n = ((n >> 2) & M2) | ((n & M2) << 2);
        n = ((n >> 4) & M3) | ((n & M3) << 4);
        n = ((n >> 8) & M4) | ((n & M4) << 8);
        return n >> 16 | n << 16;
    }
private:
    static constexpr uint32_t M1 = 0x55555555;
    static constexpr uint32_t M2 = 0x33333333;
    static constexpr uint32_t M3 = 0x0F0F0F0F;
    static constexpr uint32_t M4 = 0x00FF00FF;
};

class Solution2 {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (auto i = 0; i != 32; ++i) {
            ans <<= 1;
            ans |= n&1;
            n >>= 1;
        }
        return ans;
    }
};
