inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/geri");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("east","wizards/nalle/workroom");
  short_desc = "In a tropical forest";
  long_desc =
"You are in a tropical forest, under a big banana \n" +
"tree. It seems to have fruit in it.\n";
}

init() {
    ::init();
   add_action("shake", "shake");
}

shake(arg) {
   write("You shake the tree vigorously and a banana drops down. \n");
   say(call_other(this_player(), "query_name", 0) +" makes bananas fall out of a tree.\n");
   move_object("wizards/nalle/banaani.c", this_player());
   return 1;
}

