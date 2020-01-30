// the rock. written by C


string query_name() {
  return "rock";
}

status get() { return 1; }

status id(string str) {
  return str == "rock" || str == "medium";
}

string short() {
  return "A medium rock";
}

void long() {
  write("A medium-sized circular-shaped rock.\n");
}

int query_value() {
  return 400;
}

int query_weight() {
  return 700;
}

query_no_save() { return 1; }
  
