#include<iostream>
#include<stdlib.h>
#include<string.h>
#define MAX 10
using namespace std;

struct Hash1
{
    int id;
    char name[20];
}rec[MAX] , tmp;

class Hashtable
{
   public:
       void initialize();
       int hashing( int );
       void woreplace(struct Hash1);
       void wreplace(struct Hash1);
       void place_at_next_slot(int , struct Hash1);
       void display();
       void search(int);
};

void Hashtable :: initialize()
{
    int i;
    for(i = 0; i < MAX; i++)
    {
        rec[i].id = -1;
        strcpy( rec[i].name , "-");
    }
}

int Hashtable :: hashing( int no )
{
    int key;
    key = no % MAX;
    return(key);

}

void Hashtable :: woreplace(struct Hash1 h)
{
    int i,k,z;
    k = hashing(h.id);

    if(rec[k].id == -1)
    {
        rec[k].id = h.id;
        strcpy(rec[k].name , h.name);
    }
    else
        place_at_next_slot(k,h);
}

void Hashtable :: wreplace(struct Hash1 h)
{
    int k,p,change_pos;
    k = hashing( h.id);

    if(rec[k].id == -1)
    {
        rec[k].id = h.id;
        strcpy(rec[k].name , h.name);
    }
    else if(hashing(rec[k].id) == hashing(h.id))
            place_at_next_slot(k , h);

    else
    {
        tmp.id = rec[k].id;
        strcpy(tmp.name ,rec[k].name );

        rec[k].id = h.id;
        strcpy(rec[k].name , h.name);

        place_at_next_slot(k , tmp);
    }
}

void Hashtable :: place_at_next_slot(int k,struct Hash1 h)
{
    int i,z;
    for(i = 1;i < MAX;i++)
    {
        z = (k+i)%MAX;
        if(rec[z].id == -1)
        {
            rec[z].id = h.id;
            strcpy(rec[z].name , h.name);
            break;
        }
    }
}
void Hashtable :: display()
{
    cout<<"\n Collision Handling : \n\t---------#######---------";
    cout<<"\n\t Index     ID     NAME      \n\t----------------------\n";
    for(int i=0;i<MAX;i++)
    {
        cout<<"\t"<<i<<" \t "<<rec[i].id;
        cout<<"\t "<<rec[i].name;
        cout<<"\n";
    }
    cout<<"\n\t------------------------";
}
void Hashtable :: search(int key)
{
    int i,k,z;
    int flag = 0;
    k = hashing(key);

    if(rec[k].id == key)
        cout<<"\n key " <<key<< "found at home address || ";
    else
    {
        for(z = 1;z < MAX;z++)
        {
            i = (k+z)%MAX;
            if(rec[i].id == key)
            {
                cout<<"\n key " <<key<< "found at "<<i<<"address ||";
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            cout<<"\n key "<<key<<"not found in table";
    }
}




int main()
{
    Hashtable h;
    int ch,ch1,key;
    char ans;
    struct Hash1 temph;
    do
    {
        cout<<"\n Collision Handling ";
        cout<<"\n  1. without replacement  \n 2. with replacement ";
        cout<<"\n 3. Display Record \n 4.Search record \n 5.Exit \n Enter your choice : ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            h.initialize();
            do
            {
                cout<<"\n Enter ID : ";
                cin>>temph.id;
                cout<<"\n Enter Name : ";
                cin>>temph.name;
                h.woreplace(temph);
                cout<<"\n Do you want to add more elements (0/1)? ";
                cin>>ch1;
        } while(ch1 != 0);
        break;



        case 2:
            h.initialize();
            do
            {
                cout<<"\n Enter ID : ";
                cin>>temph.id;
                cout<<"\n Enter NAME : ";
                cin>>temph.name;
                h.wreplace(temph);
                cout<<"\n Do you want to add more elements (0/1)? ";
                cin>>ch1;
            }while(ch1 != 0);
            break;

        case 3:
            h.display();
            break;

        case 4:
            cout<<"\n Enter the id for searching : ";
            cin>>key;
            h.search(key);
            break;

        case 5 : exit(0);
        }
    }while( ch != 4 );

   return 0;
}
