/*
 * =====================================================================================
 *
 *       Filename:  sicdbdao.h
 *
 *    Description:  Headfile for db access method
 *
 *        Version:  1.0
 *        Created:  2011年12月27日 20时05分43秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Karata Lau (kl), vabc3h@gmail.com
 *        Company:  ZJU
 *
 * =====================================================================================
 */

#ifndef SICDBDAO_H
#define SICDBDAO_H

#include "sicdb.h"

struct sic_dbdao_s{
	sic_dbitem* (*query)(int id);
};

typedef struct sic_dbdao_s sic_dbdao;

extern sic_dbdao* sic_dbdao_init();


#endif
