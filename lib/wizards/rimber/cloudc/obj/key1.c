inherit "room/key";

id(str) { if (str == "key") return 1; }

short() { return "A black obsidian key"; }

long() { write("The key is made of obsidian and it's big and heavy.\n"); }

reset() {
 set_door_file("/wizards/rimber/cloudc/room35.c");

 set_key_code("101");
}
get() { return 1;}
