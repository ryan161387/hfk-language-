#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int temp;
/**
 * "hfk" language
 * LISENCE : Ryan(c)
 * USEAGE : Nothing in particular just a fun project
 * INSPIRIATION : Inspired from the "brainfck" programming language
 * Contributers : Ryan Nayeraini and no one , yes litrally no one!
 * File extension : [filename].hfk 
 * Feel free to use and modify this code
 * */
void readfile(string filename)
{
    int code[30000]={0},pointer=0; // float code[30000]; int pointer=0;
    fstream compiledfile(filename.c_str() , ios::in | ios::app );
    string tempp,fullparce="";
    if(compiledfile.is_open()) // full parcer
    {
        while(getline(compiledfile , tempp))
        {
            if(tempp!="\n")
                fullparce+=tempp;
            if(compiledfile.eof())
            break;
        }
        for (ll i = 0; i < fullparce.size(); i++)
        {
            if(pointer >= 30000)
            {
                cout<<"POINTER EXCEEDED LEVEL ";
                exit(0);
            }
            else if(pointer < 0)
            {
                cout<<"POINTER CANNOT GO LOWER ";
                exit(0); 
            }
            if(fullparce[i]=='.')
            {
                cout<<code[pointer];
            }
            else if(fullparce[i]==',')
            {
                cout<<char(code[pointer]);
            }
            else if(fullparce[i]=='+')
            {
                code[pointer]++;
            }
            else if(fullparce[i]=='-')
            {
                code[pointer]--;
            }
            else if(fullparce[i]=='>')
            {
                pointer++;
            }
            else if(fullparce[i]=='<')
            {
                pointer--;
            }
            else if(fullparce[i]=='*')
            {
                cin>>code[pointer];
            }
            else if(fullparce[i]=='=')
            {
                if(fullparce[i+1]=='>' || fullparce[i+1]=='<')
                {
                    i++;
                    temp=pointer;
                    if(fullparce[i]=='>')
                    {
                        pointer++;
                    }
                    else if(fullparce[i]=='<')
                    {
                        pointer--;
                    }
                    code[temp]=code[pointer];
                    pointer=temp;
                }
                else 
                {
                    cout<<"NO SUCH ARGUMENT AFTER'=' ";
                    exit(0);
                }
            }
            else if(fullparce[i]=='$') // jame
            {
                if(fullparce[i+1]=='>' || fullparce[i+1]=='<')
                {
                    i++;
                    if(i==fullparce.size())
                    {
                        cout<<"NO ARGUMENTS AFTER '$'";
                        exit(0);
                    }
                    temp=pointer;
                    if(fullparce[i]=='>')
                    {
                        pointer++;
                    }
                    else if(fullparce[i]=='<')
                    {
                        pointer--;
                    }
                    code[temp]+=code[pointer];
                    pointer=temp;
                }
                else 
                {
                    cout<<"NO SUCH ARGUMENT FOR '$'";
                    exit(0);
                }
            }
            else if(fullparce[i]=='#') // zarb
            {
                if(fullparce[i+1]=='>' || fullparce[i+1]=='<')
                {
                    i++;
                    if(i==fullparce.size())
                    {
                        cout<<"NO ARGUMENTS AFTER '#'";
                        exit(0);
                    }
                    temp=pointer;
                    if(fullparce[i]=='>')
                    {
                        pointer++;
                    }
                    else if(fullparce[i]=='<')
                    {
                        pointer--;
                    }
                    code[temp]*=code[pointer];
                    pointer=temp;
                }
                else 
                {
                    cout<<"NO SUCH ARGUMENT FOR '#'";
                    exit(0);
                }
            }
            else if(fullparce[i]=='/')
            {
                if(fullparce[i+1]=='>' || fullparce[i+1]=='<')
                {
                    i++;
                    if(i==fullparce.size())
                    {
                        cout<<"NO ARGUMENTS AFTER '/'";
                        exit(0);
                    }
                    temp=pointer;
                    if(fullparce[i]=='>')
                    {
                        pointer++;
                    }
                    else if(fullparce[i]=='<')
                    {
                        pointer--;
                    }
                    code[temp]=code[temp]/code[pointer];
                    pointer=temp;
                }
                else 
                {
                    cout<<"NO SUCH ARGUMENT FOR '/'";
                    exit(0);
                }
            }
            else if(fullparce[i]=='[')
            {
                i++;
                if(i==fullparce.size())
                {
                    cout<<"NO ARGUMENTS AFTER '[' FOR WHILE";
                    exit(0);
                }
                int pointerofwhile=pointer;
                bool has=false;
                for (int j = i; j<fullparce[i] ; j++)
                {
                    if(fullparce[j]==']')
                        has=true;
                }
                if(has==false)
                {
                    cout<<"WHILE NOT CLOSED ";
                    exit(0);
                }
                for (ll j = i; code[pointer]>=0; j++) // code[pointerofwhile]
                {
                    //pointer=pointerofwhile;
                    if(fullparce[j]==']')
                    {
                        j=i;
                    }
                    if(pointer >= 30000)
                    {
                        cout<<"POINTER EXCEEDED LEVEL ";
                        exit(0);
                    }
                    else if(pointer < 0)
                    {
                        cout<<"POINTER CANNOT GO LOWER ";
                        exit(0); 
                    }
                    if(fullparce[j]=='.')
                    {
                        cout<<code[pointer];
                    }
                    else if(fullparce[j]==',')
                    {
                        cout<<char(code[pointer]);
                    }
                    else if(fullparce[j]=='+')
                    {
                        code[pointer]++;
                    }
                    else if(fullparce[j]=='-')
                    {
                        code[pointer]--;
                    }
                    else if(fullparce[j]=='>')
                    {
                        pointer++;
                    }
                    else if(fullparce[j]=='<')
                    {
                        pointer--;
                    }
                    else if(fullparce[j]=='*')
                    {
                        cin>>code[pointer];
                    }
                    else if(fullparce[j]=='=')
                    {
                        if(fullparce[j+1]=='>' || fullparce[j+1]=='<')
                        {
                            j++;
                            temp=pointer;
                            if(fullparce[j]=='>')
                            {
                                pointer++;
                            }
                            else if(fullparce[j]=='<')
                            {
                                pointer--;
                            }
                            code[temp]=code[pointer];
                            pointer=temp;
                        }
                        else 
                        {
                            cout<<"NO SUCH ARGUMENT AFTER'=' ";
                            exit(0);
                        }
                    }
                    else if(fullparce[j]=='$') // jame
                    {
                        if(fullparce[j+1]=='>' || fullparce[j+1]=='<')
                        {
                            i++;
                            if(j==fullparce.size())
                            {
                                cout<<"NO ARGUMENTS AFTER '$'";
                                exit(0);
                            }
                            temp=pointer;
                            if(fullparce[j]=='>')
                            {
                                pointer++;
                            }
                            else if(fullparce[j]=='<')
                            {
                                pointer--;
                            }
                            code[temp]+=code[pointer];
                            pointer=temp;
                        }
                        else 
                        {
                            cout<<"NO SUCH ARGUMENT FOR '$'";
                            exit(0);
                        }
                    }
                    else if(fullparce[j]=='#') // zarb
                    {
                        if(fullparce[j+1]=='>' || fullparce[j+1]=='<')
                        {
                            j++;
                            if(i==fullparce.size())
                            {
                                cout<<"NO ARGUMENTS AFTER '#'";
                                exit(0);
                            }
                            temp=pointer;
                            if(fullparce[j]=='>')
                            {
                                pointer++;
                            }
                            else if(fullparce[j]=='<')
                            {
                                pointer--;
                            }
                            code[temp]*=code[pointer];
                            pointer=temp;
                        }
                        else 
                        {
                            cout<<"NO SUCH ARGUMENT FOR '#'";
                            exit(0);
                        }
                    }
                    else if(fullparce[j]=='/')
                    {
                        if(fullparce[j+1]=='>' || fullparce[j+1]=='<')
                        {
                            j++;
                            if(j==fullparce.size())
                            {
                                cout<<"NO ARGUMENTS AFTER '/'";
                                exit(0);
                            }
                            temp=pointer;
                            if(fullparce[j]=='>')
                            {
                                pointer++;
                            }
                            else if(fullparce[j]=='<')
                            {
                                pointer--;
                            }
                            code[temp]=code[temp]/code[pointer];
                            pointer=temp;
                        }
                        else 
                        {
                            cout<<"NO SUCH ARGUMENT FOR '/'";
                            exit(0);
                        }
                    }
                    else if(fullparce[j]=='[' && i!=j)
                    {
                        cout<<"CAN NOT HAVE NESTED WHILES";
                        exit(0);
                    }
                    /*
                    else 
                    {
                        cout<<"NO SUCH CODE";
                        exit(0);
                    }
                    */
                }
            }
            /*
            else 
            {
                cout<<"NO SUCH CODE";
                exit(0);
            }
            */
        }
    }
    else 
    {
        cout<<"File does not exist";
        exit(0);
    }
}
bool filechecker(string filename)
{
    for(int i=0 ; i<filename.size();i++)
    {
       
        if(filename[i]=='.')
        {
            if(i+3 == filename.size()-1 && filename[i+1] == 'h' && filename[i+2] == 'f' && filename[i+3] == 'k')
                {
                    readfile(filename);
                    exit(0);
                }
            else 
            {
                cout<<"Wrong file";
                exit(0);
            }
        }
    }
}
int main()
{
    string filename;
    cin>>filename;
    filechecker(filename);
    return 0;
}
// old while code:
/*
*/
