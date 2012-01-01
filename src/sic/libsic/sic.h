/*
 * =====================================================================================
 *
 *       Filename:  sicmain.h
 *
 *    Description:  Main 
 *
 *        Version:  1.0
 *        Created:  2011年12月29日 21时40分48秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Karata Lau (kl), vabc3h@gmail.com
 *        Company:  ZJU
 *
 * =====================================================================================
 */
#ifndef SIC_H
#define SIC_H

#define PACKAGENAME	"sic"
#define SICVERSION "0.1"

#define STRMLEN 125

/*-----------------------------------------------------------------------------
 * item struct definition 
 *-----------------------------------------------------------------------------*/
typedef struct sic_dbitem_s{
	char imagefile[STRMLEN];        //image path
	char featurefile[STRMLEN];      //feature file path
	char description[STRMLEN];      //description
} sic_dbitem;


typedef struct sic_item_s{
	sic_dbitem *dbitem;
	float appo;
} sic_item;

extern void sic_getver(char *st);
extern int sic_init();
extern int sic_end();
extern int sic_cleardb();
extern int sic_status(sic_dbitem **its,int *n);
extern int sic_insert(const char *imgfile,const char *desc);
extern int sic_autoadd(char *dir);
extern int sic_matchlist(char *imgfile,char *key,sic_item**,int*);
extern void sic_debug();
#endif
