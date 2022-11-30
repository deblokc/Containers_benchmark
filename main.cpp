/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:09:37 by tnaton            #+#    #+#             */
/*   Updated: 2022/11/30 12:04:10 by tnaton           ###   ########.fr       */
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

int main () {
	switch (TEST) {
		case (0):{}
		case (1):{
			std::cerr << "=-=-=-=-=-=-=-VECTOR-=-=-=-=-=-=-=" << std::endl;
			{
				std::cerr << "### TEST CONSTRUCTOR VECTOR ###" << std::endl;
				std::cerr << std::endl;
				{
					Clock test;
					for (int i = 0; i < 100000 * PREC; i++) {
						for (int j = 0; j < 50000; j++)
							NAMESPACE::vector<std::string> v;
						std::cerr << (i+1)/(1000 * PREC) << "." << (i+1)%(1000 * PREC) << "%   " << '\r';
						std::cout.clear();
					}
					test.p();
					std::cout << "vector default constructor" << std::endl;
				}
				std::cerr << std::endl;
				{
					Clock test;
					for (int i = 0; i < 1 * PREC; i++) {
						NAMESPACE::vector<int> v1(MAXSIZE, 1);
						std::cerr << (i+1)/(0.01 * PREC) << "." << (i+1)%(ROUND(0.01 * PREC)) << "%   " << '\r';
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
					Clock test;
					for (int i = 0; i < 100000 * PREC; i++) {
						for (int j = 0; j < 1000; j++) {
							NAMESPACE::map<std::string, std::string> v;
						}
						std::cerr << (i+1)/(1000 * PREC) << "." << (i+1)%(1000 * PREC) << "%   " << '\r';
						std::cout.clear();
					}
					test.p();
					std::cout << "map default constructor" << std::endl;
				}
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
				std::cerr << "### TEST CONSTRUCTOR SET ###" << std::endl;
				std::cerr << std::endl;
				{
					Clock test;
					for (int i = 0; i < 100000 * PREC; i++) {
						for (int j = 0; j < 1000; j++) {
							NAMESPACE::set<std::string> v;
						}
						std::cerr << (i+1)/(1000 * PREC) << "." << (i+1)%(1000 * PREC) << "%   " << '\r';
						std::cout.clear();
					}
					test.p();
					std::cout << "set default constructor" << std::endl;
				}
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
}
