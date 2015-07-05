#include "stdio.h"

const int BLOCKNUM=21,PLAYERNUM=4,MAXOPERATION=200,MAPLENGTH=21;
int dx[8]={0,1,0,-1,1,1,-1,-1},dy[8]={1,0,-1,0,1,-1,1,-1};

int PlayerDie[4],PlayerUse[4],BlockUse[5][22];
int Map[MAPLENGTH+1][MAPLENGTH+1];

struct Block{
    int len;
    int list[5][2];
    int l,v,d;
} BlockArray[BLOCKNUM+1];

struct Operation{
    int ID, x, y, block_id , l , v , d;
} OperationArray[MAXOPERATION];

int  OperationNum;

int BlockInit(){
    //Block 1 
    BlockArray[1].len = 1;
    BlockArray[1].list[0][0] =0; 
    BlockArray[1].list[0][1] =0; 
    //Block 2 
    BlockArray[2].len = 2;
    BlockArray[2].list[0][0] =0; 
    BlockArray[2].list[0][1] =0; 
    BlockArray[2].list[1][0] =0; 
    BlockArray[2].list[1][1] =1; 
    //Block 3 
    BlockArray[3].len = 3;
    BlockArray[3].list[0][0] =0; 
    BlockArray[3].list[0][1] =0; 
    BlockArray[3].list[1][0] =0; 
    BlockArray[3].list[1][1] =1; 
    BlockArray[3].list[2][0] =1; 
    BlockArray[3].list[2][1] =1; 
    //Block 4 
    BlockArray[4].len = 3;
    BlockArray[4].list[0][0] =0; 
    BlockArray[4].list[0][1] =0; 
    BlockArray[4].list[1][0] =0; 
    BlockArray[4].list[1][1] =1; 
    BlockArray[4].list[2][0] =0; 
    BlockArray[4].list[2][1] =2; 
    //Block 5 
    BlockArray[5].len = 4;
    BlockArray[5].list[0][0] =0; 
    BlockArray[5].list[0][1] =0; 
    BlockArray[5].list[1][0] =0; 
    BlockArray[5].list[1][1] =1; 
    BlockArray[5].list[2][0] =1; 
    BlockArray[5].list[2][1] =0; 
    BlockArray[5].list[3][0] =1; 
    BlockArray[5].list[3][1] =1; 
    //Block 6 
    BlockArray[6].len = 4;
    BlockArray[6].list[0][0] =0; 
    BlockArray[6].list[0][1] =0; 
    BlockArray[6].list[1][0] =1; 
    BlockArray[6].list[1][1] =0; 
    BlockArray[6].list[2][0] =1; 
    BlockArray[6].list[2][1] =1; 
    BlockArray[6].list[3][0] =1; 
    BlockArray[6].list[3][1] =-1; 
    //Block 7 
    BlockArray[7].len = 4;
    BlockArray[7].list[0][0] =0; 
    BlockArray[7].list[0][1] =0; 
    BlockArray[7].list[1][0] =0; 
    BlockArray[7].list[1][1] =1; 
    BlockArray[7].list[2][0] =0; 
    BlockArray[7].list[2][1] =2; 
    BlockArray[7].list[3][0] =0; 
    BlockArray[7].list[3][1] =3; 
    //Block 8 
    BlockArray[8].len = 4;
    BlockArray[8].list[0][0] =0; 
    BlockArray[8].list[0][1] =0; 
    BlockArray[8].list[1][0] =1; 
    BlockArray[8].list[1][1] =0; 
    BlockArray[8].list[2][0] =1; 
    BlockArray[8].list[2][1] =-1; 
    BlockArray[8].list[3][0] =1; 
    BlockArray[8].list[3][1] =-2; 
    //Block 9 
    BlockArray[9].len = 4;
    BlockArray[9].list[0][0] =0; 
    BlockArray[9].list[0][1] =0; 
    BlockArray[9].list[1][0] =0; 
    BlockArray[9].list[1][1] =1; 
    BlockArray[9].list[2][0] =1; 
    BlockArray[9].list[2][1] =0; 
    BlockArray[9].list[3][0] =1; 
    BlockArray[9].list[3][1] =-1; 
    //Block 10 
    BlockArray[10].len = 5;
    BlockArray[10].list[0][0] =0; 
    BlockArray[10].list[0][1] =0; 
    BlockArray[10].list[1][0] =1; 
    BlockArray[10].list[1][1] =0; 
    BlockArray[10].list[2][0] =1; 
    BlockArray[10].list[2][1] =1; 
    BlockArray[10].list[3][0] =1; 
    BlockArray[10].list[3][1] =2; 
    BlockArray[10].list[4][0] =1; 
    BlockArray[10].list[4][1] =3; 
    //Block 11 
    BlockArray[11].len = 5;
    BlockArray[11].list[0][0] =0; 
    BlockArray[11].list[0][1] =0; 
    BlockArray[11].list[1][0] =1; 
    BlockArray[11].list[1][1] =0; 
    BlockArray[11].list[2][0] =2; 
    BlockArray[11].list[2][1] =0; 
    BlockArray[11].list[3][0] =2; 
    BlockArray[11].list[3][1] =1; 
    BlockArray[11].list[4][0] =2; 
    BlockArray[11].list[4][1] =-1; 
    //Block 12 
    BlockArray[12].len = 5;
    BlockArray[12].list[0][0] =0; 
    BlockArray[12].list[0][1] =0; 
    BlockArray[12].list[1][0] =1; 
    BlockArray[12].list[1][1] =0; 
    BlockArray[12].list[2][0] =2; 
    BlockArray[12].list[2][1] =0; 
    BlockArray[12].list[3][0] =2; 
    BlockArray[12].list[3][1] =1; 
    BlockArray[12].list[4][0] =2; 
    BlockArray[12].list[4][1] =2; 
    //Block 13 
    BlockArray[13].len = 5;
    BlockArray[13].list[0][0] =0; 
    BlockArray[13].list[0][1] =0; 
    BlockArray[13].list[1][0] =0; 
    BlockArray[13].list[1][1] =1; 
    BlockArray[13].list[2][0] =0; 
    BlockArray[13].list[2][1] =2; 
    BlockArray[13].list[3][0] =1; 
    BlockArray[13].list[3][1] =0; 
    BlockArray[13].list[4][0] =1; 
    BlockArray[13].list[4][1] =-1; 
    //Block 14 
    BlockArray[14].len = 5;
    BlockArray[14].list[0][0] =0; 
    BlockArray[14].list[0][1] =0; 
    BlockArray[14].list[1][0] =1; 
    BlockArray[14].list[1][1] =0; 
    BlockArray[14].list[2][0] =1; 
    BlockArray[14].list[2][1] =-1; 
    BlockArray[14].list[3][0] =1; 
    BlockArray[14].list[3][1] =-2; 
    BlockArray[14].list[4][0] =2; 
    BlockArray[14].list[4][1] =-2; 
    //Block 15 
    BlockArray[15].len = 5;
    BlockArray[15].list[0][0] =0; 
    BlockArray[15].list[0][1] =0; 
    BlockArray[15].list[1][0] =1; 
    BlockArray[15].list[1][1] =0; 
    BlockArray[15].list[2][0] =2; 
    BlockArray[15].list[2][1] =0; 
    BlockArray[15].list[3][0] =3; 
    BlockArray[15].list[3][1] =0; 
    BlockArray[15].list[4][0] =4; 
    BlockArray[15].list[4][1] =0; 
    //Block 16 
    BlockArray[16].len = 5;
    BlockArray[16].list[0][0] =0; 
    BlockArray[16].list[0][1] =0; 
    BlockArray[16].list[1][0] =1; 
    BlockArray[16].list[1][1] =0; 
    BlockArray[16].list[2][0] =1; 
    BlockArray[16].list[2][1] =1; 
    BlockArray[16].list[3][0] =2; 
    BlockArray[16].list[3][1] =0; 
    BlockArray[16].list[4][0] =2; 
    BlockArray[16].list[4][1] =1; 
    //Block 17 
    BlockArray[17].len = 5;
    BlockArray[17].list[0][0] =0; 
    BlockArray[17].list[0][1] =0; 
    BlockArray[17].list[1][0] =0; 
    BlockArray[17].list[1][1] =1; 
    BlockArray[17].list[2][0] =1; 
    BlockArray[17].list[2][1] =0; 
    BlockArray[17].list[3][0] =1; 
    BlockArray[17].list[3][1] =-1; 
    BlockArray[17].list[4][0] =2; 
    BlockArray[17].list[4][1] =-1; 
    //Block 18 
    BlockArray[18].len = 5;
    BlockArray[18].list[0][0] =0; 
    BlockArray[18].list[0][1] =0; 
    BlockArray[18].list[1][0] =0; 
    BlockArray[18].list[1][1] =1; 
    BlockArray[18].list[2][0] =1; 
    BlockArray[18].list[2][1] =0; 
    BlockArray[18].list[3][0] =2; 
    BlockArray[18].list[3][1] =0; 
    BlockArray[18].list[4][0] =2; 
    BlockArray[18].list[4][1] =1; 
    //Block 19 
    BlockArray[19].len = 5;
    BlockArray[19].list[0][0] =0; 
    BlockArray[19].list[0][1] =0; 
    BlockArray[19].list[1][0] =0; 
    BlockArray[19].list[1][1] =1; 
    BlockArray[19].list[2][0] =1; 
    BlockArray[19].list[2][1] =0; 
    BlockArray[19].list[3][0] =1; 
    BlockArray[19].list[3][1] =-1; 
    BlockArray[19].list[4][0] =2; 
    BlockArray[19].list[4][1] =0; 
    //Block 20 
    BlockArray[20].len = 5;
    BlockArray[20].list[0][0] =0; 
    BlockArray[20].list[0][1] =0; 
    BlockArray[20].list[1][0] =1; 
    BlockArray[20].list[1][1] =0; 
    BlockArray[20].list[2][0] =1; 
    BlockArray[20].list[2][1] =1; 
    BlockArray[20].list[3][0] =1; 
    BlockArray[20].list[3][1] =-1; 
    BlockArray[20].list[4][0] =2; 
    BlockArray[20].list[4][1] =0; 
    //Block 21 
    BlockArray[21].len = 5;
    BlockArray[21].list[0][0] =0; 
    BlockArray[21].list[0][1] =0; 
    BlockArray[21].list[1][0] =1; 
    BlockArray[21].list[1][1] =0; 
    BlockArray[21].list[2][0] =1; 
    BlockArray[21].list[2][1] =-1; 
    BlockArray[21].list[3][0] =1; 
    BlockArray[21].list[3][1] =1; 
    BlockArray[21].list[4][0] =1; 
    BlockArray[21].list[4][1] =2; 

    for(int i = 0; i < 22; i++) BlockArray[i].l = BlockArray[i].v = BlockArray[i].d = 0;
    return 0;
}

