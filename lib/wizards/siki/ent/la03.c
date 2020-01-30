inherit "room/room";

reset(arg) {
object ob,ob2;
if(arg) return;
   add_exit("northwest","/wizards/siki/ent/la02");
   add_exit("northeast","/wizards/siki/ent/la04");

   set_not_out(1);

   short_desc = "A huge labyrinth.";
   long_desc = "It seems that the infinite maze leads nowhere. The tunnel\n"+
               "has been build inside solid rock. The walls are covered with\n"+
               "green thick slime.\n";

   items = allocate(2);
   items[0] = "slime";
   items[1] = "Extremely thick green slime that's slowly dripping from the ceiling";
  
   property = allocate(1);
   property[0] = "no_summon";

   if(!ob) {
    ob = clone_object("/wizards/siki/ent/monsters/skewar.c");
    move_object(ob, this_object());
  }
  if(!ob2) {
    ob2 = clone_object("/wizards/siki/ent/monsters/skewar.c");
    move_object(ob2, this_object());
  }
}


 

