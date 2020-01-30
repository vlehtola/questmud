inherit "room/room";

  short_desc = "Jail\n.";
  long_desc = "This is a jail.\n";
                     

  


init() {
  ::init();
  add_action("quit", "quit");
}


quit(str) {
  if(str == "quit") {
    write("It's not that easy...\n");
    return 1;
 write("Idiot.\n");
  return 1;
} 

init() {
  ::init();
  add_action("ld", "ld");
}


quit(str) {
  if(str == "ld") {
    write("It's not that easy...\n");
    return 1;
 write("Idiot.\n");
  return 1;
}
