string name;

id(str) {
  if (str == ("reinc_from_"+name)) { return 1; }
}

set_accept(str) {
  name = str;
}
