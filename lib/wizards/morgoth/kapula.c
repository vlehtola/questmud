reset(arg) {
  if(arg) return;
}

init() {
  add_action("west", "w");
  add_action("east", "e");
  add_action("north", "n");
  add_action("south", "s");
  add_action("look", "l");
  add_action("fin", "fin");
  add_action("mud", "mud");
  add_action("score", "score");
}

west() {
  write("Don't do that!\n");
}

east() {
  write("East is no good!\n");
}

north() {
  write("Are you crazy?\n");
}

south() {
  write("You can't do that!\n");
}

look() {
  write("You can see FLOWERS!\n");
}

fin() {
  write("Speak english dummy!\n");
}

mud() {
  write("MUD, MUD AND MUD, can't you think anything else?\n");
}

score() {
  write("Stats: 0 0 0 0 0 0 0 0, Scary? Isn't it...\n");
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
