inherit "room/room";
object watch;
reset(arg) {

if(arg) return;
  if (!watch) {
      watch = clone_object("/wizards/neophyte/forest/obj/watch");
      move_object(watch, this_object());
}
        short_desc = "In the hole";
        long_desc = "You are inside the small hole. There are lots of\n"+
                    "tunnels going to different directions from here.\n";
    add_exit("out","/wizards/neophyte/forest/field5");
}
