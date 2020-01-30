inherit "room/room";
object wizh;
reset(arg) {
    if(arg) return;
    add_exit("east","/wizards/siggy/area/unseen/uu6.c");
    set_not_out(3);
    short_desc = "A dark closet";
    long_desc = 
        "It's very dark in here, but you can still see just a itty bitty. There is\n"
        + "nothing unusual here, instead of a old crappy box. Ah, there's someone\n"
        + "trying to hide behind the closet.\n"; 

   items = allocate(2);
   items[0] = "box";
   items[1] = "Old crappy wooden box.";
 
if(!wizh) {
    wizh = clone_object("/wizards/siggy/area/unseen/wizh.c");
    move_object(wizh, this_object());
    }

init() {
  ::init();
  add_action("force", "force");
}

force(str) {
  if(str != "box") return;
  if(str = "box");
        tell_object(ob, "*Crack* *Squick* The box cracks open and a sword jumps out of it.\n");
        clone_object("/wizards/siggy/area/unseen/bsword.c"); 
 }

}




