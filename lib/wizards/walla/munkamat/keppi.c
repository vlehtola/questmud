inherit "obj/weapon";
 
start() {
    set_class(5);
    set_sub_type("club");
    set_short("The Staff of Magius");
    set_long("woutsi wou\n"+
             "You have raistlinin keppi\n"+
             "in your hand.\n"+
             "For those who have read the Dragonlance books, you know how to make it light up,\n"+
             "for those that haven't, tough luck.\n");
}
 
int swmuoto;
 
init() {
  ::init();
  add_action("shirak", "shirak");
  add_action("dulak", "dulalk");
}
 
shirak() {
  if(swmuoto) {
  write("Keppi has light mode on.\n");
  return 1;
} else {
  set_light(3);
  write("The staff starts to glow with an eerie light\n");
  say(this_player()->query_name()+" whispers a magic word, and the staff lights up.\n");
  swmuoto = 1;
  return 1;
    }
}
 
dulak() {
  if(swmuoto) {
  write("keppivalo pois?.\n");
  say(this_player()->query_name()+" makes the light go out.\n");
  set_light(-3);
  swmuoto = 0;
  return 1;
} else {
 write("The keppi has no light.\n");
  return 1;
  }
}
