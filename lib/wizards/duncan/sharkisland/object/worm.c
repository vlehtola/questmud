// the rock. written by C


string query_name() {
  return "worm";
}

status get() { return 1; }

status id(string str) {
  return str == "worm" || str == "juicy";
}

string short() {
  return "A juicy worm";
}

void long() {
  write("A juicy worm. Worms are often used as a bait for fishes.\n");
}

int query_value() {
  return 100;
}

int query_weight() {
  return 100;
}

query_no_save() { return 1; }
  
