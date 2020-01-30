inherit "room/room";
object mob;
int h, alive;

reset(arg) {
  add_exit("north", "/wizards/ahma/orc/forest/for19");
  add_exit("south", "/wizards/ahma/orc/village/vil21");
  short_desc = "On a soft path leading to a small village";

  h = random(6);
  if(!mob) {
  if(!alive) {
    if(h==0) { move_object(mob = clone_object("/wizards/ahma/orc/mob/bear02"), this_object()); alive = 1; }
    if(h==1) { move_object(mob = clone_object("/wizards/ahma/orc/mob/hunter"), this_object()); }
    if(h==2) { move_object(mob = clone_object("/wizards/ahma/orc/mob/jogger"), this_object()); alive = 1; }
    if(h==3) { move_object(mob = clone_object("/wizards/ahma/orc/mob/lynx"), this_object()); alive = 1; }
    if(h==4) { move_object(mob = clone_object("/wizards/ahma/orc/mob/walker02"), this_object()); alive = 1; }
    if(h==5) { move_object(mob = clone_object("/wizards/ahma/orc/mob/moose"), this_object()); }
  }
  }
}

init() {
  int i;
  ::init();
  i = random(5);
  if(i==0) { long_desc = read_file("/wizards/ahma/orc/forest/fordesc01"); }
  if(i==1) { long_desc = read_file("/wizards/ahma/orc/forest/fordesc02"); }
  if(i==2) { long_desc = read_file("/wizards/ahma/orc/forest/fordesc03"); }
  if(i==3) { long_desc = read_file("/wizards/ahma/orc/forest/fordesc04"); }
  if(i==4) { long_desc = read_file("/wizards/ahma/orc/forest/fordesc05"); }
  if(!random(250)) {
    tell_room(this_object(), "An Orcish ranger jumps out from the bush.\n");
    move_object(clone_object("/wizards/ahma/orc/mob/ranger"), this_object());
  }
  if(present("walkeri", this_object())) {
  call_other(present("walkeri", this_object()), "checkroom");
  }
}

mobdead() {
  alive = 0;
}
