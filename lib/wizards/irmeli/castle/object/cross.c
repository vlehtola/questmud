// the rock. written by C


string query_name() {
  return "cross";
}

status get() { return 1; }

status id(string str) {
  return str == "cross" || str == "black";
}

string short() {
  return "Cross of the Knights";
}

void long() {
  write("The cross of the Knights. It's made of gold. A huge horse is\n"+
        "carved on it. The cross if hanging from the brown string.\n"+
        "It belongs to the McArthur family.\n");
}

int query_value() {
  return 0;
}

int query_weight() {
  return 200;
}

query_no_save() { return 1; }
  
