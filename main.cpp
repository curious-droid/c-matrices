#include <vector>

#define matrix std::vector<std::vector<long long>>
#define MOD 998244353

matrix operator*(const matrix _a, const matrix _b)
{
    matrix res(_a.size(), std::vector<long long>(_b[0].size()));
    for (long long i = 0; i < (long long)_a.size(); i++)
        for (long long j = 0; j < (long long)_b[0].size(); j++)
            for (long long k = 0; k < (long long)_b.size(); k++)
                (res[i][j] += _a[i][k] * _b[k][j] % MOD) %= MOD;
    return res;
}
matrix &operator*=(matrix &_a, const matrix _b) { return _a = _a * _b; }
void set_1(matrix &_a)
{
    for (long long i = 0; i < (long long)_a.size(); i++)
        for (long long j = 0; j < (long long)_a[0].size(); j++)
            _a[i][j] = i == j;
}
matrix operator+(const matrix _a, const matrix _b)
{
    matrix res(_a.size(), std::vector<long long>(_a[0].size()));
    for (long long i = 0; i < (long long)_a.size(); i++)
        for (long long j = 0; j < (long long)_a[0].size(); j++)
            res[i][j] = (_a[i][j] + _b[i][j]) % MOD;
    return res;
}
matrix &operator+=(matrix &_a, const matrix _b) {
    return _a = _a + _b; 
}
matrix power(matrix a, long long b)
{
    matrix res = a;
    for (set_1(res); b; a *= a, b >>= 1)
        if (b & 1)
            res *= a;
    return res;
}

int main()
{
    matrix m = {{0, 0}, {0, 0}};
}