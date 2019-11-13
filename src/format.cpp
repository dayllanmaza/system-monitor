#include "format.h"

#include <iomanip>
#include <sstream>
#include <string>

using std::setfill;
using std::setw;
using std::string;

string Format::ElapsedTime(long seconds) {
  int hh, mm, ss;

  // ASK: is there a date library that's standard in the industry
  //      that could handle this math?
  hh = seconds / 3600;
  mm = seconds % 3600 / 60;
  ss = seconds % 3600 % 60;

  // ASK: is there a cleaner way to do this
  std::stringstream hhs, mms, sss;
  hhs << setw(2) << setfill('0') << hh;
  mms << setw(2) << setfill('0') << mm;
  sss << setw(2) << setfill('0') << ss;

  return hhs.str() + ':' + mms.str() + ':' + sss.str();
}