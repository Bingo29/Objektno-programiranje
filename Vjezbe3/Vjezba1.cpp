#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <fstream>

using namespace std;

template <typename T>

void print(T const &t){
    for (auto const &x : t)
        cout << x << ", ";
    cout << endl;
}

int main(){
    vector<int> a{5, 7, 3, 1, 5, 9};
    print(a);

    auto it = remove(a.begin(), a.end(), 5);
    print(a);
    a.erase(it, a.end());
    print(a);

    list<int> li(a.size());

    //INSERT ITERATORI

    // *it = ... ---> it->push_back(...)
    // back_inserter
    copy(a.begin(), a.end(), back_inserter(li));
    print(li);

    //front_inserter
    // *it = ... ---> i->push_front(...)
    copy(a.begin(), a.end(), front_inserter(li));
    print(li);

    auto it3 = find(li.begin(), li.end(), 3);
    if (it3 == li.end())
        throw runtime_error("Element 3 nije nadjen.");
    //inserter *it = ... --> li.insert(it3,...)
    copy(a.begin(), a.end(), inserter(li, it3));
    print(li);


    // IOSTREAM ITERATORI
    ifstream in("1.txt");
    if(!in)
        throw runtime_error("File ne postoji.");

    istream_iterator<int> isi(in);
    istream_iterator<int> isi_end;

    vector<int> aisi(isi, isi_end);
    print(aisi);

    ostream_iterator<float> osi(cout, "\n");
    copy(li.begin(), li.end(), osi);

    return 0;
}
