/*************************************************************************
	> File Name: 2.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年04月04日 星期四 19时41分41秒
 ************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

shared_ptr<IValue> String::__operator(shared_ptr<IValue> &obj, int opr_type) {
    switch (opr_type) {
        case PLUS: {
            ConverYoStringVisitor v;
            obj->Accept(&v);
            shared_ptr<StringValue> ret(new StringValue(this->getValue() + v.getResult()));
            return ret;
        } break;
        case TIMES: {
            IntValue *_obj = dynamic_cast<IntValue *>(obj.get());
            if (_obj == nullptr) throw runtime_error("operator * must between string and int");
            shared_ptr<StringValue> ret(new StringValue());
            for (int i = 0; i < _obj->getValue(); i++) {
                ret->str += this->str;
            }
            return ret;
        } break;
        case MINUS: {
            StringValue *_obj = dynamic_cast<StringValue *>(obj.get());
            if (_obj == nullptr || _obj->str.size()) throw runtime_error("operator - must between string and string(1)");
            shared_ptr<StringValue> ret(new StringValue());
            for (int i = 0; i < this->str.size(); i++) {
                if (this->str[i] == _obj->str[0]) continue;
                ret += this->str[i];
            }
            return ret;
        } break;
    }
}
