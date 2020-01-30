id(str) {
  return str == "potion";
}
short() {
  return "A free-reinc potion";
}
long() {
  write("In your hands, you hold a most powerful tonic. It seems that by\n");
  write("drinking this potion, you may get reincarnated free of cost.\n");
  write("testing \n");
  write("testing.\n");
}
query_weight() {
  return  1;
}
get() {
  return 1;
}


init() {
  add_action("slurp", "slurp");
}

slurp(str) {
if(str != "potion") return;
write("You slurp the potion, and find yourself in a totally different location.\n");
  move_object(this_player(), "/world/special/free_reinc_room");
call_out("nuke", 1);
return 1;
}

nuke() {
destruct(this_object());
return 1;

}

