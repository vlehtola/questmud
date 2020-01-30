object monsu;

init() {
 add_action("start", "push");
}

short() {
  return "tama on monsun cloonaus nappi. 'push button'";
}

get() { return 1; }

start(str) {
  if(str != "button") return;
  if(monsu) {
    write("monsu elaa viela\n");
    return 1;
  }
  monsu = clone_object("/world/monsters/ant1");
  move_object(monsu, "/wizards/morgoth/workroom");
  write("Monsu cloonattu.\n");
  return 1;
}
