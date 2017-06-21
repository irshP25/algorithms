/*Author: Pooja Srivastava
Numbers are taken as string and multiplied directly using boost C++ libraries for large numbers*/
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
int main()
{
    mp::cpp_int s1("3141592653589793238462643383279502884197169399375105820974944592");
    mp::cpp_int s2("2718281828459045235360287471352662497757247093699959574966967627");
    mp::cpp_int S=s1*s2;
    std::cout << S << '\n';
}
