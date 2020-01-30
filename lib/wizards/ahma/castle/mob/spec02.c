inherit "obj/monster";
int entrances_open = 0;

id(str) { return str == "spec"; }

catch_tell(str) {
  string tmp,tmp2;
  if(entrances_open == 0) {
  if(sscanf(str,"%s arrives %s",tmp,tmp2) == 2) {
  call_other("/wizards/ahma/castle/rooms/area35h", "add_exit", "hole", "/wizards/ahma/castle/rooms/area35i");
  call_other("/wizards/ahma/castle/file1","set_new_value",1);
  say("As you arrive the room, you can spot a small pair of glowing eyes staring at\n" + 
      "you from down, from where the warm air floats in. After a moment, the eyes\n" + 
      "disappear, followed by a set of scooting sounds made by a running creature.\n");
  entrances_open = 1;
  return 1;
  }
  }
}

