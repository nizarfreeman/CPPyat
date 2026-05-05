#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>

using namespace std;

template <typename T, typename Container = deque<T> > 
class ExposedStack : public std::stack<T, Container>
{
    public: // This function gives us access to the protected member 'c'
        const Container& get_container() const { return this->c; }
        typedef Container con_type_; 
};

int main(void)
{
    ExposedStack<int> st;
    st.push(5);
    st.push(6);
    st.push(8);

    const ExposedStack<int>::con_type_ &k = st.get_container();
    cout<<k[0]<<" "<<k[1]<<" "<<k[2]<<endl;
    return (0);
}