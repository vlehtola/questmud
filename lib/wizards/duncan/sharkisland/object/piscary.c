// the rock. written by C


string query_name() {
  return "piscary";
}

status get() { return 1; }

status id(string str) {
  return str == "piscary" || str == "fishing";
}

string short() {
  return "A fishing piscary";
}

void long() {
  write("A piece of paper. Someone has written your name on it.\n");
}

int query_value() {
  return 2000;
}

int query_weight() {
  return 100;
}

query_no_save() { return 1; }
  
