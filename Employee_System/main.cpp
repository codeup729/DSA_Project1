//
//  main.cpp
//  Employee_System
//
//  Created by Anitej Srivastava on 24/03/21.
//  Copyright © 2021 Anitej Srivastava. All rights reserved.
//

#include <iostream>

using namespace std;

typedef struct node
{
    int id;
    char name[50];
    char qua[30];
    char addrs[50];
    char city[30];
    char jobtitle[30];
    int salary;
    char date[30];
    node *prev,*next;
    
}node;
class employ
{
private:
    node *head;
    char ch;
public:
    node *temp_req;
    employ()
    {
        head=NULL;
        
    }
    bool unique(int id)
    {
        node *temp=head;
        while(temp!=NULL)
        {
            if(temp->id==id)
                return false;
            temp=temp->next;
        }
        return true;
    }
    void menu()
    {
        cout<<"\n\t\t\t***********************WELCOME TO THE EMPLOYEE SYSTEM*************************"<<endl;
        cout<<"\n\t\t\t 1- Add a record:";
        cout<<"\n\t\t\t 2- Search a record:";
        cout<<"\n\t\t\t 3- Update a record:";
        cout<<"\n\t\t\t 4- Delete a record:";
        cout<<"\n\t\t\t 5- Display all records:";
        cout<<"\n\t\t\t 6- EXIT:";
        return;
    }
    void add_first()
    {
        node *newer=new node;
        cout<<"\n\t\t Enter the Employee ID:"<<endl;
        cin>>newer->id;
        while(!unique(newer->id))//used while here
        {
            cout<<"\n\t\t ID Already in Use. Please Enter a Different ID:"<<endl;
            cin>>newer->id;
        }
        fflush(stdin);
        
        cout<<"\n\t\t Enter the Employee's Full name :"<<endl;
        cin.getline(newer->name,50);
        fflush(stdin);
        
        cout<<"\n\t\t Enter the Qualification :"<<endl;
        cin.getline(newer->qua,30);
        fflush(stdin);
        
        cout<<"\n\t\t Enter the Address of Employee :"<<endl;
        cin.getline(newer->addrs ,50);
        fflush(stdin);
        
        cout<<"\n\t\tEnter the City:"<<endl;
        cin.getline(newer->city,30);
        fflush(stdin);
        
        cout<<"\n\t\tEnter the Employee Job title :"<<endl;
        cin.getline(newer->jobtitle,50);
        fflush(stdin);
        
        cout<<"\n\t\tEnter the Salary PA:"<<endl;
        cin>>newer->salary;
        fflush(stdin);
        
        cout<<"\n\t\t Enter the Start Date (DD MONTH YYYY):"<<endl;
        cin.getline(newer->date,30);
        fflush(stdin);
        
        newer->next=head;
        newer->prev=NULL;
        if(head==NULL)//added if block
        {
            head=newer;
            temp_req=newer;
        }
        if(head!=NULL)
        {
            head->prev=newer;
        }
        head=newer;
        cout<<"\n\t\t Record inserted Successfully :"<<endl;
        cout<<"\n\t\t **********THANK YOU **********"<<endl;
        
    }
    void add_last()
    {
        if (head==NULL)
        {
            cout<<"\n\t\tList is empty !:"<<endl;
            cout<<"\n\t\tAdd a new record\n\tPress Y or N:"<<endl;
            cin>>ch;
            if (ch=='Y'||ch=='y')
            {
                add_first();
                
                return;
            }
            else
            {
                exit(1);
            }
        }
        else //have made changes here removed while block
        {
            
            node  *newer=new node;
            
            cout<<"\n\t\t Enter the Employee ID:"<<endl;
            cin>>newer->id;
            while(!unique(newer->id))
            {
                cout<<"\n\t\t ID Already in Use. Please Enter a Different ID:"<<endl;
                cin>>newer->id;
            }
            fflush(stdin);
            
            cout<<"\n\t\t Enter the Employee's Full name :"<<endl;
            cin.getline(newer->name,50);
            fflush(stdin);
            
            cout<<"\n\t\t Enter the Qualification :"<<endl;
            cin.getline(newer->qua,30);
            fflush(stdin);
            
            cout<<"\n\t\t Enter the Address of Employee :"<<endl;
            cin.getline(newer->addrs ,50);
            fflush(stdin);
            
            cout<<"\n\t\t Enter the City:"<<endl;
            cin.getline(newer->city,30);
            fflush(stdin);
            
            cout<<"\n\t\t Enter the Employee Job title :"<<endl;
            cin.getline(newer->jobtitle,50);
            fflush(stdin);
            
            cout<<"\n\t\t Enter the Salary PA:"<<endl;
            cin>>newer->salary;
            fflush(stdin);
            
            cout<<"\n\t\t Enter the State Date (DD MONTH YYYY) :"<<endl;
            cin.getline(newer->date,30);
            fflush(stdin);
            
            newer->next=NULL; //made changes
            temp_req->next=newer;
            newer->prev=temp_req;
            temp_req=newer;
            cout<<"\n\t\t Record inserted Successfully :"<<endl;//ADDED 2 LINES HERE
            cout<<"\n\t\t **********THANK YOU **********"<<endl;
        }
    }
    void add_after()
    {
        if (head==NULL)
        {
            
            cout<<"\n\t\tList is empty !:"<<endl;
            cout<<"\n\t\tAdd a new record Press Y or N:"<<endl;
            cin>>ch;
            if (ch=='Y'||ch=='y')
            {
                add_first();
                return;
            }
            else
            {
                exit(1);
            }
        }
        else
        {
            int val;
            cout<<"\n\tEnter the ID after which you want to add a new record:"<<endl;
            cin>>val;
            bool flag=false;
            node *temp=head;
            node *p;
            while(temp!=NULL)
            {
                
                if(temp->id==val)
                {
                    node *newer=new node ;
                    
                    cout<<"\n\t\t Enter the Employee ID:"<<endl;
                    cin>>newer->id;
                    while(!unique(newer->id))
                    {
                        cout<<"\n\t\t ID Already in Use. Please Enter a Different ID:"<<endl;
                        cin>>newer->id;
                    }
                    fflush(stdin);
                    
                    cout<<"\n\t\t Enter the Employee's Full name :"<<endl;
                    cin.getline(newer->name,50);
                    fflush(stdin);
                    
                    cout<<"\n\t\t Enter the Qualification :"<<endl;
                    cin.getline(newer->qua,30);
                    fflush(stdin);
                    
                    cout<<"\n\t\t Enter the Address of Employee :"<<endl;
                    cin.getline(newer->addrs ,50);
                    fflush(stdin);
                    
                    cout<<"\n\t\t Enter the City:"<<endl;
                    cin.getline(newer->city,30);
                    fflush(stdin);
                    
                    cout<<"\n\t\t Enter the Employee Job title :"<<endl;
                    cin.getline(newer->jobtitle,50);
                    fflush(stdin);
                    
                    cout<<"\n\t\t Enter the Salary PA:"<<endl;
                    cin>>newer->salary;
                    fflush(stdin);
                    
                    cout<<"\n\t\t Enter the State Date (DD MONTH YYYY) :"<<endl;
                    cin.getline(newer->date,30);
                    fflush(stdin);
                    
                    
                    
                    if (temp->next!=NULL)
                    {
                        newer->next=temp->next;
                        newer->prev=temp;
                        p=temp->next;
                        p->prev=newer;
                        temp->next=newer;
                        
                    }
                    else
                    {
                        newer->next=temp->next;
                        newer->prev=temp;
                        temp->next=newer;
                        
                    }
                    flag=true;
                    cout<<"\n\t\t Record inserted Successfully :"<<endl;
                    cout<<"\n\t\t **********THANK YOU **********"<<endl;
                    
                }
                temp=temp->next;
                
            }
            if(flag==false)
            {
                cout<<"\n\t ID Not Found! :"<<endl;
                
            }
            
        }
    }
    void add_before()
    {
        if (head==NULL)
        {
            cout<<"\n\tList is empty !:"<<endl;
            cout<<"\n\tAdd a new record\n\tPress Y or N:"<<endl;
            cin>>ch;
            if (ch=='Y'||ch=='y')
            {
                add_first();
                return;
            }
            else
            {
                exit(1);
            }
        }
        else
        {
            int val;
            cout<<"\n\tEnter the ID Before which you want to add a new record:"<<endl;
            cin>>val;
            bool flag=false;
            node *temp=head;
            node *p;
            
            if(temp->id==val)
            {
                flag=true;
                add_first();
                return;
            }
            
            else
            {
                while(temp!=NULL)
                {
                    if(temp->id==val)
                        
                    {
                        node *newer=new node ;
                        
                        cout<<"\n\t\t Enter the Employee ID:"<<endl;
                        cin>>newer->id;
                        while(!unique(newer->id))
                        {
                            cout<<"\n\t\t ID Already in Use. Please Enter a Different ID:"<<endl;
                            cin>>newer->id;
                        }
                        fflush(stdin);
                        
                        cout<<"\n\t\t Enter the Employee's Full name :"<<endl;
                        cin.getline(newer->name,50);
                        fflush(stdin);
                        
                        cout<<"\n\t\t Enter the Qualification :"<<endl;
                        cin.getline(newer->qua,30);
                        fflush(stdin);
                        
                        cout<<"\n\t\t Enter the Address of Employee :"<<endl;
                        cin.getline(newer->addrs ,50);
                        fflush(stdin);
                        
                        cout<<"\n\t\t Enter the City:"<<endl;
                        cin.getline(newer->city,30);
                        fflush(stdin);
                        
                        cout<<"\n\t\t Enter the Employee Job title :"<<endl;
                        cin.getline(newer->jobtitle,50);
                        fflush(stdin);
                        
                        cout<<"\n\t\t Enter the Salary PA:"<<endl;
                        cin>>newer->salary;
                        fflush(stdin);
                        
                        cout<<"\n\t\t Enter the State Date (DD MONTH YYYY) :"<<endl;
                        cin.getline(newer->date,30);
                        fflush(stdin);
                        
                        newer->next=temp;
                        newer->prev=temp->prev;
                        p=temp->prev;
                        p->next=newer;
                        temp->prev=newer;
                        
                        flag=true;
                        cout<<"\n\t\t Record inserted Successfully :"<<endl;
                        cout<<"\n\t\t **********THANK YOU **********"<<endl;
                    }
                    temp=temp->next;
                    
                    
                }
            }
            if(flag==false)
            {
                cout<<"\n\tID is not Found! :"<<endl;
                
            }
            
        }
        
    }
    
