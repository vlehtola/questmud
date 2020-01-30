inherit "room/key";

id(str) { if (str == "key") return 1; }

short() { return "A bronze key"; }

long() { write("The key is made of bronze and it has a small name on 'lowie'.\n"); }
query_long() { return "The key is made of bronze and it has a small name on 'lowie'"; }
get() { return 1; }
query_weight() { return 1000; }

reset() {
set_key_code("112");
}
