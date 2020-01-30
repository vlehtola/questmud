reset(arg) {
if (arg) return;
}

init() {
  add_action("command", "command");
  add_action("inventory", "i");
  add_action("give", "give");
  add_action("cast", "cast");
  add_action("west", "west");
  add_action("east", "east");
  add_action("north", "north");
  add_action("south", "south");
  add_action("look", "l");
  add_action("fin", "fin");
  add_action("mud", "mud");
  add_action("kill", "kill");
}

command() {
  write("Noh Noh!\n");
  return 1;
}

inventory() {
 write("You are BLIND!\n");
 return 1;
}

give() {
 write("Laf\n");
 return 1;
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
  write("Buahahahah...\n");
  return 1;
}

short() {
 return "Thingie";
 } 
id(str) {
  return str == "thingie";
 }

long() {
  write("This is the thingie.\n");
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
