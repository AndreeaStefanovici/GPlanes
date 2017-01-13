#include <iostream>
#include<cstdlib>
#include <windows.h>
#include<cstring>
using namespace std;
char M1[11][11], varf, MA[11][11], M2[11][11], M2A[11][11], c[]="123456789";
int p1, p2, c1, c2, x, y;
void initializareMatrice(char M[11][11])
{
    for(int i=1; i<=10; i++)
        for(int j=1; j<=10; j++)
            M[i][j]='*';

}

void verificaCifre(char pc[20], int &p)
{
    if (pc[1]=='\0' && strchr(c, pc[0])!='\0')
        p=atoi(pc);
    else
        if (pc[0]=='1' && pc[1]=='0' && pc[2]=='\0')
            p=10;
        else
            p=0;
    if (p1==0)
        while (p==0)
        {
            cout<<"Introduceti alta valoare: "<<endl;
            cin>>pc;
            p=-1;
            verificaCifre(pc, p);
        }
}

void varfDreapta(char M[11][11], int p1, int p2)
{
    M[p1][p2]='>';
    M[p1][p2-1]=178;
    M[p1][p2-2]=178;
    M[p1][p2-3]=178;
    M[p1-1][p2-1]=178;
    M[p1+1][p2-1]=178;
    M[p1-1][p2-3]=178;
    M[p1+1][p2-3]=178;

}
void varfStanga(char M[11][11], int p1, int p2)
{
    M[p1][p2]='<';
    M[p1][p2+1]=178;
    M[p1][p2+2]=178;
    M[p1][p2+3]=178;
    M[p1-1][p2+1]=178;
    M[p1+1][p2+1]=178;
    M[p1-1][p2+3]=178;
    M[p1+1][p2+3]=178;

}
void varfSus(char M[11][11], int p1, int p2)
{
    M[p1][p2]='A';
    M[p1+1][p2]=178;
    M[p1+2][p2]=178;
    M[p1+3][p2]=178;
    M[p1+1][p2-1]=178;
    M[p1+1][p2+1]=178;
    M[p1+3][p2-1]=178;
    M[p1+3][p2+1]=178;

}
void varfJos(char M[11][11], int p1, int p2)
{
    M[p1][p2]='V';
    M[p1-1][p2]=178;
    M[p1-2][p2]=178;
    M[p1-3][p2]=178;
    M[p1-1][p2-1]=178;
    M[p1-1][p2+1]=178;
    M[p1-3][p2-1]=178;
    M[p1-3][p2+1]=178;

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
void avionPrabusitSus(char M[11][11], int p1, int p2)
{
    M[p1][p2]='C';
    M[p1+1][p2]='X';
    M[p1+2][p2]='X';
    M[p1+3][p2]='X';
    M[p1+1][p2-1]='X';
    M[p1+1][p2+1]='X';
    M[p1+3][p2-1]='X';
    M[p1+3][p2+1]='X';

}
void avionPrabusitJos(char M[11][11], int p1, int p2)
{
    M[p1][p2]='C';
    M[p1-1][p2]='X';
    M[p1-2][p2]='X';
    M[p1-3][p2]='X';
    M[p1-1][p2-1]='X';
    M[p1-1][p2+1]='X';
    M[p1-3][p2-1]='X';
    M[p1-3][p2+1]='X';

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
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleHandle, 6);
    cout<<"  ";
    for(int i=1;i<=10;i++)
        cout<<i;
    cout<<endl;
    for(int i=1; i<=10; i++)
    {
        if (i<10)
            cout<<' ';
        cout<<i;
        for(int j=1; j<=10; j++)
            cout<<M[i][j];
        cout<<endl;
    }
    SetConsoleTextAttribute(consoleHandle, 15);
}

void cautaAvioane (char MA[11][11], char M2[11][11], int &i)
{
    char  x1[20], x2[20];
    int c1=-1, c2=-1;
    cin>>x1;
    verificaCifre(x1, c1);
    cin>>x2;
    verificaCifre(x2, c2);
    while(MA[c1][c2]!='*')
    {
        cout<<"Introduceti alte coordonate: "<<endl;
        cin>>x1;
        verificaCifre(x1, c1);
        cin>>x2;
        verificaCifre(x2, c2);
    }
    if (M2[c1][c2]==178)
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
    char c1[20], c2[20];
    while(i<=3)
    {
        if (i==1)
            cout<<"Introduceti primul avion: ";
        if (i==2)
        {
            afisare(M);
            cout<<"Introduceti al doilea avion: ";
        }
        if (i==3)
        {
            afisare(M);
            cout<<"Intoduceti al treilea avion: ";
        }

        cin>>c1;
        p1=-1; p2=-1;
        verificaCifre(c1, p1);
        cin>>c2;
        verificaCifre(c2, p2);
        cin>>varf;
        while(varf!='A'&& varf!='V'&& varf!='>' && varf!='<')
        {
            cout<<"Introduceti alt varf: ";
            cin>>varf;
        }

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
                cout<<"Introduceti alt varf pentru primul avion: "<<endl;
            if (i==2)
                cout<<"Introduceti alt varf pentru al doilea avion: "<<endl;
            if (i==3)
                cout<<"Introduceti alt varf pentru al treilea avion: "<<endl;
        }
    }

}

