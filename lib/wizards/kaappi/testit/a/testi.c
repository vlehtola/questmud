inherit "room/room";
object mob,mob2;

reset(arg) {
   
   if(!mob) {
      mob = clone_object("/wizards/nipa/areat/torni/mosat/casterbmage.c");
  move_object(mob, this_object()); }

   if(!mob2) {
      mob2 = clone_object("/wizards/nipa/areat/torni/mosat/casterbmage.c");
  move_object(mob2, this_object()); }  
  

    add_exit("down","stairs2.c");
        add_exit("up", "stairs4.c");
        add_exit("east", "3lib6.c");
        add_exit("west", "3lib4.c");

   short_desc = "Wide stair looking plates floating in the spiral formation.";
    long_desc = "Here in the center of the tower floats thousands of plates in a spiral\n"+
                "formation. These plates are used as stairs. You have no idea what material\n"+ 
                "the plates are but you get the feeling that they have no weight at all but\n"+
                "still every step is stabile. With a peek up they allow access to every floor\n"+
                "in the tower. Faint blue light flashes every time you step on a plate.\n"+
                "The whole stairway is lit by a pillar of dim magenta light.\n";
               
        set_light(3);
}

init() {
  ::init();
  add_action("up", "up"); }
  
up() {
  if(mob || mob2) {
  write("Guard block your way up.\n");

return 1;
 }
}
