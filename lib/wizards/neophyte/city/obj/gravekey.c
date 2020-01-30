inherit "room/key";

id(str) { if (str == "key") return 1; }

short() { return "A bone key"; }

long() { write("The key is made of bone.\n"); }

get() { return 1; }

reset() {
set_key_code("4632");
}

query_name() { return "key"; }
query_long() { return "The key is made of bone"; }

query_weight() { return 500; }
