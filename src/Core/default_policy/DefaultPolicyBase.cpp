#include <DefaultPolicyBase.h>

DefaultPolicyBase::DefaultPolicyBase(EnvironmentInterface &environment)
    : _environment(environment), generator(std::mt19937(time(nullptr))){};
