#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//  | -> wstart --> wend --|
//       minptr + minlen
//       mmap + matchnum
//  1. right move wend to find a match, then resize it to min and save into minptr+minlen
//  2. left move wstart to make minptr lack one token
//  3. goto 1, continue move wend
struct mCtl{
    int slen;
    int tlen;
    int mnum;       // match char num

    int minlen;     // mini match length
    char *minptr;   // mini match start ptr
    char *wstart;   // curent window start ptr
    char *wend;     // curent window end ptr

    int tneed[128];  //  t: need difference character info
    int neednum;    //  need difference character num
    int mmap[128];  // flash windows's character info
    int matchnum;   // flash window's match character num
};

void saveit(struct mCtl *pctl){
    int minlen   = pctl->wend - pctl->wstart +1;
    if( pctl->minlen == 0 || minlen < pctl->minlen ){
        pctl->minptr = pctl->wstart;
        pctl->minlen = minlen;
    }
}

int moveright(struct mCtl *pctl){
    for( ; *pctl->wend !=0 ; pctl->wend ++ ) {
        char token = *pctl->wend;
        if( pctl->tneed[token] == 0 )
          continue;

        if( !pctl->wstart )
          pctl->wstart = pctl->wend;
        
        pctl->mmap[token] ++;
        if( pctl->mmap[token] == pctl->tneed[token] ){
            pctl->matchnum ++;
            if( pctl->matchnum == pctl->neednum ){
                /*  have find all match*/
                for( ;pctl->wstart < pctl->wend ; pctl->wstart ++){
                    char token = *pctl->wstart;
                    if( pctl->tneed[token] == 0 )
                        continue;
                    if( pctl->mmap[token] == pctl->tneed[token] )
                        break;
                    pctl->mmap[token] --;
                }
                saveit(pctl);
                pctl->wend   ++;
                return 1;
            }
        }
    }

    return 0;
}

int moveleft(struct mCtl *pctl){
    char *w = pctl->wstart;
    for( ; *pctl->wstart != 0 ; ){
        char token = *pctl->wstart;
        pctl->wstart ++ ;
        if( pctl->tneed[token] == 0 )
          continue;
        pctl->mmap[token] --;
        if( pctl->mmap[token] == pctl->tneed[token] ){
            saveit(pctl);
        }
        else if( pctl->mmap[token] < pctl->tneed[token] ){
            pctl->matchnum --;
            return 1;
        }
    }

    return 0;
}



char * minWindow(char * s, char * t){
    if( s == NULL || s[0] == 0 || t==NULL || t[0] == 0  )
        return "";

    int slen        = strlen(s);
    int tlen        = strlen(t);
    if( slen < tlen )
        return "";

    if( slen == tlen && !memcmp( s,t,slen) )
        return s;
    if( tlen == 1 )
        return strchr(s,t[0])? t: "";

    //  init ctl
    struct mCtl  mctl;
    memset(&mctl,0,sizeof(mctl));
    mctl.slen       = slen;
    mctl.tlen       = tlen;
    for( char *p = t; *p != 0; p ++ ){
        mctl.tneed[*p] ++;
        if( mctl.tneed[*p] == 1 )
          mctl.neednum ++;
    }

    mctl.wend = s;
    while( moveright(&mctl) && moveleft(&mctl) ){
    }
    if( !mctl.minptr ) return "";
    char *p = malloc(mctl.minlen+1);
    memcpy(p,mctl.minptr,mctl.minlen);
    p[mctl.minlen] = 0;
    //mctl.minptr[mctl.minlen] = 0;
    return p;
}

#define V(s,t,expect)  do{ char *m = strdup(s);char* ret = minWindow(m,t); \
  printf("%s to find %s\n",strcmp(expect,ret)? "fail": "success"); free(m);\
}while(0)

int main()
{
    V("abc","ab","ab");
    return 0;
}
