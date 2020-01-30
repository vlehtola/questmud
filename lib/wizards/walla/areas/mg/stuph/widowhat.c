inherit "obj/armour";

start() {
set_class(2);
    set_sub_type("cap");
    set_name("hat");
    set_alias("hat");
    set_short("A black hat with a veil");
    set_long("The black hat you see, is one that mourning widows usually\n"+
             "wear at funerals and when mourning. The hat has a veil, that\n"+
             "you can veil and unveil your face with");
    set_value(50);
    set_weight(3);
}


int swmuoto;

init() {
  ::init();
  add_action("veil", "veil");
  add_action("unveil", "unveil");
}

veil() {
  if(swmuoto) {
  write("The veil is already down.\n");
  return 1;
} else {
  write("You veil your face with the fabric.\n");
  say(this_player()->query_name()+" veils "+this_player()->query_possessive()+" face.\n");
  swmuoto = 1;
  return 1;
    }
}

unveil() {
  if(swmuoto) {
  write("You unveil your face.\n");
  say(this_player()->query_name()+" unveils "+ this_player()->query_possessive()+" face.\n");
  swmuoto = 0;
  return 1;
} else {
 write("But your face is not veiled.\n");
  return 1;
  }
}