void determinaCastigator(char M1[11][11], char MA[11][11], char M2[11][11], char M2A[11][11])
{
    int i1=0, i2=0;

    while (i1<3 && i2<3)
    {
        cout<<"Primul jucator: "<<endl;
        cautaAvioane(MA, M2, i1);
        if(i1!=3)
        {
            cout<<"Al doilea jucator: "<<endl;
            cautaAvioane(M2A, M1, i2);
        }
    }

    if (i1==3)
        cout<<"Felicitari!"<<endl<<"Primul jucator a castigat!";
    else if ((i1!=3)&& (i2==3))
        cout<<"Felicitari!"<<endl<<"Al doilea jucator a castigat!";
}

void pozitiiRandom(int &x, int &y, int &k)
{
    x=rand()%10+1;
    y=rand()%10+1;
    k=rand()%3;
}
void pozitiiRandomFaraCap(int &x, int &y)
{
    x=rand()%10+1;
    y=rand()%10+1;
}
void plansaCalculator(char M[11][11])
{
    int k, i=0;
    while (i<3)
    {
        pozitiiRandom(p1, p2, k);
        if (k==0)
            varf='>';
        if (k==1)
            varf='<';
        if (k==2)
            varf='A';
        if  (k==3)
            varf='V';
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
    }
}

void cautaAvioaneCalculator (char MA[11][11], char M2[11][11], int &i)
{
    int k;
    pozitiiRandomFaraCap(c1, c2);
    while(MA[c1][c2]!='*')
         pozitiiRandomFaraCap(c1, c2);
    if (M2[c1][c2]!='*'&&M2[c1][c2]!='0'&&M2[c1][c2]!='>'&&M2[c1][c2]!='<'&&M2[c1][c2]!='A'&&M2[c1][c2]!='V')
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

void determinaCastigatorCalculator(char M1[11][11], char MA[11][11], char M2[11][11], char M2A[11][11])
{
    int i1=0, i2=0;

    while (i1<3 && i2<3)
    {
        cout<<"Primul jucator: "<<endl;
        cautaAvioane(MA, M2, i1);
        if(i1!=3)
        {
            cout<<"Calculator: "<<endl;
            cautaAvioaneCalculator(M2A, M1, i2);
        }
    }

    if (i1==3)
        cout<<"Felicitari!"<<endl<<"Primul jucator a castigat!";
    else if ((i1!=3)&& (i2==3))
        cout<<"Calculatorul a invins!";
}

void instructiuni()
{
    cout<<"Fiecare jucator trebuie sa isi pozitioneze pe plansa de joc 3 avioane, apoi sa incerce sa doboare avioanele celuilalt. In momentul in care avionul este lovit in varf, se prabuseste. Primul care doboara toate avionele adversarului, castiga.";
    cout<<endl;
    cout<<"Pentru fiecare avion introduceti linia, coloana si directia in care doriti sa fie indreptat avionul."<<endl;
    cout<<'"'<<'<'<<'"'<<'-'<<"varf spre stanga;"<<endl;
    cout<<'"'<<'>'<<'"'<<'-'<<"varf spre dreapta;"<<endl;
    cout<<'"'<<'A'<<'"'<<'-'<<"varf in sus;"<<endl;
    cout<<'"'<<'V'<<'"'<<'-'<<"varf in jos."<<endl;
    cout<<endl;
    cout<<"Introduceti coordonatele avioanelor."<<endl;
}
int main()
{
    int nrJucatori;

    initializareMatrice(M1);
    initializareMatrice(MA);
    initializareMatrice(M2);
    initializareMatrice(M2A);

    instructiuni();
    cout<<"Aceasta este plansa de joc:"<<endl;
    afisare(M1);
    cout<<"Apasa 1 pentru 2 jucatori!"<<endl<<"Apasa 2 pentru a juca contra computerului!"<<endl;
    cin>>nrJucatori;
    if(nrJucatori==1)
    {

        cout<<"Plansa primului jucator: "<<endl;
        plansaAvioane(M1);
        cout<<"Plansa celui de-al doilea jucator: "<<endl;
        plansaAvioane(M2);

        afisare(M1);
        afisare(M2);

        determinaCastigator(M1, MA, M2, M2A);
    }
    else
    {
        cout<<"Plansa primului jucator: "<<endl;
        plansaAvioane(M1);
        afisare(M1);
        cout<<"Plansa calculator: "<<endl;
        plansaCalculator(M2);


        afisare(M2);

        determinaCastigatorCalculator(M1, MA, M2, M2A);

    }
    return 0;
}
