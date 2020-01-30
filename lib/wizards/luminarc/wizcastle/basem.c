inherit "room/room";
object ob;
reset(arg) {
  if(arg) return;
  add_exit("up","/wizards/luminarc/wizcastle/upwest2");
  short_desc = "cellar";
long_desc = "Small and cold room containining a lot of food supplies, barrels of vine\n"+
            "bread and almost everything what man needs. On the west side there are\n"+ 
            "three shelves containing bottles of some liquid, maybe they are vine\n"+
            "or maybe not.\n";  
set_light(3);
ob = clone_object("/wizards/luminarc/wizcastle/humans/rat.c");
move_object(ob, this_object());
ob = clone_object("/wizards/luminarc/wizcastle/humans/skilled.c");
move_object(ob, this_object());


}