int init(){
    for(int i = 1 ;i <= 4; ++i) PlayerDie[i] = 0; 

    for (int i = 1; i <= PLAYERNUM; ++i)
        for (int j = 1; j <= BLOCKNUM; ++j){
            BlockUse[i][j] = 0;
    }
    BlockInit();

    OperationNum=0;
    OperationArray[0].ID=0;
    OperationArray[0].x=0;
    OperationArray[0].y=0;
    OperationArray[0].block_id=0;
    OperationArray[0].l=0;
    OperationArray[0].v=0;
    OperationArray[0].d=0;

    for (int i = 1; i < MAPLENGTH; ++i)
        for (int j = 1; j < MAPLENGTH; ++j){
            Map[i][j]=0;
        }
}
Operation getOPR(){
    Operation opr;
    scanf("%d%d%d%d%d%d%d",&opr.ID, &opr.x, &opr.y, &opr.block_id , &opr.l , &opr.v , &opr.d);
    return opr;
}

int flipl(Block &b){
    for (int i = 0; i < b.len; ++i){
        b.list[i][0] = -b.list[i][0];
    }
    return 0;
}
int flipv(Block &b){
    for (int i = 0; i < b.len; ++i){
        b.list[i][1] = -b.list[i][1];
    }
}
int flipd(Block &b,int x){
    for(int j = 0; j < x; j++)
        for (int i = 0; i < b.len; ++i){
            b.list[i][0] = b.list[i][1];
            b.list[i][1] = -b.list[i][0];
        }
}
int update(Operation opr){
    Block b;
    if (opr.block_id == 0) PlayerDie[opr.ID] = 1;
    if (PlayerDie[opr.ID] ) return 0;

    b = BlockArray[opr.block_id];
    if (opr.l == 1) flipl(b);
    if (opr.v == 1) flipv(b);
    if(opr.d !=0) flipd(b,opr.d);

    for (int i = 0; i < b.len; ++i){
        //printf("%d %d \n",opr.x+b.list[i][0] , opr.y+b.list[i][1]);
        Map[opr.x+b.list[i][0]][opr.y+b.list[i][1]] = 0;        
    }
}

