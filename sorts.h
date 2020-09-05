/*
 * sorts.h
 *
 *  Created on: 03/03/2019
 *      Author: Luis Jesus Morales Juarez
 */

#ifndef SORTS_H_
#define SORTS_H_

#include "../includes/exception.h"
#include <vector>
#include <list>

template <class T>
class sorts {
private:
	void swap(std::vector<T>&, int, int);
	
public:
	std::vector<T> bucket_sort(const std::vector<T>&);
	std::list<T>   merge_list(const std::list<T>&, const std::list<T>&);
};

template <class T>
void sorts<T>::swap(std::vector<T> &v, int i, int j) {
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

template <class T>
std::vector<T> sorts<T>::bucket_sort(const std::vector<T> &source) {
typename  std::list<T>::iterator itr;
	std::vector<T> v(source);
	
	int temp = v.size()/2;

	while(temp>0){
        for(int i = temp; i <v.size(); i++){
            for(int j = i; j >= temp && v[j] < v[j-temp]; j-=temp){
                swap(v,j,j-temp);
            }
        }
        temp = temp/2;
	}
	return v;
}

template <class T>
std::list<T> sorts<T>::merge_list(const std::list<T> &lst1, const std::list<T> &lst2) {
typename std::list<T>::const_iterator itr1, itr2;
	std::list<T> result;
	
	std::list<T> List1(lst1), List2(lst2);
	
	
	while(!List1.empty() && !List2.empty()){
		
		if(List1.front() < List2.front()){
			result.push_back(List1.front());
			List1.pop_front();
		}
		
		else{
			
			result.push_back(List2.front());
			List2.pop_front();
		}
		
	}
	
	if(!List1.empty())
	{
		for(itr1 = List1.begin(); itr1 != List1.end(); itr1++){
			result.push_back(*itr1);
		}
	}
	
	if(!List2.empty()){
		for(itr2 = List2.begin(); itr2 != List2.end(); itr2++){
			result.push_back(*itr2);
		}
	}
	
	return result;
}


#endif /* SORTS_H_ */