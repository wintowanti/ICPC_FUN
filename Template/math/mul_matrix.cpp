int ** new_matrix(int n){
    int ** p1;
    p1=new int *[n];
    for(int i=0;i<n;i++){
        p1[i]=new int [n];
        for(int j=0;j<n;j++) p1[i][j]=0;
    }
    return p1;
}
int **mul(int **p1,int **p2,int n,int m1,int com){
    for(int i=0;i<n;i++){
        for(int j=0;j<m1;j++){
            int tsum=0;
            for(int k=0;k<com;k++){
                tsum+=mul_1(p1[i][k],p2[k][j]);
                tsum=tsum%m;
            }
            tmp[i][j]=tsum;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m1;j++){
            p1[i][j]=tmp[i][j];
        }
    }
    return p1;
}
int ** pow(int **p1,int n,int time){
    int **ans=new_matrix(M);
    for(int i=0;i<n;i++)ans[i][i]=1;
    int **tmp1=p1;
    int i=1;
    while(i<=time){
        if(time&i){
            ans=mul(ans,tmp1,n,n,n);
        }
        tmp1=mul(tmp1,tmp1,n,n,n);
        i=i<<1;
    }
    return ans;
}