int judge(Operation opr){
    Block b = BlockArray[opr.block_id];
    int p=0,x,y;

    if (opr.l) flipl(b);
    if (opr.v) flipv(b);
    if (opr.d) flipd(b,opr.d);

    for (int i = 0; i < b.len; ++i){
        x=opr.x+b.list[i][0];
        y=opr.y+b.list[i][1];
        if(x<1||x>20||y<1||y>20) return false;
        if (Map[x][y] != 0) return false;
        for (int j = 0; j < 4; j++) if (Map[x+dx[j]][y+dy[j]] == opr.ID) return false;
        for (int j = 0; j < 8; j++) if (Map[x+dx[j]][y+dy[j]] == opr.ID) p = 1;
    }
    if (p) return true; else return false;
}
Operation move(int PlayerID){
    Operation opr,oprs[1000];
    Block b;
    int oprN=0;

    opr.ID = PlayerID;

    if (PlayerDie[PlayerID] ) {
        opr.x=opr.y=opr.block_id=opr.l=opr.v=opr.d=0;
        return opr;
    }

    for (int i = 1; i < MAPLENGTH; ++i)  
        for (int j = 0; j < MAPLENGTH; ++j)  if (Map[i][j] == 0) 
            for (int bk = 1; bk < BLOCKNUM; ++bk)
                for (int lk = 0; lk < 2; ++lk)
                    for (int vk = 0; vk < 2; ++vk)
                        for (int dk = 0; dk < 4; ++dk){
                            opr.x = i; opr.y = j; opr.block_id = bk; opr.l = lk; opr.v = vk; opr.d = dk;
                            if(judge(opr)) oprs[oprN++]=opr;
                        }
    //random;                        
}

