// the rock. written by C


string query_name() {
  return "rock";
}

status get() { return 1; }

status id(string str) {
  return str == "rock" || str == "small";
}

string short() {
  return "A small rock";
}

void long() {
  write("A small-sized circular-shaped rock.\n");
}

int query_value() {
  return 200;
}

int query_weight() {
  return 400;
}

query_no_save() { return 1; }
  
