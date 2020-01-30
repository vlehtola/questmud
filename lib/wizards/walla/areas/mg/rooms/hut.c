inherit "room/room";

object lapio;

reset(arg) {
  if(!lapio) {
    lapio = clone_object("/wizards/walla/areas/mg/stuph/shovel");
    move_object(lapio, this_object());
  }
  if(arg) return;
  add_exit("out","31");

  short_desc = "Inside the groundskeepers hut";
  long_desc =
"The hut is not very well furnished. A stool and a table are set on one end\n" +
"of the room, and a well made bed is on the other end. A cupboard stands on\n" +
"one end, and next to it, a fireplace. There is a small window that points\n" +
"away from the gloomy graveyard, and a picture of a beautiful woman hangs on\n"+
"one wall. The frame has a black ribbon on one corner of it.\n";


}
