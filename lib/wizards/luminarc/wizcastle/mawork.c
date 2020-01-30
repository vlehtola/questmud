inherit "room/room";
object monster;
reset(arg) {
  if(arg) return;
  add_exit("south","/wizards/luminarc/wizcastle/up1");
  short_desc = "Somekind of workroom";
long_desc = "This messy room looks like somekind of a workroom. There are dusty\n"+ 
            "books and papers on the floor. Looks like long time has gone since this room\n"+ 
            "was in use. In middle of the room there is wooden table which contains\n"+ 
            "broken bottles and wizened herbs. Light source of this room is\n"+
            "a mysterious ball of light, some magical power is moving it around\n"+ 
            "the room. One small round shaped window is placed on the north\n"+ 
            "wall. Small coop is hanging from ceiling. Beautiful voiced bird\n"+ 
            "is singing songs from it.\n"; 
  set_light(3);
  if (!monster) {
      monster = clone_object("/wizards/luminarc/wizcastle/humans/farnax.c");
      move_object(monster, this_object());
}
items=allocate(10);
items[0]="ball";
items[1]="Some mysterious power is moving this ball. For such a small ball it gives very much light";
items[2]="table";
items[3]="Hundreds of scrolls and herbs are lying on the table";
items[4]="coop";
items[5]="Small yellow is sitting on the coop and singing happyly";
}




