#pragma once

#include <vector>
#include <map>
#include <string>

double average(std::vector<std::pair<unsigned long, double>>);
std::map<std::string, double> averages(
    std::vector<std::pair<std::string, std::pair<unsigned long, double>>>);
