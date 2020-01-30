// the rock. written by C


string query_name() {
  return "head";
}

status get() { return 1; }

status id(string str) {
  return str == "head" || str == "bloody";
}

string short() {
  return "A bloody head";
}

void long() {
  write("Fresh blood is still dripping from the head. There are intestines hanging\n"+
        "from the head. The head belongs to the executioner. Finally, someone killed\n"+
        "him.\n");
}

int query_value() {
  return 0;
}

int query_weight() {
  return 200;
}

query_no_save() { return 1; }
  
