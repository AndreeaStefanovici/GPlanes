#include <iostream>
using namespace std;
char M[11][11], varf;
int p1, p2;
void initializareMatrice(char M[11][11])
{
    for(int i=1; i<=10; i++)
        for(int j=1; j<=10; j++)
            M[i][j]='0';

}
void varfDreapta(char M[11][11], int p1, int p2)
{
    M[p1][p2]='>';
    M[p1][p2-1]='|';
    M[p1][p2-2]='-';
    M[p1][p2-3]='|';
    M[p1-1][p2-1]='|';
    M[p1+1][p2-1]='|';
    M[p1-1][p2-3]='|';
    M[p1+1][p2-3]='|';

}
void varfStanga(char M[11][11], int p1, int p2)
{
    M[p1][p2]='<';
    M[p1][p2+1]='|';
    M[p1][p2+2]='-';
    M[p1][p2+3]='|';
    M[p1-1][p2+1]='|';
    M[p1+1][p2+1]='|';
    M[p1-1][p2+3]='|';
    M[p1+1][p2+3]='|';

}
bool VarfDreaptaLaMargine (char M[11][11], int p1, int p2)
{
    if((p2<4)||(p2>10)||(p1>9)||(p1<2))
        return true;
    return false;
}

bool VarfStangaLaMargine (char M[11][11], int p1, int p2)
{
    if ((p2>7)||(p1>9)||(p2<1)||(p1<2))
        return true;
    return false;
}
bool VerificaVarfLaMargine (char M[11][11], int p1, int p2, char varf)
{
    if ((varf=='>') && (M[p1][p2]=='0'))
        if (VarfDreaptaLaMargine(M, p1, p2)==false)
            return true;
    if ((varf=='<') && (M[p1][p2]=='0'))
        if (VarfStangaLaMargine(M, p1, p2)==false)
            return true;
    if ((varf=='A') && (M[p1][p2]=='0'))
        if (VarfSusLaMargine(M, p1, p2)==false)
            return true;
    if ((varf=='V') && (M[p1][p2]=='0'))
        if (VarfJosLaMargine(M, p1, p2)==false)
            return true;
    return false;

}
bool VerificaDacaSeSuprapuneVarfDreapta (char M[11][11], int p1, int p2)
{
    if (M[p1][p2]!='0')
        return false;
    if (M[p1][p2-1]!='0')
        return false;
    if (M[p1][p2-2]!='0')
        return false;
    if (M[p1][p2-3]!='0')
        return false;
    if (M[p1-1][p2-1]!='0')
        return false;
    if (M[p1+1][p2-1]!='0')
        return false;
    if (M[p1-1][p2-3]!='0')
        return false;
    if (M[p1+1][p2-3]!='0')
        return false;
    return true;
}

bool VerificaDacaSeSuprapuneVarfStanga (char M[11][11], int p1, int p2)
{
    if (M[p1][p2]!='0')
        return false;
    if (M[p1][p2+1]!='0')
        return false;
    if (M[p1][p2+2]!='0')
        return false;
    if (M[p1][p2+3]!='0')
        return false;
    if (M[p1-1][p2+1]!='0')
        return false;
    if (M[p1+1][p2+1]!='0')
        return false;
    if (M[p1-1][p2+3]!='0')
        return false;
    if (M[p1+1][p2+3]!='0')
        return false;
    return true;
}
void afisare(char M[11][11])
{
    for(int i=1; i<=10; i++)
    {
        for(int j=1; j<=10; j++)
            cout<<M[i][j]<<"  ";
        cout<<endl;
    }

}
