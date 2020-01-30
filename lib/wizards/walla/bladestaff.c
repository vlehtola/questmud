inherit "obj/weapon";

start() {
    set_class(4);
    set_sub_type("staff");
    set_short("A beautiful oaken staff");
    set_long("A thick, beautiful oaken staff, slightly ressembling the\n"+
                "staff of a sheperd. There is some kind of a mechanism on it\n"+
                "it seems. You notice buttons labeled 'Sword' and 'Staff'.\n");
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
  set_short("An oaken staff with a long blade extracted from it");
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

