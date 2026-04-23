#include <iostream>
#include "Circle.hpp"
#include "List.hpp"
#include <utility>
#include <fstream>


int main(){
    List list;
    list.push_back(Circle(0,0,1));
    list.push_back(Circle(0,0,4));
    list.push_back(Circle(0,0,2));
    list.push_back(Circle(0,0,3));
    list.push_back(Circle(0,0,0.5));
    list.push_back(Circle(0,0,0.7));
    list.print();
    list.sort();
    list.print();

/*     list = list.sorted();
    list.print();
    for(List::Iterator it = list.begin(); it != list.end(); ++it){
        std::cout<<(*it).get_area()<<std::endl;
    }
    std::cout<<std::endl; */
/*     {
	std::cout<<"Enter Output File Name  - " ;
	char ar[80];
	std::cin>>ar;
	std::ofstream fout(ar);
	fout<<list;
	fout.close();
    } */

/*     {
        List list_in;
        std::cout<<"Enter Input File Name  - " ;
        char ar[80];
        std::cin>>ar;
        std::ifstream fin(ar);
        fin>>list_in;
        fin.close();
        list_in.print();
    } */

    return 0;
}