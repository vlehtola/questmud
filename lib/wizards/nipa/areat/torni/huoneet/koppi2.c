inherit "room/room";
inherit "room/door";
object monster;

reset(arg) {
int i;
i = random(2);

 if(!monster && i==1) {
  monster = clone_object("/wizards/nipa/areat/torni/mosat/adeptapp.c");
  move_object(monster, this_object());
  }

if(arg) return;

   short_desc = "A small cosy looking apartment.";
   long_desc = "A small apartment room with many books and scrolls around.\n"+
               "It seems this room belongs to an apprentice mage and it is lived. \n"; 

set_light(2);

door_reset();
   set_door_label("wooden door",1);
   set_door_dir("east", "hallway3.c",1);
   set_door_link("/wizards/nipa/areat/torni/huoneet/hallway3.c",1);
   set_locked(0, 1);
 
set_not_out();
}

init() {
  ::init();
  door_init();
}