int putOPR(Operation opr){

    printf("%d %d %d %d %d %d %d\n", opr.ID , opr.x , opr.y , opr.block_id , opr.l ,opr.v , opr.d);
}

int allDie(){
    for (int i = 0; i < 4; ++i){
        if(PlayerDie[i] == 0) return false;
    }
    return true;
}
int work(){
    Operation opr=getOPR();
    int ID_Now;
    if(opr.ID==0){
        ID_Now=1;
        PlayerUse[1]=1;
        Map[0][0]=1;
        PlayerUse[3]=1;
        Map[21][21]=3;
    }else{
        OperationNum++;
        OperationArray[OperationNum]=opr;
        update(opr);
        ID_Now=2;
        PlayerUse[2]=1;
        PlayerUse[4]=1;
    }

    while(1){
        OperationNum++;

        if(allDie()) break;

        if(PlayerUse[ID_Now]){
            opr = move(ID_Now);
            OperationArray[OperationNum] = opr;
            putOPR(opr);
        }else{
            opr = getOPR();
            OperationArray[OperationNum] =  opr;
        }
        if (opr.block_id!=0) update(opr); else PlayerDie[ID_Now]=1;

        if(++ID_Now==5) ID_Now=1;
    }
}
int main()
{
    init();
    work();    
    return 0;
}