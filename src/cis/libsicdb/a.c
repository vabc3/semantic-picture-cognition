/*
 * =====================================================================================
 *
 *       Filename:  tdb.c
 *
 *    Description:  Test for db
 *
 *        Version:  1.0
 *        Created:  2011年12月27日 20时14分34秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Karata Lau (kl), vabc3h@gmail.com
 *        Company:  ZJU
 *
 * =====================================================================================
 */

#include <stdio.h>
#include "sicdbdao.h"

int main()
{	sic_dbdao *dbdao;
	bmg();
	dbdao=sic_dbdao_init();
	dbdao->query(3);
	printf("Fine\n");
	return 0;
}

