#include <iostream>
#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
    int n,x,y;
    freopen("Piece.in","r",stdin);
    freopen("Piece.out","w",stdout);
    for (int i = 0; i < 21; ++i)
    {
        cin>>n;  scanf()
        printf("//Block %d \nBlockArray[%d].len = %d;\n",i+1,i+1,n);
        for (int j = 0; j < n; ++j)
        {
            cin>>x>>y;
            printf("BlockArray[%d].list[%d][0] =%d; \nBlockArray[%d].list[%d][1] =%d; \n", i+1,j,x,i+1,j,y);
        }

    }
    return 0;
}