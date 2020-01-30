// the rock. written by C


string query_name() {
  return "line";
}

status get() { return 1; }

status id(string str) {
  return str == "line" || str == "old";
}

string short() {
  return "An old fishing line";
}

void long() {
  write("An old fishing line. It's about one and a half meters long.\n");
}

int query_value() {
  return 100;
}

int query_weight() {
  return 100;
}

query_no_save() { return 1; }
  
