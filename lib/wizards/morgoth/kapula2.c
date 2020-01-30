  reset(arg) {
  if(arg) return;
}

init() {
  add_action("cast", "cast"); 
  add_action("west", "w");
  add_action("east", "e");
  add_action("north", "n");
  add_action("south", "s");
  add_action("look", "l");
  add_action("fin", "fin");
  add_action("mud", "mud");
  add_action("score", "score");
}

cast() {
 write("You are idiot, you cannot cast spells!\n");
 return 1;
}

west() {
 write("You are handicap, you cannot walk.\n");
 return 1;
}

east() {
  write("You are handicap, you cannot walk.\n");
 return 1;
}

north() {
  write("You are handicap, you cannot walk.\n");
  return 1;
}

south() {
  write("You are handicap, you cannot walk.\n");
  return 1;
}

look() { 
 write("You are BLIND! \n");
 write("This is a punishment from your crimes.\n");
 return 1;
}

fin() {
  write("You are mute.\n");
  return 1;
}

mud() {
  write("You are mute.\n");
  return 1;
}

score() {
  write("Sorry, we can't accept that.\n");
}

short() { 
 return "Kapula";
 }


id(str) {
  return str == "kapula";
 }

long() {
  write("This is the kapula.\n");
}


drop() {
  return 0;
} 
get() {
  return 1;
}


query_weight() {
  return 1;
}
