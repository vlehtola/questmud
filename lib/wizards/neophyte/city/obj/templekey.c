inherit "room/key";

id(str) { if (str == "key") return 1; }

short() { return "A iron key"; }

long() { write("The key is made of iron.\n"); }

get() { return 1; }

reset() {
set_key_code("124");
}
