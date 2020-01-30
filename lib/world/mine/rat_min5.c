inherit "room/room";

object monster;

reset(arg) {
   set_not_out(1);
   set_light(1);
   short_desc = "Entrance to rat's den";
   long_desc = "The old mining tunnel ends here but there is still a small\n"+
	"opening to the west. It smells like rats here.\n";
   add_exit("east", "world/mine/rat_min4.c");
   add_exit("west", "world/mine/rat_den.c");

   if (!monster) {
	monster = clone_object("world/mine/monsters/huge_rat");
	move_object(monster,this_object());
   }
}
