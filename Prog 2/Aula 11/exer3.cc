#include <iostream>


template <typename T, typename U>


class Pair
{
public:
    Pair(const T &t, const U &u)
        : first(t), second(u){}
    T &get_first() { return first; }
    U &get_second() { return second; }
    const T &get_first() const { return first; }
    const U &get_second() const { return second; }
    void print_pair(){std::cout << "Os pares sao: " << get_first() << " e "<< get_second()<<std::endl;}
    void add_pairs(){auto add = get_first()+get_second(); std::cout << "add_pairs: "<<add<<std::endl;}

private:
    T first;
    U second;
};

int main()
{

    std::string a = "gato", b = "cachorro";
    std::cout << "a = " << a << " b = " << b << std::endl;
    Pair <std::string, std::string> p1(a,b);
    p1.print_pair();
    p1.add_pairs();
}