    void del()
    {
        if (head==NULL)
        {
            cout<<"\n\tList is empty !:"<<endl;
            cout<<"\n\tAdd a new record\n\tPress Y or N:"<<endl;
            cin>>ch;
            if (ch=='Y'||ch=='y')
            {
                add_first();
                return;
            }
            else
            {
                exit(1);
            }
        }
        
        else
        {
            int val;
            cout<<"\n\t\tEnter the Employee ID corresponding to the record you want to delete: ";
            cin>>val;
            node *temp;
            temp=head;
            bool flag=false;
            if(temp->id==val)
            {
                if(head->next==NULL)
                {
                    head=NULL;
                    free(temp);
                }
                else
                {
                    head=temp->next;
                    head->prev=NULL;
                    flag=true;
                    free(temp);
                }
                cout<<"\n\t\tRecord has been successfully deleted"<<endl;
            }
            else
            {
                while(temp!=NULL)
                {
                    if(temp->id==val)
                    {
                        node *p,*q;
                        if(temp->next==NULL)
                        {
                            p=temp->prev;
                            p->next=NULL;
                            flag=true;
                            free(temp);
                        }
                        else
                        {
                            p=temp->prev;
                            q=temp->next;
                            p->next=q;
                            q->prev=p;
                            flag=true;
                            free(temp);
                        }
                        cout<<"\n\t\tRecord has been successfully deleted"<<endl;
                    }
                    temp=temp->next;
                }
                if(flag==false)
                    cout<<"\n\tID is not found"<<endl;
                
            }
        }
        
    }
    void show()
    {
        int count=0;
        if (head==NULL)
        {
            cout<<"\n\tList is empty !:"<<endl;
            cout<<"\n\tAdd a new record\n\tPress Y or N:"<<endl;
            cin>>ch;
            if (ch=='Y'||ch=='y')
            {
                add_first();
                return;
            }
            else
            {
                exit(1);
            }
        }
        else
        {
            node *temp=head;
            while(temp!=NULL)
            {
                cout<<"\n\n\t\t Information of the Employee"<<endl;
                cout<<"\n\t\t Employee ID:"<<temp->id<<endl;
                cout<<"\n\t\t Name:"<<temp->name<<endl;
                cout<<"\n\t\t Qualification:"<<temp->qua<<endl;
                cout<<"\n\t\t Address:"<<temp->addrs<<endl;
                cout<<"\n\t\t City:"<<temp->city<<endl;
                cout<<"\n\t\t Job Title:"<<temp->jobtitle<<endl;
                cout<<"\n\t\t Salary:"<<temp->salary<<endl;
                cout<<"\n\t\t Starting Date:"<<temp->date<<endl;
                temp=temp->next;
                count++;
            }
            cout<<"\n\tTotal no. of existing records: "<<count<<endl;
        }
        
    }
    void search()
    {
        if (head==NULL)
        {
            cout<<"\n\tList is empty !:"<<endl;
            cout<<"\n\tAdd a new record\n\tPress Y or N:"<<endl;
            cin>>ch;
            if (ch=='Y'||ch=='y')
            {
                add_first();
                return;
            }
            else
            {
                exit(1);
            }
        }
        else
        {
            int val;
            cout<<"\n\t\tEnter Employee ID you want to search: ";
            cin>>val;
            node *temp=head;
            bool flag=false;
            while(temp!=NULL)
            {
                if(temp->id==val)
                {
                    flag=true;
                    cout<<"\n\t\t Information of the Employee"<<endl;
                    cout<<"\n\t\t Employee ID:"<<temp->id<<endl;
                    cout<<"\n\t\t Name:"<<temp->name<<endl;
                    cout<<"\n\t\t Qualification:"<<temp->qua<<endl;
                    cout<<"\n\t\t Address:"<<temp->addrs<<endl;
                    cout<<"\n\t\t City:"<<temp->city<<endl;
                    cout<<"\n\t\t Job Title:"<<temp->jobtitle<<endl;
                    cout<<"\n\t\t Salary:"<<temp->salary<<endl;
                    cout<<"\n\t\t Starting Date:"<<temp->date<<endl;
                    return;
                }
                temp=temp->next;
            }
            if(flag==false)
                cout<<"\n\t\t ID not found"<<endl;
        }
        
    }
    void update()
    {
        if(head==NULL)
        {
            cout<<"\n\tList is empty !:"<<endl;
            cout<<"\n\tAdd a new record\n\tPress Y or N:"<<endl;
            cin>>ch;
            if (ch=='Y'||ch=='y')
            {
                add_first();
                return;
            }
            else
            {
                exit(1);
            }
        }
        else
        {
            int val;
            cout<<"\n\t\tEnter Employee ID you want to update: ";
            cin>>val;
            node *temp=head;
            bool flag=false;
            while(temp!=NULL)
            {
                if(temp->id==val)
                {
                    flag=true;
                    fflush(stdin);
                    
                    cout<<"\n\t\t Enter the Employee's Full name :"<<endl;
                    cin.getline(temp->name,50);
                    fflush(stdin);
                    
                    cout<<"\n\t\t Enter the Qualification :"<<endl;
                    cin.getline(temp->qua,30);
                    fflush(stdin);
                    
                    cout<<"\n\t\t Enter the Address of Employee :"<<endl;
                    cin.getline(temp->addrs ,50);
                    fflush(stdin);
                    
                    cout<<"\n\t\t Enter the City:"<<endl;
                    cin.getline(temp->city,30);
                    fflush(stdin);
                    
                    cout<<"\n\t\t Enter the Employee Job title :"<<endl;
                    cin.getline(temp->jobtitle,50);
                    fflush(stdin);
                    
                    cout<<"\n\t\t Enter the Salary PA:"<<endl;
                    cin>>temp->salary;
                    fflush(stdin);
                    
                    cout<<"\n\t\t Enter the State Date (DD MONTH YYYY) :"<<endl;
                    cin.getline(temp->date,30);
                    fflush(stdin);
                    cout<<"\n\t\t Record has beem updated sucessfully"<<endl;
                }
                temp=temp->next;
            }
            if(flag==false)
                cout<<"\n\t\t ID not found"<<endl;
        }
    }
};

