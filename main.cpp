/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:09:37 by tnaton            #+#    #+#             */
/*   Updated: 2022/12/12 18:02:15 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <typeinfo>
#include <sys/time.h>
#include <limits>
#include <list>
#include <iomanip>
#include "include.hpp"

#ifndef NAMESPACE
# define NAMESPACE std
#endif

#ifndef PREC
# define PREC 1
#endif

#ifndef TEST
# define TEST 0
#endif

#define MAXSIZE (((std::size_t)std::numeric_limits<int>::max() / sizeof(int))/4)

#define ROUND(x) ((x - 1 < 0)? 1 : (int)x)

class	Clock {
	public:
		Clock(void) {gettimeofday(&_time, NULL);};
		long time(void) {struct timeval now; gettimeofday(&now, NULL); return (((now.tv_sec - _time.tv_sec)*1000) + ((now.tv_usec - _time.tv_usec)/1000));}
		void p(void) {long tmp = time(); std::cout << tmp/1000 << "." << std::setfill('0') << std::setw(3) << tmp%1000 << "s ";}
	private:
		struct timeval _time;
};

template <typename T>
void printVector(const NAMESPACE::vector<T> & v) {
	typedef typename NAMESPACE::vector<T>::const_iterator			citerator;
	typedef typename NAMESPACE::vector<T>::const_reverse_iterator	criterator;
	std::cout << "VECTOR = ";
	for (citerator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << "|";
	}
	std::cout << std::endl;
	std::cout << "REVERSE VECTOR = ";
	for (criterator it = v.rbegin(); it != v.rend(); it++) {
		std::cout << *it << "|";
	}
	std::cout << std::endl;
	std::cout << "SIZE:" << v.size() << std::endl;
	std::cout << "CAPACITY:" << v.capacity() << std::endl;
	std::cout << "IS EMPTY:" << v.empty() << std::endl;
	std::cout << "MAX SIZE:" << v.max_size() << std::endl;
}

template <typename T, typename U>
void printMap(const NAMESPACE::map<T, U> & m) {
	typedef typename NAMESPACE::map<T, U>::const_iterator			citerator;
	typedef typename NAMESPACE::map<T, U>::const_reverse_iterator	criterator;
	std::cout << "MAP = ";
	for (citerator it = m.begin(); it != m.end(); it++) {
		std::cout << it->first << "&" << it->second << "|";
	}
	std::cout << std::endl;
	std::cout << "REVERSE MAP = ";
	for (criterator it = m.rbegin(); it != m.rend(); it++) {
		std::cout << it->first << "&" << it->second << "|";
	}
	std::cout << "SIZE:" << m.size() << std::endl;
	std::cout << "IS EMPTY:" << m.empty() << std::endl;
}

template <typename T>
void printSet(const NAMESPACE::set<T> & s) {
	typedef typename NAMESPACE::set<T>::const_iterator			citerator;
	typedef typename NAMESPACE::set<T>::const_reverse_iterator	criterator;
	std::cout << "SET = ";
	for (citerator it = s.begin(); it != s.end(); it++) {
		std::cout << *it << "|";
	}
	std::cout << std::endl;
	std::cout << "REVERSE SET = ";
	for (criterator it = s.rbegin(); it != s.rend(); it++) {
		std::cout << *it << "|";
	}
	std::cout << "SIZE:" << s.size() << std::endl;
	std::cout << "IS EMPTY:" << s.empty() << std::endl;
}

int main (void) {
	volatile int x = 0;
	switch (TEST) {
		case (0):{}
		case (1):{
			std::cerr << "=-=-=-=-=-=-=-VECTOR-=-=-=-=-=-=-=" << std::endl;
			{
				std::cerr << "### TEST CONSTRUCTOR VECTOR ###" << std::endl;
				std::cerr << std::endl;
				{
					Clock test;
					for (int i = 0; i < 1 * PREC; i++) {
						NAMESPACE::vector<int> v1(MAXSIZE, 1);
						std::cerr << (i+1)/(0.01 * PREC) << "." << (i+1)%(ROUND(0.01 * PREC)) << "%   " << '\r';
						if (v1[0] == 42)
							x = x + 42;
					}
					test.p();
					std::cout << "vector value constructor" << std::endl;
				}
				std::cerr << std::endl;
				{
					NAMESPACE::vector<int> vec(MAXSIZE, 42);
					Clock test;
					for (int i = 0; i < 1 * PREC; i++) {
						NAMESPACE::vector<int> v1(vec.begin(), vec.end());
						std::cerr << (i+1)/(0.01 * PREC) << "." << (i+1)%(ROUND(0.01 * PREC)) << "%   " << '\r';
						std::cout.clear();
						if (v1[0] == 42)
							x = x + 42;
					}
					test.p();
					std::cout << "vector iterator constructor" << std::endl;
				}
				std::cerr << std::endl;
				{
					Clock test;

					NAMESPACE::vector<int> v1(MAXSIZE, 21);
					NAMESPACE::vector<NAMESPACE::vector<int> >v2 (1, v1);
					NAMESPACE::vector<NAMESPACE::vector<NAMESPACE::vector<int> > > v3(1, v2);
					for (int i = 0; i < 1 * PREC; i++) {
						NAMESPACE::vector<NAMESPACE::vector<NAMESPACE::vector<int> > > vector1(v3);

						std::cerr << (i+1)/(0.01 * PREC) << "." << (i+1)%(ROUND(0.01 * PREC)) << "%   " << '\r';
						std::cout.clear();
						if (v1[0] == 42)
							x = x + 42;
					}
					test.p();
					std::cout << "vector copy constructor" << std::endl;
				}
				std::cerr << std::endl;
			}
			{
				std::cerr << "### TEST OPERATOR= ###" << std::endl;
				std::cerr << std::endl;
				{
					Clock test;

					NAMESPACE::vector<int> v1(MAXSIZE, 24);
					NAMESPACE::vector<int> v2;
					for (int i = 0; i < 1 * PREC; i++) {
						v2 = v1;
						v1 = v2;
						std::cerr << (i+1)/(0.01 * PREC) << "." << (i+1)%(ROUND(0.01 * PREC)) << "%   " << '\r';
						if (v1[0] == 42)
							x = x + 42;
					}
					test.p();
					std::cout << "vector operator =" << std::endl;
				}
				std::cerr << std::endl;
			}
			{
				std::cerr << "### TEST ASSIGN ###" << std::endl;
				std::cerr << std::endl;
				{
					Clock test;

					NAMESPACE::vector<int> v;
					for (int i = 0; i < 1 * PREC; i++) {
						v.assign(MAXSIZE, 42);
						std::cerr << (i+1)/(0.01 * PREC) << "." << (i+1)%(ROUND(0.01 * PREC)) << "%   " << '\r';
						if (v[0] == 42)
							x = x + 42;
					}
					test.p();
					std::cout << "vector assign value" << std::endl;
				}
				std::cerr << std::endl;
				{
					Clock test;

					NAMESPACE::vector<int> v(MAXSIZE, 2147483647);
					NAMESPACE::vector<int> v2;
					for (int i = 0; i < 1 * PREC; i++) {
						v2.assign(v.begin(), v.end());
						std::cerr << (i+1)/(0.01 * PREC) << "." << (i+1)%(ROUND(0.01 * PREC)) << "%   " << '\r';
						if (v2[0] == 42)
							x = x + 42;
					}
					test.p();
					std::cout << "vector assign iterator" << std::endl;
				}
				std::cerr << std::endl;
				{
					Clock test;

					int	lst[1000000];
					for (int i = 0; i < 1000000; i++)
						lst[i] = 42;
					NAMESPACE::vector<int> v;
					for (int i = 0; i < 1 * PREC; i++) {
						v.assign(lst, lst + 1000000);
						std::cerr << (i+1)/(0.01 * PREC) << "." << (i+1)%(ROUND(0.01 * PREC)) << "%   " << '\r';
						if (v[0] == 42)
							x = x + 42;
					}
					test.p();
					std::cout << "vector assign BidirectionalIterator" << std::endl;
				}
				std::cerr << std::endl;
			}
			{
				std::cerr << "### TEST RESERVE ###" << std::endl;
				std::cerr << std::endl;
				{
					Clock test;

					for (int i = 0; i < 1 * PREC; i++) {
						NAMESPACE::vector<int> v(MAXSIZE, 42);
						v.reserve(MAXSIZE);
						std::cerr << (i+1)/(0.01 * PREC) << "." << (i+1)%(ROUND(0.01 * PREC)) << "%   " << '\r';
						if (v[0] == 42)
							x = x + 42;
					}
					test.p();
					std::cout << "vector reserve capacity" << std::endl;
				}
				std::cerr << std::endl;
			}
			{
				std::cerr << "### TEST CLEAR ###" << std::endl;
				std::cerr << std::endl;
				{
					Clock test;

					for (int i = 0; i < 1 * PREC; i++) {
						NAMESPACE::vector<int> v(MAXSIZE, 42);
						v.clear();
						std::cerr << (i+1)/(0.01 * PREC) << "." << (i+1)%(ROUND(0.01 * PREC)) << "%   " << '\r';
						if (v[0] == 42)
							x = x + 42;
					}
					test.p();
					std::cout << "vector create clear" << std::endl;
				}
				std::cerr << std::endl;
			}
			{
				std::cerr << "### TEST INSERT ###" << std::endl;
				std::cerr << std::endl;
				{
					Clock test;

					for (int i = 0; i < 1 * PREC; i++) {
						NAMESPACE::vector<int> v(MAXSIZE, 42);
						v.insert(v.begin() + MAXSIZE/2, 41);
						std::cerr << (i+1)/(0.01 * PREC) << "." << (i+1)%(ROUND(0.01 * PREC)) << "%   " << '\r';
						if (v[0] == 42)
							x = x + 42;
					}
					test.p();
					std::cout << "vector insert val" << std::endl;
				}
				std::cerr << std::endl;
				{
					Clock test;

					for (int i = 0; i < 1 * PREC; i++) {
						NAMESPACE::vector<int> v(1000, 42);
						v.insert(v.begin(), MAXSIZE/4, 21);
						std::cerr << (i+1)/(0.01 * PREC) << "." << (i+1)%(ROUND(0.01 * PREC)) << "%   " << '\r';
						if (v[0] == 42)
							x = x + 42;
					}
					test.p();
					std::cout << "vector insert count" << std::endl;
				}
				std::cerr << std::endl;
				{
					Clock test;

					NAMESPACE::vector<int> v2(MAXSIZE, 42);
					for (int i = 0; i < 1 * PREC; i++) {
						NAMESPACE::vector<int> v(1000, 42);
						v.insert(v.begin() + 500, v2.begin(), v2.end());
						std::cerr << (i+1)/(0.01 * PREC) << "." << (i+1)%(ROUND(0.01 * PREC)) << "%   " << '\r';
						if (v[0] == 42)
							x = x + 42;
					}
					test.p();
					std::cout << "vector insert iterator" << std::endl;
				}
				std::cerr << std::endl;
				{
					Clock test;

					std::list<int> v2(MAXSIZE/40, 42);
					for (int i = 0; i < 1 * PREC; i++) {
						NAMESPACE::vector<int> v(1000, 42);
						v.insert(v.begin() + 500, v2.begin(), v2.end());
						std::cerr << (i+1)/(0.01 * PREC) << "." << (i+1)%(ROUND(0.01 * PREC)) << "%   " << '\r';
						if (v[0] == 42)
							x = x + 42;
					}
					test.p();
					std::cout << "vector insert InputIterator" << std::endl;
				}
				std::cerr << std::endl;
			}
			{
				std::cerr << "### TEST ERASE ###" << std::endl;
				std::cerr << std::endl;
				{
					Clock test;

					for (int i = 0; i < 1 * PREC; i++) {
						NAMESPACE::vector<int> v(10000, 42);
						while (v.size()) {
							v.erase(v.begin());
						}
						std::cerr << (i+1)/(0.01 * PREC) << "." << (i+1)%(ROUND(0.01 * PREC)) << "%   " << '\r';
						if (v[0] == 42)
							x = x + 42;
					}
					test.p();
					std::cout << "vector erase value" << std::endl;
				}
				std::cerr << std::endl;
				{
					Clock test;

					for (int i = 0; i < 1 * PREC; i++) {
						NAMESPACE::vector<int> v(1000000, 42);
						while (v.size()) {
							if (v.size() > 1000) {
								v.erase(v.begin(), v.begin() + 1000);
							} else {
								v.erase(v.begin());
							}
						}
						std::cerr << (i+1)/(0.01 * PREC) << "." << (i+1)%(ROUND(0.01 * PREC)) << "%   " << '\r';
						if (v[0] == 42)
							x = x + 42;
					}
					test.p();
					std::cout << "vector erase range" << std::endl;
				}
				std::cerr << std::endl;
			}
			{
				std::cerr << "### TEST PUSH_BACK ###" << std::endl;
				std::cerr << std::endl;
				{
					Clock test;

					for (int i = 0; i < 1 * PREC; i++) {
						NAMESPACE::vector<int> v;
						while (v.size() < 10000000) {
							v.push_back(42);
						}
						std::cerr << (i+1)/(0.01 * PREC) << "." << (i+1)%(ROUND(0.01 * PREC)) << "%   " << '\r';
						if (v[0] == 42)
							x = x + 42;
					}
					test.p();
					std::cout << "vector push_back value" << std::endl;
				}
				std::cerr << std::endl;
			}
			{
				std::cerr << "### TEST POP_BACK ###" << std::endl;
				std::cerr << std::endl;
				{
					Clock test;

					for (int i = 0; i < 1 * PREC; i++) {
						NAMESPACE::vector<int> v(MAXSIZE, 42);
						while (v.size()) {
							v.pop_back();
						}
						std::cerr << (i+1)/(0.01 * PREC) << "." << (i+1)%(ROUND(0.01 * PREC)) << "%   " << '\r';
						if (v[0] == 42)
							x = x + 42;
					}
					test.p();
					std::cout << "vector pop_back value" << std::endl;
				}
				std::cerr << std::endl;
			}
			{
				std::cerr << "### TEST RESIZE ###" << std::endl;
				std::cerr << std::endl;
				{
					Clock test;

					for (int i = 0; i < 1 * PREC; i++) {
						NAMESPACE::vector<int> v;
						v.resize(MAXSIZE);
						v.resize(MAXSIZE/100);
						std::cerr << (i+1)/(0.01 * PREC) << "." << (i+1)%(ROUND(0.01 * PREC)) << "%   " << '\r';
						if (v[0] == 42)
							x = x + 42;
					}
					test.p();
					std::cout << "vector resize range" << std::endl;
				}
				std::cerr << std::endl;
			}
			if (TEST)
				break;
		}
		case (2):{
			std::cerr << "=-=-=-=-=-=-=-MAP-=-=-=-=-=-=-=" << std::endl;
			{
				std::cerr << "### TEST CONSTRUCTOR MAP ###" << std::endl;
				std::cerr << std::endl;
				{
					NAMESPACE::map<int, int> m;
					for (int i = 0; i < 10000; i++) {
						m.insert(NAMESPACE::make_pair(i, 42));
					}
					Clock test;
					for (int i = 0; i < 1 * PREC; i++) {
						NAMESPACE::map<int, int> t(m.begin(), m.end());
						std::cerr << (i+1)/(0.01 * PREC) << "." << (i+1)%ROUND(0.01 * PREC) << "%   " << '\r';
						std::cout.clear();
						if (m[0] == 42)
							x = x + 42;
					}
					test.p();
					std::cout << "map iterator constructor" << std::endl;
				}
				std::cerr << std::endl;
				{
					NAMESPACE::map<int, int> m;
					for (int i = 0; i < 10000; i++) {
						m.insert(NAMESPACE::make_pair(i, 42));
					}
					Clock test;
					for (int i = 0; i < 1 * PREC; i++) {
						NAMESPACE::map<int, int> t(m);
						std::cerr << (i+1)/(0.01 * PREC) << "." << (i+1)%ROUND(0.01 * PREC) << "%   " << '\r';
						std::cout.clear();
						if (m[0] == 42)
							x = x + 42;
					}
					test.p();
					std::cout << "map copy constructor" << std::endl;
				}
				std::cerr << std::endl;
			}
			{
				std::cerr << "### TEST OPERATOR= ###" << std::endl;
				std::cerr << std::endl;
				{
					NAMESPACE::map<int, int> m;
					for (int i = 0; i < 10000; i++) {
						m.insert(NAMESPACE::make_pair(i, 42));
					}
					NAMESPACE::map<int, int> t;
					Clock test;
					for (int i = 0; i < 1 * PREC; i++) {
						t = m;
						m = t;
						std::cerr << (i+1)/(0.01 * PREC) << "." << (i+1)%ROUND(0.01 * PREC) << "%   " << '\r';
						std::cout.clear();
						if (m[0] == 42)
							x = x + 42;
					}
					test.p();
					std::cout << "map operator =" << std::endl;
				}
				std::cerr << std::endl;
			}
			{
				std::cerr << "### TEST ACCESS ###" << std::endl;
				std::cerr << std::endl;
				{
					NAMESPACE::map<int, int> m;
					for (int i = 0; i < 10000; i++) {
						m.insert(NAMESPACE::make_pair(i, 42));
					}
					Clock test;
					for (int i = 0; i < 100 * PREC; i++) {
						for (int j = 0; j < 10000; j++) {
							m.at(j);
						}
						std::cerr << (i+1)/(1 * PREC) << "." << (i+1)%(1 * PREC) << "%   " << '\r';
						std::cout.clear();
						if (m[0] == 42)
							x = x + 42;
					}
					test.p();
					std::cout << "map access at" << std::endl;
				}
				std::cerr << std::endl;
				{
					NAMESPACE::map<int, int> m;
					Clock test;
					for (int i = 0; i < 100 * PREC; i++) {
						for (int j = 0; j < 10000; j++) {
							m[j];
						}
						std::cerr << (i+1)/(1 * PREC) << "." << (i+1)%(1 * PREC) << "%   " << '\r';
						std::cout.clear();
						if (m[0] == 42)
							x = x + 42;
					}
					test.p();
					std::cout << "map access operator[]" << std::endl;
				}
				std::cerr << std::endl;
				{
					NAMESPACE::map<int, int> m;
					for (int i = 0; i < 10000; i++) {
						m[i];
					}
					Clock test;
					for (int i = 0; i < 100 * PREC; i++) {
						for (int j = 0; j < 10000; j++) {
							m.find(j);
						}
						std::cerr << (i+1)/(1 * PREC) << "." << (i+1)%(1 * PREC) << "%   " << '\r';
						std::cout.clear();
						if (m[0] == 42)
							x = x + 42;
					}
					test.p();
					std::cout << "map access find" << std::endl;
				}
				std::cerr << std::endl;
			}
			{
				std::cerr << "### TEST INSERT ###" << std::endl;
				std::cerr << std::endl;
				{
					Clock test;
					for (int i = 0; i < 100 * PREC; i++) {
						NAMESPACE::map<int, int> m;
						for (int j = 0; j < 10000; j++) {
							m.insert(NAMESPACE::make_pair(j, 42));
						}
						std::cerr << (i+1)/(1 * PREC) << "." << (i+1)%(1 * PREC) << "%   " << '\r';
						std::cout.clear();
						if (m[0] == 42)
							x = x + 42;
					}
					test.p();
					std::cout << "map insert val" << std::endl;
				}
				std::cerr << std::endl;
				{
					NAMESPACE::map<int, int> m;
					for (int i = 0; i < 10000; i++) {
						m[i];
					}
					Clock test;
					for (int i = 0; i < 100 * PREC; i++) {
						NAMESPACE::map<int, int> t;
						t.insert(m.begin(), m.end());
						std::cerr << (i+1)/(1 * PREC) << "." << (i+1)%(1 * PREC) << "%   " << '\r';
						std::cout.clear();
						if (m[0] == 42)
							x = x + 42;
					}
					test.p();
					std::cout << "map insert iterator" << std::endl;
				}
				std::cerr << std::endl;
			}
			{
				std::cerr << "### TEST REMOVE ###" << std::endl;
				std::cerr << std::endl;
				{
					Clock test;
					for (int i = 0; i < 100 * PREC; i++) {
						NAMESPACE::map<int, int> m;
						for (int j = 0; j < 10000; j++) {
							m[j];
						}
						for (int j = 0; j < 10000; j++) {
							m.erase(j);
						}
						std::cerr << (i+1)/(1 * PREC) << "." << (i+1)%(1 * PREC) << "%   " << '\r';
						std::cout.clear();
						if (m[0] == 42)
							x = x + 42;
					}
					test.p();
					std::cout << "map erase value" << std::endl;
				}
				std::cerr << std::endl;
				{
					Clock test;
					for (int i = 0; i < 100 * PREC; i++) {
						NAMESPACE::map<int, int> m;
						for (int j = 0; j < 10000; j++) {
							m[j];
						}
						m.erase(m.begin(), m.end());
						std::cerr << (i+1)/(1 * PREC) << "." << (i+1)%(1 * PREC) << "%   " << '\r';
						std::cout.clear();
						if (m[0] == 42)
							x = x + 42;
					}
					test.p();
					std::cout << "map erase range" << std::endl;
				}
				std::cerr << std::endl;
				{
					Clock test;
					for (int i = 0; i < 100 * PREC; i++) {
						NAMESPACE::map<int, int> m;
						for (int j = 0; j < 10000; j++) {
							m[j];
						}
						for (int j = 0; j < 10000; j++) {
							m.erase(m.begin());
						}
						std::cerr << (i+1)/(1 * PREC) << "." << (i+1)%(1 * PREC) << "%   " << '\r';
						std::cout.clear();
						if (m[0] == 42)
							x = x + 42;
					}
					test.p();
					std::cout << "map erase iterator" << std::endl;
				}
				std::cerr << std::endl;
				{
					Clock test;
					for (int i = 0; i < 100 * PREC; i++) {
						NAMESPACE::map<int, int> m;
						for (int j = 0; j < 10000; j++) {
							m[j];
						}
						m.clear();
						std::cerr << (i+1)/(1 * PREC) << "." << (i+1)%(1 * PREC) << "%   " << '\r';
						std::cout.clear();
						if (m[0] == 42)
							x = x + 42;
					}
					test.p();
					std::cout << "map clear all" << std::endl;
				}
				std::cerr << std::endl;
			}
			if (TEST)
				break;
		}
		case (3):{
			std::cerr << "=-=-=-=-=-=-=-SET-=-=-=-=-=-=-=" << std::endl;
			{
				std::cerr << std::endl;
				{
					NAMESPACE::set<int> m;
					for (int i = 0; i < 10000; i++) {
						m.insert(i);
					}
					Clock test;
					for (int i = 0; i < 1 * PREC; i++) {
						NAMESPACE::set<int> t(m.begin(), m.end());
						std::cerr << (i+1)/(0.01 * PREC) << "." << (i+1)%ROUND(0.01 * PREC) << "%   " << '\r';
						std::cout.clear();
					}
					test.p();
					std::cout << "set iterator constructor" << std::endl;
				}
				std::cerr << std::endl;
				{
					NAMESPACE::set<int> m;
					for (int i = 0; i < 10000; i++) {
						m.insert(i);
					}
					Clock test;
					for (int i = 0; i < 1 * PREC; i++) {
						NAMESPACE::set<int> t(m);
						std::cerr << (i+1)/(0.01 * PREC) << "." << (i+1)%ROUND(0.01 * PREC) << "%   " << '\r';
						std::cout.clear();
					}
					test.p();
					std::cout << "set copy constructor" << std::endl;
				}
				std::cerr << std::endl;
			}
			{
				std::cerr << "### TEST OPERATOR= ###" << std::endl;
				std::cerr << std::endl;
				{
					NAMESPACE::set<int> m;
					for (int i = 0; i < 10000; i++) {
						m.insert(i);
					}
					NAMESPACE::set<int> t;
					Clock test;
					for (int i = 0; i < 1 * PREC; i++) {
						t = m;
						m = t;
						std::cerr << (i+1)/(0.01 * PREC) << "." << (i+1)%ROUND(0.01 * PREC) << "%   " << '\r';
						std::cout.clear();
					}
					test.p();
					std::cout << "set operator =" << std::endl;
				}
				std::cerr << std::endl;
			}
			{
				std::cerr << "### TEST INSERT ###" << std::endl;
				std::cerr << std::endl;
				{
					Clock test;
					for (int i = 0; i < 100 * PREC; i++) {
						NAMESPACE::set<int> m;
						for (int j = 0; j < 10000; j++) {
							m.insert(j);
						}
						std::cerr << (i+1)/(1 * PREC) << "." << (i+1)%(1 * PREC) << "%   " << '\r';
						std::cout.clear();
					}
					test.p();
					std::cout << "set insert val" << std::endl;
				}
				std::cerr << std::endl;
				{
					NAMESPACE::set<int> m;
					for (int i = 0; i < 10000; i++) {
						m.insert(i);
					}
					Clock test;
					for (int i = 0; i < 100 * PREC; i++) {
						NAMESPACE::set<int> t;
						t.insert(m.begin(), m.end());
						std::cerr << (i+1)/(1 * PREC) << "." << (i+1)%ROUND(1 * PREC) << "%   " << '\r';
						std::cout.clear();
					}
					test.p();
					std::cout << "set insert iterator" << std::endl;
				}
				std::cerr << std::endl;
			}
			{
				std::cerr << "### TEST REMOVE ###" << std::endl;
				std::cerr << std::endl;
				{
					Clock test;
					for (int i = 0; i < 100 * PREC; i++) {
						NAMESPACE::set<int> m;
						for (int j = 0; j < 10000; j++) {
							m.insert(j);
						}
						for (int j = 0; j < 10000; j++) {
							m.erase(j);
						}
						std::cerr << (i+1)/(1 * PREC) << "." << (i+1)%(1 * PREC) << "%   " << '\r';
						std::cout.clear();
					}
					test.p();
					std::cout << "set erase value" << std::endl;
				}
				std::cerr << std::endl;
				{
					Clock test;
					for (int i = 0; i < 100 * PREC; i++) {
						NAMESPACE::set<int> m;
						for (int j = 0; j < 10000; j++) {
							m.insert(j);
						}
						m.erase(m.begin(), m.end());
						std::cerr << (i+1)/(1 * PREC) << "." << (i+1)%(1 * PREC) << "%   " << '\r';
						std::cout.clear();
					}
					test.p();
					std::cout << "set erase range" << std::endl;
				}
				std::cerr << std::endl;
				{
					Clock test;
					for (int i = 0; i < 100 * PREC; i++) {
						NAMESPACE::set<int> m;
						for (int j = 0; j < 10000; j++) {
							m.insert(j);
						}
						for (int j = 0; j < 10000; j++) {
							m.erase(m.begin());
						}
						std::cerr << (i+1)/(1 * PREC) << "." << (i+1)%(1 * PREC) << "%   " << '\r';
						std::cout.clear();
					}
					test.p();
					std::cout << "set erase iterator" << std::endl;
				}
				std::cerr << std::endl;
				{
					Clock test;
					for (int i = 0; i < 100 * PREC; i++) {
						NAMESPACE::set<int> m;
						for (int j = 0; j < 10000; j++) {
							m.insert(j);
						}
						m.clear();
						std::cerr << (i+1)/(1 * PREC) << "." << (i+1)%(1 * PREC) << "%   " << '\r';
						std::cout.clear();
					}
					test.p();
					std::cout << "set clear all" << std::endl;
				}
				std::cerr << std::endl;
			}
			if (TEST)
				break;
		}
	}
	switch (TEST) {
		std::cout << "//////////////////////////////////////////////////////////////////////////" << std::endl;
		std::cout << "                           TEST OF OUTPUT FOR DIFF                        " << std::endl;
		std::cout << "//////////////////////////////////////////////////////////////////////////" << std::endl;
		case (0):{
			std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-STACK-=-=-=-=-=-=-=-=-=-=-=-=-=" << std::endl;
			{
				NAMESPACE::stack<int>	s;
				
				std::cout << "IS EMPTY:" << s.empty() << std::endl;
				std::cout << "SIZE:" << s.size() << std::endl;
				s.push(42);
				s.push(42);
				s.push(42);
				std::cout << "IS EMPTY:" << s.empty() << std::endl;
				std::cout << "SIZE:" << s.size() << std::endl;
				std::cout << "TOP:" << s.top() << std::endl;
				s.pop();
				std::cout << "IS EMPTY:" << s.empty() << std::endl;
				std::cout << "SIZE:" << s.size() << std::endl;
				std::cout << "TOP:" << s.top() << std::endl;
				s.pop();
				s.pop();
				std::cout << "IS EMPTY:" << s.empty() << std::endl;
				std::cout << "SIZE:" << s.size() << std::endl;
			}
		}
		case (1):{
			std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-VECTOR-=-=-=-=-=-=-=-=-=-=-=-=-=" << std::endl;
			{
				int lst[42];
				for (int i = 0; i < 42; i++) {
					lst[i] = (i + 42)%5;
				}
				NAMESPACE::vector<int>	v(lst, lst + 12);
				printVector(v);
				NAMESPACE::vector<int> other;
				printVector(other);
				other = v;
				printVector(other);
				v.assign(lst + 5, lst + 7);
				printVector(v);
				v.assign(lst, lst + 40);
				printVector(v);
				std::cout << "AT POS 2" << v.at(2) << std::endl;
				std::cout << "[] POS 10" << v[10] << std::endl;
				std::cout << "FRONT" << v.front() << std::endl;
				std::cout << "BACK" << v.back() << std::endl;
				std::cout << "DATA" << *(v.data() + 5) << std::endl;
				v.reserve(100);
				printVector(v);
				v.clear();
				printVector(v);
				v.insert(v.begin(), 42, 42);
				printVector(v);
				v.insert(v.begin() + 20, 9);
				printVector(v);
				v.erase(v.begin() + 9, v.end() - 2);
				printVector(v);
				v.push_back(1);
				printVector(v);
				v.pop_back();
				printVector(v);
				v.resize(30);
				printVector(v);
				NAMESPACE::swap(v, other);
				printVector(v);
				printVector(other);
				std::cout << (v == other) << std::endl;
				std::cout << (v != other) << std::endl;
				std::cout << (v <= other) << std::endl;
				std::cout << (v >= other) << std::endl;
				std::cout << (v > other) << std::endl;
				std::cout << (v < other) << std::endl;
			}
			if (TEST)
				break;
		}
		case (2):{
			std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-MAP-=-=-=-=-=-=-=-=-=-=-=-=-=" << std::endl;
			{
				NAMESPACE::pair<int, int> lst[420];
				for (int i = 0; i < 420; i++) {
					lst[i] = NAMESPACE::make_pair(((i + 42)%210), 0);
				}
				NAMESPACE::map<int, int>	m(lst, lst + 30);
				printMap(m);
				NAMESPACE::map<int, int>	other;
				printMap(other);
				other = m;
				printMap(other);
				std::cout << "AT POS 2" << m.at(42) << std::endl;
				std::cout << "[] POS 10" << m[10] << std::endl;
				printMap(m);
				m.clear();
				printMap(m);
				for (NAMESPACE::map<int, int>::iterator it = other.begin(); it != other.end(); it++) {
					NAMESPACE::pair<NAMESPACE::map<int, int>::iterator, bool> ret = m.insert(NAMESPACE::make_pair<int, int>(((it->first) + 10)%90, (it->second) + 0));
					std::cout << ret.second;
				}
				std::cout << std::endl;
				printMap(m);
				m.insert(m.begin(), NAMESPACE::make_pair<int, int>(10, 10));
				printMap(m);
				m.erase(m.begin());
				printMap(m);
				m.erase(m.begin());
				printMap(m);
				printMap(other);
				NAMESPACE::swap(m, other);
				printMap(m);
				printMap(other);
				for (int i = 0; i < 500; i++) {
					std::cout << m.count(i%250 + 1);
					if (m.count(i)) {
						std::cout << std::endl << m.find(i)->second << std::endl;
					}
				}
				printMap(m);
				NAMESPACE::pair<NAMESPACE::map<int, int>::iterator, NAMESPACE::map<int, int>::iterator> ret = m.equal_range(42);
				std::cout << ret.first->first << "&" << ret.first->second << "|" << ret.second->first << "&" << ret.second->second << std::endl;
				std::cout << (m == other) << std::endl;
				std::cout << (m != other) << std::endl;
				std::cout << (m <= other) << std::endl;
				std::cout << (m >= other) << std::endl;
				std::cout << (m > other) << std::endl;
				std::cout << (m < other) << std::endl;
			}
			if (TEST)
				break;
		}
		case (3):{
			std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-SET-=-=-=-=-=-=-=-=-=-=-=-=-=" << std::endl;
			{
				int lst[420];
				for (int i = 0; i < 420; i++) {
					lst[i] = (i + 42)%210;
				}
				NAMESPACE::set<int>	s(lst, lst + 30);
				printSet(s);
				NAMESPACE::set<int>	other;
				printSet(other);
				other = s;
				printSet(other);
				printSet(s);
				s.clear();
				printSet(s);
				for (NAMESPACE::set<int>::iterator it = other.begin(); it != other.end(); it++) {
					NAMESPACE::pair<NAMESPACE::set<int>::iterator, bool> ret = s.insert((*it + 10)%90);
					std::cout << ret.second;
				}
				std::cout << std::endl;
				printSet(s);
				s.insert(s.begin(), 10);
				printSet(s);
				s.erase(s.begin());
				printSet(s);
				s.erase(s.begin());
				printSet(s);
				printSet(other);
				NAMESPACE::swap(s, other);
				printSet(s);
				printSet(other);
				for (int i = 0; i < 500; i++) {
					std::cout << s.count(i%250 + 1);
					if (s.count(i)) {
						std::cout << std::endl << *s.find(i) << std::endl;
					}
				}
				printSet(s);
				NAMESPACE::pair<NAMESPACE::set<int>::iterator, NAMESPACE::set<int>::iterator> ret = s.equal_range(42);
				std::cout << *ret.first << "|" << *ret.second << std::endl;
				std::cout << (s == other) << std::endl;
				std::cout << (s != other) << std::endl;
				std::cout << (s <= other) << std::endl;
				std::cout << (s >= other) << std::endl;
				std::cout << (s > other) << std::endl;
				std::cout << (s < other) << std::endl;
			}
			if (TEST)
				break;
		}
	}
}
