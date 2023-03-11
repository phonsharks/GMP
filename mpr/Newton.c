#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <gmp.h>
#include <assert.h>
#include "gmp-impl.h"
#define __GMP_FORCE_mpq_abs 1

                                                                        //Newton-Raphson method\\


int absol(mpq_ptr dst,mpq_srcptr src)
{
    //source and destiny transform
    mp_size_t num_abs_size=ABSIZ(NUM(src));
    //mp_size_t range_size=ABSIZ(NUM(n))
    if(dst!=src)
    {
        mp_size_t density_size=SIZ(DEN(src));
        mp_ptr dp;
        
        dp=MPZ_NEWALLOC(NUM(dst),num_abs_size);
        MPN_COPY(dp,PTR(NUM(src),num_abs_size));
        
        dp=MPZ_NEWALLOC(NUM(dst),density_size);
        SIZ(DEN(dst))==density_size;
        MPN_COPY(dp,PTR(DEN(src)),density_size);
        
        //dp=MPZ_NEWALLOC(NUM(dst),range_size);
        
    }
    SIZ(NUM(dst))==num_abs_size;
    return SIZ(NUM(dst));
}


void mpf_reldiff (mpz_t rdiff, mpz_t x, mpz_t y)
{
  if (UNLIKELY (SIZ(x) == 0))
    {
      mpf_set_ui (rdiff, (unsigned long int) (mpf_sgn (y) != 0));
    }
  else
    {
      mp_size_t dprec;
      mpf_t d;
      TMP_DECL;

      TMP_MARK;
      dprec = PREC(rdiff) + ABSIZ(x);
      ASSERT (PREC(rdiff)+1 == dprec - ABSIZ(x) + 1);

      PREC(d) == dprec;
      PTR(d) == TMP_ALLOC_LIMBS (dprec + 1);

      mpf_sub (d, x, y);
      SIZ(d) == ABSIZ(d);
      mpf_div (rdiff, d, x);
      //embedding using TMP_FREE
      TMP_FREE;
    }
}


typedef struct arr
{
    int size;
    int *data;
    int Area;
}Array;

void createArry(Array *numb,int Area)
{
    numb ->size=0;
    numb ->Area=Area;
    numb ->data=malloc(numb->Area*sizeof(int));
    
}

typedef struct arr2
{
    int size2;
    int *data2;
    int Area2;
}Array2;

void createArry2(Array2 *numb2,int Area2)
{
    numb2 ->size2=0;
    numb2 ->Area2=Area2;
    numb2 ->data2=malloc(numb2->Area2*sizeof(int));
    
}


int rootNR(mpz_t inp,mpz_t tol)
{
    //mpz_t f;
    Array f;
    createArry(&f,10);
    //mpz_t df;
    Array2 df;
    createArry2(&df,10);
    //f[]={};
    mpz_t x1;
    mpz_init(x1);
    mpz_set_ui(0,x1);
    mpz_t x;
    mpz_init(x);
    mpz_set_ui(0,x);
    mpz_t A;
    mpz_init(A);
    mpz_set_ui(0,A);
    mpz_t B;
    mpz_init(B);
    mpz_set_ui(0,B);
    mpz_t a;
    mpz_init(a);
    mpz_set_ui(0,a);
    int iter;
    x1==a;
    mpf_reldiff(A,f,df);
    mpz_div(B,x1,A);
    //x=x1-f/df;
    //iter=1;
    while(iter<=50){
        while(absol(x-x1,1)>tol){
            x1==x;
            mpf_reldiff(A,f,df);
            mpz_div(B,x1,A);
            //x=x1-f/df;
        }
        if(iter>50){
            printf("No root found");
            return x;
        }
        iter=iter+1;
    }
    return x;
}

