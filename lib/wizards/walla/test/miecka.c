inherit "obj/weapon";
 
start() {
    set_class(6);
    set_sub_type("staff");
    set_short("A beautifully carved walking staff");
    set_long("This staff is beautifully carved out of a bonsai tree. It has some strange\n"+
             "markings on it. As you search closer, you find a blade, well concealed \n"+
             "inside the staff.\n");
}
 
int swmuoto;
 
init() {
  ::init();
  add_action("sword", "sword");
  add_action("staff", "staff");
}
 
sword() {
  if(swmuoto) {
  write("The device will not function. Perhaps it is because the blade is already visible.\n");
  return 1;
} else {
  set_class(6);
  set_sub_type("sabre");
  set_short("The Tobidashinaifu");
  write("You quickly draw the sabre out of it's hilt.\n");
  say(this_player()->query_name()+" quickly draws a sabre out of it's hilt.\n");
  swmuoto = 1;
  return 1;
    }
}
 
staff() {
  if(swmuoto) {
  set_class(4);
  set_sub_type("staff");
  set_short("A beautifully carved walking staff");
  write("You quickly insert the sabre back into the hilt.\n");
  say(this_player()->query_name()+" quickly conceals the sabre into the cane.\n");
  swmuoto = 0;
  return 1;
} else {
 write("Nothing seems to happen.\n");
  return 1;
  }
}
