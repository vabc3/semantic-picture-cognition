/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Main sicd
 *
 *        Version:  1.0
 *        Created:  2012年01月01日 19时49分01秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Karata Lau (kl), vabc3h@gmail.com
 *        Company:  ZJU
 *
 * =====================================================================================
 */

#include <iostream>
#include <sic.h>
using namespace std;

int main()
{
	char af[255];
	sic_getver(af);
	cout<<af<<endl;
}
