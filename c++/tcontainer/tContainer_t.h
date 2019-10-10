#include <vector>
#include <list>
#include "isEqual_t.h"
#include <iostream>
#include <algorithm>
using namespace std;

#ifndef H_TCON
#define H_TCON


template <class T, class C >
class tContainer_t{
	public:
		virtual ~tContainer_t();
		tContainer_t(){}	
		bool isEmpty() const{return m_c.empty();}
		size_t numOfElements() const{return m_c.size();}
		void insertElement(T* element){m_c.push_back(element);}
		T* getFirst() const{return m_c.front();}	
		T* getLast() const{return m_c.back();}
		T* findByVal(const T& val) const;
		T* removeByVal(const T& val);
		void deleteByVal(const T& val);
		void removeAll(){m_c.clear();}
		void deleteAll();
		T* operator[](size_t index);
	private:
		tContainer_t(const tContainer_t& ct);
		tContainer_t& operator=(const tContainer_t& ct);
		C m_c;
		typedef typename C::iterator iter_t;
		typedef typename C::const_iterator citer_t;	
		void static deleteElement(T* element);
};

template <class T, class C> void tContainer_t<T, C>::deleteElement(T* element) {
	delete element;
}

template <class T, class C>  T* tContainer_t<T, C>::findByVal(const T& val) const{
	citer_t cit = find_if(m_c.begin(),m_c.end(), isEqual<T>(val));
	if (cit != m_c.end()){
		T* ret = *cit;
		return ret;
	}
	else{
		return 0;
	}
}

template <class T, class C>  T* tContainer_t<T, C>::removeByVal(const T& val){
	iter_t it = find_if(m_c.begin(), m_c.end(), isEqual<T>(val));
	if (it != m_c.end()){
		T* ret = *it;
		m_c.erase(it);	
		return ret;
	}
	else return 0;
}

template <class T, class C>  void tContainer_t<T, C>::deleteByVal(const T& val){
	iter_t it = find_if(m_c.begin(), m_c.end(), isEqual<T>(val));
	if (it != m_c.end()){
		T* ret = *it;
		m_c.erase(it);	
		delete ret;
	}
}

template <class T, class C> void tContainer_t<T, C>::deleteAll(){
	for_each(m_c.begin(), m_c.end(), deleteElement);
	m_c.clear();
	return;
}

template <class T, class C> T* tContainer_t<T, C>::operator[](size_t index){
	if (typeid(C*) == typeid(vector<T*>*)) {
		vector<T*> vec {begin(m_c), end(m_c)};
			return vec[index];	
	}
	else if(typeid(C*) == typeid(list<T*>*)) {
		int i;
		citer_t cit = m_c.begin();
		for (i = 0; i<index; i ++){
			cit++;
		}
		return *cit;
	}
}

template <class T, class C> tContainer_t<T, C>::~tContainer_t(){
	while (!m_c.empty()){
    	m_c.pop_back();
	}
}


#endif




























