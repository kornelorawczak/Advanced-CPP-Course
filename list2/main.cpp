#include <iostream>
#include <vector>
#include <cstdint>
#include <cmath>
#include <limits>
#include <cstring>
using namespace std;



//vector<int64_t> euklides_primes(int64_t n) {
//    vector<int64_t> nums(static_cast<int64_t>(sqrt(n))+1, 1); //initializing vector with possible prime numbers
//    //vector<int64_t> nums(n+1, 1);
//    vector<int64_t> primes;
//    nums[0]=nums[1]=0; //numbers 0 and 1 can't be primes
//    for (int i=2; i<nums.size(); i++)
//    {
//        if (nums[i]==1)
//        {
//            primes.push_back(i);
//            for (int j=i*i; j<nums.size(); j+=i)
//            {
//                nums[j]=0;
//            }
//        }
//    }
//    return primes;
//}

vector<int64_t> factorization(int64_t n){
    vector<int64_t> factors;
//    vector<int64_t> primes = euklides_primes(n);
//    for (const auto& x : primes)
//    {
//        if (n==1) return factors; // in some cases it can shorten the call stack
//        while (n%x == 0)
//        {
//            factors.push_back(x);
//            n/=x;
//        }
//    }
    if (n<0)
    {
        factors.push_back(-1);
        n=n*(-1);
    }
    for (int64_t i=2; i<static_cast<int64_t>(sqrt(n))+1; i++)
    {
        if (n==1) return factors;
        while (n%i==0)
        {
            factors.push_back(i);
            n/=i;
        }
    }
    if (n!=1) factors.push_back(n);
    return factors;
}

void returnal(int64_t n)
{
    vector<int64_t> vec = factorization(n);
    if (vec.size()==1)
    {
        cout<<n<<" is prime number!"<<endl;
        return;
    }
    cout<<n<<" = ";
    for (int i=0; i<vec.size()-1; i++)
    {
        cout<<vec[i]<<"*";
    }
    cout<<vec[vec.size()-1]<<endl;
}

int main(int argc, const char* argv[]) {
    if (argc==1)
    {
        cerr << "No arguments were given! You shall pass arguments separated by a space when running a.exe"<<endl;
        return -1;
    }
    for (int i=1; i<argc; i++) {
        try
        {
            size_t index;
            if (strcmp(argv[i], "9223372036854775808")==0 || strcmp(argv[i], "-9223372036854775808")==0)
            { // for some reason out_of_range exception doesn't only catch these two numbers even though they don't fit into int64_t
                cerr << "Inputted argument " << argv[i] << " is out of bounds of type int64_t!"<<endl;
                continue;
            }
            int64_t arg = stoll(argv[i], &index);
            if (argv[i][index]!='\0')
            {
                cerr << "Error! Argument " << argv[i] << " is not an int64_t number!"<<endl;
                continue;
            }
            returnal(arg);
        }
        catch (const invalid_argument &e)
        {
            cerr << "Argument " << argv[i] <<" is not valid for the factorization! It should be a number type int64_t!"<<endl;
        }
        catch (const out_of_range &e)
        {
            cerr << "Inputted argument " << argv[i] << " is out of bounds of type int64_t!"<<endl;
        }
    }
    return 0;
}
