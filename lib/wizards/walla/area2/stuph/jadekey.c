inherit "room/key";
 
id(str) { if (str == "key") return 1; }
 
short() { return "A jade key"; }
 
long() { write("The key is made of jade.\n"); }
 
reset() {
  set_door_file("/wizards/walla/area2/rooms/ricefield/28.c");
}
 
get() { return 1; }
