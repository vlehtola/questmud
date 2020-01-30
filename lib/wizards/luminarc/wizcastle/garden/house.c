inherit "room/room";
object ob;
reset(arg) {
  if(arg) return;
  add_exit("south","/wizards/luminarc/wizcastle/garden/entrance");
  add_exit("house","/wizards/luminarc/wizcastle/garden/inhou");
  short_desc = "house";
  long_desc="Old and ruined house rises here. The roof looks like it would collapse\n"+
            "any moment. Small windows on walls are partly broken. Some moss is growing\n"+
            "all around the house. Bricks of chimney, which once was rising on the roof\n"+
            "are now lying on the ground.\n";   

 property = allocate(1);
  set_light(3);
ob = clone_object("/wizards/luminarc/wizcastle/humans/bee.c");
move_object(ob, this_object());
}

