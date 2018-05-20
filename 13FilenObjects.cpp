/*
Design and develop a ITEM class with itemName, itemCode, itemPrize, numberOfItems (itemCount) as
data members. Implement suitable methods
Working with Files: demonstrate the following file operations;
a. Writing an object at the end of file
b. Reading all objects from a file and display on console
c. Update a given object information on the file
*/

#include<iostream>
#include<fstream>

using namespace std;

class ITEM{
    string itemName;
    int itemCode;
    int itemPrize;
    int itemCount;
    public:
    
    void getdata(void){
        cin>>itemName>>itemCode>>itemPrize>>    itemCount;
    }

    void display(void){
        cout<<"Itemname:"<<itemName;
        cout<<" Itemcode:"<<itemCode;
        cout<<" Itemprize:"<<itemPrize;
        cout<<" Itemcount:"<<itemCount<<endl;
    }
};

int main(){
    int n,loc;
    cout<<"Enter number of objects:";
    cin>>n;
    fstream file("items",ios::out|ios::in);
    if(!file){
        cout<<"Error occured while opening file"<<endl;
        exit(0);
    }
    ITEM it;

    for(int i=0;i<n;i++){
        cout<<"Enter values for item "<<i<<":"<<endl;
        it.getdata(); 
        file.write((char*)&it,sizeof(it));
    }

    cout<<"Successfuly added "<<n<<" objs to file"<<endl;
    
    cout<<"Enter one more object to add:";
    it.getdata();
    file.write((char*)&it,sizeof(it));
    n++;

    file.seekg(ios::beg);
    for(int i=0;i<n;i++){
        cout<<"item "<<i+1<<":"<<endl;
        file.read((char*)&it,sizeof(it));
        it.display();
    }
    cout<<"\nEnter object number to be modified:";
    cin>>loc;
    if(loc>n || loc<=0){
        cout<<"Outta bounds\n"<<"Program will terminate now"<<endl;
        exit(0);
    }
    loc=(loc-1)*sizeof(it);
    file.seekp(loc);
    cout<<"Enter new data:"<<endl;
    it.getdata();
    file.write((char*)&it,sizeof(it));
    cout<<"Object successfully modified in file"<<endl;

    cout<<"Updated file contents:\n";
    
    file.seekg(ios::beg);
    for(int i=0;i<n;i++){
        file.read((char*)&it,sizeof(it));
        it.display();
    }
    file.close();
    return 0;
}