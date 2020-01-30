inherit "obj/monster";
int door_tried = 0;

id(str) { return str == "spec"; }

catch_tell(str) {
  string tmp,tmp2;
  if(door_tried == 0) {
  if(sscanf(str,"%s says %s",tmp,tmp2) == 2) {
  call_out("hopo", 3);
  }
  }
}

hopo() {
  say("You hear the guard whispering: 'Ah, at last. I was sure those things would\n" +
        "come and slay me just like they did to the others. Wait, I'll open the\n" +
        "the door for you.'\n" +
        "You hear a key turning in a lock and soon the door opens with a loud\n" +
        "creaking sound.\n");
  call_other("/wizards/ahma/castle/rooms/area07", "add_exit", "south", "/wizards/ahma/castle/rooms/area08");
  door_tried = 1;  
  return 1;
}
