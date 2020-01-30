inherit "obj/weapon"; 
 
start() {
    set_class(1);
    set_sub_type("staff");
    set_short("A Jedi Light-Saber");
    set_long("The Jedi light-saber is now reduced to nothing more than a \n"+
                "handle. It glows in a strange light, making you feel secure\n"+
                "with it. You notice buttons labeled 'On' and 'Off'.\n");
}
 
int swmuoto;
 
init() {
  ::init();
  add_action("on", "on");
  add_action("off", "off");
}
 
on() {
  if(swmuoto) {
  write("Moron, it's already on.\n");
  return 1;
} else {
  set_class(10);
  set_sub_type("long sword");
  set_short("A Jedi Light-Saber, dangerous mode");
  write("As you press the button, a glowing blade appears with a 'Wooosh'.\n");
  say(this_player()->query_name()+" reveals a glowing blade with a 'Wooosh'.\n");
  swmuoto = 1;
  return 1;
    }

 }               
 
off() {
  if(swmuoto) {
  set_class(1);
  set_sub_type("staff");
  set_short("A Jedi Light-Saber");
  write("As you press the button, the blade quickly dissappears.\n");
  say(this_player()->query_name()+" turns the sabre off.\n");
  swmuoto = 0;
  return 1;
} else {
 write("Nothing seems to happen.\n");
  return 1;
  }
}

