inherit "obj/weapon";

start() {
  set_class(10);
  set_sub_type("broad sword");
  set_name("claws");
  set_short("Freak's sharp claws");
  set_long("You should not be holding these claws.\n");
}

long() {
  destruct(this_object());
}
