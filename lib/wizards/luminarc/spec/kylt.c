reset(arg) {
  if(arg) return;
}
id(str) {
  return str == "paper";
}
get() {
  return 0;
}
query_weight() {
  return 1;
}
short() {
  return "Small paper with information";
}
long() {
  write("The goal of this event is to be a last man standing.\n"+
        "If you take 5 hits you are removed from the game.\n"+
        "You can make snowballs with command: make snowball.\n"+
        "At this room you can check who have been joined game\n"+
        "by typin who_event and join the game with join event\n"+
        "command. Good luck and let the best man win\n");
}

