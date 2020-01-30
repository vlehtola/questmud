inherit "room/key";

id(str) { if (str == "key") return 1; }

short() { return "A black iron key"; }

long() { write("A black iron key. The flap on the key is decorated with a skull carving.\n"); }

reset() {
 set_door_file("/wizards/rimber/cloudc/room35.c");
 set_key_code("020");
}
get() { return 1;}
