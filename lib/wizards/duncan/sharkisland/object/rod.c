// the rock. written by C


string query_name() {
  return "rod";
}

status get() { return 1; }

status id(string str) {
  return str == "rod" || str == "fishing";
}

string short() {
  return "A fishing rod";
}

void long() {
  write("A wooden fishing rod. It's about two meters long.\n");
}

int query_value() {
  return 100;
}

int query_weight() {
  return 100;
}

query_no_save() { return 1; }
  
