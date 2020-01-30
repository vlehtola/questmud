string short_desc, long_desc, alias, name;    
int value, weight;

reset() {
  name = "gold";
  alias = "gold ore";
  short_desc = "A piece of gold";
  long_desc = "A small piece of gold\n";
  value = 100;
  weight = 1;
}
get() { return 1; }

id(str) { return str == name || str == alias || str == short_desc; }
short() { return short_desc; }

long() { write(long_desc); }
