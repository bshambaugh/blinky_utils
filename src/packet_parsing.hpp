#include <cstring>
#include <iostream>
using namespace std;

#pragma once

void parse_packet(const string *source, string *type, string *curve, string *payload);

void parse_packet(const string *source, string *type, string *curve, string *payload) {
  *type = (*source).substr(0,1);
  *curve = (*source).substr(1,4);
  *payload = (*source).substr(5,(*source).length());
}
