#include <iostream>
using namespace std;
char M1[11][11], varf, MA[11][11], M2[11][11], M2A[11][11];
int p1, p2;
void initializareMatrice(char M[11][11])
{
    for(int i=1; i<=10; i++)
        for(int j=1; j<=10; j++)
            M[i][j]='*';

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
void varfSus(char M[11][11], int p1, int p2)
{
    M[p1][p2]='A';
    M[p1+1][p2]='-';
    M[p1+2][p2]='|';
    M[p1+3][p2]='-';
    M[p1+1][p2-1]='-';
    M[p1+1][p2+1]='-';
    M[p1+3][p2-1]='-';
    M[p1+3][p2+1]='-';

}
void varfJos(char M[11][11], int p1, int p2)
{
    M[p1][p2]='V';
    M[p1-1][p2]='-';
    M[p1-2][p2]='|';
    M[p1-3][p2]='-';
    M[p1-1][p2-1]='-';
    M[p1-1][p2+1]='-';
    M[p1-3][p2-1]='-';
    M[p1-3][p2+1]='-';

}

void avionPrabusitDreapta(char M[11][11], int p1, int p2)
{
    M[p1][p2]='C';
    M[p1][p2-1]='X';
    M[p1][p2-2]='X';
    M[p1][p2-3]='X';
    M[p1-1][p2-1]='X';
    M[p1+1][p2-1]='X';
    M[p1-1][p2-3]='X';
    M[p1+1][p2-3]='X';

}
void avionPrabusitStanga(char M[11][11], int p1, int p2)
{
    M[p1][p2]='C';
    M[p1][p2+1]='X';
    M[p1][p2+2]='X';
    M[p1][p2+3]='X';
    M[p1-1][p2+1]='X';
    M[p1+1][p2+1]='X';
    M[p1-1][p2+3]='X';
    M[p1+1][p2+3]='X';

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

bool VarfSusLaMargine (char M[11][11], int p1, int p2)
{
    if ((p2<2)||(p2>9)||(p1>7)||(p1<1))
        return true;
    return false;
}

bool VarfJosLaMargine (char M[11][11], int p1, int p2)
{
    if ((p2>9)||(p2<2)||(p1<4)||(p1>10))
        return true;
    return false;
}

bool VerificaVarfLaMargine (char M[11][11], int p1, int p2, char varf)
{
    if ((varf=='>') && (M[p1][p2]=='*'))
        if (VarfDreaptaLaMargine(M, p1, p2)==false)
            return true;
    if ((varf=='<') && (M[p1][p2]=='*'))
        if (VarfStangaLaMargine(M, p1, p2)==false)
            return true;
    if ((varf=='A') && (M[p1][p2]=='*'))
        if (VarfSusLaMargine(M, p1, p2)==false)
            return true;
    if ((varf=='V') && (M[p1][p2]=='*'))
        if (VarfJosLaMargine(M, p1, p2)==false)
            return true;
    return false;

}

bool VerificaDacaSeSuprapuneVarfDreapta (char M[11][11], int p1, int p2)
{
    if (M[p1][p2]!='*')
        return false;
    if (M[p1][p2-1]!='*')
        return false;
    if (M[p1][p2-2]!='*')
        return false;
    if (M[p1][p2-3]!='*')
        return false;
    if (M[p1-1][p2-1]!='*')
        return false;
    if (M[p1+1][p2-1]!='*')
        return false;
    if (M[p1-1][p2-3]!='*')
        return false;
    if (M[p1+1][p2-3]!='*')
        return false;
    return true;
}

bool VerificaDacaSeSuprapuneVarfStanga (char M[11][11], int p1, int p2)
{
    if (M[p1][p2]!='*')
        return false;
    if (M[p1][p2+1]!='*')
        return false;
    if (M[p1][p2+2]!='*')
        return false;
    if (M[p1][p2+3]!='*')
        return false;
    if (M[p1-1][p2+1]!='*')
        return false;
    if (M[p1+1][p2+1]!='*')
        return false;
    if (M[p1-1][p2+3]!='*')
        return false;
    if (M[p1+1][p2+3]!='*')
        return false;
    return true;
}
bool VerificaDacaSeSuprapuneVarfSus (char M[11][11], int p1, int p2)
{
    if (M[p1][p2]!='*')
        return false;
    if(M[p1+1][p2]!='*')
        return false;
    if(M[p1+2][p2]!='*')
        return false;
    if(M[p1+3][p2]!='*')
        return false;
    if(M[p1+1][p2-1]!='*')
        return false;
    if(M[p1+1][p2+1]!='*')
        return false;
    if(M[p1+3][p2-1]!='*')
        return false;
    if(M[p1+3][p2+1]!='*')
        return false;
    return true;
}
bool VerificaDacaSeSuprapuneVarfJos (char M[11][11], int p1, int p2)
{
    if (M[p1][p2]!='*')
        return false;
    if(M[p1-1][p2]!='*')
        return false;
    if(M[p1-2][p2]!='*')
        return false;
    if(M[p1-3][p2]!='*')
        return false;
    if(M[p1-1][p2-1]!='*')
        return false;
    if(M[p1-1][p2+1]!='*')
        return false;
    if(M[p1-3][p2-1]!='*')
        return false;
    if(M[p1-3][p2+1]!='*')
        return false;
    return true;
}
bool VerificaDacaSeSuprapuneAvionul (char M[11][11], int p1, int p2, char varf)
{
    if (varf=='>')
        if (VerificaDacaSeSuprapuneVarfDreapta(M, p1, p2)==false)
            return false;

    if (varf=='<')
        if (VerificaDacaSeSuprapuneVarfStanga(M, p1, p2)==false)
            return false;
    if (varf=='A')
        if (VerificaDacaSeSuprapuneVarfSus(M, p1, p2)==false)
            return false;
    if (varf=='V')
        if (VerificaDacaSeSuprapuneVarfJos(M, p1, p2)==false)
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
    cout<<endl;

}

void cautaAvioane (char MA[11][11], char M2[11][11], int &i)
{
    int  c1, c2;
    cin>>c1>>c2;
    while(MA[c1][c2]!='*')
    {
        cout<<"Introduceti alte coordonate: "<<endl;
        cin>>c1>>c2;
    }

    if (M2[c1][c2]=='|'|| M2[c1][c2]=='-')
    {
        MA[c1][c2]='X';
        cout<<"Avion lovit!"<<endl;
    }
    if (M2[c1][c2]=='>'||M2[c1][c2]=='<'||M2[c1][c2]=='A'||M2[c1][c2]=='V')
    {
        MA[c1][c2]='C';
        cout<<"Avion prabusit!"<<endl;
        i++;
        if(M2[c1][c2]=='<')
            avionPrabusitStanga(MA,c1,c2);
        if(M2[c1][c2]=='>')
            avionPrabusitDreapta(MA,c1,c2);
        if(M2[c1][c2]=='A')
            avionPrabusitSus(MA,c1,c2);
        if(M2[c1][c2]=='V')
            avionPrabusitJos(MA,c1,c2);
    }
    if (M2[c1][c2]=='*')
    {
        MA[c1][c2]='O';
        cout<<"Spatiu gol!"<<endl;
    }
    afisare(MA);

}

void plansaAvioane(char M[11][11])
{
    int i=1;
    while(i<=3)
    {
        if (i==1)
            cout<<"Introduceti primul avion! ";
        if (i==2)
            cout<<"Introduceti al doilea avion! ";
        if (i==3)
            cout<<"Intoduceti al treilea avion! ";
        cin>>p1>>p2>>varf;
        if (VerificaVarfLaMargine(M, p1, p2, varf)==true && VerificaDacaSeSuprapuneAvionul(M, p1, p2, varf)==true)
        {
            i++;
            if(varf=='>')
                varfDreapta(M,p1,p2);
            else if(varf=='<')
                varfStanga(M,p1,p2);
            else if(varf=='A')
                varfSus(M,p1,p2);
            else if(varf=='V')
                varfJos(M,p1,p2);
        }
        else
        {
            cout<<"Pozitia varfului introdus este gresita! "<<endl;
            if (i==1)
                cout<<"Introduceti alt varf pentru al primul avion: "<<endl;
            if (i==2)
                cout<<"Introduceti alt varf pentru al doilea avion: "<<endl;
            if (i==3)
                cout<<"Introduceti alt varf pentru al treilea avion: "<<endl;
        }
    }
}
