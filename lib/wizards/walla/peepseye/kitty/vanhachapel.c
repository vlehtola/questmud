inherit "room/room";     
 
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/peepseye/monsters/cleophus");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","/wizards/walla/peepseye/kitty/backchapel");
  add_exit("south","/wizards/walla/peepseye/kitty/m5");
  short_desc = "The chapel of OilOhnRock";
  long_desc =
 "Here, inside the house of God, you feel good. A gentle breeze runs through you,\n" +
 "and you feel that someone really CARES about YOU! -noooot!\n" ;

 
  items = allocate(4);
  items[0] = "altar";
  items[1] = "You see the altar, It is covered with a winered cloth.";   

  property = allocate(4);
  property[0] = "no_kill";
  property[1] = "no_skill";
  property[2] = "no_spell";
  property[3] = "no_summon";
 
}
 
 
 

