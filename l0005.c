
const char* extend(int *len,const char *s,int i,int j){
    int offset = 0;
    char *l = s + i;
    char *r = s + j;
    if( *l == *r ){
        for( ; offset < i ; l--,r++,offset ++ ){
            if( l[-1] != r[1] )
                break;
        }
    }

    if( l == r || *l != *r){
        *len = 0;
        return NULL;
    }

    *len = r - l +1;
    return l;
}


char * longestPalindrome(char * s){
    int size = strlen(s);
    int mid = size/2;
    int maxlen = 0;
    char *maxstr=NULL;
    if( size == 0 )
        return NULL;

    for( int i = 0; i <= mid ; i ++ ){
        int len[4] = {0,0,0,0};
        char* start[4];
         start[0]=extend(&len[0],s,mid -i,mid -i);
         start[1]=extend(&len[1],s,mid -i,mid -i+1);
         if( i != 0 && mid +i < size ){
            start[2]=extend(&len[2],s,mid +i,mid +i);
            if( mid +i +1 < size )
                start[3]=extend(&len[3],s,mid +i,mid +i+1);
         }

        for( int j = 0; j < 4 ; j ++){
            if( len[j] > maxlen ){
                maxlen = len[j];
                maxstr = start[j];
            }
        }
    }

    if( maxlen == 0 ){
        maxlen = 1;
        maxstr=s;
    }
      maxstr[maxlen]=0;
      return maxstr;
}