int main()
{
    int n;
    char ch;
    employ em;
x2:
    em.menu();
    cout<<"\n\t\tEnter your choice:"<<endl;
    cin>>n;
    if(n==1)
    {
    x1:
        cout<<"\n\t\tWhere do you want to add record"<<endl;
        cout<<"\n\t\t 1- very first record:"<<endl;
        cout<<"\n\t\t 2- very last record:"<<endl;
        cout<<"\n\t\t 3- add after a record:"<<endl;
        cout<<"\n\t\t 4- add before a record:"<<endl;
        cout<<"\n\t\t Enter choice"<<endl;
        cin>>n;
        if(n==1)
        {
            em.add_first();
            cout<<"\n\t\t Do you want to go to main menu:"<<endl;
            cin>>ch;
            fflush(stdin);
            if(ch=='Y'||ch=='y')
                goto x2;
            else
                exit(1);
        }
        else if(n==2)
        {
            em.add_last();
            cout<<"\n\t\t Do you want to go to main menu:"<<endl;
            cin>>ch;
            if(ch=='Y'||ch=='y')
                goto x2;
            else
                exit(1);
        }
        else if(n==3)
        {
            em.add_after();
            cout<<"\n\t\t Do you want to go to main menu:"<<endl;
            cin>>ch;
            if(ch=='Y'||ch=='y')
                goto x2;
            else
                exit(1);
        }
        else if(n==4)
        {
            em.add_before();
            cout<<"\n\t\t Do you want to go to main menu:"<<endl;
            cin>>ch;
            if(ch=='Y'||ch=='y')
                goto x2;
            else
                exit(1);
        }
        else
        {
            cout<<"\n\t\t Choose correct option:"<<endl;
            goto x1;
        }
    }
    else if(n==2)
    {
        em.search();
        cout<<"\n\t\t Do you want to go to main menu:"<<endl;
        cin>>ch;
        if(ch=='Y'||ch=='y')
            goto x2;
        else
            exit(1);
    }
    else if(n==3)
    {
        em.update();
        cout<<"\n\t\t Do you want to go to main menu:"<<endl;
        cin>>ch;
        if(ch=='Y'||ch=='y')
            goto x2;
        else
            exit(1);
    }
    else if(n==4)
    {
        em.del();
        cout<<"\n\t\t Do you want to go to main menu:"<<endl;
        cin>>ch;
        if(ch=='Y'||ch=='y')
            goto x2;
        else
            exit(1);
    }
    else if(n==5)
    {
        em.show();
        cout<<"\n\t\t Do you want to go to main menu:"<<endl;
        cin>>ch;
        if(ch=='Y'||ch=='y')
            goto x2;
        else
            exit(1);
    }
    else if(n==6)
    {
        exit(1);
    }
    else
    {
        cout<<"\n\t\t Choose correct option"<<endl;
        goto x2;
    }
    return 0;
}



