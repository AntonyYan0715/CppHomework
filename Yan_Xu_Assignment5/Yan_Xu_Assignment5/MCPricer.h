#ifndef MCPRICER_H
#define MCPRICER_H
#include "Option.h"

class MCPricer {
public:
    double Price(const Option& option, double stockPrice, double vol, double rate, unsigned long paths);
};

#endif