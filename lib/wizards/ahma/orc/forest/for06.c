inherit "room/room";
int h, alive;
object mob;

reset(arg) {
  add_exit("north", "/wizards/ahma/orc/forest/for16");
  add_exit("west", "/wizards/ahma/orc/forest/for07");
  add_exit("southeast", "/wizards/ahma/orc/forest/for05");
  short_desc = "In an intersection";

  h = random(7);
  if(!mob) {
  if(!alive) {
    if(h==0) { move_object(mob = clone_object("/wizards/ahma/orc/mob/bear01"), this_object()); alive = 1; }
    if(h==1) { move_object(mob = clone_object("/wizards/ahma/orc/mob/boar"), this_object()); alive = 1; }
    if(h==2) { move_object(mob = clone_object("/wizards/ahma/orc/mob/deer"), this_object()); alive = 1; }
    if(h==3) { move_object(mob = clone_object("/wizards/ahma/orc/mob/fox"), this_object()); alive = 1; }
    if(h==4) { move_object(mob = clone_object("/wizards/ahma/orc/mob/eagle"), this_object()); }
    if(h==5) { move_object(mob = clone_object("/wizards/ahma/orc/mob/moose"), this_object()); }
    if(h==6) { move_object(mob = clone_object("/wizards/ahma/orc/mob/walker01"), this_object()); alive = 1; }
  }
  }
}

init() {
  int i;
  ::init();
  i = random(5);
  if(i==0) {
    long_desc = "The path separates in three directions.\n" + 
    read_file("/wizards/ahma/orc/forest/fordesc01", 2);
  }
  if(i==1) {
    long_desc = "The path separates in three directions.\n" +
    read_file("/wizards/ahma/orc/forest/fordesc02", 2);
  }
  if(i==2) {
    long_desc = "The path separates in three directions.\n" +
    read_file("/wizards/ahma/orc/forest/fordesc03", 2);
  }
  if(i==3) {
    long_desc = "The path separates in three directions.\n" +
    read_file("/wizards/ahma/orc/forest/fordesc04", 2);
  }
  if(i==4) {
    long_desc = "The path separates in three directions.\n" +
    read_file("/wizards/ahma/orc/forest/fordesc05", 2);
  }
  if(!random(250)) {
    tell_room(this_object(), "An Orcish ranger jumps out from the bush.\n");
    move_object(clone_object("/wizards/ahma/orc/mob/ranger"), this_object());
  }
}

mobdead() {
  alive = 0;
}