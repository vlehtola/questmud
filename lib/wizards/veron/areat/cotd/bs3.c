inherit "room/room";
object monster;
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/veron/areat/cotd/mobs/snake");
    move_object(monster, this_object());
  }
if(arg) return;
add_exit("down","/wizards/veron/areat/cotd/bs1.c");

  short_desc = "Attic";
  long_desc = "This is a small attic where the blacksmith has undeniably used as\n"+
              "his bedroom. The room is really low preventing standing straight.\n"+
              "A small bed made of old planks is in the corner. There's also\n"+
              "a sturdy wooden stool in the room, placed next to the bed. A candle\n"+
              "is put on it. Dust twirls in the room as the heavy wind roars in\n"+
              "the streets. Over the bed there's a small window with a nice sight to\n"+
              "the wall of the house opposite of this one.\n";

  set_not_out(1);
  items = allocate(8);
  items[0] = "bed";
  items[1] = "An ugly-looking bed made of old planks. It's in the corner of the room";
  items[2] = "stool";
  items[3] = "A sturdy stool made of oak. There's a candle placed on it";
  items[4] = "candle";
  items[5] = "This little candle is already half-burnt. It's placed on the stool";
  items[6] = "window";
  items[7] = "You take a quick look out of the window and notice the wall of the house\n"+
             "opposite of this one. Nice";



  }
