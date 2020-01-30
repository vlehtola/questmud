inherit "room/key";

id(str) { if (str == "key") return 1; }

short() { return "A beautiful silver key"; }

long() { wirte("A beautifully crafted silver key. The key looks very fracile.\n"); }

reset() {
 set_door_file("/wizards/rimber/cloudc/room36.c");

 set_key_code("222");
}
get() { return 1;}
