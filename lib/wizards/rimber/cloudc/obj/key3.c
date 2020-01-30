inherit "room/key";

id(str) { if (str == "key") return 1; }

short() { return "A beautiful white steel key"; }

long() { write("The key is made of steel and it's painted white.\n"); }

reset() {
 set_door_file("/wizards/rimber/cloudc/room36.c");

 set_key_code("878");
}
get() { return 1;}
