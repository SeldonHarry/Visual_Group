#ifndef BASE_PARAM_PARAM_HPP
#define BASE_PARAM_PARAM_HPP
#include <cstdint>
#include <iostream>
#include <variant>
#include <string>
#include <vector>
#include <functional>

namespace param{
using Param = std::variant<bool, int64_t, double, std::string, std::vector<int64_t>>;
using ParamVisitor = std::function<void(const std::string &,Param & param)>;

template<typename T>
T get_param(const std::string & name,std::function<void(const std::string &,Param & param)> param_visitor)
{
    Param param = T();
    param_visitor(name,param);
    T* res = std::get_if<T>(&param);
    if(res == nullptr)
    {
        std::cout << "Parameter Type Error:" << name << std::endl;
        return T();
    }
    return *res;
}
}
#endif