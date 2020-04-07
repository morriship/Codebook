// modified from noshi91's note
// http://noshi91.hatenablog.com/entry/2019/03/31/174006
// replaced algorithm from Fermat's Little Theorem to Inverse Element
#include <cstdint>
#include <ostream>
using namespace std;

template <int_fast64_t Modulus> class ModInt {
  using i64 = int_fast64_t;
public:
  i64 a;
  ModInt(const i64 x = 0) noexcept : a (( x > 0 ? x : Modulus - ((-x) % Modulus)) % Modulus) {}
  i64 &value() noexcept { return a; }
  i64 &value() const noexcept { return a; }
  ModInt operator+(const ModInt rhs) const noexcept { return ModInt(*this) += rhs; }
  ModInt operator-(const ModInt rhs) const noexcept { return ModInt(*this) -= rhs; }
  ModInt operator*(const ModInt rhs) const noexcept { return ModInt(*this) *= rhs; }
  ModInt operator/(const ModInt rhs) const noexcept { return ModInt(*this) /= rhs; }
  ModInt &operator+=(const ModInt rhs) noexcept { a += rhs.a; if (a >= Modulus) { a -= Modulus; } return *this; }
  ModInt &operator-=(const ModInt rhs) noexcept { if (a < rhs.a) { a += Modulus; } a -= rhs.a; return *this; }
  ModInt &operator*=(const ModInt rhs) noexcept { a = a * rhs.a % Modulus; return *this; }
  // ModInt &operator/=(ModInt rhs) noexcept { i64 exp = Modulus - 2; while (exp) { if (exp & 1) { *this *= rhs; } rhs *= rhs; exp >>= 1; } return *this; }
  ModInt &operator/=(ModInt rhs) noexcept { *this *= rhs.inverse(); return *this; }
  ModInt inverse() const noexcept { int_fast64_t x(a), y(Modulus), u(1), v(0), t; while (y) { t = x / y; swap(x -= t * y, y); swap(u -= t * v, v); } return ModInt(u); } 
  friend ostream &operator<<(ostream &os, const ModInt<Modulus> rhs) { return os << rhs.a; }
};

// using Mint = ModInt<mod>;
// auto mint = Mint(1);
