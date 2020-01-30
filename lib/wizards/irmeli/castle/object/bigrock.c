// the rock. written by C


string query_name() {
  return "rock";
}

status get() { return 1; }

status id(string str) {
  return str == "rock" || str == "big";
}

string short() {
  return "A big rock";
}

void long() {
  write("A big-sized rock. It's circular.\n");
}

int query_value() {
  return 600;
}

int query_weight() {
  return 1000;
}

query_no_save() { return 1; }
  
