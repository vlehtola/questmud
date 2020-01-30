inherit "room/room";
object mob;
int h, alive;

reset(arg) {
  add_exit("north", "/wizards/ahma/orc/forest/for22");
  add_exit("east", "/wizards/ahma/orc/forest/for20");
  short_desc = "On a soft forest path leading to the base of a high cliff";

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
  if(i==0) { long_desc = read_file("/wizards/ahma/orc/forest/fordesc01") + 
             "Behind a small distance to north can be seen a high cliff.\n"; }
  if(i==1) { long_desc = read_file("/wizards/ahma/orc/forest/fordesc02") + 
             "Behind a small distance to north can be seen a high cliff.\n"; }
  if(i==2) { long_desc = read_file("/wizards/ahma/orc/forest/fordesc03") + 
             "Behind a small distance to north can be seen a high cliff.\n"; }
  if(i==3) { long_desc = read_file("/wizards/ahma/orc/forest/fordesc04") + 
             "Behind a small distance to north can be seen a high cliff.\n"; }
  if(i==4) { long_desc = read_file("/wizards/ahma/orc/forest/fordesc05") + 
             "Behind a small distance to north can be seen a high cliff.\n"; }
  if(!random(250)) {
    tell_room(this_object(), "An Orcish ranger jumps out from the bush.\n");
    move_object(clone_object("/wizards/ahma/orc/mob/ranger"), this_object());
  }
}

mobdead() {
  alive = 0;
}
