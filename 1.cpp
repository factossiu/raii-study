#include<iostream>
#include<fstream>
#include<limits>
using namespace std;
class file_operator_write{
    ofstream file;
public:
    //构造函数
    file_operator_write(const string &file_path,int &open_mode){
     if(open_mode == 1){
        this->file.open(file_path,ios::out | ios::trunc); 
     }
     else{
        this->file.open(file_path,ios::out | ios::app);
     }
    }
    file_operator_write(){}
    //析构函数
    ~file_operator_write(){
        this->file.close();
        cout<<"文件关闭"<<endl;
    }

    //获取文件对象
    ofstream& get_file(){
        return file;
    }

    //判断打开是否成功
    bool open_success(){
        return file.is_open();
    }

    //写入数据
    void write_data(){
        string str;
        cout << "请输入你要输入文件的内容:"<<endl;
        // 使用getline读取整行，包括空格
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(cin, str);
        this->file << str;
        cout<<"写入操作完成"<<endl;
    }
    
};

class file_operator_read{
    ifstream file;
public:
    file_operator_read(){}
    file_operator_read(const string& filepath);
    ~file_operator_read()
    {
        this->file.close();
    }
    bool open_success()
    {
        return this->file.is_open();
    }

    void read_data()
    {
    //使用getline读取文件数据
        if(this->open_success())
        {
            string line;
            while(getline(this->file,line))
            {
                cout<<line<<endl;
            }
        }
        else
        {
            cerr<<"打开失败"<<endl;
        }
    }

    ifstream &get_file()
    {
        return this->file;    
    }
};
file_operator_read::file_operator_read(const string& filepath){
    this->file.open(filepath);//直接使用默认模式打开文件
}

void WriteControl(const string &filepath)
{
    int open_mode;
    cout<<"按1以覆盖模式打开,2为追加模式打开"<<endl;
    cin>>open_mode;
    if(open_mode > 2 || open_mode < 1){
        cout<<"输入错误"<<endl;
        return;
    }
    file_operator_write write_file_object(filepath,open_mode); 
    
    if(!write_file_object.open_success()){
        cout<<"打开失败"<<endl;
    }
    else{//打开成功写入文件
        write_file_object.write_data();
    }

}
void ReadControl(const string &filePath)
{

    file_operator_read read_file_object(filePath);
    read_file_object.read_data();
}
int main(){

    int item;
    string filePath;
    cout<<"1选择写文件，2选择读文件"<<endl;
    cin>>item;
    cout<<"请输入文件名"<<endl;
    cin>>filePath;
    switch (item)
    {
    case 1: 
        WriteControl(filePath);
        break;
    case 2:
        
        ReadControl(filePath);
        break;
    default:
        break;
    }  

}