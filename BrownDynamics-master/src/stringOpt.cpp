#include "stringOpt.h"

/// separate Word
int separateWord(vector<string>& w, string t){

    w.clear();
    //convert all unvisible charater into space;
    for(unsigned ix = 0; ix < t.size(); ++ix){
	char ch_t = t[ix];
	if(ch_t < 33 or ch_t > 126) t[ix] = 32;
    }

    vector<string> words_t;
    string::size_type pos = 0, prev_pos = 0;
    while((pos = t.find_first_of(' ',pos)) != string::npos){
	words_t.push_back(t.substr(prev_pos,pos - prev_pos));
	prev_pos = ++pos;
    }
    words_t.push_back(t.substr(prev_pos, pos - prev_pos));
    for(vector<string>::iterator it = words_t.begin();it != words_t.end();++it){
	string s_t = *it;
	if(s_t.size() != 0) w.push_back(s_t);
    }
    return w.size();
}

/// trim string
string Ltrim(const string& str){
    size_t pos = str.find_first_not_of(" \n\r\t");
    if(pos != string::npos)
	return str.substr(pos);
    else
	return "";
}

string Rtrim(const string& str){
    size_t pos = str.find_last_not_of(" \n\r\t");
    if(pos != string::npos)
	return str.substr(0,pos+1);
    else
	return "";
}

string trim(const string& str){
    return Ltrim(Rtrim(str));
}

/// output the suffix of filename

string chgsuffix(const string& nm, const string& suf){
    return nm.substr(0,nm.find_last_of('.')+1) + suf;
}

string getsuffix(const string& nm){
    return nm.substr(nm.find_last_of('.')+1);
}

/// upping and lower the charater
string toUpper(const string& s){
    string ss;
    for(const auto &ch : s)
        ss.push_back(toupper(ch));
    return ss;
}

string toLower(const string& s){
    string ss;
    for(const auto &ch : s)
        ss.push_back(tolower(ch));
    return ss;
}

void addsuffix(string& str, char c){
    string::iterator iter=str.end();
    if(*(--iter) != c)
	str += c;
}

long getFileSize(const string& filename){
    struct stat fileInfo;
    if(stat(filename.c_str(), &fileInfo)!=0)
	return -1;
    return fileInfo.st_size;
}
