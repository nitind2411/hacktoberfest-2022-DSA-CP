#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char arr[6][20] = {"programmer", "developer", "engineer",
                        "student", "teacher", "professor"};
    char name[25];
    int found=0;
    cout<<"Who are You ? ";
    cin>>name;
    for(int i=0; i<6; i++)
    {
        if(!strcmp(name, arr[i]))
        {
            cout<<"\nCongratulation!";
            cout<<"\nYou're invited from codescracker.com";
            found=1;
            break;
        }
        else
            found++;
    }
    if(found != 1)
        cout<<"\nSorry!\nYou're not invited";
    cout<<endl;
    return 0;
}
