#include<iostream>
#include<fstream>
#include <iomanip> 

using namespace std;

class shopping{
    private:
    int pcode;
    float price;
    float dis;
    string pname;

    public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();

};

void shopping:: menu(){
    m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t______________________________________________\n";
    cout<<"\t\t\t\t                                              \n";
    cout<<"\t\t\t\t           Supermarket Main Menu              \n";
    cout<<"\t\t\t\t                                              \n";
    cout<<"\t\t\t\t______________________________________________\n";
    cout<<"\t\t\t\t                                              \n";
    cout<<"\t\t\t\t|    1) Administrator     |\n";
    cout<<"\t\t\t\t|                         |\n";
    cout<<"\t\t\t\t|    2) Buyer             |\n";
    cout<<"\t\t\t\t|                         |\n";
    cout<<"\t\t\t\t|    3) Exit              |\n";
    cout<<"\t\t\t\t|                         |\n";
    cout<<"\n\t\t\t\t Pleae select :";
    cin>>choice;
    switch(choice){
        case 1:{
            cout<<"\t\t\t\t Please login \n";
            cout<<"\t\t\t\t Enter Email \n";
            cin>>email;
            cout<<"\t\t\t\t Enter Password \n";
            cin>>password;
            if(email == "prasanthnallabariki@gmail.com" && password == "Prasanth@123"){
                administrator();
            }
            else{
                cout<<"Invalid Email/Password";
            }
            break;

        }
        case 2:{
            buyer();
        }
        case 3:{
            exit(0);
        }
        default:{
            cout<<"Please select from given options";
        }
    }
    goto m;

}
void shopping:: administrator(){
    m:
    int choice;
    cout<<"\n\n\n\t\t     Administrator Menu";
    cout<<"\n\t\t\t|_______1) Add the product______|";
    cout<<"\n\t\t\t|                               |";
    cout<<"\n\t\t\t|_______2) Modify the product___|";
    cout<<"\n\t\t\t|                               |";
    cout<<"\n\t\t\t|_______3) Delete the product___|";
    cout<<"\n\t\t\t|                               |";
    cout<<"\n\t\t\t|_______4) Back to Main Menu____|";
    cout<<"\n\n\t Enter your choice";
    cin>>choice;

    switch(choice){
        case 1:{
            add();
            break;
        }
        case 2:{
            edit();
            break;
        }
        case 3:{
            rem();
            break;
        }
        case 4:{
            menu();
            break;
        }
        default:{
            cout<<"Invalid Choice!";

        }
    }
    goto m;
}

void shopping:: buyer(){
    m:
    int choice;
    cout<<"\t\t\t Buyer   \n";
    cout<<"\t\t\t_______________  \n";
    cout<<"\t\t\t                 \n";
    cout<<"\t\t\t1) Buy Product   \n";
    cout<<"\t\t\t                 \n";
    cout<<"\t\t\t2) Go back       \n";
    cout<<"\t\t Enter your choice : ";

    cin>>choice;

    switch(choice){
        case 1:{
            receipt();
            break;
        }
        case 2:{
            menu();
            break;
        }
        default:{
            cout<<"Invalid choice";
        }
    }
    goto m;
}
void shopping:: add(){
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t Add New Product";
    cout<<"\n\n\t Product code of the product";
    cin>>pcode;
    cout<<"\n\n\t Name of the product";
    cin>>pname;
    cout<<"\n\n\t Price of the product";
    cin>>price;
    cout<<"\n\n\t Discount on product";
    cin>>dis;
    data.open("database.txt",ios::in);

    if(!data){
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else{
        data>>c>>n>>p>>d;
        while(!data.eof()){
            if(c==pcode){
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
    
    if(token == 1){
        goto m;
    }
    else{
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    }
    cout<<"\n\n\t\t Record inserted!";
}

void shopping:: edit(){
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t Modify the record";
    cout<<"\n\t\t\t  Product Code";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\n File doesn't exist";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pkey == pcode){
                cout<<"\n\t\t Product new code";
                cin>>c;
                cout<<"\n\t\t Name of the Product";
                cin>>n;
                cout<<"\n\t\t Price";
                cin>>p;
                cout<<"\n\t\t Discount";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record Edited";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";

            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");
        if(token == 0){
            cout<<"\n\n\t\t Record not found sorry!";
        }

    }
}
void shopping:: rem(){
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t Delete Product";
    cout<<"\n\n\t Product Code : ";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"File doesn't exist";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pcode == pkey){
                cout<<"\n\t\t Product Deleted Successfully";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0){
            cout<<"\n\n Record not Found";
        }

    }
}
void shopping:: list(){
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n|__________________________________________________________________\n";
    cout<<"Podno\t\tName\t\tPrice\n";
    cout<<"\n\n|__________________________________________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof()){
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;

    }
    data.close();

}

void shopping::receipt() {
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout << "\n\n\t\t\t RECEIPT";
    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\n\n Empty Database";
    } else {
        data.close();
        list();
        cout << "\n____________________________________________\n";
        cout << "\n|                                           \n";
        cout << "\n           Please place the order           \n";
        cout << "\n|                                           \n";
        cout << "\n____________________________________________\n";

        do {
        m:
            cout << "\n\n Enter Product code: ";
            cin >> arrc[c];
            cout << "\n\n Enter the product quantity: ";
            cin >> arrq[c];
            for (int i = 0; i < c; i++) {
                if (arrc[c] == arrc[i]) {
                    cout << "\n\n Duplicate product code, please try again!";
                    goto m;
                }
            }
            c++;
            cout << "\n\n Do you want to buy another product? If Yes press y else no: ";
            cin >> choice;
        } while (choice == 'y');

        // Print the receipt header once, outside the loop
        cout << "\n\n\t\t\t___________________________________RECEIPT________________________________\n";
        cout << setw(10) << "Product no" << setw(20) << "Product Name" << setw(20) << "Product quantity" << setw(10) << "Price" << setw(10) << "Amount" << setw(20) << "Amount with discount\n";
        cout << "_________________________________________________________________________\n";

        for (int i = 0; i < c; i++) {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof()) {
                if (pcode == arrc[i]) {
                    amount = price * arrq[i];
                    float discounted_amount = amount - (amount * dis / 100);
                    total += discounted_amount;
                    cout << setw(10) << pcode << setw(20) << pname << setw(20) << arrq[i] << setw(10) << price << setw(10) << amount << setw(20) << discounted_amount << "\n";
                }
                data >> pcode >> pname >> price >> dis;
            }
            data.close();
        }
        cout << "_________________________________________________________________________\n";
        cout << " Total Amount: " << total << "\n";
    }
}
int main(){
    shopping s;
    s.menu();
}