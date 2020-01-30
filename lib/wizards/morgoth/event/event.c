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
  monsu = clone_object("/wizards/morgoth/can");
  move_object(monsu, "/wizards/morgoth/workroom");
  shout("Town crier shouts: Gypsies has arrived! \n");
  return 1;
}

