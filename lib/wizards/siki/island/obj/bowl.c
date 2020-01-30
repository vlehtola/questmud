string short_desc, long_desc, alias, name;
int value, weight;

reset() {
  name = "bowl";
  alias = "empty bowl";
  short_desc = "An empty bowl";
  long_desc = "An empty wooden bowl.\n";
  value = 1;
  weight = 1;
}
get() { return 1; }

id(str) { return str == name || str == alias || str == short_desc; }
short() { return short_desc; }

long() { write(long_desc); }


