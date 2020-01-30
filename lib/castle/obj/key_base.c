int code;

short() { return "Small iron key"; }

long() {
  write("The small iron key is quite dull grey, yet light.\n");
}

query_house_key() {
  return 1;
}

id(str) { if (str == "key" || str == "castle key") { return 1; } }

query_key_code() {
  return code;
}

set_key_code(str) { code = str; }

get() { return 1; }
