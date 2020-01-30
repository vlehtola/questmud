inherit "room/key";

id(str) { if (str == "key") return 1; }

short() { return "A huge iron key"; }

long() { write("The key is made of iron and is quite heavy. The key looks to be too big to\n"+
 "fit to an ordinary door lock.\n"); }

reset() {
 set_door_file("/wizards/rimber/hell/entrance.c");
 set_key_code("666");
}
get() { return 1;}

query_weight() { return 5; }
