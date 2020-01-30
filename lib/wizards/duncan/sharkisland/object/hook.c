// the rock. written by C


string query_name() {
  return "hook";
}

status get() { return 1; }

status id(string str) {
  return str == "hook" || str == "rusty";
}

string short() {
  return "A rusty hook";
}

void long() {
  write("A rusty hook. It's sharp and shaped as the letter 'J'.\n");
}

int query_value() {
  return 100;
}

int query_weight() {
  return 100;
}

query_no_save() { return 1; }
  
