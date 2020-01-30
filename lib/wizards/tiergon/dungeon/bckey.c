inherit "room/key";

id(str) { if (str == "key") return 1; }

short() { return "A black key"; }

long() { 
write("The grasp of the key looks roughly like a skull.\n"); 
}
 
reset() {
  set_door_file("/wizards/tiergon/dungeon/b10");
}

get() { return 1; }

