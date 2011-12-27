/*
 * =====================================================================================
 *
 *       Filename:  sicdbdao.c
 *
 *    Description:  Impl
 *
 *        Version:  1.0
 *        Created:  2011年12月27日 20时44分24秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Karata Lau (kl), vabc3h@gmail.com
 *        Company:  ZJU
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "sicdbdao.h"

//sic_dbdao dbdao;

static sic_dbitem* q1(int id);

sic_dbdao* sic_dbdao_init()
{
	printf("init called\n");
	sic_dbdao* dbdao = (sic_dbdao*)malloc(sizeof(sic_dbdao));
	dbdao->query=q1;
	return dbdao;
}

sic_dbitem* q1(int id)
{
	printf("Fake q1\n");
	return NULL;
}



void bmg(){
}
