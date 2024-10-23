#include<bits/stdc++.h>
using namespace std;
struct sv
{
    string ma, ten, lop, ns;
    double gpa;

    void in()
    {
        cout<<"------------------------------------\n";
        cout<<"Ma sv:"<<ma<<endl;
        cout<<"Ten:"<<ten<<endl;
        cout<<"Lop:"<<lop<<endl;
        cout<<"Ngaysinh:"<<ns<<endl;
        cout<<"GPA:"<<fixed<<setprecision(2)<<gpa<<endl;
        cout<<"------------------------------------\n";
    }
    void nhap()
    {
        cout<<"Nhap msv:"; cin>>ma;
        cout<<"Nhap ten:";
        cin.ignore();
        getline(cin, ten);
        cout<<"Nhap lop:"; cin>>lop;
        cout<<"Nhap ngay sinh:"; cin>>ns;
        cout<<"GPA:"; cin>>gpa;
    }
};

void inds(sv a[], int n)
{
    cout<<"Thong tin dssv:\n";
    for(int i=0; i<n; i++)
    {
        a[i].in();// in ra thong tin thu i
    }
}
//"abcdefabc".find("abc")-tim chuoi con =>in ra mang dau tien
// khong tim thay  tra ve : string::npos
void tkma(sv a[], int n)
{
    string ma;
    cout<<"Nhap ma sv can tim:"; cin>>ma;
    bool found=false;
    for(int i=0; i<n; i++)
    {
        // neu in ra tat ca xau con( vd: 2018xxxx)
       /* if(a[i].ma.find(ma) != string::npos)
        {
            //tim thay
            a[i].in();
            found=true;// da tim thay
        }*/
        if(ma==a[i].ma)
        {
            a[i].in(); return;
        }
    }
   // if(!found)
    cout<<"Khong tim thay\n";
}
// co the dung nhu ben duoi
/*void in(sv,a)
{
     cout<<"------------------------------------\n";
        cout<<"Ma sv:"<<a.ma<<endl;
        cout<<"Ten:"<<a.ten<<endl;
        cout<<"Lop:"<<a.lop<<endl;
        cout<<"Ngaysinh:"<<a.ns<<endl;
        cout<<"GPA:"<<fixed<<setprecision(2)<<a.gpa<<endl;
        cout<<"------------------------------------\n";
}
  void nhap1 1(sv &a)
  {
        cout<<"Nhap msv:"; cin>>a.ma;
        cout<<"Nhap ten:";
        cin.ignore();
        getline(cin, a.ten);
        cout<<"Nhap lop:"; cin>>a.lop;
        cout<<"Nhap ngay sinh:"; cin>>a.ns;
        cout<<"GPA:"; cin>>a.gpa;
    }
/////hoac la:
sv nhap2(){
        cout<<"Nhap msv:"; cin>>a.ma;
        cout<<"Nhap ten:";
        cin.ignore();
        getline(cin, a.ten);
        cout<<"Nhap lop:"; cin>>a.lop;
        cout<<"Nhap ngay sinh:"; cin>>a.ns;
        cout<<"GPA:"; cin>>a.gpa;
        return a;
    }
*/
void lkgpa(sv a[], int n)
{
    double res=0;
    for(int i=0; i<n; i++)
    {
        if(a[i].gpa>res) res=a[i].gpa;
    }
    cout<<"Ds sv co gpa cao nhat:\n";
    for(int i=0;i<n;i++)
    {
        if(res==a[i].gpa)
        {
            a[i].in();
        }
    }
}

bool cmp1(sv a, sv b)
{
    return a.gpa>b.gpa;
}
void lkgpa2(sv a[], int n)
{
    vector<sv> v;
    for(int i=0; i<n; i++)
    {
        if(a[i].gpa>=2.5) v.push_back(a[i]);
    }
    sort(v.begin(), v.end(), cmp1 );
    cout<<"Ds sv gpa >=2.5\n";
    for(sv x:v)
    {
        x.in();
    }
}

vector<string> chuanhoa(string name)
{
    stringstream ss(name); vector<string> v;
    string token;
    while(ss>>token)
    {
        v.push_back(token);
    }
    return v;
    //noi dung: hoang van anh-> tra ve: anhhoangvan
}
//sx ten sv theo thu tu diem tang dan
bool cmp2(sv a, sv b)
{
vector<string> v1=chuanhoa(a.ten), v2=chuanhoa(b.ten);
if(v1.back() !=v2.back()) return v1.back()<v2.back();
int len1=v1.size(), len2=v2.size();
for(int i=0;i<min(len1,len2); i++)
{
    if(v1[i] !=v2[i]) return v1[i]<v2[i];
}
return len1<len2;
}
void sxten(sv a[], int n)
{
    sort(a,a+n,cmp2);
}
int main()
{
    /*
    //voi void nhap1
    sv a;
    nhap(a);
    // void nhap2
    sv a= nhap();*/

    sv a[1000];
    int n;//luu so sinh vien
    while(1)
    {
        cout<<"--------------MENU--------------\n";
        cout<<"1.Nhap thong tin sv\n";
        cout<<"2.Hien thi toan bo danh sach sinh vien\n";
        cout<<"3.Tim kiem sinh vien theo ma\n";
        cout<<"4.lksv co diem gpa cao nhat\n";
        cout<<"5.lkcac sv co diem gpa >=2.5\n";
        cout<<"6.sxsv theo ten\n ";
        cout<<"0.Thoat !\n";
        cout<<"-----------------------------\n";
        cout<<"Nhap lua chon:\n";
        int lc; cin>>lc;
        if(lc==1)
        {
            a[n].nhap();
            ++n;
        }
        else if(lc==2)
        {
            inds(a,n);
        }
        else if(lc==3)
        {
            tkma(a,n);
        }
        else if(lc==4)
        {
            lkgpa(a,n);
        }
        else if(lc==5)
        {
            lkgpa2(a,n);
        }
        else if(lc==6)
        {
            sxten(a,n);
        }
        else if(lc==0)
        {
            break;
        }
    }

    return 0;
}
