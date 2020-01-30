inherit "room/room";
object monster;

reset(arg) 
{
  if(arg) return;
  add_exit("south","/wizards/jhary/room/dwarves/dwarf3");
  short_desc = "In a healers hut";
  long_desc = "You arrive at the treatment room of the healer. All in \n"+
              "here looks very sterile, as it would be cleaned nearly \n"+
              "every hour. You heard that should be necessary to avoid, \n"+
              "that the portions get polluted with bacteria, but only \n"+
              "fools think, that small animals swirl through the air and \n"+
              "we do not taste them while breathing! But as you let \n"+
              "everybody believe, what he wants to do, you accept this view.\n"+
              "Along the walls there are a lot of potions and glasses with \n"+
              "several herbs in boards and stands. If you would be a little \n"+
              "bit more intelligent you could mix them on your own, but cause \n"+
              "you aren't, you should read the sign and order the treatment you \n"+
              "need. The healer will mix it on the desk and then you can enjoy \n"+
              "it either on one of the treatment chairs, or while standing \n"+
              "here. If you received enough health, you can leave to the south. \n";
   //impossible items[0]=({"wall","walls"});   :(
   items=allocate(2);
   items[0]="wall";
   items[1]="The walls seem to be pure granite - there are no joints visible,\n"+
           "as if the whole house has been caved out of a single, huge stone!";
}
                                        
