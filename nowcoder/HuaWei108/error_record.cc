/*
 * @Author: xuhuanhuan 
 * @Date: 2020-02-25 20:17:17 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-02-26 00:07:17
 *
 *华为机试在线训练--简单错误记录
 */

#include <sstream>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

//! get_filename(const string &IN_cstr)为什么不可以写成get_filename(const string &IN_cstr, string &OUT_filename)?
//! 因为传入的OUT_filename需要有足够的空间完成赋值，而在调用get_filename()函数前，我们并不能保证做到这一点，所以只能
//!写成传出参数的形式。
string get_filename(const string &IN_cstr){
    size_t last_idx = IN_cstr.find_last_of("\\");
    size_t len = IN_cstr.size();
    if(last_idx != string::npos){
        if(len - last_idx > 16){
            return IN_cstr.substr(len-16,16);
        }else{
            return IN_cstr.substr(last_idx+1);
        }
    }
}

//! 当需求无法使用库中的数据结构很好的完成任务时，就需要考虑自己重新设计类了。
//! 例如这个题目中必须要同时存储filename, error_line以及error_num。并且还需要
//! 判断相等和自增操作。所以，这里需要定义一个error_Node类。
struct error_Node{
    error_Node(const string &_filename, const size_t error_line)
    :filename(_filename)
    ,error_line(error_line)
    ,error_num(1)
    {}

    string filename;
    size_t error_line;
    size_t error_num;
    bool operator==(const error_Node &lhr){
        if(lhr.filename == filename && lhr.error_line == error_line)
            return true;
        return false;
    }
    error_Node& operator++()
    {
        ++error_num;
        return *this;
    }

   friend ostream &operator<<(ostream &os, const error_Node& error_node);
};

ostream &operator<<(ostream &os, const error_Node& error_node)
{
    os << error_node.filename << " " << error_node.error_line << " " << error_node.error_num;
    return os;
}
int main()
{
    string filename;
    size_t num;
    //!难点：采用什么样的数据结构存储数据才可以很方便的实现
    vector<error_Node> data;
    while(cin >> filename >> num){
        string res(get_filename(filename));
        error_Node tmp(res,num);
        //! find方法的传出参数不可以使用auto & i = find(...)。来接收。
        auto it_find = find(begin(data), end(data), tmp);
        if(it_find != data.end()){
            ++(*it_find);
        }else{
            data.push_back(tmp);
        }
    }
    size_t start = data.size() > 8? data.size() - 8 : 0;
    for(size_t i = start; i < data.size(); ++i){
        cout << data[i] << endl;
    }
    return 0;
}