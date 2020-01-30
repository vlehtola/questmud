inherit "room/room";
object monster;

reset(arg) {
      if(!monster) {
      monster = clone_object("/wizards/siki/lizard/monsters/fliz");
      move_object(monster, this_object());
      }
   if(arg) return;


  add_exit("south","/wizards/siki/lizard/dock2");
  add_exit("north","/wizards/siki/lizard/room14");

  short_desc = "An old wooden dock";
  long_desc = "The dock is very old and the wood that it is made of is slowly\n"+
              "rotting. The small lake is calm, but you sense something\n"+
              "strange in it.\n";
             
 }
