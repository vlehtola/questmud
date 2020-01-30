inherit "obj/weapon";
 
start() {
    set_class(6);
    set_sub_type("staff");
    set_short("A beautifully carved walking cane");
    set_long("This cane is beautifully carved out of a bonsai tree. It has some strange\n"+
             "markings on it. As you search closer, you find a button well concealed\n"+
             "in the tree.\n");
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
  set_sub_type("long sword");
  set_stats("dex",10);
    set_stats("wis",10);
    set_stats("con",10);
    set_stats("int",10);
    set_stats("str",10);
    set_stats("hpr",10);
    set_stats("spr",10);
  set_short("The Tobidashinaifu");
  write("You trigger a mechanism which reveals a long blade.\n");
  say(this_player()->query_name()+" works a device on his staff, revealing a long blade.\n");
  swmuoto = 1;
  return 1;
    }
}
 
staff() {
  if(swmuoto) {
  set_class(4);
  set_sub_type("staff");
  set_short("A beautiful oaken staff");
  write("The blade is promptly concealed within the staff.\n");
  say(this_player()->query_name()+" conceals the blade on his staff.\n");
  swmuoto = 0;
  return 1;
} else {
 write("Nothing seems to happen.\n");
  return 1;
  }
}
 
