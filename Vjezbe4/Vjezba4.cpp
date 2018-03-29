#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <map>
#include <set>
#include <cassert>
#include <string>
#include <functional>   // std::greater

using namespace std;

int main(){
    set<int> c{3, 5, 1, 7, 3};

    for(auto x : c)
        cout << x << ", ";
    cout << endl;

    multiset<int> a{3, 5, 1, 7, 3};
    set<int> b(a.begin(), a.end());

    cout << a.count(3) << endl;

    auto it = b.find(5);
    if(it == b.end())
        cout << "Element nije nadjen.\n";
    cout << "b\n";

    for(auto x : b)
        cout << x << ", ";
    cout << endl;

    auto it_l = a.lower_bound(3); // 3 <= *it_l  // ako ne postoji vraca iterator na end
    auto it_u = a.upper_bound(3); // 3 < *it_u   // ako nema vraca iterator na end

    //assert (it_eq.first == it_l); // nije definirano sto je it_eq
    //assert (it_eq.second == it_u);

    cout << "lower-upper\n";
    copy(it_l, it_u, ostream_iterator<int>(cout, ", "));

    pair<double, int> pp;
    pp.first = 1.0;
    pp.second = 9;

    a.insert(7);
    cout << "a\n";

    auto ms_it = a.insert(7); // povratna vrijednost iterator
    auto s_it = b.insert(7); // povratna vrijednost je par iterator i bool
                            //jer je to insertiranje u set
    cout << *ms_it << endl;
    cout << *s_it.first << " " << s_it.second << endl;

    a.erase(3); //vraca broj izbrisanih elemenata

    set<int, greater<int>> e(a.begin(), a.end()); // ako zelimo da su sortirani silazno
    for(auto x : e)
        cout << x << ", ";
    cout << endl;

    // std::pair<T,U>
    // a eq b !(a < b) AND !(b < a) a == b // OPREZ! ovo vrijedi samo ako je relacija ekvivalencije

    map<string, int> d{ {"c",4}, {"a",7}, {"b",8}}; // elementi sortirani po kljucu; map ne pamti duplikate kao ni set
    // multimap i multiset podrzavaju duplikate
    for(auto x : d)
        cout << x.first << " = " << x.second << endl;

    d.find("c"); // vraca iterator, trazenje ide uvijek po kljucu

    auto ret = d.find("c");
    if(ret != d.end());
        // NE cout << *ret << endl; jer map ima parove
        cout << ret->second << endl;

    d.insert(pair<string,int> ("e",0));
    for(auto x : d)
        cout << x.first << " = " << x.second << endl;
    //ili
    auto iit = d.insert(make_pair("e",0));
    cout << iit.first->second << endl; // treba ispisati vrijednost 0

    // brisanje po kljucu, a ne po paru

    //map je asocijativno polje
    //OPREZ!!! map dodaje novu vrijednost ako ta vrijednost nije vec u mapu
    d["d"] = 3;
    d["d"] = 300;


    return 0;
}
